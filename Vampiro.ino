#include <Servo.h>
#define Linea_Iz A0
#define Linea_Dr A1
#define Sen_Dr 2
#define Sen_Efr1 4
#define Sen_Efr2 7 
#define Sen_Iz 8
#define Band 10
int Motor1_1 = 3;
int Motor1_2 = 6;
int Motor2_1 = 9;
int Motor2_2 = 5;
#define led 0
#define Control A7
Servo Bandera; 

int sensorValue;
int lineValue;

void setup() {
  Serial.begin(9600);
  Bandera.attach(Band);
  pinMode(Linea_Iz, INPUT);
  pinMode(Linea_Dr, INPUT);
  pinMode(Sen_Dr, INPUT);
  pinMode(Sen_Efr1, INPUT);
  pinMode(Sen_Efr2, INPUT);
  pinMode(Sen_Iz, INPUT);
  pinMode(Motor1_1, OUTPUT);
  pinMode(Motor1_2, OUTPUT);
  pinMode(Motor2_1, OUTPUT);
  pinMode(Motor2_2, OUTPUT);
  pinMode(led, OUTPUT);
  
}

void loop() {
  while(1){
    
    sensorValue = sensorState();
    lineValue = lineState();
    
    switch(lineValue){
      case 0: //PELEA
        switch(sensorValue){
          case 0:
            adelante(120,120);
            delay(20);
            paro();
            delay(20);
            break;
          case 1:
            break;
          case 2:
            break;
          case 3:
            break;
          case 4:
            break;
          case 5:
            break;
          case 6:
            break;
          case 8:
            break;
          case 9:
            break;
          case 10:
            break;
          case 12:
            break;  
        }
        break;

      case 1:
      //DERECHA
       break;

      case 2:
      //IZQUIERDA
        break;

      case 3:
      //ATRAS
        break;
    }
  }

}

// ---------------- Sensores ----------------

int sensorState(){
  int valor_1 = digitalRead(Sen_Efr1); 
  int valor_2 = digitalRead(Sen_Efr2)*2;
  int valor_Der = digitalRead(Sen_Dr)*4;
  int valor_Iz = digitalRead(Sen_Iz)*8;

  int suma = valor_1 + valor_2 + valor_Der + valor_Iz;
  Serial.print("S :  ");
  Serial.println(suma);
  return suma;
}

int lineState(){
  int valine_Iz = digitalRead(Linea_Iz);
  int valine_Dr = digitalRead(Linea_Dr)*2;

  int suma = valine_Iz + valine_Dr;
  Serial.print("L :  ");
  Serial.println(suma);
  return suma;
}

// ---------------- Motores ----------------

void adelante(int a, int b){
  digitalWrite(Motor1_1, a);
  digitalWrite(Motor1_2, LOW);
  digitalWrite(Motor2_1, b);
  digitalWrite(Motor2_2, LOW);
}

void derecha(int a, int b){
  digitalWrite(Motor1_1, a);
  digitalWrite(Motor1_2, LOW);
  digitalWrite(Motor2_1, LOW);
  digitalWrite(Motor2_2, b);
}

void izquierda(int a, int b){
  digitalWrite(Motor1_1, LOW);
  digitalWrite(Motor1_2, a);
  digitalWrite(Motor2_1, b);
  digitalWrite(Motor2_2, LOW);
}

void atras(int a, int b){
  digitalWrite(Motor1_1, LOW);
  digitalWrite(Motor1_2, a);
  digitalWrite(Motor2_1, LOW);
  digitalWrite(Motor2_2, b);
}

void paro(){
  digitalWrite(Motor1_1, LOW);
  digitalWrite(Motor1_2, LOW);
  digitalWrite(Motor2_1, LOW);
  digitalWrite(Motor2_2, LOW);
}

void ledFunc(){
  if(digitalRead(led)==1){
    digitalWrite(led, LOW);
  }else{
    digitalWrite(led, HIGH);
  }
}
