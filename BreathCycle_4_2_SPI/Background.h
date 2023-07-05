void calcPar(){

  //calculate Distnce
    dist  = stdStep*cm;

  //calculation for mode one
    //calculate the accelaration with a=(8*s)/(t^2)
      acc_in  =  (8*dist)/(ti*ti);
      acc_out =  (8*dist)/(te*te);

    //velocity calculation
      vel_in   =   (dist-(acc_in*ti*ti)/4)/(ti);
      vel_out  =   (dist-(acc_out*te*te)/4)/(te);

    tir_min = ti-ti*dev_ti/200;
    tir_max = ti+ti*dev_ti/200;

    ter_min = te-te*dev_te/200;
    ter_max = te+te*dev_te/200;

    dist_min = dist-dist*dev_cm/200;
    dist_max = dist+dist*dev_cm/200;

}

void  setMode(){

  bool lev_pos_1  = false;     //postion of the lever: false --> low, true --> up

  if (digitalRead(m1) == HIGH){
    lev_pos_1 = false;
  } else {
      lev_pos_1 = true;
    }

  if(lev_pos_1  ==  false){
    mode = Lev_Down;
  } else {
      mode = Lev_Up;
    }
  
  if(mode > 4){
    mode  = 1;
  }

}

void MotorStatus(){

  //set Pre-Warning-Flag
  PWF = driver.otpw();

  if(PWF == true){
    digitalWrite(EN_PIN, HIGH);   // Motor disabled
    Serial.println("WARNUNG: Systemtemperatur zu hoch! Überhitzungsvorwarnung ist aktiv.");
  }else{
    digitalWrite(EN_PIN, LOW);   // Motor enabled
    Serial.println("Systemtemperatur i.o.");
  }
  
}