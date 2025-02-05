# 🚦 Projeto: Temporizadores no Raspberry Pi Pico W

## 📌 Unidade 4 | Capítulo 5 – C5O123A
📅 Data: 29/01/2025

Este projeto consiste na implementação de temporizadores no **Raspberry Pi Pico W** utilizando a **Pico SDK**. Ele é dividido em duas atividades principais:

1. **Temporizador periódico** - Implementação de um semáforo com temporização de 3 segundos.
2. **Temporizador de um disparo (One Shot)** - Controle de LEDs ativado por um botão.

---

## 📝 Atividade 1: Temporizador Periódico

### 🎯 Objetivo
Criar um **semáforo** que altera os sinais de trânsito a cada **3 segundos** utilizando a função `add_repeating_timer_ms()`.

### 🛠️ Componentes necessários
- 🖥️ **Microcontrolador**: Raspberry Pi Pico W
- 💡 **LEDs**: Vermelho, Amarelo e Verde
- ⚡ **Resistores**: 3x de 330 Ω
- 🛠️ Simulador Wokwi:

### 📌 Requisitos
✔️ O semáforo inicia no **vermelho**, alternando para **amarelo** e depois **verde**.
✔️ Cada alteração de estado ocorre a cada **3 segundos (3.000ms)**.
✔️ A mudança de estado dos LEDs ocorre dentro da **função de callback** do temporizador (`repeating_timer_callback()`).
✔️ No loop principal (`while`), uma mensagem deve ser impressa a cada **1 segundo (1.000ms)**.
✔️ Utilizar a ferramenta **BitDogLab** para testar o código com **LED RGB nos GPIOs 11, 12 e 13**.

---

## 📝 Atividade 2: Temporizador de Um Disparo (One Shot)

### 🎯 Objetivo
Criar um sistema de **temporização acionado por um botão** utilizando a função `add_alarm_in_ms()`.

### 🛠️ Componentes necessários
- 🖥️ **Microcontrolador**: Raspberry Pi Pico W
- 💡 **LEDs**: Azul, Vermelho e Verde
- ⚡ **Resistores**: 3x de 330 Ω
- 🔘 **Botão (Pushbutton)**
- 🛠️ Simulador Wokwi: https://wokwi.com/projects/422013525719079937

### 📌 Requisitos
✔️ **Ao pressionar o botão**, todos os LEDs acendem e começam a desligar um a um, com atraso de **3 segundos** entre as transições.
✔️ A lógica de controle dos LEDs deve ser implementada em **funções de callback** do temporizador (`turn_off_callback()`).
✔️ O botão **só pode ser acionado novamente após o desligamento do último LED**.
✔️ Utilizar a ferramenta **BitDogLab** para testar o código com **LED RGB nos GPIOs 11, 12 e 13 e o botão A no GPIO 05**.
✔️ **(Opcional)** Implementar um software **debounce** para o botão.

---

## 🔧 Ambiente de Desenvolvimento
📌 **Ferramentas utilizadas:**
- **VS Code** para desenvolvimento.
- **Linguagem C** com **Pico SDK**.
- **Simulador Wokwi** integrado ao VS Code.
- **GitHub** para versionamento e submissão da atividade.

### 📂 Estrutura do Repositório
```plaintext
📦 Atividades
 ┣ 📂 Atividade 1
 ┣  ┣ 📜 main.c                # Código da Atividade 1
 ┣  ┣ 📜 diagram.json          # Diagrama do Wokwi da atividade 1
 ┣ 📂 Atividade 2              
 ┣  ┣ 📜 main.c                # Código-fonte do projeto
 ┣  ┣ 📜 diagram.json          # Código-fonte do projeto
 ┣ 📜 CMakeLists.txt           # Configuração do projeto
 ┣ 📜 README.md                # Instruções de uso (este arquivo)
```

---

## 🚀 Como Executar o Projeto

1. **Adicione e certifique-se de ter as dependências e bibliotecas necessárias já instaladas e configuradas.**
2. **Clone este repositório:**
   ```bash
   git clone https://github.com/seu-usuario/projeto-temporizadores-pico.git
   ```
3. **Entre na pasta do projeto:**
   ```bash
   cd projeto-temporizadores-pico
   ```
3. **Compile o código utilizando o Pico SDK:**
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```
4. **Carregue o código no Raspberry Pi Pico W.**
5. **Simule o funcionamento no Wokwi ou execute diretamente no hardware.**

---

## 📢 Observações
- Consulte os materiais associados a cada atividade nos links disponíveis abaixo:
1. https://www.dropbox.com/scl/fi/6w37qxzdq4ytljqvqzr6h/2025-01-25-17-48-11.mkv?rlkey=yjj1iqcfkx444xigglaxqw81e&dl=0
2. https://www.dropbox.com/scl/fi/7faa7ib6bjrxncr2dxnf7/2025-01-26-14-01-54.mkv?rlkey=wqvef7zpxpuwvz2joj6qucasd&dl=0

🛠️ **Bons estudos e boa programação! 🚀**

