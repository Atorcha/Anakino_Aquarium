//**********************************************************************************************
//************************ Funciones EEPROM ******************************************************
//**********************************************************************************************
struct config_t                              // Temperatura
{
  int tempset;
  int tempoff;
  int tempalarm;
} 
tempSettings;





struct config_luz                        // Luz noturna
{
  int MaxI_t;
  int MinI_t;
} 
luznoturna;

struct config_timers
{
  int on1_minuto_temp;
  int on1_hora_temp;
  int on2_minuto_temp;
  int on2_hora_temp;
  int on3_minuto_temp;
  int on3_hora_temp;
  int on4_minuto_temp;
  int on4_hora_temp;
  int on5_minuto_temp;
  int on5_hora_temp;
  int off1_minuto_temp;
  int off1_hora_temp;
  int off2_minuto_temp;
  int off2_hora_temp;
  int off3_minuto_temp;
  int off3_hora_temp;
  int off4_minuto_temp;
  int off4_hora_temp;
  int off5_minuto_temp;
  int off5_hora_temp;
  int temporizador_1_ativado_temp;
  int temporizador_2_ativado_temp;
  int temporizador_3_ativado_temp;
  int temporizador_4_ativado_temp;
  int temporizador_5_ativado_temp;
}
timers;

struct led_estado
{
  int led_estado_temp2;
}
estado;

struct comedero
{
 int comedero1_Temp2;
 int comedero2_Temp2;
 int comedero3_Temp2;
 int comedero4_Temp2;

 int comedero1H_Temp2;
 int comedero1M_Temp2;
 int comedero2H_Temp2;
 int comedero2M_Temp2;
 int comedero3H_Temp2;
 int comedero3M_Temp2;
 int comedero4H_Temp2;
 int comedero4M_Temp2;
 }
 comederos;


void SaveLEDToEEPROM()                  
{
  EEPROM.write(0, 123);         //to determine if data available in EEPROM
 
}

void SaveTempToEEPROM()
{
  tempSettings.tempset = int(setTempC*10);
  tempSettings.tempoff = int(offTempC*10);
  tempSettings.tempalarm = int(alarmTempC*10);
  EEPROM_writeAnything(482, tempSettings);
}


void Salvar_luz_noturna_EEPROM()
{
  luznoturna.MinI_t = int(MinI);
  luznoturna.MaxI_t = int(MaxI);
  EEPROM_writeAnything(712, luznoturna);
}
void salvar_timers_EEPROM()
{
  timers.on1_minuto_temp = int(on1_minuto); 
  timers.on1_hora_temp = int(on1_hora);
  timers.on2_minuto_temp = int(on2_minuto); 
  timers.on2_hora_temp = int(on2_hora);
  timers.on3_minuto_temp = int(on3_minuto); 
  timers.on3_hora_temp = int(on3_hora);
  timers.on4_minuto_temp = int(on4_minuto); 
  timers.on4_hora_temp = int(on4_hora);
  timers.on5_minuto_temp = int(on5_minuto); 
  timers.on5_hora_temp = int(on5_hora);
  timers.off1_minuto_temp = int(off1_minuto); 
  timers.off1_hora_temp = int(off1_hora);
  timers.off2_minuto_temp = int(off2_minuto); 
  timers.off2_hora_temp = int(off2_hora);
  timers.off3_minuto_temp = int(off3_minuto); 
  timers.off3_hora_temp = int(off3_hora);
  timers.off4_minuto_temp = int(off4_minuto); 
  timers.off4_hora_temp = int(off4_hora);
  timers.off5_minuto_temp = int(off5_minuto); 
  timers.off5_hora_temp = int(off5_hora);  
  timers.temporizador_1_ativado_temp = int(temporizador_1_ativado);
  timers.temporizador_2_ativado_temp = int(temporizador_2_ativado);
  timers.temporizador_3_ativado_temp = int(temporizador_3_ativado);
  timers.temporizador_4_ativado_temp = int(temporizador_4_ativado);
  timers.temporizador_5_ativado_temp = int(temporizador_5_ativado);
  EEPROM_writeAnything(716, timers);
}

