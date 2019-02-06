#include <AccelStepper.h>
#include <AFMotor.h>

// two stepper motors one on each port
AF_Stepper motor1(200, 1);
AF_Stepper motor2(200, 2);

int direction = 'stop';

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
   Serial.begin(9600);
   Serial.println("OK then, you first, say something.....");
   Serial.println("Go on, type something in the space above and hit Send, or just hit the Enter key");

    stepper1.setMaxSpeed(300.0);
    stepper1.setAcceleration(100.0);
    stepper1.moveTo(1000000);
    
    stepper2.setMaxSpeed(300.0);
    stepper2.setAcceleration(100.0);
    stepper2.moveTo(1000000);
}

void loop()
{
   if(direction == 'forward'){
     stepper1.run();
     stepper2.run();
   }else if(direction == 'right'){

   }else if(direction == 'left'){

   }else if(direction == 'back'){

   }else if(direction == 'stop'){
     stepper1.stop();
     stepper2.stop();
   }
  
 while(Serial.available()==0)
 {
   if(direction == 'forward'){
     stepper1.run();
     stepper2.run();
   }else if(direction == 'right'){

   }else if(direction == 'left'){

   }else if(direction == 'back'){

   }else if(direction == 'stop'){
     stepper1.stop();
     stepper2.stop();
   }
  }
 delay(500);
 Serial.println("I heard you say:      ");
 while(Serial.available()>0)
 {
  int read = Serial.read();
   Serial.write(read);// note it is Serial.WRITE
   if(read == 'forward'){
     direction = 'forward';
   }else if(read == 'right'){
      direction = 'right';
   }else if(read == 'left'){
      direction = 'left';
   }else if(read == 'back'){
      direction = 'back';
   }else if(read == 'stop'){
      direction = 'stop';
   }

   if(direction == 'forward'){
     stepper1.run();
     stepper2.run();
   }else if(direction == 'right'){

   }else if(direction == 'left'){

   }else if(direction == 'back'){

   }else if(direction == 'stop'){
     stepper1.stop();
     stepper2.stop();
   }
 }

 Serial.println("");
}

