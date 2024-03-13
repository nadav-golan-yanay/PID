# PID

This library provides a simple PID code. 

**The library is for Arduino and ESP32**

## What is PID:
*(This section will be added in the future.)*

## Code:

**`begin()`**
Currently, this function does nothing. In the future, it might be utilized.

This function **must** be called from `void setup()`.


**`PIDcalc(double inp, int sp, double kp, double ki, double kd, int maxVal, int minVal, unsigned long currentTime, unsigned long previousTime)`**
- inp: the input to the function.
- sp: the Set Point of the function (the value that the function tends to).
- kp: the kp value of the function.
- ki: the ki value of the function.
- kd: the kd value of the function.
- maxVal: the highest value that the function returns.
- minVal: the lowest value that the function returns.
- currentTime: the corrent time in milliseconds.
- previousTime: the previous tims in milliseconds.

This function performs the basic calculation of the PID output from all of those values.


For exmple:
-4 = PIDcalc(2, 0, 2, 1, 0, 255, -255, 42, 41)

The **inp** to this function is 2, the **SP** is 0, the **kp** val is 2, the **ki** val is 0, the **kd** val is 0, **maxVal** is 255, **minVal** is -255, **currentTime** is 42 and **previousTime** is 41.
