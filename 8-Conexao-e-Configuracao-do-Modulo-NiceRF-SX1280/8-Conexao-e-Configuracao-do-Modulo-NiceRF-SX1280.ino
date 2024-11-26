#include <RadioLib.h>

// Configuração do módulo SX1280
SX1280 radio = new Module(8, 7, 6, 5, 4); // Pinos NSS, MOSI, MISO, SCK e RESET

void setup() {
    Serial.begin(9600);
    Serial.println("Inicializando SX1280...");
    
    int state = radio.begin();
    if (state == RADIOLIB_ERR_NONE) {
        Serial.println("Módulo SX1280 inicializado com sucesso!");
    } else {
        Serial.print("Erro ao inicializar: ");
        Serial.println(state);
    }
}

void loop() {
    // Envia uma mensagem
    int state = radio.transmit("Olá, LoRa!");
    if (state == RADIOLIB_ERR_NONE) {
        Serial.println("Mensagem enviada com sucesso!");
    } else {
        Serial.print("Erro no envio: ");
        Serial.println(state);
    }
    delay(2000);
}