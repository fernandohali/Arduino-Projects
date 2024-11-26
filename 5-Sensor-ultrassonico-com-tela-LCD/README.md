# Projeto de Sensor Ultrassônico com Display LCD

Este projeto utiliza um sensor ultrassônico para medir a distância de um objeto e exibir a medida tanto em centímetros quanto em polegadas em um display LCD.

## Materiais Necessários

- Arduino Uno (ou compatível)
- Sensor Ultrassônico (HC-SR04 ou similar)
- Display LCD 16x2
- Fios de conexão

## Diagrama de Conexão

1. **Sensor Ultrassônico**:
   - **Trigger**: Conecte no pino 7 do Arduino.
   - **Echo**: Conecte no pino 6 do Arduino.
   
2. **LCD 16x2**:
   - **RS**: Conecte no pino 12 do Arduino.
   - **Enable**: Conecte no pino 11 do Arduino.
   - **D4**: Conecte no pino 5 do Arduino.
   - **D5**: Conecte no pino 4 do Arduino.
   - **D6**: Conecte no pino 3 do Arduino.
   - **D7**: Conecte no pino 2 do Arduino.

## Código

O código lê a distância do sensor ultrassônico e exibe a medida no display LCD, tanto em centímetros quanto em polegadas. Ele também imprime a distância no monitor serial para depuração.

### Exibição no LCD:

- **Primeira Linha**: Exibe a distância em centímetros.
- **Segunda Linha**: Exibe a distância em polegadas.

## Como Usar

1. Faça o upload do código para o seu Arduino.
2. Conecte o sensor ultrassônico e o display LCD conforme o diagrama de conexão.
3. Abra o monitor serial para ver a distância também sendo exibida.
4. Observe o LCD atualizando a distância a cada segundo.

## Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
