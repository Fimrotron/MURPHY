/*
 *  Configuration.h
 *  In this file U can find all the needed Hardware Parameters and std includes to run this project
 *
 *  created by Anton Schlünz
 *
 */


// ---------------------------- Includes ---------------------------------//

  #include <SPI.h>
  #include <TMCStepper.h>
  #include <AccelStepper.h>


// -------------------------- Define GPIOs -------------------------------//

    //Step and Direction Pins
      #define STEP_PIN  3   // Pin to set Steps
      #define DIR_PIN   2   // Pin to set Direction


    //nesseccary Pins
      #define SW_MOSI   11  // Software Master Out Slave In (MOSI)
      #define SW_MISO   12  // Software Master In Slave Out (MISO)
      #define SW_SCK    13  // Software Slave Clock (SCK)

      #define CS_PIN    10  // Chip select --> Shoud be set to normally LOW

      #define EN_PIN    4   // Enable Pin --> Should be set to normaly HIGH (if EN_PIN=LOW motor can drive) 

    //GPIO Inputs
      #define ModeSwitch  8 //Switch to set the rigth mode
      #define Button      7 //digital Button for free use


// --------------------------- Constants and variables --------------------------------//

      #define motorInterfaceType 1  // Set the driver to Full4Wire --> Stepper is connected via 4 pins

      #define R_SENSE   0.075f      // Value for mesure the real current at the StepStick

      #define STALL_VALUE   0       //5 [-64..63] // 9 (Nema 11) after calibration at low speed (6RPM), good performance at higher speed 100 to 300 RPM  

      bool homesuccess = false;    //if the homing was not successfull the variable is false, saftey variable

      int mode = 1;                //initialize the variable to set modes

      #define e 2.71828182846f;



// ------------------------------ Choose a Driver --------------------------------------//

    //TMC2130 
      //TMC2130Stepper driver(CS_PIN, R_SENSE, SW_MOSI, SW_MISO, SW_SCK);  // Hardware SPI
      //TMC2130Stepper driver(CS_PIN, R_SENSE);
      //AccelStepper stepper = AccelStepper(motorInterfaceType, STEP_PIN, DIR_PIN);
    
    //TMC5160
      //TMC5160Stepper driver(CS_PIN, R_SENSE, SW_MOSI, SW_MISO, SW_SCK);  // Hardware SPI
      TMC5160Stepper driver(CS_PIN, R_SENSE);
      AccelStepper stepper = AccelStepper(stepper.DRIVER, STEP_PIN, DIR_PIN);



// ------------------------------ Calculation Parameters ------------------------------//
    float dist;
    float vel_in;
    float acc_in;
    float vel_out;
    float acc_out;

    float tir_min;
    float tir_max;

    float ter_min;
    float ter_max;

    float dist_min;
    float dist_max;

// ------------------------------ Status ------------------------------//
    
    bool  PWF = false;    //pre-Warming Flag
