void feedingTimeOutput()
{
  if ((comedero1==1) && (comedero1H==t.hour) && (comedero1M==t.min) && (t.sec>=0 && t.sec<5)) activacomedero(); 
  if ((comedero2==1) && (comedero2H==t.hour) && (comedero2M==t.min) && (t.sec>=0 && t.sec<5)) activacomedero();    
  if ((comedero3==1) && (comedero3H==t.hour) && (comedero3M==t.min) && (t.sec>=0 && t.sec<5)) activacomedero();
  if ((comedero4==1) && (comedero4H==t.hour) && (comedero4M==t.min) && (t.sec>=0 && t.sec<5)) activacomedero();        
}
void activacomedero()
{
   Serial.println("comdero activado");
  myStepper.step(stepsPerRevolution);
  delay(6000);       // Se espera 6 segundos
  t = rtc.getTime(); // Recupera la hora
}      
