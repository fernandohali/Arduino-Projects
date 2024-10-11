// Inclui a biblioteca Servo
#include <Servo.h>

// Define os pinos Trig e Echo do Sensor Ultrassônico
const int trigPin = 10;
const int echoPin = 9;

// Define os pinos dos LEDs
const int LED_RED1 = 2;
const int LED_GREEN = 3;
const int LED_RED2 = 4;

// Define o pino do buzzer e seu estado inicial
int buzzpin = 7;
int buzzState = LOW;

// Variáveis para armazenar a duração e a distância
long duration;
int distance;
Servo myServo;  // Cria um objeto servo para controlar o motor servo

// Variáveis de intervalo de tempo
unsigned long previousMillis = 0;
const long intervalFar = 250;
const long intervalClose = 50;

void setup() {
  pinMode(trigPin, OUTPUT);    // Define o pino trigPin como Saída
  pinMode(echoPin, INPUT);     // Define o pino echoPin como Entrada
  Serial.begin(9600);          // Inicializa a comunicação serial
  myServo.attach(12);          // Define o pino ao qual o motor servo está conectado
  pinMode(LED_RED1, OUTPUT);   // Define o pino ao qual o LED vermelho está conectado.
  pinMode(LED_RED2, OUTPUT);   // Define o pino dois ao qual o LED vermelho está conectado.
  pinMode(LED_GREEN, OUTPUT);  // Define o pino ao qual o LED verde está conectado.
  pinMode(buzzpin, OUTPUT);    // Define o pino do buzzer como Saída
}

void loop() {
  // Varredura do motor servo de 0 a 180 graus
  for (int i = 0; i <= 180; i++) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();

    // Condições de acionamento dos LEDs e buzzer com base na distância
    if (distance <= 40 && distance > 20) {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= intervalFar) {
        previousMillis = currentMillis;
        buzzState = !buzzState;  // Alterna o estado do buzzer e LED vermelho
        digitalWrite(buzzpin, buzzState);
        digitalWrite(LED_RED1, buzzState);
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED2, LOW); // Apaga o LED vermelho 2 se não está na faixa mais próxima
      }
    } else if (distance <= 20 && distance > 0) {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= intervalClose) {
        previousMillis = currentMillis;
        buzzState = !buzzState;  // Alterna o estado do buzzer e LED vermelho
        digitalWrite(buzzpin, buzzState);
        digitalWrite(LED_RED1, buzzState);
        digitalWrite(LED_RED2, buzzState); // Acende o LED vermelho 2 para distância < 20 cm
        digitalWrite(LED_GREEN, HIGH);
      }
    } else if (distance > 40) {
      digitalWrite(buzzpin, LOW);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_RED1, HIGH);
      digitalWrite(LED_RED2, LOW); // Apaga o LED vermelho 2 se não está na faixa de < 20 cm
    }

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }

  // Varredura da esquerda para a direita
  for (int i = 180; i >= 0; i--) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();

    // Condições de acionamento dos LEDs e buzzer com base na distância
    if (distance <= 40 && distance > 20) {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= intervalFar) {
        previousMillis = currentMillis;
        buzzState = !buzzState;
        digitalWrite(buzzpin, buzzState);
        digitalWrite(LED_RED1, buzzState);
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED2, LOW); // Apaga o LED vermelho 2 se não está na faixa mais próxima
      }
    } else if (distance <= 20 && distance > 0) {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= intervalClose) {
        previousMillis = currentMillis;
        buzzState = !buzzState;
        digitalWrite(buzzpin, buzzState);
        digitalWrite(LED_RED1, buzzState);
        digitalWrite(LED_RED2, buzzState); // Acende o LED vermelho 2 para distância < 20 cm
        digitalWrite(LED_GREEN, HIGH);
      }
    } else if (distance > 40) {
      digitalWrite(buzzpin, LOW);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_RED1, HIGH);
      digitalWrite(LED_RED2, LOW); // Apaga o LED vermelho 2 se não está na faixa de < 20 cm
    }

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

// Função para calcular a distância medida pelo Sensor Ultrassônico
int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}