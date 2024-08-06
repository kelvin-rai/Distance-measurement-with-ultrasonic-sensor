#include <LiquidCrystal.h>

// Define pin connections for ultrasonic sensor
const int trigPin = 10;  // Trigger pin of Ultrasonic Sensor
const int echoPin = 9;  // Echo pin of Ultrasonic Sensor

// Define LCD module connections
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Initialize LCD
  lcd.begin(16, 2);

  // Initialize serial communication
  Serial.begin(9600);

  // Define ultrasonic sensor pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance_cm;

  // Clear the LCD
  lcd.clear();
  
  // Trigger ultrasonic sensor to send out a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance_cm = duration * 0.034 / 2;

  // Print the distance on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(distance_cm);
  lcd.print(" cm");

  // Print the distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // Delay before next measurement
  delay(1000);
}

