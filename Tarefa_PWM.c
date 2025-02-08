#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define PWM_pin 22

#define div_value 50.0
#define wrap_value 50000
#define degree_180 6000
#define degree_90 3675
#define degree_0 1250
#define change_value 12.5

int main()
{
    uint slice_num;
    float i;

    stdio_init_all();

    gpio_set_function(PWM_pin, GPIO_FUNC_PWM);

    slice_num = pwm_gpio_to_slice_num(PWM_pin);

    pwm_set_clkdiv(slice_num, div_value);
    pwm_set_wrap(slice_num, wrap_value);
    pwm_set_gpio_level(PWM_pin, degree_180);

    pwm_set_enabled(slice_num, true);
    sleep_ms(5000);

    pwm_set_gpio_level(PWM_pin, degree_90);
    sleep_ms(5000);

    pwm_set_gpio_level(PWM_pin, degree_0);
    sleep_ms(5000);

    while (true) {
        for(i=(float)degree_0;i<(float)degree_180;i+=change_value) {
            pwm_set_gpio_level(PWM_pin, (uint16_t)i);
            sleep_ms(10);
        }
        for(i=(float)degree_180;i>(float)degree_0;i-=change_value) {
            pwm_set_gpio_level(PWM_pin, (uint16_t)i);
            sleep_ms(10);
        }
    }
}