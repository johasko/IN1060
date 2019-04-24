//oppgave 2.1

const int inp = 2;
const int out = 3;

int knappTrykket = 0;


void setup() {
  pinMode(out, OUTPUT);
  pinMode(inp, INPUT);

}

void loop() {
  knappTrykket = digitalRead(inp);
  if (knappTrykket != 0) {
    sos();
    
  }
  knappTrykket = 0;

}

void sos() {
  //S
  digitalWrite(out, HIGH);
  delay(200);
  digitalWrite(out, LOW);
  delay(200);
  digitalWrite(out, HIGH);
  delay(200);
  digitalWrite(out, LOW);
  delay(200);
  digitalWrite(out, HIGH);
  delay(200);
  digitalWrite(out, LOW);
  delay(1200);

  //O
  digitalWrite(out, HIGH);
  delay(800);
  digitalWrite(out, LOW);
  delay(800);
  digitalWrite(out, HIGH);
  delay(800);
  digitalWrite(out, LOW);
  delay(800);
  digitalWrite(out, HIGH);
  delay(800);
  digitalWrite(out, LOW);
  delay(1200);

  //S
  digitalWrite(out, HIGH);
  delay(200);
  digitalWrite(out, LOW);
  delay(200);
  digitalWrite(out, HIGH);
  delay(200);
  digitalWrite(out, LOW);
  delay(200);
  digitalWrite(out, HIGH);
  delay(200);
  digitalWrite(out, LOW);
  delay(1200);
  
}
