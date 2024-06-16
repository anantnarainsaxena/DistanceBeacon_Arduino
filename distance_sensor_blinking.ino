#define trigPin 9
#define echoPin 10
#define ledPin 13

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  int blinkDelay;
  if (distance > 60) {
    blinkDelay = 1000; 
  } else if (distance > 30) {
    blinkDelay = 500; 
  } else if (distance > 10) {
    blinkDelay = 250;
  } else {
    blinkDelay = 100; 
  }

  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(blinkDelay);            // wait for the calculated delay
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(blinkDelay);            // wait for the calculated delay
}

