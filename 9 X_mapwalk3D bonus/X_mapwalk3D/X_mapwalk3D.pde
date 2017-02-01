import processing.serial.*;
Serial myPort;
int cols, 
    rows, 
    scale = 20;
int w=2500,
    h=2000;
float[][] terrain;
float flying;
int degree = 150;
String comPortString;
void setup(){
  size(1200,700,P3D);
  cols = w/scale;
  rows = h/scale;
  terrain = new float[cols][rows];
  myPort = new Serial(this, Serial.list()[2], 9600);
  myPort.bufferUntil('\n'); // Trigger a SerialEvent on new line
 
}
void serialEvent (Serial myPort) {
  String xString = myPort.readStringUntil('\n');  // read the serial port until a new line
  if (xString != null) {  // if theres data in between the new lines
    xString = trim(xString); // get rid of any whitespace just in case
    degree = Integer.parseInt(xString); // set the values to variables
    println(degree);
  }
}


//void serialEvent(Serial cPort){
//  comPortString = cPort.readString();
//  print("read");
//}
void draw(){

  
  flying +=0.2;
  float yoff=flying;
  for(int y=0; y<rows; y++){
    float xoff=0;
    for(int x=0; x<cols; x++){
      if(true) {
        int normal = (int)map(degree, 0,1023, 0, 300);
        terrain[x][y] = map(noise(xoff,yoff), 0,1,-150, normal);
      } 
    //else {terrain[x][y] = map(noise(xoff,yoff), 0,1,-150, 150);}
      xoff += 0.2;
    }
    yoff += 0.2;
  }

  background(0);
  stroke(255);
  noFill();
  
  translate(width/2,height/2);
  rotateX(PI/2.4);
   //rotateX(PI/map(degree, 0 , 1023 , 2.4 , 9));
  translate(-w/2,-h/2-400);
  
  for(int y=0; y<rows-1; y++){
    beginShape(TRIANGLE_STRIP);
    for(int x=0; x<cols; x++){
      fill(terrain[x][y]*5,50,100);
      vertex(x*scale,y*scale, terrain[x][y]);
      vertex(x*scale,(y+1)*scale, terrain[x][y+1]);
    }
    endShape();
  }
}