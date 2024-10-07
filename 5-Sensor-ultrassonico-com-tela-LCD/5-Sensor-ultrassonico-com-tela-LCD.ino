#include <IRremote.h> // Inclua a biblioteca IRremote
#include <LiquidCrystal.h>

// Define os pinos do LCD: (RS, Enable, D4, D5, D6, D7)
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2); 

int cm = 0;
int inches = 0;

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  // Inicializa o LCD com 16 colunas e 2 linhas
  lcd_1.begin(16, 2);
  Serial.begin(9600); // Inicializa a comunicação serial para depuração
  
  // Exibe uma mensagem inicial no LCD
  lcd_1.setCursor(0, 0);
  lcd_1.print("Iniciando...");
  delay(2000); // Aguarda 2 segundos antes de continuar
  lcd_1.clear(); // Limpa o display
}

void loop() {
  // Lê a distância do sensor ultrassônico
  cm = 0.01723 * readUltrasonicDistance(7, 6); // Converte para centímetros
  inches = (cm / 2.54); // Converte para polegadas
  
  // Limpa a tela LCD
  lcd_1.clear();

  // Imprime a distância em cm na primeira linha
  lcd_1.setCursor(0, 0); // Posição inicial na linha 1
  lcd_1.print("Cm: ");
  lcd_1.print(cm); // Exibe a distância em centímetros
  
  // Imprime a distância em polegadas na segunda linha
  lcd_1.setCursor(0, 1); // Posição inicial na linha 2
  lcd_1.print("In: ");
  lcd_1.print(inches); // Exibe a distância em polegadas

  // Também imprime no monitor serial para verificação
  Serial.print("Distancia em cm: ");
  Serial.print(cm);
  Serial.print(" cm, ");
  Serial.print(inches);
  Serial.println(" in");

  delay(1000); // Atraso de 1 segundo entre as atualizações
}
