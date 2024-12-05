#include <Servo.h>
#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>

modbusDevice regBank;
modbusSlave slave;

word AI0;
int val;
Servo myservo;

void setup()
{
  regBank.setId(1);   //Set Slave ID

  regBank.add(8);  //Add Digital Output registers
  regBank.add(30001);   //Analog Input registers
  regBank.add(40010);   //Analog Output registers
  slave._device = &regBank;
  slave.setBaud(9600);  //Set BaudRate

  myservo.attach(10);

  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT); //GND DO LED
  pinMode(13, OUTPUT); //VCC DO POTENCIOMETRO

  digitalWrite(4, LOW);
  digitalWrite(13, HIGH);
}

void loop() {
  while (1) {

    //Digital Output
    byte DO8 = regBank.get(8);
    if (DO8 <= 0 && digitalRead(8) == HIGH)digitalWrite(8, LOW);
    if (DO8 >= 1 && digitalRead(8) == LOW)digitalWrite(8, HIGH);
    
    //Analog Input
    AI0 = analogRead(A0);
    regBank.set(30001, (word) AI0);
    delay(10);

    //Analog Output (PWM)
    if (digitalRead(8) == HIGH){
    val = analogRead(A0);
    regBank.set(40010, (word) val);
    val = map(val, 0, 1023, 0, 180);
    myservo.write(val);
    delay(10);
    }else if(digitalRead(8) == LOW){
    word AO10 = regBank.get(40010);
    val = AO10;
    val = map(val, 0, 1023, 0, 180);
    myservo.write(val);
    delay(10);
    }
   
    slave.run();
  }
}
