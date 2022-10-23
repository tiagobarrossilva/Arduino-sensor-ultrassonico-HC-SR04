// C++ code

const byte trigger = 3;
const byte echo = 5;
float duration, distance;

void setup(){
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop(){
  verificarDistancia();
  Serial.print("Distancia: ");
  Serial.println(distance);
  delay(100);
}

void verificarDistancia(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration*.0343)/2; //0.0343 é a velocidade do som em cm/μs
}