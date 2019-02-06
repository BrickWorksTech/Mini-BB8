void setup()
{
   Serial.begin(9600);
   Serial.println("OK then, you first, say something.....");
   Serial.println("Go on, type something in the space above and hit Send, or just hit the Enter key"); 
}

void loop()
{
 while(Serial.available()==0)
 {}
 delay(500);
 Serial.println("I heard you say:      ");
 while(Serial.available()>0)
 {
   Serial.write(Serial.read());// note it is Serial.WRITE
 }
 Serial.println("");
}
