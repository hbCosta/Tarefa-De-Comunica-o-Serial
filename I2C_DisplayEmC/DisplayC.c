/*
 * Por: Wilton Lacerda Silva
 *    Comunicação serial com I2C
 *  
 * Uso da interface I2C para comunicação com o Display OLED
 * 
 * Estudo da biblioteca ssd1306 com PicoW na Placa BitDogLab.
 *  
 * Este programa escreve uma mensagem no display OLED.
 * 
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "inc/ssd1306.h"
#include "hardware/clocks.h"
#include "inc/font.h"
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C
#define tempo 2500


const uint button_A = 5;
const uint button_B = 6;

const uint led_red_pin = 13;
const uint led_blue_pin = 12;
const uint led_green_pin = 11;


void inicializar_botoes(){
  gpio_init(button_A);
  gpio_init(button_B);

  gpio_set_dir(button_A, GPIO_IN);
  gpio_set_dir(button_B, GPIO_IN);

  gpio_pull_up(button_A);
  gpio_pull_up(button_B);
}

void inicializar_led(){
  gpio_init(led_green_pin);              // Inicializa o pino do LED
  gpio_set_dir(led_green_pin, GPIO_OUT); // Configura o pino como saída
  gpio_init(led_blue_pin);              // Inicializa o pino do LED
  gpio_set_dir(led_blue_pin, GPIO_OUT); // Configura o pino como saída
}

static volatile uint32_t a = 1;
static volatile uint32_t last_time = 0; // Armazena o tempo do último evento (em microssegundos)


// Função de interrupção com debouncing
void gpio_irq_handler(uint gpio, uint32_t events)
{
    // Obtém o tempo atual em microssegundos
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    printf("A = %d\n", a);
    // Verifica se passou tempo suficiente desde o último evento
    if (current_time - last_time > 200000) // 200 ms de debouncing
    {
        last_time = current_time; // Atualiza o tempo do último evento
        if(gpio == button_A){
          gpio_put(led_green_pin, !gpio_get(led_green_pin)); // Alterna o estado
          printf("Botão A pressionado - LED verde alterado\n");
        }else if(gpio == button_B){
          gpio_put(led_blue_pin, !gpio_get(led_blue_pin));
          printf("Botão B pressionado - LED azul alterado\n");

        }

        a++;                                     // incrementa a variavel de verificação
    }
}

int main()
{
  stdio_init_all(); // Inicializa comunicação USB CDC para monitor serial

  // I2C Initialisation. Using it at 400Khz.
  i2c_init(I2C_PORT, 400 * 1000);

  gpio_set_function(I2C_SDA, GPIO_FUNC_I2C); // Set the GPIO pin function to I2C
  gpio_set_function(I2C_SCL, GPIO_FUNC_I2C); // Set the GPIO pin function to I2C
  gpio_pull_up(I2C_SDA); // Pull up the data line
  gpio_pull_up(I2C_SCL); // Pull up the clock line
  ssd1306_t ssd; // Inicializa a estrutura do display
  ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Inicializa o display
  ssd1306_config(&ssd); // Configura o display
  ssd1306_send_data(&ssd); // Envia os dados para o display

  // Limpa o display. O display inicia com todos os pixels apagados.
  ssd1306_fill(&ssd, false);
  ssd1306_send_data(&ssd);
  bool cor = true;
  inicializar_botoes();
  inicializar_led();

  // Configuração da interrupção com callback
  gpio_set_irq_enabled_with_callback(button_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
  gpio_set_irq_enabled_with_callback(button_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

  while (true)
  {
    cor = !cor;
    // Atualiza o conteúdo do display com animações
    //ssd1306_fill(&ssd, !cor); // Limpa o display
    /*ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    ssd1306_draw_string(&ssd, "CEPEDI   TIC37", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "EMBARCATECH", 20, 30); // Desenha uma string
    ssd1306_draw_string(&ssd, "PROF WILTON", 15, 48); // Desenha uma string      
    */
    if(stdio_usb_connected()){
      char c;
      if(scanf("%c",&c) ==1){
        if(c >= 'a' && c <= 'z'){
          ssd1306_draw_char(&ssd, c, 15, 48);
        }
      }
    }
    ssd1306_send_data(&ssd); // Atualiza o display


    



    sleep_ms(1000);
  }
}