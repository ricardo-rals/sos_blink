# Projeto Código Morse SOS com Raspberry Pi Pico

Este projeto demonstra como usar um Raspberry Pi Pico para piscar um LED em Código Morse, transmitindo especificamente o sinal de socorro SOS.

## Funcionalidade:

- Pisca um LED no padrão correto para SOS (três pontos, três traços, três pontos).

## Requisitos de Hardware:

- Placa **Raspberry Pi Pico W**
- **LED** (qualquer cor)
- **Resistor de 220 ohms** (opcional, recomendado para proteger o LED)
- **Jumpers** para conexões

## Requisitos de Software:

- **SDK do Pico** configurado.
- **Ambiente de desenvolvimento pronto** (Visual Studio Code, com a extensão Wokwi instalada).
- **GDB (GNU Debugger)** instalado e configurado corretamente.

## Conexão do Circuito:

1. Conecte uma perna do LED ao resistor (se estiver usando). Conecte a outra perna do LED (com ou sem resistor) a um pino GPIO no Pico (por exemplo, pino 11 neste código).
2. Conecte a outra extremidade do resistor (se estiver usando) ao GND (terra) no Pico.
3. Conecte o pino GND no Pico ao terra.

## Explicação do Código:

O código inclui as seguintes funcionalidades principais:

- **`blink_led(duration_ms)`:** Liga o LED por uma duração específica em milissegundos e depois o desliga.
- **`blink_dot()`:** Pisca o LED pela duração de um ponto, seguido por um pequeno espaço.
- **`blink_dash()`:** Pisca o LED pela duração de um traço, seguido por um pequeno espaço.
- **`blink_sos()`:** Repete a sequência do Código Morse SOS (três pontos, três traços, três pontos) com espaços e atrasos definidos entre letras e ciclos.
- **`main()`:** Inicializa a comunicação serial, configura o pino do LED como saída e entra em um loop infinito para transmitir continuamente o sinal SOS.

## Configuração do Debugger

Antes de executar o projeto, você precisará configurar o caminho do GDB no arquivo `launch.json`. 

1. Abra o arquivo `.vscode/launch.json`.
2. Localize a configuração que se parece com o seguinte trecho:

```json
{
    "name": "Wokwi GDB",
    "type": "cppdbg",
    "request": "launch",
    "program": "${workspaceFolder}/build/sos_blink.elf",
    "cwd": "${workspaceFolder}",
    "MIMode": "gdb",
    "miDebuggerPath": "C:/MinGW/bin/gdb.exe", // Altere para o caminho correto do seu GDB
    "miDebuggerServerAddress": "localhost:3333"
}
```
3. Altere o valor de "miDebuggerPath" para o local onde o seu GDB está instalado. Por exemplo:

## Demonstração do Funcionamento

Abaixo está um GIF que demonstra o funcionamento do projeto no Wokwi:

![Demonstração do Projeto no Wokwi](https://github.com/user-attachments/assets/f7a4139b-2067-4f3f-8a72-fe0a6f07caf1)
