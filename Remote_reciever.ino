#include<IRremote.h>

typedef void (*Show)();
int segmentA = A0;
int segmentB = A1;
int segmentC = A2;
int segmentD = A3;
int segmentE = A4;
int segmentF = A5;
int segmentG = 13;
int Led[] = {3, 5, 6, 9 , 10};
int digit[] = {2, 4, 7, 8} ;
int RECV = 12; 

IRrecv irrecv(RECV);
decode_results results;

void setup() {
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(Led[0], OUTPUT);
  pinMode(Led[1], OUTPUT);
  pinMode(Led[2], OUTPUT);
  pinMode(Led[3], OUTPUT);
  pinMode(Led[4], OUTPUT);
  pinMode(Led[5], OUTPUT);
  pinMode(digit[0], OUTPUT);
  pinMode(digit[1], OUTPUT);
  pinMode(digit[2], OUTPUT);
  pinMode(digit[3], OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}


void loop() {
  if (irrecv.decode(&results))
  {
    switch (results.value)
    {
      case 0x59011201:
        คำสั่ง 1;        break;
      case 0x59011219:
        คำสั่ง 2;        break;
      case 0x003:
        คำสั่ง 3;        break;
      case 0x004:
        คำสั่ง 4;        break;
      case 0x005:
        คำสั่ง 5;        break;        
      case 0x006:
        คำสั่ง 6;        break;        
      case 0x007:
        คำสั่ง 7;        break;        
      case 0x008:
        คำสั่ง 8;        break;        
      case 0x009:
        คำสั่ง 9;        break;        
      case 0x010:
        คำสั่ง 10;        break;        
    }
    Serial.println(results.value, HEX);
    irrecv.resume();
  }

}



