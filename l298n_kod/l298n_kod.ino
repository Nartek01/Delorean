#define sensor A0
int in1 = 3;
int in2 = 2;
int enA = 4;
int enB = 5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(enA, LOW);
}
// Tabort kod

void loop() {
  // put your main code here, to run repeatedly:
  float volts = analogRead(sensor) * 0.00473632812;
  int distance = 13 * pow(volts, -1);

  if (distance <= 10) {
    Serial.println(distance); // Skriv ut avstånd
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  } else {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(enA, HIGH);
  }
}
