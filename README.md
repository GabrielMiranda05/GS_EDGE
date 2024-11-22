# Projeto IoT com ESP32, MQTT e Node-RED

### ALUNOS

Kheyla Thais RM558434

Gabriel Miranda RM559102

Vinicius Henrique RM556908

## Descrição

O objetivo deste projeto é coletar dados de corrente e potência, com visualização em tempo real em dashboards utilizando o NODE-RED, e futuramente serem enviados para o nosso modelo preditivo em Python (repositorio do modelo: **colocar link do modelo preditivo em python**) Para ser utilizado em politicas publicas, a fim de coletar e prever qual bairro da cidade de São Paulo tera o maior gasto com energia eletrica, assim disponibilizando um melhor filtro no momento de enviar campanhas de concientização sobre economia de energia. 

## Limitações Wokwi

No entanto, devido a limitações do simulador Wokwi, os sensores originalmente planejados para realizar essa coleta foram substituídos por potenciômetros. Esses potenciômetros simulam os dados de corrente e potência, permitindo que o projeto seja desenvolvido e testado enquanto aguardamos a implementação dos sensores reais.

## Componentes Utilizados

- **ESP32**: Microcontrolador para coleta de dados e envio via MQTT.
- **Potenciômetro**: Sensor analógico para leitura de valores variáveis.
- **Node-RED**: Plataforma de automação visual para processar e exibir os dados.
- **MQTT**: Protocolo de comunicação utilizado para enviar os dados do ESP32 para o Node-RED.
- **LEDS**: Leds utilizados para visualização e confirmação de conexão Wifi/MQTT

## Arquitetura

1. **Leitura do Potenciômetro**: O ESP32 coleta o valor analógico do potenciômetro através de uma entrada ADC (Conversor Analógico-Digital).
2. **Envio via MQTT**: O valor lido é enviado para um broker MQTT. Pode-se utilizar o **Mosquitto** ou outro broker MQTT.
3. **Node-RED**: No Node-RED, há um fluxo configurado para ler os dados do broker MQTT e exibir no dashboard de forma interativa.

## Pré-requisitos

- **Hardware**:
  - 1x ESP32
  - 1x Potenciômetro
  - Fios de conexão (Jumpers)
  - 2x LEDS com cores diferentes
  - 2x Resistores (minimo 150 Ω)

- **Software**:
  - Wokwi (para programação do ESP32 e simulação da montagem do dispositivo)
  - Node-RED (para criação do dashboard)
  - Broker MQTT (pode ser local ou na nuvem, como o **Mosquitto**)
  - Biblioteca PubSubClient (para MQTT)

## Passos para Configuração

### 1. Configuração do ESP32

1. Abra o modelo base do **ESP32** no Wokwi > https://wokwi.com/projects/new/esp32
2. Instale a biblioteca **PubSubClient** para a comunicação MQTT.
   - Clique no canto superior direito em Library Manager > Botão + > Procure por **PubSubClient** e instale.
     
2. Configuração do Node-RED
   - Baixe e instale o Node.js conforme o site oficial > https://nodejs.org/pt
   - Siga o guia de instalação do Node-red > https://inetec.com.br/como-instalar-node-red-passo-a-passo-completo/ 

### Configuração do Dashboard:

Instale o pacote do dashboard do Node-RED (se ainda não estiver instalado):
Acesse a interface do Node-RED no navegador e vá em Menu > Manage palette > Install.
Procure por "node-red-dashboard" e instale.

Importe o arquivlo "flows.json" para dentro do node-red
 
### Teste e Monitoramento
Após carregar o código no ESP32, verifique o serial monitor para garantir que o ESP32 está conectado ao Wi-Fi e ao broker MQTT.
No Node-RED, abra o dashboard para ver os valores do potenciômetro sendo atualizados a cada 2 segundos.
Exemplos de Dashboard no Node-RED
Você pode criar widgets de visualização no Node-RED, como:

Gráfico de linha: Para exibir os valores de leitura do potenciômetro ao longo do tempo.
Display: Para mostrar o valor atual do potenciômetro.
Conclusão
Este projeto demonstra como integrar o ESP32 com o protocolo MQTT e o Node-RED para criar uma solução IoT simples, mas poderosa, para monitorar dados de sensores em tempo real. Você pode expandir esse projeto para incluir mais sensores, controle de dispositivos ou automações, conforme suas necessidades.

Possíveis Melhorias
Implementar autenticação no MQTT para maior segurança.
Criar automações no Node-RED baseadas nos valores do sensor.
