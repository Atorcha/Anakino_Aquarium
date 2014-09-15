//Write CR LF to a file

void writeCRLF(SdFile& f) 
{
  f.write((uint8_t*)"\r\n", 2);
}

void logtempgraf() //Grava dados no SD CARD para gerar  grafico de temperatura.
{
  char oldminuto1;
  oldminuto1 = time1;
  time1 = t.min;

  digitalWrite (4, LOW);  

  if (oldminuto1!=time1)
  {
    file.open(&root, "LOGTDIA.TXT", O_CREAT | O_APPEND | O_WRITE);

    if ((tempC<=1.0) || (tempC>99.9))
    {
      file.print("00.00");
      file.write((uint8_t*)"\0", 1);
      writeCRLF(file);
    }
    else
    {
      file.print(tempC);
      file.write((uint8_t*)"\0", 1);
      writeCRLF(file);
    }
  }
  file.close();

  if ((t.hour == 23) && (t.min > 58))
  {
    file.open(&root, "LOGTDIA.TXT", O_WRITE);
    file.remove();
  } 
  digitalWrite (4, HIGH);  
}



void logparametros() //Grava parametros no SD CARD para consultas posteriores
{
  digitalWrite (4, LOW);

  file.open(&root, "LOGPAR.TXT", O_CREAT | O_APPEND | O_WRITE);
  file.print(rtc.getDateStr(FORMAT_SHORT)); 
  writeCRLF(file);
  file.print(rtc.getTimeStr(FORMAT_LONG));
  writeCRLF(file);
  file.print(tempC);
  writeCRLF(file);
  writeCRLF(file);
  file.close();

  digitalWrite (4, HIGH);
}
