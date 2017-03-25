// We're going to include a single library to control the PWM output to the servo
#include <Servo.h>

// Now that we have the library, we need to create an object from that library
Servo myservo;

// Let's setup our constants:
#define ServoPin 7      // This is the pin to which the servo data line is connected
#define ServoSpeed 15   // This is the speed at which the servo will turn (lower value = faster)
#define maxPWM 130      // This is the maximum PWM value that can be sent to the servo
#define minPWM 80        // This is the minimum PWM value that can be sent to the servo

// We want a variable that will store the current PWM value that indicates the servo's position
int servoVal = 0;    // variable to store the servo position

void setup() 
{
  // Configures the object "myservo" to use the data pin defined in "ServoPin"
  myservo.attach(ServoPin);
}

void loop() 
{
  for (servoVal = minPWM; servoVal <= maxPWM;) 
  { 
    myservo.write(servoVal);              // sends the PWM value to the servo that will turn it to the degree position in ServoVal
    servoVal = servoVal+1;                // advance the counter
    delay(ServoSpeed);                    // wait for as many ms as are defined in "ServoSpeed"
  }
  for (servoVal = maxPWM; servoVal >= minPWM;)
  { 
    myservo.write(servoVal);              // sends the PWM value to the servo that will turn it to the degree position in ServoVal
    servoVal = servoVal - 1;              // decrement the counter
    delay(ServoSpeed);                    // wait for as many ms as are defined in "ServoSpeed"
  }
}

