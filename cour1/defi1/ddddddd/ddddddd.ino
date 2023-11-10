byte LED = 13;


void send_S(){
 for (byte i = 0; i<3; i++){
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    Serial.println(1);
  }  
}

void send_O(){
   for (byte i = 0; i<3; i++)
  {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
    Serial.println(2);
  }
  
}

void send_SOS(){ 
  send_S();
  send_O();
  send_S();
}


void setup(){
  // put your setup code here, to run once:
  send_SOS();
}

void loop(){
  exit(1);
}
