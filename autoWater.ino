#include <arduino.h>

//определение пинов для насосов
#define pump_1 1
#define pump_2 2
#define pump_3 3
#define pump_4 4

//определение индикаторного светодиода
#define led 5

//определение кнопки
//#define but 6

//время между поливами
uint16_t timer_min = 300;

//время сасого полива
uint8_t water_sec = 5;

//флаг для сигания светодиодом
bool led_flag = 0;

//включить насосы на время t
void get_water(uint16_t t){
  digitalWrite(pump_1, HIGH);
  digitalWrite(pump_2, HIGH);
  digitalWrite(pump_3, HIGH);
  digitalWrite(pump_4, HIGH);
  digitalWrite(led, HIGH);
  delay(t);
  digitalWrite(pump_1, LOW);
  digitalWrite(pump_2, LOW);
  digitalWrite(pump_3, LOW);
  digitalWrite(pump_4, LOW);
  difitalWrite(led, LOW);
}

//мигать светодиодом раз в секунду
void led_blink(){
  if(millis()%1000==0 && flag==0){
    flag = true;
    digitalWrite(led, HIGH);
  }
  if(millis()%1000==0 && flag==1){
    flag = false;
    digitalWrite(led, LOW);
  }
}

void setup(){
  pinMode(pump_1, OUTPUT);
  pinMode(pump_2, OUTPUT);
  pinMode(pump_3, OUTPUT);
  pinMode(pump_4, OUTPUT);
  pinMode(led, OUTPUT);
  //pinMode(but, INPUT);
  get_water(water_sec);
}

void loop(){
  if(millis()%(timer_min*60*1000)==0){
    get_water(water_sec);
  } else {
    led_blink();
  }
}
