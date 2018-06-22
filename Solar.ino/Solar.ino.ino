/*  SOMA Ind. e Com. Ltda

      Bancada didática de aquecimento solar com complemento por resistência elétrica
      Create by Leticia Coelho  07/03/2018
      Modify by Eduardo Centenaro
      
*/
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <Wire.h>
#include <SPI.h>
#include <Ethernet.h>


// Define INPUT
#define IN1 42 // Nível que quando ativado desliga a bomba
#define IN2 44 // Verifica quando a resistência está ligada
#define IN3 40 // Botão que aciona a saída OUT1 e OUT7
#define IN4 38 // Botão que aciona a saída OUT2
#define IN5 30 // Botão que aciona a saída OUT3
#define IN6 32 // Botão que aciona a saída OUT4
#define IN7 34 // Botão que aciona a saída OUT5
#define IN8 36 // Botão que aciona a saída OUT6
#define IN9 46 // Botão que modifica valores do LCD
#define IN10 2 //Interrupção da vazão

// Define OUTPUT
#define OUT1 31 // Bomba  Acionamento IN3
#define OUT2 33 // Resistencia – Acionamento IN2 
#define OUT3 35 // LED1 – Acionamento IN5
#define OUT4 37 // LED2 – Acionamento IN6
#define OUT5 39 // LED3 – Acionamento IN7
#define OUT6 41 // LED4 – Acionamento IN8
#define OUT7 43 // Ventoinha – Acionamento IN3
#define OUT8 45 // LED5 – Acionamento IN2

// Porta do pino de sinal do DS18B20
#define ONE_WIRE_BUS_1 23 // Temperatura de entrada do boiler
#define ONE_WIRE_BUS_2 25 // Temperatura de saída do boiler
#define ONE_WIRE_BUS_3 27 // Temperatura de  continuação de fluxo
#define ONE_WIRE_BUS_4 29 // Temperatura da água externa

// Define uma instancia do oneWire para comunicacao com o sensor
OneWire oneWire1(ONE_WIRE_BUS_1);
OneWire oneWire2(ONE_WIRE_BUS_2);
OneWire oneWire3(ONE_WIRE_BUS_3);
OneWire oneWire4(ONE_WIRE_BUS_4);

DallasTemperature sensorsT1(&oneWire1);
DallasTemperature sensorsT2(&oneWire2);
DallasTemperature sensorsT3(&oneWire3);
DallasTemperature sensorsT4(&oneWire4);

// Sensores de Temperatura
DeviceAddress sensorT1;
DeviceAddress sensorT2;
DeviceAddress sensorT3;
DeviceAddress sensorT4;


// Define State
int ST1=0;
int ST1S=0;
int SB1=0;
int ST2=0;
int ST2S=0;
int SB2=0;
int ST3=0;
int ST3S=0;
int SB3=0;
int ST4=0;
int ST4S=0;
int SB4=0;
int ST5=0;
int ST5S=0;
int SB5=0;
int ST6=0;
int ST6S=0;
int SB6=0;
int ST7=0;
int ST7S=0;
int SB7=0;

int LED1_OnOff;



//Variáveis de manipulação
float vazao; //Variável para armazenar o valor em L/min
float media=0; //Variável para tirar a média a cada 1 minuto
int contaPulso; //Variável para a quantidade de pulsos
int i=0; //Variável para contage
float Sensores[4] = {ONE_WIRE_BUS_1, ONE_WIRE_BUS_2, ONE_WIRE_BUS_3, ONE_WIRE_BUS_4}; //Vetor com os sensores de temperatura e vazão;

//Definição configuração ethernet
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192,168,1,253);
EthernetServer server(80);
EthernetClient client;

//variáveis de controle do switch
int numero = 0; 
boolean botaoAtu = false;
boolean botaoAnt = false;

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {

  //Inicialização
  Serial.begin(9600);
  lcd.begin(20, 4);
  pinMode(IN10, INPUT); 
  attachInterrupt(0, incpulso, RISING);
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
  mostra_endereco_sensor(sensorT1);
  Serial.print("Endereco sensor: ");
  mostra_endereco_sensor(sensorT2);
  Serial.print("Endereco sensor: ");
  mostra_endereco_sensor(sensorT3);
  Serial.print("Endereco sensor: ");
  mostra_endereco_sensor(sensorT4);
  Serial.println();

  // Pinagem de entrada
  pinMode(IN1, INPUT);
  pinMode(IN2, INPUT);
  pinMode(IN3, INPUT);
  pinMode(IN4, INPUT);
  pinMode(IN5, INPUT);
  pinMode(IN6, INPUT);
  pinMode(IN7, INPUT);
  pinMode(IN8, INPUT);
  pinMode(IN9, INPUT);

  // Pinagem de saída
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  pinMode(OUT5, OUTPUT);
  pinMode(OUT6, OUTPUT);
  pinMode(OUT7, OUTPUT);

  //Inicialização ethernet
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("Server BEGIN - OK ");
  Serial.println(Ethernet.localIP());
  
}


