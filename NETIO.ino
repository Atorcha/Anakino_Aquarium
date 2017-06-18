/*
void netio()
{
  int index = 0;
  char comando[BUFFER];
  EthernetClient client = server.available();
  if (client) 
    {
    if (client.connected()) 
    {
          //Serial.println("Conectado netio");
          while (client.available()) {
          char caracter = client.read();
          if (caracter != '\n') {
            comando[index] = caracter;
            index++;
            if (index >= BUFFER) index = BUFFER -1;
            continue;
          }
        comando[index] = '\0';
      }                               
      
                               // Pantalla de estado
			    
           if (strstr(comando, "holaArdu")) { client.println("done"); }      //  Comienza comunicacion
           if (strstr(comando, "tempa")) { client.println(tempC);} 		//   Imprime temp del agua
	   if (strstr(comando, "tempt")) { client.println(tempH); }         //   Imprime temp de la tap
	   if (strstr(comando, "temph")) { client.println(tempHB);}         //   Imprime temp de la habitacion
          
           if (strstr(comando, "mluz")) { if (led_estado == 0)  { client.println("AUTO"); }                        //Modo Luz AUTO
                                               else { client.println("MANUAL"); }}                                 // Modo Luz MAN
                                               
           if (strstr(comando, "luzest")) { if (bitRead(status_parametros,3) == true) { client.println("ON"); } 
                                              else { client.println("OFF");  } }
                                              
           if (strstr(comando, "muv")) { if (temporizador_1_ativado == 1)  { client.println("AUTO"); }           // Modo Lampara UV Auto
                                               else { client.println("MANUAL"); }}                               
                             
            if (strstr(comando, "uvest")) { if (bitRead(temporizador_status,1) == true) { client.println("ON"); } // Modo Lampara UV ON/OFF
                                              else { client.println("OFF");  } } 
                                
            if (strstr(comando, "maire")) { if (temporizador_2_ativado == 1)  { client.println("AUTO"); }         // Modo Aireador Auto
                                               else { client.println("MANUAL"); }}                                
                             
            if (strstr(comando, "aireest")) { if (bitRead(temporizador_status,2) == true) { client.println("ON"); } // Modo aireador ON/OFF
                                              else { client.println("OFF");  }} 
                                              
            if (strstr(comando, "co")) { if (temporizador_3_ativado == 1)  { client.println("AUTO"); }         // Modo co2 Auto
                                               else { client.println("MANUAL"); }}
                                               
            if (strstr(comando, "coest")) { if (bitRead(temporizador_status,3) == true) { client.println("ON"); }   //Modo co2 ON/OFF
                                               else { client.println("OFF");  }} 
             
            if (strstr(comando, "estado")) { if (bitRead(status_parametros,2) == false)  { client.println("SISTEMA FUNCIONANDO"); } //Modo Luz AUTO
                                               else { client.println("ALARMA TEMPERATURA"); }}                                   


            // Pantalla de Actuacion
            
            
           if (strstr(comando, "luzon"))  { client.println("OK");  (led_estado = 1); }
           if (strstr(comando, "luzoff")) { client.println("OK");  (led_estado = 2); }
           if (strstr(comando, "luzaut")) { client.println("OK");  (led_estado = 0); }

           if (strstr(comando, "uvon"))  { client.println("OK");  (temporizador_1_ativado = 2); }
           if (strstr(comando, "uvoff")) { client.println("OK");  (temporizador_1_ativado = 0); }
           if (strstr(comando, "uvaut")) { client.println("OK");  (temporizador_1_ativado = 1);  }  
           
           if (strstr(comando, "aireon"))  { client.println("OK");  (temporizador_2_ativado = 2); }
           if (strstr(comando, "aireoff")) { client.println("OK");  (temporizador_2_ativado = 0); }
           if (strstr(comando, "aireaut")) { client.println("OK");  (temporizador_2_ativado = 1); }  

            // Pantalla de Temperaturas
            
            if (strstr(comando, "tagua"))  { client.println("OK"); (setTempC = atoi(&comando[6]));}
           
           
            Serial.println( "Fin de la lectura del texto");	
  
      }
     }
    }
    */
