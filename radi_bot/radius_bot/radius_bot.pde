/*
demostrator for the circular drawer
*/
float r1, r2;
float[][] motors = {{0, 0}, {0,0}};
JSONArray drawing;
JSONObject coords;
JSONArray coords_to_draw;
int index = 0;
boolean draw;
boolean new_draw;
PGraphics pencil;
void setup() {
  size(640,360);
  motors[0][0] = width * 0.1;
  motors[1][0] = width * (1 - 0.1);
  
  motors[0][1] = height * 0.1;
  motors[1][1] = height * (0.1);
  drawing = new JSONArray();
  coords = new JSONObject();
  draw = false;
  new_draw = false;
  try{
    //coords_to_draw = loadJSONArray("drawing.json");
    print("Ready to draw");
  } catch(Exception e){
    print("NOT ABLE TO READ JSON");
  } finally{
    pencil = createGraphics(width, height);
  }
}  

void motor_radi(int m, float r){
  fill(100,40,30);
  ellipse(motors[m][0], motors[m][1], 10, 10);
  noFill();
  ellipse(motors[m][0], motors[m][1], 2*r, 2*r);
}


void draw(){  
    background(200);  
  if(mousePressed == true){
    frameRate(70);
    print( (mouseX - motors[0][0]) + "," + (mouseY - motors[0][1]) +"\n");
    coords = new JSONObject();
    coords.setFloat("x", (mouseX - motors[0][0]));
    coords.setFloat("y", (mouseY - motors[0][1]));
    drawing.setJSONObject(index++, coords);
    new_draw=true;
  }
  if(draw){
    if(index < coords_to_draw.size()){
       JSONObject xy = coords_to_draw.getJSONObject(index++);
       pencil.beginDraw();
       pencil.fill(0,0,130);
       pencil.ellipse(xy.getFloat("x")+ motors[0][0], xy.getFloat("y")+ motors[0][1], 3, 3);
       pencil.endDraw();
       image(pencil,0,0);
       print(xy.getFloat("x") + " " + xy.getFloat("y") + "\n");
       r1 = sqrt( pow(xy.getFloat("y"), 2) + pow(xy.getFloat("x"), 2));
       r2 = sqrt( pow(xy.getFloat("y"), 2) + pow((motors[1][0]) - (motors[0][0] +xy.getFloat("x")), 2) );
       motor_radi(0, r1);
       motor_radi(1, r2);
       delay(10);
    }
    else{
      draw = false;
      pencil.background(200);
    }
    //
  } else {
    r1 = sqrt( pow((mouseY - motors[0][1]), 2) + pow((mouseX - motors[0][0]), 2));
    r2 = sqrt( pow((mouseY - motors[0][1]), 2) + pow(( (motors[1][0]) - mouseX ), 2) );
    motor_radi(0, r1);
    motor_radi(1, r2);
  }
}


void keyPressed(){
  if(key == ' '){
    saveJSONArray(drawing, "drawing.json");
    draw=true;
    new_draw= false;
    index = 0;
    coords_to_draw = loadJSONArray("drawing.json");
    print("Ready to draw");
  }
}


void dispose(){
  if(new_draw){
    print("Save file");
    saveJSONArray(drawing, "drawing.json");
  }
}