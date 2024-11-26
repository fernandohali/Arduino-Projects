# Conexão e Configuração do Módulo NiceRF SX1280 com Arduino

Este projeto utiliza o módulo **NiceRF SX1280** em conjunto com um Arduino para comunicação sem fio usando tecnologia **LoRa**. O SX1280 opera na frequência de 2.4 GHz, oferecendo alta taxa de transferência e alcance estendido com baixo consumo de energia.

## 🚀 Funcionalidades

- Comunicação LoRa na frequência de 2.4 GHz.
- Configuração simples e eficiente com a biblioteca `RadioLib`.
- Código básico para transmissão de mensagens.

---

## 🔌 Conexões

Os pinos do módulo SX1280 devem ser conectados ao Arduino da seguinte forma:

| **SX1280**  | **Arduino** | **Função**               |
|-------------|-------------|--------------------------|
| 3.3V        | 3.3V        | Alimentação do módulo    |
| GND         | GND         | Terra                    |
| D8          | MISO        | Master Input, Slave Output |
| D7          | MOSI        | Master Output, Slave Input |
| D6          | SCK         | Clock Serial             |
| D5          | NSS         | Chip Select (CS)         |
| D2          | DIO1        | Interrupção Digital      |
| D3          | BUSSY       | Status do Módulo         |
| D4          | RESET       | Reset do Módulo          |

> ⚠ **Atenção:** O SX1280 opera com tensão de 3.3V. Caso o seu Arduino opere a 5V, utilize um conversor de nível lógico para evitar danos ao módulo.

---

## 📦 Dependências

Este projeto utiliza a biblioteca `RadioLib` para comunicação com o módulo SX1280. Para instalar:

1. Abra o **Arduino IDE**.
2. Acesse **Sketch** > **Include Library** > **Manage Libraries**.
3. Procure por `RadioLib` e clique em **Install**.

---

## 🖥️ Código Básico

Abaixo, um exemplo simples para inicializar o módulo SX1280 e realizar a transmissão de mensagens:

```cpp
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
