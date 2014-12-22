//**********************************************************************************************
//************************ Funciones EEPROM ******************************************************
//**********************************************************************************************
struct luces                   // Estructura luces
{
  int hora_on_set;
  int minuto_on_set;
  int hora_off_set;
  int minuto_off_set;
  int duracion_set;
  int potencia_set;
  int percent_set;
}
lucesSettings;


struct config_t                              // Temperatura
{
  int tempset;
  int tempoff;
  int tempalarm;
} 
tempSettings;



struct config_PHA                         // PH de acuario
{
  int PHAset;
  int PHAoff;
  int PHAalarm;
} 
PHASettings;




struct config_dos
{
  int fator_calib_dosadora_1_temp;
  int fator_calib_dosadora_2_temp;
  int fator_calib_dosadora_3_temp;
  int dose_dosadora_1_personalizada_temp;
  int dose_dosadora_2_personalizada_temp;
  int dose_dosadora_3_personalizada_temp;
  int hora_inicial_dosagem_personalizada_1_temp; 
  int minuto_inicial_dosagem_personalizada_1_temp;
  int hora_final_dosagem_personalizada_1_temp; 
  int minuto_final_dosagem_personalizada_1_temp; 
  byte segunda_dosagem_personalizada_1_temp; 
  int terca_dosagem_personalizada_1_temp; 
  int quarta_dosagem_personalizada_1_temp; 
  int quinta_dosagem_personalizada_1_temp; 
  int sexta_dosagem_personalizada_1_temp; 
  int sabado_dosagem_personalizada_1_temp; 
  int domingo_dosagem_personalizada_1_temp;
  int hora_inicial_dosagem_personalizada_2_temp; 
  int minuto_inicial_dosagem_personalizada_2_temp;
  int hora_final_dosagem_personalizada_2_temp; 
  int minuto_final_dosagem_personalizada_2_temp; 
  int terca_dosagem_personalizada_2_temp; 
  int quarta_dosagem_personalizada_2_temp; 
  int quinta_dosagem_personalizada_2_temp; 
  int sexta_dosagem_personalizada_2_temp; 
  int sabado_dosagem_personalizada_2_temp; 
  int domingo_dosagem_personalizada_2_temp;
  int hora_inicial_dosagem_personalizada_3_temp; 
  int minuto_inicial_dosagem_personalizada_3_temp;
  int hora_final_dosagem_personalizada_3_temp; 
  int minuto_final_dosagem_personalizada_3_temp;  
  int terca_dosagem_personalizada_3_temp; 
  int quarta_dosagem_personalizada_3_temp; 
  int quinta_dosagem_personalizada_3_temp; 
  int sexta_dosagem_personalizada_3_temp; 
  int sabado_dosagem_personalizada_3_temp; 
  int domingo_dosagem_personalizada_3_temp;
  int quantidade_dose_dosadora_1_personalizada_temp;
  int quantidade_dose_dosadora_2_personalizada_temp;
  int quantidade_dose_dosadora_3_personalizada_temp;
  byte modo_personalizado_on_1_temp;  
  int fator_calib_dosadora_4_temp;
  int fator_calib_dosadora_5_temp;
  int fator_calib_dosadora_6_temp;
  int dose_dosadora_4_personalizada_temp;
  int dose_dosadora_5_personalizada_temp;
  int dose_dosadora_6_personalizada_temp;
  int hora_inicial_dosagem_personalizada_4_temp; 
  int minuto_inicial_dosagem_personalizada_4_temp;
  int hora_final_dosagem_personalizada_4_temp; 
  int minuto_final_dosagem_personalizada_4_temp; 
  int terca_dosagem_personalizada_4_temp; 
  int quarta_dosagem_personalizada_4_temp; 
  int quinta_dosagem_personalizada_4_temp; 
  int sexta_dosagem_personalizada_4_temp; 
  int sabado_dosagem_personalizada_4_temp; 
  int domingo_dosagem_personalizada_4_temp;
  int hora_inicial_dosagem_personalizada_5_temp; 
  int minuto_inicial_dosagem_personalizada_5_temp;
  int hora_final_dosagem_personalizada_5_temp; 
  int minuto_final_dosagem_personalizada_5_temp; 
  int terca_dosagem_personalizada_5_temp; 
  int quarta_dosagem_personalizada_5_temp; 
  int quinta_dosagem_personalizada_5_temp; 
  int sexta_dosagem_personalizada_5_temp; 
  int sabado_dosagem_personalizada_5_temp; 
  int domingo_dosagem_personalizada_5_temp;
  int hora_inicial_dosagem_personalizada_6_temp; 
  int minuto_inicial_dosagem_personalizada_6_temp;
  int hora_final_dosagem_personalizada_6_temp; 
  int minuto_final_dosagem_personalizada_6_temp; 
  int terca_dosagem_personalizada_6_temp; 
  int quarta_dosagem_personalizada_6_temp; 
  int quinta_dosagem_personalizada_6_temp; 
  int sexta_dosagem_personalizada_6_temp; 
  int sabado_dosagem_personalizada_6_temp; 
  int domingo_dosagem_personalizada_6_temp;
  int quantidade_dose_dosadora_4_personalizada_temp;
  int quantidade_dose_dosadora_5_personalizada_temp;
  int quantidade_dose_dosadora_6_personalizada_temp;
}
dosaconfig;


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
  lucesSettings.hora_on_set=int (led_on_hora);
  lucesSettings.minuto_on_set=int (led_on_minuto);
  lucesSettings.hora_off_set=int (led_off_hora);
  lucesSettings.minuto_off_set=int (led_off_minuto);
  lucesSettings.duracion_set=int (amanecer_anochecer);
  lucesSettings.potencia_set=int (pwm_absoluto);
  lucesSettings.percent_set=int (pwm_percent);
  EEPROM_writeAnything(1, lucesSettings);
   
}

