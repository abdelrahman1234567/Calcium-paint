import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port
float speed,Color,volume,limit = 100;

void setup() {
  size(640, 360);
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.read();         // read it and store it in val
    print(val , "\n");
    if(val > 100){
      val -= 100;
      volume = val * 22 * 14;
    } 
    else if(val > 1000000){
      val -= 1000000;
      speed = val;
    }
    else{
      Color = val;
    }
  }
  background(0,204,255);
  textSize(40);
  fill(255);
  text("Volume: ", 10, 50);
  fill(0);
  text(int(volume),180,50);
  if(volume < 5000)
    fill(0,255,0);
  else
    fill(255,0,0);
  rect(500, 20, 120, 40);
  fill(255);
  text("Color: R =        ,G = 0,B = 0",10,130);
  fill(0);
  text(int(Color),180,130);
  if(Color > 10 && Color < 50)
    fill(0,255,0);
  else
    fill(255,0,0);
  rect(500, 100, 120, 40);
  fill(255);
  text("Stirring speed: ",10,210);
  fill(0);
  if(limit == 100){limit = 0;speed = random(30,50);}
  limit++;
  text(speed,300,210);
  if(speed >= 30 && speed <= 60)
    fill(0,255,0);
  else
    fill(255,0,0);
  rect(500, 180, 120, 40);
  textSize(30);
  fill(0);
  rect(230, 280, 400,60);
  fill(255,0,0);
  text("Made by team [Calcium paint]",250,320);
}
