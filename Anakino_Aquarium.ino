
/*
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
//                 - Pin 1 => Cable marron   => Naranja         (Calentador)
//                 - Pin 2 => Cable mostaza  => Naranja/negro   (TEMPORIZADOR 1)
//                 - Pin 3 => Cable morado   => Amarillo/negro  (TEMPORIZADOR 2)
//                 - Pin 4 => Cable gris     => Negro enfundado (TEMPORIZADOR 3)
//                 - Pin 5 => Cable azul     => Verde/Negro
//                 - Pin 6 => cable verde    => Verde
//                 - Pin 7 => cable XXXX
//                 - Pin 8 => Cable amarillo => Amarillo
//                 - VCC   => Cable blanco   => Rojo 5+
//*************************************************************************************************



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
*/
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
#include <Stepper.h>

//#include <PCF8575.h>
//#include <JeeLib.h>



//****************************************************************************************************
//***************** Sensores de temperatura **********************************************************
//****************************************************************************************************
OneWire OneWireBus(42);                   //Sensores de temperatura conectados al pin 42.
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
// Pines 2, 3, 4, 5, 6     reservado para el  Touch.
const int ledPinWhite = 7;// Pin que controla PWM luz dimeable  // CHANNEL 1
const int ledPinMoon = 8; // Pin que activa los leds de luz nocturna // CHANNEL 2
const int fanPin = 9;     // Pin que controla la velocidad de ventilador // CHANNEL 3 Para aprovechar la salida de 24 de las luces ponemos los ventiladores en serie. asi si son de 12v la tension de 24 se divide entre los dos
// const int Pin = 10;   // Resrvado para ethernet shield
// const int Pin = 11;   // Bomba dosadora 1
 const int nivel_acu = 12;   // Sensor nivel agua acuario
 const int nivel_dep = 13;   // Sensor nivel agua deposito
// const int pin = 14;   // Pin motor comedero
// const int pin = 15;   // Pin motor comedero
// const int pin = 16;   // Pin motor comedero
// const int pin = 17;   // Pin motor comedero
// const int pin = 18;   // Pin de sensor de nivel. Leemos la lectura para saber si esta a nivel o no
 const int bomba = 19;   // Pin accionara la bomba de llenado
//          Pines 20 y 21 reservados para comunicacion RTC
//          Pines 22 al 41 reservados para o LCD.
//          Pin 42      reservado para los sensores de temperatura

const int calentadorPin  = 43;  // Rele 1 => Enchufe 1  ****** Pin que activa el calentador
//********************* Temporizadores **********************
const int temporizador1 = 44;   // Rele x => Enchufe 2  ****** Pin de activacion de TEMPORIZADOR 1 /aireador   
const int temporizador2 = 45;   // Rele x => Enchufe 3  ****** Pin de activacion de TEMPORIZADOR 2 /Lampara uv
const int temporizador3 = 46;   // Rele x => Enchufe 4  ****** Pin de activacion de TEMPORIZADOR 3 / CO2
const int temporizador4 = 47;   // Rele x => Enchufe XX ****** Pin de activacion de TEMPORIZADOR 4 
const int temporizador5 = 48;   // Rele x => Enchufe XX ****** Pin de activacion de TEMPORIZADOR 5 
// ******************************************************************************************

// const int comederopin = 49;   // Pin Libre
// Pines             50, 51 e 52 // Reservados para comunicacion SPI

// ******************************************************************************************


const int dosadora1 = 11;     // Bomba dosadora 1
const int dosadora2 = A10;     // Bomba dosadora 2
const int dosadora3 = A11;     // Bomba dosadora 3
const int dosadora4 = A12;     // Bomba dosadora 4
const int dosadora5 = A13;     // Bomba dosadora 5
const int dosadora6 = A14;     // Bomba dosadora 6


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
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution   for your motor

Stepper myStepper(stepsPerRevolution, 14,15,16,17); // initialize the stepper library on pins 8 through 11

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
//bit 0;     // estado ventilador disipador 
//bit 1;     // estado del calentador
//bit 2;     // estado de la temperatura (caliente) Influye alarma en pantalla
//bit 3;     // estado de la iluminacion
//bit 4;     // estado del PH del acuario

