//
//******************** Anakino_Aquarium es un codigo para arduino basado en Ferduino para adaptarlo a agua dulce y con añadidos.
//
//
//

//*******************************************************************************************************************************************************
//***********************              Modificado  por Antonio David Torres      ************************************************************************
//*******************************************************************************************************************************************************
//******* Dudas, sugerencias, peticiones: antoniodavidtorres@gmail.com   *************************************************************************************
// 
//*******************************************************************************************************************************************************
//      Combinacion de colores para la conexion de la placa de reles.
//                 Reles *** Conector *********   Arduino
//                 - GND   => Cable rojo     => Negro GND
//                 - Pin 1 => Cable marron   => Naranja         (Calentador
//                 - Pin 2 => Cable mostaza  => Naranja/negro   (Luces)
//                 - Pin 3 => Cable morado   => Amarillo/negro  (Aireador)
//                 - Pin 4 => Cable gris     => Negro enfundado (UV)
//                 - Pin 5 => Cable azul     => Verde/Negro
//                 - Pin 6 => cable verde    => Verde
//                 - Pin 7 => cable XXXX
//                 - Pin 8 => Cable amarillo => Amarillo
//                 - VCC   => Cable blanco   => Rojo 5+


// // Programa compatible con arduino 1.0.4

//---------------------------------------------------------

// Programa modificado desde Ferduino
// Disponible en esta página https://github.com/FernandoGarcia
// 

//---------------------------------------------------------

// Algoritmo de control de LED esta basado en  Krusduino de Hugh Dangerfield
// http://Code.Google.com/p/dangerduino/
// Algoritmo de fase lunar fue escrito por Jamie Jardin vulgo "TheDOdblG", basado en código de NightAtTheOpera's Lunar Phase 
// http://www.nano-reef.com/forums/index.php?showtopic=217305

//-----------------------------------------------------------
// Este programa é software livre; Você pode redistribuí-lo e/ou
// modificá-lo sob os termos da GNU General Public License
// como publicada pela Free Software Foundation versão 3
// da licença, ou (por sua opção) qualquer versão posterior.
// Este programa é distribuído na esperança que seja útil,
// mas sem qualquer garantia; sem mesmo a garantia implícita de
// comercialização ou propósito particular. Consulte o
// GNU General Public License para mais detalhes.

//*************************************************************************************************
//*************** Biliotecas utilizadas ***********************************************************
//*************************************************************************************************
#include <UTFT.h>    
#include <UTouch.h> 
#include <Wire.h>
#include <EEPROM.h>
#include <writeAnything.h> // Fuciones de lectura y escritura de EEPROM.
#include <DS1307henning.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <SPI.h>
#include <Ethernet.h>
#include <HttpClient.h>
#include <Xively.h>
#include <Twitter.h>
//#include <PCF8575.h>
//#include <JeeLib.h>



//****************************************************************************************************
//***************** Sensores de temperatura **********************************************************
//****************************************************************************************************
OneWire OneWireBus(42);                   //Sensores de temperatura conectados al pin 43.
DallasTemperature sensors(&OneWireBus);  
DeviceAddress sensor_agua= {0x28, 0x10, 0x32, 0x2B, 0x04, 0x00, 0x00, 0x38 }; // Es necesario cambiar este valor acorde con nuestro sensor.
DeviceAddress sensor_dissipador = {0x28, 0x99, 0x47, 0x2B, 0x04, 0x00, 0x00, 0xFB }; // Es necesario cambiar este valor acorde con nuestro sensor.
DeviceAddress sensor_habitacion = {0x28, 0x6D, 0x70, 0x2B, 0x04, 0x00, 0x00, 0x80 }; // Es necesario cambiar este valor acorde con nuestro sensor.

//****************************************************************************************************
//****************** Variables de textos y fuentes ****************************************************
//****************************************************************************************************
#define LARGE true
#define SMALL false
extern uint8_t SmallFont[];   // Declara que fuentes vamos usar
extern uint8_t BigFont[];     // Declara que fuentes vamos usar
char buffer[70];

