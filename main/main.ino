#include <SoftwareSerial.h>

//Constrains a value between min & max
#define clamp(value, min, max) (value < min ? min : value > max ? max : value)

//pin definitions
int rxPin = 10;
int txPin = 11;

int speed = 400;

//bluetooth input
char data;

//Roomba object
SoftwareSerial Roomba(rxPin,txPin);

//SETUP
void setup() {

 //115200 BAUD RATE
 Serial.begin(9600);
 Roomba.begin(115200);  
 Serial.println("Bluetooth ready");
 delay (1000);

 Roomba.write(128);  // START
 delay(150);
 delay (1000);
 Roomba.write(131);  // SAFE MODE
 delay(150);
 Serial.println("\n");
 delay (2000);
 // -- playsound? -- //
 setTheLick();
 setSongOne();
 setMeglovania();

}

//LOOP
void loop() {


    //test();

    //if input, set data to input.
    while(Serial.available()>0) {
        data = Serial.read();
        Serial.println(data);
    }
    
    //decide what to do with data.
    if(data == 'w') {
        goForward();
    }
    if(data == 's') {
        goBackward();
    }
    if(data == 'a') {
        turnLeft();
    }
    if(data == 'd') {
        turnRight();
    }
    if(data == ' ') {
        halt();
    }
    if(data == 'x') {
        clean();
    }
    if(data == 'v') {
      fullMode();
    }
    if(data == 't') {
      playMeglovania();
    }
    if(data == 'q') {
      playTheLick();
    }
    
    data=0;
    
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
driveWheels(speed,speed);
}

void goBackward() {
 /*Roomba.write(137);   // DRIVE
 Roomba.write(0xff);   // 0xff38 == -200
 Roomba.write(0x38);
 Roomba.write(0x80);
 Roomba.write((byte)0x00); */
 driveWheels(-speed,-speed);
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
  driveWheels(speed,-speed);
}

void turnRight() {
  driveWheels(-speed,speed);
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

void setMeglovania() {
    Roomba.write(140);
    Roomba.write(3);
    Roomba.write(40);

    //62 62 74 69 68 67 65 62 65 67
    Roomba.write(62);
    Roomba.write(8);
    Roomba.write(62);
    Roomba.write(8);
    Roomba.write(74);
    Roomba.write(16);
    Roomba.write(69)
    Roomba.write(24);
    Roomba.write(68);
    Roomba.write(16);
    Roomba.write(67);
    Roomba.write(16);
    Roomba.write(65);
    Roomba.write(16);
    Roomba.write(62);
    Roomba.write(8);
    Roomba.write(65);
    Roomba.write(8);
    Roomba.write(67);
    Roomba.write(8);

    Roomba.write(60);
    Roomba.write(8);
    Roomba.write(60);
    Roomba.write(8);
    Roomba.write(74);
    Roomba.write(16);
    Roomba.write(69)
    Roomba.write(24);
    Roomba.write(68);
    Roomba.write(16);
    Roomba.write(67);
    Roomba.write(16);
    Roomba.write(65);
    Roomba.write(16);
    Roomba.write(62);
    Roomba.write(8);
    Roomba.write(65);
    Roomba.write(8);
    Roomba.write(67);
    Roomba.write(8);

    Roomba.write(59);
    Roomba.write(8);
    Roomba.write(59);
    Roomba.write(8);
    Roomba.write(74);
    Roomba.write(16);
    Roomba.write(69)
    Roomba.write(24);
    Roomba.write(68);
    Roomba.write(16);
    Roomba.write(67);
    Roomba.write(16);
    Roomba.write(65);
    Roomba.write(16);
    Roomba.write(62);
    Roomba.write(8);
    Roomba.write(65);
    Roomba.write(8);
    Roomba.write(67);
    Roomba.write(8);

    Roomba.write(58);
    Roomba.write(8);
    Roomba.write(58);
    Roomba.write(8);
    Roomba.write(74);
    Roomba.write(16);
    Roomba.write(69)
    Roomba.write(24);
    Roomba.write(68);
    Roomba.write(16);
    Roomba.write(67);
    Roomba.write(16);
    Roomba.write(65);
    Roomba.write(16);
    Roomba.write(62);
    Roomba.write(8);
    Roomba.write(65);
    Roomba.write(8);
    Roomba.write(67);
    Roomba.write(8);

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

void playMeglovania() {
    Roomba.write(141);
    Roomba.write(3);
}











void clean() {
  Roomba.write(135);
  Serial.println("Cleaning opcode sent");
}

void fullMode() {
  Roomba.write(131);
}

