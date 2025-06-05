# Projeto HydroSafe Tech - Monitoramento do Nível dos Rios

## Descrição do Problema

Em muitas regiões, enchentes causam alagamentos que afetam ruas, residências e áreas de risco, causando danos materiais e colocando vidas em perigo. A falta de alertas locais rápidos dificulta a tomada de decisões preventivas pela população e autoridades. Monitorar o nível da água dos rios em tempo real é essencial para avisar sobre riscos iminentes de enchentes e alagamentos.

## Visão Geral da Solução

O **HydroSafe Tech** é um sistema de monitoramento do nível da água utilizando um Arduino, sensor ultrassônico, LEDs indicativos, buzzer sonoro e uma tela LCD para exibir as informações. O sistema mede a distância da superfície da água até o sensor, avaliando o nível do rio e indicando o risco com base em faixas pré-definidas:

* **Risco Baixo:** nível da água abaixo de 100 cm — LED verde aceso, buzzer desligado.
* **Risco Moderado:** nível entre 50 cm e 100 cm — LED amarelo aceso, buzzer desligado.
* **Risco Crítico:** nível abaixo de 50 cm — LED vermelho aceso, buzzer ligado emitindo alerta sonoro.

O sistema é montado em um circuito Arduino simulado no Wokwi, apresentando uma solução simples, econômica e eficaz para alertas locais de enchentes.

### Componentes utilizados:

* Arduino Uno
* Sensor ultrassônico HC-SR04 (para medir a altura da água)
* Display LCD 16x2 com interface I2C (para exibir distância e status)
* LEDs verde, amarelo e vermelho (indicadores visuais do nível de risco)
* Buzzer piezo (alerta sonoro no risco crítico)

## Guia para simular o projeto no Wokwi

1. Acesse o [Wokwi](https://wokwi.com/).
2. Crie um novo projeto Arduino.
3. Insira os componentes:

   * Arduino Uno
   * Sensor ultrassônico HC-SR04
   * Display LCD 16x2 I2C
   * LEDs (verde, amarelo e vermelho)
   * Buzzer piezo
4. Faça as conexões conforme o código e a descrição:

   * Sensor ultrassônico: trig no pino 13, echo no pino 12
   * LEDs: verde no 8, amarelo no 9, vermelho no 10
   * Buzzer no pino 11
   * LCD I2C no endereço 0x27 (pinos SDA e SCL do Arduino)
5. Copie e cole o código-fonte do projeto no editor do Wokwi.
6. Clique em “Start Simulation” para rodar o projeto.
7. Observe o display LCD mostrando a altura da água e o LED/buzzer indicando o risco.

### Link direto para o projeto no Wokwi

https://wokwi.com/projects/432949577457076225

## Link para o vídeo demonstrativo

