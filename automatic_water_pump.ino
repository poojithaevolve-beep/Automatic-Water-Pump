// Automatic Water Pump Using Ultrasonic Sensor

const int trigPin = 9;
const int echoPin = 10;
const int relayPin = 8;

long duration;
float distance;

// Tank level settings (Change according to your tank)
const float FULL_LEVEL = 5.0;   // Pump OFF
const float LOW_LEVEL  = 7.0;  // Pump ON

bool pumpState = false;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, HIGH);   // Relay OFF (Active LOW)

  Serial.begin(9600);
}

void loop()
{
  // Trigger ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Water level control
  if(distance >= LOW_LEVEL && !pumpState)
  {
    digitalWrite(relayPin, LOW);   // Pump ON
    pumpState = true;
    Serial.println("Pump ON");
  }

  if(distance <= FULL_LEVEL && pumpState)
  {
    digitalWrite(relayPin, HIGH);  // Pump OFF
    pumpState = false;
    Serial.println("Pump OFF");
  }

  delay(1000);
}