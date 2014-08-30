//------------------------------------ Menu 1 ----------------------------------------------------------- PANTALLA =1
void menuScreen()
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printHeader(buffer); // tabela_textos[1] = "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[3])));
  printButton(buffer, tanD[0], tanD[1], tanD[2], tanD[3]); // "HORA Y FECHA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[201])));
  printButton(buffer, tesT[0], tesT[1], tesT[2], tesT[3]); // "ILUMINACION"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[5])));
  printButton(buffer, temC[0], temC[1], temC[2], temC[3]); // "TEMPERATURA."

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[160])));
  printButton(buffer, ledW[0], ledW[1], ledW[2], ledW[3]); // tabela_textos[160] = "TEMPORIZADORES"
  
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[10])));// COMEDERO
  printButton(buffer, aFeed[0], aFeed[1], aFeed[2], aFeed[3]);
  
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[9])));
  printButton(buffer, dosA[0], dosA[1], dosA[2], dosA[3]); // "EEPROM"  

 // strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[8])));
 // printButton(buffer, tpaA[0], tpaA[1], tpaA[2], tpaA[3]); // "TPA AUTOMATICA"

 // printButton(buffer, wavM[0], wavM[1], wavM[2], wavM[3]); //  "COMEDERO" 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[2])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 2";
}

// -------------------------Reloj------------------------------------------------------ PANTALLA =2
void setClock()   
{
  t_temp = rtc.getTime();

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[12])));
  printHeader(buffer); // tabela_textos[12] = "ALTERAR HORA E DATA"

  printButton ("+", houU[0], houU[1], houU[2], houU[3], true);   //hour up
  printButton ("-", houD[0], houD[1], houD[2], houD[3], true);   //hour down

  printButton ("+", minU[0], minU[1], minU[2], minU[3], true);   //min up
  printButton ("-", minD[0], minD[1], minD[2], minD[3], true);   //min down 

  printButton ("+", segC[0], segC[1], segC[2], segC[3], true);   //segundo mais
  printButton ("-", segB[0], segB[1], segB[2], segB[3], true);   //segundo menos

  printButton ("+", yeaU[0], yeaU[1], yeaU[2], yeaU[3], true);    //year up
  printButton ("-", yeaD[0], yeaD[1], yeaD[2], yeaD[3], true);     //year down

  printButton ("-", dayD[0], dayD[1], dayD[2], dayD[3], true);     //day down
  printButton ("+", dayU[0], dayU[1], dayU[2], dayU[3], true);    //day up

  printButton ("+", monU[0], monU[1], monU[2], monU[3], true);    //month up
  printButton ("-", monD[0], monD[1], monD[2], monD[3], true);     //month down

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
  printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[14])));
  myGLCD.print(buffer, 10, 51); // "HORA:"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[15])));
  myGLCD.print(buffer, 10, 134); // "DATA:"

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.print(":", 120, 48);
  myGLCD.print(":", 210, 48);

  if (t_temp.hour<10)
  {
    myGLCD.printNumI(0, 70, 48);
    myGLCD.printNumI(t_temp.hour, 86, 48);
  }
  else
  {
    myGLCD.printNumI(t_temp.hour, 70, 48);
  } 
  if (t_temp.min<10)
  {
    myGLCD.printNumI(0, 160, 48);
    myGLCD.printNumI(t_temp.min, 176, 48);
  }
  else
  {
    myGLCD.printNumI(t_temp.min, 160, 48);
  } 
  if (t_temp.sec<10)
  {
    myGLCD.printNumI(0, 250, 48);
    myGLCD.printNumI(t_temp.sec, 266, 48);
  }
  else
  {
    myGLCD.printNumI(t_temp.sec, 250, 48);
  }
  if (t_temp.date<10)
  {
    myGLCD.printNumI(0, 70, 132);
    myGLCD.printNumI(t_temp.date, 86, 132);
  }
  else
  {
    myGLCD.printNumI(t_temp.date, 70, 132);
  }
  if (t_temp.mon<10)
  {
    myGLCD.printNumI(0, 160, 132);
    myGLCD.printNumI(t_temp.mon, 176, 132);
  }
  else
  {
    myGLCD.printNumI(t_temp.mon, 160, 132);
  }
  myGLCD.printNumI(t_temp.year, 230, 132);

}

//---------------------------------------------Selecciona que  Temperatura configurar -------------------------------- PANTALLA =3
void seleccionartemperatura()
{
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[26])));
    printHeader(buffer); //tabela_textos[26] "SELECCIONA TEMPERATURA A CONFIGURAR"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[32])));
    printButton(buffer, tanD[0], tanD[1], tanD[2], tanD[3]); // "AGUA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[33])));
    printButton(buffer, tesT[0], tesT[1], tesT[2], tesT[3]); // "TAPA"    
}



//---------------------------------------------Configura Temperatura del Agua -------------------------------- PANTALLA =4 
void tempScreen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setTempC==0) {
      setTempC = tempC;  
    }                  //change to current temp.
    temp2beS = setTempC;
    temp2beO = offTempC;
    temp2beA = alarmTempC;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[24])));
    printHeader(buffer); //tabela_textos[24] "CONTROLE DE TEMPERATURA DA AGUA"

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[74])));
    myGLCD.print(buffer, 85, 20); // "TEMPERATURA DESEJADA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[75])));
    myGLCD.print(buffer, 90, 70); // "VARIACAO PERMITIDA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[76])));
    myGLCD.print(buffer, 50, 120); // "VARIACAO PARA ACIONAR O ALARME:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU"
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumF(temp2beS, 1, 130, 40);
  myGLCD.printNumF(temp2beO, 1, 140, 90);
  myGLCD.printNumF(temp2beA, 1, 140, 140);
}
//-------------------------------- Configurar temperatura tapa ----------------------------------- PANTALLA =5
void temperaturatapa()
{
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[34])));
    printHeader(buffer); //tabela_textos[24] "CONTROL DE TEMPERATURA DE TAPA"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[27])));
    myGLCD.print(buffer, 90, 70); // "TEMPERATURA MAXIMA DEL DISIPADOR"
  
}

