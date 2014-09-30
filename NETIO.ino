void netio()
{
  int index = 0;
  char comando[BUFFER];
  EthernetClient clienteApp = servidorArduino.available();
  if (clienteApp) 
    {
    if (clienteApp.connected()) 
    {
          //Serial.println("Conectado netio");
          while (clienteApp.available()) {
          char caracter = clienteApp.read();
          if (caracter != '\n') {
            comando[index] = caracter;
            index++;
            if (index >= BUFFER) index = BUFFER -1;
            continue;
          }
        comando[index] = '\0';
      }                               
      
                               // Pantalla de estado
			    
           if (strstr(comando, "holaArdu")) { clienteApp.println("done"); }      //  Comienza comunicacion
           if (strstr(comando, "tempa")) { clienteApp.println(tempC);} 		//   Imprime temp del agua
	   if (strstr(comando, "tempt")) { clienteApp.println(tempH); }         //   Imprime temp de la tap
	   if (strstr(comando, "temph")) { clienteApp.println(tempHB);}         //   Imprime temp de la habitacion
          
           if (strstr(comando, "mluz")) { if (led_estado == 0)  { clienteApp.println("AUTO"); }                        //Modo Luz AUTO
                                               else { clienteApp.println("MANUAL"); }}                                 // Modo Luz MAN
                                               
           if (strstr(comando, "luzest")) { if (bitRead(status_parametros,3) == true) { clienteApp.println("ON"); } 
                                              else { clienteApp.println("OFF");  } }
                                              
           if (strstr(comando, "muv")) { if (temporizador_1_ativado == 1)  { clienteApp.println("AUTO"); }           // Modo Lampara UV Auto
                                               else { clienteApp.println("MANUAL"); }}                               // Modo Lampara UV MAN
                             
            if (strstr(comando, "uvest")) { if (bitRead(temporizador_status,1) == true) { clienteApp.println("ON"); } 
                                              else { clienteApp.println("OFF");  } } 
                                
            if (strstr(comando, "maire")) { if (temporizador_2_ativado == 1)  { clienteApp.println("AUTO"); }         // Modo Aireador Auto
                                               else { clienteApp.println("MANUAL"); }}                                // Modo aireador MAN
                             
            if (strstr(comando, "aireest")) { if (bitRead(temporizador_status,2) == true) { clienteApp.println("ON"); } 
                                              else { clienteApp.println("OFF");  } }   
             
            if (strstr(comando, "estado")) { if (bitRead(status_parametros,2) == false)  { clienteApp.println("SISTEMA FUNCIONANDO"); } //Modo Luz AUTO
                                               else { clienteApp.println("ALARMA TEMPERATURA"); }}                                   


            // Pantalla de Actuacion
            
            
           if (strstr(comando, "luzon"))  { clienteApp.println("OK");  (led_estado = 1); }
           if (strstr(comando, "luzoff")) { clienteApp.println("OK");  (led_estado = 2); }
           if (strstr(comando, "luzaut")) { clienteApp.println("OK");  (led_estado = 0); }

           if (strstr(comando, "uvon"))  { clienteApp.println("OK");  (temporizador_1_ativado = 2); }
           if (strstr(comando, "uvoff")) { clienteApp.println("OK");  (temporizador_1_ativado = 0); }
           if (strstr(comando, "uvaut")) { clienteApp.println("OK");  (temporizador_1_ativado = 1);  }  
           
           if (strstr(comando, "aireon"))  { clienteApp.println("OK");  (temporizador_2_ativado = 2); }
           if (strstr(comando, "aireoff")) { clienteApp.println("OK");  (temporizador_2_ativado = 0); }
           if (strstr(comando, "aireaut")) { clienteApp.println("OK");  (temporizador_2_ativado = 1); }  

            // Pantalla de Temperaturas
            
            if (strstr(comando, "tagua"))  { clienteApp.println("OK"); (setTempC = atoi(&comando[6]));}
           
           
            Serial.println( "Fin de la lectura del texto");	
  
      }
     }
    }