//****************************************************************************************************
//****************** Define las funciones de los pines digitales y analogicos **********************************
//****************************************************************************************************
// Pines 0 y 1 reservados para el puerto serial 0.
const int alarmPin = 0;          // Pin que acciona la alarma
// Pines 2, 3, 4, 5, 6  reservado para el  Touch.
const int fanPin = 7;          // Pin que controla la velocidad de ventilador del disipador // Conexion  nº 3 azul
const int PWMLuz = 8;      // Pin que controla PWM del  balastro dimeable  // Conexion nº 1 amarillo
//const int Pin = 9;       // Pin libre
//const int Pin = 11;      // Pin libre
const int ledPinMoon = 12; // Pin que activa los leds de luz noturna // Conexion nº 2 Verde
// const int Pin = 13;   // Pin libre
// const int pin = 14;   // Pin libre
// const int pin = 15;   // Pin libre
// const int pin = 16;   // Pin libre
// const int pin = 17;   // Pin libre
// const int pin = 18;   // Pin libre
// const int pin = 19;   // Pin libre
// Pines 20 y 21 reservados para comunicacion RTC
// Pines 22 al 41 reservados para o LCD.

// Pin 42 reservado para los sensores de temperatura

// *******************  Placa de reles ************************

const int calentadorPin  = 43;  // Rele 1 => Enchufe 1 Cable Naranja ****** Pin que activa el calentador 
const int ReleLuz = 44;         // Rele 2 => Enchufe 2 => Naranja/negro *** Pin que activa el rele de la luz
const int temporizador1 = 45;   // Rele 3 => Enchufe 3 => Amarillo/negro ** Pin de activacion de timer 1 ( bomba aire )  
const int temporizador2 = 46;   // Rele 4 => Enchufe 4  ******************* Pin de activacion de timer 2 ( Lampara UV )
const int temporizador3 = 47;   // Rele 4 => Enchufe 4 => Negro enfundado * Pin de activacion de timer 3 
const int temporizador4 = 48;   // Rele 5 => Verde/negro ****************** Pin de activacion de timer 4 
const int temporizador5 = 49;   // Rele 6 => Verde ************************ Pin de activacion de timer 5  
const int comederopin = 50;     // Rele 7 =>            *******             Pin de comedero

// ******************************************************************************************

// Pines 50, 51 e 52 reservados para comunicacion SPI
// Pin 53 reservado para "select slave de ethernet shield.
// Pin A15 reservado para SS do RFM12B



//*******************************************************************************************************
//********************** Funciones del RTC ********************************************************************
//*******************************************************************************************************
DS1307 rtc(20, 21); // Indica en que pines esta conectado el RTC.
Time t_temp, t;

//*******************************************************************************************************
//********************** Variables de la funcion del touch screen y de la pantalla incial ****************************
//*******************************************************************************************************
UTFT        myGLCD(ITDB32WD, 38,39,40,41);   // Cambiar segun el modelo de la TFT LCD
UTouch      myTouch(6,5,4,3,2); 

long previousMillis = 0;
byte data[56];
String day; 
int whiteLed, moonLed;    // Valor anterior de PWM.
int dispScreen = 0;

// pantalla  inicio =0, 
// pantalla de menu = 1, 
// pantalla do reloj = 2,
// pantalla de temperaturas = 3,
// pantalla control de temperatura acuario = 4, 
// pantalla control temperatura tapa = 5
// pantalla para variar potencia de los leds = 6,
// pantalla EEPROM guarda y borra = 7, 
// pantalla graficos = 9,
// pantalla configuracion parametros = 14, 
// pantalla configuracion modo leds = 16, 
// pantalla configuracion de ph do aquario = 18, 

