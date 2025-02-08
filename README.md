# Tarefa do EmbarcaTech para Controle de Servomotor com Raspberry Pi Pico W
  - **Desenvolvedor:** <ins>Gabriel Cavalcanti Coelho</ins>;
  - **Vídeo:** [YouTube](https://www.youtube.com/).

### Este projeto implementa o controle de um servomotor utilizando PWM no Raspberry Pi Pico W. O código configura o PWM para operar com uma frequência próxima a 50 Hz e permite o controle da posição do servomotor, variando entre 0 e 180 graus.

**Funcionamento:**
  - O código configura o pino 22 do Raspberry Pi Pico W como saída PWM;
  - Define os parâmetros do PWM, como divisor de clock e wrap;
  - Move o servomotor entre três posições fixas (0°, 90° e 180°) inicialmente.
  - Após 5 segundos em cada posição fixa, inicia um loop contínuo que faz o servomotor variar suavemente entre 0° e 180° e vice-versa.

**Instruções de Uso:**
  - Instale e configure a extensão do Raspberry Pi Pico no VSCode;
  - Instale e configure a do wokwi no VSCode;
  - Compile o código;
  - Acesse o diagram.json e execute o programa.