//--------------------------------------- Menu EEPROM------------------------------ PANTALLA =6

void menu_eeprom()

{
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[36])));
    printHeader(buffer); //tabela_textos[24] "MENU EEPROM"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[191])));
    printButton(buffer, tanD[0], tanD[1], tanD[2], tanD[3]); // "BORRAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[192])));
    printButton(buffer, tesT[0], tesT[1], tesT[2], tesT[3]); // "GRABAR" 
  
} 

//-------------------------Borrar EEPROM------------------------

void borrar_eeprom_screen()
{
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[36])));
    printHeader(buffer); //tabela_textos[24] "MENU EEPROM"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU"
    
    setFont(LARGE, 255, 255, 0, 0, 0, 0); 
    myGLCD.setColor(255, 0, 0);   
    myGLCD.print("Confirme que borrara toda la eeprom", 50, 100);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[191])));
    printButton_vermelho(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // BORRAR en rojo    
   
}

//----------------------Parametros---------------------------------------------PANTALLA =14


//******** AUTOMATIC FEEDER SCREEN *************  ***********************      pantalla = 19
void comederoScreen()
{
  printHeader("PAGINA DE COMEDERO AUTOMATICO");  
  
  myGLCD.setColor(64, 64, 64);
  myGLCD.drawRect(0, 196, 319, 194);
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";
  
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"  
  
  myGLCD.setColor(64, 64, 64);
  myGLCD.drawRect(159, 194, 161, 121);
  myGLCD.drawRoundRect(78, 87, 242, 121);    
  myGLCD.drawRoundRect(80, 89, 240, 119);  
  myGLCD.drawRect(0, 103, 78, 105);
  myGLCD.drawRect(242, 103, 319, 105); 
  myGLCD.drawLine(159, 87, 159, 14);  
  myGLCD.drawLine(161, 87, 161, 14);  
  myGLCD.setColor(0, 0, 0);
  myGLCD.drawLine(160, 195, 160, 193);
  myGLCD.drawLine(160, 122, 160, 120);
  myGLCD.drawLine(77, 104, 79, 104);
  myGLCD.drawLine(241, 104, 243, 104);  
  myGLCD.drawLine(160, 88, 160, 86);

  myGLCD.setColor(153, 0, 102);
  myGLCD.fillRoundRect(85, 94, 235, 114);           //Feed Fish Now Button
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect(85, 94, 235, 114); 
  setFont(SMALL, 255, 255, 255, 153, 0, 102);
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[35])));
  myGLCD.print(buffer, 106, 98); //Dar de comer ahora

  if (comedero1==0)                                 //Feeding Time 1 Button 
    { myGLCD.setColor(255, 0, 0);
      myGLCD.fillRoundRect(5, 20, 155, 40);
      setFont(SMALL, 255, 255, 255, 255, 0, 0);
      myGLCD.print("Feeding Time 1", 24, 24);
      setFont(SMALL, 255, 0, 0, 0, 0, 0);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[28])));    
      myGLCD.print(buffer, 12, 52);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[29])));
      myGLCD.print(buffer, 24, 65);}      
  else
    { myGLCD.setColor(0, 255, 0);
      myGLCD.fillRoundRect(5, 20, 155, 40);
      setFont(SMALL, 0, 0, 0, 0, 255, 0);
      myGLCD.print("Feeding Time 1", 24, 24);
      setFont(LARGE, 255, 255, 255, 0, 0, 0);          
      myGLCD.printNumI(comedero1H,30,55);
      myGLCD.print(":",60,55);
      myGLCD.printNumI(comedero1M,70,55);
      
      }
  if (comedero2==0)                                 //Feeding Time 2 Button
    { myGLCD.setColor(255, 0, 0);
      myGLCD.fillRoundRect(165, 20, 315, 40);
      setFont(SMALL, 255, 255, 255, 255, 0, 0);
      myGLCD.print("Feeding Time 2", 184, 24); 
      setFont(SMALL, 255, 0, 0, 0, 0, 0);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[28])));
      myGLCD.print(buffer, 172, 52);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[29])));
      myGLCD.print(buffer, 184, 65);}      
  else
    { myGLCD.setColor(0, 255, 0);
      myGLCD.fillRoundRect(165, 20, 315, 40);
      setFont(SMALL, 0, 0, 0, 0, 255, 0);
      myGLCD.print("Feeding Time 2", 184, 24);
      setFont(LARGE, 255, 255, 255, 0, 0, 0);          
      myGLCD.printNumI(comedero2H,200,55);
      myGLCD.print(":",230,55);
      myGLCD.printNumI(comedero2M,240,55);      
      }          
  if (comedero3==0)                                 //Feeding Time 3 Button
    { myGLCD.setColor(255, 0, 0);
      myGLCD.fillRoundRect(5, 168, 155, 188);
      setFont(SMALL, 255, 255, 255, 255, 0, 0);
      myGLCD.print("Feeding Time 3", 24, 172);
      setFont(SMALL, 255, 0, 0, 0, 0, 0);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[28])));
      myGLCD.print(buffer, 12, 133);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[29])));
      myGLCD.print(buffer, 24, 146);}       
  else
    { myGLCD.setColor(0, 255, 0);
      myGLCD.fillRoundRect(5, 168, 155, 188);
      setFont(SMALL, 0, 0, 0, 0, 255, 0);
      myGLCD.print("Feeding Time 3", 24, 172);
      setFont(LARGE, 255, 255, 255, 0, 0, 0);          
      myGLCD.printNumI(comedero3H,30,130);
      myGLCD.print(":",60,130);
      myGLCD.printNumI(comedero3M,70,130);      
      }          
  if (comedero4==0)                                 //Feeding Time 4 Button
    { myGLCD.setColor(255, 0, 0);
      myGLCD.fillRoundRect(165, 168, 315, 188);
      setFont(SMALL, 255, 255, 255, 255, 0, 0);
      myGLCD.print("Feeding Time 4", 184, 172); 
      setFont(SMALL, 255, 0, 0, 0, 0, 0);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[28])));
      myGLCD.print(buffer, 172, 133);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[29])));
      myGLCD.print(buffer, 184, 146);}
  else
    { myGLCD.setColor(0, 255, 0);
      myGLCD.fillRoundRect(165, 168, 315, 188);
      setFont(SMALL, 0, 0, 0, 0, 255, 0);
      myGLCD.print("Feeding Time 4", 184, 172);
      setFont(LARGE, 255, 255, 255, 0, 0, 0);          
      myGLCD.printNumI(comedero4H,200,130);
      myGLCD.print(":",230,130);
      myGLCD.printNumI(comedero4M,230,130);
      }      

  myGLCD.setColor(255, 255, 255);
  for (int x=0; x<2; x++)
    { for (int y=0; y<2; y++)
        { myGLCD.drawRoundRect((x*160)+5, (y*148)+20, (x*160)+155, (y*148)+40); }
    }    
}

