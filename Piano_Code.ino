#include <Servo.h>
#include <SoftwareSerial.h>


SoftwareSerial BTSerial(10, 11); 

Servo myServos[9];

// The Arduino Pins: 2, 3, 4, 5, 6, 7, 8, 9, 12
int servoPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 12};

// --- ANGLES ---
#define ANG_CENTER  90
#define ANG_LEFT    145
#define ANG_RIGHT   30
#define PRESS_TIME  120
int noteToServo[] = {0, 1, 0, 1, 2, 3, 2, 3, 4, 5, 4, 5, 6, 7, 6, 7, 8, 8};

int noteToDir[]   = {1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1,-1, 1,-1};

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  Serial.println("9-Servo Piano Ready!");

  // Attach all 9 servos
  for(int i=0; i<9; i++) {
    myServos[i].attach(servoPins[i]);
    myServos[i].write(ANG_CENTER); 
    delay(50);
  }
}

void loop() {
  if (BTSerial.available()) {
    char cmd = BTSerial.read();
    Serial.write(cmd); 

    // Manual Play: (Letters 'a' through 'r')
    if(cmd >= 'a' && cmd <= 'r') {
      int note = cmd - 'a';
      playNote(note);
    }
    // Song Selection
    else if(cmd == '1') playHappyBirthday();
    else if(cmd == '2') playMerryChristmas();
    else if(cmd == '3') playTwinkleTwinkle(); 
    else if(cmd == '4') playJingleBells();    
    else if(cmd == '5') playOdeToJoy();    
  }
}

void playNote(int noteID) {
  // Safety Limit
  if(noteID > 17) return; 

  int servoID = noteToServo[noteID];
  int direction = noteToDir[noteID];
  
  if(direction == 1) {
    myServos[servoID].write(ANG_LEFT);
    delay(PRESS_TIME);
    myServos[servoID].write(ANG_CENTER);
  } else {
    myServos[servoID].write(ANG_RIGHT);
    delay(PRESS_TIME);
    myServos[servoID].write(ANG_CENTER);
  }
  delay(50); // Small pause between notes
}

// SONGS

void playHappyBirthday() {
  playNote(0); delay(150); playNote(0); delay(150);
  playNote(1); delay(300);
  playNote(0); delay(300);
  playNote(3); delay(300);
  playNote(2); delay(600);
  delay(300);
  playNote(0); delay(150); playNote(0); delay(150);
  playNote(1); delay(300);
  playNote(0); delay(300);
  playNote(4); delay(300);
  playNote(3); delay(600);
}

void playMerryChristmas() {
  playNote(0); delay(300);
  playNote(3); delay(300);
  playNote(3); delay(150); playNote(4); delay(150);
  playNote(3); delay(150); playNote(2); delay(150);
  playNote(1); delay(300); playNote(1); delay(300);
  playNote(1); delay(300); playNote(4); delay(300);
  playNote(4); delay(150); playNote(5); delay(150);
  playNote(4); delay(150); playNote(3); delay(150);
  playNote(2); delay(300); playNote(0); delay(300);
}

void playTwinkleTwinkle() {
  playNote(0); delay(300); playNote(0); delay(300);
  playNote(4); delay(300); playNote(4); delay(300);
  playNote(5); delay(300); playNote(5); delay(300);
  playNote(4); delay(600);
  
  delay(300);
  playNote(7); delay(300); playNote(7); delay(300); 
  playNote(11); delay(300); playNote(11); delay(300); 
  playNote(12); delay(300); playNote(12); delay(300); 
  playNote(11); delay(600); 
}

void playJingleBells() {
  playNote(2); delay(200); playNote(2); delay(200); playNote(2); delay(400);
  playNote(2); delay(200); playNote(2); delay(200); playNote(2); delay(400);
  playNote(9); delay(200); playNote(9); delay(200); playNote(9); delay(400); 
  playNote(9); delay(200); playNote(11); delay(200); 
  playNote(7); delay(200); playNote(8); delay(200);  
  playNote(9); delay(600); 
}

void playOdeToJoy() {
  playNote(2); delay(300); playNote(2); delay(300);
  playNote(3); delay(300); playNote(4); delay(300);
  playNote(4); delay(300); playNote(3); delay(300);
  playNote(2); delay(300); playNote(1); delay(300);
  playNote(0); delay(300); playNote(0); delay(300);
  playNote(1); delay(300); playNote(2); delay(300);
  playNote(2); delay(400); playNote(1); delay(150); playNote(1); delay(600);

  delay(500);

  playNote(9); delay(300); playNote(9); delay(300); 
  playNote(10); delay(300); playNote(11); delay(300); 
  playNote(11); delay(300); playNote(10); delay(300);
  playNote(9); delay(300); playNote(8); delay(300);  
  playNote(7); delay(300); playNote(7); delay(300); 
  playNote(8); delay(300); playNote(9); delay(300);
  playNote(9); delay(400); playNote(8); delay(150); playNote(8); delay(600);

  delay(300);
  playNote(16); delay(200); playNote(17); delay(200); playNote(16); delay(600);
}