int Mostraled1(int LED1_OnOff, EthernetClient client, String vars){
       int l=0;

         client.println("<br>");
         client.println("<input type=button value=LED1 style=margin-left:350px;margin-top:5px;height:35px;width:360px;background-color:white;margin:4px2px;color:#e47f26;text-align:center;font-size:28px;border-color:#e47f26");
         client.println("<br><br>");
         client.println("<input type=button value=Ligar style=margin-left:350px;margin-top:5px;height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px;");
         client.println(" onclick=\"document.location='/led1_on'\" />");
         client.println("<input type=button value=Desligar style=height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px;");
         client.println(" onclick=\"document.location='/led1_off'\" />");
         client.println("<br>");
           if (l==0){
            if (LED1_OnOff==1){ //Liga
                l = 1;
                ST1S=1;
            }else{
              if (LED1_OnOff==2){ //Desliga
                l = 0;
                ST1S=0;
              }
           }
           }
}


//MOSTRA ENDEREÇO DOS SENSORES
void mostra_endereco_sensor(DeviceAddress deviceAddress) // Mostra o endereço do sensor
{
  for (uint8_t i = 0; i < 8; i++)
  {
    // Adiciona zeros se necessário
    if (deviceAddress[i] < 16) Serial.print("0");
      Serial.print(deviceAddress[i], HEX);
  }
}


//Mostra o nome da bancada no LCD
void LCDgeral(){

  lcd.setCursor(3, 0);
  lcd.print("SOMA ENGENHARIA");
  lcd.setCursor(8, 1);
  lcd.print("BDAS"); 
  lcd.setCursor(2, 2);
  lcd.print("BANCADA DIDATICA");
  lcd.setCursor(0, 3);
  lcd.print("DE AQUECIMENTO SOLAR");
}


//Mostra a temperatura no LCD
void LCDtemp(float sensor_vector[4]) {

  lcd.setCursor(0, 0);
  lcd.print("Temp1:       ");
  //Simbolo grau
  lcd.write(223);
  lcd.print("C");
  lcd.setCursor(7, 0);
  lcd.print(Sensores[0]);

  lcd.setCursor(0, 1);
  lcd.print("Temp2:       ");
  //Simbolo grau
  lcd.write(223);
  lcd.print("C");
  lcd.setCursor(7, 1);
  lcd.print(Sensores[1]);

  lcd.setCursor(0, 2);
  lcd.print("Temp3:       ");
  //Simbolo grau
  lcd.write(223);
  lcd.print("C");
  lcd.setCursor(7, 2);
  lcd.print(Sensores[2]);

  lcd.setCursor(0, 3);
  lcd.print("Temp4:       ");
  //Simbolo grau
  lcd.write(223);
  lcd.print("C");
  lcd.setCursor(7, 3);
  lcd.print(Sensores[3]);

  float * Sensores =  sensor_vector;
  sensorsT1.requestTemperatures();
  sensorsT2.requestTemperatures();
  sensorsT3.requestTemperatures();
  sensorsT4.requestTemperatures();
}


//Mostra a vazão da bancada no LCD
void LCDvazao() { 

  lcd.setCursor(3, 0);
  lcd.print("SOMA ENGENHARIA");
  lcd.setCursor(5, 2);
  lcd.print("Q:");
  lcd.print(vazao);
  lcd.setCursor(12, 2);  
  lcd.print("L/m");
  
}

void LCDresistencia() { 

  lcd.setCursor(4, 0);
  lcd.print("RESISTENCIA");
  if (digitalRead(IN2)==HIGH){
   lcd.setCursor(5, 2);
   lcd.print("LIGADA   ");
  }
  else{
   lcd.setCursor(5, 2);
   lcd.print("DESLIGADA");
  } 
}

//MANIPULAÇÃO DAS SAÍDAS DIGITAIS
void out_OFF(int out_pin) { //Desliga uma saída determinada pela variável out_pin
  digitalWrite(out_pin, HIGH);
}