/***** PANTALLA DE AJUSTE HORARIOS DE COMEDEROS Y MODO ********** pantalla = 20 *******************/
void config_comedero(boolean refreshAll=false) 
{
  if( refreshAll == true)
  {
    comedero1H_Temp = comedero1H;
    comedero1M_Temp = comedero1M;
    comedero2H_Temp = comedero2H;
    comedero2M_Temp = comedero2M;
    comedero3H_Temp = comedero3H;
    comedero3M_Temp = comedero3M;
    comedero4H_Temp = comedero4H;
    comedero4M_Temp = comedero4M;
    comedero1_Temp  = comedero1;
    comedero2_Temp  = comedero2;
    comedero3_Temp  = comedero3;
    comedero4_Temp  = comedero4;
    
  if (comedero == 1)
    { printHeader("Ajusta horario 1"); }      
  else if (comedero == 2)
    { printHeader("Ajusta horario  2");}
  else if (comedero == 3)
    { printHeader("Ajusta horario 3");}
  else if (comedero == 4)
    { printHeader("Ajusta horario 4");}
   
    printButton("+", 21, 45, 65, 88, true);     // Boton mas
    printButton("+", 89, 45, 133, 88, true);    // Boton mas
    printButton("-", 21, 135, 65, 178, true);   // Boton menos
    printButton("-", 89, 135, 133, 178, true);  // Boton menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"
  
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "VOLVER";
  
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));   
  printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // Guarda las modificaciones. // "SALVAR"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);          
    myGLCD.print(":",70, 103);
  }
  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  
   if (comedero == 1)//******************************* Pantalla comedero  1 *******************************
{
    if (comedero1H_Temp < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(comedero1H_Temp, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(comedero1H_Temp, 27, 100);
    }

    if (comedero1M_Temp < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(comedero1M_Temp, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(comedero1M_Temp, 95, 100);
    }

    if (comedero1_Temp == 1)  
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Verde > ON
    } 
    else if (comedero1_Temp == 0) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton_vermelho(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Rojo > OFF 
    }
  }
      
  if (comedero == 2) //******************************* Pantalla comedero  2 *******************************
{
    if (comedero2H_Temp < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(comedero2H_Temp, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(comedero2H_Temp, 27, 100);
    }

    if (comedero2M_Temp < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(comedero2M_Temp, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(comedero2M_Temp, 95, 100);
    }

    if (comedero2_Temp == 1)  
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Verde > ON
    } 
    else if (comedero2_Temp == 0) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton_vermelho(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Rojo > OFF 
    }
  }
      
  if (comedero == 3) //******************************* Pantalla comedero  3 *******************************
{
    if (comedero3H_Temp < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(comedero3H_Temp, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(comedero3H_Temp, 27, 100);
    }

    if (comedero3M_Temp < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(comedero3M_Temp, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(comedero3M_Temp, 95, 100);
    }

    if (comedero3_Temp == 1)  
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Verde > ON
    } 
    else if (comedero3_Temp == 0) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton_vermelho(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Rojo > OFF 
    }
  }
      
  if (comedero == 4)  //******************************* Pantalla comedero  4 *******************************
{
    if (comedero4H_Temp < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(comedero4H_Temp, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(comedero4H_Temp, 27, 100);
    }

    if (comedero4M_Temp < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(comedero4M_Temp, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(comedero4M_Temp, 95, 100);
    }

    if (comedero4_Temp == 1)  
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Verde > ON
    } 
    else if (comedero4_Temp == 0) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton_vermelho(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Rojo > OFF 
    }
  }
  
  }    


/********************** END OF SET AUTOMATIC FEEDER TIMES SCREEN **********************/

//----------Selecciona peristaltica-----------------------------------PANTALLA =21
void selecionar_dosadora()
{

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[41])));
  printHeader(buffer); // tabela_textos[41] = "ESCOLHA UMA DOSADORA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[102])));
  printButton(buffer, dosa1[0], dosa1[1], dosa1[2], dosa1[3]); // tabela_textos[102] = "DOSADORA 1"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[103])));
  printButton(buffer, dosa2[0], dosa2[1], dosa2[2], dosa2[3]); // tabela_textos[103] = "DOSADORA 2"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[104])));
  printButton(buffer, dosa3[0], dosa3[1], dosa3[2], dosa3[3]); // tabela_textos[104] = "DOSADORA 3"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[204])));
  printButton(buffer, dosa4[0], dosa4[1], dosa4[2], dosa4[3]); // tabela_textos[204] = "DOSADORA 4"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[205])));
  printButton(buffer, dosa5[0], dosa5[1], dosa5[2], dosa5[3]); // tabela_textos[205] = "DOSADORA 5"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[206])));
  printButton(buffer, dosa6[0], dosa6[1], dosa6[2], dosa6[3]); // tabela_textos[206] = "DOSADORA 6"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);  // "VOLTAR"
}

