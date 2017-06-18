//---------------------------------------------------------------------------------------------
void checkTempC()
{ 
  contador_temp ++;

  sensors.requestTemperatures();   // call sensors.requestTemperatures() to issue a global 
  // temperature request to all devices on the bus
  temperatura_agua_temp += (sensors.getTempC(sensor_agua));  //read water temperature
  temperatura_dissipador_temp += (sensors.getTempC(sensor_dissipador));   //read heatsink temperature
  temperatura_habitacion_temp += (sensors. getTempC(sensor_habitacion));       // lee temperatura habitacion.

  if(contador_temp == 10)
  {
    tempC = temperatura_agua_temp / 10;
    tempH = temperatura_dissipador_temp / 10; 
    tempHB = temperatura_habitacion_temp / 10;
    contador_temp = 0;  
    temperatura_agua_temp = 0;
    temperatura_dissipador_temp = 0;
    temperatura_habitacion_temp = 0; 
  }

  if (tempC < (setTempC + offTempC + alarmTempC) && tempC > (setTempC - offTempC - alarmTempC)) // SI EL AGUA ESTA DENTRO DE PARAMETROS
  {

    bitWrite(status_parametros,2,0);   // tempAflag = false;    //Agua dentro de valores maximos y minimos
  }

  
   else if ((tempC >= (setTempC + offTempC + alarmTempC)) || (tempC <= (setTempC - offTempC - alarmTempC))) // si la temperatura del agua esta fuera de los parametros
     {

      bitWrite(status_parametros,2,1); // tempAflag=true;//Agua fuera de valores maximo o minimo
    }


  
  
//*********************** Gestion activacion calentador *************
  if (tempC > (setTempC + offTempC))           //apaga calentador
  {
    bitWrite(status_parametros,1,0); // Calentador apagado
    SetRele (calentadorPin, LOW);    // ya cambiada por la funcion
  }

    if (tempC < (setTempC - offTempC))             //activa calentador
    {
      bitWrite(status_parametros,1,1); //Calentador encendido
      SetRele(calentadorPin, HIGH);     // ya cambiado
    }
    
    if ((tempC > 50) || (tempC <10)) // Si por lo que sea la temperatura marca -127
  {
    bitWrite(status_parametros,1,0);
    SetRele(calentadorPin, LOW);
  }


  // **************** Gestion del ventilador para refrigeracion del agua  *******
  /*
  if (tempC > setTempC +2)
     {
      analogWrite(fanPin, ); 
      bitWrite(status_parametros,0,1);   //ventilador activado
     }
     else
     {
       analogWrite(fanPin, 0);
      (bitWrite(status_parametros,0,0)); //ventilador apagado
        } 
  */     
  
      const int HtempMin = setTempC +2;    // Declara la temperatura para iniciar el funcionamiento de la velocidad del ventilador para refrigerar el agua sera 5º mas que la deseada 
      const int HtempMax = setTempC +4;    // Declara que el ventilador debe estar a su maxima velocidad cuando el agua se encuentre 8 grados por encima de la temperatura deseada
              
      int tempval = int(tempC * 10);     
      fanSpeed = map(tempval, (HtempMin * 10), (HtempMax * 10), 240, 255);       //---------Control de velocidad de los ventiladores del disipador

      
      if (fanSpeed < 240)                      
      {
        fanSpeed = 0;
       }
       
      if (fanSpeed > 255)    
      
      {
        fanSpeed = 255;
      }
      
      analogWrite(fanPin, fanSpeed);
      
      Serial.println("");
      Serial.print ("Temp Agua: ");
      Serial.print (tempC);
      Serial.println("");       
      Serial.print ("fanSpeed: ");
      Serial.print (fanSpeed);
      Serial.println("");       
      Serial.print ("temp deseada: ");
      Serial.print (setTempC);      
      Serial.println(""); 
 
      if (tempC < HtempMin )
        {
        (bitWrite(status_parametros,0,0)); //ventilador apagado
        }
   else
      {
      bitWrite(status_parametros,0,1);   //ventilador activado
      }  
      
}

void check_PH_aquario()
{ 
  if (PHA < (setPHA + offPHA + alarmPHA) && PHA > (setPHA - offPHA - alarmPHA)) 
  {
    bitWrite(status_parametros,4,0);
  }
  if (alarmPHA > 0)           // Liga o alarme
  {
    if ((PHA >= (setPHA + alarmPHA)) || (PHA <= (setPHA - offPHA - alarmPHA)))
    {
    bitWrite(status_parametros,4,1);
    }
  }
  if (PHA < (setPHA - offPHA)) // Si el PH es menor del deseado o de la variacion permitida. 
  {
    bitWrite(status_parametros,5,0);
    digitalWrite(temporizador1, LOW);  // Desactiva co2 
  }  
}
