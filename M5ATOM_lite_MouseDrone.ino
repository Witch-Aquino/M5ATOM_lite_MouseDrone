#include "M5Atom.h"
#include <BleMouse.h>

BleMouse bleMouse("Standard Mouse");

const int button = 39;
int interval_max = 500;
int interval = 0;
int btnState = 0;

void setup() {
  M5.begin(true, false, true);
  pinMode(button, INPUT);
  attachInterrupt(button,pressed,FALLING);
  bleMouse.begin();
}


void pressed() {
  if (btnState==0) {
    btnState=1;
  } else {
    btnState=0;
  }
}


void loop() {
  if (bleMouse.isConnected()) {
    if (btnState==1) {
      interval++;
      M5.dis.drawpix(0, 0x160000);

      if ( interval >= interval_max ) {
        interval=0;

        M5.dis.drawpix(0, 0x641600);

        bleMouse.move(1, 1);
        delay(100);
        bleMouse.move(-1, -1);
      }

    } else {
      M5.dis.drawpix(0, 0x166400);
    }

  } else {
    M5.dis.drawpix(0, 0x000001);
  }

   delay(1);
   M5.update();

}
