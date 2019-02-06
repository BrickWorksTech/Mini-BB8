// MultiStepper
// -*- mode: C++ -*-
//
// Control both Stepper motors at the same time with different speeds
// and accelerations. 
// Requires the AFMotor library (https://github.com/adafruit/Adafruit-Motor-Shield-library)
// And AccelStepper with AFMotor support (https://github.com/adafruit/AccelStepper)
// Public domain!

#include <AccelStepper.h>
#include <AFMotor.h>

// two stepper motors one on each port
AF_Stepper motor1(200, 1);
AF_Stepper motor2(200, 2);

// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
// wrappers for the first motor!
void forwardstep1() {  
  motor1.onestep(FORWARD, SINGLE);
}
void backwardstep1() {  
  motor1.onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void forwardstep2() {  
  motor2.onestep(FORWARD, SINGLE);
}
void backwardstep2() {  
  motor2.onestep(BACKWARD, SINGLE);
}

// Motor shield has two motor ports, now we'll wrap them in an AccelStepper object
AccelStepper stepper1(forwardstep1, backwardstep1);
AccelStepper stepper2(forwardstep2, backwardstep2);

void setup()
{  
    stepper1.setMaxSpeed(1000.0);
    stepper1.setAcceleration(500.0);
    
    
    stepper2.setMaxSpeed(1000.0);
    stepper2.setAcceleration(500.0);
    stepper2.moveTo(1000000);

    
    
}

void loop()
{
    char state = '4';
    int flag=0;
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    stepper1.run();
    stepper2.run();
    
    if(state == '0'){
      //forward
      stepper2.moveTo(1000000);
      stepper2.moveTo(1000000);
       if(flag == 0){
        Serial.println("Motor: forward");
        flag=1;
       }
    }else if(state == '1'){
      //left
      stepper1.stop();
      stepper2.moveTo(1000000);
      if(flag == 0){
        Serial.println("Motor: left");
        flag=1;
       }
    }else if(state == '2'){
      //right
      stepper1.moveTo(1000000);
      stepper2.stop();
      if(flag == 0){
        Serial.println("Motor: right");
        flag=1;
       }
    }else     if(state == '3'){
      //back
      stepper1.moveTo(-1000000);
      stepper2.moveTo(-1000000);
      if(flag == 0){
        Serial.println("Motor: back");
        flag=1;
       }
    }else     if(state == '4'){
      //stop
      stepper1.stop();
      stepper2.stop();
      if(flag == 0){
        Serial.println("Motor:stop");
        flag=1;
       }
    } 
}
