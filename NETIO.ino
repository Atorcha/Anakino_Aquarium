void netio()
{
  int index = 0;
  char comando[BUFFER];
  EthernetClient clienteApp = servidorArduino.available();
  if (clienteApp) 
    {
    if (clienteApp.connected()) 
    {
          Serial.println("Conectado netio");
          while (clienteApp.available()) {
          char caracter = clienteApp.read();
          if (caracter != '\n') {
            comando[index] = caracter;
            Serial.println(comando);
            index++;
            if (index >= BUFFER) index = BUFFER -1;
            continue;
          }
        comando[index] = '\0';
      }			    
           if (strstr(comando, "holaArdu")) { clienteApp.println("done"); Serial.println("Esta conectado"); }
           if (strstr(comando, "tempa")) { clienteApp.println(tempC);} 		
	   if (strstr(comando, "tempt")) { clienteApp.println(tempH); }
	   if (strstr(comando, "temph")) { clienteApp.println(tempHB);}          
           if (strstr(comando, "onsend")) { clienteApp.println("OK");  (led_estado = 1); Serial.println("Debe on luz");  }
           if (strstr(comando, "offsend")) { clienteApp.println("OK");  (led_estado = 2); Serial.println("Debe off luz");}
           if (strstr(comando, "autom")) { clienteApp.println("OK");  (led_estado = 0); Serial.println("Debe off auto");  }

           if (strstr(comando, "ledest")) 
             { 
               if (bitRead(temporizador_status,0) == true) 
                   { 
                   clienteApp.println("ON"); 
                    } 
             else 
                 {
                 clienteApp.println("OFF"); 
               }
           }
          if (strstr(comando, "modoluz")) 
             { 
               if (led_estado == 0) 
                   { 
                   clienteApp.println("AUTO"); 
                    } 
             else 
                 {
                 clienteApp.println("MANUAL"); 
               }
           }           

           
            Serial.println( "Fin de la lectura del texto");	
  
      }
     }
    }
