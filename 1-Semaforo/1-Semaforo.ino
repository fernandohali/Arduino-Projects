// C++ code for Arduino
// O código aciona três pinos de saída digitais (13, 12 e 7) para controlar, por exemplo, LEDs ou outros dispositivos conectados.

void setup()
{
  // Configura os pinos 13, 12 e 7 como saídas.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
}
2-Sequencial-com-leds
void loop()
{
  // Liga o dispositivo conectado ao pino 13 por 6 segundos.
  digitalWrite(13, HIGH);
  delay(6000); // Aguarda 6000 milissegundos (6 segundos)
  
  // Desliga o dispositivo no pino 13 e espera 1 segundo antes de continuar.
  digitalWrite(13, LOW);
  delay(1000); // Aguarda 1000 milissegundos (1 segundo)
  
  // Liga o dispositivo no pino 12 por 0,1 segundo.
  digitalWrite(12, HIGH);
  delay(100); // Aguarda 100 milissegundos (0,1 segundo)
  
  // Desliga o dispositivo no pino 12 e espera 0,1 segundo.
  digitalWrite(12, LOW);
  delay(100); // Aguarda 100 milissegundos (0,1 segundo)
  
  // Liga o dispositivo no pino 7 por 6 segundos.
  digitalWrite(7, HIGH);
  delay(6000); // Aguarda 6000 milissegundos (6 segundos)
  
  // Desliga o dispositivo no pino 7 e espera 1 segundo antes de reiniciar o ciclo.
  digitalWrite(7, LOW);
  delay(1000); // Aguarda 1000 milissegundos (1 segundo)
}
