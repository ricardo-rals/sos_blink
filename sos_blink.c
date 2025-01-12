#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos tempos em milissegundos
#define DOT_TIME 200      // 0,2 segundos
#define DASH_TIME 800     // 0,8 segundos
#define GAP_TIME 125      // 0,125 segundos
#define LETTER_GAP_TIME 250 // 0,25 segundos
#define CYCLE_DELAY 3000    // 3 segundos

// GPIO utilizada para o LED
#define LED_PIN 11

void blink_led(int duration_ms) {
    gpio_put(LED_PIN, 1);
    sleep_ms(duration_ms);
    gpio_put(LED_PIN, 0); 
}

void blink_dot() {
    blink_led(DOT_TIME);
    sleep_ms(GAP_TIME); 
}

void blink_dash() {
    blink_led(DASH_TIME);
    sleep_ms(GAP_TIME);
}

void blink_sos() {
    // Enviar três pontos (.)
    for (int i = 0; i < 3; i++) {
        blink_dot();
    }
    sleep_ms(LETTER_GAP_TIME);

    // Enviar três traços (-)
    for (int i = 0; i < 3; i++) {
        blink_dash();
    }
    sleep_ms(LETTER_GAP_TIME);

    // Enviar três pontos (.)
    for (int i = 0; i < 3; i++) {
        blink_dot();
    }
    sleep_ms(CYCLE_DELAY); 
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);


    while (1) {
        blink_sos();
    }
    return 0;
}
