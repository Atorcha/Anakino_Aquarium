//-----------------------main loop------------------------------
void loop()
{

  t = rtc.getTime(); // Actualiza las variables que usa el  RTC.   

  LED_levels_output(); // Actualiza la potencia  de salida de los  leds

  if (myTouch.dataAvailable())  
  { 
    processMyTouch();  // Verifica si se pulsa la pantalla.
    Serial.print("pulsa pantalla");
  }


  if((Ethernet_Shield == true))  // Condiciones para el envio a xively.com.
  {
    xively (); // Envia datos a xively
   // netio();   // Comunica los datos con netio
    checkForClient(); // Comprueba si alguien ha acceddio a la webserver
  } 
 
   if(dosadoras == true) // Verifica y ejecuta las dosificadoras.
  {
    check_dosagem_personalizada_1(); // Dosadora 1 - Dosagem personalizado
    check_dosagem_personalizada_2(); // Dosadora 2 - Dosagem personalizado
    check_dosagem_personalizada_3(); // Dosadora 3 - Dosagem personalizado
    check_dosagem_personalizada_4(); // Dosadora 4 - Dosagem personalizado
    check_dosagem_personalizada_5(); // Dosadora 5 - Dosagem personalizado
    check_dosagem_personalizada_6(); // Dosadora 6 - Dosagem personalizado
  }  

  if (millis() - previousMillis > 5000)    // Verifica las funciones cada 5 segundos.
  {
    Serial.print("Verifica funciones");
    Serial.println("");
    previousMillis = millis();
    checkTempC(); // Verifica las temperaturas.
    min_cnt = NumMins(t.hour,t.min); // Atualiza intervalo para la potencia de leds
    check_PH_aquario(); // Verifica el pH de acuario.    
    check_temporizadores(); // Verifica temporizadores
    check_rellenador(); // comprueba el rellenador
    feedingTimeOutput();   // Comprueba si hay que dar de comer a los peces



    if (dispScreen == 0)
    {
      mainScreen();    // Atualiza pantalla inicial.
      check_alarmas(); // Verifica las alarmas.        
    }
    if(suavizar <= 1)
    {
      suavizar += 0.1;
    }

    Serial.print ("Memoria libre:");
    Serial.println (FreeRam());
    Serial.println("");      //imprime otro salto de linea
    
  }

} //-------------------end of main loop