//--------------------------- Prueba manual de leds ----------------------------------------------------- PANTALLA =22
/*void teste_individual_leds()
{
  wled_out_temp = wled_out;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[16])));
  printHeader(buffer); // tabela_textos[16] "TESTAR VARIACAO DE LUMINOSIDADE"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);  // "VOLTAR"

  printButton("+", 49, 18, 93, 41, true);    // "+"
  printButton("+", 101, 18, 145, 41, true);  // "+"
  printButton("+", 153, 18, 197, 41, true);  // "+"
  printButton("+", 205, 18, 249, 41, true);  // "+"
  printButton("+", 257, 18, 301, 41, true);  // "+"

  printButton("-", 49, 201, 93, 224, true);    // "-"
  printButton("-", 101, 201, 145, 224, true);  // "-"
  printButton("-", 153, 201, 197, 224, true);  // "-"
  printButton("-", 205, 201, 249, 224, true);  // "-"
  printButton("-", 257, 201, 301, 224, true);  // "-"

  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(0,0,0);

  myGLCD.setColor(cor_canal1[0], cor_canal1[1],cor_canal1[2]); 
  myGLCD.drawRect(49, 44, 93, 172);   // % bar place holder 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[1])));
  myGLCD.print(buffer, 61, 176);   //  Branco

  myGLCD.printNumI(wled_out_temp, 61, 186);
  

  setFont(SMALL, 255, 255, 255, 0, 0, 0); 
  myGLCD.drawRect(30, 173, 315, 173);     // Eixo x
  myGLCD.drawRect(30, 173, 30, 44);       // eixo y  

  myGLCD.setColor(190, 190, 190);
  for (int i=0; i<10; i++){               // Escala % 
    myGLCD.drawLine(31, (i*13)+44, 38, (i*13)+44); 
  } 
  for (int i=0; i<10; i++){              
    myGLCD.drawLine(31, (i*13)+51, 34, (i*13)+51); 
  } 

  myGLCD.setFont(SmallFont);
  myGLCD.print("%", 20, 25);     // %
  myGLCD.print("100", 5, 41);   // 100
  myGLCD.print("90", 12, 54);   // 90
  myGLCD.print("80", 12, 67);   // 80
  myGLCD.print("70", 12, 80);   // 70
  myGLCD.print("60", 12, 93);   // 60
  myGLCD.print("50", 12, 106);  // 50
  myGLCD.print("40", 12, 119);  // 40
  myGLCD.print("30", 12, 132);  // 30
  myGLCD.print("20", 12, 145);  // 20
  myGLCD.print("10", 12, 158);  // 10
  myGLCD.print("0", 20, 171);   // 0

  myGLCD.setColor(180, 180, 180);                  
  for (int i=0; i<10; i++){                      // escalas de linhas pontilhadas horizontais 
    for(int k=46; k<311; k++){ 
      myGLCD.drawPixel(k,(i*13)+44); 
      k=k+2;
    } 
  } 

  //void desenhar_barras(int sbR, int sbG, int sbB, int sbX1, int sbY1, int sbX2, int sbY2)

  y_tocado = map(wled_out_temp, 255, 0, 44, 172);
  desenhar_barras(cor_canal1[0], cor_canal1[1],cor_canal1[2], 49, 44, 93, 172);                                                            
}

*/


//---------------------------------------- Opções de teste dos leds ---------------------- PANTALLA =25

/*void escolher_teste()
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[49])));
  printHeader(buffer); //tabela_textos[49] = "ESCOLHA UM TIPO DE TESTE"; 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";  

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[67])));
  printButton(buffer, testI[0], testI[1], testI[2], testI[3]); // "TESTE INDIVIDUAL"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[68])));
  printButton(buffer, testT[0], testT[1], testT[2], testT[3]); // "TESTAR TODOS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[69])));
  printButton(buffer, preD[0], preD[1], preD[2], preD[3]); // "PRE DEFINIDO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);// "VOLTAR
}






//----------------Seleccionar canal------------------------------------------ PANTALLA =28
void escolher_canal() 
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[11])));
  printHeader(buffer); // nome_canal[11] = "ESCOLHA UMA COR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3],false); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3],false); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);// "VOLTAR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[6])));
  printButton(buffer, tempG[0], tempG[1], tempG[2],tempG[3]); // "BRANCO"
}  
*/
// ---------Configurar dosificacion personalizada----------tela =29

// ----------tela =31

//--------------------Regresar configuracion dosadoras-------------------------tela =32
 
// ------------------------------------------------------------------tela =34


//---------------------------------------------Desativar dosadoras--------------------------------tela =35 ----------

//--------------------------------------------- Potência mínima e máxima para a luz noturna -------------------------------- tela =36 
void luz_noturna(boolean refreshAll=false)
{

  if (refreshAll)
  {
    tMaxI = MaxI;
    tMinI = MinI;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[52])));
    printHeader(buffer); // tabela_textos[52] = "LUZ NOTURNA   255 = 100 %"

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[180])));
    myGLCD.print(buffer, 90, 70); // "ILUMINACAO MAXIMA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[156])));
    myGLCD.print(buffer, 90, 170); // "ILUMINACAO MINIMA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[157])));
    myGLCD.print(buffer, 120, 20); // "LUA CHEIA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[158])));
    myGLCD.print(buffer, 125, 120); // "LUA NOVA:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //Lua cheia menos
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //Lua cheia mais
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //Lua nova menos
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //Lua nova mais

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);  // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);  // tabela_textos[66] = "VOLTAR";
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0); 
  myGLCD.printNumI(tMaxI, 135, 40);
  myGLCD.printNumI(tMinI, 135, 140);
}

