// HAY QUE ADAPTAR LOS RELES A LA NUEVA FUNCION!!!!!

void check_dosagem_personalizada_1()
{
  int16_t n;
  char buf[7];
  minuto01 = 0;
  char oldminuto9;
  oldminuto9 = time9;
  time9 = t.min;


  digitalWrite (4, LOW);

  if (oldminuto9!=time9)
  {  

    if(bitRead(modo_personalizado_on,1) == true)
    {
      if(bitRead(segunda_dosagem_personalizada,1) == t.dow)
      {
        if(file.open(&root, "HDP1.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();
      }
      if(terca_dosagem_personalizada_1 == t.dow)
      {
        if(file.open(&root, "HDP1.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();
      }
      if(quarta_dosagem_personalizada_1 == t.dow)
      {
        if(file.open(&root, "HDP1.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();
      }
      if(quinta_dosagem_personalizada_1 == t.dow)
      {
        if(file.open(&root, "HDP1.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();
      }
      if(sexta_dosagem_personalizada_1 == t.dow)
      {
        if(file.open(&root, "HDP1.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();
      }
      if(sabado_dosagem_personalizada_1 == t.dow)
      {
        if(file.open(&root, "HDP1.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();

      }
      if(domingo_dosagem_personalizada_1 == t.dow)
      {
        if(file.open(&root, "HDP1.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_1_personalizada/quantidade_dose_dosadora_1_personalizada)*2), 0, fator_calib_dosadora_1, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();
      }
    }
  }
  digitalWrite (4, HIGH);
}

void check_dosagem_personalizada_2()
{
  int16_t n;
  char buf[7];
  minuto01 = 0;
  char oldminuto10;
  oldminuto10 = time10;
  time10 = t.min;


  digitalWrite (4, LOW);

  if (oldminuto10!=time10)
  {  
    if(bitRead(modo_personalizado_on,2) == true)
    {
      if(bitRead(segunda_dosagem_personalizada,2) == t.dow)
      {
        if(file.open(&root, "HDP2.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();
      }
      if(terca_dosagem_personalizada_2 == t.dow)
      {
        if(file.open(&root, "HDP2.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();
      }
      if(quarta_dosagem_personalizada_2 == t.dow)
      {
        if(file.open(&root, "HDP2.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();
      }
      if(quinta_dosagem_personalizada_2 == t.dow)
      {
        if(file.open(&root, "HDP2.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();
      }
      if(sexta_dosagem_personalizada_2 == t.dow)
      {
        if(file.open(&root, "HDP2.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();
      }
      if(sabado_dosagem_personalizada_2 == t.dow)
      {
        if(file.open(&root, "HDP2.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();

      }
      if(domingo_dosagem_personalizada_2 == t.dow)
      {
        if(file.open(&root, "HDP2.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_2_personalizada/quantidade_dose_dosadora_2_personalizada)*2), 0, fator_calib_dosadora_2, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();
      }
    }
  }
  digitalWrite (4, HIGH);
}

void check_dosagem_personalizada_3()
{
  int16_t n;
  char buf[7];
  minuto01 = 0;
  char oldminuto11;
  oldminuto11 = time11;
  time11 = t.min;


  digitalWrite (4, LOW);

  if (oldminuto11!=time11)
  {  
    if(bitRead(modo_personalizado_on,3) == true)
    {
      if(bitRead(segunda_dosagem_personalizada,3) == t.dow)
      {
        if(file.open(&root, "HDP3.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
      if(terca_dosagem_personalizada_3 == t.dow)
      {
        if(file.open(&root, "HDP3.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
      if(quarta_dosagem_personalizada_3 == t.dow)
      {
        if(file.open(&root, "HDP3.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
      if(quinta_dosagem_personalizada_3 == t.dow)
      {
        if(file.open(&root, "HDP3.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
      if(sexta_dosagem_personalizada_3 == t.dow)
      {
        if(file.open(&root, "HDP3.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
      if(sabado_dosagem_personalizada_3 == t.dow)
      {
        if(file.open(&root, "HDP3.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
      if(domingo_dosagem_personalizada_3 == t.dow)
      {
        if(file.open(&root, "HDP3.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_3_personalizada/quantidade_dose_dosadora_3_personalizada)*2), 0, fator_calib_dosadora_3, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
    }
  }
  digitalWrite (4, HIGH);
}

void check_dosagem_personalizada_4()
{
  int16_t n;
  char buf[7];
  minuto01 = 0;
  char oldminuto15;
  oldminuto15 = time15;
  time15 = t.min;


  digitalWrite (4, LOW);

  if (oldminuto15!=time15)
  {  

    if(bitRead(modo_personalizado_on,4) == true)
    {
      if(bitRead(segunda_dosagem_personalizada,4) == t.dow)
      {
        if(file.open(&root, "HDP4.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_4_personalizada/quantidade_dose_dosadora_4_personalizada)*2), 0, fator_calib_dosadora_4, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();
      }
      if(terca_dosagem_personalizada_4 == t.dow)
      {
        if(file.open(&root, "HDP4.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_4_personalizada/quantidade_dose_dosadora_4_personalizada)*2), 0, fator_calib_dosadora_4, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();
      }
      if(quarta_dosagem_personalizada_4 == t.dow)
      {
        if(file.open(&root, "HDP4.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_4_personalizada/quantidade_dose_dosadora_4_personalizada)*2), 0, fator_calib_dosadora_4, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();
      }
      if(quinta_dosagem_personalizada_4 == t.dow)
      {
        if(file.open(&root, "HDP4.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_4_personalizada/quantidade_dose_dosadora_4_personalizada)*2), 0, fator_calib_dosadora_4, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();
      }
      if(sexta_dosagem_personalizada_4 == t.dow)
      {
        if(file.open(&root, "HDP4.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_4_personalizada/quantidade_dose_dosadora_4_personalizada)*2), 0, fator_calib_dosadora_4, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();
      }
      if(sabado_dosagem_personalizada_4 == t.dow)
      {
        if(file.open(&root, "HDP4.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_4_personalizada/quantidade_dose_dosadora_4_personalizada)*2), 0, fator_calib_dosadora_4, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();

      }
      if(domingo_dosagem_personalizada_4 == t.dow)
      {
        if(file.open(&root, "HDP4.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_4_personalizada/quantidade_dose_dosadora_4_personalizada)*2), 0, fator_calib_dosadora_4, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora1, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora1, LOW);
            }
          }
        }
        file.close();
      }
    }
  }
  digitalWrite (4, HIGH);
}

void check_dosagem_personalizada_5()
{
  int16_t n;
  char buf[7];
  minuto01 = 0;
  char oldminuto16;
  oldminuto16 = time16;
  time16 = t.min;


  digitalWrite (4, LOW);

  if (oldminuto16!=time16)
  {  
    if(bitRead(modo_personalizado_on,5) == true)
    {
      if(bitRead(segunda_dosagem_personalizada,5) == t.dow)
      {
        if(file.open(&root, "HDP5.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_5_personalizada/quantidade_dose_dosadora_5_personalizada)*2), 0, fator_calib_dosadora_5, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();
      }
      if(terca_dosagem_personalizada_5 == t.dow)
      {
        if(file.open(&root, "HDP5.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_5_personalizada/quantidade_dose_dosadora_5_personalizada)*2), 0, fator_calib_dosadora_5, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();
      }
      if(quarta_dosagem_personalizada_5 == t.dow)
      {
        if(file.open(&root, "HDP5.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_5_personalizada/quantidade_dose_dosadora_5_personalizada)*2), 0, fator_calib_dosadora_5, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();
      }
      if(quinta_dosagem_personalizada_5 == t.dow)
      {
        if(file.open(&root, "HDP5.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_5_personalizada/quantidade_dose_dosadora_5_personalizada)*2), 0, fator_calib_dosadora_5, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();
      }
      if(sexta_dosagem_personalizada_5 == t.dow)
      {
        if(file.open(&root, "HDP5.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_5_personalizada/quantidade_dose_dosadora_5_personalizada)*2), 0, fator_calib_dosadora_5, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();
      }
      if(sabado_dosagem_personalizada_5 == t.dow)
      {
        if(file.open(&root, "HDP5.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_5_personalizada/quantidade_dose_dosadora_5_personalizada)*2), 0, fator_calib_dosadora_5, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();

      }
      if(domingo_dosagem_personalizada_5 == t.dow)
      {
        if(file.open(&root, "HDP5.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_5_personalizada/quantidade_dose_dosadora_5_personalizada)*2), 0, fator_calib_dosadora_5, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora2, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora2, LOW);
            }
          }
        }
        file.close();
      }
    }
  }
  digitalWrite (4, HIGH);
}

void check_dosagem_personalizada_6()
{
  int16_t n;
  char buf[7];
  minuto01 = 0;
  char oldminuto17;
  oldminuto17 = time17;
  time17 = t.min;


  digitalWrite (4, LOW);

  if (oldminuto17!=time17)
  {  
    if(bitRead(modo_personalizado_on,6) == true)
    {
      if(bitRead(segunda_dosagem_personalizada,6) == t.dow)
      {
        if(file.open(&root, "HDP6.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_6_personalizada/quantidade_dose_dosadora_6_personalizada)*2), 0, fator_calib_dosadora_6, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
      if(terca_dosagem_personalizada_6 == t.dow)
      {
        if(file.open(&root, "HDP6.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_6_personalizada/quantidade_dose_dosadora_6_personalizada)*2), 0, fator_calib_dosadora_6, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
      if(quarta_dosagem_personalizada_6 == t.dow)
      {
        if(file.open(&root, "HDP6.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_6_personalizada/quantidade_dose_dosadora_6_personalizada)*2), 0, fator_calib_dosadora_6, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
      if(quinta_dosagem_personalizada_6 == t.dow)
      {
        if(file.open(&root, "HDP6.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_6_personalizada/quantidade_dose_dosadora_6_personalizada)*2), 0, fator_calib_dosadora_6, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
      if(sexta_dosagem_personalizada_6 == t.dow)
      {
        if(file.open(&root, "HDP6.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_6_personalizada/quantidade_dose_dosadora_6_personalizada)*2), 0, fator_calib_dosadora_6, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
      if(sabado_dosagem_personalizada_6 == t.dow)
      {
        if(file.open(&root, "HDP6.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_6_personalizada/quantidade_dose_dosadora_6_personalizada)*2), 0, fator_calib_dosadora_6, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
      if(domingo_dosagem_personalizada_6 == t.dow)
      {
        if(file.open(&root, "HDP6.TXT", O_READ))
        {
          while ((n = file.read(buf, sizeof(buf))) > 0)
          {
            minuto01 = atoi(buf);
            if(minuto01 ==  NumMins(t.hour,t.min))
            {
              tempo_dosagem = map (((dose_dosadora_6_personalizada/quantidade_dose_dosadora_6_personalizada)*2), 0, fator_calib_dosadora_6, 0, 60000);
              tempo_dosagem /= 2;                 
              digitalWrite(dosadora3, HIGH);
              delay(tempo_dosagem);
              digitalWrite(dosadora3, LOW);
            }
          }
        }
        file.close();
      }
    }
  }
  digitalWrite (4, HIGH);
}




