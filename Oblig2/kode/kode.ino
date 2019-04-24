//johasko oblig 2 IN1060 - Arduino 2

//Deklarerer konstante variabler for innganger
const int k1 = 2;
const int k2 = 3;
const int k3 = 4;
const int k4 = 5;
const int ledRed = 6;
const int ledGreen = 7;
const int lydUt = 8;
const int resetKnapp = 9;
const int motor = 11;

int noter[] = {262, 294, 330, 400}; //Noter til piezo

int trykk[15];                      //Array for lagring av trykk så langt

//Deklarerer variabel for teller og rotasjonshastighet for motor
int nummer = 0;
int rotasjon = 250;

//Kode til lås: 3241 (k3, k2, k4, k1)

void setup() {
  Serial.begin(9600);
  pinMode(k1, INPUT);
  pinMode(k2, INPUT);
  pinMode(k3, INPUT);
  pinMode(k4, INPUT);
  pinMode(resetKnapp, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(motor, OUTPUT);
}


void loop() {
  lukket();
  
  apneLyd();
  grontLys();
  motorApne();
  apen();
  lukkeLyd();
  reset();
}


void apen() {
  while (apenSjekk()) {
    grontLys();
    resetSjekk();
  }
}


//Sjekker om knapper trykkes mens låsen er åpen
boolean apenSjekk() {
  boolean sjekk = true;

  if (knappTrykket(k1)) {
    sjekk = false;
  }
  if (knappTrykket(k2)) {
    sjekk = false;
  }
  if (knappTrykket(k3)) {
    sjekk = false;
  }
  if (knappTrykket(k4)) {
    sjekk = false;
  }
  if (knappTrykket(resetKnapp)) {
    sjekk = false;
  }

  return sjekk;
}


void motorApne() {
  analogWrite(motor, rotasjon);
  delay(35);
  analogWrite(motor, 0 );
}


//Kjøres mens kretsen er låst
void lukket() {
  while (sjekkRekke() == false) {
    rodtLys();
    kjoring();
    forMangeTall();
    resetSjekk();
  }
}


//Sjekker rekkefølgen på inputs, og leter etter riktig kombinasjon for koden
boolean sjekkRekke() {
  boolean resultat = false;
  for (int i = 0; i < 15; i++) {
    if (trykk[i] == 3) {
      if (trykk[i+1] == 2) {
        if (trykk[i+2] == 4) {
          if (trykk[i+3] == 1) {
            resultat = true;
          }
        }
      }
    }  
  }return resultat;
}


//Stagnerer når antall inputs når 15
void forMangeTall() {
  if (nummer >= 15) {
      lydFeil();
      nummer = 14;
    }
}


void rodtLys() {
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);
}


void grontLys() {
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
}


//Registrerer knappetrykk og legger til array, samt avspilling av lyd for å bekrefte trykk
void kjoring() {
  if (knappTrykket(k1)) {
    leggTil(1);
    tone(lydUt, noter[2]);
    delay(200);
    noTone(lydUt);
  }
  if (knappTrykket(k2)) {
    leggTil(2);
    tone(lydUt, noter[2]);
    delay(200);
    noTone(lydUt);
  }
  if (knappTrykket(k3)) {
    leggTil(3);
    tone(lydUt, noter[2]);
    delay(200);
    noTone(lydUt);
  }
  if (knappTrykket(k4)) {
    leggTil(4);
    tone(lydUt, noter[2]);
    delay(200);
    noTone(lydUt);
  }  
}


boolean knappTrykket(int knapp) {
  return digitalRead(knapp);
}


void leggTil(int tall) {
  trykk[nummer] = tall;
  nummer = nummer + 1; 
}


//Sjekker om knapp satt opp for å nullstille array trykkes inn
void resetSjekk() {
  if (knappTrykket(resetKnapp)) {
    reset();
    lydReset();
    delay(200);
    lukket();
    }
}


void reset() {
  for (int i = 0; i < 15; i++) {
    trykk[i] = 0;
  }
  nummer = 0;
}


//Funksjoner for de ulike lydkombinasjonene
void apneLyd() {
  tone(lydUt, noter[0]);
  delay(200);
  tone(lydUt, noter[1]);
  delay(200);
  tone(lydUt, noter[2]);
  delay(200);
  tone(lydUt, noter[3]);
  delay(200);
  noTone(lydUt);
}


void lukkeLyd() {
  tone(lydUt, noter[3]);
  delay(200);
  tone(lydUt, noter[2]);
  delay(200);
  tone(lydUt, noter[1]);
  delay(200);
  tone(lydUt, noter[0]);
  delay(200);
  noTone(lydUt);
}


void lydReset() {
  tone(lydUt, noter[3]);
  delay(200);
  tone(lydUt, noter[2]);
  delay(200);
  tone(lydUt, noter[1]);
  delay(200);
  tone(lydUt, noter[0]);
  delay(200);
  noTone(lydUt);
}


void lydFeil() {
  delay(100);
  tone(lydUt, noter[3]);
  delay(200);
  tone(lydUt, noter[0]);
  delay(200);
  noTone(lydUt);
}
