#include <IRremote.h>

int RECV_PIN = 10;
int motor1Fwd=2;  
int motor1Rev=3;
int motor2Fwd=4;
int motor2Rev=5; 
int motor3Fwd=6;
int motor3Rev=7;
int motor4Fwd=8;
int motor4Rev=9;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  //Scoop
  pinMode(motor1Fwd,OUTPUT);
  pinMode(motor1Rev,OUTPUT);
  //Arm pitch
  pinMode(motor2Fwd,OUTPUT);
  pinMode(motor2Rev,OUTPUT);
  //Left tread
  pinMode(motor3Fwd,OUTPUT);
  pinMode(motor3Rev,OUTPUT);
  //Right tread
  pinMode(motor4Fwd,OUTPUT);
  pinMode(motor4Rev,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true);
}

void loop() {

  if (irrecv.decode(&results)) {
    if (results.decode_type == NEC) {
      Serial.print("NEC: ");
    } else if (results.decode_type == SONY) {
      Serial.print("SONY: ");
    } else if (results.decode_type == RC5) {
      Serial.print("RC5: ");
    } else if (results.decode_type == RC6) {
      Serial.print("RC6: ");
    } else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN: ");
    }
    Serial.println(results.value, DEC);
    irrecv.resume(); // Receive the next value
  }
  //Forward
  if (results.value == 16613503){
    digitalWrite(motor2Fwd,HIGH);
    digitalWrite(motor3Fwd,HIGH);
    delay(10);
    digitalWrite(motor2Fwd,LOW);
    digitalWrite(motor3Fwd,LOW);
    delay(20);
  }
  //Reverse
  else if(results.value == 16617583){
    digitalWrite(motor2Rev,HIGH);
    digitalWrite(motor3Rev,HIGH);
    delay(10);
    digitalWrite(motor2Rev,LOW);
    digitalWrite(motor3Rev,LOW);
    delay(20);
  }
  //Right turn
  else if(results.value == 16605343){
    digitalWrite(motor3Fwd,HIGH);
    //digitalWrite(motor2Rev,HIGH);
    
    delay(10);
    
    digitalWrite(motor3Fwd,LOW);
    //digitalWrite(motor2Rev,LOW);
    delay(20);
  //Left turn
  }
  else if(results.value == 16589023){
    digitalWrite(motor2Fwd,HIGH);
    //digitalWrite(motor3Rev,HIGH);
    
    delay(10);
    
    digitalWrite(motor2Fwd,LOW);
    //digitalWrite(motor3Rev,LOW);
    delay(20);
  }
  else if(results.value == 16601263){
    digitalWrite(motor1Rev,HIGH);
    delay(10);
    digitalWrite(motor1Rev,LOW);
    delay(20);
  }
  else if(results.value == 16584943){
   
    digitalWrite(motor1Fwd,HIGH);
    delay(10);
    digitalWrite(motor1Fwd,LOW);
    delay(20);
  }
  else if(results.value == 16597183){
    digitalWrite(motor4Rev,HIGH);
    delay(10);
    digitalWrite(motor4Rev,LOW);
    delay(20);
  }
  else if(results.value == 16580863){
    digitalWrite(motor4Fwd,HIGH);
    delay(10);
    digitalWrite(motor4Fwd,LOW);
    delay(20);
  }
}
