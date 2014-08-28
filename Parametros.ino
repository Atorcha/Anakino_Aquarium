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


  // **************** Gestion del ventilador del disipador  *******
     if (tempH > 32)
           {     
            int tempval = int(tempH * 10);     
            fanSpeed = map(tempval, (HtempMin * 10), (HtempMax * 10), 0, 255);       //---------Control de velocidad de los ventiladores del disipador
            if (fanSpeed <= 0)                      //30°c = 0 volts -- 40°c = 5 volts
            {
             (fanSpeed = 0);
             (bitWrite(status_parametros,0,0)); //ventflag apagado
            }
         
       else bitWrite(status_parametros,0,1);   //ventflag activado
                            
      if (fanSpeed > 255)    fanSpeed = 255;
      analogWrite(fanPin, fanSpeed);
          }
          
     if (tempH <= 30 )
        {
        (fanSpeed = 0);
        (bitWrite(status_parametros,0,0)); //ventflag apagado
         analogWrite(fanPin, fanSpeed);
        }     
}

/*void check_nivel() //verifica o nivel do reef e fish only.
{
  if((analogRead(sensor5) > 400) ||(analogRead(sensor6) > 400) || (analogRead(sensor2) < 100) && (bitRead(tpa_status,1) == false))
  {
    nivel_status =true; //sinaliza nivel baixo em um dos aquários ou sump
  }
  else 
  {
    nivel_status =false; //sinaliza nivel normal dos aquários e sump
  }
}*/


/*void reposicao_agua_doce () // abre a solenoide 1 se o nível estiver baixo e se a tpa não estiver em andamento
//e se o chiller estiver desligado e se o nível do sump não estiver anormal e se não houve falha durante uma tpa.
{
  if((analogRead(sensor3) > 400) && (analogRead(sensor2) > 400) && (bitRead(tpa_status,1) == false) && (bitRead(status_parametros,0) == false) && (bitRead(tpa_status,2) == false))
  {
    digitalWrite(solenoide1Pin,HIGH);
    ato = true; //sinaliza reposição em andamento
  }
  else
  {
    ato = false;
    digitalWrite(solenoide1Pin,LOW);
  }
}*/