//--------------------------------------------- Menu 2 -------------------------------- tela =37
void menuScreen_2()
{

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[2])));
  printHeader(buffer); // tabela_textos[2] = "MENU 2"
  // printButton("", tanD[0], tanD[1], tanD[2], tanD[3]); // 1º botaão, 1ª coluna
  //  printButton("", tesT[0], tesT[1], tesT[2], tesT[3]); // 2º botão, 1ª coluna 
  //  printButton("", temC[0], temC[1], temC[2], temC[3]); // 3º botão, 1ª coluna
  //  printButton("", graF[0], graF[1], graF[2], graF[3]); // 4º botão, 1ª coluna
  //  printButton("", ledW[0], ledW[1], ledW[2], ledW[3]); // 1º botão, 2ª coluna
  //  printButton("", tpaA[0], tpaA[1], tpaA[2], tpaA[3]); // 2º botão, 2ª coluna
  //  printButton("", dosA[0], dosA[1], dosA[2], dosA[3]); // 3º botão, 2ª coluna
  //  printButton("", wavM[0], wavM[1], wavM[2], wavM[3]); // 4º botão, 2ª coluna
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"
}

//--------------------------------------------- Timers -------------------------------- tela =38
void TimerScreen()
{ 
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[53])));
  printHeader(buffer); // tabela_textos[53] = "SELECIONE O TIMER"
  //***************** TIMER 1  ******************

  if (temporizador_1_ativado == 1) 
  {
    printButton("T 1",7, 22, 56, 50);           // Timer 1 AUTO > Azul
  }
  else if(temporizador_1_ativado == 2) 
  {
    printButton_verde("T 1",7, 22, 56, 50);     // Timer 1 ON  > Verde
  } 
  else
  {
    printButton_vermelho("T 1",7, 22, 56, 50);  // Timer 1 OFF > Rojo
  } 
  //***************** TIMER 2  ******************

  if (temporizador_2_ativado == 1) 
  {
    printButton("T 2",71, 22, 120, 50);           // Timer 2 AUTO > Azul 
  }
  else if(temporizador_2_ativado == 2) 
  {
    printButton_verde("T 2",71, 22, 120, 50);     // Timer 2 ON  > Verde
  } 
  else
  {
    printButton_vermelho("T 2",71, 22, 120, 50);   // Timer 2 OFF > Rojo
  } 
  //***************** TIMER 3  ******************
  if (temporizador_3_ativado == 1) 
  {
    printButton("T 3",135, 22, 184, 50);            // Timer 3 AUTO > Azul
  }
  else if(temporizador_3_ativado == 2) 

  {
    printButton_verde("T 3",135, 22, 184, 50);      // Timer 3 ON  > Verde
  }
  else
  {
    printButton_vermelho("T 3",135, 22, 184, 50);   // Timer 3 OFF > Rojo
  }
  //***************** TIMER 4  ******************

  if (temporizador_4_ativado == 1) 
  {
    printButton("T 4",199, 22, 248, 50);           // Timer 4 AUTO > Azul
  }
  else if(temporizador_4_ativado == 2) 
  {
    printButton_verde("T 4",199, 22, 248, 50);     // Timer 4 ON  > Verde
  }
  else
  {
    printButton_vermelho("T 4",199, 22, 248, 50);   // Timer 4 OFF > Rojo
  }
  //***************** TIMER 5  ******************

  if (temporizador_5_ativado == 1) 
  {
    printButton("T 5",263, 22, 312, 50);          // Timer 5 AUTO > Azul
  }
  else if(temporizador_5_ativado == 2) 
  {
    printButton_verde("T 5",263, 22, 312, 50);    // Timer 5 ON  > Verde
  } 
  else
  {
    printButton_vermelho("T 5",263, 22, 312, 50); // Timer 5 OFF > Rojo
  }


  //*********************************************

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,7, 55, 56, 97);      // Botão ON 1 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,71, 55, 120, 97);    // Botão ON 2

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,135, 55, 184, 97);   // Botão ON 3

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,199, 55, 248, 97);   // Botão ON 4

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,263, 55, 312, 97);   // Botão ON 5

  myGLCD.setColor(255, 255, 255);  // Retângulos ao redor dos horários
  myGLCD.drawRoundRect(7, 102, 56, 144);      // Botão ON 1 
  myGLCD.drawRoundRect(71, 102, 120, 144);    // Botão ON 2 
  myGLCD.drawRoundRect(135, 102, 184, 144);   // Botão ON 3 
  myGLCD.drawRoundRect(199, 102, 248, 144);   // Botão ON 4 
  myGLCD.drawRoundRect(263, 102, 312, 144);   // Botão ON 5  

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 8, 149, 55, 191);      // Botão OFF 1 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 72, 149, 119, 191);    // Botão OFF 2 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 136, 149, 183, 191);   // Botão OFF 3 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 200, 149, 247, 191);   // Botão OFF 4 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 264, 149, 311, 191);   // Botão OFF 5 

  myGLCD.setColor(255, 255, 255);  // Retângulos ao redor dos horários
  myGLCD.drawRoundRect(7, 196, 56, 238);     // Botão OFF 1 
  myGLCD.drawRoundRect(71, 196, 120, 238);   // Botão OFF 2 
  myGLCD.drawRoundRect(135, 196, 184, 238);  // Botão OFF 3 
  myGLCD.drawRoundRect(199, 196, 248, 238);  // Botão OFF 4 
  myGLCD.drawRoundRect(263, 196, 312, 238);  // Botão OFF 5

  myGLCD.setBackColor(0, 0, 0);

  if (on1_hora < 10) // Timer 1
  { 
    myGLCD.print("0",12, 117); 
    myGLCD.printNumI(on1_hora,21,117);
  }
  else
  {
    myGLCD.printNumI(on1_hora, 12, 117);
  }
  myGLCD.print(":", 29, 117); 

  if (on1_minuto < 10)
  { 
    myGLCD.print("0", 37, 117);
    myGLCD.printNumI(on1_minuto, 46, 117);
  } 
  else 
  { 
    myGLCD.printNumI(on1_minuto, 37,117);
  }      

  if (on2_hora < 10) // Timer 2
  { 
    myGLCD.print("0", 76, 117);
    myGLCD.printNumI(on2_hora ,85, 117);
  }
  else
  {
    myGLCD.printNumI(on2_hora, 76, 117);
  }

  myGLCD.print(":", 93, 117);    

  if (on2_minuto < 10)
  { 
    myGLCD.print("0",101, 117);  
    myGLCD.printNumI(on2_minuto, 110, 117);
  } 
  else 
  { 
    myGLCD.printNumI(on2_minuto,101, 117);
  } 

  if (on3_hora <10) // Timer 3
  { 
    myGLCD.print("0",140, 117);   
    myGLCD.printNumI(on3_hora,149, 117);
  }
  else
  {
    myGLCD.printNumI(on3_hora, 140, 117);
  } 

  myGLCD.print(":",157, 117);          

  if (on3_minuto < 10)
  { 
    myGLCD.print("0",165, 117);  
    myGLCD.printNumI(on3_minuto, 174, 117);
  } 
  else { 
    myGLCD.printNumI(on3_minuto ,165, 117);
  } 

  if (on4_hora < 10) // Timer 4
  { 
    myGLCD.print("0",204, 117); 
    myGLCD.printNumI(on4_hora,213, 117);
  }
  else{
    myGLCD.printNumI(on4_hora,204, 117);
  }

  myGLCD.print(":",221, 117);         

  if (on4_minuto < 10)
  { 
    myGLCD.print("0",229, 117);  
    myGLCD.printNumI(on4_minuto, 238, 117);
  } 
  else 
  { 
    myGLCD.printNumI(on4_minuto, 229, 117);
  } 

  if (on5_hora < 10) // Timer 5
  { 
    myGLCD.print("0",268, 117);  
    myGLCD.printNumI(on5_hora, 277, 117);
  }
  else
  {
    myGLCD.printNumI(on5_hora, 268, 117);
  } 

  myGLCD.print(":",285, 117);          

  if (on5_minuto < 10)
  { 
    myGLCD.print("0", 293, 117); 
    myGLCD.printNumI(on5_minuto, 302, 117);
  } 
  else 
  { 
    myGLCD.printNumI(on5_minuto, 293, 117);
  } 

  if (off1_hora < 10) // Timer 1
  { 
    myGLCD.print("0",12, 211); 
    myGLCD.printNumI(off1_hora, 21, 211);
  }
  else
  {
    myGLCD.printNumI(off1_hora, 12, 211);
  }

  myGLCD.print(":", 29, 210); 

  if (off1_minuto < 10)
  { 
    myGLCD.print("0", 37, 211);
    myGLCD.printNumI(off1_minuto, 46, 211);
  } 
  else 
  { 
    myGLCD.printNumI(off1_minuto, 37,211);
  }      

  if (off2_hora < 10) // Timer 2
  { 
    myGLCD.print("0", 76, 211);
    myGLCD.printNumI(off2_hora , 85, 211);
  }
  else
  {
    myGLCD.printNumI(off2_hora, 76, 211);
  }

  myGLCD.print(":", 93, 211);    

  if (off2_minuto < 10)
  { 
    myGLCD.print("0",101, 211);  
    myGLCD.printNumI(off2_minuto, 110, 211);
  } 
  else 
  { 
    myGLCD.printNumI(off2_minuto,101, 211);
  } 

  if (off3_hora <10) // Timer 3
  { 
    myGLCD.print("0", 140, 211);   
    myGLCD.printNumI(off3_hora, 149, 211);
  }
  else
  {
    myGLCD.printNumI(off3_hora, 140, 211);
  } 

  myGLCD.print(":", 157, 211);          

  if (off3_minuto < 10)
  { 
    myGLCD.print("0", 165, 211);  
    myGLCD.printNumI(off3_minuto, 174, 211);
  } 
  else 
  { 
    myGLCD.printNumI(off3_minuto, 165, 211);
  } 

  if (off4_hora < 10) // Timer 4
  { 
    myGLCD.print("0", 204, 211); 
    myGLCD.printNumI(off4_hora, 213, 211);
  }
  else
  {
    myGLCD.printNumI(off4_hora, 204, 211);
  }

  myGLCD.print(":", 221, 211);         

  if (off4_minuto < 10)
  { 
    myGLCD.print("0", 229, 211);  
    myGLCD.printNumI(off4_minuto, 238, 211);
  } 
  else 
  { 
    myGLCD.printNumI(off4_minuto, 229, 211);
  } 

  if (off5_hora < 10) // Timer 5
  { 
    myGLCD.print("0", 268, 211);  
    myGLCD.printNumI(off5_hora, 277, 211);
  }
  else
  {
    myGLCD.printNumI(off5_hora, 268, 211);
  } 

  myGLCD.print(":", 285, 211);          

  if (off5_minuto < 10)
  { 
    myGLCD.print("0", 293, 211); 
    myGLCD.printNumI(off5_minuto, 302, 211);
  } 
  else { 
    myGLCD.printNumI(off5_minuto, 293, 211);
  }

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // Volta ao menu 1. // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // Volta ao início.  // "INICIO"
} 
//--------------------------------------------- Configurar timers -------------------------------- tela =39
void config_timer(boolean refreshAll=false)
{
  if( refreshAll == true)
  {
    on1_minuto_temp2 = on1_minuto;
    on1_hora_temp2 = on1_hora;
    on2_minuto_temp2 = on2_minuto;
    on2_hora_temp2 = on2_hora;
    on3_minuto_temp2 = on3_minuto;
    on3_hora_temp2 = on3_hora;
    on4_minuto_temp2 = on4_minuto;
    on4_hora_temp2 = on4_hora;
    on5_minuto_temp2 = on5_minuto;
    on5_hora_temp2 = on5_hora ;
    off1_minuto_temp2 = off1_minuto;
    off1_hora_temp2 = off1_hora;
    off2_minuto_temp2 = off2_minuto;
    off2_hora_temp2 = off2_hora;
    off3_minuto_temp2 = off3_minuto;
    off3_hora_temp2 = off3_hora;
    off4_minuto_temp2 = off4_minuto;
    off4_hora_temp2 = off4_hora;
    off5_minuto_temp2 = off5_minuto;
    off5_hora_temp2 = off5_hora;
    temporizador_1_ativado_temp2 = temporizador_1_ativado;
    temporizador_2_ativado_temp2 = temporizador_2_ativado;
    temporizador_3_ativado_temp2 = temporizador_3_ativado;
    temporizador_4_ativado_temp2 = temporizador_4_ativado;
    temporizador_5_ativado_temp2 = temporizador_5_ativado;

    if(bitRead(temporizador,1) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[54])));
      printHeader(buffer); // tabela_textos[54] = "CONFIGURAR TIMER 1"
    }
    else if(bitRead(temporizador,2) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[55])));
      printHeader(buffer); // tabela_textos[55] = "CONFIGURAR TIMER 2"
    }
    else  if(bitRead(temporizador,3) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[56])));
      printHeader(buffer); // tabela_textos[56] = "CONFIGURAR TIMER 3"
    }
    else if(bitRead(temporizador,4) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[57])));
      printHeader(buffer); // tabela_textos[57] = "CONFIGURAR TIMER 4"
    } 
    else if(bitRead(temporizador,5) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[58])));
      printHeader(buffer); // tabela_textos[58] ="CONFIGURAR TIMER 5"
    }

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[161])));
    printButton_verde(buffer, 8, 17, 142, 34); // "LIGAR TIMER"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[162])));
    printButton_vermelho(buffer, 173, 17, 312, 34); // "DESLIGAR TIMER"

    printButton("+", 21, 45, 65, 88, true);    // Botão para cima
    printButton("+", 89, 45, 133, 88, true);    // Botão para cima
    printButton("-", 21, 135, 65, 178, true); // Botão para baixo
    printButton("-", 89, 135, 133, 178, true); // Botão para baixo

    printButton("+", 187, 45, 231, 88, true);    // Botão para cima
    printButton("+", 255, 45, 299, 88, true);    // Botão para cima
    printButton("-", 187, 135, 231, 178, true); // Botão para baixo
    printButton("-", 255, 135, 299, 178, true); // Botão para baixo

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // Vuelta al menu 1.  // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // Vuelta al inicio. // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // Vuelta al menu selecionar timer. // "VOLTAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // Salva las modificaciones. // "SALVAR"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);          
    myGLCD.print(":",70, 103);
    myGLCD.print(":",236, 103);
  }
  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  if(bitRead(temporizador,1) == true)
  {
    if (on1_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on1_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on1_hora_temp2, 27, 100);
    }

    if (on1_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on1_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on1_minuto_temp2, 95, 100);
    }

    if (off1_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off1_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off1_hora_temp2, 193, 100);
    }

    if (off1_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off1_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off1_minuto_temp2, 262, 100);
    }
    if (temporizador_1_ativado_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[215])));
      printButton(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Azul > Auto
    }
    else if (temporizador_1_ativado_temp2 == 2) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Verde > ON
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton_vermelho(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Rojo > OFF 
    }
  }
  else if(bitRead(temporizador,2) == true)
  {
    if (on2_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on2_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on2_hora_temp2, 27, 100);
    }

    if (on2_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on2_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on2_minuto_temp2, 95, 100);
    }

    if (off2_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off2_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off2_hora_temp2, 193, 100);
    }

    if (off2_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off2_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off2_minuto_temp2, 262, 100);
    } 
    if (temporizador_2_ativado_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[215])));
      printButton(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Azul > Auto
    }
    else if (temporizador_2_ativado_temp2 == 2) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Verde > ON
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton_vermelho(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Rojo > OFF 
    }
  }
  else  if(bitRead(temporizador,3) == true)
  {
    if (on3_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on3_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on3_hora_temp2, 27, 100);
    }

    if (on3_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on3_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on3_minuto_temp2, 95, 100);
    }

    if (off3_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off3_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off3_hora_temp2, 193, 100);
    }

    if (off3_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off3_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off3_minuto_temp2, 262, 100);
    } 
    if (temporizador_3_ativado_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[215])));
      printButton(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Azul > Auto
    }
    else if (temporizador_3_ativado_temp2 == 2) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Verde > ON
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton_vermelho(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Rojo > OFF 
    }
  }
  else if(bitRead(temporizador,4) == true)
  {
    if (on4_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on4_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on4_hora_temp2, 27, 100);
    }

    if (on4_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on4_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on4_minuto_temp2, 95, 100);
    }

    if (off4_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off4_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off4_hora_temp2, 193, 100);
    }

    if (off4_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off4_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off4_minuto_temp2, 262, 100);
    }
    if (temporizador_4_ativado_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[215])));
      printButton(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Azul > Auto
    }
    else if (temporizador_4_ativado_temp2 == 2) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Verde > ON
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton_vermelho(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Rojo > OFF 
    }
  } 
  if(bitRead(temporizador,5) == true)
  {
    if (on5_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on5_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on5_hora_temp2, 27, 100);
    }

    if (on5_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on5_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on5_minuto_temp2, 95, 100);
    }

    if (off5_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off5_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off5_hora_temp2, 193, 100);
    }

    if (off5_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off5_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off5_minuto_temp2, 262, 100);
    }  
    if (temporizador_5_ativado_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[215])));
      printButton(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Azul > Auto
    }
    else if (temporizador_5_ativado_temp2 == 2) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Verde > ON
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton_vermelho(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Rojo > OFF 
    }
  }
}

