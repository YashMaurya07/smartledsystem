/* Bluetooth LED control (HC-05 / HC-06)
   - LED on pin LED_PIN (default D13).
   - HC-05 connected to SoftwareSerial pins (RX=10, TX=11).
   - Put a voltage divider on HC-05 RX (Arduino TX -> divider -> HC-05 RX)
*/

#include <SoftwareSerial.h>

const int BT_RX_PIN = 10; // Arduino receives from HC-05 TX on this pin (SoftwareSerial RX)
const int BT_TX_PIN = 11; // Arduino transmits to HC-05 RX on this pin (SoftwareSerial TX)
const int LED_PIN   = 13; // onboard LED or external LED

SoftwareSerial bt(BT_RX_PIN, BT_TX_PIN); // RX, TX

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(9600);      // debug via USB
  bt.begin(9600);          // HC-05 default baud usually 9600
  Serial.println("BT LED control ready. Pair phone and send '1' or '0'.");
}

void loop() {
  // If data from BT
  if (bt.available()) {
    char c = bt.read();
    Serial.print("Received from BT: ");
    Serial.println(c);

    if (c == '1') {
      digitalWrite(LED_PIN, HIGH);
      bt.println("LED:ON");
      Serial.println("LED turned ON");
    } else if (c == '0') {
      digitalWrite(LED_PIN, LOW);
      bt.println("LED:OFF");
      Serial.println("LED turned OFF");
    } else {
      // ignore other characters, but echo for debugging
      bt.print("Unknown:");
      bt.println(c);
    }
  }

  // Optionally: read from Serial (USB) and forward to BT (handy for testing)
  if (Serial.available()) {
    char c = Serial.read();
    bt.write(c);
  }
}
