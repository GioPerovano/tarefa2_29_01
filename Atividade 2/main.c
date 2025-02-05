#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Definição dos pinos
#define LED_AZUL 11
#define LED_VERMELHO 12
#define LED_VERDE 13
#define BOTAO 5

// Estados possíveis do sistema
typedef enum {
    ESTADO_INICIAL,
    TODOS_ACESOS,
    AZUL_APAGADO,
    VERMELHO_APAGADO,
    VERDE_APAGADO
} EstadoLED;

volatile EstadoLED estado_atual = ESTADO_INICIAL;
volatile bool botao_habilitado = true; // Controla a disponibilidade do botão

// Função para debounce do botão
bool debounce() {
    static uint32_t ultima_acao = 0;
    uint32_t tempo_atual = to_ms_since_boot(get_absolute_time());

    if (tempo_atual - ultima_acao < 200) { // Tempo mínimo de debounce
        return false;
    }

    ultima_acao = tempo_atual;
    return true;
}

// Callback para alternar os estados dos LEDs
int64_t alternar_estado_leds(alarm_id_t id, void *user_data) {
    if (estado_atual == ESTADO_INICIAL) {
        return 0;
    }

    switch (estado_atual) {
        case TODOS_ACESOS:
            gpio_put(LED_AZUL, 0);
            estado_atual = AZUL_APAGADO;
            add_alarm_in_ms(3000, alternar_estado_leds, NULL, false);
            break;
        case AZUL_APAGADO:
            gpio_put(LED_VERMELHO, 0);
            estado_atual = VERMELHO_APAGADO;
            add_alarm_in_ms(3000, alternar_estado_leds, NULL, false);
            break;
        case VERMELHO_APAGADO:
            gpio_put(LED_VERDE, 0);
            estado_atual = VERDE_APAGADO;
            botao_habilitado = true; // Libera o botão para nova ativação
            break;
        default:
            break;
    }
    return 0;
}

// Callback para o acionamento do botão
void tratar_botao(uint gpio, uint32_t eventos) {
    if (gpio == BOTAO && debounce() && botao_habilitado) {
        botao_habilitado = false; // Impede nova ativação até o ciclo ser concluído

        // Acende todos os LEDs
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_VERDE, 1);
        estado_atual = TODOS_ACESOS;

        // Inicia a transição entre os estados
        add_alarm_in_ms(3000, alternar_estado_leds, NULL, false);
    }
}

int main() {
    stdio_init_all();

    // Configuração dos LEDs
    gpio_init(LED_AZUL);
    gpio_init(LED_VERMELHO);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Inicializa os LEDs apagados
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_VERDE, 0);

    // Configuração do botão
    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    // Configuração da interrupção do botão
    gpio_set_irq_enabled_with_callback(BOTAO, GPIO_IRQ_EDGE_FALL, true, &tratar_botao);

    // Loop principal
    while (1) {
        tight_loop_contents(); // Mantém o loop rodando
    }
}
