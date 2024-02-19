#define sensor A0
int in1 = 3;
int in2 = 2;
int enA = 4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  digitalWrite(enA, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  float volts = analogRead(sensor) * 0.00473632812;
  int distance = 13 * pow(volts, -1);
  if (distance < 10000) {
    // Rotera motorn med urs
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH); // PWM HÖG
    Serial.println((distance * 50));
    delayMicroseconds(distance);  // dumpa ut sensor värdet
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delayMicroseconds((distance * 50));
    // PWM LÅG
  } else {
    // Stäng av motorn
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}
