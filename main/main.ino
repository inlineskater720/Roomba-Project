#include <SoftwareSerial.h>

//Constrains a value between min & max
#define clamp(value, min, max) (value < min ? min : value > max ? max : value)

//pin definitions
int rxPin = 10;
int txPin = 11;

//bluetooth input
int data;

//Roomba object
SoftwareSerial Roomba(rxPin,txPin);

//SETUP
void setup() {

 //115200 BAUD RATE
 Serial.begin(115200);
 Roomba.begin(115200);  
 delay (1000);

 Roomba.write(128);  // START
 delay(150);
 delay (1000);
 Roomba.write(131);  // SAFE MODE
 delay(150);
 Serial.println("\n");
 delay (2000);
 // -- playsound? -- //

}

//LOOP
void loop() {


    //test();

    //if input, set data to input.
    while(Serial.available()>0) {
        data = Serial.read();
    }
    
    //decide what to do with data.
    if(data == ) {
        goForward();
    }
    if(data == ) {
        goBackward();
    }
    if(data == ) {
        turnLeft();
    }
    if(data == ) {
        turnRight();
    }
    if(data == ) {
        halt();
    }
    if(data == ) {
        playCMajor();
    }
    if(data == ) {
        playTheLick();
    }
}


//////////////////////////
// FUNCTION DEFINITIONS //
//////////////////////////


void goForward() {
 /*
 Roomba.write(137);   // DRIVE
 Roomba.write((byte)0x00);   // 0x00c8 == 200
 Roomba.write(0xc8);
 Roomba.write(0x80);
 Roomba.write((byte)0x00);
 */
driveWheels(200,200);
}

void goBackward() {
 /*Roomba.write(137);   // DRIVE
 Roomba.write(0xff);   // 0xff38 == -200
 Roomba.write(0x38);
 Roomba.write(0x80);
 Roomba.write((byte)0x00); */
 driveWheels(-200,-200);
}

void halt(){
byte j = 0x00;
Roomba.write(137);
Roomba.write(j);   
Roomba.write(j);
Roomba.write(j);
Roomba.write(j);
}

void turnLeft() {
  driveWheels(200,-200);
}

void turnRight() {
  driveWheels(-200,200);
}


//control each motor individually
void driveWheels(int right, int left) {
  clamp(right, -500, 500);
  clamp(left, -500, 500);
  
  Roomba.write(145);
  Roomba.write(right >> 8); //high byte
  Roomba.write(right); //low byte
  Roomba.write(left >> 8);
  Roomba.write(left);
}

//manual test
void test() {
 goForward();
 delay (2000);
 halt();
 delay (500);
 turnLeft();
 delay (2000);
 halt();
 while(1) { } // Stop loop
}

void setSongOne() {
    Roomba.write(140); //Song opcode
    Roomba.write(1); //song 1
    Roomba.write(4); //4 notes long

    Roomba.write(60); //C  -->  C Major arpeggio - C E G C -- 60  64  67 72
    Roomba.write(16); //1/4th second long
    Roomba.write(64); //E
    Roomba.write(16);
    Roomba.write(67); //G
    Roomba.write(16);
    Roomba.write(72); //C
    Roomba.write(16);
}

void setTheLick() {
    Roomba.write(140);
    Roomba.write(2);
    Roomba.write(7);

    //65 67 68 70 67 63 65
    Roomba.write(65);
    Roomba.write(10);
    Roomba.write(67);
    Roomba.write(10);
    Roomba.write(68);
    Roomba.write(10);
    Roomba.write(70);
    Roomba.write(10);
    Roomba.write(67);
    Roomba.write(20);
    Roomba.write(63);
    Roomba.write(10);
    Roomba.write(65);
    Roomba.write(10);
}

//C Major chord
void playCMajor() {
    Roomba.write(141);
    Roomba.write(1);
}

//    "Alexa, play the lick."
void playTheLick() {
    Roomba.write(141);
    Roomba.write(2);
}