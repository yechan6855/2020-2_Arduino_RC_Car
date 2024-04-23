Bluetooth RC Car project



#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출



char value; //블루투스에서 받는 값

int speed = 100;

void setup() {

  pinMode(9, OUTPUT);

  pinMode(5, OUTPUT);

  pinMode(6, OUTPUT);

  pinMode(7, OUTPUT);



#define BLUE_TX 2 //블루투스 TX

#define BLUE_RX 3 //블루투스 RX



  SoftwareSerial mySerial(BLUE_TX, BLUE_RX);



  Serial.begin(9600); 

  mySerial.begin(9600); 

  Serial.println("Arduino Bluetooth Car is ready to start");

}

void loop() {

  while (mySerial.available())

  {

    value = mySerial.read(); //블루투스 값 읽기

    Serial.print(value);



    if (value == 'f') {    //전진

      Serial.println("forward");

      forward();

    } else if (value == 's') {    //정지

      Serial.println("stop");

      stop();

    } else if (value == 'n') {    //속도 증가

      Serial.println("plus");

      plus();

    } else if (value == 'm') {    //속도 감소

      Serial.println("minus");

      minus();

    }

  }

}



void forward() {

  digitalWrite(9, HIGH);

  digitalWrite(5, LOW);

  digitalWrite(6, HIGH);

  digitalWrite(7, LOW);

  analogWrite(9, speed-9);

  analogWrite(6, speed);

}

void stop() {

  digitalWrite(9, LOW);

  digitalWrite(6, LOW);

}

void plus() {

  speed += 75;

if (speed >= 255)

    speed = 255;

  digitalWrite(9, HIGH);

  digitalWrite(5, LOW);

  digitalWrite(6, HIGH);

  digitalWrite(7, LOW);

  analogWrite(9, speed-9);

  analogWrite(6, speed);

}

void minus() {

  speed -= 75;

if (speed <= 0)

    speed = 9;

  digitalWrite(9, HIGH);

  digitalWrite(5, LOW);

  digitalWrite(6, HIGH);

  digitalWrite(7, LOW);

  analogWrite(9, speed-9);

  analogWrite(6, speed);

}
