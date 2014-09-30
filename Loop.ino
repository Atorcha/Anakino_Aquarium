//-----------------------main loop------------------------------
void loop()
{

  t = rtc.getTime(); // Atualiza as variáveis que usam o RTC.   

  LED_levels_output(); // Atualiza la potencia  de salida de los  leds

  if (myTouch.dataAvailable())  
  { 
    processMyTouch();  // Verifica si se pulsa la pantalla.
  }


  if((Ethernet_Shield == true))  // Condiciones para el envio a xively.com.
  {
    xively (); // Envia datos a xively
    netio();   // Comunica los datos con netio
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

  

  if (dispScreen != 22)
  {
    teste_em_andamento = false;

  }

  if (millis() - previousMillis > 5000)    // Verifica laas funciones cada 5 segundos.
  {
    Serial.print("Verifica funciones");
    Serial.println("");
    previousMillis = millis();
    checkTempC(); // Verifica las temperaturas.
    min_cnt = NumMins(t.hour,t.min); // Atualiza intervalo para la potencia de leds
    check_PH_aquario(); // Verifica el pH de acuario.    
    check_temporizadores(); // Verifica temporizadores
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



