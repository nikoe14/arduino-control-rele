
#include <IRremote.h>

int IR_Recv = 3;  //IR Receiver Pin 3
int rele = 2; 

IRrecv irrecv(IR_Recv);
decode_results results;

void setup(){
  Serial.begin(9600);  //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
  pinMode(rele, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(decCode);
    irrecv.resume(); // Receives the next value from the button you press
    switch (decCode) {
      case 16738455:
        digitalWrite(rele, HIGH);
        break;
      case 16750695:
        digitalWrite(rele, LOW);
        break;
    }
  }
}                               
