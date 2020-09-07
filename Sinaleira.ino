#define YELLOW_LED 8
#define RED_LED 13
#define GREEN_LED 7
#define PASS_RED_LED 4
#define PASS_GREEN_LED 2

void setup() {
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(PASS_RED_LED, OUTPUT);
  pinMode(PASS_GREEN_LED, OUTPUT);
}

void loop() {
  onGreen(false);
  onRed(true);
  passAllow();
  delay(3000);
  onRed(false);
  passDenied();
  onGreen(true);
  delay(3000);
  waitYellow();
}

void onRed(bool shine) {
  if(shine == true){
    digitalWrite(RED_LED, HIGH);  
  } else 
    digitalWrite(RED_LED, LOW);
}

void onYellow(bool shine) {
  if(shine == true){
    digitalWrite(YELLOW_LED, HIGH);  
  } else 
    digitalWrite(YELLOW_LED, LOW);
}

void onGreen(bool shine) {
  if(shine == true){
    digitalWrite(GREEN_LED, HIGH);  
  } else 
    digitalWrite(GREEN_LED, LOW);
}

void waitYellow(){
  for (int i = 0; i <= 3; i++) {
    onYellow(1);
    delay(500);
    onYellow(0);
    delay(500);
  }
}

void passAllow() {
  digitalWrite(PASS_GREEN_LED, HIGH);
  digitalWrite(PASS_RED_LED, LOW);
}

void passDenied() {
  digitalWrite(PASS_RED_LED, HIGH);
  digitalWrite(PASS_GREEN_LED, LOW);  
}
