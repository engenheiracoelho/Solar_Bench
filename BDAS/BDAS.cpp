#include "BDAS.h"


//MOSTRA ENDEREÇO DOS SENSORES
void BDAS::mostra_endereco_sensor(DeviceAddress deviceAddress) // Mostra o endereço do sensor
{
  for (uint8_t i = 0; i < 8; i++)
  {
    // Adiciona zeros se necessário
    if (deviceAddress[i] < 16) Serial.print("0");
      Serial.print(deviceAddress[i], HEX);
  }
}

int BDAS::Mostraled1(int LED1_OnOff, EthernetClient client, String vars,float sensor){
       // Maniuplacao das variaveis - LED1
         int i=0;
         client.println("<br><input type=button value=LED1 style=margin-left:350px;margin-top:60px;height:35px;width:360px;background-color:white;margin:4px2px;color:#e47f26;text-align:center;font-size:28px;border-color:#e47f26>");
         client.println("<br><br><input type=button value=Ligar style=position:static;margin-left:350px;height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px; onclick=\"document.location='/led1_on'\" />");
         client.println("<input type=button value=Desligar style=height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px;");
         client.println(" onclick=\"document.location='/led1_off'\" />");
         client.println("<output style=margin-left:20px;font-weight:bold;font-variant:small-caps;height:40px;width:180px;border-radius:8px;font-size:22px;border-radius:8px;>Temperatura 1:</div>");
         client.println(sensor);
         client.println("°C");
         client.println("<output style=margin-left:240px;font-weight:bold;font-variant:small-caps;height:40px;width:180px;border-radius:8px;font-size:22px;border-radius:8px;>Temperatura 2:</div>");
         client.println(sensor);
         client.println("°C<br>");
         if (i==0){
            if (LED1_OnOff==1){ //Liga
                i = 1;
                //digitalWrite(OUT3,LOW);
                LED1_sup=1;
                      Serial.println("LED1 SUP LIGADO");
            }else if (LED1_OnOff==2){ //Desliga
                i = 0;
                //digitalWrite(OUT3,HIGH);
                LED1_sup=0;
                      Serial.println("LED1 SUP DESLIGADO");
            }
          }
}

int BDAS::Mostraled2(int LED2_OnOff,EthernetClient client, String vars,float sensor){/*---------------------------------------------------------------------------------------------------------------------/>*/

        int j=0;
        client.println("<br>");
        client.println("<input type=button value=LED2 style=margin-left:350px;margin-top:5px;height:35px;width:360px;background-color:white;margin:4px2px;color:#e47f26;text-align:center;font-size:28px;border-color:#e47f26");
        client.println("<br><br>");
        client.println("<input type=button value=Ligar style=margin-left:350px;margin-top:5px;height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px;");
        client.println(" onclick=\"document.location='/led2_on'\" />");
        client.println("<input type=button value=Desligar style=height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px;");
        client.println(" onclick=\"document.location='/led2_off'\" /><br>");

        if (j==0){
         if (LED2_OnOff==1){ //Liga
             j = 1;
             //digitalWrite(OUT4,LOW);
             LED2_sup=1;
         }else{
           if (LED2_OnOff==2){ //Desliga
             j = 0;
             //digitalWrite(OUT4,HIGH);
             LED2_sup=0;
           }
        }
        }
}

int BDAS::Mostraled3(int LED3_OnOff,EthernetClient client, String vars,float sensor){
         int a=0;
         client.println("<br>");
         client.println("<input type=button value=LED3 style=margin-left:350px;margin-top:5px;height:35px;width:360px;background-color:white;margin:4px2px;color:#e47f26;text-align:center;font-size:28px;border-color:#e47f26");
         client.println("<br><br>");
         client.println("<input type=button value=Ligar style=margin-left:350px;margin-top:5px;height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px;");
         client.println(" onclick=\"document.location='/led3_on'\" />");
         client.println("<input type=button value=Desligar style=height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px;");
         client.println(" onclick=\"document.location='/led3_off'\" />");
         client.println("<output style=margin-left:540px;font-weight:bold;font-variant:small-caps;height:40px;width:180px;border-radius:8px;font-size:22px;border-radius:8px;>Temperatura 3:</div>");
         client.println(sensor);
         client.println("°C<br>");

         if (a==0){
          if (LED3_OnOff==1){ //Liga
              a = 1;
              //digitalWrite(OUT5,LOW);
              LED3_sup=1;
          }else{
            if (LED3_OnOff==2){ //Desliga
              a = 0;
              //digitalWrite(OUT5,HIGH);
              LED3_sup=0;
            }
         }
         }
}