//--------------------------------------------- Configurar leds -------------------------------- tela =40
void config_leds(boolean refreshAll=false)
{
  
    if( refreshAll == true)
       {
        led_estado_temp = led_estado;
       }
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[202])));
  printHeader(buffer); // tabela_textos[2] = "CONFIGURAR LEDS"

//  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[4])));
//  printButton(buffer, tanD[0], tanD[1], tanD[2], tanD[3]); // 1º boton, 1ª columna (probar led) 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[7])));
  printButton(buffer, tesT[0], tesT[1], tesT[2], tesT[3]); // 2º boton, 1ª columna( camb fotoperiodo led) 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[159])));
  printButton(buffer, temC[0], temC[1], temC[2], temC[3]); // 3º boton, 1ª columna (luz nocturna)
   
  //  printButton("", ledW[0], ledW[1], ledW[2], ledW[3]); // 1º boton, 2ª columna
  //  printButton("", tpaA[0], tpaA[1], tpaA[2], tpaA[3]); // 2º boton, 2ª columna
  //  printButton("", dosA[0], dosA[1], dosA[2], dosA[3]); // 3º boton, 2ª columna
  //  printButton("", wavM[0], wavM[1], wavM[2], wavM[3]); // 4º boton, 2ª columna
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"
  
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));   
  printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // Guarda las modificaciones. // "SALVAR"
       
       
    if (led_estado_temp == 0) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[215])));
      printButton(buffer, modL[0], modL[1], modL[2], modL[3]); // Azul > Auto
    }
    else if (led_estado_temp == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, modL[0], modL[1], modL[2], modL[3]); // Verde > ON
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton_vermelho(buffer, modL[0], modL[1], modL[2], modL[3]); // Rojo > OFF 
    }
}