//*****************************************************************************************************
//***************************    COMEDERO   ***********************************************************
//*****************************************************************************************************
int comedero = 0;
int comedero1 = 0;       //Valor a cero comedero desactivado valor a 1 comedero activado
int comedero2 = 0;       //Valor a cero comedero desactivado valor a 1 comedero activado
int comedero3 = 0;       //Valor a cero comedero desactivado valor a 1 comedero activado
int comedero4 = 0;       //Valor a cero comedero desactivado valor a 1 comedero activado

int comedero1H = 0;
int comedero1M = 0;
int comedero2H = 0;
int comedero2M = 0;
int comedero3H = 0;
int comedero3M = 0;
int comedero4H = 0;
int comedero4M = 0;
// ************************************************** Valores temporales del comedero  ************* 
int comedero1_Temp = 0;
int comedero2_Temp = 0;
int comedero3_Temp = 0;
int comedero4_Temp = 0;

int comedero1H_Temp = 0;
int comedero1M_Temp = 0;
int comedero2H_Temp = 0;
int comedero2M_Temp = 0;
int comedero3H_Temp = 0;
int comedero3M_Temp = 0;
int comedero4H_Temp = 0;
int comedero4M_Temp = 0;   
 

//*****************************************************************************************
//*********************** Parametros ******************************************************
//*****************************************************************************************
byte status_parametros = 0x0; // En esta variable podremos añadir los diferentes estados del sistema
//bit 0;    tempCflag    // indica  el estado del calentador
//bit 1;    ventflag     // estado ventilador disipador
//bit 2;    tempAflag    // indica que la temperatura del agua esta fuera de rango (aviso en rojo ºC de la temp)



//*****************************************************************************************
//*********************** Variables de control de temperatura del agua ********************
//*****************************************************************************************
float tempC = 0;              // Temperatura de agua
float setTempC = 25;          // Temperatura deseada
float offTempC = 0.5;         // Variacion permitida de temperatura
float alarmTempC = 3;         // Variacion para acionar la alarme de temperatura de agua
int contador_temp = 0;
float temperatura_agua_temp;       // Temperatura temporal del agua
float temperatura_dissipador_temp; // Temperatura temporal del disipador
float temperatura_habitacion_temp; // temperatura temporal de la habitacion
int fanSpeed = 0;


//*****************************************************************************************
//************************ Variables del control de la velocidad del ventilador ***********
//*****************************************************************************************
const int HtempMin = 30;    // Declara la temperatura para iniciar el funcionamiento de la velocidad del ventilador 
const int HtempMax = 40;    // Declara que el ventilador debe estar a su maxima velocidad cuando el disipado este a  40º


//*****************************************************************************************
//************************ Variable de control de la temperatura del disipador **************
//*****************************************************************************************
float tempH = 0;            // Temperatura del disipador
float tempHB = 0;

byte tempHMAX          = 40; // Temperatura máxima del disipador en la cual se reducirá la potencia de la iluminación  
byte tempHMAZX_t;            // Valor temporal de la temperatura maxima del disipador
byte tempHRecuperacion = 37; // Temperatura de recuperación de potencia completa de la iluminación                    
byte tempHRecuperacion_t;    // Valor temporal de la recuperacion de potencia

//*****************************************************************************************
//************************ Variable temporal del control de la temperatura del agua    ****
//*****************************************************************************************
float temp2beS;           
float temp2beO;
float temp2beA;

//*****************************************************************************************
//************************ Variables de control de la iluminacion ****************************
//*****************************************************************************************
int LedChangTime = 0;          // Página de variacion de leds, tiempo y valores.
boolean MeanWell = true;      // Es estiver usando drivers cuja potência máxima seja obtida aplicando zero volt e a mínima seja 5 volts altere de "true" para "false".
int min_cnt ;
int wled_out;
int wled_out_temp;
int moonled_out;
int y_tocado;
boolean teste_em_andamento = false;
int w_out, moon_out;
byte cor_selecionada = 0x0;
// bit 1 = led blanco
// bit 2 = led azul
int setor_selecionado = 0;
boolean mensagem = true;
float suavizar = 0.0; // LEDS inicia suavemente y llega al valor especificado en 50 segundos.
byte predefinido = 0;