void SaveTempToEEPROM()
{
  tempSettings.tempset = int(setTempC*10);
  tempSettings.tempoff = int(offTempC*10);
  tempSettings.tempalarm = int(alarmTempC*10);
  EEPROM_writeAnything(482, tempSettings);
}

void SavePHAToEEPROM()
{
  PHASettings.PHAset = int(setPHA*10);
  PHASettings.PHAoff = int(offPHA*10);
  PHASettings.PHAalarm = int(alarmPHA*10);
  EEPROM_writeAnything(520, PHASettings);
}


void Salvar_dosadora_EEPROM()
{
  dosaconfig.fator_calib_dosadora_1_temp = int (fator_calib_dosadora_1*10);
  dosaconfig.fator_calib_dosadora_2_temp = int (fator_calib_dosadora_2*10);
  dosaconfig.fator_calib_dosadora_3_temp = int (fator_calib_dosadora_3*10);
  dosaconfig.dose_dosadora_1_personalizada_temp = int(dose_dosadora_1_personalizada*10);
  dosaconfig.dose_dosadora_2_personalizada_temp = int(dose_dosadora_2_personalizada*10);
  dosaconfig.dose_dosadora_3_personalizada_temp = int(dose_dosadora_3_personalizada*10);
  dosaconfig.hora_inicial_dosagem_personalizada_1_temp = int(hora_inicial_dosagem_personalizada_1);
  dosaconfig.minuto_inicial_dosagem_personalizada_1_temp = int(minuto_inicial_dosagem_personalizada_1); 
  dosaconfig.hora_final_dosagem_personalizada_1_temp = int(hora_final_dosagem_personalizada_1);
  dosaconfig.minuto_final_dosagem_personalizada_1_temp = int(minuto_final_dosagem_personalizada_1);
  dosaconfig.segunda_dosagem_personalizada_1_temp = segunda_dosagem_personalizada;
  dosaconfig.terca_dosagem_personalizada_1_temp = int(terca_dosagem_personalizada_1);
  dosaconfig.quarta_dosagem_personalizada_1_temp = int(quarta_dosagem_personalizada_1);
  dosaconfig.quinta_dosagem_personalizada_1_temp = int(quinta_dosagem_personalizada_1);
  dosaconfig.sexta_dosagem_personalizada_1_temp = int(sexta_dosagem_personalizada_1);
  dosaconfig.sabado_dosagem_personalizada_1_temp = int(sabado_dosagem_personalizada_1);
  dosaconfig.domingo_dosagem_personalizada_1_temp = int(domingo_dosagem_personalizada_1);
  dosaconfig.hora_inicial_dosagem_personalizada_2_temp = int(hora_inicial_dosagem_personalizada_2);
  dosaconfig.minuto_inicial_dosagem_personalizada_2_temp = int(minuto_inicial_dosagem_personalizada_2); 
  dosaconfig.hora_final_dosagem_personalizada_2_temp = int(hora_final_dosagem_personalizada_2);
  dosaconfig.minuto_final_dosagem_personalizada_2_temp = int(minuto_final_dosagem_personalizada_2);
  dosaconfig.terca_dosagem_personalizada_2_temp = int(terca_dosagem_personalizada_2);
  dosaconfig.quarta_dosagem_personalizada_2_temp = int(quarta_dosagem_personalizada_2);
  dosaconfig.quinta_dosagem_personalizada_2_temp = int(quinta_dosagem_personalizada_2);
  dosaconfig.sexta_dosagem_personalizada_2_temp = int(sexta_dosagem_personalizada_2);
  dosaconfig.sabado_dosagem_personalizada_2_temp = int(sabado_dosagem_personalizada_2);
  dosaconfig.domingo_dosagem_personalizada_2_temp = int(domingo_dosagem_personalizada_2);
  dosaconfig.hora_inicial_dosagem_personalizada_3_temp = int(hora_inicial_dosagem_personalizada_3);
  dosaconfig.minuto_inicial_dosagem_personalizada_3_temp = int(minuto_inicial_dosagem_personalizada_3); 
  dosaconfig.hora_final_dosagem_personalizada_3_temp = int(hora_final_dosagem_personalizada_3);
  dosaconfig.minuto_final_dosagem_personalizada_3_temp = int(minuto_final_dosagem_personalizada_3);
  dosaconfig.terca_dosagem_personalizada_3_temp = int(terca_dosagem_personalizada_3);
  dosaconfig.quarta_dosagem_personalizada_3_temp = int(quarta_dosagem_personalizada_3);
  dosaconfig.quinta_dosagem_personalizada_3_temp = int(quinta_dosagem_personalizada_3);
  dosaconfig.sexta_dosagem_personalizada_3_temp = int(sexta_dosagem_personalizada_3);
  dosaconfig.sabado_dosagem_personalizada_3_temp = int(sabado_dosagem_personalizada_3);
  dosaconfig.domingo_dosagem_personalizada_3_temp = int(domingo_dosagem_personalizada_3);
  dosaconfig.quantidade_dose_dosadora_1_personalizada_temp = int(quantidade_dose_dosadora_1_personalizada);
  dosaconfig.quantidade_dose_dosadora_2_personalizada_temp = int(quantidade_dose_dosadora_2_personalizada);
  dosaconfig.quantidade_dose_dosadora_3_personalizada_temp = int(quantidade_dose_dosadora_3_personalizada);
  dosaconfig.modo_personalizado_on_1_temp = modo_personalizado_on;  
  dosaconfig.fator_calib_dosadora_4_temp = int (fator_calib_dosadora_4*10);
  dosaconfig.fator_calib_dosadora_5_temp = int (fator_calib_dosadora_5*10);
  dosaconfig.fator_calib_dosadora_6_temp = int (fator_calib_dosadora_6*10);
  dosaconfig.dose_dosadora_4_personalizada_temp = int(dose_dosadora_4_personalizada*10);
  dosaconfig.dose_dosadora_5_personalizada_temp = int(dose_dosadora_5_personalizada*10);
  dosaconfig.dose_dosadora_6_personalizada_temp = int(dose_dosadora_6_personalizada*10);
  dosaconfig.hora_inicial_dosagem_personalizada_4_temp = int(hora_inicial_dosagem_personalizada_4);
  dosaconfig.minuto_inicial_dosagem_personalizada_4_temp = int(minuto_inicial_dosagem_personalizada_4); 
  dosaconfig.hora_final_dosagem_personalizada_4_temp = int(hora_final_dosagem_personalizada_4);
  dosaconfig.minuto_final_dosagem_personalizada_4_temp = int(minuto_final_dosagem_personalizada_4);
  dosaconfig.terca_dosagem_personalizada_4_temp = int(terca_dosagem_personalizada_4);
  dosaconfig.quarta_dosagem_personalizada_4_temp = int(quarta_dosagem_personalizada_4);
  dosaconfig.quinta_dosagem_personalizada_4_temp = int(quinta_dosagem_personalizada_4);
  dosaconfig.sexta_dosagem_personalizada_4_temp = int(sexta_dosagem_personalizada_4);
  dosaconfig.sabado_dosagem_personalizada_4_temp = int(sabado_dosagem_personalizada_4);
  dosaconfig.domingo_dosagem_personalizada_4_temp = int(domingo_dosagem_personalizada_4);
  dosaconfig.hora_inicial_dosagem_personalizada_5_temp = int(hora_inicial_dosagem_personalizada_5);
  dosaconfig.minuto_inicial_dosagem_personalizada_5_temp = int(minuto_inicial_dosagem_personalizada_5); 
  dosaconfig.hora_final_dosagem_personalizada_5_temp = int(hora_final_dosagem_personalizada_5);
  dosaconfig.minuto_final_dosagem_personalizada_5_temp = int(minuto_final_dosagem_personalizada_5);
  dosaconfig.terca_dosagem_personalizada_5_temp = int(terca_dosagem_personalizada_5);
  dosaconfig.quarta_dosagem_personalizada_5_temp = int(quarta_dosagem_personalizada_5);
  dosaconfig.quinta_dosagem_personalizada_5_temp = int(quinta_dosagem_personalizada_5);
  dosaconfig.sexta_dosagem_personalizada_5_temp = int(sexta_dosagem_personalizada_5);
  dosaconfig.sabado_dosagem_personalizada_5_temp = int(sabado_dosagem_personalizada_5);
  dosaconfig.domingo_dosagem_personalizada_5_temp = int(domingo_dosagem_personalizada_5);
  dosaconfig.hora_inicial_dosagem_personalizada_6_temp = int(hora_inicial_dosagem_personalizada_6);
  dosaconfig.minuto_inicial_dosagem_personalizada_6_temp = int(minuto_inicial_dosagem_personalizada_6); 
  dosaconfig.hora_final_dosagem_personalizada_6_temp = int(hora_final_dosagem_personalizada_6);
  dosaconfig.minuto_final_dosagem_personalizada_6_temp = int(minuto_final_dosagem_personalizada_6);
  dosaconfig.terca_dosagem_personalizada_6_temp = int(terca_dosagem_personalizada_6);
  dosaconfig.quarta_dosagem_personalizada_6_temp = int(quarta_dosagem_personalizada_6);
  dosaconfig.quinta_dosagem_personalizada_6_temp = int(quinta_dosagem_personalizada_6);
  dosaconfig.sexta_dosagem_personalizada_6_temp = int(sexta_dosagem_personalizada_6);
  dosaconfig.sabado_dosagem_personalizada_6_temp = int(sabado_dosagem_personalizada_6);
  dosaconfig.domingo_dosagem_personalizada_6_temp = int(domingo_dosagem_personalizada_6);
  dosaconfig.quantidade_dose_dosadora_4_personalizada_temp = int(quantidade_dose_dosadora_4_personalizada);
  dosaconfig.quantidade_dose_dosadora_5_personalizada_temp = int(quantidade_dose_dosadora_5_personalizada);
  dosaconfig.quantidade_dose_dosadora_6_personalizada_temp = int(quantidade_dose_dosadora_6_personalizada);
  EEPROM_writeAnything(532, dosaconfig);
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
  EEPROM_readAnything(1, lucesSettings);
  led_on_hora=lucesSettings.hora_on_set;
  led_on_minuto=lucesSettings.minuto_on_set;
  led_off_hora=lucesSettings.hora_off_set;
  led_off_minuto=lucesSettings.minuto_off_set;
  amanecer_anochecer=lucesSettings.duracion_set;
  pwm_absoluto=lucesSettings.potencia_set;
  pwm_percent=lucesSettings.percent_set;
  

  EEPROM_readAnything(482, tempSettings);  
  setTempC = tempSettings.tempset;
  setTempC /=10;
  offTempC = tempSettings.tempoff;
  offTempC /=10;
  alarmTempC = tempSettings.tempalarm;
  alarmTempC /= 10;

}