//------------------------------- Configuracion fotoperiodo de los leds -------------------------------- PANTALLA =44
void fotoperiodo(boolean refreshAll = false)
{
  if (refreshAll)
  {
 
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[254]))); // "CONFIG. FOTOPERIODO"
    printHeader(buffer);
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"  

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // VOLTAR

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[250])));
    printButton_verde(buffer, 8, 17, 142, 34); // "AMANECER"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[251])));
    printButton_vermelho(buffer, 173, 17, 312, 34); // "ANOCHECER"

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[253])));
    myGLCD.print(buffer, 15, 155); // "DURACION AMANECER Y ANOCHECER."

    printButton("+", 30, 45, 55, 70, true);    // Boton mas hora
    printButton("+", 100, 45, 125, 70, true);    // Boton mas minuto
    printButton("-", 30, 105, 55, 130, true); // Boton menos hora
    printButton("-", 100, 105, 125, 130, true); // Boton menos minuto

    printButton("+", 195, 45, 220, 70, true);    // Boton mas hora
    printButton("+", 265, 45, 290, 70, true);    // Boton mas minuto
    printButton("-", 195, 105, 220, 130, true); // Boton menos hora
    printButton("-", 265, 105, 290, 130, true); // Boton menos minuto


    printButton("-", 20, 175, 45, 200, true);    // Botão para cima
    printButton("+", 110, 175, 135, 200, true);    // Botão para cima
