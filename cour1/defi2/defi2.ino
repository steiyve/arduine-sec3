byte LED = 3;
byte conte = 0;
int start_time = 0;

void clignote(int duree, int conte){
  while (conte < 100 || duree < 3000){
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    conte++;
    Serial.println(conte);
  }
  digitalWrite(LED, HIGH);
}

void setup() {
  start_time = millis();
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int loop_time = millis();
  int current_time = loop_time - start_time;
  Serial.println(current_time); 
}
