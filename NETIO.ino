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
           if (strstr(comando, "tempa")) { clienteApp.println(tempC);   Serial.println("Debe imprimir temperatura AGUA");} 		
	   if (strstr(comando, "tempt")) { clienteApp.println(tempH);  Serial.println("Debe imprimir temt TAPA");  }          
           
            Serial.println( "Fin de la lectura del texto");	
  
      }
     }
    }
