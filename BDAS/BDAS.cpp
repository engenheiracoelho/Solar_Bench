
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
                ST1S=1;
                Serial.println("LED1 SUP LIGADO");
            }else if (LED1_OnOff==2){ //Desliga
                i = 0;
                //digitalWrite(OUT3,HIGH);
                ST1S=0;
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
             ST2S=1;
         }else{
           if (LED2_OnOff==2){ 
             j = 0;
             ST2S=0;
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
              ST3S=1;
          }else{
            if (LED3_OnOff==2){ //Desliga
              a = 0;
              ST3S=0;
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
                LED4_sup=1;
               }else{
             if (LED4_OnOff==2){ //Desliga
               k = 0;
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
                LED5_sup=1;
            }else{
              if (LED5_OnOff==2){ //Desliga
                l = 0;
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
                LED6_sup=1;
            }else{
              if (LED6_OnOff==2){ //Desliga
                l = 0;
                LED6_sup=0;
              }
           }
           }

}

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
