/*
 *  SetUpFunctions.h
 *  In this file all the needed Parameters are defined that are needed for starting a motion with the Phantom
 *
 *  created by Anton Schlünz
 *
 */

 // ---------------------------- Includes ---------------------------------//

  /* Dont change this Values */
  #include "UserSettings.h"


 // ------------------------ Define functions -----------------------------//

   void init_Driver_GPIO(){

  //set Enable and Chip Select Pin to Output
    pinMode(EN_PIN, OUTPUT);      //Enable Pin --> to enable the motor EN_PIN=LOW
    digitalWrite(EN_PIN, HIGH);   //Set to normaly HIGH

    pinMode(CS_PIN, OUTPUT);      //Chip select pin
    digitalWrite(CS_PIN, LOW);    //Chip select pin set to normaly LOW

  //init GPIO
    pinMode(ModeSwitch, INPUT_PULLUP);      //Implement the mode switch --> high in 0 and low is switched


  // ------------- Stepper Settings -------------- //
  
	  stepper.setMaxSpeed(15000);   
	  stepper.setAcceleration(16000);
	  stepper.setEnablePin(EN_PIN);
	  stepper.setPinsInverted(false, false, false);

    driver.begin();
	  // driver.setSPISpeed(4000000);
    driver.chm(1);           //chopper mode: 0: spreadCycle. 1: stealthChop
      driver.toff(12);     //3
	  driver.intpol(1);           // 1: enabled microstepping interpolation up to 256, 0: disabled
	  driver.blank_time(24);
	  driver.rms_current(1400);    // mA
	  driver.microsteps(16);      // 0: Fullstep, 2: halfstep 4: quarters teps 16: sixteenth
	  driver.TCOOLTHRS(0xFFFFF); // 20bit max
	  //driver.THIGH(0);
	  //driver.semin(1);
	  //driver.semax(28);
    //driver.sedn(0);          //Coolstep; current decreasing rate
	  //driver.sfilt(0);            //  0 Standard mode, high time resolution for StallGuard2
	  // 1 Filtered mode, StallGuard2 signal updated for each four fullsteps
	  driver.sgt(5);
    driver.sfilt(0);
	  // driver.diag1_stall(1);    enable DIAG-Pin to get triggerd after stall

	  //driver.vsense(1);
	  driver.en_pwm_mode(true);    // Enable extremely quiet stepping
	  driver.pwm_autoscale(true);
  
    //Parameters for dcStep
    driver.vhighfs(1);
    driver.vhighchm(1);
    driver.VDCMIN(4194304);
    driver.tbl(1);
    //driver.VMAX(4000000);

}

void homingKalibration(){
  digitalWrite(EN_PIN, LOW);        // Motor enabled
  stepper.setAcceleration(1000);

  stepper.setSpeed(-1000);

  bool beq = false;
  int i = 0;

  while(1){
    stepper.runSpeed();
    Serial.println(driver.sg_result());
    if(driver.sg_result() < HousingImpact)beq=true; else beq = false;
    Serial.println(beq);
    if(beq == true && i>100) break;
    i++;
    Serial.println(i);
  }

  stepper.setCurrentPosition(0);

  stepper.setSpeed(1000);
  stepper.setAcceleration(1000);

  beq = false;
  i = 0;

  while(1){
    stepper.runSpeed();
    Serial.println(driver.sg_result());
    if(driver.sg_result() < PhantomImpact)beq=true; else beq = false;
    Serial.println(beq);
    if(beq == true && i>300) break;
    i++;
    Serial.println(i);
  }

  stepper.setCurrentPosition(0);
  
  digitalWrite(EN_PIN, HIGH);        // Motor disable
  
}