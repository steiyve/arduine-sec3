byte LED = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);                                                         //source: https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor
}

byte temps = 0;
void loop() {
  // put your main code here, to run repeatedly:

  //variation
  if (temps == 254) {
    temps = 0;
  }

  digitalWrite(LED, HIGH);
  Serial.println("ON");
  delay(temps * 2);
  digitalWrite(LED, LOW);
  Serial.print("OFF || ");
  Serial.println(temps);
  delay(temps * 2);
  temps++;
}
