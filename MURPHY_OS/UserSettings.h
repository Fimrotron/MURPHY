/*
 *  Configuration.h
 *  In this file u can set all the needed Parameters that arer needed to configure your motion
 *
 *  created by Anton Schlünz
 *
 */

 // ---------------------------- Includes ---------------------------------//

  /* Dont change this Values */
  #include "Configuration.h"


// ------------------------------- User Settings ------------------------- //
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
      
      int Lev_Down = 1;    //lever low postion, insert one of the integer variables that are listed in the upper mode list


      //Force Parameters for calibratrion
        //Choose higher Values for higher sensitivity and otherwise (0...1025)
      
      #define HousingImpact   1000       //Std Value 250
      #define PhantomImpact   500       //Std Value 300


// ------------------------------- End of User Settings ------------------------------------ //
