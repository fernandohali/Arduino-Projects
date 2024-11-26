# Envio de Dados via LoRa com Módulo SX1280

Este projeto demonstra como enviar um conjunto de dados inteiros usando o módulo SX1280 LoRa. O programa converte os números inteiros em uma string e os envia como pacotes usando o protocolo LoRa. Um LED é usado para indicar o status da transmissão e o monitor serial exibe detalhes sobre o envio dos pacotes.

## Materiais Necessários

- Arduino Uno ou compatível
- Módulo SX1280 LoRa
- LEDs e resistores para indicações visuais
- Fios de conexão

## Diagrama de Conexão

1. **Módulo LoRa SX1280**:

   - Conecte os pinos SPI do módulo LoRa ao Arduino conforme as configurações definidas no código.

2. **LEDs**:
   - Conecte um LED ao pino `LED1` para indicar o status da transmissão.

## Funcionamento

O código envia um conjunto de números inteiros como pacotes LoRa. A cada pacote transmitido, o monitor serial exibe o número do pacote, a string de dados e o tempo de envio. O LED1 acende enquanto o pacote está sendo transmitido.

## Como Usar

1. Faça o upload do código para o seu Arduino.
2. Conecte o módulo LoRa e o LED conforme o diagrama de conexão.
3. Abra o monitor serial para visualizar as informações sobre o envio dos pacotes.
4. O LED1 indicará o status da transmissão.

## Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
