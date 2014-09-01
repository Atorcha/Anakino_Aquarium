//-------------------------------------------Touch screen----------------------------
void processMyTouch()
{
  myTouch.read();
  int x, y;                  // Coordenadas del touch screen
  x=myTouch.getX();
  y=myTouch.getY();
  if ((x>=iniC[0]) && (x<=iniC[2]) && (y>=iniC[1]) && (y<=iniC[3]) && (dispScreen!=0))  // volta ao inicio
  {
    waitForIt(iniC[0], iniC[1], iniC[2], iniC[3]);
    if((dispScreen == 5) || (dispScreen == 28)) 
    {
      ReadFromEEPROM();
    }
    dispScreen=0;
    clearScreen();
    mainScreen(true);   
  } 
  else
  {
    switch (dispScreen) 
    {
    case 0:                       //Tela de inico
      dispScreen=1;
      clearScreen();
      menuScreen();
      break;
    case 1:     //------------------------------------Tela de menu------------------------------------------------- PANTALLA = 1
      if ((x>=tanD[0]) && (x<=tanD[2]))               //first column
      {
        if ((y>=tanD[1]) && (y<=tanD[3]))             //press clock
        {
          waitForIt(tanD[0], tanD[1], tanD[2], tanD[3]);
          dispScreen=2;
          clearScreen();
          setClock();
        }

        if ((y>=tesT[1]) && (y<=tesT[3]))              // Menu iluminacion
        {
          waitForIt(tesT[0], tesT[1], tesT[2], tesT[3]);
          dispScreen=40;
          clearScreen();
          config_leds();
        }  
        if ((y>=temC[1]) && (y<=temC[3]))               //control de temperatura agua o tapa
        {
        waitForIt(temC[0], temC[1], temC[2], temC[3]);
        dispScreen=3;
        clearScreen();
        seleccionartemperatura();        
        } 
      }
      if ((x>=ledW[0]) && (x<=ledW[2]))                 //second column
      {
        if  ((y>=ledW[1]) && (y<=ledW[3]))           //Timers
        {
          waitForIt(ledW[0], ledW[1], ledW[2], ledW[3]);
          dispScreen=38;
          clearScreen();
          TimerScreen();
        } 
        if  ((y>=dosA[1]) && (y<=dosA[3]))           // seleciona EEPROM
        {
          waitForIt(dosA[0], dosA[1], dosA[2], dosA[3]);
          dispScreen=6;
          clearScreen();
          menu_eeprom();
        } 
        if  ((y>=aFeed[1]) && (y<=aFeed[3]))             //selecciona comedero
         {
          waitForIt(aFeed[0], aFeed[1], aFeed[2], aFeed[3]);
          dispScreen=19;
          clearScreen();
          comederoScreen();
         } 
      }
      if ((y>=menU[1]) && (y<=menU[3]) && (x>=menU[0]) && (x<=menU[2]))
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]); // Vai para o menu 2
        dispScreen=37;
        clearScreen();
        menuScreen_2();
      }
      break;

    case 2:    // -------------------------------------Tela configuracao data e hora---------------------PANTALLA = 2

      if ((y>=houU[1]) && (y<=houU[3])) // Buttons: Time UP
      {
        if((x>=houU[0]) && (x<=houU[2]))
        {
          waitForIt(houU[0], houU[1], houU[2], houU[3]);

          t_temp.hour = (t_temp.hour+1) %24;
          if (t_temp.hour<10)
          {
            myGLCD.printNumI(0, 70, 48);
            myGLCD.printNumI(t_temp.hour, 86, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.hour, 70, 48);
          }   
        }
        else if ((x>=minU[0]) && (x<=minU[2]))
        {
          waitForIt(minU[0], minU[1], minU[2], minU[3]);
          t_temp.min = (t_temp.min +1) %60;
          if (t_temp.min<10)
          {
            myGLCD.printNumI(0, 160, 48);
            myGLCD.printNumI(t_temp.min, 176, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.min, 160, 48);
          }   
        }
        else if ((x>=segC[0]) && (x<=segC[2]))
        {
          waitForIt(segC[0], segC[1], segC[2], segC[3]);
          t_temp.sec = (t_temp.sec +1) %60;
          if (t_temp.sec==60)
            t_temp.sec=0;
          if (t_temp.sec<10)
          {
            myGLCD.printNumI(0, 250, 48);
            myGLCD.printNumI(t_temp.sec, 266, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.sec, 250, 48);
          }     
        }
      }
      else if ((y>=houD[1]) && (y<=houD[3])) // Buttons: Time DOWN
      {
        if ((x>=houD[0]) && (x<=houD[2]))
        {
          waitForIt(houD[0], houD[1], houD[2], houD[3]);
          t_temp.hour =(t_temp.hour + 23)% 24;
          if (t_temp.hour<10)
          {
            myGLCD.printNumI(0, 70, 48);
            myGLCD.printNumI(t_temp.hour, 86, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.hour, 70, 48);
          }            
        }
        else if ((x>=minD[0]) && (x<=minD[2]))
        {
          waitForIt(minD[0], minD[1], minD[2], minD[3]);
          t_temp.min =(t_temp.min +59) %60;
          if (t_temp.min<10)
          {
            myGLCD.printNumI(0, 160, 48);
            myGLCD.printNumI(t_temp.min, 176, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.min, 160, 48);
          } 
        }
        else if ((x>=segB[0]) && (x<=segB[2]))
        {
          waitForIt(segB[0], segB[1], segB[2], segB[3]); 
          t_temp.sec = (t_temp.sec +59) %60;
          if (t_temp.sec<10)
          {
            myGLCD.printNumI(0, 250, 48);
            myGLCD.printNumI(t_temp.sec, 266, 48);
          }
          else
          {
            myGLCD.printNumI(t_temp.sec, 250, 48);
          }
        }
      }

      if ((y>=dayU[1]) && (y<=dayU[3])) // Buttons: Date UP
      {
        if ((x>=dayU[0]) && (x<=dayU[2]))
        {
          waitForIt(dayU[0], dayU[1], dayU[2], dayU[3]);
          t_temp.date+=1;
          t_temp.date=validateDate(t_temp.date, t_temp.mon, t_temp.year);
          if (t_temp.date<10)
          {
            myGLCD.printNumI(0, 70, 132);
            myGLCD.printNumI(t_temp.date, 86, 132);
          }
          else
          {
            myGLCD.printNumI(t_temp.date, 70, 132);
          }
        }
        else if ((x>=monU[0]) && (x<=monU[2]))
        {
          waitForIt(monU[0], monU[1], monU[2], monU[3]);
          t_temp.mon =(t_temp.mon + 1) %13;
          if (t_temp.mon ==0)
          {
            t_temp.mon = 1;
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

          t_temp.date=validateDateForMonth(t_temp.date, t_temp.mon, t_temp.year);
        }
        else if ((x>=yeaU[0]) && (x<=yeaU[2]))   
        {
          waitForIt(yeaU[0], yeaU[1], yeaU[2], yeaU[3]);
          t_temp.year+=1;
          if (t_temp.year==2100)
            t_temp.year=2000;
          myGLCD.printNumI(t_temp.year, 230, 132);

          t_temp.date=validateDateForMonth(t_temp.date, t_temp.mon, t_temp.year);
        }
        t_temp.dow=calcDOW(t_temp.date, t_temp.mon, t_temp.year);
      }
      else if ((y>=dayD[1]) && (y<=dayD[3]))  // Buttons: Date DOWN
      {
        if ((x>=dayD[0]) && (x<=dayD[2]))
        {
          waitForIt(dayD[0], dayD[1], dayD[2], dayD[3]);
          t_temp.date-=1;
          t_temp.date=validateDate(t_temp.date, t_temp.mon, t_temp.year);
          if (t_temp.date<10)
          {
            myGLCD.printNumI(0, 70, 132);
            myGLCD.printNumI(t_temp.date, 86, 132);
          }
          else
          {
            myGLCD.printNumI(t_temp.date, 70, 132);
          }
        }
        else if ((x>=monD[0]) && (x<=monD[2]))   
        {
          waitForIt(monD[0], monD[1], monD[2], monD[3]);
          t_temp.mon =(t_temp.mon +12) %13;
          if (t_temp.mon ==0)
          {
            t_temp.mon = 12;
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
          t_temp.date=validateDateForMonth(t_temp.date, t_temp.mon, t_temp.year);
        }

        else if ((x>=yeaD[0]) && (x<=yeaD[2]))
        {
          waitForIt(yeaD[0], yeaD[1], yeaD[2], yeaD[3]);
          t_temp.year = (t_temp.year +2099) %2100;

          myGLCD.printNumI(t_temp.year, 230, 132);
          t_temp.date=validateDateForMonth(t_temp.date, t_temp.mon, t_temp.year);        
        }
        t_temp.dow=calcDOW(t_temp.date, t_temp.mon, t_temp.year);
      }
      if ((y>=prOK[1]) && (y<=prOK[3]) && (x>=prOK[0]) && (x<=prOK[2]))
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
        rtc.halt(true);
        rtc.setTime(t_temp.hour, t_temp.min, t_temp.sec); 
        rtc.setDate(t_temp.date, t_temp.mon, t_temp.year);
        rtc.setDOW(t_temp.dow);
        rtc.halt(false);
        dispScreen=0;
        clearScreen();
        mainScreen(true);
      }
      if ((y>=iniC[1]) && (y<=iniC[3]) && (x>=iniC[0]) && (x<=iniC[2]))
      {
        waitForIt(iniC[0], iniC[1], iniC[2], iniC[3]); //volta ao inicio
        dispScreen=0;
        clearScreen();
        mainScreen(true);
      }
      if ((y>=menU[1]) && (y<=menU[3]) && (x>=menU[0]) && (x<=menU[2]))
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]); //volta ao menu
        dispScreen=1;
        clearScreen();
        menuScreen();
      }     
      break;
      
      case 3:           //---------------------------------------pantalla SELECCION de temperaturas de acuario y pantalla----------------------------------PANTALLA = 3
      if ((x>=tanD[0]) && (x<=tanD[2]))               //first column
      {
        if ((y>=tanD[1]) && (y<=tanD[3]))             //presiona agua
        {
          waitForIt(tanD[0], tanD[1], tanD[2], tanD[3]);
          dispScreen=4;
          clearScreen();
        tempScreen(true); 
        }

        if ((y>=tesT[1]) && (y<=tesT[3]))              // presiona tapa
        {
          waitForIt(tesT[0], tesT[1], tesT[2], tesT[3]);
          dispScreen=5;
          clearScreen();
          temperaturatapa();
        }  
      } 
      if ((y>=menU[1]) && (y<=menU[3]) && (x>=menU[0]) && (x<=menU[2]))
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]); //volta ao menu
        dispScreen=1;
        clearScreen();
        menuScreen();
      }    
      
      break;

    case 4:             //---------------------------------------Tela controle de temperatura----------------------------------PANTALLA = 4
      if ((x>=prOK[0]) && (x<=prOK[2]) && (y>=prOK[1]) && (y<=prOK[3]))       //Funcao salvar
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]);
        setTempC = temp2beS;
        offTempC = temp2beO;
        alarmTempC = temp2beA;
        dispScreen=14;
        SaveTempToEEPROM();
        clearScreen();
        tempScreen(true);
      } 
      else
      {
        if ((x>=temM[0]) && (x<=temM[2]))                         // Primeira coluna
        {
          if ((y>=temM[1]) && (y<=temM[3]))                      //press temp minus
          {
            waitForIt(temM[0], temM[1], temM[2], temM[3]);
            temp2beS -= 0.1;
            if (temp2beS < 10) {
              temp2beS = 10; 
            }
            tempScreen();
          }
          if ((y>=offM[1]) && (y<=offM[3]))                       //press offset minus
          {
            waitForIt(offM[0], offM[1], offM[2], offM[3]);
            temp2beO -= 0.1;
            if (temp2beO <= 0.1) {
              temp2beO = 0.0; 
            }
            tempScreen();
          }          
          if ((y>=almM[1]) && (y<=almM[3]))                        //press alarm minus
          {
            waitForIt(almM[0], almM[1], almM[2], almM[3]);
            temp2beA -= 0.1;
            if (temp2beA < 0.1) {
              temp2beA = 0.0;  
            }
            tempScreen();
          }
        }
        if ((x>=temP[0]) && (x<=temP[2]))                             //Segunda coluna
        {
          if ((y>=temP[1]) && (y<=temP[3]))                      //press temp plus
          {
            waitForIt(temP[0], temP[1], temP[2], temP[3]);
            temp2beS += 0.1;
            if (temp2beS >= 40) {
              temp2beS = 40; 
            }
            tempScreen();
          }
          if ((y>=offP[1]) && (y<=offP[3]))                           //press offset plus
          {
            waitForIt(offP[0], offP[1], offP[2], offP[3]);
            temp2beO += 0.1;
            if (temp2beO >= 10) {
              temp2beO = 9.9; 
            }
            tempScreen();
          }
          if ((y>=almP[1]) && (y<=almP[3]))                           //press alarm plus
          {
            waitForIt(almP[0], almP[1], almP[2], almP[3]);
            temp2beA += 0.1;
            if (temp2beA >= 10) {
              temp2beA = 9.9;  
            }
            tempScreen();
          }
        }
        if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           // vuelta al menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=1;
          clearScreen();
          menuScreen();
        } 

      }
      break;
      
    case 5:  // ------------------------------------------------- configurar temperatura tapa --------------------- PANTALLA: 5
    
            if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           // vuelta al menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=1;
          clearScreen();
          menuScreen();
        } 
    
    break;
    
    case 6:  ///--------------------------------------------------Pantalla MENU EEPROM----------------------------- PAntalla 6
      if ((x>=tanD[0]) && (x<=tanD[2]))               //first column
      {
        if ((y>=tanD[1]) && (y<=tanD[3]))             //presiona borrar
        {
          waitForIt(tanD[0], tanD[1], tanD[2], tanD[3]);
          dispScreen=7;
          clearScreen();
        borrar_eeprom_screen(); 
        }

        if ((y>=tesT[1]) && (y<=tesT[3]))              // presiona grabar
        {
          waitForIt(tesT[0], tesT[1], tesT[2], tesT[3]);
          dispScreen=1;
          clearScreen();
          menuScreen();
        }  
      } 
      if ((y>=menU[1]) && (y<=menU[3]) && (x>=menU[0]) && (x<=menU[2]))
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]); //volta ao menu
        dispScreen=1;
        clearScreen();
        menuScreen();
      }  

        
    break;
    
    case 7:  //---------------------------Borrar eeprom--------
    
          if ((y>=iniC[1]) && (y<=iniC[3]) && (x>=iniC[0]) && (x<=iniC[2]))
      {
        waitForIt(iniC[0], iniC[1], iniC[2], iniC[3]); //volta ao inicio
        dispScreen=0;
        clearScreen();
        mainScreen(true);
      }    
      if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           /// vuelta al menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }   
  if ((x>=modL[0]-20) && (x<=modL[2]+20) && (y>=modL[1]) && (y<=modL[3]))           // Boton borrar
        {
          waitForIt(modL[0], modL[1], modL[2], modL[3]);
          borrar_eeprom();
          asm volatile ("  jmp 0"); 
        }
    
    break;
    
    
    case 16:             //---------------------------------------Pantalla en blanco---------------------------------
      if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           /// vuelta al menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      } 
      
      
      break;

      
 //--------------- AUTOMATIC FISH FEEDER PAGE -----------------------------------------------PANTALLA = 19
     case 19:    
     
             if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           // vuelta al menu 1
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=1;
          clearScreen();
          menuScreen(); 
        }
        
      if ((x>=5) && (x<=155) && (y>=20) && (y<=40))      //Si presiona comedero 1
        {
         waitForIt(5, 20, 155, 40);
         comedero=1;
         dispScreen=20;
         clearScreen();
         config_comedero(true);
        } else
      if ((x>=165) && (x<=315) && (y>=20) && (y<=40))    //Si presiona comedero 2
        {
         waitForIt(165, 20, 315, 40);
         comedero=2;
         dispScreen=20;
         clearScreen();
         config_comedero(true);
        } else
      if ((x>=5) && (x<=155) && (y>=168) && (y<=188))      //Si presiona comedero 3
        {
         waitForIt(5, 168, 155, 188);
         comedero=3;
         dispScreen=20;
         clearScreen();
         config_comedero(true);
        } else
      if ((x>=165) && (x<=315) && (y>=168) && (y<=188))    //Si presiona comedero 4
        {
         waitForIt(165, 168, 315, 188);
         comedero=4;
         dispScreen=20;
         clearScreen();
         config_comedero(true);
        } else
      if ((x>=85) && (x<=235) && (y>=94) && (y<=114))      //Presiona comer ahora!!
        {
         waitForIt(85, 94, 235, 114);
         myGLCD.setColor(0, 255, 0);
         myGLCD.fillRoundRect(85, 94, 235, 114);
         myGLCD.setColor(255, 255, 255);
         myGLCD.drawRoundRect(85, 94, 235, 114); 
         setFont(SMALL, 0, 0, 0, 0, 255, 0);
         myGLCD.print("Now Feeding", 118, 98); 
         SetRele(comederopin, HIGH);                   // Se activa rele comedero
         delay(5000);
         myGLCD.setColor(153, 0, 102);
         myGLCD.fillRoundRect(85, 94, 235, 114);
         myGLCD.setColor(255, 255, 255);
         myGLCD.drawRoundRect(85, 94, 235, 114); 
         setFont(SMALL, 255, 255, 255, 153, 0, 102);
         myGLCD.print("Feed Fish Now!", 106, 98);  
         SetRele(comederopin, LOW);
        } 
    break;

    case 20:     //------------ CONFIGURAR HORARIOS COMEDERO ------------
    
    
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // Vuelta al menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);   
        dispScreen=19;
        clearScreen();
        comederoScreen();
      }    
 
      if (comedero ==1)      
        {
        if ((x>=salV[0]) && x<=salV[2] && (y>=salV[1]) && (y<=salV[3]))
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Pulsacion grabar
          comedero1H = comedero1H_Temp;
          comedero1M = comedero1M_Temp;         
          comedero1 = comedero1_Temp;
          dispScreen=19;
          clearScreen();
          comederoScreen();
          salvar_comederos_EEPROM();        
          }
          
        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora sube 
        {
          waitForIt(21, 45, 65, 88);
          comedero1H_Temp += 1;
          if(comedero1H_Temp > 23)
          {
            comedero1H_Temp = 0;
          }
          config_comedero();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora baja
        {
          waitForIt(21, 135, 65, 178);
          comedero1H_Temp -= 1;
          if(comedero1H_Temp < 0)
          {
            comedero1H_Temp = 23;
          }
          config_comedero();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto sube 
        {
          waitForIt(89, 45, 133, 88);
          comedero1M_Temp += 1;
          if(comedero1M_Temp > 59)
          {
            comedero1M_Temp = 0;
          }
          config_comedero();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto baja
        {
          waitForIt(89, 135, 133, 178);
          comedero1M_Temp -= 1;
          if(comedero1M_Temp < 0)
          {
            comedero1M_Temp = 59;
          }
          config_comedero();
        }
 
         if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]) && (y<=domI[3]))           // Ativar / desativar comedero
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(comedero1_Temp == 0)
          {
            comedero1_Temp = 1;
          }
          else if(comedero1_Temp == 1)
          {
            comedero1_Temp = 0;
          }          
          config_comedero();
        }
      }
      if (comedero ==2)      
        {
        if ((x>=salV[0]) && x<=salV[2] && (y>=salV[1]) && (y<=salV[3]))
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Pulsacion grabar
          comedero2H = comedero2H_Temp;
          comedero2M = comedero2M_Temp;         
          comedero2 = comedero2_Temp;
          dispScreen=19;
          clearScreen();
          comederoScreen();
          // Grabar comedero EEPROM();
        }
        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora sube 
        {
          waitForIt(21, 45, 65, 88);
          comedero2H_Temp += 1;
          if(comedero2H_Temp > 23)
          {
            comedero2H_Temp = 0;
          }
          config_comedero();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora baja
        {
          waitForIt(21, 135, 65, 178);
          comedero2H_Temp -= 1;
          if(comedero2H_Temp < 0)
          {
            comedero2H_Temp = 23;
          }
          config_comedero();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto sube 
        {
          waitForIt(89, 45, 133, 88);
          comedero2M_Temp += 1;
          if(comedero2M_Temp > 59)
          {
            comedero2M_Temp = 0;
          }
          config_comedero();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto baja
        {
          waitForIt(89, 135, 133, 178);
          comedero2M_Temp -= 1;
          if(comedero2M_Temp < 0)
          {
            comedero2M_Temp = 59;
          }
          config_comedero();
        }
 
         if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]) && (y<=domI[3]))           // Ativar / desativar timer
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(comedero2_Temp == 0)
          {
            comedero2_Temp = 1;
          }
          else if(comedero2_Temp == 1)
          {
            comedero2_Temp = 0;
          }          
          config_comedero();
        }
      }
      if (comedero ==3)      
        {
        if ((x>=salV[0]) && x<=salV[2] && (y>=salV[1]) && (y<=salV[3]))
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Pulsacion grabar
          comedero3H = comedero3H_Temp;
          comedero3M = comedero3M_Temp;         
          comedero3 = comedero3_Temp;
          dispScreen=19;
          clearScreen();
          comederoScreen();
          // Grabar comedero EEPROM();
        }
        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora sube 
        {
          waitForIt(21, 45, 65, 88);
          comedero3H_Temp += 1;
          if(comedero3H_Temp > 23)
          {
            comedero3H_Temp = 0;
          }
          config_comedero();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora baja
        {
          waitForIt(21, 135, 65, 178);
          comedero3H_Temp -= 1;
          if(comedero3H_Temp < 0)
          {
            comedero3H_Temp = 23;
          }
          config_comedero();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto sube 
        {
          waitForIt(89, 45, 133, 88);
          comedero3M_Temp += 1;
          if(comedero3M_Temp > 59)
          {
            comedero3M_Temp = 0;
          }
          config_comedero();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto baja
        {
          waitForIt(89, 135, 133, 178);
          comedero3M_Temp -= 1;
          if(comedero3M_Temp < 0)
          {
            comedero3M_Temp = 59;
          }
          config_comedero();
        }
 
         if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]) && (y<=domI[3]))           // Ativar / desativar comedero
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(comedero3_Temp == 0)
          {
            comedero3_Temp = 1;
          }
          else if(comedero3_Temp == 1)
          {
            comedero3_Temp = 0;
          }          
          config_comedero();
        }
      }
      if (comedero ==4)      
        {
        if ((x>=salV[0]) && x<=salV[2] && (y>=salV[1]) && (y<=salV[3]))
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Pulsacion grabar
          comedero4H = comedero4H_Temp;
          comedero4M = comedero4M_Temp;         
          comedero4 = comedero4_Temp;
          dispScreen=19;
          clearScreen();
          comederoScreen();
          // Grabar comedero EEPROM();
        }
        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora ligar mais 
        {
          waitForIt(21, 45, 65, 88);
          comedero4H_Temp += 1;
          if(comedero4H_Temp > 23)
          {
            comedero4H_Temp = 0;
          }
          config_comedero();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora baja
        {
          waitForIt(21, 135, 65, 178);
          comedero4H_Temp -= 1;
          if(comedero4H_Temp < 0)
          {
            comedero4H_Temp = 23;
          }
          config_comedero();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto ligar mais 
        {
          waitForIt(89, 45, 133, 88);
          comedero4M_Temp += 1;
          if(comedero4M_Temp > 59)
          {
            comedero4M_Temp = 0;
          }
          config_comedero();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto baja
        {
          waitForIt(89, 135, 133, 178);
          comedero4M_Temp -= 1;
          if(comedero4M_Temp < 0)
          {
            comedero4M_Temp = 59;
          }
          config_comedero();
        }
 
         if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]) && (y<=domI[3]))           // Ativar / desativar comedero
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(comedero4_Temp == 0)
          {
            comedero4_Temp = 1;
          }
          else if(comedero4_Temp == 1)
          {
            comedero4_Temp = 0;
          }          
          config_comedero();
        }
      }      
    break;
      
      
    case 36: // -------------------------------- Luz noturna --------------------------------------------
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // volta a tela configurar leds
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=40;
        clearScreen();
        config_leds(); 
      }
      if ((x>=salV[0]) && (x<=salV[2]) && (y>=salV[1]) && (y<=salV[3]))       //Funcao salvar
      {
        waitForIt(salV[0], salV[1], salV[2], salV[3]);
        MaxI = tMaxI;
        MinI = tMinI;
        dispScreen=0;
        Salvar_luz_noturna_EEPROM();
        clearScreen();
        mainScreen(true);
      } 
      if ((x>=temM[0]) && (x<=temM[2]))                         // Primeira coluna
      {
        if ((y>=temM[1]) && (y<=temM[3]))                      //press densidade minus
        {
          waitForIt(temM[0], temM[1], temM[2], temM[3]);
          tMaxI -= 1;
          if (tMaxI < 0)
          {
            tMaxI = 255;
          }
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (128, 40, 180, 56);//Limpar texto
          luz_noturna();
        }

        if ((y>=almM[1]) && (y<=almM[3]))                        //press alarm minus
        {
          waitForIt(almM[0], almM[1], almM[2], almM[3]);
          tMinI -= 1;
          if (tMinI < 0)
          {
            tMinI = 255;
          }
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (128, 140, 180, 156);//Limpar texto
          luz_noturna();
        }
      }
      if ((x>=temP[0]) && (x<=temP[2]))                             //Segunda coluna
      {
        if ((y>=temP[1]) && (y<=temP[3]))                      //press densidade plus
        {
          waitForIt(temP[0], temP[1], temP[2], temP[3]);
          tMaxI += 1;
          if (tMaxI > 255)
          {
            tMaxI = 1;
          }
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (128, 40, 180, 56); //Limpar texto
          luz_noturna();
        }

        if ((y>=almP[1]) && (y<=almP[3]))                           //press alarm plus
        {
          waitForIt(almP[0], almP[1], almP[2], almP[3]);
          tMinI += 1;
          if (tMinI > 255)
          {
            tMinI = 1;
          }
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect (128, 140, 180, 156);//Limpar texto
          luz_noturna();
        }
      }
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu 1
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen();
      } 
      break;
      
      
    case 37: // -------------------------------- Menu 2 -------------------------------------------------------------- 
      if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           // Volta ao menu 1
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen();
      }
      break;
      
      
    case 38: // -------------------------------- Timers -------------------------------------------------------------- 
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // Volta ao menu 1
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen();
      }
      if ((x >= 7) && (x <= 56) && (y >= 22) && (y <= 238))           // Timer 1 
      {
        waitForIt(7, 22, 56, 238);
        temporizador = 0x0;
        bitWrite(temporizador,1,1);
        dispScreen=39;
        clearScreen();
        config_timer(true);
      }
      if ((x >= 71) && (x <= 120) && (y >= 22) && (y <= 238))           // Timer 2 
      {
        waitForIt(71, 22, 120, 238);
        temporizador = 0x0;
        bitWrite(temporizador,2,1);
        dispScreen=39;
        clearScreen();
        config_timer(true);
      }
      if ((x >= 135) && (x <= 184) && (y >= 22) && (y <= 238))           // Timer 3 
      {
        waitForIt(135, 22, 184, 238);
        temporizador = 0x0;
        bitWrite(temporizador,3,1);
        dispScreen=39;
        clearScreen();
        config_timer(true);
      }
      if ((x >= 199) && (x <= 248) && (y >= 22) && (y <= 238))           // Timer 4 
      {
        waitForIt(199, 22, 248, 238);
        temporizador = 0x0;
        bitWrite(temporizador,4,1);
        dispScreen=39;
        clearScreen();
        config_timer(true);
      } 
      if ((x >= 263) && (x <= 312) && (y >= 22) && (y <= 238))           // Timer 5 
      {
        waitForIt(263, 22, 312, 238);
        temporizador = 0x0;
        bitWrite(temporizador,5,1);
        dispScreen=39;
        clearScreen();
        config_timer(true);
      }       
      break;
    case 39:// -------------------------------- Configurar timers ------------------------------------------------------ 
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // Volta ao menu 2
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);   
        dispScreen=1;
        clearScreen();
        menuScreen();
      }
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // Selecionar timer
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=38;
        clearScreen();
        TimerScreen(); 
      } 
      if(bitRead(temporizador,1) == true)
      {
        if ((x>=salV[0]) && x<=salV[2] && (y>=salV[1]) && (y<=salV[3]))
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Função salvar
          on1_minuto = on1_minuto_temp2;
          on1_hora = on1_hora_temp2;
          off1_minuto = off1_minuto_temp2;
          off1_hora = off1_hora_temp2;
          temporizador_1_ativado = temporizador_1_ativado_temp2;
          dispScreen=38;
          clearScreen();
          TimerScreen();
          salvar_timers_EEPROM();
        }
        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora ligar mais 
        {
          waitForIt(21, 45, 65, 88);
          on1_hora_temp2 += 1;
          if(on1_hora_temp2 > 23)
          {
            on1_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora ligar menos
        {
          waitForIt(21, 135, 65, 178);
          on1_hora_temp2 -= 1;
          if(on1_hora_temp2 < 0)
          {
            on1_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto ligar mais 
        {
          waitForIt(89, 45, 133, 88);
          on1_minuto_temp2 += 1;
          if(on1_minuto_temp2 > 59)
          {
            on1_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto ligar menos
        {
          waitForIt(89, 135, 133, 178);
          on1_minuto_temp2 -= 1;
          if(on1_minuto_temp2 < 0)
          {
            on1_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x >= 187) && (x <= 231) && (y >= 45) && (y <= 88))           // Hora desligar mais 
        {
          waitForIt(187, 45, 231, 88);
          off1_hora_temp2 += 1;
          if(off1_hora_temp2 > 23)
          {
            off1_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 187) && (x <= 231) && (y >= 135) && (y <= 178))           // Hora desligar menos
        {
          waitForIt(187, 135, 231, 178);
          off1_hora_temp2 -= 1;
          if(off1_hora_temp2 < 0)
          {
            off1_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 255) && (x <= 299) && (y >= 45) && (y <= 88))           // Minuto desligar mais 
        {
          waitForIt(255, 45, 299, 88);
          off1_minuto_temp2 += 1;
          if(off1_minuto_temp2 > 59)
          {
            off1_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 255) && (x <= 299) && (y >= 135) && (y <= 178))           // Minuto desligar menos
        {
          waitForIt(255, 135, 299, 178);
          off1_minuto_temp2 -= 1;
          if(off1_minuto_temp2 < 0)
          {
            off1_minuto_temp2 = 59;
          }
          config_timer();
        }
 
         if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]) && (y<=domI[3]))           // Ativar / desativar timer
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(temporizador_1_ativado_temp2 == 0)
          {
            temporizador_1_ativado_temp2 = 1;
          }
          else if(temporizador_1_ativado_temp2 == 1)
          {
            temporizador_1_ativado_temp2 = 2;
          }
          else if (temporizador_1_ativado_temp2 == 2)
          {
            temporizador_1_ativado_temp2 = 0;
          }          
          config_timer();
        }
      }
        
      if(bitRead(temporizador,2) == true)
      {
        if ((x>=salV[0]) && x<=salV[2] && (y>=salV[1]) && (y<=salV[3]))
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Função salvar
          on2_minuto = on2_minuto_temp2;
          on2_hora = on2_hora_temp2;
          off2_minuto = off2_minuto_temp2;
          off2_hora = off2_hora_temp2;
          temporizador_2_ativado = temporizador_2_ativado_temp2;
          dispScreen=38;
          clearScreen();
          TimerScreen();
          salvar_timers_EEPROM();
        }

        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora ligar mais 
        {
          waitForIt(21, 45, 65, 88);
          on2_hora_temp2 += 1;
          if(on2_hora_temp2 > 23)
          {
            on2_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora ligar menos
        {
          waitForIt(21, 135, 65, 178);
          on2_hora_temp2 -= 1;
          if(on2_hora_temp2 < 0)
          {
            on2_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto ligar mais 
        {
          waitForIt(89, 45, 133, 88);
          on2_minuto_temp2 += 1;
          if(on2_minuto_temp2 > 59)
          {
            on2_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto ligar menos
        {
          waitForIt(89, 135, 133, 178);
          on2_minuto_temp2 -= 1;
          if(on2_minuto_temp2 < 0)
          {
            on2_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x >= 187) && (x <= 231) && (y >= 45) && (y <= 88))           // Hora desligar mais 
        {
          waitForIt(187, 45, 231, 88);
          off2_hora_temp2 += 1;
          if(off2_hora_temp2 > 23)
          {
            off2_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 187) && (x <= 231) && (y >= 135) && (y <= 178))           // Hora desligar menos
        {
          waitForIt(187, 135, 231, 178);
          off2_hora_temp2 -= 1;
          if(off2_hora_temp2 < 0)
          {
            off2_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 255) && (x <= 299) && (y >= 45) && (y <= 88))           // Minuto desligar mais 
        {
          waitForIt(255, 45, 299, 88);
          off2_minuto_temp2 += 1;
          if(off2_minuto_temp2 > 59)
          {
            off2_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 255) && (x <= 299) && (y >= 135) && (y <= 178))           // Minuto desligar menos
        {
          waitForIt(255, 135, 299, 178);
          off2_minuto_temp2 -= 1;
          if(off2_minuto_temp2 < 0)
          {
            off2_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]) && (y<=domI[3]))           // Ativar / desativar timer
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(temporizador_2_ativado_temp2 == 0)
          {
            temporizador_2_ativado_temp2 = 1;
          }
          else if(temporizador_2_ativado_temp2 == 1)
          {
            temporizador_2_ativado_temp2 = 2;
          }
          else if (temporizador_2_ativado_temp2 == 2)
          {
            temporizador_2_ativado_temp2 = 0;
          }          
          config_timer();
        }  
      }   
      if(bitRead(temporizador,3) == true)
      {
        if ((x>=salV[0]) && x<=salV[2] && (y>=salV[1]) && (y<=salV[3]))
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Função salvar          
          on3_minuto = on3_minuto_temp2;
          on3_hora = on3_hora_temp2;
          off3_minuto = off3_minuto_temp2;
          off3_hora = off3_hora_temp2;
          temporizador_3_ativado = temporizador_3_ativado_temp2;
          dispScreen=38;
          clearScreen();
          TimerScreen();
          salvar_timers_EEPROM();
        }

        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora ligar mais 
        {
          waitForIt(21, 45, 65, 88);
          on3_hora_temp2 += 1;
          if(on3_hora_temp2 > 23)
          {
            on3_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora ligar menos
        {
          waitForIt(21, 135, 65, 178);
          on3_hora_temp2 -= 1;
          if(on3_hora_temp2 < 0)
          {
            on3_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto ligar mais 
        {
          waitForIt(89, 45, 133, 88);
          on3_minuto_temp2 += 1;
          if(on3_minuto_temp2 > 59)
          {
            on3_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto ligar menos
        {
          waitForIt(89, 135, 133, 178);
          on3_minuto_temp2 -= 1;
          if(on3_minuto_temp2 < 0)
          {
            on3_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x >= 187) && (x <= 231) && (y >= 45) && (y <= 88))           // Hora desligar mais 
        {
          waitForIt(187, 45, 231, 88);
          off3_hora_temp2 += 1;
          if(off3_hora_temp2 > 23)
          {
            off3_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 187) && (x <= 231) && (y >= 135) && (y <= 178))           // Hora desligar menos
        {
          waitForIt(187, 135, 231, 178);
          off3_hora_temp2 -= 1;
          if(off3_hora_temp2 < 0)
          {
            off3_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 255) && (x <= 299) && (y >= 45) && (y <= 88))           // Minuto desligar mais 
        {
          waitForIt(255, 45, 299, 88);
          off3_minuto_temp2 += 1;
          if(off3_minuto_temp2 > 59)
          {
            off3_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 255) && (x <= 299) && (y >= 135) && (y <= 178))           // Minuto desligar menos
        {
          waitForIt(255, 135, 299, 178);
          off3_minuto_temp2 -= 1;
          if(off3_minuto_temp2 < 0)
          {
            off3_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]) && (y<=domI[3]))           // Ativar / desativar timer
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(temporizador_3_ativado_temp2 == 0)
          {
            temporizador_3_ativado_temp2 = 1;
          }
          else if(temporizador_3_ativado_temp2 == 1)
          {
            temporizador_3_ativado_temp2 = 2;
          }
          else if (temporizador_3_ativado_temp2 == 2)
          {
            temporizador_3_ativado_temp2 = 0;
          }          
          config_timer(); 
        }  
      }
      if(bitRead(temporizador,4) == true)
      {
        if ((x>=salV[0]) && x<=salV[2] && (y>=salV[1]) && (y<=salV[3]))
        {
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Função salvar
          on4_minuto = on4_minuto_temp2;
          on4_hora = on4_hora_temp2;
          off4_minuto = off4_minuto_temp2;
          off4_hora = off4_hora_temp2;
          temporizador_4_ativado = temporizador_4_ativado_temp2;
          dispScreen=38;
          clearScreen();
          TimerScreen();
          salvar_timers_EEPROM();
        }
        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora ligar mais 
        {
          waitForIt(21, 45, 65, 88);
          on4_hora_temp2 += 1;
          if(on4_hora_temp2 > 23)
          {
            on4_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora ligar menos
        {
          waitForIt(21, 135, 65, 178);
          on4_hora_temp2 -= 1;
          if(on4_hora_temp2 < 0)
          {
            on4_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto ligar mais 
        {
          waitForIt(89, 45, 133, 88);
          on4_minuto_temp2 += 1;
          if(on4_minuto_temp2 > 59)
          {
            on4_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto ligar menos
        {
          waitForIt(89, 135, 133, 178);
          on4_minuto_temp2 -= 1;
          if(on4_minuto_temp2 < 0)
          {
            on4_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x >= 187) && (x <= 231) && (y >= 45) && (y <= 88))           // Hora desligar mais 
        {
          waitForIt(187, 45, 231, 88);
          off4_hora_temp2 += 1;
          if(off4_hora_temp2 > 23)
          {
            off4_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 187) && (x <= 231) && (y >= 135) && (y <= 178))           // Hora desligar menos
        {
          waitForIt(187, 135, 231, 178);
          off4_hora_temp2 -= 1;
          if(off4_hora_temp2 < 0)
          {
            off4_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 255) && (x <= 299) && (y >= 45) && (y <= 88))           // Minuto desligar mais 
        {
          waitForIt(255, 45, 299, 88);
          off4_minuto_temp2 += 1;
          if(off4_minuto_temp2 > 59)
          {
            off4_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 255) && (x <= 299) && (y >= 135) && (y <= 178))           // Minuto desligar menos
        {
          waitForIt(255, 135, 299, 178);
          off4_minuto_temp2 -= 1;
          if(off4_minuto_temp2 < 0)
          {
            off4_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]) && (y<=domI[3]))           // Ativar / desativar timer
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(temporizador_4_ativado_temp2 == 0)
          {
            temporizador_4_ativado_temp2 = 1;
          }
          else if(temporizador_4_ativado_temp2 == 1)
          {
            temporizador_4_ativado_temp2 = 2;
          }
          else if (temporizador_4_ativado_temp2 == 2)
          {
            temporizador_4_ativado_temp2 = 0;
          }          
          config_timer();
        }  
      }
       if(bitRead(temporizador,5) == true)
      {
        if ((x>=salV[0]) && x<=salV[2] && (y>=salV[1]) && (y<=salV[3]))
        {        
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Função salvar
          on5_minuto = on5_minuto_temp2;
          on5_hora = on5_hora_temp2;
          off5_minuto = off5_minuto_temp2;
          off5_hora = off5_hora_temp2;
          temporizador_5_ativado = temporizador_5_ativado_temp2;
          dispScreen=38;
          clearScreen();
          TimerScreen();
          salvar_timers_EEPROM();
        }
        if ((x >= 21) && (x <= 65) && (y >= 45) && (y <= 88))           // Hora ligar mais 
        {
          waitForIt(21, 45, 65, 88);
          on5_hora_temp2 += 1;
          if(on5_hora_temp2 > 23)
          {
            on5_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 21) && (x <= 65) && (y >= 135) && (y <= 178))           // Hora ligar menos
        {
          waitForIt(21, 135, 65, 178);
          on5_hora_temp2 -= 1;
          if(on5_hora_temp2 < 0)
          {
            on5_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 89) && (x <= 133) && (y >= 45) && (y <= 88))           // Minuto ligar mais 
        {
          waitForIt(89, 45, 133, 88);
          on5_minuto_temp2 += 1;
          if(on5_minuto_temp2 > 59)
          {
            on5_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 89) && (x <= 133) && (y >= 135) && (y <= 178))           // Minuto ligar menos
        {
          waitForIt(89, 135, 133, 178);
          on5_minuto_temp2 -= 1;
          if(on5_minuto_temp2 < 0)
          {
            on5_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x >= 187) && (x <= 231) && (y >= 45) && (y <= 88))           // Hora desligar mais 
        {
          waitForIt(187, 45, 231, 88);
          off5_hora_temp2 += 1;
          if(off5_hora_temp2 > 23)
          {
            off5_hora_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 187) && (x <= 231) && (y >= 135) && (y <= 178))           // Hora desligar menos
        {
          waitForIt(187, 135, 231, 178);
          off5_hora_temp2 -= 1;
          if(off5_hora_temp2 < 0)
          {
            off5_hora_temp2 = 23;
          }
          config_timer();
        } 

        if ((x >= 255) && (x <= 299) && (y >= 45) && (y <= 88))           // Minuto desligar mais 
        {
          waitForIt(255, 45, 299, 88);
          off5_minuto_temp2 += 1;
          if(off5_minuto_temp2 > 59)
          {
            off5_minuto_temp2 = 0;
          }
          config_timer();
        } 
        if ((x >= 255) && (x <= 299) && (y >= 135) && (y <= 178))           // Minuto desligar menos
        {
          waitForIt(255, 135, 299, 178);
          off5_minuto_temp2 -= 1;
          if(off5_minuto_temp2 < 0)
          {
            off5_minuto_temp2 = 59;
          }
          config_timer();
        }
        if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]) && (y<=domI[3]))           // Ativar / desativar timer
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(temporizador_5_ativado_temp2 == 0)
          {
            temporizador_5_ativado_temp2 = 1;
          }
          else if(temporizador_5_ativado_temp2 == 1)
          {
            temporizador_5_ativado_temp2 = 2;
          }
          else if (temporizador_5_ativado_temp2 == 2)
          {
            temporizador_5_ativado_temp2 = 0;
          }          
          config_timer();
        }  
      }     
      
      break;
    case 40://---------------------------------------- Configurar leds ----------------------------
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // Vuelta al  menu 1
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);   
        dispScreen=1;
        clearScreen();
        menuScreen();
      }
      
        if ((x>=salV[0]) && x<=salV[2] && (y>=salV[1]) && (y<=salV[3]))
        {        
          waitForIt(salV[0], salV[1], salV[2], salV[3]); // Funcion salvar
          led_estado = led_estado_temp;
          dispScreen=40;
          clearScreen();
          config_leds();
          salvar_estado_EEPROM();
        }      

      if ((x>=tesT[0]) && x<=tesT[2] && (y>=tesT[1]) && (y<=tesT[3]))           // Configurar fotoperiodo
      {

      led_on_minuto_t =led_on_minuto; 
      led_on_hora_t = led_on_hora;
      led_off_minuto_t = led_off_minuto; 
      led_off_hora_t = led_off_hora;
      amanecer_anochecer_t = amanecer_anochecer; 
      waitForIt(tesT[0], tesT[1], tesT[2], tesT[3]);   
      dispScreen=44;
      clearScreen();
      fotoperiodo(true);
      
      }
      if ((x>=temC[0]) && x<=temC[2] && (y>=temC[1]) && (y<=temC[3]))           // Luz Noturna
      {
        waitForIt(temC[0], temC[1], temC[2], temC[3]);   
        dispScreen=36;
        clearScreen();
        luz_noturna(true);
      }
        if ((x>=modL[0]-20) && (x<=modL[2]+20) && (y>=modL[1]) && (y<=modL[3]))           // Modo iluminacion ON / OFF Automatico
        {
          waitForIt(modL[0], modL[1], modL[2], modL[3]);
          
          if(led_estado_temp == 0)
          {
            led_estado_temp = 1;
          }
          else if(led_estado_temp == 1)
          {
            led_estado_temp = 2;
          }
          else if (led_estado_temp == 2)
          {
            led_estado_temp = 0;
          }
        config_leds();         
        }    
      break;
      
    case 44://---------------------------------------- Potência pré-definida para os leds ----------------------------

        if ((x >= menU[0]) && (x <= menU[2]) && (y >= menU[1]) && (y <= menU[3]))         // vuelta al menu 1
        {
          //waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=1;
          clearScreen();
          menuScreen();

        }   
        else if ((x >= volT[0]) && (x <= volT[2]) && (y >= volT[1]) && (y <= volT[3]))     // volver a menu iluminacion
        {
          //waitForIt(volT[0], volT[1], volT[2], volT[3]);
          dispScreen=40;
          clearScreen();
          config_leds();

        }
        else if ((x >= salV[0]) && (x <= salV[2]) && (y >= salV[1]) && (y <= salV[3]))    // guardar y salir al menu iluminacion
        {
          //waitForIt(salV[0], salV[1], salV[2], salV[3]);
          dispScreen=40;
          clearScreen();
          config_leds();
          led_on_minuto = led_on_minuto_t; 
          led_on_hora = led_on_hora_t;
          led_off_minuto = led_off_minuto_t; 
          led_off_hora = led_off_hora_t;
          led_on_minuto = led_on_minuto_t; 
          led_on_hora = led_on_hora_t;
          led_off_minuto = led_off_minuto_t; 
          led_off_hora = led_off_hora_t;
          amanecer_anochecer = amanecer_anochecer_t;

       


        }        
        
        
        if ((x >= 30) && (x <= 55) && (y >= 45) && (y <= 70))           // Hora encendido mas 
        {
          waitForIt(30, 45, 55, 70);
          led_on_hora_t += 1;
          if(led_on_hora_t > 23)
          {
            led_on_hora_t = 0;
          }
          fotoperiodo();
        } 
        else if ((x >= 30) && (x <= 55) && (y >= 105) && (y <= 130))           // Hora encendido menos
        {
          waitForIt(30, 105, 55, 130);
          led_on_hora_t -= 1;
          if(led_on_hora_t > 200) // 0 - 1 = 255 pois, byte varia de  0 a 255. 
          {
            led_on_hora_t = 23;
          }
          fotoperiodo();
        } 

        else if ((x >= 100) && (x <= 125) && (y >= 45) && (y <= 70))           // Minuto ligar mais 
        {
          waitForIt(100, 45, 125, 70);
          led_on_minuto_t += 5;
          if(led_on_minuto_t > 59)
          {
            led_on_minuto_t = 0;
          }
          fotoperiodo();
        } 
        else if ((x >= 100) && (x <= 125) && (y >= 105) && (y <= 130))           // Minuto ligar menos
        {
          waitForIt(100, 105, 125, 130);
          led_on_minuto_t -= 5;
          if(led_on_minuto_t > 200) // 0 - 1 = 255 pois, byte varia de  0 a 255. 
          {
            led_on_minuto_t = 59;
          }
          fotoperiodo();
        }
        else if ((x >= 195) && (x <= 220) && (y >= 45) && (y <= 70))           // Hora mas 
        {
          waitForIt(195, 45, 220, 70);
          led_off_hora_t += 1;
          if(led_off_hora_t > 23)
          {
            led_off_hora_t = 0;
          }
          fotoperiodo();
        } 
        else if ((x >= 195) && (x <= 220) && (y >= 105) && (y <= 130))           // Hora menos
        {
          waitForIt(195, 105, 220, 130);
          led_off_hora_t -= 1;
          if(led_off_hora_t > 200) // 0 - 1 = 255 pois, byte varia de  0 a 255. 
          {
            led_off_hora_t = 23;
          }
          fotoperiodo();
        } 

        else if ((x >= 265) && (x <= 290) && (y >= 45) && (y <= 70))           // Minuto mas 
        {
          waitForIt(265, 45, 290, 70);
          led_off_minuto_t += 5;
          if(led_off_minuto_t > 59)
          {
            led_off_minuto_t = 0;
          }
          fotoperiodo();
        } 
        else if ((x >= 265) && (x <= 290) && (y >= 105) && (y <= 130))           // Minuto menos
        {
          waitForIt(265, 105, 290, 130);
          led_off_minuto_t -= 5;
          if(led_off_minuto_t > 200) // 0 - 1 = 255 pois, byte varia de  0 a 255. 
          {
            led_off_minuto_t = 59;
          }
          fotoperiodo();
        }
        else if ((x >= 110) && (x <= 135) && (y >= 175) && (y <= 200))           // Amanecer/anochecer mas 
        {
          waitForIt(265, 45, 290, 70);
          amanecer_anochecer_t += 5;
          if(amanecer_anochecer_t > 240)
          {
            amanecer_anochecer_t = 5;
          }
          fotoperiodo();
        } 
        else if ((x >= 20) && (x <= 45) && (y >= 175) && (y <= 200))           // Amanecer/anochecer menos
        {
          waitForIt(265, 105, 290, 130);
          amanecer_anochecer_t -= 5;
          if(amanecer_anochecer_t < 5)
          {
            amanecer_anochecer_t = 240;
          }
          fotoperiodo();
        }                   
      break; 

    }
  }
}


