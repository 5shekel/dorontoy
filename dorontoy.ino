#include <Streaming.h>


//https://www.bananarobotics.com/shop/How-to-use-the-L298N-Dual-H-Bridge-Motor-Driver

#define in01_en 8
#define in01_A 9
#define in01_B 11
#define pot A0

///////// motor /////////////
int inApin[2] = {9, A3};  // INA: Clockwise input
int inBpin[2] = {10, A4}; // INB: Counter-clockwise input
int pwmpin[2] = {11, A5}; // PWM input

int steps;

void setup() {
	Serial.begin(9600);

	pinMode(pot, INPUT);

  // Initialize motor pins as outputs
  for (int i = 0; i < 2; i++)
  {
  	pinMode(inApin[i], OUTPUT);
  	pinMode(inBpin[i], OUTPUT);
  	pinMode(pwmpin[i], OUTPUT);
  }  

}


void loop() {
	int steps = analogRead(pot);

	steps = map(steps, 0, 1024, 250, -250);
	move(0, steps);

	//Serial<<steps<<endl;

}

// motor functions
void move(int motor, int speed) {
	if (speed < -10)
	{
		digitalWrite(inApin[motor], HIGH);
		digitalWrite(inBpin[motor], LOW); 
		analogWrite(pwmpin[motor], abs(speed));
	}
	else if (speed > 10){ 
		digitalWrite(inApin[motor], LOW);
		digitalWrite(inBpin[motor], HIGH);
		analogWrite(pwmpin[motor], abs(speed));
	}else{
		analogWrite(pwmpin[motor], 0);
		
	}
}