int BDAS::Mostraled4(int LED4_OnOff,EthernetClient client, String vars,float sensor){

         int k=0;
         client.println("<br>");
         client.println("<input type=button value=LED4 style=margin-left:350px;margin-top:5px;height:35px;width:360px;background-color:white;margin:4px2px;color:#e47f26;text-align:center;font-size:28px;border-color:#e47f26");
         client.println("<br><br>");
         client.println("<input type=button value=Ligar style=margin-left:350px;margin-top:5px;height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px;");
         client.println(" onclick=\"document.location='/led4_on'\" />");
         client.println("<input type=button value=Desligar style=height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px;");
         client.println(" onclick=\"document.location='/led4_off'\" /><br>");


          if (k==0){
           if (LED4_OnOff==1){ //Liga
               k = 1;
               //digitalWrite(OUT6,LOW);;
                LED4_sup=1;
               }else{
             if (LED4_OnOff==2){ //Desliga
               k = 0;
               //digitalWrite(OUT6,HIGH);
               LED4_sup=0;
               }
          }
          }
}

int BDAS::Mostraled5(int LED5_OnOff,EthernetClient client, String vars,float sensor){


         int l=0;
         client.println("<br>");
         client.println("<input type=button value=LED5 style=margin-left:350px;margin-top:5px;height:35px;width:360px;background-color:white;margin:4px2px;color:#e47f26;text-align:center;font-size:28px;border-color:#e47f26");
         client.println("<br><br>");
         client.println("<input type=button value=Ligar style=margin-left:350px;margin-top:5px;height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px;");
         client.println(" onclick=\"document.location='/led5_on'\" />");
         client.println("<input type=button value=Desligar style=height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px;");
         client.println(" onclick=\"document.location='/led5_off'\" />");
         client.println("<output style=margin-left:540px;font-weight:bold;font-variant:small-caps;height:40px;width:180px;border-radius:8px;font-size:22px;border-radius:8px;>Temperatura 4:</div>");
         client.println(sensor);
         client.println("°C<br>");
           if (l==0){
            if (LED5_OnOff==1){ //Liga
                l = 1;
                //digitalWrite(OUT2,LOW);
                LED5_sup=1;
            }else{
              if (LED5_OnOff==2){ //Desliga
                l = 0;
                //digitalWrite(OUT2,HIGH);
                LED5_sup=0;
              }
           }
           }
}

int BDAS::Mostraled6(int LED6_OnOff,EthernetClient client, String vars){


         int l=0;

         client.println("<br>");
         client.println("<input type=button value=LED6 style=margin-left:350px;margin-top:5px;height:35px;width:360px;background-color:white;margin:4px2px;color:#e47f26;text-align:center;font-size:28px;border-color:#e47f26");
         client.println("<br><br>");
         client.println("<input type=button value=Ligar style=margin-left:350px;margin-top:5px;height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px;");
         client.println(" onclick=\"document.location='/led6_on'\" />");
         client.println("<input type=button value=Desligar style=height:40px;width:180px;background-color:#005595;color:white;padding:14px40px;font-size:22px;border-radius:8px;");
         client.println(" onclick=\"document.location='/led6_off'\" />");
         client.println("<br>");


           if (l==0){
            if (LED6_OnOff==1){ //Liga
                l = 1;
                //digitalWrite(OUT1,LOW);
                //digitalWrite(OUT7,LOW);
                LED6_sup=1;
            }else{
              if (LED6_OnOff==2){ //Desliga
                l = 0;
                //digitalWrite(OUT1,HIGH);
                //digitalWrite(OUT7,HIGH);
                LED6_sup=0;
              }
           }
           }

}

//Mostra o nome da bancada no LCD
void BDAS::LCDgeral(LiquidCrystal_I2C lcd){

  lcd.setCursor(3, 0);
  lcd.print("SOMA ENGENHARIA");
  lcd.setCursor(8, 1);
  lcd.print("BDAS");
  lcd.setCursor(2, 2);
  lcd.print("BANCADA DIDATICA");
  lcd.setCursor(0, 3);
  lcd.print("DE AQUECIMENTO SOLAR");
}

//Calcula a vazão
//valor vazaao

//Mostra a temperatura no LCD
void BDAS::LCDtemp(LiquidCrystal_I2C lcd, float sensor_vector[4], DallasTemperature sensorsT1,DallasTemperature sensorsT2,DallasTemperature sensorsT3,DallasTemperature sensorsT4) {

  float * Sensores =  sensor_vector;
  sensorsT1.requestTemperatures();
  sensorsT2.requestTemperatures();
  sensorsT3.requestTemperatures();
  sensorsT4.requestTemperatures();

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


}


