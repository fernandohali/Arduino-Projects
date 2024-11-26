# Projeto de Controle com Sensor Infravermelho e LCD 16x2

Este projeto utiliza um sensor infravermelho para receber sinais de um controle remoto e exibe informações em um display LCD 16x2.

## Materiais Necessários

- Arduino Uno (ou compatível)
- Receptor Infravermelho (IR)
- Display LCD 16x2
- Controle remoto (qualquer controle que envie comandos IR compatíveis)
- Fios de conexão

## Diagrama de Conexão

1. **Sensor IR**:
   - **IR RECEIVER**: Conecte ao pino 10 do Arduino.
   
2. **LCD 16x2**:
   - **RS**: Pino 12.
   - **Enable**: Pino 11.
   - **D4**: Pino 5.
   - **D5**: Pino 4.
   - **D6**: Pino 3.
   - **D7**: Pino 2.

## Código

O código lê os sinais de um controle remoto IR e executa ações baseadas nos comandos recebidos, como exibir ou limpar informações no display LCD.

### Comandos IR:
- **Comando 69**: Limpa a tela do LCD após 1 segundo.
- **Comando 70** e **Comando 71**: (Ações a serem definidas).

## Como Usar

1. Faça o upload do código para o seu Arduino.
2. Conecte o sensor infravermelho e o display LCD conforme o diagrama de conexão.
3. Aponte o controle remoto para o receptor IR e pressione os botões para enviar os comandos.
4. Observe a mudança no LCD de acordo com o comando recebido.

## Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
