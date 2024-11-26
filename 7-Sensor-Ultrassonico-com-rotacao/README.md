# Sensor Ultrassônico com Motor Servo, LEDs e Buzzer

Este projeto utiliza um sensor ultrassônico para medir a distância e, com base no valor dessa distância, aciona LEDs e um buzzer. Além disso, um motor servo é utilizado para realizar uma varredura de 0 a 180 graus e detectar objetos em várias direções.

## Materiais Necessários

- Arduino Uno (ou compatível)
- Sensor Ultrassônico (HC-SR04)
- Motor Servo
- LEDs (Vermelho e Verde)
- Buzzer
- Fios de conexão

## Diagrama de Conexão

1. **Sensor Ultrassônico**:

   - **Trig**: Pino 10.
   - **Echo**: Pino 9.

2. **Motor Servo**:

   - Conecte ao pino 12.

3. **LEDs**:

   - **LED Vermelho 1**: Pino 2.
   - **LED Vermelho 2**: Pino 4.
   - **LED Verde**: Pino 3.

4. **Buzzer**:
   - Conecte ao pino 7.

## Funcionamento

- O motor servo realiza uma varredura de 0 a 180 graus e depois retorna de 180 a 0 graus.
- Para cada posição do servo, o sensor ultrassônico calcula a distância.
- Dependendo da distância:
  - **Menor que 20 cm**: Acende os LEDs vermelhos, ativa o buzzer.
  - **Entre 20 e 40 cm**: Acende o LED verde, alterna o buzzer e LED vermelho.
  - **Maior que 40 cm**: Desliga o buzzer e apaga o LED verde.

## Como Usar

1. Faça o upload do código para o seu Arduino.
2. Conecte o sensor ultrassônico, motor servo, LEDs e buzzer conforme o diagrama de conexão.
3. O motor servo começará a realizar a varredura e o sistema fornecerá feedback sonoro e visual com base nas distâncias detectadas.

## Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
