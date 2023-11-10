const byte LED = 13;
const int one_unit = 300;

void send_S(){
 for (byte i = 0; i<2; i++){
    digitalWrite(LED, HIGH);
    delay(one_unit);
    digitalWrite(LED, LOW);
    delay(one_unit);
  }  
 digitalWrite(LED, HIGH);
 delay(one_unit);
 digitalWrite(LED, LOW);
}

void send_O(){
   for (byte i = 0; i<3; i++){
    digitalWrite(LED, HIGH);
    delay(one_unit*3);
    digitalWrite(LED, LOW);
    delay(one_unit);
  }
  digitalWrite(LED, HIGH);
   delay(one_unit*3);
   digitalWrite(LED, LOW);
}

void send_SOS(){ 
  send_S();
  delay(one_unit*3);
  send_O();
  delay(one_unit*3);
  send_S();
}


void setup(){
  // put your setup code here, to run once:
  send_SOS();
}

void loop(){}
