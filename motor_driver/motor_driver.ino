/** "Koll "Kooplingsschema" i Kod-Bibliotek branchen för att ser hur L298N är kopplad till arduino **/
#define sensor A0
int in1 = 3; // IN1 på L298N
int in2 = 2; // IN2 på L298N
int enA = 4; // Enable A pin
void setup() {
  Serial.begin(19200); // Baudrate ser ingen skillnad på 9600 vs 19200
  pinMode(in1, OUTPUT); // Sätter GPIO pin som kommer från IN1 från L298N till Arduino som OUTPUT
  pinMode(in2, OUTPUT); // Sätter GPIO pin som kommer från IN2 från L298N till Arduino som OUTPUT
  pinMode(enA, OUTPUT);  // Sätter GPIO pin som kommer från Enable A eller ENB från L298N till Arduino som OUTPUT
  digitalWrite(enA, HIGH); // Enable A skicka 5V till L298N, för att indikera att motorn ska starta och är beredd för kommando
}

void loop() {
  // put your main code here, to run repeatedly:
  float volts = analogRead(sensor) * 0.00473632812; // Gångra den analoga värdet med en constant så att det går att skala distans från 3 till 30
  int distance = 13 * pow(volts, -1);
  if (distance < 10000) { // Motorn sluta aldrig att snurra
    // PWM HÖG
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH); 
    Serial.println((distance * 50)); // dumpa ut sensor värdet i millisekunder
    delayMicroseconds(distance); // Duty-cycle
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delayMicroseconds((distance * 50)); // Duty-cycle
    // PWM LÅG
  } else {
    // Stäng av motorn
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}
