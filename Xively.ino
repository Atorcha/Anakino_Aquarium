void xively()
{
  if (millis() - previous_Millis > 180000)    //Envia datos  cada 180 segundos
  {
    previous_Millis = millis();
    // if there's a successful connection:
      Serial.println("connecting...XIVELY");
      datastreams[0].setFloat(tempC);      //Serial.println(tempC);
      datastreams[1].setFloat(tempH);      //Serial.println(tempH);
      datastreams[2].setFloat(tempHB);     //Serial.println(tempHB);
      datastreams[3].setInt(digitalRead(calentadorPin));  //Serial.print(digitalRead(calentadorPin)); Serial.println("  Calentador");// Calentador
      datastreams[4].setInt(LedToPercent(fanSpeed));      //Serial.print(fanSpeed);Serial.println("  Ventilador");// Ventilador
      datastreams[5].setInt(digitalRead(temporizador1));  //Serial.println(digitalRead(temporizador1));// Lampara UV 1, 0 = desligado e 1 = ligado
      datastreams[6].setInt(digitalRead(temporizador2));  //Serial.println(digitalRead(temporizador2));// Aireador 2, 0 = desligado e 1 = ligado
      datastreams[7].setInt(digitalRead(temporizador3));  //Serial.println(digitalRead(temporizador3));// Tempo 3, 0 = desligado e 1 = ligado
      datastreams[8].setInt(digitalRead(temporizador4));  //Serial.println(digitalRead(temporizador4));// Tempo 4, 0 = desligado e 1 = ligado
      datastreams[9].setInt((millis()/1000)/60);         //Serial.println((millis()/1000)/60);
      datastreams[10].setInt(LedToPercent(wled_out));     //Serial.print(LedToPercent(wled_out));Serial.println("  Led Blanco");
      datastreams[11].setInt(LedToPercent(moonled_out));  //Serial.print(LedToPercent(moonled_out));Serial.println("  Luz luna");
  //  datastreams[12].setInt(digitalRead(ReleLuz));       //Serial.print(digitalRead(ReleLuz));Serial.println(" ReleLuz");
  //  datastreams[14].setInt(LedToPercent(rbled_out));    //Serial.print(LedToPercent(rbled_out));Serial.println("  Led azul royal");
  //  datastreams[15].setInt(LedToPercent(rled_out));     //Serial.print(LedToPercent(rled_out));Serial.println("  Led rojo");
  //  datastreams[16].setInt(bitRead(status_parametros,5));// Serial.print(status_parametros,5);Serial.println("  CO2");// CO2

      xivelyReturn = xivelyclient.put(feed,xivelyKey);   // Send feed to xively

   Serial.print("XIVELY client returned : "); // Get return result code, similar to HTTP code
  if (xivelyReturn == 200) 
    { 
      Serial.print(" OK "); 
    }
   else 
    {
     Serial.print(" ERROR ");   
    } 
  Serial.println(xivelyReturn);  

     }
  }

