/*
 *  MoveFunctions.h
 *  In this file all the needed functions to the main programm
 *
 *  created by Anton Schlünz
 *
 */

 // ---------------------------- Includes ---------------------------------//

  /* Dont change this Values */
  #include "MoveFunctions.h"


void setup() {

  //Begin the serial connection
  Serial.begin(115200);
  Serial.println("Das Programm ist gestartet");

  // begin SPI connection
    SPI.begin();

  //set up MotorDriver
    init_Driver_GPIO();

  //calc times
    calcPar();

  //attachInterrupt(driver.LOST_STEPS(), homingKalibration(), RISING);
    Serial.println("Alle Setups wurden durchgeführt");
  
  //calibration
    homingKalibration();

  digitalWrite(EN_PIN, LOW);   // Motor enabled

}

void loop() {
  // put your main code here, to run repeatedly:

  setMode();

  MotorStatus();

  if (mode == 1){
          modeone();
        }
        else if (mode == 2){
            modetwo(random(dist_min,dist_max), random(tir_min,tir_max), random(ter_min,ter_max));
        }
        else if (mode == 3){
            modethree();
        }
        else if (mode == 4){
            modefour();
  }



}
