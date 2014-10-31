void check_temporizadores()
{

  if (temporizador_1_ativado == 1) 
  {  
    if(NumMins(off1_hora,off1_minuto) > NumMins(on1_hora,on1_minuto))
    { 
      if((NumMins(t.hour,t.min) >= NumMins(on1_hora,on1_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off1_hora,off1_minuto)))
      {
        SetRele(temporizador1, HIGH);        // activa rele
        bitWrite(temporizador_status,1,1);
      }
      if (NumMins(t.hour,t.min) > NumMins(off1_hora,off1_minuto))
      {
        SetRele(temporizador1, LOW);       // desactiva rele
        bitWrite(temporizador_status,1,0);
      }
    }
    if(NumMins(off1_hora,off1_minuto) < NumMins(on1_hora,on1_minuto))
    {                     
      if(NumMins(t.hour,t.min) >= NumMins(on1_hora,on1_minuto)) 
      {
        SetRele(temporizador1, HIGH);          // activa rele
        bitWrite(temporizador_status,1,1);
      }

      if (NumMins(t.hour,t.min) < NumMins(off1_hora,off1_minuto)) 
      {
        SetRele(temporizador1, HIGH);          //  ACTIVA RELE
        bitWrite(temporizador_status,1,1);
      }     
      if ((NumMins(t.hour,t.min) >= NumMins(off1_hora,off1_minuto)) && (NumMins(t.hour,t.min) < NumMins(on1_hora,on1_minuto)))
      {
        SetRele(temporizador1, LOW);         // desactiva rele
        bitWrite(temporizador_status,1,0);
      } 
    }
  }
  else if (temporizador_1_ativado == 2)
  {
    SetRele(temporizador1, HIGH);             // activa rele
    bitWrite(temporizador_status,1,1);
  }
  else
  {
    SetRele(temporizador1, LOW);            // desactiva rele
    bitWrite(temporizador_status,1,0);
  }
///////////////////////////////////////////////////////////  TEMPORIZADOR 2

  if (temporizador_2_ativado == 1) 
  {
    if(NumMins(off2_hora,off2_minuto) > NumMins(on2_hora,on2_minuto))
    {
      if((NumMins(t.hour,t.min) >= NumMins(on2_hora,on2_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off2_hora,off2_minuto)))
      {
        SetRele(temporizador2, HIGH);          //  ACTIVA RELE
        bitWrite(temporizador_status,2,1);
      }
      if (NumMins(t.hour,t.min) > NumMins(off2_hora,off2_minuto))
      {
        SetRele(temporizador2, LOW);         // desactiva rele
        bitWrite(temporizador_status,2,0);
      }
    }
    if(NumMins(off2_hora,off2_minuto) < NumMins(on2_hora,on2_minuto))
    {                     
      if(NumMins(t.hour,t.min) >= NumMins(on2_hora,on2_minuto)) 
      {
        SetRele(temporizador2, HIGH);          //  Activa rele
        bitWrite(temporizador_status,2,1);
      }

      if (NumMins(t.hour,t.min) < NumMins(off2_hora,off2_minuto)) 
      {
        SetRele(temporizador2, HIGH);        // Activa rele
        bitWrite(temporizador_status,2,1);
      }     
      if ((NumMins(t.hour,t.min) >= NumMins(off2_hora,off2_minuto)) && (NumMins(t.hour,t.min) < NumMins(on2_hora,on2_minuto)))
      {
        SetRele(temporizador2, LOW);       // desactiva rele
        bitWrite(temporizador_status,2,0);
      } 
    }
  }
  else if (temporizador_2_ativado == 2)
  {
    SetRele(temporizador2, HIGH);            // activa rele
    bitWrite(temporizador_status,2,1);
  }
  else
  {
    SetRele(temporizador2, LOW);           // desactiva rele
    bitWrite(temporizador_status,2,0);
  } 
  if (temporizador_3_ativado == 1) 
  {  
    if(NumMins(off3_hora,off3_minuto) > NumMins(on3_hora,on3_minuto))
    {
      if((NumMins(t.hour,t.min) >= NumMins(on3_hora,on3_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off3_hora,off3_minuto)))
      {
        SetRele(temporizador3, HIGH);          //  Activa rele
        bitWrite(temporizador_status,3,1);
      }
      if (NumMins(t.hour,t.min) > NumMins(off3_hora,off3_minuto))
      {
        SetRele(temporizador3, LOW);          //  desactiva rele
        bitWrite(temporizador_status,3,0);
      }
    }
    if(NumMins(off3_hora,off3_minuto) < NumMins(on3_hora,on3_minuto))
    {                     
      if(NumMins(t.hour,t.min) >= NumMins(on3_hora,on3_minuto)) 
      {
        SetRele(temporizador3, HIGH);          //  Activa rele
        bitWrite(temporizador_status,3,1);
      }

      if (NumMins(t.hour,t.min) < NumMins(off3_hora,off3_minuto)) 
      {
        SetRele(temporizador3, HIGH);          //  Activa rele
        bitWrite(temporizador_status,3,1);
      }     
      if ((NumMins(t.hour,t.min) >= NumMins(off3_hora,off3_minuto)) && (NumMins(t.hour,t.min) < NumMins(on3_hora,on3_minuto)))
      {
        SetRele(temporizador3, LOW);          //  desactiva rele
        bitWrite(temporizador_status,3,0);
      } 
    }
  }
  else if (temporizador_3_ativado == 2)
  {
    SetRele(temporizador3, HIGH);          //  Activa rele
    bitWrite(temporizador_status,3,1);
  }
  else
  {
    SetRele(temporizador3, LOW);          //  desactiva rele
    bitWrite(temporizador_status,3,0);
  } 
  if (temporizador_4_ativado == 1) 
  {  
    if(NumMins(off4_hora,off4_minuto) > NumMins(on4_hora,on4_minuto))
    {
      if((NumMins(t.hour,t.min) >= NumMins(on4_hora,on4_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off4_hora,off4_minuto)))
      {
        SetRele(temporizador4, HIGH);          //  Activa rele
        bitWrite(temporizador_status,4,1);
      }
      if (NumMins(t.hour,t.min) > NumMins(off4_hora,off4_minuto))
      {
        SetRele(temporizador4, LOW);          //  desactiva rele
        bitWrite(temporizador_status,4,0);
      }
    }
    if(NumMins(off4_hora,off4_minuto) < NumMins(on4_hora,on4_minuto))
    {                     
      if(NumMins(t.hour,t.min) >= NumMins(on4_hora,on4_minuto)) 
      {
        SetRele(temporizador4, HIGH);          //  Activa rele
        bitWrite(temporizador_status,4,1);
      }

      if (NumMins(t.hour,t.min) < NumMins(off4_hora,off4_minuto)) 
      {
        SetRele(temporizador4, HIGH);          //  Activa rele
        bitWrite(temporizador_status,4,1);
      }     
      if ((NumMins(t.hour,t.min) >= NumMins(off4_hora,off4_minuto)) && (NumMins(t.hour,t.min) < NumMins(on4_hora,on4_minuto)))
      {
        SetRele(temporizador4, LOW);          //  desactiva rele
        bitWrite(temporizador_status,4,0);
      } 
    }
  }
  else if (temporizador_4_ativado == 2)
  {
    SetRele(temporizador4, HIGH);          //  Activa rele
    bitWrite(temporizador_status,4,1);
  }
  else
  {
    SetRele(temporizador4, LOW);          //  desactiva rele
    bitWrite(temporizador_status,4,0);
  }
  if (temporizador_5_ativado == 1) 
  {  
    if(NumMins(off5_hora,off5_minuto) > NumMins(on5_hora,on5_minuto))
    {
      if((NumMins(t.hour,t.min) >= NumMins(on5_hora,on5_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off5_hora,off5_minuto)))
      {
        SetRele(temporizador5, HIGH);          //  Activa rele
        bitWrite(temporizador_status,5,1);
      }
      if (NumMins(t.hour,t.min) > NumMins(off5_hora,off5_minuto))
      {
        SetRele(temporizador5, LOW);          //  desactiva rele
        bitWrite(temporizador_status,5,0);
      }
    }
    if(NumMins(off5_hora,off5_minuto) < NumMins(on5_hora,on5_minuto))
    {                     
      if(NumMins(t.hour,t.min) >= NumMins(on5_hora,on5_minuto)) 
      {
        SetRele(temporizador5, HIGH);          //  Activa rele
        bitWrite(temporizador_status,5,1);
      }

      if (NumMins(t.hour,t.min) < NumMins(off5_hora,off5_minuto)) 
      {
        SetRele(temporizador5, HIGH);          //  Activa rele
        bitWrite(temporizador_status,5,1);
      }     
      if ((NumMins(t.hour,t.min) >= NumMins(off5_hora,off5_minuto)) && (NumMins(t.hour,t.min) < NumMins(on5_hora,on5_minuto)))
      {
        SetRele(temporizador5, LOW);          //  desactiva rele
        bitWrite(temporizador_status,5,0);
      } 
    }
  }
  else if (temporizador_5_ativado == 2)
  {
    SetRele(temporizador5, HIGH);          //  Activa rele
    bitWrite(temporizador_status,5,1);
  }
  else
  {
    SetRele(temporizador5, LOW);          //  desactiva rele
    bitWrite(temporizador_status,5,0);
  }   
 
}


