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

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[183])));
    myGLCD.print(buffer, 212, 42); // tabela_textos[183] = "temp disipador:"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[189])));
    myGLCD.print(buffer, 212, 56); // tabela_textos[189] = "ventilador:"    

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[214])));
    myGLCD.print(buffer, 212, 70); // tabela_textos[214] = "temperatura habitacion" 
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[185])));
    myGLCD.print(buffer, 212, 84); // tabela_textos[185] = "PH DO AQUARIO:"   

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[31])));
    myGLCD.print(buffer, 212, 98); // tabela_textos[31] = "TIMER 1:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[77])));
    myGLCD.print(buffer, 212, 112); // tabela_textos[77] = "TIMER 2:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[78])));
    myGLCD.print(buffer, 212, 126); // tabela_textos[78] = "TIMER 3:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[79])));
    myGLCD.print(buffer, 212, 140); // tabela_textos[79] = "TIMER 4:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[80])));
    myGLCD.print(buffer, 212, 154); // tabela_textos[80] = "TIMER 5:"

    myGLCD.setColor(0, 255, 0);

    myGLCD.print("C", 370, 14);                     // GRADOS agua
    myGLCD.print("C", 370, 42);                     // GRADOS disipador        
    myGLCD.print("C", 370, 70);                     // GRADOS habitacion


    myGLCD.setColor(161, 127, 73);                  
    myGLCD.drawRect(7, 5, 199, 145);                // Dibujar rectangulo barras
    myGLCD.drawRect(7, 150, 199, 208);              // Dibujar rectangulo alarmas
    myGLCD.drawRect(206, 5, 392, 208);              // Dibujar rectangulo datos

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
  myGLCD.fillRect(315, 10, 360, 205);                // Apagar todo el cuadro de temperaturas y Temporizadores

  myGLCD.setColor(0, 255, 0);  
  myGLCD.printNumF(tempC, 2, 316, 14);            // Temperatura agua
  myGLCD.printNumF(tempH, 2, 316, 42);            // Temperatura disipador
  myGLCD.printNumF(tempHB, 2, 316, 70);           // Temperatura habitacion 

 
  myGLCD.setColor(255, 0, 0);

  if (bitRead(status_parametros,2)==true)             //Estado del agua
  {                               
    myGLCD.printNumF( tempC, 2, 316, 14);             // Temperatura en rojo
  }     
  
  if (bitRead(status_parametros,0) == true)           //Estado ventilador disipador
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.printNumI(LedToPercent(fanSpeed), 316, 56); // ventilador conectado
    myGLCD.print("%", 340, 56);
  }
  else 
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 316, 56);          // ventilador desconectado
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
  
  if (bitRead(temporizador_status,1) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 316, 98);           // Lampara UV conectada
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 316, 98);          // Lampara UV desconectada
  }

  if (bitRead(temporizador_status,2) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 316, 112);           // Airedor activado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 316, 112);          // Aireador desactivado
  }
  if (bitRead(temporizador_status,3) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 316, 126);           // Timer 3 ligado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 316, 126);          // Timer 3 desligado
  }
  if (bitRead(temporizador_status,4) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 316, 140);           // Timer 4 ligado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 316, 140);          // Timer 4 desligado
  }
  if (bitRead(temporizador_status,5) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 316, 154);           // Timer 5 ligado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 316, 154);          // Timer 5 desligado
  }

  
}




