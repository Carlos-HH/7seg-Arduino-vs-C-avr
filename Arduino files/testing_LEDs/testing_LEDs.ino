

void setup() {
  // put your setup code here, to run once:
  int i = 0;
  for(i=2; i<=13; i++){
    pinMode(i, OUTPUT);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int k;
  int digits[]={6, 8, 9, 12};
  for(k=0; k<4; k++){
    digitalWrite(digits[k], HIGH);
    delay(500);
    digitalWrite(digits[k], LOW);
    delay(500); //Si no ponemos dos, pasa inmediatamente al estado anterior
    }
}
