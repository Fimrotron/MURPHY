
//definition oft the normal driving mode
void modeOne(){

    //set inspiration drive parameters
      stepper.setSpeed(vel_in);
      stepper.setAcceleration(acc_in);

    //start running to inhaled position
      stepper.runToNewPosition(dist);

    //holding breath after inspiration
      delay(pi);

    //set expiration drive parameters
      stepper.setSpeed(vel_out);
      stepper.setAcceleration(acc_out);

    //start running to exhaled position
      stepper.runToNewPosition(0);

    //holding breath after expiration
      delay(pe);

}

//definition of the random driving mode
void modeTwo(float distr, float tir, float ter){


    //calculate the accelaration with a=(8*s)/(t^2)
      float accr_in   =  (8*distr)/(tir*tir);
      float accr_out  =  (8*distr)/(ter*ter);

    //velocity calculation
      float velr_in   =   (distr-(accr_in*tir*tir)/4)/(tir);
      float velr_out  =   (distr-(accr_out*ter*ter)/4)/(ter);

    //set inspiration drive parameters
      stepper.setSpeed(velr_in);
      stepper.setAcceleration(accr_in);

    //start running to inhaled position
      stepper.runToNewPosition(distr);

    //holding breath after inspiration
      delay(pi);

    //set expiration drive parameters
      stepper.setSpeed(velr_out);
      stepper.setAcceleration(accr_out);

    //start running to exhaled position
      stepper.runToNewPosition(0);

    //holding breath after expiration
      delay(pe);

}

//definition oft the e-function mode (not ready)
void modeThree(){

  int Vh = dist/ti;
  int Vr = dist/te;

  long ah = 16000*pow(ti, -1.827)-250*ti/2.5;
  long ar = 16000*pow(te, -1.827)-250*te/2.5;

  stepper.setAcceleration(ah); //2.5 3000

  stepper.setSpeed((35/8) * Vh);
  stepper.runToNewPosition((5/8)*dist);

  stepper.setSpeed((7/12) * Vh);
  stepper.runToNewPosition((7/8)*dist);

  stepper.setSpeed((7/24) * Vh);
  stepper.runToNewPosition(dist);

  delay(pi);

  stepper.setAcceleration(ar);

  stepper.setSpeed((35/8) * Vr);
  stepper.runToNewPosition((3/8)*dist);

  stepper.setSpeed((7/12) * Vr);
  stepper.runToNewPosition((1/8)*dist);

  stepper.setSpeed((7/24) * Vr);
  stepper.runToNewPosition(0);

  delay(pe);

}

//definition oft the stop mode
void modeFour(){

  int lengt = sizeof(dsr);

  for(int i=0; i<lengt; i++){

      stepper.runToNewPosition(stdStep*dsr[i]);

    while(1){
      if(digitalRead(h) == LOW){
        break;
      }
      delay(10);
    }
  }
  stepper.runToNewPosition(0);
}
