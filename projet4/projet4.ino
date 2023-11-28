const byte led = 11;
const byte button = 2;
byte button_state = 0;

void use_button() {
  button_state = digitalRead(button);
}


void on_off() {
  use_button();
  switch(button_state) {
    case 1:
      Serial.println("ON");
    case 0:
      Serial.println("OFF");
  }
}
void setup() {
  Serial.begin(9600);
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  on_off();

}
