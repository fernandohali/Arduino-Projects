# Projeto de Controle de LEDs com Sensor Ultrassônico

Este projeto usa um sensor ultrassônico para medir a distância de um objeto e acionar LEDs de acordo com a proximidade. Quanto mais perto o objeto, mais LEDs são acesos.

## Materiais Necessários

- Arduino Uno (ou compatível)
- Sensor Ultrassônico (HC-SR04 ou similar)
- 3 LEDs
- 3 resistores de 220 ohms
- Fios de conexão

## Diagrama de Conexão

1. Conecte o pino **Trig** do sensor no pino 7 do Arduino.
2. Conecte o pino **Echo** do sensor no pino 6 do Arduino.
3. Conecte os LEDs nos pinos 2, 3 e 4, com resistores de 220 ohms em série.

## Código

O código utiliza a biblioteca padrão para controlar o sensor ultrassônico e calcula a distância em centímetros e polegadas. Com base na distância medida, o código acende diferentes LEDs.

### Lógica de LEDs:

- **LED1 (pino 2)**: Acende quando a distância for menor ou igual a 350 cm.
- **LED2 (pino 3)**: Acende quando a distância for menor ou igual a 250 cm.
- **LED3 (pino 4)**: Acende quando a distância for menor ou igual a 100 cm.

Quando a distância for superior a 350 cm, todos os LEDs serão apagados.

## Como Usar

1. Faça o upload do código para o seu Arduino.
2. Conecte o sensor ultrassônico e os LEDs de acordo com o diagrama de conexão.
3. Abra o monitor serial para visualizar a distância medida em centímetros e polegadas.
4. Observe os LEDs acendendo conforme a distância medida.

## Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
