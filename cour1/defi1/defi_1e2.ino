byte LED = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

byte temps = 0;
void loop() {
  // put your main code here, to run repeatedly:
  
  //variation
  if (temps == 254){
    temps = 0;
  }
  
  digitalWrite(LED, HIGH);
  delay(temps*2);
  digitalWrite(LED, LOW);
  delay(temps*2);
  
  temps++;
}
