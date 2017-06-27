void check_alarmas()        // Imprime el texto de las alarmas
  
  {

    setFont(LARGE, 255, 255, 0, 0, 0, 0);    
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(10, 140, 180, 280);
    
  if (bitRead(status_parametros,2) == false) //SI EN ALARMA 0 TENEMOS 0  => SISTEMA OK 
      { 
          myGLCD.setColor(0, 255, 0);     
          myGLCD.print("SISTEMA", 50, 155);
          myGLCD.print("FUNCIONANDO", 15, 180);
 
        if (cuenta_twitter == true) 
        { 
          
        if (bitRead(msg_enviado,0) == false)
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[186])));
          tweet( strcat(buffer,rtc.getTimeStr(FORMAT_LONG) ));
          bitWrite(msg_enviado,0,1); //Marcamos que el msg de sist ok se ha enviado
          bitWrite(msg_enviado,1,0); //y que ha sido el ultimo en enviarse
          bitWrite(msg_enviado,2,0); //asi lo dejamos preparado para enviar las alarmas
        }
      }
        
      }
      
      
    else if  (bitRead(status_parametros,2) == true) //SI EN ALARMA 2 TENEMOS 1 => ALARMA AGUA
      {
       myGLCD.setColor(255, 0, 0); 
       myGLCD.print("ALARMA", 50, 155);
       myGLCD.print("TEMPERATURA", 12, 170);
       myGLCD.print("ACUARIO", 35, 185);
       
       if (cuenta_twitter == true) 
       {   
       
       if (bitRead(msg_enviado,2) == false)
       {
       strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[188])));
       tweet( strcat(buffer,rtc.getTimeStr(FORMAT_LONG) ) );
       bitWrite(msg_enviado,2,1);//Decimos que hemos enviado el del temp agua
       bitWrite(msg_enviado,1,0);// los demas a cero, porque no se han enviado
       bitWrite(msg_enviado,0,0);
       }       
       }
      }
      
     else if (bitRead(status_parametros,0) == true) // Si hay alarma de temperatura de tapa
       {
       myGLCD.setColor(255, 0, 0); 
       myGLCD.print("ALARMA", 50, 155);
       myGLCD.print("TEMPERATURA", 12, 170);
       myGLCD.print("TAPA", 35, 185);
       }
  }

