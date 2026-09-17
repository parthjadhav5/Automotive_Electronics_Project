#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5
#define RST_PIN 6

// L298N Connections
#define ENA 14
#define IN1 15
#define IN2 16

// Stop Switch
#define STOP_SWITCH 17

MFRC522 rfid(SS_PIN, RST_PIN);

// Authorized RFID Tag UID
byte authorizedUID[4] = {99, 142, 40, 3};

void setup() {

  Serial.begin(115200);

  // Onboard LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Motor Driver
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(ENA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Stop Switch
  pinMode(STOP_SWITCH, INPUT_PULLUP);

  // RC522 SPI
  SPI.setRX(4);
  SPI.setTX(3);
  SPI.setSCK(2);
  SPI.begin();

  rfid.PCD_Init();

  Serial.println("RFID Motor Control Ready");
  Serial.println("Scan RFID Tag...");
}

void loop() {

  if (!rfid.PICC_IsNewCardPresent())
    return;

  if (!rfid.PICC_ReadCardSerial())
    return;

  bool authorized = true;

  for (byte i = 0; i < 4; i++) {
    if (rfid.uid.uidByte[i] != authorizedUID[i]) {
      authorized = false;
      break;
    }
  }

  if (authorized) {

    Serial.println("Access Granted");
    Serial.println("Motor Running");

    // LED ON
    digitalWrite(LED_BUILTIN, HIGH);

    // Motor ON
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    // Keep motor running until switch is pressed
    while (digitalRead(STOP_SWITCH) == HIGH) {
      delay(10);
    }

    Serial.println("Motor Stopped");

    // Motor OFF
    digitalWrite(ENA, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    // LED OFF
    digitalWrite(LED_BUILTIN, LOW);

    delay(500); // debounce
  }

  else {

    Serial.println("Access Denied");

    digitalWrite(ENA, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    digitalWrite(LED_BUILTIN, LOW);
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  delay(200);
}