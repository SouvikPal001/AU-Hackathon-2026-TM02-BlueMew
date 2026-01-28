#include <Wire.h>
#include <BH1750.h>

#define RELAY_PIN 7
#define LUX_THRESHOLD 150
#define LUX_SAMPLES 5

BH1750 lightMeter;

bool humanDetected = false;
float luxBuffer[LUX_SAMPLES];
int luxIndex = 0;
bool sensorOK = false;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);   // Lamp OFF (safe)

  Serial.begin(9600);
  Wire.begin();

  // Initialize lux buffer
  for (int i = 0; i < LUX_SAMPLES; i++) {
    luxBuffer[i] = 0;
  }

  sensorOK = lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
  delay(500);

  if (sensorOK) {
    Serial.println("BH1750 detected and started");
  } else {
    Serial.println("❌ BH1750 NOT detected");
  }

  Serial.println("Night Vision Lamp READY");
}

float getAverageLux() {
  float sum = 0;
  for (int i = 0; i < LUX_SAMPLES; i++) {
    sum += luxBuffer[i];
  }
  return sum / LUX_SAMPLES;
}

void loop() {
  // SERIAL INPUT FROM PYTHON
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == '1') humanDetected = true;
    else if (cmd == '0') humanDetected = false;
  }

  float lux = lightMeter.readLightLevel();

  // Accept only valid readings
  if (lux >= 0 && lux < 65535) {
    luxBuffer[luxIndex] = lux;
    luxIndex = (luxIndex + 1) % LUX_SAMPLES;
  }

  float avgLux = getAverageLux();

  // FINAL DECISION
  if (sensorOK && humanDetected && avgLux < LUX_THRESHOLD) {
    digitalWrite(RELAY_PIN, LOW);   // Lamp ON
  } else {
    digitalWrite(RELAY_PIN, HIGH);  // Lamp OFF
  }

  // DEBUG OUTPUT
  Serial.print("Human=");
  Serial.print(humanDetected);
  Serial.print(" | Lux=");
  Serial.print(avgLux);
  Serial.print(" | Raw=");
  Serial.println(lux);

  delay(1000);
}
