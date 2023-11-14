const byte LED = 11;
const byte green = 10;
byte light_amount = 0;
byte modification = 5;
const byte delay_time = 250;
char choix = 0;

void input(){
  choix = Serial.parseInt();
  Serial.println("votre choix");
  Serial.println(choix);
}

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(LED, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  analogWrite(LED, light_amount);
  
  input();
  if (choix == 1){
    digitalWrite(green, HIGH);
  }

  else if (choix == 2){
    digitalWrite(green, LOW);
  }

  // bloc de code qui donne une valeur random a modification
  modification = random(100);
  light_amount = map(modification, 0, 100, 0, 255);             // modification = x/100 (%) -> x/255
  //Serial.println(light_amount);
  
  if (light_amount <= 0 || light_amount >= 255) {
    modification = -modification;
  }
  delay(delay_time);
}
