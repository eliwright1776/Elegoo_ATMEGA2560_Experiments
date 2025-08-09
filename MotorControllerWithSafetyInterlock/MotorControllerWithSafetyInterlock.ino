/*
MotorDriverWithSafetyInterlock.ino

Controls a servo using an analog joystick. The microcontroller can be placed into
multiple modes. A liquid crytal display is used to denote the mode change and the
parameters of the servo output.

using LCD, DC Brushed Motor, IR Reciever, Remote, Joystick

Originally written 8 Aug 2025
by Elijah D. Wright

This code is internal to Aeglos Inventors Robotics.
It is based on example code in the public domain.

https://github.com/eliwright1776/Elegoo_ATMEGA2560_Experiments

*/


/*      Include Libraries      */
#include <Servo.h>
#include <LiquidCrystal.h>


/*      Initialize Objects      */
Servo outputServo;  // initialize the output servo
LiquidCrystal lcd;  // initialize the LCD


// 
void readJoystick() {
  
  
}


// 
void moveServo() {

}


// 
void printSerialToLCD() {
// when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
}

// Void setup function runs code once to prepare the microcontroller for function.
void setup() {
  
  /*    Servo   */
  outputServo.attach(13);
  int joystickPos[2] = [A0, A1];  // [xPos, yPos]
  int valX;

  /*    Liquid Crystal Display    */
  const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  lcd(rs, en, d4, d5, d6, d7);
  lcd.begin(16, 2);  // lcd.begin(num_columns, num_rows);

  /*    Serial Monitor    */
  Serial.begin(9600);  // sample/baud rate in Hz

  /*    Boot-up Text    */
  for (int init = 0; init < 2; init++) {
    lcd.print("Initializing...");
    wait(500);  // miliseconds
  }
  lcd.print("All is ready. Commence motor control.");

}


// Void loop function runs code repeatedly as long as the microcontroller has power.
void loop() {
  
  // Read and convert the analog input from the joystick and move the servo to 
  // reflect that value.
  valX = analogRead(inputPinX);
  valX = map(valX, 0, 1023, 0, 180);  // scales the bitcount value to degrees
  outputServo.write(val);  // sets the servo position in bitcount
  delay(15);
  
}
