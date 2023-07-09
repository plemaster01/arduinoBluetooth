#include <SoftwareSerial.h>
SoftwareSerial BT(3,4);
char val; //value to receieve data from the serial port
int ledpin1 = 9; //red LED
int ledpin2 = 10; // green LED

void setup() {
  pinMode(ledpin1, OUTPUT); // set LED pins as outputs
  pinMode(ledpin2, OUTPUT);
  BT.begin(9600); //begin serial communications at 9600 bits per second (baud)
}

void loop() {
  if( BT.available() ) // check if there is data to read
  {
    val = BT.read(); // read the data into our value variable
    BT.print("Reading new data: ");
    BT.println(val);
  }
  if (val == '1') // if 1 (high) is received
  {
  digitalWrite(ledpin1, HIGH); // Turn on the green light and off the red light
  digitalWrite(ledpin2, LOW);
  }
  else // 1 not received
  {
  digitalWrite(ledpin1, LOW); // Turn on the red light and off the green light
  digitalWrite(ledpin2, HIGH);
  }
  delay(100);
}