//*****************************************************************************************
//*********************** Variables de control de temperatura del agua ********************
//*****************************************************************************************
float tempC;              // Temperatura de agua
float setTempC;           // Temperatura deseada
float offTempC;           // Variacion permitida de temperatura
float alarmTempC;         // Variacion para acionar la alarma de temperatura de agua
int contador_temp = 0;
float temperatura_agua_temp;       // Temperatura temporal del agua
float temperatura_dissipador_temp; // Temperatura temporal del disipador
float temperatura_habitacion_temp; // temperatura temporal de la habitacion
int fanSpeed = 0;

//*****************************************************************************************
//************************ Variáveis do controle do PH do aquário *************************
//*****************************************************************************************
float PHA = 0;              // PH do acuario
float setPHA = 0;           // PH deseado de acuario
float offPHA = 0;           // Variacion permitida de PH de acuario
float alarmPHA = 0;         // Variacin para accionar la alarma de pH del acuario

//*****************************************************************************************
//************************ Variable temporal del ph del acuario      *************
//*****************************************************************************************
float PHA2beS;             
float PHA2beO;
float PHA2beA;

//*****************************************************************************************
//************************ Variable de control de la temperatura del disipador **************
//*****************************************************************************************
float tempH = 0;            // Temperatura del disipador
float tempHB = 0;

/*
byte tempHMAX          = 55;// Temperatura máxima del disipador en la cual se reducirá la potencia de la iluminación  
byte tempHMAZX_t;            // Valor temporal de la temperatura maxima del disipador
byte tempHRecuperacion = 37; // Temperatura de recuperación de potencia completa de la iluminación                    
byte tempHRecuperacion_t;    // Valor temporal de la recuperacion de potencia
*/

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
int w_out, moon_out;
byte cor_selecionada = 0x0;
// bit 1 = led blanco
// bit 2 = led azul
int setor_selecionado = 0;
boolean mensagem = true;
float suavizar = 0.0; // LEDS inicia suavemente y llega al valor especificado en 50 segundos.

int led_estado = 0;    // Variable que indicara el estado de la iluminacion MAN ON / MAN OFF / Automatico
int led_estado_temp;  // Variable temporal del estado de la luz

byte led_on_hora;       // Horario para encender leds.
byte led_on_minuto;
byte led_off_hora;      // Horario para apagar leds.
byte led_off_minuto;   
byte amanecer_anochecer;  //Tiempo en amanecer o anochecer
byte pwm_percent;      //  Tanto por ciento fijado desde la pantalla de config fotoperiodo
byte pwm_absoluto;     // potencia de leds

byte led_on_hora_t;       // Horarios temporales
byte led_on_minuto_t;      
byte led_off_hora_t;
byte led_off_minuto_t;
byte amanecer_anochecer_t;
byte pwm_percent_t;

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


//****************************************************************************************
//*********************** Variables de funcion de control de la SD      *****
//****************************************************************************************
unsigned long logtempminutoantes = 0;  // Variável que controla o tempo para gravação dos parâmetros no cartão SD 
const int chipselect = 4;            // Para utilizar o Sd card do LCD altere para 53
Sd2Card card;
SdFile file;
SdFile root;
SdVolume volume;
char time1;
char time2;
char time3;
char time4;
char time5;


//*****************************************************************************************
//********************************* Estado del rellenado  *********************************
//*****************************************************************************************
boolean rellenador_activo =false;

//*****************************************************************************************
//************************ Configuracion de xively ******************
//*****************************************************************************************
long previous_Millis = 0; // Variável que controla o tempo para envio dos dados

//*****************************************************************************************
// *********************** NETIO
//*****************************************************************************************
EthernetServer server(54322);
#define BUFFER 10


//*****************************************************************************************
//************************* Funciones de ethernet shield **********************************
//*****************************************************************************************
boolean Ethernet_Shield = true; // Cambiar a "false" en caso de no tener una ethernetshield conectada al arduino

