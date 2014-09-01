void tweet(char *msg)
    {
    previous_Millis = millis();
    // if there's a successful connection:
      Serial.println("connecting tweeter...");
      if (twitter.post(msg)) {
                              int status = twitter.wait(&Serial);
                               if (status == 200) { Serial.println("OK.");}
                               else 
                               { Serial.print("failed : code "); Serial.println(status); }
                             } 
                             else
                             
          { Serial.println("connection tweeter failed.");
        }        
  }
