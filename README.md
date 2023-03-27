# WebServer-Node-MCU

## Objetivo

Criação de um webServer para controle de motores

# Softwares e Hardwares necessários 
* Keil Studio Online
* Arduino IDE
* Nucleo Stm32 F103
* Placa Node MCU 8266
* Motor de passo 28BYJ-48
* Drive ULN 2003
* Display OLED I2C 128x64
* Módulo Relê

# Introdução 
Nesse tutorial iremos mostrar como fazer um webserver para controle de três motores de passo. A idéia do projeto é utilizar a placa NodeMCU para gerar uma página em HTLM para comando dos motores.

## Página em HTML 

![pg1](https://user-images.githubusercontent.com/60757810/228042894-d3867996-4fbd-46d7-93c8-b4b0ee577738.JPG)

## Suporte para Motores
![WhatsApp Image 2023-03-27 at 16 11 16](https://user-images.githubusercontent.com/60757810/228043498-176e275d-263d-4bd2-afbb-09bb3a1bd9a0.jpeg)

## Ligação 
Conexão entre Nucleo F103 e Node é feita pela as portas RX e TX de ambos os micocontroladorres. 
Node MCU Pinos: D7 RX  F103 Pino TX D8
Node MCU Pinos: D8 TX  F103 Pino RX D2

## Interface Display Oled

![WhatsApp Image 2023-03-27 at 16 11 15](https://user-images.githubusercontent.com/60757810/228044194-fe5069d3-4e70-4162-baed-d867583d308f.jpeg)
