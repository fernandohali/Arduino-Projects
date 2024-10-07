// Declaração de um array que contém os pinos conectados aos LEDs
byte ledPin[] = {5, 6, 7, 8, 9, 10, 11, 12, 13}; 

void setup() {
  // Configura todos os pinos como saídas, permitindo o controle dos LEDs.
  for (int x = 0; x < 9; x++) {
    pinMode(ledPin[x], OUTPUT);
  }
}

void loop() {
  int x = 0;

  // Primeira parte: acende os LEDs da esquerda (pino 5) para a direita (pino 13)
  while (x < 9) {
    digitalWrite(ledPin[x], HIGH);  // Liga o LED no pino atual
    delay(150);                     // Aguarda 150 milissegundos
    digitalWrite(ledPin[x], LOW);   // Desliga o LED
    x = ++x;                        // Avança para o próximo LED
  }

  // Segunda parte: acende os LEDs da direita (pino 13) para a esquerda (pino 5)
  while (x > 0) {
    digitalWrite(ledPin[x], HIGH);  // Liga o LED no pino atual
    delay(150);                     // Aguarda 150 milissegundos
    digitalWrite(ledPin[x], LOW);   // Desliga o LED
    x = --x;                        // Retrocede para o LED anterior
  }
}
