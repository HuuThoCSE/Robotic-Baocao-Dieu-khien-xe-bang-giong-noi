#include <SoftwareSerial.h>

// Define the motor control pins
const int n1 = 9; // Motor 1 forward
const int n2 = 8; // Motor 1 backward
const int n3 = 7; // Motor 2 forward
const int n4 = 6; // Motor 2 backward

// Define the pins for the Bluetooth module
const int rxPin = 2; // RX pin of Bluetooth module
const int txPin = 3; // TX pin of Bluetooth module

// Create a SoftwareSerial object for Bluetooth communication
SoftwareSerial bluetoothSerial(rxPin, txPin);

void setup() {
  // Set the motor control pins as outputs
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4, OUTPUT);

  // Initialize serial communication at 9600 baud rate for debugging
  Serial.begin(9600);
  
  // Initialize serial communication for the Bluetooth module
  bluetoothSerial.begin(9600);
}

void loop() {
  // Check if data is available from Bluetooth
  if (bluetoothSerial.available() > 0) {
    // Read the command from the Bluetooth serial input
    String command = bluetoothSerial.readStringUntil('\n');
    command.trim(); // Remove any whitespace or newline characters

    // Print the received command to the Serial Monitor
    Serial.println("Received command: " + command);
    
    // Execute the corresponding motor control command
    if (command.indexOf("tiến lên") != -1) {
      moveForward();
    } else if (command.indexOf("lùi") != -1) {
      moveBackward();
    } else if (command.indexOf("trái") != -1) {
      turnLeft();
    } else if (command.indexOf("phải") != -1) {
      turnRight();
    } else {
      stopMotor();
    }
  }
}

// Function to move forward
void moveForward() {
  digitalWrite(n1, HIGH);
  digitalWrite(n2, LOW);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, LOW);
}

// Function to move backward
void moveBackward() {
  digitalWrite(n1, LOW);
  digitalWrite(n2, HIGH);
  digitalWrite(n3, LOW);
  digitalWrite(n4, HIGH);
}

// Function to turn left
void turnLeft() {
  digitalWrite(n1, LOW);
  digitalWrite(n2, HIGH);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, LOW);
}

// Function to turn right
void turnRight() {
  digitalWrite(n1, HIGH);
  digitalWrite(n2, LOW);
  digitalWrite(n3, LOW);
  digitalWrite(n4, HIGH);
}

// Function to stop the motor
void stopMotor() {
  digitalWrite(n1, LOW);
  digitalWrite(n2, LOW);
  digitalWrite(n3, LOW);
  digitalWrite(n4, LOW);
}