int led_estado = 0;       // Variable que indicara el estado de la iluminacion ON / OFF / Automatico
int led_estado_temp;  // Variable temporal del estado de la luz

int potenciaIluminacion; // Porcentaje de potencia de iluminacion ACTUAL de los leds


byte pwm_pre_definido = 255;// potencia de leds
byte pwm_percent = 100;           //  Tanto por ciento fijado desde la pantalla de config fotoperiodo
byte led_on_hora = 12;     // Horario para encender leds.
byte led_on_minuto = 00;
byte led_off_hora = 21;    // Horario para apagar leds.
byte led_off_minuto = 0;   

byte amanecer_anochecer = 40;   //Tiempo en amanecer o anochecer
byte pwm_percent_t;
byte led_on_minuto_t;      // Horarios temporales
byte led_on_hora_t;
byte led_off_minuto_t;
byte led_off_hora_t;
byte amanecer_anochecer_t;
boolean encender_luz;

//*************************************************************************************************
//***************DISEÑO BARRAS LUZ PANTALLA ***********************************************************
//*************************************************************************************************     
const byte cor_canal1[] = { 255, 255, 255}; // Blanco
const byte cor_canal2[] = {9, 184, 255};    // Luna Azul

//*****************************************************************************************
//************************ Variables de la fase lunar ******************************************
//*****************************************************************************************
String LP;
int MaxI , tMaxI;  // Potencia  máxima en Luna llena.             
int MinI, tMinI;  // Potencia  mínima en Luna nueva.
float lunarCycle; //get a value for the lunar cycle



//*****************************************************************************************
//*********************** Variables de control de níveles **********************************
//*****************************************************************************************
boolean nivel_status = 0;             // indica nivel bajo en uno de los acuarios

//*****************************************************************************************
//************************ Variável de controle da reposição de água doce *****************
//*****************************************************************************************
boolean ato = 0;                      // indica reposição activada / desactivada

//*****************************************************************************************
//************************ Variáveis de envio da informações ao xively.com ******************
//*****************************************************************************************
long previous_Millis = 0; // Variável que controla o tempo para envio dos dados
byte Status = 0x0;
// bit 1 int reposicao_status;
// bit 2 niveis_status;
// bit 3 tpa_status;

//*****************************************************************************************
//************************* Funciones de ethernet shield **********************************
//*****************************************************************************************
boolean Ethernet_Shield = true; // Cambiar a "false" en caso de no tener una ethernetshield conectada al arduino

char data0[] = "T.Agua";
char data1[] = "T.Disip";
char data2[] = "T.Habit";
char data3[] = "pH";
char data4[] = "Calent";
char data5[] = "Fan";
char data6[] = "UV";
char data7[] = "Aire";
char data8[] = "T3";
char data9[] = "T4";
char data10[] = "T5";
char data11[] = "Crono";
char data12[] = "Luz_Blanca";
char data13[] = "Luz_Luna";
/*char data14[] = "L.Blanco";
char data15[] = "15";
char data16[] = "16";
char data17[] = "17";
*/


XivelyDatastream datastreams[] = 

