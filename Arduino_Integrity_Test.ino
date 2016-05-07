int led = 13;

void tab(int tabNumber) { //tabs the Serial Monitor by tabNumber space(s)
  for (int tabStart = 0; tabStart < tabNumber; tabStart++) {
    Serial.println("");

  }
}

void wait(int seconds) { //changes delay(milliseconds) to wait(seconds) to save time
  delay(seconds * 1000);

}

void pinHigh(int pin) { //automatically sets pin to HIGH
  digitalWrite(pin, HIGH);
}

void pinLow(int pin) { //automatically sets pin to LOW
  digitalWrite(pin, LOW);
}

void Blink(int pin, int interval){
  pinHigh(pin);
  wait(interval);
  pinHigh(pin);
  wait(interval);
  
}
void setup() {

  Serial.begin(9600); //initialize Serial Communication at 9600 baud

  Serial.println("Hello User");
  tab(1);
  wait(1);
  Serial.println("Current Board is Arduino Uno");
  //Pinmode Setup Code

  pinMode(led, OUTPUT);


  // put your setup code here, to run once:
  for (int test = 0; test < 20; test++) {
    Blink(led, 500);
  }
}


void loop() {
  // put your main code here, to run repeatedly:

}
