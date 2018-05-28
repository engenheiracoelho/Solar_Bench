 /*  SOMA Ind. e Com. Ltda

      Bancada didática de aquecimento solar com complemento por resistência elétrica
      Create by Leticia Coelho - 07/03/2018
      Modify by Eduardo Centenaro
      
*/
#include "BDAS.h"
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <Wire.h>
#include <SPI.h>
#include <Ethernet.h>


// Porta do pino de sinal do DS18B20
#define ONE_WIRE_BUS_1 23 // Temperatura de entrada do boiler
#define ONE_WIRE_BUS_2 25 // Temperatura de saída do boiler
#define ONE_WIRE_BUS_3 27 // Temperatura de  continuação de fluxo
#define ONE_WIRE_BUS_4 29 // Temperatura da água externa

BDAS Soma;
//variáveis de controle do switch
int numero = 0; 
boolean botaoAtu = false;
boolean botaoAnt = false;


//Definição configuração ethernet
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192,168,1,253);
EthernetServer server(80);
EthernetClient client;

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// Sensores de Temperatura
DeviceAddress sensorT1;
DeviceAddress sensorT2;
DeviceAddress sensorT3;
DeviceAddress sensorT4;

    // Define uma instancia do oneWire para comunicacao com o sensor
    OneWire oneWire1(ONE_WIRE_BUS_1);
    OneWire oneWire2(ONE_WIRE_BUS_2);
    OneWire oneWire3(ONE_WIRE_BUS_3);
    OneWire oneWire4(ONE_WIRE_BUS_4);

    DallasTemperature sensorsT1(&oneWire1);
    DallasTemperature sensorsT2(&oneWire2);
    DallasTemperature sensorsT3(&oneWire3);
    DallasTemperature sensorsT4(&oneWire4);

    //Variáveis de manipulação
    int cli = 0;
    float vazao; //Variável para armazenar o valor em L/min
    float media=0; //Variável para tirar a média a cada 1 minuto
    int contaPulso; //Variável para a quantidade de pulsos
    int i=0; //Variável para contagem
    float Sensores[4] = {ONE_WIRE_BUS_1, ONE_WIRE_BUS_2, ONE_WIRE_BUS_3, ONE_WIRE_BUS_4}; //Vetor com os sensores de temperatura e vazão;
    int LED1_OnOff;
    int LED2_OnOff;
    int LED3_OnOff;
    int LED4_OnOff;
    int LED5_OnOff;
    int LED6_OnOff;    
    
void valor_vazao()
{
  contaPulso = 0;   //Zera a variável para contar os giros por segundos
  sei();      //Habilita interrupção
  delay (500); //Aguarda 1 segundo
  cli();      //Desabilita interrupção
  vazao = contaPulso / 7.5; //Converte para L/min
  media=media+vazao; //Soma a vazão para o calculo da media
  i++;
  Serial.print("Vazao ");
  Serial.print(vazao); //Imprime na serial o valor da vazão
  Serial.println(" L/min  "); //Imprime L/min

  if(i==60)
  {
    media = media/60; //Tira a media dividindo por 60
    Serial.print("\nMedia por minuto = "); //Imprime a frase Media por minuto =
    Serial.print(media); //Imprime o valor da media
    Serial.print(" L/min - "); //Imprime L/min
    media = 0; //Zera a variável media para uma nova contagem
    i=0; //Zera a variável i para uma nova contagem
    Serial.println("\n\nInicio\n\n"); //Imprime Inicio indicando que a contagem iniciou
  }
}

void incpulso ()//Incrementa a variável de contagem dos pulsos
{
  contaPulso++;
}

void setup() {
    int LED1_OnOff=0;
    int LED2_OnOff=0;
    int LED3_OnOff=0;
    int LED4_OnOff=0;
    int LED5_OnOff=0;
    int LED6_OnOff=0; 
  Soma.Pinagem();

  //Inicialização
  Serial.begin(9600);
  lcd.begin(20, 4);
  attachInterrupt(0,incpulso, RISING);
  Serial.println("\n\nInicio\n\n");
  sensorsT1.begin(); // Sensor de temperatura
  sensorsT2.begin(); // Sensor de temperatura
  sensorsT3.begin(); // Sensor de temperatura
  sensorsT4.begin(); // Sensor de temperatura
  
  // Localiza e mostra enderecos dos sensores
  Serial.println("Localizando sensores DS18B20...");
  Serial.print("Foram encontrados ");
  Serial.print(sensorsT1.getDeviceCount(), DEC);
  Serial.print("Foram encontrados ");
  Serial.print(sensorsT2.getDeviceCount(), DEC);
  Serial.print("Foram encontrados ");
  Serial.print(sensorsT3.getDeviceCount(), DEC);
  Serial.print("Foram encontrados ");
  Serial.print(sensorsT4.getDeviceCount(), DEC);
  Serial.println("sensores.");
  if (!sensorsT1.getAddress(sensorT1, 0))
    Serial.println("Sensore T1 nao encontrado!");
  if (!sensorsT2.getAddress(sensorT2, 0))
    Serial.println("Sensore T2 nao encontrado!");
  if (!sensorsT3.getAddress(sensorT3, 0))
    Serial.println("Sensore T3 nao encontrado!");
  if (!sensorsT4.getAddress(sensorT4, 0))
    Serial.println("Sensore T4 nao encontrado!");

  // Mostra o endereco do sensor encontrado no barramento
  Serial.print("Endereco sensor: ");
  Soma.mostra_endereco_sensor(sensorT1);
  Serial.print("Endereco sensor: ");
  Soma.mostra_endereco_sensor(sensorT2);
  Serial.print("Endereco sensor: ");
  Soma.mostra_endereco_sensor(sensorT3);
  Serial.print("Endereco sensor: ");
  Soma.mostra_endereco_sensor(sensorT4);
  Serial.println();

 
  //Inicialização ethernet
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("Server BEGIN - OK ");
  Serial.println(Ethernet.localIP());
}