//    printButton("-", 185, 175, 210, 200, true);    // Botão para cima
//    printButton("+", 275, 175, 300, 200, true);    // Botão para cima    
  }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);          
    myGLCD.print(":",70, 83);
    myGLCD.print(":",236, 83);

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (led_on_hora_t < 10)
    {
      myGLCD.print("0",27, 80);           
      myGLCD.printNumI(led_on_hora_t, 44, 80);
    } 
    else 
    {
      myGLCD.printNumI(led_on_hora_t, 27, 80);
    }

    if (led_on_minuto_t < 10)
    {                            
      myGLCD.print("0", 98, 80);
      myGLCD.printNumI(led_on_minuto_t, 115, 80);
    } 
    else 
    {
      myGLCD.printNumI(led_on_minuto_t, 98, 80);
    }

    if (led_off_hora_t < 10)
    {
      myGLCD.print("0",193, 80);            
      myGLCD.printNumI(led_off_hora_t, 210, 80);
    } 
    else 
    {
      myGLCD.printNumI(led_off_hora_t, 193, 80);
    }

    if (led_off_minuto_t < 10)
    {
      myGLCD.print("0",262, 80); 
      myGLCD.printNumI(led_off_minuto_t, 279, 80);
    } 
    else 
    {
      myGLCD.printNumI(led_off_minuto_t, 262, 80);
    }

    if (amanecer_anochecer_t < 100)
    {
      myGLCD.print("   ", 60, 179);      
      myGLCD.printNumI(amanecer_anochecer_t, 68, 179);
    } 
    else 
    {
      myGLCD.printNumI(amanecer_anochecer_t, 60, 179);
    }
 
}


