#ifndef PID_h
#define PID_h

#include <Arduino.h>

class PID {
  public:
    PID();
    void begin();
    double PIDcalc(double inp, int sp, double kp, double ki, double kd, int maxVal, int minVal, unsigned long currentTime, unsigned long previousTime);

};

#endif 
