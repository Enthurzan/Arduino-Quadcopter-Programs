#define introLettersVar 100

//Intro variables
//--------------------------------------
char introLetters [introLettersVar] {};
int introNumberChars;
String intro = "Welcome the to the Autonomous Intelligent Robotic Software created by Wyatt Johnson ";
int letterTime = 25;
//--------------------------------------


//Motor Variables
//--------------------------------------
int leftMotor = 9;
int rightMotor = 10;
int topMotor = 8;
int bottomMotor = 7;
int testMotorTime = 3000;
//--------------------------------------




//Misc Boolean Variables
//--------------------------------------
bool check = true;
bool inputAsk = true;
bool commandList = true;
bool timeFrameReset = true;
bool offCheck = false;
//--------------------------------------



//Time Variables
//--------------------------------------
int inputTime;
unsigned long timeReset = millis();
unsigned long timeFrame = 0;
unsigned long currentTime;
//--------------------------------------



//Test Rotor Function- tests one motor at a time
//--------------------------------------
void testRotor(int pinNumber) {
  digitalWrite(pinNumber, HIGH);
  delay(testMotorTime);
  digitalWrite(pinNumber, LOW);
}
//--------------------------------------



void setup() {
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  pinMode(topMotor, OUTPUT);
  pinMode(bottomMotor, OUTPUT);
  Serial.begin(9600);

  //Begin intro sequence
  introNumberChars = intro.length();
  intro.toCharArray(introLetters, introNumberChars);
  for (int introCheck = 0; introCheck <= introNumberChars; introCheck++) {
    Serial.print(introLetters[introCheck]);
    delay(letterTime);

  }
  Serial.println(""); 
  Serial.println("The following commands are available: ");
  delay(1000);
  Serial.println("     N           Can enter a new time ");
  delay(1000);
  Serial.println("     X           Stop the current command");

}

void loop() {

  if (Serial.available() > 0) {
    if (Serial.read() == 'N') {
      inputAsk = true;
      check = true;
      timeFrame = 0;
      Serial.println("Processing request...");
    }
  }
  while (check) {
    Serial.println("Enter the time you want to the drone to fly in milliseconds"); //Enter a time you want the motors to be on
    check = false;
  }
  while (inputAsk) { //this while loop waits for the user to enter a time in milliseconds
    if (Serial.available() > 0) {
      inputTime = Serial.parseInt(); //automatically converts char to int
      Serial.println("Initializing Motors...");
      inputAsk = false; //breaks the loop once the user has entered his/her specified time
    }

  }
  timeReset = millis();
  while (timeFrame < inputTime) {
    offCheck = true;
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, HIGH);
    digitalWrite(topMotor, HIGH);
    digitalWrite(bottomMotor, HIGH);
    currentTime = millis();
    timeFrame =  currentTime - timeReset;
    if (Serial.available() > 0)
    {
      if (Serial.read() == 'X') {
        timeFrame = inputTime;
        Serial.println("Turning off drone...");
        Serial.println("Process completed");
      }
    }

  }
  while (offCheck) {
    Serial.println("Turning off drone...");
    Serial.println("Command Completed");
    offCheck = false;
  }
  digitalWrite(leftMotor, LOW);
  digitalWrite(rightMotor, LOW);
  digitalWrite(topMotor, LOW);
  digitalWrite(bottomMotor, LOW);

  // put your main code here, to run repeatedly:

}