void salvar_estado_EEPROM()
{
  estado.led_estado_temp2 = int (led_estado);
  EEPROM_writeAnything(766, estado);
}
  
void salvar_comederos_EEPROM()
{
  comederos.comedero1_Temp2 = int(comedero1);
  comederos.comedero2_Temp2 = int(comedero2);
  comederos.comedero3_Temp2 = int(comedero3);
  comederos.comedero4_Temp2 = int(comedero4);
  comederos.comedero1H_Temp2= int(comedero1H);
  comederos.comedero1M_Temp2= int(comedero1M);
  comederos.comedero2H_Temp2= int(comedero2H);
  comederos.comedero2M_Temp2= int(comedero2M);
  comederos.comedero3H_Temp2= int(comedero3H);
  comederos.comedero3M_Temp2= int(comedero3M);
  comederos.comedero4H_Temp2= int(comedero4H);
  comederos.comedero4M_Temp2= int(comedero4M);
  EEPROM_writeAnything(768, comederos);
}
  
  
void ReadFromEEPROM()
{
  int k = EEPROM.read(0);
  if (k==123) 
  {
  
  }

  EEPROM_readAnything(482, tempSettings);  
  setTempC = tempSettings.tempset;
  setTempC /=10;
  offTempC = tempSettings.tempoff;
  offTempC /=10;
  alarmTempC = tempSettings.tempalarm;
  alarmTempC /= 10;

}


void ler_luz_noturna_EEPROM()
{
  EEPROM_readAnything(712, luznoturna);  
  MinI = luznoturna.MinI_t;
  MaxI = luznoturna.MaxI_t;
}
void ler_timers_EEPROM()
{
  EEPROM_readAnything(716, timers);
  on1_minuto = timers.on1_minuto_temp; 
  on1_hora = timers.on1_hora_temp;
  on2_minuto = timers.on2_minuto_temp; 
  on2_hora = timers.on2_hora_temp;
  on3_minuto = timers.on3_minuto_temp; 
  on3_hora = timers.on3_hora_temp;
  on4_minuto = timers.on4_minuto_temp; 
  on4_hora = timers.on4_hora_temp;
  on5_minuto = timers.on5_minuto_temp; 
  on5_hora = timers.on5_hora_temp;
  off1_minuto = timers.off1_minuto_temp; 
  off1_hora = timers.off1_hora_temp;
  off2_minuto = timers.off2_minuto_temp; 
  off2_hora = timers.off2_hora_temp;
  off3_minuto = timers.off3_minuto_temp; 
  off3_hora = timers.off3_hora_temp;
  off4_minuto = timers.off4_minuto_temp; 
  off4_hora = timers.off4_hora_temp;
  off5_minuto = timers.off5_minuto_temp; 
  off5_hora = timers.off5_hora_temp;
  temporizador_1_ativado = timers.temporizador_1_ativado_temp;
  temporizador_2_ativado = timers.temporizador_2_ativado_temp;
  temporizador_3_ativado = timers.temporizador_3_ativado_temp;
  temporizador_4_ativado = timers.temporizador_4_ativado_temp;
  temporizador_5_ativado = timers.temporizador_5_ativado_temp;
}

void ler_led_estado_EEPROM()
{
  EEPROM_readAnything(766, estado);
  led_estado = estado.led_estado_temp2;
}

void ler_comederos_EEPROM()
{
  EEPROM_readAnything(768,comederos);
  comedero1 = comederos.comedero1_Temp2;
  comedero2 = comederos.comedero2_Temp2;
  comedero3 = comederos.comedero3_Temp2;
  comedero4 = comederos.comedero4_Temp2;
  comedero1H = comederos.comedero1H_Temp2;
  comedero1M = comederos.comedero1M_Temp2;
  comedero2H = comederos.comedero2H_Temp2;
  comedero2M = comederos.comedero2M_Temp2;
  comedero3H = comederos.comedero3H_Temp2;
  comedero3M = comederos.comedero3M_Temp2;
  comedero4H = comederos.comedero4H_Temp2;
  comedero4M = comederos.comedero4M_Temp2;
  }
