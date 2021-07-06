/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder_Wemos.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
const byte PIN_ENC_A = 14;  // D5 (SCK)
const byte PIN_ENC_B = 12;  // D6 (MISO)
const byte PIN_ENC_PB = 13; // D7 (MOSI)
Encoder myEnc(PIN_ENC_A, PIN_ENC_B);      // create encoder object

//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(115200);
  Serial.println("Basic Encoder Test:");
}

long oldPosition  = -999;

void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }
  yield();
}
