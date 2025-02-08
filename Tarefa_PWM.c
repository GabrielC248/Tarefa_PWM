#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

// Definição do pino de saída do PWM
#define PWM_pin 22

// Definições dos parâmetros para o PWM
#define div_value 50.0    // Valor do divisor de clock do PWM
#define wrap_value 50000  // Valor do wrap
#define degree_180 6000   // Valor correspondente a 180 graus
#define degree_90 3675    // Valor correspondente a 90 graus
#define degree_0 1250     // Valor correspondente a 0 graus
#define change_value 12.5 // Valor do incremento e do decremento para a variação do PWM

/*
COMENTÁRIOS SOBRE AS DEFINIÇÕES PARA O PWM

Para definir o Wrap, pensei em um valor próximo ao default (65535) e que parecesse mais 
compatível com os cálculos que eu precisaria fazer e então, após isso, encontrei o valor inteiro do divisor;

Como a tarefa não exigiu que a frequência seja exatamente 50 Hz, mantive o wrap em 50000, o que, nos
cálculos da frequência do PWM, resulta em: 125000000/((50+0/16)×(50000+1)) ≈ 49,999 Hz.
*/

int main()
{
    uint slice_num; // Variável para armazenar o número do slice do PWM
    float i;        // Variável auxiliar para a variação do PWM

    stdio_init_all();

    gpio_set_function(PWM_pin, GPIO_FUNC_PWM); // Configura o pino como PWM

    slice_num = pwm_gpio_to_slice_num(PWM_pin); // Obtém o número do slice associado ao pino

    pwm_set_clkdiv(slice_num, div_value); // Configura o divisor de clock do PWM
    pwm_set_wrap(slice_num, wrap_value);  // Define o wrap do PWM

    pwm_set_gpio_level(PWM_pin, degree_180); // Define o nível inicial como 180 graus
    pwm_set_enabled(slice_num, true);        // Habilita o PWM no slice
    sleep_ms(5000);                          // Pausa 5 segundos

    pwm_set_gpio_level(PWM_pin, degree_90); // Move para 90 graus
    sleep_ms(5000);                         // Pausa 5 segundos

    pwm_set_gpio_level(PWM_pin, degree_0); // Move para 0 graus
    sleep_ms(5000);                        // Pausa 5 segundos

    while (true) {

        // Move de 0 até 180 graus
        for(i=(float)degree_0;i<(float)degree_180;i+=change_value) {
            pwm_set_gpio_level(PWM_pin, (uint16_t)i); // Atualiza o nível PWM
            sleep_ms(10);                             // Atraso de de ajuste 10 ms
        }

        // Move de 180 até 0 graus
        for(i=(float)degree_180;i>(float)degree_0;i-=change_value) {
            pwm_set_gpio_level(PWM_pin, (uint16_t)i); // Atualiza o nível PWM
            sleep_ms(10);                             // Atraso de ajuste de 10 ms
        }

    }
}