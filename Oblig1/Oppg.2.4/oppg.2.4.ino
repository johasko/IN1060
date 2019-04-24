//Oppg. 2.4
int antallTrykk = 0;
int knapp = 2;
unsigned long forrigeTrykk = 0;
int forsinkelse = 250;

void setup() {
  pinMode(knapp, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  if (erTrykket(knapp)) {
    antallTrykk++;
    Serial.print("Antall trykk på knappen: ");
    Serial.println(antallTrykk);
  }
}

boolean erTrykket(int knapp) {
  if ((millis() - forrigeTrykk) >= forsinkelse) {
    if (digitalRead(knapp)) {
      forrigeTrykk = millis();
      return true;
    }
  }
  return false;
}
