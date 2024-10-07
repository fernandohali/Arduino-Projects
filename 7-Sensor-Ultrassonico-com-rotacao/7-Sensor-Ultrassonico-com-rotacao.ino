#include <Servo.h> 

// Definindo variáveis
const int trigPin = 10;
const int echoPin  = 9;

long duration;
int  distance;

int buzzpin = 7;
int buzzState = LOW;

int ledRed = 3;
int ledGreen = 4;

int switchpin = 10;
int ledStatus = 8;

unsigned long previousMillis = 0;

const long intervalFar = 250;
const long intervalClose = 50;
const long intervalIdle = 1250;

Servo myServo; 

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(12); 
  pinMode(buzzpin, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(switchpin, INPUT);
  pinMode(ledStatus, OUTPUT);
}

void loop() {
  if (digitalRead(switchpin) == HIGH){
    digitalWrite(ledStatus, LOW);
    StartScan();
  }
  if (digitalRead(switchpin) == LOW){
    digitalWrite(ledStatus, HIGH);
  }
}

int calculateDistance() { 
  digitalWrite(trigPin,  LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // lê o echoPin e retorna o tempo de viagem da onda sonora (ms)
  distance = duration * 0.034 / 2;
  return distance;
}

void StartScan() {
  // Varre de 15 a 165 graus
  for (int i = 15; i <= 165; i++) {  
    myServo.write(i);
    delay(30);
    distance = calculateDistance();

    if (distance <= 40 && distance > 20) {
      unsigned long currentMillis = millis();

      if (currentMillis - previousMillis >= intervalFar) {
        previousMillis = currentMillis;
        buzzState = !buzzState;
        digitalWrite(buzzpin, buzzState);
        digitalWrite(ledRed, buzzState); 
        digitalWrite(ledGreen, HIGH); 
      }
    } else if (distance <= 20 && distance > 0) {
      unsigned long currentMillis = millis();

      if (currentMillis - previousMillis >= intervalClose) {
        previousMillis = currentMillis;
        buzzState = !buzzState;
        digitalWrite(buzzpin, buzzState);
        digitalWrite(ledRed, buzzState); 
        digitalWrite(ledGreen, HIGH); 
      }
    } else if (distance > 40) {
      digitalWrite(buzzpin, LOW);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH); 
    }
      
    Serial.print(i); 
    Serial.print(","); 
    Serial.print(distance);  
    Serial.print(".");
  }

  // Varre de 165 a 15 graus
  for (int i = 165; i >= 15; i--) {  
    myServo.write(i);
    delay(30);
    distance = calculateDistance();

    if (distance <= 40 && distance > 20) {
      unsigned long currentMillis = millis();

      if (currentMillis - previousMillis >= intervalFar) {
        previousMillis = currentMillis;
        buzzState = !buzzState;
        digitalWrite(buzzpin, buzzState);
        digitalWrite(ledRed, buzzState); 
        digitalWrite(ledGreen, HIGH); 
      }
    } else if (distance <= 20 && distance > 0) {
      unsigned long currentMillis = millis();

      if (currentMillis - previousMillis >= intervalClose) {
        previousMillis = currentMillis;
        buzzState = !buzzState;
        digitalWrite(buzzpin, buzzState);
        digitalWrite(ledRed, buzzState); 
        digitalWrite(ledGreen, HIGH); 
      }
    } else if (distance > 40) {
      digitalWrite(buzzpin, LOW);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH); 
    }

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}
