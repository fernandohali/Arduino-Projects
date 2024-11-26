#include <IRremote.h>

int IRporta = 5, ledV = 8;

// Declarações de uso da biblioteca IR 
IRrecv irReceptor(IRporta);
decode_results valorRecebido;

int retorno = 0;
bool codigo = false;


bool traduzirCodIR() {
  // 1 16582903
  // 2 16615543
  switch (valorRecebido.value) {
    case 16582903:
    	return true;
    case 16615543:
    	return false;
  }
}

void acionarLED(bool codigoIR) {
  if (codigoIR) digitalWrite(ledV, HIGH);
  else digitalWrite(ledV, LOW);
}


void setup() {
  pinMode(ledV, OUTPUT);
  Serial.begin(9600);
  irReceptor.enableIRIn(); //Inicializa o receptor
}

void loop() {
  if (irReceptor.decode(&valorRecebido)) {
    codigo = traduzirCodIR();
    acionarLED(codigo);
    irReceptor.resume(); 
  }
}