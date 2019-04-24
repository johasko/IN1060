//Oppg. 2.3

unsigned int forrigeTid = 0;
int timer;

void setup() {
 Serial.begin(9600);
}

void loop() {
  timer = millis();
  if (timer - forrigeTid >= 5000) {
    Serial.println("Det har gått fem sekunder!");
    forrigeTid = timer;
  }
}
