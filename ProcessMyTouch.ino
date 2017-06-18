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
        if ((y>=temC[1]) && (y<=temC[3]))               //control de temperatura agua 
        {
        waitForIt(temC[0], temC[1], temC[2], temC[3]);
        dispScreen=4;
        clearScreen();
         tempScreen(true);         
        }
        if ((y>=graF[1]) && (y<=graF[3]))           // seleciona funcion PH Acuario
        {
          waitForIt(graF[0], graF[1], graF[2], graF[3]);
        dispScreen=18;
        clearScreen();
        config_phA_Screen(true); 
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
        if  ((y>=dosA[1]) && (y<=dosA[3]))           // seleciona PERISTALTICAS
        {
          waitForIt(dosA[0], dosA[1], dosA[2], dosA[3]);
          dispScreen=8;
          clearScreen();
          menu_dosadoras();
        } 
        if  ((y>=aFeed[1]) && (y<=aFeed[3]))             //selecciona comedero
         {
          waitForIt(aFeed[0], aFeed[1], aFeed[2], aFeed[3]);
          dispScreen=19;
          clearScreen();
          comederoScreen();
         }
        if  ((y>=relL[1]) && (y<=relL[3]))             //selecciona rellenado agua
         {
          waitForIt(relL[0], relL[1], relL[2], relL[3]);
          dispScreen=6;
          clearScreen();
          rellenador();
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
      
 /*     case 3:           //---------------------------------------pantalla SELECCION de temperaturas de acuario y pantalla----------------------------------PANTALLA = 3
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
*/
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
    
    case 6:             //---------------------------------------Pantalla en blanco- PARA MODIFICAR EL RELLENADOR--------------------------------
      if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           /// vuelta al menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen(); 
      }
         if ((x>=domI[0]-20) && (x<=domI[2]+20) && (y>=domI[1]) && (y<=domI[3]))           // Activar / desactivar rellenador
        {
          waitForIt(domI[0]-20, domI[1], domI[2]+20, domI[3]);
          if(rellenador_activo == true)
          {
            rellenador_activo = false;
          }
          else if(rellenador_activo == false)
          {
            rellenador_activo = true;
          }
          
          rellenador();
        }      
      break;
      
    case 8: //--------------------------------------------- Escolher dosadora -----------------------------------
      if ((x>=manU[0]) && (x<=manU[2]) && (y>=manU[1]) && (y<=manU[3]))
      {
        waitForIt(manU[0], manU[1], manU[2], manU[3]);
        modo_manual = true;
        modo_personalizado = false;
        modo_calibrar = false;
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);

        strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[164])));
        myGLCD.print(buffer, 15, 220); // "MODO MANUAL SELECIONADO"
      }
      if ((x>=perS[0]) && (x<=perS[2]) && (y>=perS[1]) && (y<=perS[3]))
      {
        waitForIt(perS[0], perS[1], perS[2], perS[3]);
        modo_manual = false;
        modo_personalizado = true;
        modo_calibrar = false;
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);

        strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171])));
        myGLCD.print(buffer, 15, 220);      
      }
      if ((x>=orP[0]) && (x<=orP[2]) && (y>=orP[1]) && (y<=orP[3]))
      {
        waitForIt(orP[0], orP[1], orP[2], orP[3]);
        modo_manual = false;
        modo_personalizado = false;
        modo_calibrar = true;
        dispScreen=21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);

        strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[172])));
        myGLCD.print(buffer, 15, 220);      
      }    
      if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           /// volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen=1;
        clearScreen();
        menuScreen();
        modo_manual = false;
        modo_personalizado = false;
        modo_calibrar = false; 
      }          
      if ((x>=reV[0]) && (x<=reV[2]) && (y>=reV[1]) && (y<=reV[3]))           /// Rever config
      {
        waitForIt(reV[0], reV[1], reV[2], reV[3]);
        dispScreen=32;
        clearScreen();
        rever_configuracao_dosadoras();
      }
      if ((x>=atiV[0]) && (x<=atiV[2]) && (y>=atiV[1]) && (y<=atiV[3]))
      {
        waitForIt(atiV[0], atiV[1], atiV[2], atiV[3]);
        dispScreen = 35;
        clearScreen();
        desativar_dosadoras(true);
      }
      break; 

    case 18: //--------------------------Tela configuracao de ph do aquario-----------------------------------
      if ((x>=prOK[0]) && (x<=prOK[2]) && (y>=prOK[1]) && (y<=prOK[3]))       //Funcao salvar
      {
        waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]);
        setPHA = PHA2beS;
        offPHA = PHA2beO;
        alarmPHA = PHA2beA;
        dispScreen=1;
        SavePHAToEEPROM();
        clearScreen();
        menuScreen(); 
      } 
      else
      {
        if ((x>=temM[0]) && (x<=temM[2]))                         // Primeira coluna
        {
          if ((y>=temM[1]) && (y<=temM[3]))                      //press ph minus
          {
            waitForIt(temM[0], temM[1], temM[2], temM[3]);
            PHA2beS -= 0.1;
            if (PHA2beS <0.1)
            {
              PHA2beS = 0.0;
            }
            config_phA_Screen();
          }
          if ((y>=offM[1]) && (y<=offM[3]))                       //press offset minus
          {
            waitForIt(offM[0], offM[1], offM[2], offM[3]);
            PHA2beO -= 0.1;
            if (PHA2beO < 0.1) {
              PHA2beO = 0.0; 
            }
            config_phA_Screen();
          }          
          if ((y>=almM[1]) && (y<=almM[3]))                        //press alarm minus
          {
            waitForIt(almM[0], almM[1], almM[2], almM[3]);
            PHA2beA -= 0.1;
            if (PHA2beA < 0.1) {
              PHA2beA = 0.0;  
            }
            config_phA_Screen();
          }
        }
        if ((x>=temP[0]) && (x<=temP[2]))                             //Segunda coluna
        {
          if ((y>=temP[1]) && (y<=temP[3]))                      //press temp plus
          {
            waitForIt(temP[0], temP[1], temP[2], temP[3]);
            PHA2beS += 0.1;
            if (PHA2beS > 9.9)
            {
              PHA2beS = 9.9;
            }            
            config_phA_Screen();
          }
          if ((y>=offP[1]) && (y<=offP[3]))                           //press offset plus
          {
            waitForIt(offP[0], offP[1], offP[2], offP[3]);
            PHA2beO += 0.1;
            if (PHA2beO > 9.9)
            {
              PHA2beO = 9.9;
            }
            config_phA_Screen();
          }
          if ((y>=almP[1]) && (y<=almP[3]))                           //press alarm plus
          {
            waitForIt(almP[0], almP[1], almP[2], almP[3]);
            PHA2beA += 0.1;
            if (PHA2beA > 9.9)
            {
              PHA2beA = 9.9;
            }
            config_phA_Screen();
          }
        }
        if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
        {
          waitForIt(menU[0], menU[1], menU[2], menU[3]);
          dispScreen=1;
          clearScreen();
          menuScreen(); 
        } 

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
         activacomedero();                   // Se activa el comedero
         delay(5000);
         myGLCD.setColor(153, 0, 102);
         myGLCD.fillRoundRect(85, 94, 235, 114);
         myGLCD.setColor(255, 255, 255);
         myGLCD.drawRoundRect(85, 94, 235, 114); 
         setFont(SMALL, 255, 255, 255, 153, 0, 102);
         myGLCD.print("Feed Fish Now!", 106, 98);  
         activacomedero();
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
      
     
    case 21: // ------------------------------------------------ Escolher dosadora -----------------------------------

      if ((x>=dosa1[0]) && (x<=dosa1[2]) && (y>=dosa1[1]) && (y<=dosa1[3]))         
      {
        waitForIt(dosa1[0], dosa1[1], dosa1[2], dosa1[3]);
        if (modo_manual == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,1,1);

          dispScreen = 27;
          clearScreen();
          config_dosagem_manual(true);
        }     
        if (modo_personalizado == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,1,1);         
          dispScreen = 29;
          clearScreen();
          config_dosagem_personalizada(true);
        }

        if (modo_calibrar == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,1,1);
          dispScreen = 26;
          clearScreen();
          calibrar_dosadoras(true);
        }      
      }
      if ((x>=dosa2[0]) && (x<=dosa2[2]) && (y>=dosa2[1]) && (y<=dosa2[3]))         
      {
        waitForIt(dosa2[0], dosa2[1], dosa2[2], dosa2[3]);
        if (modo_manual == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,2,1);
          dispScreen = 27;
          clearScreen();
          config_dosagem_manual(true);
        }   
        if (modo_personalizado == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,2,1);
          dispScreen = 29;
          clearScreen();
          config_dosagem_personalizada(true);
        }

        if (modo_calibrar == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,2,1);
          dispScreen = 26;
          clearScreen();
          calibrar_dosadoras(true);
        } 
      }
      if ((x>=dosa3[0]) && (x<=dosa3[2]) && (y>=dosa3[1]) && (y<=dosa3[3]))         
      {
        waitForIt(dosa3[0], dosa3[1], dosa3[2], dosa3[3]);
        if (modo_manual == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,3,1);
          dispScreen = 27;
          clearScreen();
          config_dosagem_manual(true);
        }     
        if (modo_personalizado == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,3,1);
          dispScreen = 29;
          clearScreen();
          config_dosagem_personalizada(true);
        }

        if (modo_calibrar == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,3,1);
          dispScreen = 26;
          clearScreen();
          calibrar_dosadoras(true);
        }  
      }        
      if ((x>=dosa4[0]) && x<=dosa4[2] && (y>=dosa4[1]) && (y<=dosa4[3]))         
      {
        waitForIt(dosa4[0], dosa4[1], dosa4[2], dosa4[3]);
        if (modo_manual == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,4,1);       
          dispScreen = 27;
          clearScreen();
          config_dosagem_manual(true);
        }
        if (modo_personalizado == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,4,1);
          dispScreen = 29;
          clearScreen();
          config_dosagem_personalizada(true);
        }

        if (modo_calibrar == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,4,1);
          dispScreen = 26;
          clearScreen();
          calibrar_dosadoras(true);
        }      
      }
      if ((x>=dosa5[0]) && x<=dosa5[2] && (y>=dosa5[1]) && (y<=dosa5[3]))         
      {
        waitForIt(dosa5[0], dosa5[1], dosa5[2], dosa5[3]);
        if (modo_manual == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,5,1);
          dispScreen = 27;
          clearScreen();
          config_dosagem_manual(true);
        }     
        if (modo_personalizado == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,5,1);
          dispScreen = 29;
          clearScreen();
          config_dosagem_personalizada(true);
        }

        if (modo_calibrar == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,5,1);
          dispScreen = 26;
          clearScreen();
          calibrar_dosadoras(true);
        } 
      }
      if ((x>=dosa6[0]) && x<=dosa6[2] && (y>=dosa6[1]) && (y<=dosa6[3]))         
      {
        waitForIt(dosa6[0], dosa6[1], dosa6[2], dosa6[3]);
        if (modo_manual == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,6,1);
          dispScreen = 27;
          clearScreen();
          config_dosagem_manual(true);
        }
        if (modo_personalizado == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,6,1);
          dispScreen = 29;
          clearScreen();
          config_dosagem_personalizada(true);
        }

        if (modo_calibrar == true)
        {
          dosadora_selecionada = 0x0;
          bitWrite(dosadora_selecionada,6,1);
          dispScreen = 26;
          clearScreen();
          calibrar_dosadoras(true);
        }  
      }
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // volta a tela de escolha da dosadora
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 8;
        clearScreen();
        menu_dosadoras();
      }
      break;
    case 23:// -------------------------------- Rever configuração das dosadoras modo personalizado ------------------------------------------
      if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]) && (x<=volT[2]) && (y>=volT[1]) && (y<=volT[3]))           // volta ao menu de revisão das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=34;
        clearScreen();
        rever_dosagem_personalizada();
      }
      break;
    case 24:// -------------------------------------- Desativar dosadoras ------------------------------------------
      if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen();    
      }
      if ((x>=volT[0]) && (x<=volT[2]) && (y>=volT[1]) && (y<=volT[3]))           // volta ao menu desativar dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 35;
        clearScreen();
        desativar_dosadoras(true);
      }
      if ((x >= 100) && (x <= 220) && (y >= 45) && (y <= 85))           //Ativar/desativar dosadora 4
      {
        waitForIt(100, 45, 220, 85);

        if(bitRead(ativar_desativar,4) == true)
        {
          bitWrite(ativar_desativar,4 ,0);
          desativar_dosadoras_2();
        }
        else
        {
          desativar_dosadoras_2(true);
        }          
      }
      if ((x >= 100) && (x <= 220) && (y >= 115) && (y <= 155))           //Ativar/desatiavr dosadora 5
      {
        waitForIt(100, 115, 220, 155);

        if(bitRead(ativar_desativar,5) == true)
        {
          bitWrite(ativar_desativar,5 ,0);
          desativar_dosadoras_2();
        }
        else
        {
          desativar_dosadoras_2(true);
        }          
      }
      if ((x >= 100) && (x <= 220) && (y >= 185) && (y <= 225))           //Ativar/desatiavr dosadora 6
      {
        waitForIt(100, 185, 220, 225);

        if(bitRead(ativar_desativar,6) == true)
        {
          bitWrite(ativar_desativar,6 ,0);
          desativar_dosadoras_2();
        }
        else
        {
          desativar_dosadoras_2(true);
        }          
      }
      if ((x>=salV[0]) && (x<=salV[2]) && (y>=salV[1]) && (y<=salV[3]))           //Salvar alterações
      {
        waitForIt(salV[0], salV[1], salV[2], salV[3]);
        if(bitRead(ativar_desativar,4) == false)
        {
          bitWrite(modo_personalizado_on,4, 0);
        }
        if(bitRead(ativar_desativar,5) == false)
        {
          bitWrite(modo_personalizado_on,5, 0);
        }
        if(bitRead(ativar_desativar,6) == false)
        {
          bitWrite(modo_personalizado_on,6, 0);
        }
        Salvar_dosadora_EEPROM(); 
        dispScreen = 0;
        clearScreen();
        mainScreen(true);       
      }
      break;
      
    case 26: //------------------------------------ calibrar dosadoras -------------------------------------------
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (bitRead(dosadora_selecionada,1) == true))            //fator calibracao mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        fator_calib_dosadora_1_temp2 += 0.1;
        if (fator_calib_dosadora_1_temp2 > 99.9)
        {
          fator_calib_dosadora_1_temp2 = 0.0;
        }
        calibrar_dosadoras();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (bitRead(dosadora_selecionada,1) == true))            //fator calibracao menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        fator_calib_dosadora_1_temp2 -= 0.1;
        if (fator_calib_dosadora_1_temp2 < 0.1)
        {
          fator_calib_dosadora_1_temp2 = 99.9;
        }
        calibrar_dosadoras();
      }
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (bitRead(dosadora_selecionada,2) == true))            //fator calibracao mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        fator_calib_dosadora_2_temp2 += 0.1;
        if (fator_calib_dosadora_2_temp2 > 99.9)
        {
          fator_calib_dosadora_2_temp2 = 0.0;
        }
        calibrar_dosadoras();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (bitRead(dosadora_selecionada,2) == true))            //fator calibracao menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        fator_calib_dosadora_2_temp2 -= 0.1;
        if (fator_calib_dosadora_2_temp2 < 0.1)
        {
          fator_calib_dosadora_2_temp2 = 99.9;
        }
        calibrar_dosadoras();
      }          
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (bitRead(dosadora_selecionada,3) == true))            //fator calibracao mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        fator_calib_dosadora_3_temp2 += 0.1;
        if (fator_calib_dosadora_3_temp2 > 99.9)
        {
          fator_calib_dosadora_3_temp2 = 0.0;
        }
        calibrar_dosadoras();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (bitRead(dosadora_selecionada,3) == true))            //fator calibracao menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        fator_calib_dosadora_3_temp2 -= 0.1;
        if (fator_calib_dosadora_3_temp2 < 0.1)
        {
          fator_calib_dosadora_3_temp2 = 99.9;
        }
        calibrar_dosadoras();
      }    
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (bitRead(dosadora_selecionada,4) == true))            //fator calibracao mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        fator_calib_dosadora_4_temp2 += 0.1;
        if (fator_calib_dosadora_4_temp2 > 99.9)
        {
          fator_calib_dosadora_4_temp2 = 0.0;
        }
        calibrar_dosadoras();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (bitRead(dosadora_selecionada,4) == true))            //fator calibracao menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        fator_calib_dosadora_4_temp2 -= 0.1;
        if (fator_calib_dosadora_4_temp2 < 0.1)
        {
          fator_calib_dosadora_4_temp2 = 99.9;
        }
        calibrar_dosadoras();
      }
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (bitRead(dosadora_selecionada,5) == true))            //fator calibracao mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        fator_calib_dosadora_5_temp2 += 0.1;
        if (fator_calib_dosadora_5_temp2 > 99.9)
        {
          fator_calib_dosadora_5_temp2 = 0.0;
        }
        calibrar_dosadoras();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (bitRead(dosadora_selecionada,5) == true))            //fator calibracao menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        fator_calib_dosadora_5_temp2 -= 0.1;
        if (fator_calib_dosadora_5_temp2 < 0.1)
        {
          fator_calib_dosadora_5_temp2 = 99.9;
        }
        calibrar_dosadoras();
      }          
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (bitRead(dosadora_selecionada,6) == true))            //fator calibracao mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        fator_calib_dosadora_6_temp2 += 0.1;
        if (fator_calib_dosadora_6_temp2 > 99.9)
        {
          fator_calib_dosadora_6_temp2 = 0.0;
        }
        calibrar_dosadoras();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (bitRead(dosadora_selecionada,6) == true))            //fator calibracao menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        fator_calib_dosadora_6_temp2 -= 0.1;
        if (fator_calib_dosadora_6_temp2 < 0.1)
        {
          fator_calib_dosadora_6_temp2 = 99.9;
        }
        calibrar_dosadoras();
      }
      if ((x>=salV[0]) && x<=salV[2] && (y>=salV[1]) && (y<=salV[3]))
      {
        waitForIt(salV[0], salV[1], salV[2], salV[3]); // Função salvar
        if(bitRead(dosadora_selecionada,1) == true)
        {
          fator_calib_dosadora_1 = fator_calib_dosadora_1_temp2;
          Salvar_dosadora_EEPROM();
          dispScreen = 21;
          clearScreen();
          selecionar_dosadora();
          setFont(SMALL, 255, 255, 255, 0, 0, 0);

          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[172])));
          myGLCD.print(buffer, 15, 220);

          modo_manual = false;
          modo_personalizado = false;
          modo_calibrar = true;
          dosadora_selecionada = 0x0;
        }        
        if(bitRead(dosadora_selecionada,2) == true)
        {
          fator_calib_dosadora_2 = fator_calib_dosadora_2_temp2;
          Salvar_dosadora_EEPROM();
          dispScreen = 21;
          clearScreen();
          selecionar_dosadora();
          setFont(SMALL, 255, 255, 255, 0, 0, 0);

          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[172])));
          myGLCD.print(buffer, 15, 220);

          modo_manual = false;
          modo_personalizado = false;
          modo_calibrar = true;
          dosadora_selecionada = 0x0;
        }
        if(bitRead(dosadora_selecionada,3) == true)
        {
          fator_calib_dosadora_3 = fator_calib_dosadora_3_temp2;
          Salvar_dosadora_EEPROM();
          dispScreen = 21;
          clearScreen();
          selecionar_dosadora();
          setFont(SMALL, 255, 255, 255, 0, 0, 0);

          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[172])));
          myGLCD.print(buffer, 15, 220);

          modo_manual = false;
          modo_personalizado = false;
          modo_calibrar = true;
          dosadora_selecionada = 0x0;
        }
        if(bitRead(dosadora_selecionada,4) == true)
        {
          fator_calib_dosadora_4 = fator_calib_dosadora_4_temp2;
          Salvar_dosadora_EEPROM();
          dispScreen = 21;
          clearScreen();
          selecionar_dosadora();
          setFont(SMALL, 255, 255, 255, 0, 0, 0);

          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[172])));
          myGLCD.print(buffer, 15, 220);

          modo_manual = false;
          modo_personalizado = false;
          modo_calibrar = true;
          dosadora_selecionada = 0x0;
        }        
        if(bitRead(dosadora_selecionada,5) == true)
        {
          fator_calib_dosadora_5 = fator_calib_dosadora_5_temp2;
          Salvar_dosadora_EEPROM();
          dispScreen = 21;
          clearScreen();
          selecionar_dosadora();
          setFont(SMALL, 255, 255, 255, 0, 0, 0);

          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[172])));
          myGLCD.print(buffer, 15, 220);

          modo_manual = false;
          modo_personalizado = false;
          modo_calibrar = true;
          dosadora_selecionada = 0x0;
        }
        if(bitRead(dosadora_selecionada,6) == true)
        {
          fator_calib_dosadora_6 = fator_calib_dosadora_6_temp2;
          Salvar_dosadora_EEPROM();
          dispScreen = 21;
          clearScreen();
          selecionar_dosadora();
          setFont(SMALL, 255, 255, 255, 0, 0, 0);

          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[172])));
          myGLCD.print(buffer, 15, 220);

          modo_manual = false;
          modo_personalizado = false;
          modo_calibrar = true;
          dosadora_selecionada = 0x0;
        }
      }      
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // Volta a tela altera configuracao das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);

        strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[172])));
        myGLCD.print(buffer, 15, 220);

        modo_manual = false;
        modo_personalizado = false;
        modo_calibrar = true;
        dosadora_selecionada = 0x0;
      }
      if ((x>=iniciaR[0]) && (x<=iniciaR[2]) && (y>=iniciaR[1]) && (y<=iniciaR[3]))
      {
        waitForIt(iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        if((modo_calibrar == true) && (bitRead(dosadora_selecionada,1) == true))
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
          printButton_verde(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);

          delay(10000);
          digitalWrite(dosadora1, HIGH);
          delay(60000);
          digitalWrite(dosadora1, LOW);

          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
          printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        }
        if((modo_calibrar == true) && (bitRead(dosadora_selecionada,2) == true))
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
          printButton_verde(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          delay(10000);
          digitalWrite(dosadora2, HIGH);
          delay(60000);
          digitalWrite(dosadora2, LOW);

          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
          printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        }
        if((modo_calibrar == true) && (bitRead(dosadora_selecionada,3) == true))
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
          printButton_verde(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          delay(10000);
          digitalWrite(dosadora3, HIGH);
          delay(60000);
          digitalWrite(dosadora3, LOW);

          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
          printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        }
        if((modo_calibrar == true) && (bitRead(dosadora_selecionada,4) == true))
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
          printButton_verde(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);

          delay(10000);
          digitalWrite(dosadora4, HIGH);
          delay(60000);
          digitalWrite(dosadora4, LOW);

          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
          printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        }
        if((modo_calibrar == true) && (bitRead(dosadora_selecionada,5) == true))
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
          printButton_verde(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          delay(10000);
          digitalWrite(dosadora5, HIGH);
          delay(60000);
          digitalWrite(dosadora5, LOW);

          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
          printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        }
        if((modo_calibrar == true) && (bitRead(dosadora_selecionada,6) == true))
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
          printButton_verde(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          delay(10000);
          digitalWrite(dosadora6, HIGH);
          delay(60000);
          digitalWrite(dosadora6, LOW);

          strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
          printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        }
      }      
      break;
    case 27:   // ----------------------------------------- Config dosagem manual --------------------------------------
      if ((x>=almP[0]) && (x<=almP[2]) && (y>=almP[1]) && (y<=almP[3]) && (bitRead(dosadora_selecionada,1) == true))            //dose manual mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        dose_dosadora_1_manual += 0.5;
        if (dose_dosadora_1_manual > 99.5)
        {
          dose_dosadora_1_manual = 0.0;
        }
        config_dosagem_manual();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (bitRead(dosadora_selecionada,1) == true))            //dose manual menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        dose_dosadora_1_manual -= 0.5;
        if (dose_dosadora_1_manual < 0.5)
        {
          dose_dosadora_1_manual = 99.5;
        }
        config_dosagem_manual();
      }
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (bitRead(dosadora_selecionada,2) == true))            //dose manual mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        dose_dosadora_2_manual += 0.5;
        if (dose_dosadora_2_manual > 99.5)
        {
          dose_dosadora_2_manual = 0.0;
        }
        config_dosagem_manual();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (bitRead(dosadora_selecionada,2) == true))            //dose manual menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        dose_dosadora_2_manual -= 0.5;
        if (dose_dosadora_2_manual < 0.5)
        {
          dose_dosadora_2_manual = 99.5;
        }
        config_dosagem_manual();
      }          
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (bitRead(dosadora_selecionada,3) == true))            //dose manual mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        dose_dosadora_3_manual += 0.5;
        if (dose_dosadora_3_manual > 99.5)
        {
          dose_dosadora_3_manual = 0.5;
        }
        config_dosagem_manual();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (bitRead(dosadora_selecionada,3) == true))            //dose manual menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        dose_dosadora_3_manual -= 0.5;
        if (dose_dosadora_3_manual < 0.5)
        {
          dose_dosadora_3_manual = 99.5;
        }
        config_dosagem_manual();
      }    
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (bitRead(dosadora_selecionada,4) == true))            //dose manual mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        dose_dosadora_4_manual += 0.5;
        if (dose_dosadora_4_manual > 99.5)
        {
          dose_dosadora_4_manual = 0.0;
        }
        config_dosagem_manual();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (bitRead(dosadora_selecionada,4) == true))            //dose manual menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        dose_dosadora_4_manual -= 0.5;
        if (dose_dosadora_4_manual < 0.5)
        {
          dose_dosadora_4_manual = 99.5;
        }
        config_dosagem_manual();
      }
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (bitRead(dosadora_selecionada,5) == true))            //dose manual mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        dose_dosadora_5_manual += 0.5;
        if (dose_dosadora_5_manual > 99.5)
        {
          dose_dosadora_5_manual = 0.0;
        }
        config_dosagem_manual();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (bitRead(dosadora_selecionada,5) == true))            //dose manual menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        dose_dosadora_5_manual -= 0.5;
        if (dose_dosadora_5_manual < 0.5)
        {
          dose_dosadora_5_manual = 99.5;
        }
        config_dosagem_manual();
      }          
      if ((x>=almP[0]) && x<=almP[2] && (y>=almP[1]) && (y<=almP[3]) && (bitRead(dosadora_selecionada,6) == true))            //dose manual mais.
      {
        waitForIt(almP[0], almP[1], almP[2], almP[3]);
        dose_dosadora_6_manual += 0.5;
        if (dose_dosadora_6_manual > 99.5)
        {
          dose_dosadora_6_manual = 0.5;
        }
        config_dosagem_manual();
      }
      if ((x>=almM[0]) && x<=almM[2] && (y>=almM[1]) && (y<=almM[3]) && (bitRead(dosadora_selecionada,6) == true))            //dose manual menos.
      {
        waitForIt(almM[0], almM[1], almM[2], almM[3]);
        dose_dosadora_6_manual -= 0.5;
        if (dose_dosadora_6_manual < 0.5)
        {
          dose_dosadora_6_manual = 99.5;
        }
        config_dosagem_manual();
      }
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // Volta a tela altera configuracao das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);

        strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[164])));
        myGLCD.print(buffer, 15, 220);

        modo_manual = true;
        modo_personalizado = false;
        modo_calibrar = false;
        dosadora_selecionada = 0x0; 
      }
      if ((x>=iniciaR[0]) && x<=iniciaR[2] && (y>=iniciaR[1]) && (y<=iniciaR[3]))
      {
        waitForIt(iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
        if((modo_manual == true) && (bitRead(dosadora_selecionada,1) == true))
        {
          if(fator_calib_dosadora_1 > 10)
          {
            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
            printButton_verde(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);

            tempo_dosagem = map ((dose_dosadora_1_manual*2), 0, fator_calib_dosadora_1, 0, 60000);
            tempo_dosagem /= 2;                 
            delay(10000);
            digitalWrite(dosadora1, HIGH);
            delay(tempo_dosagem);
            digitalWrite(dosadora1, LOW);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
            printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          }
        }
        if((modo_manual == true) && (bitRead(dosadora_selecionada,2) == true))
        {
          if(fator_calib_dosadora_2 > 10)
          {
            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
            printButton_verde(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);

            tempo_dosagem = map ((dose_dosadora_2_manual*2), 0, fator_calib_dosadora_2, 0, 60000);
            tempo_dosagem /= 2;
            delay(10000);
            digitalWrite(dosadora2, HIGH);
            delay(tempo_dosagem);
            digitalWrite(dosadora2, LOW);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
            printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          }
        }
        if((modo_manual == true) && (bitRead(dosadora_selecionada,3) == true))
        {
          if(fator_calib_dosadora_3 > 10)
          {
            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
            printButton_verde(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);

            tempo_dosagem = map ((dose_dosadora_3_manual*2), 0, fator_calib_dosadora_3, 0, 60000);
            tempo_dosagem /= 2;
            delay(10000);
            digitalWrite(dosadora3, HIGH);
            delay(tempo_dosagem);
            digitalWrite(dosadora3, LOW);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));            
            printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          }
        }
        if((modo_manual == true) && (bitRead(dosadora_selecionada,4) == true))
        {
          if(fator_calib_dosadora_4 > 10)
          {
            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
            printButton_verde(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);

            tempo_dosagem = map ((dose_dosadora_4_manual*2), 0, fator_calib_dosadora_4, 0, 60000);
            tempo_dosagem /= 2;                 
            delay(10000);
            digitalWrite(dosadora4, HIGH);
            delay(tempo_dosagem);
            digitalWrite(dosadora4, LOW);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
            printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          }
        }
        if((modo_manual == true) && (bitRead(dosadora_selecionada,5) == true))
        {
          if(fator_calib_dosadora_5 > 10)
          {
            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
            printButton_verde(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);

            tempo_dosagem = map ((dose_dosadora_5_manual*2), 0, fator_calib_dosadora_5, 0, 60000);
            tempo_dosagem /= 2;
            delay(10000);
            digitalWrite(dosadora5, HIGH);
            delay(tempo_dosagem);
            digitalWrite(dosadora5, LOW);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
            printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          }
        }
        if((modo_manual == true) && (bitRead(dosadora_selecionada,6) == true))
        {
          if(fator_calib_dosadora_6 > 10)
          {
            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
            printButton_verde(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);

            tempo_dosagem = map ((dose_dosadora_6_manual*2), 0, fator_calib_dosadora_6, 0, 60000);
            tempo_dosagem /= 2;
            delay(10000);
            digitalWrite(dosadora6, HIGH);
            delay(tempo_dosagem);
            digitalWrite(dosadora6, LOW);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));            
            printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]);
          }
        }
      }      
      break;

   case 29:   // ----------------------------------------- Config dosagem personalizada --------------------------------------
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]) && x<=volT[2] && (y>=volT[1]) && (y<=volT[3]))           // Volta a tela altera configuracao das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 21;
        clearScreen();
        selecionar_dosadora();
        setFont(SMALL, 255, 255, 255, 0, 0, 0);

        strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171])));
        myGLCD.print(buffer, 15, 220);

        modo_manual = false;
        modo_personalizado = true;
        modo_calibrar = false;
        dosadora_selecionada = 0x0;
      }
      if ((y >= proX[1]) && (y <= proX[3]) && (x >= proX[0]) && (x <= proX[2])) {
        waitForIt(proX[0], proX[1], proX[2], proX[3]); //Próximo menu.
        dispScreen = 31;
        clearScreen();
        config_dosagem_personalizada_2(true);
      }
      if(bitRead(dosadora_selecionada,1) == true)
      {
        if ((y >= houU[1]) && (y <= houU[3])) // Buttons: Time UP
        {
          if ((x >= houU[0]) && (x <= houU[2])) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            temp2hora_inicial_dosagem_personalizada_1 = (temp2hora_inicial_dosagem_personalizada_1 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0]) && (x <= minUT[2])) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            temp2minuto_inicial_dosagem_personalizada_1 = (temp2minuto_inicial_dosagem_personalizada_1 + 1) % 60;
            config_dosagem_personalizada();
          } 


          if ((x >= houU[0] + 155) && (x <= houU[2] + 155)) {
            waitForIt(houU[0] + 155, houU[1], houU[2] + 155, houU[3]);
            temp2hora_final_dosagem_personalizada_1 = (temp2hora_final_dosagem_personalizada_1 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0] + 155) && (x <= minUT[2] + 155)) {
            waitForIt(minUT[0] + 155, minUT[1], minUT[2] + 155, minUT[3]);
            temp2minuto_final_dosagem_personalizada_1 = (temp2minuto_final_dosagem_personalizada_1 + 1) % 60;
            config_dosagem_personalizada();
          }

        } 
        if ((y >= houD[1]) && (y <= houD[3])) // Buttons: Time DOWN
        {
          if ((x >= houD[0]) && (x <= houD[2])) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            temp2hora_inicial_dosagem_personalizada_1 = (temp2hora_inicial_dosagem_personalizada_1 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0]) && (x <= minDT[2])) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            temp2minuto_inicial_dosagem_personalizada_1 = (temp2minuto_inicial_dosagem_personalizada_1 + 59) % 60;
            config_dosagem_personalizada();
          } 

          if ((x >= houD[0] + 155) && (x <= houD[2] + 155)) {
            waitForIt(houD[0] + 155, houD[1], houD[2] + 155, houD[3]);
            temp2hora_final_dosagem_personalizada_1 = (temp2hora_final_dosagem_personalizada_1 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0] + 155) && (x <= minDT[2] + 155)) {
            waitForIt(minDT[0] + 155, minDT[1], minDT[2] + 155, minDT[3]);
            temp2minuto_final_dosagem_personalizada_1 = (temp2minuto_final_dosagem_personalizada_1 + 59) % 60;
            config_dosagem_personalizada();
          }
        }

        if ((x >= segU[0]) && (x <= segU[2]) && (y >= segU[1]) && (y <= segU[3])) {
          if (temp2segunda_dosagem_personalizada_1 == 1) {
            temp2segunda_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2segunda_dosagem_personalizada_1 = 1;
            config_dosagem_personalizada();
          }
        }
        if ((x >= terC[0]) && (x <= terC[2]) && (y >= terC[1]) && (y <= terC[3])) {
          if (temp2terca_dosagem_personalizada_1 == 2) {
            temp2terca_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2terca_dosagem_personalizada_1 = 2;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quaR[0]) && (x <= quaR[2]) && (y >= quaR[1]) && (y <= quaR[3])) {

          if (temp2quarta_dosagem_personalizada_1 == 3) {
            temp2quarta_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quarta_dosagem_personalizada_1 = 3;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quiN[0]) && (x <= quiN[2]) && (y >= quiN[1]) && (y <= quiN[3])) {

          if (temp2quinta_dosagem_personalizada_1 == 4) {
            temp2quinta_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quinta_dosagem_personalizada_1 = 4;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sexT[0]) && (x <= sexT[2]) && (y >= sexT[1]) && (y <= sexT[3])) {
          if (temp2sexta_dosagem_personalizada_1 == 5) {
            temp2sexta_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sexta_dosagem_personalizada_1 = 5;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sabA[0]) && (x <= sabA[2]) && (y >= sabA[1]) && (y <= sabA[3])) {
          if (temp2sabado_dosagem_personalizada_1 == 6) {
            temp2sabado_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sabado_dosagem_personalizada_1 = 6;
            config_dosagem_personalizada();
          }
        }
        if ((x >= domI[0]) && (x <= domI[2]) && (y >= domI[1]) && (y <= domI[3])) {
          if (temp2domingo_dosagem_personalizada_1 == 7) {
            temp2domingo_dosagem_personalizada_1 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2domingo_dosagem_personalizada_1 = 7;
            config_dosagem_personalizada();
          }
        }
      }
      if(bitRead(dosadora_selecionada,2) == true)
      {
        if ((y >= houU[1]) && (y <= houU[3])) // Buttons: Time UP
        {
          if ((x >= houU[0]) && (x <= houU[2])) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            temp2hora_inicial_dosagem_personalizada_2 = (temp2hora_inicial_dosagem_personalizada_2 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0]) && (x <= minUT[2])) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            temp2minuto_inicial_dosagem_personalizada_2 = (temp2minuto_inicial_dosagem_personalizada_2 + 1) % 60;
            config_dosagem_personalizada();
          } 


          if ((x >= houU[0] + 155) && (x <= houU[2] + 155)) {
            waitForIt(houU[0] + 155, houU[1], houU[2] + 155, houU[3]);
            temp2hora_final_dosagem_personalizada_2 = (temp2hora_final_dosagem_personalizada_2 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0] + 155) && (x <= minUT[2] + 155)) {
            waitForIt(minUT[0] + 155, minUT[1], minUT[2] + 155, minUT[3]);
            temp2minuto_final_dosagem_personalizada_2 = (temp2minuto_final_dosagem_personalizada_2 + 1) % 60;
            config_dosagem_personalizada();
          }

        } 
        if ((y >= houD[1]) && (y <= houD[3])) // Buttons: Time DOWN
        {
          if ((x >= houD[0]) && (x <= houD[2])) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            temp2hora_inicial_dosagem_personalizada_2 = (temp2hora_inicial_dosagem_personalizada_2 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0]) && (x <= minDT[2])) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            temp2minuto_inicial_dosagem_personalizada_2 = (temp2minuto_inicial_dosagem_personalizada_2 + 59) % 60;
            config_dosagem_personalizada();
          } 

          if ((x >= houD[0] + 155) && (x <= houD[2] + 155)) {
            waitForIt(houD[0] + 155, houD[1], houD[2] + 155, houD[3]);
            temp2hora_final_dosagem_personalizada_2 = (temp2hora_final_dosagem_personalizada_2 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0] + 155) && (x <= minDT[2] + 155)) {
            waitForIt(minDT[0] + 155, minDT[1], minDT[2] + 155, minDT[3]);
            temp2minuto_final_dosagem_personalizada_2 = (temp2minuto_final_dosagem_personalizada_2 + 59) % 60;
            config_dosagem_personalizada();
          }
        }

        if ((x >= segU[0]) && (x <= segU[2]) && (y >= segU[1]) && (y <= segU[3])) {
          if (temp2segunda_dosagem_personalizada_2 == 1) {
            temp2segunda_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2segunda_dosagem_personalizada_2 = 1;
            config_dosagem_personalizada();
          }
        }
        if ((x >= terC[0]) && (x <= terC[2]) && (y >= terC[1]) && (y <= terC[3])) {
          if (temp2terca_dosagem_personalizada_2 == 2) {
            temp2terca_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2terca_dosagem_personalizada_2 = 2;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quaR[0]) && (x <= quaR[2]) && (y >= quaR[1]) && (y <= quaR[3])) {

          if (temp2quarta_dosagem_personalizada_2 == 3) {
            temp2quarta_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quarta_dosagem_personalizada_2 = 3;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quiN[0]) && (x <= quiN[2]) && (y >= quiN[1]) && (y <= quiN[3])) {

          if (temp2quinta_dosagem_personalizada_2 == 4) {
            temp2quinta_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quinta_dosagem_personalizada_2 = 4;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sexT[0]) && (x <= sexT[2]) && (y >= sexT[1]) && (y <= sexT[3])) {
          if (temp2sexta_dosagem_personalizada_2 == 5) {
            temp2sexta_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sexta_dosagem_personalizada_2 = 5;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sabA[0]) && (x <= sabA[2]) && (y >= sabA[1]) && (y <= sabA[3])) {
          if (temp2sabado_dosagem_personalizada_2 == 6) {
            temp2sabado_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sabado_dosagem_personalizada_2 = 6;
            config_dosagem_personalizada();
          }
        }
        if ((x >= domI[0]) && (x <= domI[2]) && (y >= domI[1]) && (y <= domI[3])) {
          if (temp2domingo_dosagem_personalizada_2 == 7) {
            temp2domingo_dosagem_personalizada_2 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2domingo_dosagem_personalizada_2 = 7;
            config_dosagem_personalizada();
          }
        }
      }
      if(bitRead(dosadora_selecionada,3) == true)
      {
        if ((y >= houU[1]) && (y <= houU[3])) // Buttons: Time UP
        {
          if ((x >= houU[0]) && (x <= houU[2])) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            temp2hora_inicial_dosagem_personalizada_3 = (temp2hora_inicial_dosagem_personalizada_3 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0]) && (x <= minUT[2])) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            temp2minuto_inicial_dosagem_personalizada_3 = (temp2minuto_inicial_dosagem_personalizada_3 + 1) % 60;
            config_dosagem_personalizada();
          } 


          if ((x >= houU[0] + 155) && (x <= houU[2] + 155)) {
            waitForIt(houU[0] + 155, houU[1], houU[2] + 155, houU[3]);
            temp2hora_final_dosagem_personalizada_3 = (temp2hora_final_dosagem_personalizada_3 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0] + 155) && (x <= minUT[2] + 155)) {
            waitForIt(minUT[0] + 155, minUT[1], minUT[2] + 155, minUT[3]);
            temp2minuto_final_dosagem_personalizada_3 = (temp2minuto_final_dosagem_personalizada_3 + 1) % 60;
            config_dosagem_personalizada();
          }

        } 
        if ((y >= houD[1]) && (y <= houD[3])) // Buttons: Time DOWN
        {
          if ((x >= houD[0]) && (x <= houD[2])) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            temp2hora_inicial_dosagem_personalizada_3 = (temp2hora_inicial_dosagem_personalizada_3 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0]) && (x <= minDT[2])) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            temp2minuto_inicial_dosagem_personalizada_3 = (temp2minuto_inicial_dosagem_personalizada_3 + 59) % 60;
            config_dosagem_personalizada();
          } 

          if ((x >= houD[0] + 155) && (x <= houD[2] + 155)) {
            waitForIt(houD[0] + 155, houD[1], houD[2] + 155, houD[3]);
            temp2hora_final_dosagem_personalizada_3 = (temp2hora_final_dosagem_personalizada_3 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0] + 155) && (x <= minDT[2] + 155)) {
            waitForIt(minDT[0] + 155, minDT[1], minDT[2] + 155, minDT[3]);
            temp2minuto_final_dosagem_personalizada_3 = (temp2minuto_final_dosagem_personalizada_3 + 59) % 60;
            config_dosagem_personalizada();
          }
        }

        if ((x >= segU[0]) && (x <= segU[2]) && (y >= segU[1]) && (y <= segU[3])) {
          if (temp2segunda_dosagem_personalizada_3 == 1) {
            temp2segunda_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2segunda_dosagem_personalizada_3 = 1;
            config_dosagem_personalizada();
          }
        }
        if ((x >= terC[0]) && (x <= terC[2]) && (y >= terC[1]) && (y <= terC[3])) {
          if (temp2terca_dosagem_personalizada_3 == 2) {
            temp2terca_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2terca_dosagem_personalizada_3 = 2;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quaR[0]) && (x <= quaR[2]) && (y >= quaR[1]) && (y <= quaR[3])) {

          if (temp2quarta_dosagem_personalizada_3 == 3) {
            temp2quarta_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quarta_dosagem_personalizada_3 = 3;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quiN[0]) && (x <= quiN[2]) && (y >= quiN[1]) && (y <= quiN[3])) {

          if (temp2quinta_dosagem_personalizada_3 == 4) {
            temp2quinta_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quinta_dosagem_personalizada_3 = 4;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sexT[0]) && (x <= sexT[2]) && (y >= sexT[1]) && (y <= sexT[3])) {
          if (temp2sexta_dosagem_personalizada_3 == 5) {
            temp2sexta_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sexta_dosagem_personalizada_3 = 5;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sabA[0]) && (x <= sabA[2]) && (y >= sabA[1]) && (y <= sabA[3])) {
          if (temp2sabado_dosagem_personalizada_3 == 6) {
            temp2sabado_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sabado_dosagem_personalizada_3 = 6;
            config_dosagem_personalizada();
          }
        }
        if ((x >= domI[0]) && (x <= domI[2]) && (y >= domI[1]) && (y <= domI[3])) {
          if (temp2domingo_dosagem_personalizada_3 == 7) {
            temp2domingo_dosagem_personalizada_3 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2domingo_dosagem_personalizada_3 = 7;
            config_dosagem_personalizada();
          }
        }
      }
      if(bitRead(dosadora_selecionada,4) == true)
      {
        if ((y >= houU[1]) && (y <= houU[3])) // Buttons: Time UP
        {
          if ((x >= houU[0]) && (x <= houU[2])) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            temp2hora_inicial_dosagem_personalizada_4 = (temp2hora_inicial_dosagem_personalizada_4 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0]) && (x <= minUT[2])) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            temp2minuto_inicial_dosagem_personalizada_4 = (temp2minuto_inicial_dosagem_personalizada_4 + 1) % 60;
            config_dosagem_personalizada();
          } 


          if ((x >= houU[0] + 155) && (x <= houU[2] + 155)) {
            waitForIt(houU[0] + 155, houU[1], houU[2] + 155, houU[3]);
            temp2hora_final_dosagem_personalizada_4 = (temp2hora_final_dosagem_personalizada_4 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0] + 155) && (x <= minUT[2] + 155)) {
            waitForIt(minUT[0] + 155, minUT[1], minUT[2] + 155, minUT[3]);
            temp2minuto_final_dosagem_personalizada_4 = (temp2minuto_final_dosagem_personalizada_4 + 1) % 60;
            config_dosagem_personalizada();
          }

        } 
        if ((y >= houD[1]) && (y <= houD[3])) // Buttons: Time DOWN
        {
          if ((x >= houD[0]) && (x <= houD[2])) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            temp2hora_inicial_dosagem_personalizada_4 = (temp2hora_inicial_dosagem_personalizada_4 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0]) && (x <= minDT[2])) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            temp2minuto_inicial_dosagem_personalizada_4 = (temp2minuto_inicial_dosagem_personalizada_4 + 59) % 60;
            config_dosagem_personalizada();
          } 

          if ((x >= houD[0] + 155) && (x <= houD[2] + 155)) {
            waitForIt(houD[0] + 155, houD[1], houD[2] + 155, houD[3]);
            temp2hora_final_dosagem_personalizada_4 = (temp2hora_final_dosagem_personalizada_4 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0] + 155) && (x <= minDT[2] + 155)) {
            waitForIt(minDT[0] + 155, minDT[1], minDT[2] + 155, minDT[3]);
            temp2minuto_final_dosagem_personalizada_4 = (temp2minuto_final_dosagem_personalizada_4 + 59) % 60;
            config_dosagem_personalizada();
          }
        }

        if ((x >= segU[0]) && (x <= segU[2]) && (y >= segU[1]) && (y <= segU[3])) {
          if (temp2segunda_dosagem_personalizada_4 == 1) {
            temp2segunda_dosagem_personalizada_4 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2segunda_dosagem_personalizada_4 = 1;
            config_dosagem_personalizada();
          }
        }
        if ((x >= terC[0]) && (x <= terC[2]) && (y >= terC[1]) && (y <= terC[3])) {
          if (temp2terca_dosagem_personalizada_4 == 2) {
            temp2terca_dosagem_personalizada_4 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2terca_dosagem_personalizada_4 = 2;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quaR[0]) && (x <= quaR[2]) && (y >= quaR[1]) && (y <= quaR[3])) {

          if (temp2quarta_dosagem_personalizada_4 == 3) {
            temp2quarta_dosagem_personalizada_4 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quarta_dosagem_personalizada_4 = 3;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quiN[0]) && (x <= quiN[2]) && (y >= quiN[1]) && (y <= quiN[3])) {

          if (temp2quinta_dosagem_personalizada_4 == 4) {
            temp2quinta_dosagem_personalizada_4 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quinta_dosagem_personalizada_4 = 4;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sexT[0]) && (x <= sexT[2]) && (y >= sexT[1]) && (y <= sexT[3])) {
          if (temp2sexta_dosagem_personalizada_4 == 5) {
            temp2sexta_dosagem_personalizada_4 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sexta_dosagem_personalizada_4 = 5;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sabA[0]) && (x <= sabA[2]) && (y >= sabA[1]) && (y <= sabA[3])) {
          if (temp2sabado_dosagem_personalizada_4 == 6) {
            temp2sabado_dosagem_personalizada_4 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sabado_dosagem_personalizada_4 = 6;
            config_dosagem_personalizada();
          }
        }
        if ((x >= domI[0]) && (x <= domI[2]) && (y >= domI[1]) && (y <= domI[3])) {
          if (temp2domingo_dosagem_personalizada_4 == 7) {
            temp2domingo_dosagem_personalizada_4 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2domingo_dosagem_personalizada_4 = 7;
            config_dosagem_personalizada();
          }
        }
      }
      if(bitRead(dosadora_selecionada,5) == true)
      {
        if ((y >= houU[1]) && (y <= houU[3])) // Buttons: Time UP
        {
          if ((x >= houU[0]) && (x <= houU[2])) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            temp2hora_inicial_dosagem_personalizada_5 = (temp2hora_inicial_dosagem_personalizada_5 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0]) && (x <= minUT[2])) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            temp2minuto_inicial_dosagem_personalizada_5 = (temp2minuto_inicial_dosagem_personalizada_5 + 1) % 60;
            config_dosagem_personalizada();
          } 


          if ((x >= houU[0] + 155) && (x <= houU[2] + 155)) {
            waitForIt(houU[0] + 155, houU[1], houU[2] + 155, houU[3]);
            temp2hora_final_dosagem_personalizada_5 = (temp2hora_final_dosagem_personalizada_5 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0] + 155) && (x <= minUT[2] + 155)) {
            waitForIt(minUT[0] + 155, minUT[1], minUT[2] + 155, minUT[3]);
            temp2minuto_final_dosagem_personalizada_5 = (temp2minuto_final_dosagem_personalizada_5 + 1) % 60;
            config_dosagem_personalizada();
          }

        } 
        if ((y >= houD[1]) && (y <= houD[3])) // Buttons: Time DOWN
        {
          if ((x >= houD[0]) && (x <= houD[2])) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            temp2hora_inicial_dosagem_personalizada_5 = (temp2hora_inicial_dosagem_personalizada_5 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0]) && (x <= minDT[2])) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            temp2minuto_inicial_dosagem_personalizada_5 = (temp2minuto_inicial_dosagem_personalizada_5 + 59) % 60;
            config_dosagem_personalizada();
          } 

          if ((x >= houD[0] + 155) && (x <= houD[2] + 155)) {
            waitForIt(houD[0] + 155, houD[1], houD[2] + 155, houD[3]);
            temp2hora_final_dosagem_personalizada_5 = (temp2hora_final_dosagem_personalizada_5 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0] + 155) && (x <= minDT[2] + 155)) {
            waitForIt(minDT[0] + 155, minDT[1], minDT[2] + 155, minDT[3]);
            temp2minuto_final_dosagem_personalizada_5 = (temp2minuto_final_dosagem_personalizada_5 + 59) % 60;
            config_dosagem_personalizada();
          }
        }

        if ((x >= segU[0]) && (x <= segU[2]) && (y >= segU[1]) && (y <= segU[3])) {
          if (temp2segunda_dosagem_personalizada_5 == 1) {
            temp2segunda_dosagem_personalizada_5 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2segunda_dosagem_personalizada_5 = 1;
            config_dosagem_personalizada();
          }
        }
        if ((x >= terC[0]) && (x <= terC[2]) && (y >= terC[1]) && (y <= terC[3])) {
          if (temp2terca_dosagem_personalizada_5 == 2) {
            temp2terca_dosagem_personalizada_5 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2terca_dosagem_personalizada_5 = 2;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quaR[0]) && (x <= quaR[2]) && (y >= quaR[1]) && (y <= quaR[3])) {

          if (temp2quarta_dosagem_personalizada_5 == 3) {
            temp2quarta_dosagem_personalizada_5 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quarta_dosagem_personalizada_5 = 3;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quiN[0]) && (x <= quiN[2]) && (y >= quiN[1]) && (y <= quiN[3])) {

          if (temp2quinta_dosagem_personalizada_5 == 4) {
            temp2quinta_dosagem_personalizada_5 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quinta_dosagem_personalizada_5 = 4;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sexT[0]) && (x <= sexT[2]) && (y >= sexT[1]) && (y <= sexT[3])) {
          if (temp2sexta_dosagem_personalizada_5 == 5) {
            temp2sexta_dosagem_personalizada_5 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sexta_dosagem_personalizada_5 = 5;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sabA[0]) && (x <= sabA[2]) && (y >= sabA[1]) && (y <= sabA[3])) {
          if (temp2sabado_dosagem_personalizada_5 == 6) {
            temp2sabado_dosagem_personalizada_5 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sabado_dosagem_personalizada_5 = 6;
            config_dosagem_personalizada();
          }
        }
        if ((x >= domI[0]) && (x <= domI[2]) && (y >= domI[1]) && (y <= domI[3])) {
          if (temp2domingo_dosagem_personalizada_5 == 7) {
            temp2domingo_dosagem_personalizada_5 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2domingo_dosagem_personalizada_5 = 7;
            config_dosagem_personalizada();
          }
        }
      }
      if(bitRead(dosadora_selecionada,6) == true)
      {
        if ((y >= houU[1]) && (y <= houU[3])) // Buttons: Time UP
        {
          if ((x >= houU[0]) && (x <= houU[2])) {
            waitForIt(houU[0], houU[1], houU[2], houU[3]);
            temp2hora_inicial_dosagem_personalizada_6 = (temp2hora_inicial_dosagem_personalizada_6 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0]) && (x <= minUT[2])) {
            waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
            temp2minuto_inicial_dosagem_personalizada_6 = (temp2minuto_inicial_dosagem_personalizada_6 + 1) % 60;
            config_dosagem_personalizada();
          } 


          if ((x >= houU[0] + 155) && (x <= houU[2] + 155)) {
            waitForIt(houU[0] + 155, houU[1], houU[2] + 155, houU[3]);
            temp2hora_final_dosagem_personalizada_6 = (temp2hora_final_dosagem_personalizada_6 + 1) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minUT[0] + 155) && (x <= minUT[2] + 155)) {
            waitForIt(minUT[0] + 155, minUT[1], minUT[2] + 155, minUT[3]);
            temp2minuto_final_dosagem_personalizada_6 = (temp2minuto_final_dosagem_personalizada_6 + 1) % 60;
            config_dosagem_personalizada();
          }

        } 
        if ((y >= houD[1]) && (y <= houD[3])) // Buttons: Time DOWN
        {
          if ((x >= houD[0]) && (x <= houD[2])) {
            waitForIt(houD[0], houD[1], houD[2], houD[3]);
            temp2hora_inicial_dosagem_personalizada_6 = (temp2hora_inicial_dosagem_personalizada_6 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0]) && (x <= minDT[2])) {
            waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
            temp2minuto_inicial_dosagem_personalizada_6 = (temp2minuto_inicial_dosagem_personalizada_6 + 59) % 60;
            config_dosagem_personalizada();
          } 

          if ((x >= houD[0] + 155) && (x <= houD[2] + 155)) {
            waitForIt(houD[0] + 155, houD[1], houD[2] + 155, houD[3]);
            temp2hora_final_dosagem_personalizada_6 = (temp2hora_final_dosagem_personalizada_6 + 23) % 24;
            config_dosagem_personalizada();
          } 
          if ((x >= minDT[0] + 155) && (x <= minDT[2] + 155)) {
            waitForIt(minDT[0] + 155, minDT[1], minDT[2] + 155, minDT[3]);
            temp2minuto_final_dosagem_personalizada_6 = (temp2minuto_final_dosagem_personalizada_6 + 59) % 60;
            config_dosagem_personalizada();
          }
        }

        if ((x >= segU[0]) && (x <= segU[2]) && (y >= segU[1]) && (y <= segU[3])) {
          if (temp2segunda_dosagem_personalizada_6 == 1) {
            temp2segunda_dosagem_personalizada_6 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2segunda_dosagem_personalizada_6 = 1;
            config_dosagem_personalizada();
          }
        }
        if ((x >= terC[0]) && (x <= terC[2]) && (y >= terC[1]) && (y <= terC[3])) {
          if (temp2terca_dosagem_personalizada_6 == 2) {
            temp2terca_dosagem_personalizada_6 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2terca_dosagem_personalizada_6 = 2;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quaR[0]) && (x <= quaR[2]) && (y >= quaR[1]) && (y <= quaR[3])) {

          if (temp2quarta_dosagem_personalizada_6 == 3) {
            temp2quarta_dosagem_personalizada_6 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quarta_dosagem_personalizada_6 = 3;
            config_dosagem_personalizada();
          }
        }
        if ((x >= quiN[0]) && (x <= quiN[2]) && (y >= quiN[1]) && (y <= quiN[3])) {

          if (temp2quinta_dosagem_personalizada_6 == 4) {
            temp2quinta_dosagem_personalizada_6 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2quinta_dosagem_personalizada_6 = 4;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sexT[0]) && (x <= sexT[2]) && (y >= sexT[1]) && (y <= sexT[3])) {
          if (temp2sexta_dosagem_personalizada_6 == 5) {
            temp2sexta_dosagem_personalizada_6 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sexta_dosagem_personalizada_6 = 5;
            config_dosagem_personalizada();
          }
        }
        if ((x >= sabA[0]) && (x <= sabA[2]) && (y >= sabA[1]) && (y <= sabA[3])) {
          if (temp2sabado_dosagem_personalizada_6 == 6) {
            temp2sabado_dosagem_personalizada_6 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2sabado_dosagem_personalizada_6 = 6;
            config_dosagem_personalizada();
          }
        }
        if ((x >= domI[0]) && (x <= domI[2]) && (y >= domI[1]) && (y <= domI[3])) {
          if (temp2domingo_dosagem_personalizada_6 == 7) {
            temp2domingo_dosagem_personalizada_6 = 0;
            config_dosagem_personalizada();
          } 
          else {
            temp2domingo_dosagem_personalizada_6 = 7;
            config_dosagem_personalizada();
          }
        }
      }
      break;

    case 31:// ----------------------------------------- Dosagem personalizada --------------------------------------------
      if ((x>=menU[0]) && x<=menU[2] && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
      }
      if ((y >= anT[1]) && (y <= anT[3]) && (x >= anT[0]) && (x <= anT[2])) // Volta ao menu dosagem personalizada
      {
        waitForIt(anT[0], anT[1], anT[2], anT[3]);
        dispScreen = 29;
        clearScreen();
        config_dosagem_personalizada(true);
      }
      if(bitRead(dosadora_selecionada,1) == true)
      {
        if ((x >= minUT[0]) && (x <= minUT[2]) && (y >= minUT[1]) && (y <= minUT[3])) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          dose_dosadora_1_personalizada_temp2 += 0.5;
          if(dose_dosadora_1_personalizada_temp2 > 999.5)
          {
            dose_dosadora_1_personalizada_temp2 = 0.5;
          }
          if(dose_dosadora_1_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }           

          config_dosagem_personalizada_2();
        }
        if ((x >= minDT[0]) && (x <= minDT[2]) && (y >= minDT[1]) && (y <= minDT[3])) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          dose_dosadora_1_personalizada_temp2 -= 0.5;
          if(dose_dosadora_1_personalizada_temp2 <0.5)
          {
            dose_dosadora_1_personalizada_temp2 = 999.5;
          }
          if(dose_dosadora_1_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= durC[0]) && (x <= durC[2]) && (y >= durC[1]) && (y <= durC[3])) 
        {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          quantidade_dose_dosadora_1_personalizada_temp2 += 1;
          if(quantidade_dose_dosadora_1_personalizada_temp2 > 24)
          {
            quantidade_dose_dosadora_1_personalizada_temp2 = 1;
          }
          config_dosagem_personalizada_2();
        }

        if ((x >= durB[0]) && (x <= durB[2]) && (y >= durB[1]) && (y <= durB[3])) 
        {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          quantidade_dose_dosadora_1_personalizada_temp2 -= 1;
          if(quantidade_dose_dosadora_1_personalizada_temp2 < 1)
          {
            quantidade_dose_dosadora_1_personalizada_temp2 = 24;
          }
          config_dosagem_personalizada_2();        
        }
        if ((x >= sexT[0]) && (x<= sexT[2]) && (y >= sexT [1]) && (y <= sexT[3])) // Ativar ou desativar modo personalizado
        {
          waitForIt(sexT[0], sexT[1], sexT[2], sexT[3]);
          if(modo_personalizado_on_1_temp2 == 0)
          {
            modo_personalizado_on_1_temp2 = 1;
            config_dosagem_personalizada_2();
          }
          else
          {
            modo_personalizado_on_1_temp2 = 0;
            config_dosagem_personalizada_2();
          }
        }
        if ((y >= prOK[1]) && (y <= prOK[3]) && (x >= prOK[0]) && (x <= prOK[2])) 
        {
          waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
          dose_dosadora_1_personalizada = dose_dosadora_1_personalizada_temp2;
          quantidade_dose_dosadora_1_personalizada = quantidade_dose_dosadora_1_personalizada_temp2;
          bitWrite(modo_personalizado_on,1,modo_personalizado_on_1_temp2);
          hora_inicial_dosagem_personalizada_1 = temp2hora_inicial_dosagem_personalizada_1;
          minuto_inicial_dosagem_personalizada_1 = temp2minuto_inicial_dosagem_personalizada_1;
          hora_final_dosagem_personalizada_1 = temp2hora_final_dosagem_personalizada_1;
          minuto_final_dosagem_personalizada_1 = temp2minuto_final_dosagem_personalizada_1;
          bitWrite(segunda_dosagem_personalizada,1,temp2segunda_dosagem_personalizada_1);
          terca_dosagem_personalizada_1 = temp2terca_dosagem_personalizada_1;
          quarta_dosagem_personalizada_1 = temp2quarta_dosagem_personalizada_1;
          quinta_dosagem_personalizada_1 = temp2quinta_dosagem_personalizada_1;
          sexta_dosagem_personalizada_1 = temp2sexta_dosagem_personalizada_1;
          sabado_dosagem_personalizada_1 = temp2sabado_dosagem_personalizada_1;
          domingo_dosagem_personalizada_1 = temp2domingo_dosagem_personalizada_1;

          if((hora_final_dosagem_personalizada_1 == hora_inicial_dosagem_personalizada_1) && (minuto_final_dosagem_personalizada_1 < (minuto_inicial_dosagem_personalizada_1+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[176])));            
            myGLCD.print(buffer, 20, 110); // "O INTERVALO ENTRE A INICIAL E A FINAL"

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[177]))); 
            myGLCD.print(buffer, 35, 130);

          }
          if(hora_final_dosagem_personalizada_1 < hora_inicial_dosagem_personalizada_1)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[178]))); 
            myGLCD.print(buffer, 50, 110);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[179]))); 
            myGLCD.print(buffer, 100, 130);
          }

          if((temp2hora_final_dosagem_personalizada_1 == hora_inicial_dosagem_personalizada_1) && (temp2minuto_final_dosagem_personalizada_1 >= (minuto_inicial_dosagem_personalizada_1+10)))
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171]))); 
            myGLCD.print(buffer, 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"

            modo_manual = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_selecionada = 0x0;
            digitalWrite (4, LOW); 
            file.open(&root, "HDP1.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP1.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = NumMins(hora_final_dosagem_personalizada_1, minuto_final_dosagem_personalizada_1) - NumMins(hora_inicial_dosagem_personalizada_1, minuto_inicial_dosagem_personalizada_1); 
            minuto01 /= 1 + quantidade_dose_dosadora_1_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_1_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = NumMins(hora_inicial_dosagem_personalizada_1, minuto_inicial_dosagem_personalizada_1) + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(temp2hora_final_dosagem_personalizada_1 > hora_inicial_dosagem_personalizada_1)
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171]))); 
            myGLCD.print(buffer, 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"


            modo_manual = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_selecionada = 0x0;
            digitalWrite (4, LOW); 
            file.open(&root, "HDP1.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP1.TXT", O_CREAT | O_APPEND | O_WRITE);

            if((minuto_inicial_dosagem_personalizada_1 == minuto_inicial_dosagem_personalizada_2) || (minuto_inicial_dosagem_personalizada_1 == minuto_inicial_dosagem_personalizada_3))
            {
              minuto_inicial_dosagem_personalizada_1 += 10;
            }
            if(minuto_inicial_dosagem_personalizada_1 >= 60)
            {
              minuto_inicial_dosagem_personalizada_1 -= 60;
              hora_inicial_dosagem_personalizada_1 += 1;
            }
            minuto01 = NumMins(hora_final_dosagem_personalizada_1, minuto_final_dosagem_personalizada_1) - NumMins(hora_inicial_dosagem_personalizada_1, minuto_inicial_dosagem_personalizada_1); 
            minuto01 /= 1 + quantidade_dose_dosadora_1_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_1_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = NumMins(hora_inicial_dosagem_personalizada_1, minuto_inicial_dosagem_personalizada_1) + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        } 
      }      
      if(bitRead(dosadora_selecionada,2) == true)
      {
        if ((x >= minUT[0]) && (x <= minUT[2]) && (y >= minUT[1]) && (y <= minUT[3])) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          dose_dosadora_2_personalizada_temp2 += 0.5;
          if(dose_dosadora_2_personalizada_temp2 > 999.5)
          {
            dose_dosadora_2_personalizada_temp2 = 0.5;
          }
          if(dose_dosadora_2_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= minDT[0]) && (x <= minDT[2]) && (y >= minDT[1]) && (y <= minDT[3])) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          dose_dosadora_2_personalizada_temp2 -= 0.5;
          if(dose_dosadora_2_personalizada_temp2 <0.5)
          {
            dose_dosadora_2_personalizada_temp2 = 999.5;
          }
          if(dose_dosadora_2_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= durC[0]) && (x <= durC[2]) && (y >= durC[1]) && (y <= durC[3])) 
        {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          quantidade_dose_dosadora_2_personalizada_temp2 += 1;
          if(quantidade_dose_dosadora_2_personalizada_temp2 > 24)
          {
            quantidade_dose_dosadora_2_personalizada_temp2 = 1;
          }
          config_dosagem_personalizada_2();
        }

        if ((x >= durB[0]) && (x <= durB[2]) && (y >= durB[1]) && (y <= durB[3])) 
        {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          quantidade_dose_dosadora_2_personalizada_temp2 -= 1;
          if(quantidade_dose_dosadora_2_personalizada_temp2 < 1)
          {
            quantidade_dose_dosadora_2_personalizada_temp2 = 24;
          }
          config_dosagem_personalizada_2();        
        }
        if ((x >= sexT[0]) && (x<= sexT[2]) && (y >= sexT [1]) && (y <= sexT[3]))
        {
          waitForIt(sexT[0], sexT[1], sexT[2], sexT[3]);
          if(modo_personalizado_on_2_temp2 == 0)
          {
            modo_personalizado_on_2_temp2 = 1;
            config_dosagem_personalizada_2();
          }
          else
          {
            modo_personalizado_on_2_temp2 = 0;
            config_dosagem_personalizada_2();
          }
        }
        if ((y >= prOK[1]) && (y <= prOK[3]) && (x >= prOK[0]) && (x <= prOK[2])) 
        {
          waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
          dose_dosadora_2_personalizada = dose_dosadora_2_personalizada_temp2;
          quantidade_dose_dosadora_2_personalizada = quantidade_dose_dosadora_2_personalizada_temp2;
          bitWrite(modo_personalizado_on,2,modo_personalizado_on_2_temp2);
          hora_inicial_dosagem_personalizada_2 = temp2hora_inicial_dosagem_personalizada_2;
          minuto_inicial_dosagem_personalizada_2 = temp2minuto_inicial_dosagem_personalizada_2;
          hora_final_dosagem_personalizada_2 = temp2hora_final_dosagem_personalizada_2;
          minuto_final_dosagem_personalizada_2 = temp2minuto_final_dosagem_personalizada_2;
          bitWrite(segunda_dosagem_personalizada,2,temp2segunda_dosagem_personalizada_2);
          terca_dosagem_personalizada_2 = temp2terca_dosagem_personalizada_2;
          quarta_dosagem_personalizada_2 = temp2quarta_dosagem_personalizada_2;
          quinta_dosagem_personalizada_2 = temp2quinta_dosagem_personalizada_2;
          sexta_dosagem_personalizada_2 = temp2sexta_dosagem_personalizada_2;
          sabado_dosagem_personalizada_2 = temp2sabado_dosagem_personalizada_2;
          domingo_dosagem_personalizada_2 = temp2domingo_dosagem_personalizada_2;

          if((hora_final_dosagem_personalizada_2 == hora_inicial_dosagem_personalizada_2) && (minuto_final_dosagem_personalizada_2 < (minuto_inicial_dosagem_personalizada_2+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[176]))); 
            myGLCD.print(buffer, 20, 110);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[177]))); 
            myGLCD.print(buffer, 35, 130);
          }
          if(hora_final_dosagem_personalizada_2 < hora_inicial_dosagem_personalizada_2)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[178]))); 
            myGLCD.print(buffer, 50, 110); // "A HORA FINAL NAO PODE SER MENOR"

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[179]))); 
            myGLCD.print(buffer, 100, 130); // tabela_textos[179] = "QUE A INICIAL!"
          }

          if((temp2hora_final_dosagem_personalizada_2 == hora_inicial_dosagem_personalizada_2) && (temp2minuto_final_dosagem_personalizada_2 >= (minuto_inicial_dosagem_personalizada_2+10)))
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171]))); 
            myGLCD.print(buffer, 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"

            modo_manual = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_selecionada = 0x0;
            digitalWrite (4, LOW); 
            file.open(&root, "HDP2.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP2.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = NumMins(hora_final_dosagem_personalizada_2, minuto_final_dosagem_personalizada_2) - NumMins(hora_inicial_dosagem_personalizada_2, minuto_inicial_dosagem_personalizada_2); 
            minuto01 /= 1 + quantidade_dose_dosadora_2_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_2_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = NumMins(hora_inicial_dosagem_personalizada_2, minuto_inicial_dosagem_personalizada_2) + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(temp2hora_final_dosagem_personalizada_2 > hora_inicial_dosagem_personalizada_2)
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171]))); 
            myGLCD.print(buffer, 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"

            modo_manual = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_selecionada = 0x0;
            digitalWrite (4, LOW); 
            file.open(&root, "HDP2.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP2.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = NumMins(hora_final_dosagem_personalizada_2, minuto_final_dosagem_personalizada_2) - NumMins(hora_inicial_dosagem_personalizada_2, minuto_inicial_dosagem_personalizada_2); 
            minuto01 /= 1 + quantidade_dose_dosadora_2_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_2_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = NumMins(hora_inicial_dosagem_personalizada_2, minuto_inicial_dosagem_personalizada_2) + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }      
      }
      if(bitRead(dosadora_selecionada,3) == true)
      {
        if ((x >= minUT[0]) && (x <= minUT[2]) && (y >= minUT[1]) && (y <= minUT[3])) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          dose_dosadora_3_personalizada_temp2 += 0.5;
          if(dose_dosadora_3_personalizada_temp2 > 999.5)
          {
            dose_dosadora_3_personalizada_temp2 = 0.5;
          }
          if(dose_dosadora_3_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= minDT[0]) && (x <= minDT[2]) && (y >= minDT[1]) && (y <= minDT[3])) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          dose_dosadora_3_personalizada_temp2 -= 0.5;
          if(dose_dosadora_3_personalizada_temp2 <0.5)
          {
            dose_dosadora_3_personalizada_temp2 = 999.5;
          }
          if(dose_dosadora_3_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= durC[0]) && (x <= durC[2]) && (y >= durC[1]) && (y <= durC[3])) 
        {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          quantidade_dose_dosadora_3_personalizada_temp2 += 1;
          if(quantidade_dose_dosadora_3_personalizada_temp2 > 24)
          {
            quantidade_dose_dosadora_3_personalizada_temp2 = 1;
          }
          config_dosagem_personalizada_2();
        }

        if ((x >= durB[0]) && (x <= durB[2]) && (y >= durB[1]) && (y <= durB[3])) 
        {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          quantidade_dose_dosadora_3_personalizada_temp2 -= 1;
          if(quantidade_dose_dosadora_3_personalizada_temp2 < 1)
          {
            quantidade_dose_dosadora_3_personalizada_temp2 = 24;
          }
          config_dosagem_personalizada_2();        
        }
        if ((x >= sexT[0]) && (x<= sexT[2]) && (y >= sexT [1]) && (y <= sexT[3]))
        {
          waitForIt(sexT[0], sexT[1], sexT[2], sexT[3]);
          if(modo_personalizado_on_3_temp2 == 0)
          {
            modo_personalizado_on_3_temp2 = 1;
            config_dosagem_personalizada_2();
          }
          else
          {
            modo_personalizado_on_3_temp2 = 0;
            config_dosagem_personalizada_2();
          }
        }
        if ((y >= prOK[1]) && (y <= prOK[3]) && (x >= prOK[0]) && (x <= prOK[2])) 
        {
          waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
          dose_dosadora_3_personalizada = dose_dosadora_3_personalizada_temp2;
          quantidade_dose_dosadora_3_personalizada = quantidade_dose_dosadora_3_personalizada_temp2;
          bitWrite(modo_personalizado_on,3,modo_personalizado_on_3_temp2);
          hora_inicial_dosagem_personalizada_3 = temp2hora_inicial_dosagem_personalizada_3;
          minuto_inicial_dosagem_personalizada_3 = temp2minuto_inicial_dosagem_personalizada_3;
          hora_final_dosagem_personalizada_3 = temp2hora_final_dosagem_personalizada_3;
          minuto_final_dosagem_personalizada_3 = temp2minuto_final_dosagem_personalizada_3;
          bitWrite(segunda_dosagem_personalizada,3,temp2segunda_dosagem_personalizada_3);
          terca_dosagem_personalizada_3 = temp2terca_dosagem_personalizada_3;
          quarta_dosagem_personalizada_3 = temp2quarta_dosagem_personalizada_3;
          quinta_dosagem_personalizada_3 = temp2quinta_dosagem_personalizada_3;
          sexta_dosagem_personalizada_3 = temp2sexta_dosagem_personalizada_3;
          sabado_dosagem_personalizada_3 = temp2sabado_dosagem_personalizada_3;
          domingo_dosagem_personalizada_3 = temp2domingo_dosagem_personalizada_3;
          if((hora_final_dosagem_personalizada_3 == hora_inicial_dosagem_personalizada_3) && (minuto_final_dosagem_personalizada_3 < (minuto_inicial_dosagem_personalizada_3+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[176]))); 
            myGLCD.print(buffer, 20, 110);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[177]))); 
            myGLCD.print(buffer, 35, 130); // tabela_textos[177] = "DEVE SER DE NO MINIMO 10 MINUTOS!"
          }
          if(hora_final_dosagem_personalizada_3 < hora_inicial_dosagem_personalizada_3)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[178]))); 
            myGLCD.print(buffer, 50, 110); // tabela_textos[178] = "A HORA FINAL NAO PODE SER MENOR"

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[179]))); 
            myGLCD.print(buffer, 100, 130); // tabela_textos[179] = "QUE A INICIAL!" 
          }

          if((temp2hora_final_dosagem_personalizada_3 == hora_inicial_dosagem_personalizada_3) && (temp2minuto_final_dosagem_personalizada_3 >= (minuto_inicial_dosagem_personalizada_3+10)))
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171]))); 
            myGLCD.print(buffer, 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"

            modo_manual = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_selecionada = 0x0;
            digitalWrite (4, LOW); 
            file.open(&root, "HDP3.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP3.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = NumMins(hora_final_dosagem_personalizada_3, minuto_final_dosagem_personalizada_3) - NumMins(hora_inicial_dosagem_personalizada_3, minuto_inicial_dosagem_personalizada_3); 
            minuto01 /= 1 + quantidade_dose_dosadora_3_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_3_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = NumMins(hora_inicial_dosagem_personalizada_3, minuto_inicial_dosagem_personalizada_3) + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(temp2hora_final_dosagem_personalizada_3 > hora_inicial_dosagem_personalizada_3)
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171]))); 
            myGLCD.print(buffer, 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"

            modo_manual = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_selecionada = 0x0;
            digitalWrite (4, LOW); 
            file.open(&root, "HDP3.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP3.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = NumMins(hora_final_dosagem_personalizada_3, minuto_final_dosagem_personalizada_3) - NumMins(hora_inicial_dosagem_personalizada_3, minuto_inicial_dosagem_personalizada_3); 
            minuto01 /= 1 + quantidade_dose_dosadora_3_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_3_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = NumMins(hora_inicial_dosagem_personalizada_3, minuto_inicial_dosagem_personalizada_3) + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }
      }      
      if(bitRead(dosadora_selecionada,4) == true)
      {
        if ((x >= minUT[0]) && (x <= minUT[2]) && (y >= minUT[1]) && (y <= minUT[3])) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          dose_dosadora_4_personalizada_temp2 += 0.5;
          if(dose_dosadora_4_personalizada_temp2 > 999.5)
          {
            dose_dosadora_4_personalizada_temp2 = 0.5;
          }
          if(dose_dosadora_4_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }           

          config_dosagem_personalizada_2();
        }
        if ((x >= minDT[0]) && (x <= minDT[2]) && (y >= minDT[1]) && (y <= minDT[3])) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          dose_dosadora_4_personalizada_temp2 -= 0.5;
          if(dose_dosadora_4_personalizada_temp2 <0.5)
          {
            dose_dosadora_4_personalizada_temp2 = 999.5;
          }
          if(dose_dosadora_4_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= durC[0]) && (x <= durC[2]) && (y >= durC[1]) && (y <= durC[3])) 
        {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          quantidade_dose_dosadora_4_personalizada_temp2 += 1;
          if(quantidade_dose_dosadora_4_personalizada_temp2 > 24)
          {
            quantidade_dose_dosadora_4_personalizada_temp2 = 1;
          }
          config_dosagem_personalizada_2();
        }

        if ((x >= durB[0]) && (x <= durB[2]) && (y >= durB[1]) && (y <= durB[3])) 
        {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          quantidade_dose_dosadora_4_personalizada_temp2 -= 1;
          if(quantidade_dose_dosadora_4_personalizada_temp2 < 1)
          {
            quantidade_dose_dosadora_4_personalizada_temp2 = 24;
          }
          config_dosagem_personalizada_2();        
        }
        if ((x >= sexT[0]) && (x<= sexT[2]) && (y >= sexT [1]) && (y <= sexT[3])) // Ativar ou desativar modo personalizado
        {
          waitForIt(sexT[0], sexT[1], sexT[2], sexT[3]);
          if(modo_personalizado_on_4_temp2 == 0)
          {
            modo_personalizado_on_4_temp2 = 1;
            config_dosagem_personalizada_2();
          }
          else
          {
            modo_personalizado_on_4_temp2 = 0;
            config_dosagem_personalizada_2();
          }
        }
        if ((y >= prOK[1]) && (y <= prOK[3]) && (x >= prOK[0]) && (x <= prOK[2])) 
        {
          waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
          dose_dosadora_4_personalizada = dose_dosadora_4_personalizada_temp2;
          quantidade_dose_dosadora_4_personalizada = quantidade_dose_dosadora_4_personalizada_temp2;
          bitWrite(modo_personalizado_on,4 , modo_personalizado_on_4_temp2);
          hora_inicial_dosagem_personalizada_4 = temp2hora_inicial_dosagem_personalizada_4;
          minuto_inicial_dosagem_personalizada_4 = temp2minuto_inicial_dosagem_personalizada_4;
          hora_final_dosagem_personalizada_4 = temp2hora_final_dosagem_personalizada_4;
          minuto_final_dosagem_personalizada_4 = temp2minuto_final_dosagem_personalizada_4;
          bitWrite(segunda_dosagem_personalizada,4,temp2segunda_dosagem_personalizada_4);
          terca_dosagem_personalizada_4 = temp2terca_dosagem_personalizada_4;
          quarta_dosagem_personalizada_4 = temp2quarta_dosagem_personalizada_4;
          quinta_dosagem_personalizada_4 = temp2quinta_dosagem_personalizada_4;
          sexta_dosagem_personalizada_4 = temp2sexta_dosagem_personalizada_4;
          sabado_dosagem_personalizada_4 = temp2sabado_dosagem_personalizada_4;
          domingo_dosagem_personalizada_4 = temp2domingo_dosagem_personalizada_4;

          if((hora_final_dosagem_personalizada_4 == hora_inicial_dosagem_personalizada_4) && (minuto_final_dosagem_personalizada_4 < (minuto_inicial_dosagem_personalizada_4+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[176])));            
            myGLCD.print(buffer, 20, 110); // "O INTERVALO ENTRE A INICIAL E A FINAL"

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[177]))); 
            myGLCD.print(buffer, 35, 130);

          }
          if(hora_final_dosagem_personalizada_4 < hora_inicial_dosagem_personalizada_4)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[178]))); 
            myGLCD.print(buffer, 50, 110);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[179]))); 
            myGLCD.print(buffer, 100, 130);
          }

          if((temp2hora_final_dosagem_personalizada_4 == hora_inicial_dosagem_personalizada_4) && (temp2minuto_final_dosagem_personalizada_4 >= (minuto_inicial_dosagem_personalizada_4+10)))
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171]))); 
            myGLCD.print(buffer, 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"

            modo_manual = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_selecionada = 0x0;
            digitalWrite (4, LOW); 
            file.open(&root, "HDP4.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP4.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = NumMins(hora_final_dosagem_personalizada_4, minuto_final_dosagem_personalizada_4) - NumMins(hora_inicial_dosagem_personalizada_4, minuto_inicial_dosagem_personalizada_4); 
            minuto01 /= 1 + quantidade_dose_dosadora_4_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_4_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = NumMins(hora_inicial_dosagem_personalizada_4, minuto_inicial_dosagem_personalizada_4) + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(temp2hora_final_dosagem_personalizada_4 > hora_inicial_dosagem_personalizada_4)
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171]))); 
            myGLCD.print(buffer, 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"


            modo_manual = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_selecionada = 0x0;
            digitalWrite (4, LOW); 
            file.open(&root, "HDP4.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP4.TXT", O_CREAT | O_APPEND | O_WRITE);

            if((minuto_inicial_dosagem_personalizada_4 == minuto_inicial_dosagem_personalizada_5) || (minuto_inicial_dosagem_personalizada_4 == minuto_inicial_dosagem_personalizada_6))
            {
              minuto_inicial_dosagem_personalizada_4 += 10;
            }
            if(minuto_inicial_dosagem_personalizada_4 >= 60)
            {
              minuto_inicial_dosagem_personalizada_4 -= 60;
              hora_inicial_dosagem_personalizada_4 += 1;
            }
            minuto01 = NumMins(hora_final_dosagem_personalizada_4, minuto_final_dosagem_personalizada_4) - NumMins(hora_inicial_dosagem_personalizada_4, minuto_inicial_dosagem_personalizada_4); 
            minuto01 /= 1 + quantidade_dose_dosadora_4_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_4_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = NumMins(hora_inicial_dosagem_personalizada_4, minuto_inicial_dosagem_personalizada_4) + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        } 
      }      
      if(bitRead(dosadora_selecionada,5) == true)
      {
        if ((x >= minUT[0]) && (x <= minUT[2]) && (y >= minUT[1]) && (y <= minUT[3])) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          dose_dosadora_5_personalizada_temp2 += 0.5;
          if(dose_dosadora_5_personalizada_temp2 > 999.5)
          {
            dose_dosadora_5_personalizada_temp2 = 0.5;
          }
          if(dose_dosadora_5_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= minDT[0]) && (x <= minDT[2]) && (y >= minDT[1]) && (y <= minDT[3])) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          dose_dosadora_5_personalizada_temp2 -= 0.5;
          if(dose_dosadora_5_personalizada_temp2 <0.5)
          {
            dose_dosadora_5_personalizada_temp2 = 999.5;
          }
          if(dose_dosadora_5_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= durC[0]) && (x <= durC[2]) && (y >= durC[1]) && (y <= durC[3])) 
        {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          quantidade_dose_dosadora_5_personalizada_temp2 += 1;
          if(quantidade_dose_dosadora_5_personalizada_temp2 > 24)
          {
            quantidade_dose_dosadora_5_personalizada_temp2 = 1;
          }
          config_dosagem_personalizada_2();
        }

        if ((x >= durB[0]) && (x <= durB[2]) && (y >= durB[1]) && (y <= durB[3])) 
        {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          quantidade_dose_dosadora_5_personalizada_temp2 -= 1;
          if(quantidade_dose_dosadora_5_personalizada_temp2 < 1)
          {
            quantidade_dose_dosadora_5_personalizada_temp2 = 24;
          }
          config_dosagem_personalizada_2();        
        }
        if ((x >= sexT[0]) && (x<= sexT[2]) && (y >= sexT [1]) && (y <= sexT[3]))
        {
          waitForIt(sexT[0], sexT[1], sexT[2], sexT[3]);
          if(modo_personalizado_on_5_temp2 == 0)
          {
            modo_personalizado_on_5_temp2 = 1;
            config_dosagem_personalizada_2();
          }
          else
          {
            modo_personalizado_on_5_temp2 = 0;
            config_dosagem_personalizada_2();
          }
        }
        if ((y >= prOK[1]) && (y <= prOK[3]) && (x >= prOK[0]) && (x <= prOK[2])) 
        {
          waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
          dose_dosadora_5_personalizada = dose_dosadora_5_personalizada_temp2;
          quantidade_dose_dosadora_5_personalizada = quantidade_dose_dosadora_5_personalizada_temp2;
          bitWrite(modo_personalizado_on,5 , modo_personalizado_on_5_temp2);
          hora_inicial_dosagem_personalizada_5 = temp2hora_inicial_dosagem_personalizada_5;
          minuto_inicial_dosagem_personalizada_5 = temp2minuto_inicial_dosagem_personalizada_5;
          hora_final_dosagem_personalizada_5 = temp2hora_final_dosagem_personalizada_5;
          minuto_final_dosagem_personalizada_5 = temp2minuto_final_dosagem_personalizada_5;
          bitWrite(segunda_dosagem_personalizada,5,temp2segunda_dosagem_personalizada_5);
          terca_dosagem_personalizada_5 = temp2terca_dosagem_personalizada_5;
          quarta_dosagem_personalizada_5 = temp2quarta_dosagem_personalizada_5;
          quinta_dosagem_personalizada_5 = temp2quinta_dosagem_personalizada_5;
          sexta_dosagem_personalizada_5 = temp2sexta_dosagem_personalizada_5;
          sabado_dosagem_personalizada_5 = temp2sabado_dosagem_personalizada_5;
          domingo_dosagem_personalizada_5 = temp2domingo_dosagem_personalizada_5;

          if((hora_final_dosagem_personalizada_5 == hora_inicial_dosagem_personalizada_5) && (minuto_final_dosagem_personalizada_5 < (minuto_inicial_dosagem_personalizada_5+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[176]))); 
            myGLCD.print(buffer, 20, 110);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[177]))); 
            myGLCD.print(buffer, 35, 130);
          }
          if(hora_final_dosagem_personalizada_5 < hora_inicial_dosagem_personalizada_5)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[178]))); 
            myGLCD.print(buffer, 50, 110); // "A HORA FINAL NAO PODE SER MENOR"

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[179]))); 
            myGLCD.print(buffer, 100, 130); // tabela_textos[179] = "QUE A INICIAL!"
          }

          if((temp2hora_final_dosagem_personalizada_5 == hora_inicial_dosagem_personalizada_5) && (temp2minuto_final_dosagem_personalizada_5 >= (minuto_inicial_dosagem_personalizada_5+10)))
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171]))); 
            myGLCD.print(buffer, 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"

            modo_manual = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_selecionada = 0x0;
            digitalWrite (4, LOW); 
            file.open(&root, "HDP5.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP5.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = NumMins(hora_final_dosagem_personalizada_5, minuto_final_dosagem_personalizada_5) - NumMins(hora_inicial_dosagem_personalizada_5, minuto_inicial_dosagem_personalizada_5); 
            minuto01 /= 1 + quantidade_dose_dosadora_5_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_5_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = NumMins(hora_inicial_dosagem_personalizada_5, minuto_inicial_dosagem_personalizada_5) + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(temp2hora_final_dosagem_personalizada_5 > hora_inicial_dosagem_personalizada_5)
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171]))); 
            myGLCD.print(buffer, 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"

            modo_manual = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_selecionada = 0x0;
            digitalWrite (4, LOW); 
            file.open(&root, "HDP5.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP5.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = NumMins(hora_final_dosagem_personalizada_5, minuto_final_dosagem_personalizada_5) - NumMins(hora_inicial_dosagem_personalizada_5, minuto_inicial_dosagem_personalizada_5); 
            minuto01 /= 1 + quantidade_dose_dosadora_5_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_5_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = NumMins(hora_inicial_dosagem_personalizada_5, minuto_inicial_dosagem_personalizada_5) + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }      
      }
      if(bitRead(dosadora_selecionada,6) == true)
      {
        if ((x >= minUT[0]) && (x <= minUT[2]) && (y >= minUT[1]) && (y <= minUT[3])) // Dose diaria mais
        {
          waitForIt(minUT[0], minUT[1], minUT[2], minUT[3]);
          dose_dosadora_6_personalizada_temp2 += 0.5;
          if(dose_dosadora_6_personalizada_temp2 > 999.5)
          {
            dose_dosadora_6_personalizada_temp2 = 0.5;
          }
          if(dose_dosadora_6_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= minDT[0]) && (x <= minDT[2]) && (y >= minDT[1]) && (y <= minDT[3])) // Dose diaria menos
        {
          waitForIt(minDT[0], minDT[1], minDT[2], minDT[3]);
          dose_dosadora_6_personalizada_temp2 -= 0.5;
          if(dose_dosadora_6_personalizada_temp2 <0.5)
          {
            dose_dosadora_6_personalizada_temp2 = 999.5;
          }
          if(dose_dosadora_6_personalizada_temp2 <= 9.5)
          {
            myGLCD.setColor(0, 0, 0);                      
            myGLCD.fillRect(100, 45, 185, 67);
          }
          config_dosagem_personalizada_2();
        }
        if ((x >= durC[0]) && (x <= durC[2]) && (y >= durC[1]) && (y <= durC[3])) 
        {
          waitForIt(durC[0], durC[1], durC[2], durC[3]); 
          quantidade_dose_dosadora_6_personalizada_temp2 += 1;
          if(quantidade_dose_dosadora_6_personalizada_temp2 > 24)
          {
            quantidade_dose_dosadora_6_personalizada_temp2 = 1;
          }
          config_dosagem_personalizada_2();
        }

        if ((x >= durB[0]) && (x <= durB[2]) && (y >= durB[1]) && (y <= durB[3])) 
        {
          waitForIt(durB[0], durB[1], durB[2], durB[3]);
          quantidade_dose_dosadora_6_personalizada_temp2 -= 1;
          if(quantidade_dose_dosadora_6_personalizada_temp2 < 1)
          {
            quantidade_dose_dosadora_6_personalizada_temp2 = 24;
          }
          config_dosagem_personalizada_2();        
        }
        if ((x >= sexT[0]) && (x<= sexT[2]) && (y >= sexT [1]) && (y <= sexT[3]))
        {
          waitForIt(sexT[0], sexT[1], sexT[2], sexT[3]);
          if(modo_personalizado_on_6_temp2 == 0)
          {
            modo_personalizado_on_6_temp2 = 1;
            config_dosagem_personalizada_2();
          }
          else
          {
            modo_personalizado_on_6_temp2 = 0;
            config_dosagem_personalizada_2();
          }
        }
        if ((y >= prOK[1]) && (y <= prOK[3]) && (x >= prOK[0]) && (x <= prOK[2])) 
        {
          waitForIt(prOK[0], prOK[1], prOK[2], prOK[3]); //funcao salvar
          dose_dosadora_6_personalizada = dose_dosadora_6_personalizada_temp2;
          quantidade_dose_dosadora_6_personalizada = quantidade_dose_dosadora_6_personalizada_temp2;
          bitWrite(modo_personalizado_on,6 , modo_personalizado_on_6_temp2);
          hora_inicial_dosagem_personalizada_6 = temp2hora_inicial_dosagem_personalizada_6;
          minuto_inicial_dosagem_personalizada_6 = temp2minuto_inicial_dosagem_personalizada_6;
          hora_final_dosagem_personalizada_6 = temp2hora_final_dosagem_personalizada_6;
          minuto_final_dosagem_personalizada_6 = temp2minuto_final_dosagem_personalizada_6;
          bitWrite(segunda_dosagem_personalizada,6,temp2segunda_dosagem_personalizada_6);
          terca_dosagem_personalizada_6 = temp2terca_dosagem_personalizada_6;
          quarta_dosagem_personalizada_6 = temp2quarta_dosagem_personalizada_6;
          quinta_dosagem_personalizada_6 = temp2quinta_dosagem_personalizada_6;
          sexta_dosagem_personalizada_6 = temp2sexta_dosagem_personalizada_6;
          sabado_dosagem_personalizada_6 = temp2sabado_dosagem_personalizada_6;
          domingo_dosagem_personalizada_6 = temp2domingo_dosagem_personalizada_6;
          if((hora_final_dosagem_personalizada_6 == hora_inicial_dosagem_personalizada_6) && (minuto_final_dosagem_personalizada_6 < (minuto_inicial_dosagem_personalizada_6+10)))
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[176]))); 
            myGLCD.print(buffer, 20, 110);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[177]))); 
            myGLCD.print(buffer, 35, 130); // tabela_textos[177] = "DEVE SER DE NO MINIMO 10 MINUTOS!"
          }
          if(hora_final_dosagem_personalizada_6 < hora_inicial_dosagem_personalizada_6)
          {
            setFont(SMALL, 255, 0, 0, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[178]))); 
            myGLCD.print(buffer, 50, 110); // tabela_textos[178] = "A HORA FINAL NAO PODE SER MENOR"

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[179]))); 
            myGLCD.print(buffer, 100, 130); // tabela_textos[179] = "QUE A INICIAL!" 
          }

          if((temp2hora_final_dosagem_personalizada_6 == hora_inicial_dosagem_personalizada_6) && (temp2minuto_final_dosagem_personalizada_6 >= (minuto_inicial_dosagem_personalizada_6+10)))
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171]))); 
            myGLCD.print(buffer, 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"

            modo_manual = false;
            modo_personalizado = true;
            modo_calibrar = false; 
            digitalWrite (4, LOW); 
            file.open(&root, "HDP6.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP6.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = NumMins(hora_final_dosagem_personalizada_6, minuto_final_dosagem_personalizada_6) - NumMins(hora_inicial_dosagem_personalizada_6, minuto_inicial_dosagem_personalizada_6); 
            minuto01 /= 1 + quantidade_dose_dosadora_6_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_6_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = NumMins(hora_inicial_dosagem_personalizada_6, minuto_inicial_dosagem_personalizada_6) + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM(); 
          }    

          if(temp2hora_final_dosagem_personalizada_6 > hora_inicial_dosagem_personalizada_6)
          {
            dispScreen =21;
            clearScreen();
            selecionar_dosadora();
            setFont(SMALL, 255, 255, 255, 0, 0, 0);

            strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[171]))); 
            myGLCD.print(buffer, 15, 220); // tabela_textos[171] = "MODO PERSONALIZADO SELECIONADO"

            modo_manual = false;
            modo_personalizado = true;
            modo_calibrar = false;
            dosadora_selecionada = 0x0;
            digitalWrite (4, LOW); 
            file.open(&root, "HDP6.TXT", O_WRITE);
            file.remove();       
            file.open(&root, "HDP6.TXT", O_CREAT | O_APPEND | O_WRITE);

            minuto01 = NumMins(hora_final_dosagem_personalizada_6, minuto_final_dosagem_personalizada_6) - NumMins(hora_inicial_dosagem_personalizada_6, minuto_inicial_dosagem_personalizada_6); 
            minuto01 /= 1 + quantidade_dose_dosadora_6_personalizada;

            for(int i = 1; i <= quantidade_dose_dosadora_6_personalizada; i++)
            { 
              contador += 1;  
              if(contador == 1)
              {
                minuto11 = NumMins(hora_inicial_dosagem_personalizada_6, minuto_inicial_dosagem_personalizada_6) + minuto01;
              }
              if(contador > 1)
              {
                minuto11 += minuto01; 
              }
              if(minuto11 < 10)
              {
                file.print("000");  
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 > 10) && (minuto11 < 100))
              {
                file.print("00");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(( minuto11 >= 100) && (minuto11 < 1000))
              {
                file.print("0");
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
              else if(minuto11 >= 1000)
              {
                file.print(minuto11);
                file.write((uint8_t*)"\0", 1);
                writeCRLF(file);
              }
            }
            file.close();  
            contador = 0;
            digitalWrite (4, HIGH);
            Salvar_dosadora_EEPROM();
          }         
        }
      }      
      break;
    case 32: // -------------------------------- Rever configuração das dosadoras ------------------------------------------
      if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen(); 
      }
      if ((x>=volT[0]) && (x<=volT[2]) && (y>=volT[1]) && (y<=volT[3]))           // volta ao menu das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=8;
        clearScreen();
        menu_dosadoras();
      }
      if ((x>=manU[0]) && (x<=manU[2]) && (y>=manU[1]) && (y<=manU[3]))           // Rever configuração dosagem personalizada
      {
        waitForIt(manU[0], manU[1], manU[2], manU[3]);
        dispScreen = 34;
        clearScreen();
        rever_dosagem_personalizada();
      }  
      break;     
    case 34:// -------------------------------- Rever configuração das dosadoras personalizado ------------------------------------------
      if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen();    
      }
      if ((x>=volT[0]) && (x<=volT[2]) && (y>=volT[1]) && (y<=volT[3]))           // volta ao menu de revisão das dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen=32;
        clearScreen();
        rever_configuracao_dosadoras();
      }
      if ((x>=salV[0]) && (x<=salV[2]) && (y>=salV[1]) && (y<=salV[3]))           // Mais dosadoras
      {
        waitForIt(salV[0], salV[1], salV[2], salV[3]);
        dispScreen=23;
        clearScreen();
        rever_dosagem_personalizada_2();
      }
      break;
    case 35:// -------------------------------------- Desativar dosadoras ------------------------------------------
      if ((x>=menU[0]) && (x<=menU[2]) && (y>=menU[1]) && (y<=menU[3]))           // volta ao menu
      {
        waitForIt(menU[0], menU[1], menU[2], menU[3]);
        dispScreen = 1;
        clearScreen();
        menuScreen();    
      }
      if ((x>=volT[0]) && (x<=volT[2]) && (y>=volT[1]) && (y<=volT[3]))           // volta ao menu desativar dosadoras
      {
        waitForIt(volT[0], volT[1], volT[2], volT[3]);
        dispScreen = 8;
        clearScreen();
        menu_dosadoras();
      }
      if ((x>=deS[0]) && (x<=deS[2]) && (y>=deS[1]) && (y<=deS[3]))           // volta ao menu desativar dosadoras
      {
        waitForIt(deS[0], deS[1], deS[2], deS[3]);
        dispScreen = 24;
        clearScreen();
        desativar_dosadoras_2(true);
      }
      if ((x >= 100) && (x <= 220) && (y >= 45) && (y <= 85))           //Ativar/desatiavr dosadora 1
      {
        waitForIt(100, 45, 220, 85);

        if(bitRead(ativar_desativar,1) == true)
        {
          bitWrite(ativar_desativar,1, 0);
          desativar_dosadoras();
        }
        else
        {
          desativar_dosadoras(true);
        }          
      }
      if ((x >= 100) && (x <= 220) && (y >= 115) && (y <= 155))           //Ativar/desatiavr dosadora 2
      {
        waitForIt(100, 115, 220, 155);

        if(bitRead(ativar_desativar,2) == true)
        {
          bitWrite(ativar_desativar,2, 0);
          desativar_dosadoras();
        }
        else
        {
          desativar_dosadoras(true);
        }          
      }
      if ((x >= 100) && (x <= 220) && (y >= 185) && (y <= 225))           //Ativar/desatiavr dosadora 3
      {
        waitForIt(100, 185, 220, 225);

        if(bitRead(ativar_desativar,3) == true)
        {
          bitWrite(ativar_desativar,3, 0);
          desativar_dosadoras();
        }
        else
        {
          desativar_dosadoras(true);
        }          
      }
      if ((x>=salV[0]) && (x<=salV[2]) && (y>=salV[1]) && (y<=salV[3]))           //Salvar alterações
      {
        waitForIt(salV[0], salV[1], salV[2], salV[3]);
        if(bitRead(ativar_desativar,1) == false)
        {
          bitWrite(modo_personalizado_on,1, 0);
        }
        if(bitRead(ativar_desativar,2) == false)
        {
          bitWrite(modo_personalizado_on,2, 0);
        }
        if(bitRead(ativar_desativar,3) == false)
        {
          bitWrite(modo_personalizado_on,3, 0);
        }
        Salvar_dosadora_EEPROM(); 
        dispScreen = 0;
        clearScreen();
        mainScreen(true);       
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
            temporizador_1_ativado_temp2 = 1; Serial.println("temporizador activado = 1");
          }
          else if(temporizador_1_ativado_temp2 == 1)
          {
            temporizador_1_ativado_temp2 = 2; Serial.println("temporizador activado = 2");
          }
          else if (temporizador_1_ativado_temp2 == 2)
          {
            temporizador_1_ativado_temp2 = 0; Serial.println("temporizador activado = 0");
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
        if ((x>=tanD[0]) && x<=tanD[2] && (y>=tanD[1]) && (y<=tanD[3]))           // Testar leds
      {
        waitForIt(tanD[0], tanD[1], tanD[2], tanD[3]);   
        dispScreen=25;
        clearScreen();
        probar_leds();
      }      

      if ((x>=tesT[0]) && x<=tesT[2] && (y>=tesT[1]) && (y<=tesT[3]))           // Configurar fotoperiodo
      {

      led_on_minuto_t =led_on_minuto; 
      led_on_hora_t = led_on_hora;
      led_off_minuto_t = led_off_minuto; 
      led_off_hora_t = led_off_hora;
      amanecer_anochecer_t = amanecer_anochecer;
      pwm_percent_t = pwm_percent;
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
          pwm_percent = pwm_percent_t;
          pwm_absoluto = map(pwm_percent, 0, 100, 0, 255);
          SaveLEDToEEPROM();
        }        
        
        
        if ((x >= 30) && (x <= 55) && (y >= 45) && (y <= 70))           // Hora AMANECER mas 
        {
          waitForIt(30, 45, 55, 70);
          led_on_hora_t += 1;
          if(led_on_hora_t > 23)
          {
            led_on_hora_t = 0;
          }
          fotoperiodo();
        } 
        else if ((x >= 30) && (x <= 55) && (y >= 105) && (y <= 130))           // Hora AMANECER menos
        {
          waitForIt(30, 105, 55, 130);
          led_on_hora_t -= 1;
          if(led_on_hora_t < 0)  
          {
            led_on_hora_t = 23;
          }
          fotoperiodo();
        } 

        else if ((x >= 100) && (x <= 125) && (y >= 45) && (y <= 70))           // Minuto AMANECER mais 
        {
          waitForIt(100, 45, 125, 70);
          led_on_minuto_t += 5;
          if(led_on_minuto_t > 59)
          {
            led_on_minuto_t = 0;
          }
          fotoperiodo();
        } 
        else if ((x >= 100) && (x <= 125) && (y >= 105) && (y <= 130))           // Minuto AMANECER menos
        {
          waitForIt(100, 105, 125, 130);
          led_on_minuto_t -= 5;
          if(led_on_minuto_t < 0) 
          {
            led_on_minuto_t = 55;
          }
          fotoperiodo();
        }
        else if ((x >= 195) && (x <= 220) && (y >= 45) && (y <= 70))           // Hora ANOCHECER mas 
        {
          waitForIt(195, 45, 220, 70);
          led_off_hora_t += 1;
          if(led_off_hora_t > 23)
          {
            led_off_hora_t = 0;
          }
          fotoperiodo();
        } 
        else if ((x >= 195) && (x <= 220) && (y >= 105) && (y <= 130))           // Hora ANOCHECER menos
        {
          waitForIt(195, 105, 220, 130);
          led_off_hora_t -= 1;
          if(led_off_hora_t < 0) 
          {
            led_off_hora_t = 23;
          }
          fotoperiodo();
        } 

        else if ((x >= 265) && (x <= 290) && (y >= 45) && (y <= 70))           // Minuto ANOCHECER mas 
        {
          waitForIt(265, 45, 290, 70);
          led_off_minuto_t += 5;
          if(led_off_minuto_t > 59)
          {
            led_off_minuto_t = 0;
          }
          fotoperiodo();
        } 
        else if ((x >= 265) && (x <= 290) && (y >= 105) && (y <= 130))           // Minuto ANOCHECER menos
        {
          waitForIt(265, 105, 290, 130);
          led_off_minuto_t -= 5;
          if(led_off_minuto_t < 0) // 0 - 1 = 255 pois, byte varia de  0 a 255. 
          {
            led_off_minuto_t = 55;
          }
          fotoperiodo();
        }
        else if ((x >= 110) && (x <= 135) && (y >= 175) && (y <= 200))           // Amanecer/anochecer mas 
        {
          waitForIt(265, 45, 290, 70);
          amanecer_anochecer_t += 5;
          if(amanecer_anochecer_t > 120)
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
            amanecer_anochecer_t = 120;
          }
          fotoperiodo();
        }

        else if((x >= 275) && (x <= 300) && (y >= 175) && (y <= 200)) // PWM +
            {
              pwm_percent_t += 10;
              if(pwm_percent_t > 100){ pwm_percent_t = 0;}
               
              fotoperiodo(); 
            }
            else if((x >= 185) && (x <= 210) && (y >= 175) && (y <= 200)) // PWM -
            {
              pwm_percent_t -= 10;
              if(pwm_percent_t < 9) 
              {
              pwm_percent_t = 100;
              }
              fotoperiodo();
            }        
      break; 

    }
  }
}