void lerPHAEEPROM()
{
  EEPROM_readAnything(520, PHASettings);  
  setPHA = PHASettings.PHAset;
  setPHA /=10;
  offPHA = PHASettings.PHAoff;
  offPHA /=10;
  alarmPHA = PHASettings.PHAalarm;
  alarmPHA /= 10;
}


void ler_dosadora_EEPROM()
{
  EEPROM_readAnything(532,dosaconfig);
  fator_calib_dosadora_1 = dosaconfig.fator_calib_dosadora_1_temp;
  fator_calib_dosadora_1 /=10;
  fator_calib_dosadora_2 = dosaconfig.fator_calib_dosadora_2_temp;
  fator_calib_dosadora_2 /=10;
  fator_calib_dosadora_3 = dosaconfig.fator_calib_dosadora_3_temp;
  fator_calib_dosadora_3 /=10;
  dose_dosadora_1_personalizada = dosaconfig.dose_dosadora_1_personalizada_temp;
  dose_dosadora_1_personalizada /= 10;
  dose_dosadora_2_personalizada = dosaconfig.dose_dosadora_2_personalizada_temp;
  dose_dosadora_2_personalizada /= 10;
  dose_dosadora_3_personalizada = dosaconfig.dose_dosadora_3_personalizada_temp; 
  dose_dosadora_3_personalizada /= 10;
  hora_inicial_dosagem_personalizada_1 = dosaconfig.hora_inicial_dosagem_personalizada_1_temp;
  minuto_inicial_dosagem_personalizada_1 = dosaconfig.minuto_inicial_dosagem_personalizada_1_temp;
  hora_final_dosagem_personalizada_1 = dosaconfig.hora_final_dosagem_personalizada_1_temp;  
  minuto_final_dosagem_personalizada_1 = dosaconfig.minuto_final_dosagem_personalizada_1_temp; 
  segunda_dosagem_personalizada = dosaconfig.segunda_dosagem_personalizada_1_temp; 
  terca_dosagem_personalizada_1 = dosaconfig.terca_dosagem_personalizada_1_temp; 
  quarta_dosagem_personalizada_1 = dosaconfig.quarta_dosagem_personalizada_1_temp;
  quinta_dosagem_personalizada_1 = dosaconfig.quinta_dosagem_personalizada_1_temp;
  sexta_dosagem_personalizada_1  = dosaconfig.sexta_dosagem_personalizada_1_temp;
  sabado_dosagem_personalizada_1 = dosaconfig.sabado_dosagem_personalizada_1_temp;
  domingo_dosagem_personalizada_1 = dosaconfig.domingo_dosagem_personalizada_1_temp;
  hora_inicial_dosagem_personalizada_2 = dosaconfig.hora_inicial_dosagem_personalizada_2_temp;
  minuto_inicial_dosagem_personalizada_2 = dosaconfig.minuto_inicial_dosagem_personalizada_2_temp;
  hora_final_dosagem_personalizada_2 = dosaconfig.hora_final_dosagem_personalizada_2_temp;  
  minuto_final_dosagem_personalizada_2 = dosaconfig.minuto_final_dosagem_personalizada_2_temp; 
  terca_dosagem_personalizada_2 = dosaconfig.terca_dosagem_personalizada_2_temp; 
  quarta_dosagem_personalizada_2 = dosaconfig.quarta_dosagem_personalizada_2_temp;
  quinta_dosagem_personalizada_2 = dosaconfig.quinta_dosagem_personalizada_2_temp;
  sexta_dosagem_personalizada_2  = dosaconfig.sexta_dosagem_personalizada_2_temp;
  sabado_dosagem_personalizada_2 = dosaconfig.sabado_dosagem_personalizada_2_temp;
  domingo_dosagem_personalizada_2 = dosaconfig.domingo_dosagem_personalizada_2_temp;
  hora_inicial_dosagem_personalizada_3 = dosaconfig.hora_inicial_dosagem_personalizada_3_temp;
  minuto_inicial_dosagem_personalizada_3 = dosaconfig.minuto_inicial_dosagem_personalizada_3_temp;
  hora_final_dosagem_personalizada_3 = dosaconfig.hora_final_dosagem_personalizada_3_temp;  
  minuto_final_dosagem_personalizada_3 = dosaconfig.minuto_final_dosagem_personalizada_3_temp;  
  terca_dosagem_personalizada_3 = dosaconfig.terca_dosagem_personalizada_3_temp; 
  quarta_dosagem_personalizada_3 = dosaconfig.quarta_dosagem_personalizada_3_temp;
  quinta_dosagem_personalizada_3 = dosaconfig.quinta_dosagem_personalizada_3_temp;
  sexta_dosagem_personalizada_3  = dosaconfig.sexta_dosagem_personalizada_3_temp;
  sabado_dosagem_personalizada_3 = dosaconfig.sabado_dosagem_personalizada_3_temp;
  domingo_dosagem_personalizada_3 = dosaconfig.domingo_dosagem_personalizada_3_temp;
  quantidade_dose_dosadora_1_personalizada = dosaconfig.quantidade_dose_dosadora_1_personalizada_temp;
  quantidade_dose_dosadora_2_personalizada = dosaconfig.quantidade_dose_dosadora_2_personalizada_temp;
  quantidade_dose_dosadora_3_personalizada = dosaconfig.quantidade_dose_dosadora_3_personalizada_temp;
  modo_personalizado_on = dosaconfig.modo_personalizado_on_1_temp;
  fator_calib_dosadora_4 = dosaconfig.fator_calib_dosadora_4_temp;
  fator_calib_dosadora_4 /=10;
  fator_calib_dosadora_5 = dosaconfig.fator_calib_dosadora_5_temp;
  fator_calib_dosadora_5 /=10;
  fator_calib_dosadora_6 = dosaconfig.fator_calib_dosadora_6_temp;
  fator_calib_dosadora_6 /=10;
  dose_dosadora_4_personalizada = dosaconfig.dose_dosadora_4_personalizada_temp;
  dose_dosadora_4_personalizada /= 10;
  dose_dosadora_5_personalizada = dosaconfig.dose_dosadora_5_personalizada_temp;
  dose_dosadora_5_personalizada /= 10;
  dose_dosadora_6_personalizada = dosaconfig.dose_dosadora_6_personalizada_temp; 
  dose_dosadora_6_personalizada /= 10;
  hora_inicial_dosagem_personalizada_4 = dosaconfig.hora_inicial_dosagem_personalizada_4_temp;
  minuto_inicial_dosagem_personalizada_4 = dosaconfig.minuto_inicial_dosagem_personalizada_4_temp;
  hora_final_dosagem_personalizada_4 = dosaconfig.hora_final_dosagem_personalizada_4_temp;  
  minuto_final_dosagem_personalizada_4 = dosaconfig.minuto_final_dosagem_personalizada_4_temp; 
  terca_dosagem_personalizada_4 = dosaconfig.terca_dosagem_personalizada_4_temp; 
  quarta_dosagem_personalizada_4 = dosaconfig.quarta_dosagem_personalizada_4_temp;
  quinta_dosagem_personalizada_4 = dosaconfig.quinta_dosagem_personalizada_4_temp;
  sexta_dosagem_personalizada_4  = dosaconfig.sexta_dosagem_personalizada_4_temp;
  sabado_dosagem_personalizada_4 = dosaconfig.sabado_dosagem_personalizada_4_temp;
  domingo_dosagem_personalizada_4 = dosaconfig.domingo_dosagem_personalizada_4_temp;
  hora_inicial_dosagem_personalizada_5 = dosaconfig.hora_inicial_dosagem_personalizada_5_temp;
  minuto_inicial_dosagem_personalizada_5 = dosaconfig.minuto_inicial_dosagem_personalizada_5_temp;
  hora_final_dosagem_personalizada_5 = dosaconfig.hora_final_dosagem_personalizada_5_temp;  
  minuto_final_dosagem_personalizada_5 = dosaconfig.minuto_final_dosagem_personalizada_5_temp; 
  terca_dosagem_personalizada_5 = dosaconfig.terca_dosagem_personalizada_5_temp; 
  quarta_dosagem_personalizada_5 = dosaconfig.quarta_dosagem_personalizada_5_temp;
  quinta_dosagem_personalizada_5 = dosaconfig.quinta_dosagem_personalizada_5_temp;
  sexta_dosagem_personalizada_5  = dosaconfig.sexta_dosagem_personalizada_5_temp;
  sabado_dosagem_personalizada_5 = dosaconfig.sabado_dosagem_personalizada_5_temp;
  domingo_dosagem_personalizada_5 = dosaconfig.domingo_dosagem_personalizada_5_temp;
  hora_inicial_dosagem_personalizada_6 = dosaconfig.hora_inicial_dosagem_personalizada_6_temp;
  minuto_inicial_dosagem_personalizada_6 = dosaconfig.minuto_inicial_dosagem_personalizada_6_temp;
  hora_final_dosagem_personalizada_6 = dosaconfig.hora_final_dosagem_personalizada_6_temp;  
  minuto_final_dosagem_personalizada_6 = dosaconfig.minuto_final_dosagem_personalizada_6_temp; 
  terca_dosagem_personalizada_6 = dosaconfig.terca_dosagem_personalizada_6_temp; 
  quarta_dosagem_personalizada_6 = dosaconfig.quarta_dosagem_personalizada_6_temp;
  quinta_dosagem_personalizada_6 = dosaconfig.quinta_dosagem_personalizada_6_temp;
  sexta_dosagem_personalizada_6  = dosaconfig.sexta_dosagem_personalizada_6_temp;
  sabado_dosagem_personalizada_6 = dosaconfig.sabado_dosagem_personalizada_6_temp;
  domingo_dosagem_personalizada_6 = dosaconfig.domingo_dosagem_personalizada_6_temp;
  quantidade_dose_dosadora_4_personalizada = dosaconfig.quantidade_dose_dosadora_4_personalizada_temp;
  quantidade_dose_dosadora_5_personalizada = dosaconfig.quantidade_dose_dosadora_5_personalizada_temp;
  quantidade_dose_dosadora_6_personalizada = dosaconfig.quantidade_dose_dosadora_6_personalizada_temp;
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
