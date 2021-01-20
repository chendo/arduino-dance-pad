// Dance Pad for Arduino Leonardo
// by @chendo

#include <Keyboard.h>
// use fastest detection method
#define BOUNCE_WITH_PROMPT_DETECTION
#include <Bounce2.h>

#define PIN_UP 0
#define PIN_DOWN 1
#define PIN_LEFT 2
#define PIN_RIGHT 3
#define PIN_X 4
#define PIN_O 5

#define NUM_BUTTONS 6
// in ms
#define DEBOUNCE_THRESHOLD 50

byte pins[] = {
  PIN_UP,
  PIN_DOWN,
  PIN_LEFT,
  PIN_RIGHT,
  PIN_X,
  PIN_O
};

byte keyCodes[] = { // match to pins above
  KEY_UP_ARROW,
  KEY_DOWN_ARROW,
  KEY_LEFT_ARROW,
  KEY_RIGHT_ARROW,
  KEY_RETURN,
  KEY_ESC,
};

// these have internal state to handle fell/role detection
Bounce debouncers[NUM_BUTTONS];

void setup() {
  for (int i = 0; i < (sizeof(pins) / sizeof(byte)); i++) {
    debouncers[i] = Bounce();
    debouncers[i].attach(pins[i], INPUT_PULLUP);
    debouncers[i].interval(DEBOUNCE_THRESHOLD);
  }
  Keyboard.begin();
}

void loop() {
  uint8_t state = 0;
  
  for (int i = 0; i < (sizeof(pins) / sizeof(byte)); i++) {
    debouncers[i].update();

    if (debouncers[i].fell()) { // on press
      Keyboard.press(keyCodes[i]);
    } else if (debouncers[i].rose()) { // on release
      Keyboard.release(keyCodes[i]);
    }
  }
}
