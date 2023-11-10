const byte LED = 12;
const byte durre = 250;


void blink(int startTime, const byte durre){
    Serial.println("debug");
    int blink = 0;
    int time = 0;
    int currentTime = 0;
    while (blink < 100 && time < 30000){
        Serial.println("hallo");
        time = millis();
        currentTime = (time - startTime) ;
        digitalWrite(LED, HIGH);
        delay(durre);
        digitalWrite(LED, LOW);
        delay(durre);
        blink ++;
        Serial.print(blink);
        Serial.print(" || ");
        Serial.println(time);
    }
}

void setup(){
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
    Serial.println("-----------------------------------------------------------");
    int startTime = millis();
    Serial.println(startTime);
    blink(startTime, durre);
}

void loop(){
    digitalWrite(LED, HIGH);
}
