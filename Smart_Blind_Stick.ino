const int p1 = 7;//trigger pin
const int p2 = 8;//echo pin
const int buzz = 4;//buzzer pin
const int led = 2; //led pin
const int p3 = 12 ;//trigger pin for second ping
const int p4 = 13 ;//echo pin for second ping
void left();
void right();
void var_delay();
void var_delays();
long cm, duration, durations, cmm, t;


void setup()
{
  Serial.begin(9600);
  pinMode(p1, OUTPUT);
  pinMode(p2, INPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  left();
  Serial.println("left side is: \t");
  Serial.print(cm);
  right();
  Serial.println("right side is: \n");
  Serial.print(cmm);
}
long mTCenti(long microseconds) {

  return microseconds / 29 / 2;           //conversion of microseconds to centimeter
}
void right() {
  //  long duration, cm;

  digitalWrite(p1, LOW);
  delayMicroseconds(2);
  digitalWrite(p1, HIGH);
  delayMicroseconds(5);
  digitalWrite(p1, LOW);

  duration = pulseIn(p2, HIGH);         //getting value of echo pin in duration
  cm = mTCenti(duration);
  Serial.println();
  //  delay(300);
  if (cm < 25)
  {
    var_delay();
  }

}

void left() {
  //  long durations, cmm;
  digitalWrite(p3, LOW);
  delayMicroseconds(2);
  digitalWrite(p3, HIGH);
  delayMicroseconds(5);
  digitalWrite(p3, LOW);
  durations = pulseIn(p4, HIGH);         //getting value of echo pin in durations
  cmm = mTCenti(durations);
  Serial.println();
  if (cmm < 25)
  {
    var_delay();
  }

}

void var_delay() {
  byte t;
  if (cm < cmm)         //left
  {
    t = map(cm, 0, 20, 10, 100);
  }
  else {
    t = map(cmm, 0, 20, 10, 100);       //right
  }
  digitalWrite(buzz, HIGH);
  digitalWrite(led, HIGH);
  delay(t);
  digitalWrite(buzz, LOW);
  digitalWrite(led, LOW);
  delay(t);

}
