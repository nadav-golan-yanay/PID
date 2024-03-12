#include "PID.h"

unsigned long currentTime;
unsigned long previousTime;
double elapsedTime;
double error;
double lastError;
double input, output;
double cumError, rateError;
double kp = 0;
double ki = 0; 
double kd = 0;

PID::PID(){

}

void PID::begin(){
}

double PID::PIDcalc(double inp, int sp, double kp, double ki, double kd, int maxVal, int minVal, unsigned long currentTime, unsigned long previousTime){
   //currentTime = millis();                //get current time
   elapsedTime = (double)(currentTime - previousTime)/1000; //compute time elapsed from previous computation (60ms approx). divide in 1000 to get in Sec
   //Serial.print(currentTime); //for serial plotter
   //Serial.println("\t"); //for serial plotter
   error = sp - inp;                                  // determine error
   cumError += error * elapsedTime;                   // compute integral
   rateError = (error - lastError)/elapsedTime;       // compute derivative deltaError/deltaTime
   double out = kp*error + ki*cumError + kd*rateError; //PID output               
   //Serial.println(cumError);
   lastError = error;                                 //remember current error
   //previousTime = currentTime;                        //remember current time
   if(out > maxVal){out = maxVal;}    //limit the function for smoother operation
   if(out < minVal){out = minVal;}
   return out;                                        //the function returns the PID output value 
}
