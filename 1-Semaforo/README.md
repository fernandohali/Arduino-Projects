# Projeto: Semáforo

Este é um projeto simples em **C++ para Arduino**, que implementa o controle sequencial de um semáforo utilizando LEDs ou outros dispositivos conectados. Ele utiliza três pinos digitais do Arduino para simular o funcionamento de um semáforo, com tempos configuráveis para cada etapa.

## Funcionalidades

- Acionamento sequencial de dispositivos (LEDs, relés, etc.).
- Temporizações definidas para cada etapa, simulando o comportamento de um semáforo real.
- Código simples e bem documentado para facilitar o entendimento e a modificação.

## Requisitos

- **Arduino** (ou placa compatível).
- Três LEDs (ou outros dispositivos) conectados aos pinos digitais 13, 12 e 7.
- Resistores para proteção dos LEDs (se utilizados).

## Circuito

1. Conecte os LEDs aos pinos digitais do Arduino:
   - Pino 13: LED vermelho.
   - Pino 12: LED amarelo.
   - Pino 7: LED verde.
2. Ligue os cátodos dos LEDs ao **GND** do Arduino.
3. Adicione resistores apropriados para limitar a corrente (se necessário).

## Código

O código é dividido em duas partes principais:

### Configuração (`setup`)

Configura os pinos 13, 12 e 7 como saídas.

```cpp
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
}
