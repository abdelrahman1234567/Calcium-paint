//Defining the pins of the sensors and motors
#define GateCW 4 // Motor responsible for moving the holes clockwise
#define GateCCW 5 // Motor responsible for moving the holes counter-clockwise

#define Stir 10 // Motor responsible for stirring the product
#define currentSensor A0 // sensor responsible for calculating the current
                        // taken by the stirring motor to calculate the speed

#define trig 3 // Ultrasonic sensor used to measure 
#define echo 2 // the height of product to calculate volume

#define S0 6 // Color sensor's pins 
#define S1 7
#define S2 8
#define S3 9
#define output 10

const int MaxVolume = 5000; // Max volume will be putten in the box
                            // to avoid overflowing out of the box

int limeIdx = 0;
int waterIdx = 1;
int paintIdx = 2;
int colorIdx = 3;
int curridx = -1;

int upperboundSpeed = 60;
int lowerboundSpeed = 30;

struct ColorValue{
  int Red;
  int Blue;
  int Green;
};

ColorValue IdealColor = {20,0,0};

void setup() {
  //Defining the mode of each pin if it is input or output
  pinMode(GateCW, OUTPUT);
  pinMode(GateCCW, OUTPUT);
  pinMode(Stir, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(output, INPUT);

  digitalWrite(S0,HIGH);
  digitalWrite(S1,HIGH);

  Serial.begin(9600);
}

void loop() {
  int motorSpeed = analogRead(currentSensor);
  ColorValue Color = ColorCode(); //Getting values of the color
  
  int height = 40 - Ultrasonic(); // Get the height of the product
  int volume = height * 22 * 14; // Calculating volume of the product in the box
  // length = 22 cm, width = 14 cm, height = calculated with ultrasonic

  if(volume > MaxVolume) //if volume of the product is greater than 
    StopProcess();  // the limit volume the code will stop the process
                    // to avoid any overflow

  if(validColor(Color) == 1) // if the color is heavy or overdose
     openHole(paintIdx); // Increase white paint to make the color lighter
  
  if(validColor(Color) == -1) // if the color is light
    openHole(colorIdx); // Just increase red color

  if(motorSpeed > upperboundSpeed) // if the speed of motor is more than
    openHole(limeIdx);               // usual then the product has light
                                     // viscousity then increase limestone
                              
  if(motorSpeed < lowerboundSpeed) // if the speed of motor is less than
    openHole(waterIdx);              // usual then the product has heavy
                                     // viscousity then increase water
}

void StopProcess(){
  CloseHoles();
  exit(0);
}