{
XivelyDatastream(data0, strlen(data0), DATASTREAM_FLOAT),  
XivelyDatastream(data1, strlen(data1), DATASTREAM_FLOAT),
XivelyDatastream(data2, strlen(data2), DATASTREAM_FLOAT),
XivelyDatastream(data3, strlen(data3), DATASTREAM_FLOAT),
XivelyDatastream(data4, strlen(data4), DATASTREAM_INT),
XivelyDatastream(data5, strlen(data5), DATASTREAM_INT),
XivelyDatastream(data6, strlen(data6), DATASTREAM_INT),
XivelyDatastream(data7, strlen(data7), DATASTREAM_INT),
XivelyDatastream(data8, strlen(data8), DATASTREAM_INT),
XivelyDatastream(data9, strlen(data9), DATASTREAM_INT),
XivelyDatastream(data10, strlen(data10), DATASTREAM_INT),
XivelyDatastream(data11, strlen(data11), DATASTREAM_INT),
XivelyDatastream(data12, strlen(data12), DATASTREAM_INT),
XivelyDatastream(data13, strlen(data13), DATASTREAM_INT),
/*XivelyDatastream(data14, strlen(data14), DATASTREAM_INT),
XivelyDatastream(data15, strlen(data15), DATASTREAM_INT),
XivelyDatastream(data16, strlen(data16), DATASTREAM_INT),
XivelyDatastream(data17, strlen(data17), DATASTREAM_INT)
*/
};

XivelyFeed feed(157388679, datastreams, 14); // numero de datastreams
EthernetClient client;
XivelyClient xivelyclient(client);
char xivelyKey[]= "IztIl4jRHL0vLd6fFkwnXwLZ7YbuAi6jmr8kAXPO5RxrDkQQ"; // replace your xively api key here
// assign a MAC address for the ethernet controller.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
// fill in your address here:
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192,168,1, 15); // fill in an available IP address on your network here for manual configuration
int xivelyReturn = 0;    // Result Return code from data send

//*****************************************************************************************
//************************** tweeter ******************************************
//*****************************************************************************************

Twitter twitter("1692134557-fzSysgvsLE9DMKAQEFt0aashH7QGFAqZMe8VrY1"); // Your Token to Tweet (get it from http://arduino-tweet.appspot.com/)

byte msg_enviado = 0x0;
// byte 1 = sistema ok
// byte 2 = alarma disipador
// byte 3 = alarma temp agua


//*****************************************************************************************
//************************** Variables de los temporizadoes *******************************
//*****************************************************************************************
byte temporizador =0x0; // 0 = false, 1 = true
byte temporizador_status = 0x0; // 1 = true e 0 = false
//bit 1 = temporizador 1
//bit 2 = temporizador 2
//bit 3 = temporizador 3
//bit 4 = temporizador 4
//bit 5 = temporizador 5
int temporizador_1_ativado = 0;
int temporizador_2_ativado = 0;
int temporizador_3_ativado = 0;
int temporizador_4_ativado= 0;
int temporizador_5_ativado= 0;
int on1_minuto = 0;
int on1_hora = 0;
int on2_minuto = 0;
int on2_hora = 0;
int on3_minuto = 0;
int on3_hora = 0;
int on4_minuto = 0;
int on4_hora = 0;
int on5_minuto = 0;
int on5_hora = 0;
int off1_minuto = 0;
int off1_hora = 0;
int off2_minuto = 0;
int off2_hora = 0;
int off3_minuto = 0;
int off3_hora = 0;
int off4_minuto = 0;
int off4_hora = 0;
int off5_minuto = 0;
int off5_hora= 0;

//*****************************************************************************************
//************************** Variables temporales de los temporizadores *******************
//*****************************************************************************************
int on1_minuto_temp2;
int on1_hora_temp2;
int on2_minuto_temp2;
int on2_hora_temp2;
int on3_minuto_temp2;
int on3_hora_temp2;
int on4_minuto_temp2;
int on4_hora_temp2;
int on5_minuto_temp2;
int on5_hora_temp2;
int off1_minuto_temp2;
int off1_hora_temp2;
int off2_minuto_temp2;
int off2_hora_temp2;
int off3_minuto_temp2;
int off3_hora_temp2;
int off4_minuto_temp2;
int off4_hora_temp2;
int off5_minuto_temp2;
int off5_hora_temp2;
int temporizador_1_ativado_temp2;
int temporizador_2_ativado_temp2;
int temporizador_3_ativado_temp2;
int temporizador_4_ativado_temp2;
int temporizador_5_ativado_temp2;


