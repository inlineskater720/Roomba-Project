//Confines a value between two chosen parameters
#define clamp(value, min, max) (value < min ? min : value > max ? max : value)

void drive(int,int);
void test();
void goForward();
void halt();
void turnLeft();
void turnRight();
void goBackward();

void drive(int left, int right) {
    
}


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

