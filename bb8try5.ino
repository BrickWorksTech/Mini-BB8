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

char data = '0';            //Variable for storing received data
void setup()
{
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
    

    //reset();
    stepper1.setMaxSpeed(300.0);
    stepper1.setAcceleration(100.0);
    stepper1.moveTo(1000000);
    
    stepper2.setMaxSpeed(300.0);
    stepper2.setAcceleration(100.0);
    stepper2.moveTo(1000000);
    //stepper1.setSpeed(300.0);
    //stepper2.setSpeed(300.0);
}
void loop()
{
  if(data == '0'){
  //  reset();    
    //stepper1.run();
    //stepper2.run();

    
     stepper1.step(10.5);
    delay(2000);
     //stepper1.runSpeed();
     //stepper2.runSpeed();
  }else if(data == '1'){
    stepper1.stop();
    stepper2.stop();        
  }

   
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");        

            


   }
}

//void reset(){
//    stepper1.setMaxSpeed(300.0);
//    stepper1.setAcceleration(100.0);
//    stepper1.moveTo(1000000);
    
//    stepper2.setMaxSpeed(300.0);
//    stepper2.setAcceleration(100.0);
//    stepper2.moveTo(1000000);
//}

