
////////////////////////////////////////////////////////////////////////
//checkForClient Function
////////////////////////////////////////////////////////////////////////
//
void checkForClient()
{
   EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    String cadena="";    //Definimos una variable de tipo string vacía para almacenar el mensaje    
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        cadena.concat(c);                              //Unimos todos los caracteres de la petición HTTP "c", en la variable de tipo String "Cadena"
        
         //Ya que hemos convertido la petición HTTP a una cadena de caracteres, ahora podremos buscar partes del texto.
         int posicion=cadena.indexOf("AIRE=");           //Nos fijamos en el texto "AIRE="
           if(cadena.substring(posicion)=="AIRE=ON")     //Si en esa posición tenemos "AIRE=ON"
          {
            SetRele(temporizador1, HIGH);                //Encendemos el AIREADOR
            aire_web_estado="ON";                               //Asignamos el valor "ON" a la variable "estado"
          }
          if(cadena.substring(posicion)=="AIRE=OFF")    //Si en esa posición tenemos "AIRE=OFF"
          {
            SetRele(temporizador1, LOW);                     //Apagamos el AIREADOR
            aire_web_estado="OFF";                              //Asignamos el valor "OFF" a la variable "estado"
          }        
        if (c == '\n' && currentLineIsBlank) {

 
            // Enviamos al cliente una respuesta HTTP (cabecera)
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println("Connection: close");
            
            // Enviamos al cliente una respuesta en formato HTML
            client.println("<html>");
            client.println("");
            client.println("<head>");
            client.println("<meta charset='UTF-8'>");
            client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
            client.println("<title>Anakino_Aquarium v 1.0</title>");
            client.println("</head>");
            client.println("");
            client.println("<body>");
   //       client.println("<center><img src='http://www.minitronica.com/wp-content/uploads/bilogo.png'></center>");
            client.println("<br><br>");
            
            //Creamos los botones. Para enviar parametros a través de HTML se utilizara el metodo URL encode. Los parametros se envian a traves del simbolo '?'
            client.println("<div style='text-align:center;'>");
            client.println("<button onClick=location.href='./?AIRE=ON' style='width:200px; height:75px; background-color:#aaf442; color:snow; padding:10px; border:1px solid #3F7CFF;'>ON</button>");
            client.println("<button onClick=location.href='./?AIRE=OFF' style='width:200px; height:75px; background-color:#d82408; color:snow; padding:10px; border:1px solid #3F7CFF;'>OFF</button>");
            client.println("<br><br>");
            client.println("<b>Estado del AIREADOR = ");
            client.print(aire_web_estado);
            
          client.println("<H2>");
          client.print("Temperatura agua: ");
          client.println("</H2>");
          client.println("<p />");
          client.println("<H1>");          
          client.println(tempC);
          client.print(" C\t");
          client.println("</H1>");
          client.println("<p />"); 
          client.println("<H2>");
          client.print("Temperatura Hab: ");
          client.println("</H2>");
          client.println("<H1>");
          client.print(tempHB);
          client.println(" &#176;");
          client.println("C");
          client.println("</H1>"); 
          
            client.println("</b><br />");
            client.println("</b></body>");
            client.println("</html>");
    break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  } 

 
}

