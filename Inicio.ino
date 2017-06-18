//---------------------------------------Pantalla inicial ----------------------------------------------pantalla =0
void mainScreen(boolean refreshAll=false)
{
  int ledLevel, s, u;
  String oldval, rtc1, rtcm;
  oldval = day;
  day = String(t.date);                             //Atualiza se a data for diferente
  int offset = 0;

  setFont(SMALL, 255, 255, 0, 0, 0, 0);
  myGLCD.print(rtc.getTimeStr(FORMAT_LONG), 315, 227);  

  if ((oldval != day) || refreshAll)
  {
    setFont(SMALL, 255, 255, 0, 0, 0, 0);
    myGLCD.print(rtc.getDOWStr(FORMAT_LONG), 10, 227);
    myGLCD.printNumI(t.date, 90, 227);
    myGLCD.print("DE", 115, 227);
    myGLCD.print(rtc.getMonthStr(FORMAT_LONG), 135, 227);
    myGLCD.print("DE", 225, 227);
    myGLCD.printNumI(t.year, 245, 227);

    char bufferLP[16];
    LP.toCharArray(bufferLP, 16);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(98, 213, 235, 226); //tapa la descripcion de la fase lunar

    myGLCD.setColor(255, 255, 255);
    myGLCD.print(bufferLP, 98, 213); //Escribe la fase lunar

    float lunarCycle = moonPhase(t.year,t.mon, t.date); //get a value for the lunar cycle

      if ((lunarCycle*100) < 0) //Print % of Full to LCD
    { 
      myGLCD.print(" 0.00", 240, 213); 
    }
    else 
    { 
      myGLCD.printNumF(lunarCycle*100, 1, 240, 213);
    }

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[181])));
    myGLCD.print(buffer, 280, 213); // tabela_textos[181] = "% ILUMINADA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[182])));
    myGLCD.print(buffer, 10, 213); // tabela_textos[182] = "FASE LUNAR:"
  }

  if ( refreshAll == true)                                  //Diseña elementos fijos
  {
    myGLCD.setColor(255, 255, 255);
        myGLCD.print("100", 24, 17);  

    for (int i = 0; i < 90; i += 10)
    {
      myGLCD.printNumI(90-i, 32, 28 + offset);   // de 90 a 10
      offset += 11;
    }

    myGLCD.print("0", 40, 127);

    myGLCD.setColor(255, 255, 255);

    myGLCD.drawRect(50, 138, 187, 138);       // Eixo X
    myGLCD.drawRect(50, 28, 50, 138);         // Eixo Y

    for (int i=0; i<10; i++)
    {
      myGLCD.drawLine(51,(i*11)+28,55,(i*11)+28);
    } // Marcador grande 
    myGLCD.setColor(190, 190, 190);  

    for (int i=0; i<10; i++)
    {
      myGLCD.drawLine(51,(i*11)+34,53,(i*11)+34);
    } // Marcador pequeno

    for (int i=0; i<10; i++)
    {
      myGLCD.drawLine(79,(i*11)+28,187,(i*11)+28);
    }// Grade
    
    myGLCD.setColor(255, 255, 255);
 
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[30])));
    myGLCD.print(buffer, 50, 10); // tabela_textos[30] = "POTENCIA DE LEDS"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[184])));
    myGLCD.print(buffer, 212, 14);  // tabela_textos[184] = "Temp agua" 
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[190])));
    myGLCD.print(buffer, 212, 28); // tabela_textos[190] = "calentador:" 
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[189])));
    myGLCD.print(buffer, 212, 42); // tabela_textos[189] = "ventilador:" 
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[183])));
    myGLCD.print(buffer, 212, 56); // tabela_textos[183] = "temp disipador:"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[214])));
    myGLCD.print(buffer, 212, 70); // tabela_textos[214] = "temperatura habitacion" 
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[94])));
    myGLCD.print(buffer, 212, 84); // tabela_textos[214] = "PH acuario"     
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[185])));
    myGLCD.print(buffer, 212, 112); // tabela_textos[185] = "ILUMINACION:"   

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[31])));
    myGLCD.print(buffer, 212, 126); // tabela_textos[31] = "AIREADOR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[77])));
    myGLCD.print(buffer, 212, 140); // tabela_textos[77] = "LAMPARA UV"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[78])));
    myGLCD.print(buffer, 212, 154); // tabela_textos[78] = "CO2:"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[79])));
    myGLCD.print(buffer, 212, 168); // tabela_textos[79] = "TIMER 4:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[80])));
    myGLCD.print(buffer, 212, 182); // tabela_textos[80] = "TIMER 5:"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[96])));
    myGLCD.print(buffer, 212, 196); // tabela_textos[96] = "Rellenador:"
    
  
    myGLCD.setColor(0, 255, 0);

    myGLCD.print("C", 370, 14);                     // GRADOS agua
    myGLCD.print("C", 370, 56);                     // GRADOS disipador        
    myGLCD.print("C", 370, 70);                     // GRADOS habitacion


    myGLCD.setColor(161, 127, 73);                  
    myGLCD.drawRect(7, 5, 199, 145);                // Dibujar rectangulo barras
    myGLCD.drawRect(7, 150, 199, 208);              // Dibujar rectangulo alarmas
    myGLCD.drawRect(206, 5, 392, 103);              // Dibujar rectangulo temperaturas
    myGLCD.drawRect(206,106, 392, 208);              // Dibujar rectangulo temprizadores
   

  } //////////////////////////                                           //////////////      Fin de refreshAll
  
  

  if ((whiteLed != wled_out) || refreshAll)        // Actualiza gráfico led blanco    
  {
    whiteLed = wled_out;
    ledLevel = LedToPercent(wled_out);
    myGLCD.setColor(255, 255, 255);
    offset = map(ledLevel, 100, 0, 28, 137);
    myGLCD.fillRect(60, offset, 100, 137);
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(60, offset -1, 100, 28);            // Apaga barra anterior
    
    /////////////////////////////////////           // Atualiza gráfica luz de luna
    
  
    ledLevel = (255-moonled_out);
    myGLCD.setColor(58, 95, 205);
    offset = map(ledLevel, 0, 255, 28, 137);
    myGLCD.fillRect(130, offset, 170, 137);
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(130, offset -1, 170, 28);          // Apaga barra anterior
  } 


  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(10, 155, 195, 205);                // Apagar todo el cuadro de Alarmas
  myGLCD.fillRect(315, 10, 360, 101);                // Apagar todo el cuadro de temperaturas
  myGLCD.fillRect(315, 113, 380, 205);                // Apagar todo el cuadro de Temporizadores 
 
 
 // ************** Empieza a imprimir valores
 
  myGLCD.setColor(0, 255, 0);  
  myGLCD.printNumF(tempC, 2, 316, 14);            // Temperatura agua
  myGLCD.printNumF(tempH, 2, 316, 56);            // Temperatura disipador
  myGLCD.printNumF(tempHB, 2, 316, 70);           // Temperatura habitacion 
  myGLCD.printNumF(PHA, 2, 316, 84);              // PH Acuario

 
  myGLCD.setColor(255, 0, 0);   // En color rojo lo siguiente

  if (bitRead(status_parametros,2)==true)             //Estado del agua
  {                               
    myGLCD.printNumF( tempC, 2, 316, 14);             // Temperatura en rojo
  }     
  
  if (bitRead(status_parametros,4) == true)  // Estado del pH
  {                               
    myGLCD.printNumF(PHA, 2, 316, 84);       // PH de aquario en rojo
  }
  
  if (bitRead(status_parametros,0) == true)           //Estado ventilador disipador
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ACTIVADO", 316, 42); // ventilador conectado
    //myGLCD.print("%", 340, 42);
  }
  else 
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF     ", 316, 42);          // ventilador desconectado
  }
  if (bitRead(status_parametros,1) == true) //Estado del calentador
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 316, 28);           // Calentador conectado
  } 
  else  
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 316, 28);          // calentador desconectado
  }
    
  
  

