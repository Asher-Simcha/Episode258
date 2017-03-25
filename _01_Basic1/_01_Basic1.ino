// We're going to include a single library to control the PWM output to the servo
#include <Servo.h>

// Now that we have the library, we need to create an object from that library
Servo myservo;

// We want a variable that will store the current PWM value that indicates the servo's position
int servoVal = 0;    // variable to store the servo position

void setup() 
{
  // Configures the object "myservo" to use data pin 7
  myservo.attach(7);
}

void loop() 
{
  for (servoVal = 0; servoVal <= 180;) 
  { 
    myservo.write(7);                     // sends the PWM value to the servo that will turn it to the degree position in ServoVal
    servoVal = servoVal+1;                // advance the counter
    delay(10);                            // wait 10ms
  }
  for (servoVal = 180; servoVal >= 0;)
  { 
    myservo.write(servoVal);              // sends the PWM value to the servo that will turn it to the degree position in ServoVal
    servoVal = servoVal - 1;              // decrement the counter
    delay(10);                            // wait 10ms
  }
}

