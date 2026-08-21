// ======================================================
// INTELLIGENT WATER LEVEL MONITORING & PUMP LOGIC SYSTEM
// HC-SR04 + RELAY + DC PUMP
// OPTIMIZED FOR 10 cm TANK
// ======================================================

#define trigPin 9
#define echoPin 10
#define relayPin 8

// ---------------- TANK SETTINGS ----------------
const float emptyLevel = 10.0; // Empty/low water distance
const float fullLevel = 2.0;   // Full water distance

// ---------------- RELAY SETTINGS ----------------
// Active LOW relay
#define PUMP_ON LOW
#define PUMP_OFF HIGH

float distance = 0;
float lastValidDistance = 10.0;
bool pumpState = false; // false = OFF, true = ON

// ------------------------------------------------
// FUNCTION TO READ HC-SR04 DISTANCE SAFELY
// ------------------------------------------------

float getDistance() {

  float total = 0;
  int validCount = 0;

  // Take 5 readings for stability
  for (int i = 0; i < 5; i++) {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    unsigned long duration = pulseIn(echoPin, HIGH, 30000);

    float d = duration * 0.034 / 2;

    // Accept only valid distance
    if (d > 0 && d <= 20) {
      total += d;
      validCount++;
    }

    delay(50);
  }

  // If valid readings found, return average
  if (validCount > 0) {
    lastValidDistance = total / validCount;
    return lastValidDistance;
  }

  // If sensor misses, use previous valid value
  return lastValidDistance;
}

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);

  Serial.begin(9600);

  // Pump OFF initially
  digitalWrite(relayPin, PUMP_OFF);

  Serial.println("SMART WATER LEVEL SYSTEM STARTED");
  Serial.println("--------------------------------");
}

void loop() {

  distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LOW WATER / EMPTY TANK -> Pump ON
  if (distance >= emptyLevel && pumpState == false) {

    digitalWrite(relayPin, PUMP_ON);
    pumpState = true;

    Serial.println("Pump Turned ON");
  }

  // FULL WATER -> Pump OFF
  else if (distance <= fullLevel && pumpState == true) {

    digitalWrite(relayPin, PUMP_OFF);
    pumpState = false;

    Serial.println("Pump Turned OFF");
  }

  Serial.println("--------------------------------");

  delay(700);
}