//Mostra a vazão da bancada no LCD
void BDAS::LCDvazao(LiquidCrystal_I2C lcd, float vazao) {

  lcd.setCursor(3, 0);
  lcd.print("SOMA ENGENHARIA");
  lcd.setCursor(5, 2);
  lcd.print("Q:");
  lcd.print(vazao);
  lcd.setCursor(12, 2);
  lcd.print("L/m");

}

void BDAS::LCDresistencia(LiquidCrystal_I2C lcd) {

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
void BDAS::out_OFF(int out_pin) { //Desliga uma saída determinada pela variável out_pin
  digitalWrite(out_pin, HIGH);
}

void BDAS::out_ON(int out_pin) { //Liga uma saída determinada pela variável out_pin
  digitalWrite(out_pin, LOW);
}

//MANIPULAÇÃO DAS ENTRADAS DIGITAIS
int BDAS::in_READ(int in_pin) { //Retorna o valor correspondente a entrada in_pin
  return digitalRead(in_pin);
}

void BDAS::Associa_BT_LED(){
  // IN1 - Botão que desliga a saída OUT1 e OUT7
//  if (!in_READ(IN1) && in_READ(IN3)) {
//    out_ON(OUT1) ;
//    out_ON(OUT7);
//  }// IN3 - Botão que aciona a saída OUT1 e OUT7
//  else {
//    out_OFF(OUT1);
//    out_OFF(OUT7);
//  }
// IN2 - Acionamento do LED5

    if (in_READ(IN5)) {
      //out_ON(OUT2);
      LED1_real=1;
      Serial.println("LED1 REAL LIGADO");
    }
    else {
      //out_OFF(OUT2);
      LED1_real=0;
      //Serial.println("LED1 REAL DESLIGADO");
    }
  //IN4 - Botão que aciona a saída OUT2
    if (in_READ(IN6)) {
      //out_ON(OUT2);
      LED2_real=1;
      Serial.println("LED2 REAL LIGADO");
    }
    else {
      //out_OFF(OUT2);
      LED2_real=0;
      Serial.println("DESLIGADO");
    }
  //IN5 - Botão que aciona a saída OUT3
    if (in_READ(IN7)) {
      //out_ON(OUT3);
      LED3_real=1;
      Serial.println("LED3 REAL LIGADO");
    }
    else {
      //out_OFF(OUT3);
      LED3_real=0;
      Serial.println("DESLIGADO");
    }
  //IN6 - Botão que aciona a saída OUT4
    if (in_READ(IN8)) {
      //out_ON(OUT4);
      LED4_real=1;
      Serial.println("LED4 REAL LIGADO");
    }
    else {
      //out_OFF(OUT4);
      LED4_real=0;
      Serial.println("DESLIGADO");
    }
  //IN7 - Botão que aciona a saída OUT5
    if (in_READ(IN4)) {
      //out_ON(OUT5);
      LED5_real=1;
      Serial.println("LED5 REAL LIGADO");
    }
    else {
    //out_OFF(OUT5);
      LED5_real=0;
      Serial.println("DESLIGADO");
  }

//IN8 - Botão que aciona a saída OUT6
    if (in_READ(IN3)) {
      //out_ON(OUT6);
      LED6_real=1;
    }
    else {
      //out_OFF(OUT6);
      LED6_real=0;
      Serial.println("DESLIGADO");
    }
}


void BDAS::Saida_LED(int LED1_OnOff,int LED2_OnOff,int LED3_OnOff,int LED4_OnOff,int LED5_OnOff,int LED6_OnOff){
  // IN1 - Botão que desliga a saída OUT1 e OUT7
//  if (!in_READ(IN1) && in_READ(IN3)) {
//    out_ON(OUT1) ;
//    out_ON(OUT7);
//  }// IN3 - Botão que aciona a saída OUT1 e OUT7
//  else {
//    out_OFF(OUT1);
//    out_OFF(OUT7);
//  }
// IN2 - Acionamento do LED5
/*if (LED1_real==1) {
     out_ON(OUT2);
   }else{
     out_OFF(OUT2);
   }
 //IN4 - Botão que aciona a saída OUT2
 if (LED2_real==1) {
   out_ON(OUT2);
 }else{
   out_OFF(OUT2);
 }
 //IN5 - Botão que aciona a saída OUT3
 if (LED3_real==1) {
   out_ON(OUT3);
 }else{
   out_OFF(OUT3);
 }
 //IN6 - Botão que aciona a saída OUT4
 if (LED4_real==1) {
   out_ON(OUT4);
 }else{
   out_OFF(OUT4);
 }
 //IN7 - Botão que aciona a saída OUT5
 if (LED5_real==1) {
   out_ON(OUT5);
 }else{
   out_OFF(OUT5);
 }
//IN8 - Botão que aciona a saída OUT6
if (LED6_real==1) {
 out_ON(OUT6);
}else{
 out_OFF(OUT6);
}*/

if(LED1_OnOff!=0) {
    if (LED1_sup==1){
       out_ON(OUT2);
     }else{
       out_OFF(OUT2);
     }
}else{
     if(LED1_real==1){
       out_ON(OUT2);
     }else {
       out_OFF(OUT2);
     }
  }
 //IN4 - Botão que aciona a saída OUT2
 if ((LED2_sup==1 && LED2_real==1)) {
   out_ON(OUT3);
 }else if(LED2_sup==0 && LED2_real==1){
   out_OFF(OUT3);
 }else {
   out_OFF(OUT3);
}
 //IN5 - Botão que aciona a saída OUT3
 if (LED3_sup==1 && LED3_real==1) {
   out_ON(OUT4);
 }else{
   out_OFF(OUT4);
 }
 //IN6 - Botão que aciona a saída OUT4
 if (LED4_sup==1 && LED4_real==1) {
   out_ON(OUT5);
 }else{
   out_OFF(OUT5);
 }
 //IN7 - Botão que aciona a saída OUT5
 if (LED5_sup==1 && LED5_real==1) {
   out_ON(OUT6);
 }else{
   out_OFF(OUT6);
 }
//IN8 - Botão que aciona a saída OUT6
if (LED6_sup==1 && LED6_real==1) {
 out_ON(OUT7);
}else{
 out_OFF(OUT7);
}
/*    if (LED1_real==1 && LED1_sup==1) {
      out_ON(OUT2);
    }else if (LED1_real==1 && LED1_sup==0) {
      out_ON(OUT2);
    }else if (LED1_real==0 && LED1_sup==1) {
      out_ON(OUT2);
    }else{
      out_OFF(OUT2);
    }
  //IN4 - Botão que aciona a saída OUT2
  if (LED2_real==1 && LED2_sup==1) {
    out_ON(OUT2);
  }else if (LED2_real==1 && LED2_sup==0) {
    out_ON(OUT2);
  }else if (LED2_real==0 && LED2_sup==1) {
    out_ON(OUT2);
  }else{
    out_OFF(OUT2);
  }
  //IN5 - Botão que aciona a saída OUT3
  if (LED3_real==1 && LED3_sup==1) {
    out_ON(OUT3);
  }else if (LED3_real==1 && LED3_sup==0) {
    out_ON(OUT3);
  }else if (LED3_real==0 && LED3_sup==1) {
    out_ON(OUT3);
  }else{
    out_OFF(OUT3);
  }
  //IN6 - Botão que aciona a saída OUT4
  if (LED4_real==1 && LED4_sup==1) {
    out_ON(OUT4);
  }else if (LED4_real==1 && LED4_sup==0) {
    out_ON(OUT4);
  }else if (LED4_real==0 && LED4_sup==1) {
    out_ON(OUT4);
  }else{
    out_OFF(OUT4);
  }
  //IN7 - Botão que aciona a saída OUT5
  if (LED5_real==1 && LED5_sup==1) {
    out_ON(OUT5);
  }else if (LED5_real==1 && LED5_sup==0) {
    out_ON(OUT5);
  }else if (LED5_real==0 && LED5_sup==1) {
    out_ON(OUT5);
  }else{
    out_OFF(OUT5);
  }
//IN8 - Botão que aciona a saída OUT6
if (LED6_real==1 && LED6_sup==1) {
  out_ON(OUT6);
}else if (LED5_real==1 && LED6_sup==0) {
  out_ON(OUT6);
}else if (LED6_real==0 && LED6_sup==1) {
  out_ON(OUT6);
}else{
  out_OFF(OUT6);
}*/
}
void BDAS::Pinagem(){
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
 pinMode(IN10, INPUT);

 // Pinagem de saída
 pinMode(OUT1, OUTPUT);
 pinMode(OUT2, OUTPUT);
 pinMode(OUT3, OUTPUT);
 pinMode(OUT4, OUTPUT);
 pinMode(OUT5, OUTPUT);
 pinMode(OUT6, OUTPUT);
 pinMode(OUT7, OUTPUT);

}
