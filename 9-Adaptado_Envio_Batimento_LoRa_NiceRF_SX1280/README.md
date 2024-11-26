# Envio de Dados de Eletrocardiograma (ECG) via LoRa com Módulo SX1280

Este projeto demonstra como enviar dados de batimentos cardíacos (ECG) usando o módulo LoRa SX1280, utilizando o Arduino. Os dados de ECG são coletados de um arquivo TXT (ou XLSX), convertidos e enviados via LoRa para outro dispositivo receptor.

## Materiais Necessários

- **Arduino Uno** ou compatível
- **Módulo SX1280 LoRa**
- **LED** e resistores para indicar o status de transmissão
- **Fios de conexão**

## Diagrama de Conexão

1. **Módulo LoRa SX1280**:
   - Conecte os pinos SPI do módulo LoRa ao Arduino conforme as configurações no código.
2. **LED**:
   - Conecte um LED ao pino `LED1` para indicar o status da transmissão.

## Funcionamento

O código realiza as seguintes etapas:
1. Coleta os dados do ECG a partir de um arquivo de texto (ou um array de inteiros).
2. Converte os valores para uma string de caracteres.
3. Envia os dados em pacotes via LoRa utilizando o módulo SX1280.
4. Exibe o status da transmissão no monitor serial e acende um LED durante a transmissão.
5. O receptor coleta os pacotes LoRa e exibe os dados recebidos no monitor serial.

### Etapas de Implementação:

1. **Seleção de Dados**:
   Os dados de ECG são extraídos e convertidos para um formato adequado. Cada conjunto de dados representa um batimento cardíaco.

2. **Conversão de Dados**:
   A conversão dos dados de inteiros para caracteres é realizada para que possam ser transmitidos como pacotes LoRa.

3. **Transmissão de Dados**:
   Os dados são transmitidos em pacotes via LoRa. O LED indica quando os pacotes estão sendo enviados.

4. **Recepção de Dados**:
   O dispositivo receptor coleta os pacotes e exibe os dados no monitor serial.

5. **Visualização Gráfica**:
   Após a recepção dos dados, um gráfico pode ser gerado em uma ferramenta como o Excel para visualizar os batimentos cardíacos.

