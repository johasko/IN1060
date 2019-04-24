//Oppg. 2.2

int potensiometer = 0;
int led = 3;
int styrke;

void setup() {
  pinMode(led, OUTPUT);
  
}

void loop() {
  styrke = analogRead(potensiometer) / 4;
  analogWrite(led, styrke);
}

/*Oppg 2.2 - 4
 * Andre komponenter som kan brukes til å kontrollere lysstyrke er f.eks. knapp, som til forskjell
 * fra analoge komponenter kun kan styre lyset av og på, i tillegg til tilt-sensoren, som har samme
 * mulighet til å styre lyset av og på som knappen. 
 */


/*Oppg. 2.2 - 5
 * Vi kan styre lysstyrken med potensiometeret med Arduinoen kun som en strømkilde,
 * ved å koble en kabel mellom den analoge utgangen til potensiometeret og inputen til
 * LED-pæra. Strømmen vil da automatisk med varierende styrke føres
 * gjennom denne og inn i pæra, som resulterer i muligheten til å "dimme" mellom 0V og 5V.
 */
