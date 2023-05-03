int en = 3;
int in3 = 5;
int in4 = 4;

int pin_lamp = 7;
int pin_daylight = 8;

void setup() {
	pinMode(en, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
  	pinMode(pin_lamp, INPUT);
  	pinMode(pin_daylight, INPUT);
  	Serial.begin(9600);
}

void clocklize() {
	analogWrite(en, 255);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
  	delay(1000);
  	analogWrite(en, 0);
	
}
void counter_clocklize() {
	analogWrite(en, 255);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
  	delay(1000);
  	analogWrite(en, 0);
}

int already_down = 0;
int already_up = 1;

void loop() {
	digitalWrite(pin_lamp, HIGH);
  	digitalWrite(pin_daylight, HIGH);
  	Serial.println(digitalRead(pin_daylight));
  	delay(100);
  	int inside = digitalRead(pin_lamp);
  	int outside = digitalRead(pin_daylight);

  	if(inside == 0 && already_up)
    {
    	  clocklize();
        already_down = 1, already_up = 0;
    }
 	  if(inside == 1 && outside == 0 && already_down)
     {
        counter_clocklize();
        already_up = 1, already_down = 0;
     }
  	if(inside == 1 && outside == 1 && already_up)
    {
        clocklize();
        already_down = 1, already_up = 0;
    }
}