void loop() {
      Soma.Associa_BT_LED();
      Soma.Saida_LED(LED1_OnOff,LED2_OnOff,LED3_OnOff,LED4_OnOff,LED5_OnOff,LED6_OnOff);
    float Sensores[4] = {sensorsT1.getTempC(sensorT1), sensorsT2.getTempC(sensorT2), sensorsT3.getTempC(sensorT3), sensorsT4.getTempC(sensorT4)};
    Serial.println(client.connected());

    
//IN9 - Botão que modifica valores do LCD
  botaoAtu = digitalRead(IN9);

  if (botaoAtu && !botaoAnt) {
     numero++;
     lcd.clear(); 
     if (numero > 3) {
        numero = 0; 
     }
  }
  botaoAnt = botaoAtu;

switch (numero) {
    case 0:
       Soma.LCDgeral(lcd);
       break;  
         
    case 1:
       Soma.LCDtemp(lcd,Sensores,sensorsT1,sensorsT2,sensorsT3,sensorsT4);
       break; 
              
    case 2:
       Soma.LCDvazao(lcd,vazao);
       valor_vazao();
       break;

    case 3:
       Soma.LCDresistencia(lcd);
       break;       
}  

    int i = client.connected();

    client = server.available();
    
    if (client) {
    Serial.println("new client");

       
    boolean currentLineIsBlank = true;
    
    String vars;
 
  
   while(client.connected()) {
      if (client.available()) {
        cli = 1;
        char c = client.read();
        Serial.write(c);
        vars.concat(c);       
        if (vars.endsWith("/led1_on"))  LED1_OnOff = 1;
        if (vars.endsWith("/led1_off")) LED1_OnOff = 2;
        
        if (vars.endsWith("/led2_on"))  LED2_OnOff = 1;
        if (vars.endsWith("/led2_off")) LED2_OnOff = 2;
        
        if (vars.endsWith("/led3_on"))  LED3_OnOff = 1;
        if (vars.endsWith("/led3_off")) LED3_OnOff = 2;
        
        if (vars.endsWith("/led4_on"))  LED4_OnOff = 1;
        if (vars.endsWith("/led4_off")) LED4_OnOff = 2;
        
        if (vars.endsWith("/led5_on"))  LED5_OnOff = 1;
        if (vars.endsWith("/led5_off")) LED5_OnOff = 2;

        if (vars.endsWith("/led6_on"))  LED6_OnOff = 1;
        if (vars.endsWith("/led6_off")) LED6_OnOff = 2;
        
        if (c == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html; charset=utf-8");
          client.println("Connnection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<style> html,body {height: 100%;");
          client.println("background: url(https://www.soma.eng.br/imagens/bdas.png) no-repeat center center fixed;");
          client.println("background-size:auto auto; } </style>");
          client.println("<br><br><br>");
          
          Soma.Mostraled1(LED1_OnOff,client,vars,Sensores[0]);
          Soma.Mostraled2(LED2_OnOff,client,vars,Sensores[1]);
          Soma.Mostraled3(LED3_OnOff,client,vars,Sensores[2]);
          Soma.Mostraled4(LED4_OnOff,client,vars,Sensores[3]);
          Soma.Mostraled5(LED5_OnOff,client,vars,Sensores[3]);
          Soma.Mostraled6(LED6_OnOff,client,vars);
     
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }

    delay(1);
    client.stop();

    Serial.println("client disonnected");
    cli=0;
  }
      LED1_OnOff=0;
    LED2_OnOff=0;
    LED3_OnOff=0;
    LED4_OnOff=0;
    LED5_OnOff=0;
    LED6_OnOff=0;
}

