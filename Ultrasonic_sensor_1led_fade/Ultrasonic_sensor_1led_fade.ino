 const int trigPin = 9;
 const int echoPin = 10;
 const int led = 8;
 
 int  fadeValue2 ;
 
void setup()

  {
      // initialize serial communication:
         Serial.begin(4800);
   }
 
void loop()
 {

//-------------Get-Distance-----------------------------//
   // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
   long duration, inches, cm, cm2;
 
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
   // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);
     pinMode(led, OUTPUT);
     
     digitalWrite(trigPin, LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(5);
     digitalWrite(trigPin, LOW);
 
  
  // pulse whose duration is the time (in microseconds) 
  // of the ping to the reception of its echo off of an object.
     
    duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
     inches = microsecondsToInches(duration);
     cm = microsecondsToCentimeters(duration);
  //-------------End-Get-Distance----------------------------//


  //-------------Fading-LED------------------------------//
  if (cm<40)   // If Distance is less than 40 cm then do the following:

 {    // Maps the LED brightness inversely proportional to the distance 

  cm2 = 40 - cm;  

  fadeValue2 = map(cm2 , 0, 40, 0, 254);


  analogWrite(led, fadeValue2);  // Writes the fadeValue to pin 9 
 }
 else
 {
   analogWrite(led, 0);  //If distance is larger than 40cm then switch off  

 }
 //-------------End-Fading-LED-----------------------------//

 


 //-------------Debugging-------------------------------// 
   //For debugging purposes

    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
   Serial.println();
//-------------End-Debugging------------------------------//

  
  delay(100);  // Short Delay allows for smoother fading

 }  //End Loop

 

//-------------Functions-------------------------------// 
long microsecondsToInches(long microseconds)
 {
   // According to Parallax's datasheet for the PING))), there are
   // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
   // second).  This gives the distance travelled by the ping, outbound
   // and return, so we divide by 2 to get the distance of the obstacle.
   // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
   return microseconds / 74 / 2;
 }
 
long microsecondsToCentimeters(long microseconds)
 {
   // The speed of sound is 340 m/s or 29 microseconds per centimeter.
   // The ping travels out and back, so to find the distance of the
   // object we take half of the distance travelled.
   return microseconds / 29 / 2;
 }

 //------------End-Functions-------------------------------//

 

//End Of Program 
