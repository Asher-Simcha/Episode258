// We're going to include a single library to control the PWM output to the servo
#include <Servo.h> 

// Now that we have the library, we need to create an object from that library
Servo myservo;
 
// We need two buttons and four LEDs
#define buttonPin1 2
#define buttonPin2 3
#define LEDpin1 8
#define LEDpin2 9
#define LEDpin3 10
#define LEDpin4 11

// We also need to define the pin that the servo uses
#define ServoPin 7

// While we're at it, let's set the speed of our servo
// 0 is fastest
#define ServoSpeed 10

// And finally, we need the Max and Min PWM values
#define maxPWM 110 // Max Value 180
#define minPWM 24   // Min Value 0

// We need a variable that will hold the value to be encoded into PWM
// This will also set the default position on power-up
int servoVal = 90;

// This is the variable that stores the state of the button
int OnOff = 0;

void setup()
{
  // Open the serial port so we can see the values of our button
  Serial.begin(9600);
  
  // Let's tell the servo object to what pin the servo is attached
  myservo.attach(ServoPin); 

  // Setting the mode for the pin to which LED1 is connected
  pinMode(LEDpin1, OUTPUT);
  
  // Setting the mode for the pin to which LED2 is connected
  pinMode(LEDpin2, OUTPUT);

  // Setting the mode for the pin to which LED3 is connected
  pinMode(LEDpin3, OUTPUT);
  
  // Setting the mode for the pin to which LED4 is connected
  pinMode(LEDpin4, OUTPUT);
 
  // Setting the mode for the pin to which the button1 is connected
  pinMode(buttonPin1, INPUT);     
  
  // Setting the mode for the pin to which the button2 is connected
  pinMode(buttonPin2, INPUT); 
}

void loop()
{
  // Calline the buttonRead function once for each button
  buttonRead(buttonPin1, LEDpin1);
  buttonRead(buttonPin2, LEDpin2);
  moveServo();
  
}

// This function can be passed two values: the number of the button pin & the number of the LED pin
// Doing it this way means I don't have to rewrite the code for each button/LED pair
void buttonRead(int button, int LED)
{
  // Read the button state and put the value into the variable "OnOff"
  OnOff = digitalRead(button);

  // Conditional Statement -- Only runs if true
  if (OnOff == HIGH)
  {     
  Serial.print("High");
  Serial.print("\t");
  digitalWrite(LED, HIGH);
  
  // We need to know WHICH button was pressed in order to move the servo in the right direction
  // This is a NESTED if statement
  // Each of these statements will only run if they are true AND if the if statement above is true
    if (button == buttonPin1)
    {
      servoVal = servoVal + 1;
    }
    if (button == buttonPin2)
    {
      servoVal = servoVal -1;
    }
  } 
  
  // This runs if the root if-statement is no true
  else 
  {
  Serial.print("Low");
  Serial.print("\t");
    digitalWrite(LED, LOW);
  } 
   
    Serial.print(servoVal);
    Serial.print("\n");
}

// This function does two things:
// First, it makes sure that the value being sent to the servo stays between Min and Max
// Second, it send the error-checked value to the digital pin connected to the servo
void moveServo()
{
  if(servoVal >= maxPWM)
  {
    servoVal = maxPWM;
    digitalWrite(LEDpin3, HIGH);
    digitalWrite(LEDpin4, LOW);
  }
  else
  if(servoVal <= minPWM)
  {
    servoVal = minPWM;  
    digitalWrite(LEDpin3, HIGH);
    digitalWrite(LEDpin4, LOW);
  }
  else
  {
    digitalWrite(LEDpin3, LOW);
    digitalWrite(LEDpin4, HIGH);
  }
  myservo.write(servoVal);
  delay(ServoSpeed);
}
