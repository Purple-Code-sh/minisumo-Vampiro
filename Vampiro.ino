#include <Servo.h>
#define Linea_Iz A0
#define Linea_Dr A1
#define Sen_Der 7
#define Sen_Enfr_Der 10
#define Sen_Enfr_Izq 4
#define Sen_Izq 8
#define Band 2
int MotorIzq_1 = 5;
int MotorIzq_2 = 9;
int MotorDer_1 = 3;
int MotorDer_2 = 6;
#define Control A7
Servo Bandera; 

int sensorValue;
int lineValue;
int justOneTime;
int ledi;

void setup() {
  Serial.begin(9600);
  Bandera.attach(Band);
  pinMode(Linea_Iz, INPUT);
  pinMode(Linea_Dr, INPUT);
  pinMode(Sen_Der, INPUT);
  pinMode(Sen_Enfr_Der, INPUT);
  pinMode(Sen_Enfr_Izq, INPUT);
  pinMode(Sen_Izq, INPUT);
  pinMode(MotorIzq_1, OUTPUT);
  pinMode(MotorIzq_2, OUTPUT);
  pinMode(MotorDer_1, OUTPUT);
  pinMode(MotorDer_2, OUTPUT);

  justOneTime = 1;
  
}

void loop() {
  while(1){

    /*if(justOneTime == 1){
      delay(5000);
      justOneTime = 0;
    }*/
    
    //Bandera.write(25);
    sensorValue = sensorState();
    lineValue = 0;
    
    switch(lineValue){
      case 0: //PELEA
        //Serial.println("pelea");
        switch(sensorValue){
          case 0:
            //ninguno detecta
            Serial.println("ninguno");
            adelante(26,255);
            delay(20);
            paro();
            delay(130);
            break;
          case 1:
            //enfrente-der
            Serial.println("enfrente-der");
            derecha(10, 10);
            //paro();
            break;
          case 2:
            //enfrente-izq
            Serial.println("enfrente-izq");
            izquierda(20, 20);
            //paro();
            break;
          case 3:
            //ambos enfrente
            Serial.println("ambos enfrente");
            adelante(1,255);
            delay(5);
            paro();
            delay(250);
            break;
          case 4:
            //Derecha
            Serial.println("solo derecha");
            derecha(18, 18);
            //paro();
            break;
          case 5:
            //Derecha y enfrente-der
            Serial.println("derecha y enf-der");
            derecha(13, 13);
            //paro();
            break;
          case 7:
            // 3 a la derecha
            derecha(8,8);
            break;
          case 8:
            //Izquierda
            Serial.println("solo izquierda");
            //paro();
            izquierda(30,30);
            break;
          case 10:
            //Izquierda y enfrente-izq
            Serial.println("izquierda y enf-izq");
            //paro();
            izquierda(16, 16);
            break;
          case 11:
            // 3 a la izquierda
            izquierda(12,12);
            break;
           case 12:
            // Izquierda y derecha
            izquierda(12,12);
            break;
           case 15:
            // Todos
            adelante(26,255);
            delay(20);
            paro();
            delay(130);
            break;
        }
        break;

      case 1:
        //DERECHA
        Serial.println("linea der");
        /*atras(120, 120);
        delay(400);
        izquierda(120,120);
        delay(400);
        adelante(80,80);*/
       break;

      case 2:
        //IZQUIERDA
        Serial.println("linea izq");
        /*atras(120, 120);
        delay(300);
        derecha(120,120);
        delay(300);
        adelante(80,80);*/
        break;

      case 3:
        Serial.println("linea ambos");
        /*atras(120, 120);
        delay(300);
        izquierda(130,130);
        delay(300);
        adelante(80,80);*/
        break;
    }
  }
  
  //paro();
  //Bandera.write(0);
  
}

// ---------------- Sensores ----------------

int sensorState(){
  int valor_1 = digitalRead(Sen_Enfr_Der); 
  int valor_2 = digitalRead(Sen_Enfr_Izq)*2;
  int valor_Der = digitalRead(Sen_Der)*4;
  int valor_Iz = digitalRead(Sen_Izq)*8;

  int suma = valor_1 + valor_2 + valor_Der + valor_Iz;
  /*Serial.print("S :  ");
  Serial.println(suma);*/
  return suma;
}

int lineState(){
  int valine_Iz =! digitalRead(Linea_Iz);
  int valine_Dr =! digitalRead(Linea_Dr)*2;

  int suma = valine_Iz + valine_Dr;
  /*Serial.print("L :  ");
  Serial.println(suma);*/
  return suma;
}

// ---------------- Motores ----------------

void adelante(int a, int b){
  digitalWrite(MotorIzq_1, a);
  digitalWrite(MotorIzq_2, LOW);
  digitalWrite(MotorDer_1, b);
  digitalWrite(MotorDer_2, LOW);
}

void derecha(int a, int b){
  digitalWrite(MotorIzq_1, a);
  digitalWrite(MotorIzq_2, LOW);
  digitalWrite(MotorDer_1, LOW);
  digitalWrite(MotorDer_2, b);
}

void izquierda(int a, int b){
  digitalWrite(MotorIzq_1, LOW);
  digitalWrite(MotorIzq_2, a);
  digitalWrite(MotorDer_1, b);
  digitalWrite(MotorDer_2, LOW);
}

void atras(int a, int b){
  digitalWrite(MotorIzq_1, LOW);
  digitalWrite(MotorIzq_2, a);
  digitalWrite(MotorDer_1, LOW);
  digitalWrite(MotorDer_2, b);
}

void paro(){
  digitalWrite(MotorIzq_1, LOW);
  digitalWrite(MotorIzq_2, LOW);
  digitalWrite(MotorDer_1, LOW);
  digitalWrite(MotorDer_2, LOW);
}

void ledFunc(){
  if(ledi==1){
    ledi=0;
  }else{
    ledi=1;
  }
}
