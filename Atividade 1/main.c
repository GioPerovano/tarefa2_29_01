#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Definição dos GPIOs para os LEDs
#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

// Estados do semáforo
typedef enum {
    RED,
    YELLOW,
    GREEN
} TrafficLightState;

volatile TrafficLightState current_state = RED; // Começa no vermelho

// Função de callback para mudar o estado do semáforo
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (current_state) {
        case RED:
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 1);
            current_state = YELLOW;
            break;
        case YELLOW:
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 1);
            current_state = GREEN;
            break;
        case GREEN:
            gpio_put(LED_GREEN, 0);
            gpio_put(LED_RED, 1);
            current_state = RED;
            break;
    }
    return true; // Continua o temporizador
}

int main() {
    stdio_init_all();

    printf("************* INÍCIO DO PROGRAMA *************\n\n");

    // Configuração dos LEDs
    gpio_init(LED_RED);
    gpio_init(LED_YELLOW);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Inicializa com o LED vermelho ligado
    gpio_put(LED_RED, 1);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);

    // Configura um temporizador para alternar os LEDs a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (1) {
        switch (current_state) {
            case RED:
                printf("Semáforo na cor vermelha. PARE!\n");
                break;
            case YELLOW:
                printf("Semáforo na cor amarela. ATENÇÃO!\n");
                break;
            case GREEN:
                printf("Semáforo na cor verde. PROSSIGA!\n");
                break;
        }
        sleep_ms(1000); // Imprime mensagem a cada 1 segundo
    }
}
