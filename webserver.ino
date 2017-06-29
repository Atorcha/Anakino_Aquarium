
////////////////////////////////////////////////////////////////////////
//checkForClient Function
////////////////////////////////////////////////////////////////////////
//
void checkForClient()
{
 //  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          
          // add page title 
          client.println("<title>Anakino Aquarium</title>");
          client.println("<meta name=\"description\" content=\"Anakino Aquarium\"/>");

          // add a meta refresh tag, so the browser pulls again every x seconds:
          client.print("<meta http-equiv=\"refresh\" content=\"");
          client.print(refreshPage);
          client.println("; url=/\">");

          // add other browser configuration
          client.println("<meta name=\"apple-mobile-web-app-capable\" content=\"yes\">");
          client.println("<meta name=\"apple-mobile-web-app-status-bar-style\" content=\"default\">");
          client.println("<meta name=\"viewport\" content=\"width=device-width, user-scalable=no\">");          

          //inserting the styles data, usually found in CSS files.
          client.println("<style type=\"text/css\">");
          client.println("");

          //This will set how the page will look graphically
          client.println("html { height:100%; }");  

          client.println("  body {");
          client.println("    height: 100%;");
          client.println("    margin: 0;");
          client.println("    font-family: helvetica, sans-serif;");
          client.println("    -webkit-text-size-adjust: none;");
          client.println("   }");
          client.println("");
          client.println("body {");
          client.println("    -webkit-background-size: 100% 21px;");
          client.println("    background-color: #c5ccd3;");
          client.println("    background-image:");
          client.println("    -webkit-gradient(linear, left top, right top,");
          client.println("    color-stop(.75, transparent),");
          client.println("    color-stop(.75, rgba(255,255,255,.1)) );");
          client.println("    -webkit-background-size: 7px;");
          client.println("   }");
          client.println("");
          client.println(".view {");
          client.println("    min-height: 100%;");
          client.println("    overflow: auto;");
          client.println("   }");
          client.println("");
          client.println(".header-wrapper {");
          client.println("    height: 44px;");
          client.println("    font-weight: bold;");
          client.println("    text-shadow: rgba(0,0,0,0.7) 0 -1px 0;");
          client.println("    border-top: solid 1px rgba(255,255,255,0.6);");
          client.println("    border-bottom: solid 1px rgba(0,0,0,0.6);");
          client.println("    color: #fff;");
          client.println("    background-color: #8195af;");
          client.println("    background-image:");
          client.println("    -webkit-gradient(linear, left top, left bottom,");
          client.println("    from(rgba(255,255,255,.4)),");
          client.println("    to(rgba(255,255,255,.05)) ),");
          client.println("    -webkit-gradient(linear, left top, left bottom,");
          client.println("    from(transparent),");
          client.println("    to(rgba(0,0,64,.1)) );");
          client.println("    background-repeat: no-repeat;");
          client.println("    background-position: top left, bottom left;");
          client.println("    -webkit-background-size: 100% 21px, 100% 22px;");
          client.println("    -webkit-box-sizing: border-box;");
          client.println("   }");
          client.println("");
          client.println(".header-wrapper h1 {");
          client.println("    text-align: center;");
          client.println("    font-size: 20px;");
          client.println("    line-height: 44px;");
          client.println("    margin: 0;");
          client.println("   }");
          client.println("");
          client.println(".group-wrapper {");
          client.println("    margin: 9px;");
          client.println("    }");
          client.println("");
          client.println(".group-wrapper h2 {");
          client.println("    color: #4c566c;");
          client.println("    font-size: 17px;");
          client.println("    line-height: 0.8;");
          client.println("    font-weight: bold;");
          client.println("    text-shadow: #fff 0 1px 0;");
          client.println("    margin: 20px 10px 12px;");
          client.println("   }");
          client.println("");
          client.println(".group-wrapper h3 {");
          client.println("    color: #4c566c;");
          client.println("    font-size: 12px;");
          client.println("    line-height: 1;");
          client.println("    font-weight: bold;");
          client.println("    text-shadow: #fff 0 1px 0;");
          client.println("    margin: 20px 10px 12px;");
          client.println("   }");
          client.println("");
          client.println(".group-wrapper h4 {");  //Text for description
          client.println("    color: #212121;");
          client.println("    font-size: 14px;");
          client.println("    line-height: 1;");
          client.println("    font-weight: bold;");
          client.println("    text-shadow: #aaa 1px 1px 3px;");
          client.println("    margin: 5px 5px 5px;");
          client.println("   }");
          client.println(""); 
          client.println(".group-wrapper table {");
          client.println("    background-color: #fff;");
          client.println("    -webkit-border-radius: 10px;");

          client.println("    -moz-border-radius: 10px;");
          client.println("    -khtml-border-radius: 10px;");
          client.println("    border-radius: 10px;");


          client.println("    font-size: 17px;");
          client.println("    line-height: 20px;");
          client.println("    margin: 9px 0 20px;");
          client.println("    border: solid 1px #a9abae;");
          client.println("    padding: 11px 3px 12px 3px;");
          client.println("    margin-left:auto;");
          client.println("    margin-right:auto;");

          client.println("    -moz-transform :scale(1);"); //Code for Mozilla Firefox
          client.println("    -moz-transform-origin: 0 0;");



          client.println("   }");
          client.println("");


          //and finally this is the end of the style data and header
          client.println("</style>");
          client.println("</head>");

          //now printing the page itself
          client.println("<body>");
          client.println("<div class=\"view\">");
          client.println("    <div class=\"header-wrapper\">");
          client.println("      <h1>Anakino_aquarium_v 1.0</h1>");
          client.println("    </div>");
       
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
                                   
    //printing last part of the html
         client.println("\n<h3 align=\"center\">&copy; Author - Claudio Vella <br> Malta - October - 2012 - ");
         client.println(rev);
         client.println("</h3></div>\n</div>\n</body>\n</html>");

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