void out_ON(int out_pin) { //Liga uma saída determinada pela variável out_pin
  digitalWrite(out_pin, LOW);
}

//MANIPULAÇÃO DAS ENTRADAS DIGITAIS
int in_READ(int in_pin) { //Retorna o valor correspondente a entrada in_pin
  return digitalRead(in_pin);
}

//Calcula a vazão 
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
    Serial.print(" L/min  "); //Imprime L/min
    media = 0; //Zera a variável media para uma nova contagem
    i=0; //Zera a variável i para uma nova contagem
    Serial.println("\n\nInicio\n\n"); //Imprime Inicio indicando que a contagem iniciou
  } 
}

void incpulso ()//Incrementa a variável de contagem dos pulsos
{
  contaPulso++;
}

void Associa_BT_LED(){
// IN1  Botão que desliga a saída OUT1 e OUT7 - ST1
  if (!in_READ(IN1) && in_READ(IN3)) {
    ST1 = !ST1;
    delay(500);
  }
// IN2  Acionamento do LED5
 /* if (in_READ(IN2)) {
     ST2=1;
  }
  else {
     ST2=0;
  } 
//IN4  Botão que aciona a saída OUT2
  if (in_READ(IN4)) {
     ST3=1;
  }
  else {
     ST3=0;
  }
//IN5  Botão que aciona a saída OUT3
  if (in_READ(IN5)) {
     ST4=1;
  }
  else {
     ST4=0;
  }
//IN6  Botão que aciona a saída OUT4
  if (in_READ(IN6)) {
     ST5=1;
  }
  else {
     ST5=0;
  }
//IN7  Botão que aciona a saída OUT5
  if (in_READ(IN7)) {
     ST6=1;
  }
  else {
    ST6=0;
  }
//IN8  Botão que aciona a saída OUT6
  if (in_READ(IN8)) {
    ST7=1; 
  }
  else {
     ST7=0;
  }*/
}

void Associa_Estado(){
// IN1  Botão que desliga a saída OUT1 e OUT7 - ST1
  if ((ST1S==1 && ST1==LOW)||(ST1S==1 && ST1==HIGH)||(ST1S==0 && ST1==HIGH)) {
    out_ON(OUT1);
    out_ON(OUT7);
  }// IN3  Botão que aciona a saída OUT1 e OUT7
  else {
    out_OFF(OUT1);
    out_OFF(OUT7);
  }
 /*
// IN2  Acionamento do LED5
  if (ST2==1) {
    out_ON(OUT8);
  }
  else {
    out_OFF(OUT8);
  }
  

//IN4  Botão que aciona a saída OUT2
  if (ST3==1) {
    out_ON(OUT2);
  }
  else {
    out_OFF(OUT2);
  }

//IN5  Botão que aciona a saída OUT3
  if (ST4==1) {
    out_ON(OUT3);
  }
  else {
    out_OFF(OUT3);
  }

//IN6  Botão que aciona a saída OUT4
  if (ST5==1) {
    out_ON(OUT4);
  }
  else {
    out_OFF(OUT4);
  }

//IN7  Botão que aciona a saída OUT5
  if (ST6==1) {
    out_ON(OUT5);
  }
  else {
    out_OFF(OUT5);
  }

//IN8  Botão que aciona a saída OUT6
  if (ST7==1) {
    out_ON(OUT6);
  }
  else {
    out_OFF(OUT6);
  }*/
}

void loop() {

float Sensores[4] = {sensorsT1.getTempC(sensorT1), sensorsT2.getTempC(sensorT2), sensorsT3.getTempC(sensorT3), sensorsT4.getTempC(sensorT4)};

//IN9  Botão que modifica valores do LCD
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
       LCDgeral();
       break;  
         
    case 1:
       LCDtemp(Sensores);
       break; 
              
    case 2:
       LCDvazao();
       valor_vazao();
       break;

    case 3:
       LCDresistencia();
       break;       
}

  Associa_BT_LED();
  Associa_Estado();
  int i = client.connected();

    client = server.available();
    
    if (client) {
    Serial.println("new client");

       
    boolean currentLineIsBlank = true;
    
    String vars;
 
  
   while(client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        vars.concat(c);       
        if (vars.endsWith("/led1_on"))  LED1_OnOff = 1;
        if (vars.endsWith("/led1_off")) LED1_OnOff = 2;
               
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
          
          Mostraled1(LED1_OnOff,client,vars);
     
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
  }
}