char data0[] = "T.Agua";
char data1[] = "T.Disip";
char data2[] = "T.Habit";
char data3[] = "Calent";
char data4[] = "Fan";
char data5[] = "UV";
char data6[] = "Aire";
char data7[] = "T3";
char data8[] = "T4";
char data9[] = "Crono";
char data10[] = "Luz_Blanca";
char data11[] = "Luz_luna";
//char data12[] = "Rele_Luz";
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
/*XivelyDatastream(data12, strlen(data12), DATASTREAM_INT),
XivelyDatastream(data13, strlen(data13), DATASTREAM_INT),
XivelyDatastream(data14, strlen(data14), DATASTREAM_INT),
XivelyDatastream(data15, strlen(data15), DATASTREAM_INT),
XivelyDatastream(data16, strlen(data16), DATASTREAM_INT),
XivelyDatastream(data17, strlen(data17), DATASTREAM_INT)
*/
};
XivelyFeed feed(157388679, datastreams, 12); // numero de datastreams
EthernetClient client;
XivelyClient xivelyclient(client);
char xivelyKey[]= "XXXXXXXXXX"; // replace your xively api key here// assign a MAC address for the ethernet controller.

// Newer Ethernet shields have a MAC address printed on a sticker on the shield
// fill in your address here:
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
byte ip[] = { 192, 168, 1, 15 };
//IPAddress ip(192,168,1, 15); // fill in an available IP address on your network here for manual configuration
int xivelyReturn = 0;    // Result Return code from data send


//Ethernet Port
//EthernetServer server = EthernetServer(54322); //default html port 80


//*****************************************************************************************
//************************ Declaracion variables webserver ******************
//*****************************************************************************************

//Html page refresh
int refreshPage = 15; //default is 10sec. 
//Beware that if you make it refresh too fast, the page could become inacessable.

int outp = 0;
boolean printLastCommandOnce = false;
boolean printButtonMenuOnce = false;
boolean initialPrint = true;
String allOn = "";
String allOff = "";
boolean reading = false;
boolean outputStatus[10]; //Create a boolean array for the maximum ammount.
String rev = "V4.06";
unsigned long timeConnectedAt;



//*****************************************************************************************
//************************** tweeter ******************************************
//*****************************************************************************************
boolean cuenta_twitter = false; // modificar esto a false en caso de no tener cuenta en twiiter para el aviso de las alarmas
Twitter twitter("XXXXXXXXXXXXX"); // Your Token to Tweet (get it from http://arduino-tweet.appspot.com/)

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
//bit  = temporizador luz

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



