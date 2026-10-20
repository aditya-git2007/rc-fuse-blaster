```cpp
// ==========================================
// RC FUSE BLASTER — RECEIVER & FIRMWARE
// Secure Remote Pyrotechnic Firing Control
// Developer: Aditya Kumar Gupta (aditya.geninfo.in)
// ==========================================

#define ARM_KEY_PIN    2  // Physical hardware arming switch
#define CONTINUITY_PIN A0 // Bridge wire continuity sensor
#define IGNITER_PIN    5  // MOSFET gate trigger pin
#define STATUS_LED     13 // System status LED

void setup() {
  Serial.begin(115200);
  pinMode(ARM_KEY_PIN, INPUT_PULLUP);
  pinMode(CONTINUITY_PIN, INPUT_PULLUP);
  pinMode(IGNITER_PIN, OUTPUT);
  pinMode(STATUS_LED, OUTPUT);

  digitalWrite(IGNITER_PIN, LOW); // Ensure igniter is OFF
  Serial.println("RC Fuse Blaster Initialized. System Disarmed.");
}

void loop() {
  bool isArmed = (digitalRead(ARM_KEY_PIN) == LOW); // LOW means key turned ON
  bool hasContinuity = (analogRead(CONTINUITY_PIN) > 500); // Check bridge wire

  if (isArmed && hasContinuity) {
    digitalWrite(STATUS_LED, HIGH); // Solid light = ARMED & Ready
    Serial.println("SYSTEM ARMED & CONTINUITY OK. Awaiting remote fire command...");

    // Simulated remote fire command received via RF
    // In production, parse incoming wireless packet here
    bool fireCommandReceived = true; // Placeholder for RF trigger packet

    if (fireCommandReceived) {
      Serial.println("FIRING SEQUENCE INITIATED!");
      digitalWrite(IGNITER_PIN, HIGH); // Send high current pulse
      delay(1200);                     // Energize igniter for 1.2 seconds
      digitalWrite(IGNITER_PIN, LOW);  // Cut power immediately
      Serial.println("Firing pulse completed. Disarming system.");
      while(1); // Lockout until manual reboot
    }
  } else {
    digitalWrite(STATUS_LED, LOW);
    if (!isArmed) Serial.println("Status: System Disarmed (Check Key Switch).");
    if (!hasContinuity) Serial.println("Status: No Igniter Continuity Detected.");
  }

  delay(1000);
}
