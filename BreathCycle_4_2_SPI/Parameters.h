//_________________User Settings_______________________
  // this area is to configurate your MURPHY's parameters

    //standard Parameter
      // --> stdStep defines the amout of steps that are nesseccary to drive 1 cm
      // --> this is one of the most important parameters of the system. If this is set too inaccurately, the limit values to be set in the following are not guaranteed

      #define stdStep 1275   //Number of steps to drive 1cm


    //drive parameters
      
      //normal distance to go (madically ca. 2.6 cm)
        // --> sets the run distance for all modes except for random mode

      double cm = 2.6;    //distance to drive in cm


      //inspiration Time in seconds (medically ca. 1.82 s)
        // --> sets the time that the system has to drive from the start position to inhale

      #define ti  2.1f    //inspiration time in s


      //expiration Time in seconds (medically ca. 2.37 s)
        // --> sets the time that the system has to drive from the inhaled position to exhale

      #define te  3.1f    //expiration time in s


      //holding breath time after inspiration in milli seconds
        // --> sets the time that the system pauses after inspiration

      #define pi  200    //inspiration time in ms


      //holding breath time after expiration in milli seconds
        // --> sets the time that the system pauses after expiration

      #define pe  500    //expiration time in ms



    //Random mode

      // deviation from normal parameters
      // --> set deviation percentage instead of minimum and maximum parameters for distance and time

        //deviation percentage for distance

        #define dev_cm 10   // +- Deviation from cm


        //deviation percentage for inspiration

        #define dev_ti 5   // +- Deviation from ti


        //deviation percentage for expiration

        #define dev_te 6   // +- Deviation from te


    //Parameter for mode 4

      // insert here the distances the motor has to stop. The vektor do not have a defined length.
      // after driving this procedure the motor will drive to position 0, so the last position shouldnt be 0

      double dsr[]= {0.5,1,1.5,2,2.5,3,2.5,2,1.5,1,0.5};  //Driving vector for mode 4, distances in cm



    //Choose modes

      // there is a switch at MURPHY that is for choosing a mode
      // here you cann choose the modes for the tow position of the mode selector lever
      // all modes are listed in the following

          //possible Modes
          // 1  --> standard mode (drives with set parameters)
          // 2  --> random mode (drives with set parameters in a range that is set by the deviation percentage)
          // 3  --> e-function mode (most relistic drives with the set parameters) !!!!!Not Ready Yet!!!!!!!
          // 4  --> stop mode (stops at distances that are set in the beginning, moves to the next position if the switch was toggeled)


      //lever upper position
      
      int Lev_Up = 1;    //lever upper postion, insert one of the integer variables that are listed in the upper mode list


      //lever upper position
      
      int Lev_Down = 3;    //lever low postion, insert one of the integer variables that are listed in the upper mode list


//____________________End of User Settings______________________________________________________________________________________________________________________________




//_____________________Define GPIOs________________________

    //Step and Direction Pins
      #define STEP_PIN  4   // Pin to set Steps
      #define DIR_PIN   3   // Pin to set Direction


    //nesseccary Pins
      #define SW_MOSI   11  // Software Master Out Slave In (MOSI)
      #define SW_MISO   12  // Software Master In Slave Out (MISO)
      #define SW_SCK    13  // Software Slave Clock (SCK)

      #define CS_PIN    10  // Chip select --> Shoud be set to normally LOW

      #define EN_PIN    5   // Enable Pin --> Should be set to normaly HIGH (if EN_PIN=LOW motor can drive) 
      #define VIO       8   // PowerSupply for the TMC5160

    //additional Pins
      #define h         2   // Homebutton
      #define m1        6   // Switch to Set Mode 1
      #define m2        7   // Switch to Set Mode 2



//_____________________Constants and variables________________________

      #define motorInterfaceType 1  // Set the driver to Full4Wire --> Stepper is connected via 4 pins

      #define R_SENSE   0.075f      // Value for mesure the real current at the StepStick

      #define STALL_VALUE   0       //5 [-64..63] // 9 (Nema 11) after calibration at low speed (6RPM), good performance at higher speed 100 to 300 RPM  

      bool homesuccess = false;    //if the homing was not successfull the variable is false, saftey variable

      int mode = 1;                //initialize the variable to set modes

      #define e 2.71828182846f;


//_____________________Choose a Driver___________________

    //TMC2130 
      //TMC2130Stepper driver(CS_PIN, R_SENSE, SW_MOSI, SW_MISO, SW_SCK);  // Hardware SPI
      //TMC2130Stepper driver(CS_PIN, R_SENSE);
      //AccelStepper stepper = AccelStepper(motorInterfaceType, STEP_PIN, DIR_PIN);
    
    //TMC5160
      //TMC5160Stepper driver(CS_PIN, R_SENSE, SW_MOSI, SW_MISO, SW_SCK);  // Hardware SPI
      TMC5160Stepper driver(CS_PIN, R_SENSE);
      AccelStepper stepper = AccelStepper(stepper.DRIVER, STEP_PIN, DIR_PIN);



//____________________Calculation Parameters_________________________

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

//___________________Status_______________________________________
    
    bool  PWF = false;    //pre-Warming Flag


//_____________________Declare Functions__________________________