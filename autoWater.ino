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

uint16_t timer_min = 300;
uint8_t water_sec = 5;

void get_water(uint16_t t){
}

void setup(){
  pinMode(pump_1, OUTPUT);
  pinMode(pump_2, OUTPUT);
  pinMode(pump_3, OUTPUT);
  pinMode(pump_4, OUTPUT);
  pinMode(led, OUTPUT);
  //pinMode(but, INPUT);
}

void loop(){
}