// *********************** Iluminacion
  
  if (led_estado == 0)                  //Iluminacion en modo AUTO
  {
    myGLCD.setColor(0, 255, 0);         // En verde
    myGLCD.print("AUTO",316,112);           
  }
  else                                 // ILuminacion Modo MANUAL ON
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("MAN. ON",316,112);    
  }
   
  if (bitRead(status_parametros,3) == true) 
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("ON", 355, 112);           // Iluminacion conectada
  }
  else
  {             
    myGLCD.setColor(255, 0, 0);            // en rojo
    myGLCD.print("OFF", 355, 112);          // Iluminacion desconectada
  }
   
// *********************** TEMPORIZADOR 1 /aireador
  
  if (temporizador_1_ativado == 1) 
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("AUTO", 316, 126);           // modo AUTO
  }
  else
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("MAN", 316, 126);          // MAN 
  }
  
  if (bitRead(temporizador_status,1) == true) 
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("ON", 355, 126);           // conectada
  }
  else
  {             
    myGLCD.setColor(255, 0, 0);
    myGLCD.print("OFF", 355, 126);          // desconectada
  }
  
  
// *********************** TEMPORIZADOR 2 /Lampara uv

 if (temporizador_2_ativado == 1)        //  modo AUTO
 {
   myGLCD.setColor(0, 255, 0);
   myGLCD.print("AUTO", 316,140);
 }
 else
 {
   myGLCD.setColor(0, 130, 255);        //  modo MAN
   myGLCD.print("MAN", 316, 140); 
 }


  if (bitRead(temporizador_status,2) == true) 
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("ON", 355, 140);           // activado
  }
  else
  {             
    myGLCD.setColor(255, 0, 0);
    myGLCD.print("OFF", 355, 140);          //  desactivado
  }
  
