# Projeto de indicador de temperatura com Arduino

Este projeto utiliza um sensor DHT22 para monitorar a temperatura ambiente e aciona uma barra de LEDs conforme o nível de temperatura detectado. Se a temperatura ultrapassar 50°C, todos os LEDs acendem como um aviso.

## Componentes Necessários

- 1x Arduino (Uno, Mega, etc.)
- 1x Sensor de temperatura e umidade DHT22
- 10x LEDs
- 10x Resistores (220Ω ou 330Ω)
- Jumpers
- Protoboard

## Conexões

1. **Sensor DHT22:**
   - VCC -> 5V do Arduino
   - GND -> GND do Arduino
   - DATA -> Pino A5 do Arduino (com um resistor pull-up de 10kΩ se necessário)

2. **LEDs:**
   - Anodos (perna longa) dos LEDs conectados aos pinos digitais 12, 11, 10, 9, 8, 7, 6, 5, 4 e 3 do Arduino através dos resistores
   - Catodos (perna curta) dos LEDs conectados ao GND do Arduino

## Código

Carregue o código do arquivo 'sketch.ino' no seu Arduino.

## Funcionamento

1. **Início:** O Arduino inicializa e configura os pinos dos LEDs e o sensor DHT22.
2. **Loop:**
   - A cada 2 segundos, o Arduino lê a temperatura do sensor DHT22.
   - A temperatura é mapeada para um valor entre 0 e 10, correspondente ao número de LEDs que serão acesos.
   - Se a temperatura ultrapassar 50°C, todos os LEDs são acesos.
   - A temperatura é enviada ao monitor serial para visualização.

## Autor

- Gustavo Atanazio, RM: 559098
- Gustavo do Espírito Santo, RM: 559034
- Heitor Prestes, RM: 554823
- Lucca Cardinale, RM: 556668
- Mohamed Afif, RM: 554445
