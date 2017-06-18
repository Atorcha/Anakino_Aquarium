//------------------------setup------------------------------
void setup()
{
  Serial.begin(38400); //Inicia a comunicação com a  porta serial 0 para obter mensagens de depuração.   
//  Serial2.begin(38400); //Inicia a comunicação com a  porta serial 2 onde estão conectados os "stamps".

  Ethernet.begin(mac, ip);
  server.begin();
  pinMode(ledPinWhite, OUTPUT);
  pinMode(ledPinMoon, OUTPUT); 
  pinMode(calentadorPin, OUTPUT);
  pinMode(alarmPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode (4, OUTPUT);  //sd card
  digitalWrite (4, HIGH);
  pinMode (dosadora1, OUTPUT);
  pinMode (dosadora2, OUTPUT);
  pinMode (dosadora3, OUTPUT);
  pinMode (dosadora4, OUTPUT);
  pinMode (dosadora5, OUTPUT);
  pinMode (dosadora6, OUTPUT);  
  pinMode (temporizador1, OUTPUT);
  pinMode (temporizador2, OUTPUT);
  pinMode (temporizador3, OUTPUT);
  pinMode (temporizador4, OUTPUT);
  pinMode (temporizador5, OUTPUT);
  pinMode (bomba, OUTPUT);
  pinMode(nivel_acu, INPUT);
  pinMode(nivel_dep, INPUT);  
   
  myStepper.setSpeed(60); // set the speed at 60 rpm
  
  // Con esto apagamos todos los reles.  
    byte n;
    for(n=43; n < 51; n = n + 1)
       {
         digitalWrite( n, HIGH);
       } 


  myGLCD.InitLCD(LANDSCAPE); // Orientação da imagem no LCD.
  myGLCD.clrScr(); // Limpa o LCD.

  myTouch.InitTouch(LANDSCAPE); // Orientação do "touch screen".
  myTouch.setPrecision(PREC_MEDIUM); // Define a precisão do "touch screen".

  sensors.begin();     //Inicia as leituras das sondas de temperatura.
  sensors.setResolution(sensor_agua, 12); // Define a resolução em 10 bits.
  sensors.setResolution(sensor_dissipador, 12); // Define a resolução em 10 bits.

  rtc.halt(false); // Inicia o funcionamento do RTC.
  
  //Lee las variables guardadas en la eeprom.
  ReadFromEEPROM();
  lerPHAEEPROM();
  ler_dosadora_EEPROM();  
  ler_luz_noturna_EEPROM();
  ler_timers_EEPROM();
  ler_led_estado_EEPROM();
  ler_comederos_EEPROM();
  
  card.init(SPI_QUARTER_SPEED,chipselect); // Inicia a comunicação com o cartão SD.
  volume.init(&card);
  root.openRoot(&volume);
  
  mainScreen(true); // Exibe a tela inicial no LCD.
}

void SetRele( int Pin, boolean Estado )  //Funcion que hace que el rele chino funcione bien y se puede poner LOW o HIGH segun corresponda.
{
 
 digitalWrite( Pin, !Estado );

}

