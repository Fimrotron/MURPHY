//Firmaware of MURPHY Vers. BreathCycle_4.0_SPI
//This Code was written and designed by Anton Schlünz

#include <SPI.h>
#include <TMCStepper.h>
#include <AccelStepper.h>
#include "Parameters.h"
#include "SetUp.h"
#include "MoveFunctions.h"
#include  "Background.h"


void setup() {

  Serial.begin(115200);
  Serial.println("Das Programm ist gestartet");

  //setPinmodes
    setPinModes();

  // begin SPI connection
    SPI.begin();

  //set up MotorDriver
    driverSetup();

  //calc times
    calcPar();

    //attachInterrupt(driver.LOST_STEPS(), homingKalibration(), RISING);

    Serial.println("Alle Setups wurden durchgeführt");

  //homing
    //homing();

    Serial.println("Starten des Kalibrierungsmodus");
    homingKalibration();

}

void loop() {
      
        setMode();


        digitalWrite(EN_PIN, LOW);   // Motor enabled

        MotorStatus();

        //if(driver.LOST_STEPS()>=1)Serial.println("STEPS DURCHGERUTSCHT!");else Serial.println("i.0.");
        Serial.println(driver.LOST_STEPS());

         if (mode == 1){
          modeOne();
        }
          else if (mode == 2){
            modeTwo(random(dist_min,dist_max), random(tir_min,tir_max), random(ter_min,ter_max));
          }
          else if (mode == 3){
            modeThree();
          }
          else if (mode == 4){
            modeFour();
          }

        //digitalWrite(EN_PIN, HIGH);     // Motor disable

}
