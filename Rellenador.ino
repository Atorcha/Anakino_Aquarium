void check_rellenador()

{
  if (rellenador_activo == true)
  
    {
      if (digitalRead(nivel_dep) == LOW)      // Si el nivel del deposito esta bien entonces comprueba si hace falta rellenar    
      {
        if (digitalRead (nivel_acu) == LOW) // Si la lectura del sensor del nivel acuario indica que esta bajo
      {
       (digitalWrite(bomba, HIGH)); // activa la bomba
      }
   else (digitalWrite(bomba, LOW));
  }  
 }   
}
