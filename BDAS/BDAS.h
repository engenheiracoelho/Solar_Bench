#ifndef BDAS_H
#define BDAS_H

#include <Arduino.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <Wire.h>
#include <SPI.h>
#include <Ethernet.h>

// Define INPUT
#define IN1 42 // Nível que quando ativado desliga a bomba
#define IN2 22 // Verifica quando a resistência está ligada
#define IN3 40 // Botão que aciona a saída OUT1 e OUT7
#define IN4 38 // Botão que aciona a saída OUT2
#define IN5 30 // Botão que aciona a saída OUT3
#define IN6 32 // Botão que aciona a saída OUT4
#define IN7 34 // Botão que aciona a saída OUT5
#define IN8 36 // Botão que aciona a saída OUT6
#define IN9 46 // Botão que modifica valores do LCD
#define IN10 2 //Interrupção da vazão

// Define OUTPUT
#define OUT1 31 // Bomba - Acionamento IN3
#define OUT2 33 // Resistencia – Acionamento IN2
#define OUT3 35 // LED1 – Acionamento IN5
#define OUT4 37 // LED2 – Acionamento IN6
#define OUT5 39 // LED3 – Acionamento IN7
#define OUT6 41 // LED4 – Acionamento IN8
#define OUT7 43 // Ventoinha – Acionamento IN3


class BDAS
{
    public:

    void mostra_endereco_sensor(DeviceAddress deviceAddress);  //MOSTRA ENDEREÇO DOS SENSORES
    int Mostraled1(int LED1_OnOff, EthernetClient client, String vars,float sensor);
    int Mostraled2(int LED2_OnOff,EthernetClient client, String vars,float sensor);
    int Mostraled3(int LED3_OnOff,EthernetClient client, String vars,float sensor);
    int Mostraled4(int LED4_OnOff,EthernetClient client, String vars,float sensor);
    int Mostraled5(int LED5_OnOff,EthernetClient client, String vars,float sensor);
    int Mostraled6(int LED6_OnOff,EthernetClient client, String vars);
    void LCDgeral(LiquidCrystal_I2C lcd);  //Mostra o nome da bancada no LCD
    void LCDtemp(LiquidCrystal_I2C lcd, float sensor_vector[4], DallasTemperature sensorsT1,DallasTemperature sensorsT2,DallasTemperature sensorsT3,DallasTemperature sensorsT4);  //Mostra a temperatura no LCD
    void LCDvazao(LiquidCrystal_I2C lcd, float vazao);//Mostra a vazão da bancada no LCD
    void LCDresistencia(LiquidCrystal_I2C lcd);
    void out_OFF(int out_pin); //Desliga uma saída determinada pela variável out_pin
    void out_ON(int out_pin);//Liga uma saída determinada pela variável out_pin
    int in_READ(int in_pin);//MANIPULAÇÃO DAS ENTRADAS DIGITAIS
    void Associa_BT_LED();
    void Saida_LED(int LED1_OnOff,int LED2_OnOff,int LED3_OnOff,int LED4_OnOff,int LED5_OnOff,int LED6_OnOff);
    //void Mostra_sensor(int i,float sensor,EthernetClient client);
    void Pinagem();
    int LED1_sup,LED1_real;
    int LED2_sup,LED2_real;
    int LED3_sup,LED3_real;
    int LED4_sup,LED4_real;
    int LED5_sup,LED5_real;
    int LED6_sup,LED6_real;

};

#endif