// *********************** TEMPORIZADOR 3 / CO2
 if (temporizador_3_ativado == 1)        // Temporizador 3 en modo AUTO
 {
   myGLCD.setColor(0, 255, 0); 
   myGLCD.print("AUTO",316, 154); 
 }
 else
  {
   myGLCD.setColor(0, 130, 255);        // Temporizador en modo MAN
   myGLCD.print("MAN", 316, 154); 
 }
 
  
  if (bitRead(temporizador_status,3) == true) 
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("ON", 355, 154);           // Timer 3 activado
  }
  else
  {             
    myGLCD.setColor(255, 0, 0);
    myGLCD.print("OFF", 355, 154);          // Timer 3 desactivado
  }
  
// *********************** Temporizador 4

 if (temporizador_4_ativado == 1)        // Temporizador 4 en modo AUTO
 {
   myGLCD.setColor(0, 255, 0); 
   myGLCD.print("AUTO",316, 168); 
 }
 else
  {
   myGLCD.setColor(0, 130, 255);        // Temporizador en modo MAN
   myGLCD.print("MAN", 316, 168); 
 }

  if (bitRead(temporizador_status,4) == true) 
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("ON", 355, 168);           // Timer 4 activado
  }
  else
  {             
    myGLCD.setColor(255, 0, 0);
    myGLCD.print("OFF", 355, 168);          // Timer 4 desactivado
  }
  
// *********************** Temporizador 5

 if (temporizador_5_ativado == 1)        // Temporizador 5 en modo AUTO
 {
   myGLCD.setColor(0, 255, 0); 
   myGLCD.print("AUTO",316, 182); 
 }
 else
  {
   myGLCD.setColor(0, 130, 255);        // Temporizador en modo MAN
   myGLCD.print("MAN", 316, 182); 
 }
  
  if (bitRead(temporizador_status,5) == true) 
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("ON", 355, 182);           // Timer 5 activado
  }
  else
  {             
    myGLCD.setColor(255, 0, 0);
    myGLCD.print("OFF", 355, 182);          // Timer 5 desactivado
  }
// *********************** Rellenador

 if (rellenador_activo == true)        // si rellenador esta  activado

  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("ACTIVADO", 316, 196);           // activado
  }
  else
  {
    myGLCD.setColor(255, 0, 0);
    myGLCD.print("APAGADO ", 316, 196);          // Desactivado
  } 
  
}