//*****************************************************************************************
//************************** Variable  dosificadoras ******************************************
//*****************************************************************************************
boolean dosadoras = true; //Cambiar a false en caso de no tener dosificadoras
char time9;
char time10;
char time11;
char time15;
char time16;
char time17;
int contador = 0;
int minuto01 = 0;
int minuto11 = 0;
long tempo_dosagem = 0;
float dose_dosadora_1_manual = 0.0;
float dose_dosadora_2_manual = 0.0;
float dose_dosadora_3_manual = 0.0;
float dose_dosadora_4_manual = 0.0;
float dose_dosadora_5_manual = 0.0;
float dose_dosadora_6_manual = 0.0;
boolean modo_manual = false;
boolean modo_personalizado = false;
boolean modo_calibrar = false;
byte dosadora_selecionada = 0x0; // 0 = false, 1 = true
byte ativar_desativar = 0x0;     // 0 = false, 1 = true
byte modo_personalizado_on = 0x0; // 0 = false, 1 = true
byte segunda_dosagem_personalizada = 0x0; // 0 = false, 1 = true
// bit 1 = dosadora 1
// bit 2 = dosadora 2
// bit 3 = dosadora 3
// bit 4 = dosadora 4
// bit 5 = dosadora 5
// bit 6 = dosadora 6
float fator_calib_dosadora_1 = 0.0;
float fator_calib_dosadora_2 = 0.0;
float fator_calib_dosadora_3 = 0.0;
float dose_dosadora_1_personalizada = 0.0;
float dose_dosadora_2_personalizada = 0.0;
float dose_dosadora_3_personalizada = 0.0;
int hora_inicial_dosagem_personalizada_1 = 0;
int minuto_inicial_dosagem_personalizada_1 = 0;
int hora_final_dosagem_personalizada_1 = 0;
int minuto_final_dosagem_personalizada_1 = 0;
int terca_dosagem_personalizada_1 = 0;
int quarta_dosagem_personalizada_1 = 0;
int quinta_dosagem_personalizada_1 = 0;
int sexta_dosagem_personalizada_1 = 0;
int sabado_dosagem_personalizada_1 = 0;
int domingo_dosagem_personalizada_1 = 0;
int hora_inicial_dosagem_personalizada_2 = 0;
int minuto_inicial_dosagem_personalizada_2 = 0;
int hora_final_dosagem_personalizada_2 = 0;
int minuto_final_dosagem_personalizada_2 = 0;
int terca_dosagem_personalizada_2 = 0;
int quarta_dosagem_personalizada_2 = 0;
int quinta_dosagem_personalizada_2 = 0;
int sexta_dosagem_personalizada_2 = 0;
int sabado_dosagem_personalizada_2 = 0;
int domingo_dosagem_personalizada_2 = 0;
int hora_inicial_dosagem_personalizada_3 = 0;
int minuto_inicial_dosagem_personalizada_3 = 0;
int hora_final_dosagem_personalizada_3 = 0;
int minuto_final_dosagem_personalizada_3 = 0;
int terca_dosagem_personalizada_3 = 0;
int quarta_dosagem_personalizada_3 = 0;
int quinta_dosagem_personalizada_3 = 0;
int sexta_dosagem_personalizada_3 = 0;
int sabado_dosagem_personalizada_3 = 0;
int domingo_dosagem_personalizada_3 = 0;
int quantidade_dose_dosadora_1_personalizada = 0;
int quantidade_dose_dosadora_2_personalizada = 0;
int quantidade_dose_dosadora_3_personalizada = 0;
float fator_calib_dosadora_4 = 0.0;
float fator_calib_dosadora_5 = 0.0;
float fator_calib_dosadora_6 = 0.0;
float dose_dosadora_4_personalizada = 0.0;
float dose_dosadora_5_personalizada = 0.0;
float dose_dosadora_6_personalizada = 0.0;
int hora_inicial_dosagem_personalizada_4 = 0;
int minuto_inicial_dosagem_personalizada_4 = 0;
int hora_final_dosagem_personalizada_4 = 0;
int minuto_final_dosagem_personalizada_4 = 0;
int terca_dosagem_personalizada_4 = 0;
int quarta_dosagem_personalizada_4 = 0;
int quinta_dosagem_personalizada_4 = 0;
int sexta_dosagem_personalizada_4 = 0;
int sabado_dosagem_personalizada_4 = 0;
int domingo_dosagem_personalizada_4 = 0;
int hora_inicial_dosagem_personalizada_5 = 0;
int minuto_inicial_dosagem_personalizada_5 = 0;
int hora_final_dosagem_personalizada_5 = 0;
int minuto_final_dosagem_personalizada_5 = 0;
int terca_dosagem_personalizada_5 = 0;
int quarta_dosagem_personalizada_5 = 0;
int quinta_dosagem_personalizada_5 = 0;
int sexta_dosagem_personalizada_5 = 0;
int sabado_dosagem_personalizada_5 = 0;
int domingo_dosagem_personalizada_5 = 0;
int hora_inicial_dosagem_personalizada_6 = 0;
int minuto_inicial_dosagem_personalizada_6 = 0;
int hora_final_dosagem_personalizada_6 = 0;
int minuto_final_dosagem_personalizada_6 = 0;
int terca_dosagem_personalizada_6 = 0;
int quarta_dosagem_personalizada_6 = 0;
int quinta_dosagem_personalizada_6 = 0;
int sexta_dosagem_personalizada_6 = 0;
int sabado_dosagem_personalizada_6 = 0;
int domingo_dosagem_personalizada_6 = 0;
int quantidade_dose_dosadora_4_personalizada = 0;
int quantidade_dose_dosadora_5_personalizada = 0;
int quantidade_dose_dosadora_6_personalizada = 0;
//*****************************************************************************************
//************************** Variables temporales de las dosadoras ************************
//*****************************************************************************************
byte    modo_personalizado_on_1_temp2;
byte    modo_personalizado_on_2_temp2;
byte    modo_personalizado_on_3_temp2;
byte    modo_personalizado_on_4_temp2;
byte    modo_personalizado_on_5_temp2;
byte    modo_personalizado_on_6_temp2;
float fator_calib_dosadora_1_temp2;
float fator_calib_dosadora_2_temp2;
float fator_calib_dosadora_3_temp2;
float dose_dosadora_1_personalizada_temp2;
float dose_dosadora_2_personalizada_temp2;
float dose_dosadora_3_personalizada_temp2;
float dose_dosadora_1_manual_temp2;
float dose_dosadora_2_manual_temp2;
float dose_dosadora_3_manual_temp2;
int temp2hora_inicial_dosagem_personalizada_1;
int temp2minuto_inicial_dosagem_personalizada_1;
int temp2hora_final_dosagem_personalizada_1;
int temp2minuto_final_dosagem_personalizada_1;
int temp2segunda_dosagem_personalizada_1;
int temp2terca_dosagem_personalizada_1;
int temp2quarta_dosagem_personalizada_1;
int temp2quinta_dosagem_personalizada_1;
int temp2sexta_dosagem_personalizada_1;
int temp2sabado_dosagem_personalizada_1;
int temp2domingo_dosagem_personalizada_1;
int temp2hora_inicial_dosagem_personalizada_2;
int temp2minuto_inicial_dosagem_personalizada_2;
int temp2hora_final_dosagem_personalizada_2;
int temp2minuto_final_dosagem_personalizada_2;
int temp2segunda_dosagem_personalizada_2;
int temp2terca_dosagem_personalizada_2;
int temp2quarta_dosagem_personalizada_2;
int temp2quinta_dosagem_personalizada_2;
int temp2sexta_dosagem_personalizada_2;
int temp2sabado_dosagem_personalizada_2;
int temp2domingo_dosagem_personalizada_2;
int temp2hora_inicial_dosagem_personalizada_3;
int temp2minuto_inicial_dosagem_personalizada_3;
int temp2hora_final_dosagem_personalizada_3;
int temp2minuto_final_dosagem_personalizada_3;
int temp2segunda_dosagem_personalizada_3;
int temp2terca_dosagem_personalizada_3;
int temp2quarta_dosagem_personalizada_3;
int temp2quinta_dosagem_personalizada_3;
int temp2sexta_dosagem_personalizada_3;
int temp2sabado_dosagem_personalizada_3;
int temp2domingo_dosagem_personalizada_3;
int quantidade_dose_dosadora_1_personalizada_temp2;
int quantidade_dose_dosadora_2_personalizada_temp2;
int quantidade_dose_dosadora_3_personalizada_temp2;
float fator_calib_dosadora_4_temp2;
float fator_calib_dosadora_5_temp2;
float fator_calib_dosadora_6_temp2;
float dose_dosadora_4_personalizada_temp2;
float dose_dosadora_5_personalizada_temp2;
float dose_dosadora_6_personalizada_temp2;
float dose_dosadora_4_manual_temp2;
float dose_dosadora_5_manual_temp2;
float dose_dosadora_6_manual_temp2;
int temp2hora_inicial_dosagem_personalizada_4;
int temp2minuto_inicial_dosagem_personalizada_4;
int temp2hora_final_dosagem_personalizada_4;
int temp2minuto_final_dosagem_personalizada_4;
int temp2segunda_dosagem_personalizada_4;
int temp2terca_dosagem_personalizada_4;
int temp2quarta_dosagem_personalizada_4;
int temp2quinta_dosagem_personalizada_4;
int temp2sexta_dosagem_personalizada_4;
int temp2sabado_dosagem_personalizada_4;
int temp2domingo_dosagem_personalizada_4;
int temp2hora_inicial_dosagem_personalizada_5;
int temp2minuto_inicial_dosagem_personalizada_5;
int temp2hora_final_dosagem_personalizada_5;
int temp2minuto_final_dosagem_personalizada_5;
int temp2segunda_dosagem_personalizada_5;
int temp2terca_dosagem_personalizada_5;
int temp2quarta_dosagem_personalizada_5;
int temp2quinta_dosagem_personalizada_5;
int temp2sexta_dosagem_personalizada_5;
int temp2sabado_dosagem_personalizada_5;
int temp2domingo_dosagem_personalizada_5;
int temp2hora_inicial_dosagem_personalizada_6;
int temp2minuto_inicial_dosagem_personalizada_6;
int temp2hora_final_dosagem_personalizada_6;
int temp2minuto_final_dosagem_personalizada_6;
int temp2segunda_dosagem_personalizada_6;
int temp2terca_dosagem_personalizada_6;
int temp2quarta_dosagem_personalizada_6;
int temp2quinta_dosagem_personalizada_6;
int temp2sexta_dosagem_personalizada_6;
int temp2sabado_dosagem_personalizada_6;
int temp2domingo_dosagem_personalizada_6;
int quantidade_dose_dosadora_4_personalizada_temp2;
int quantidade_dose_dosadora_5_personalizada_temp2;
int quantidade_dose_dosadora_6_personalizada_temp2;

