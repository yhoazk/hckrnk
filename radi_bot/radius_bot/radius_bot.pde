/*
demostrator for the circular drawer
*/
float r1, r2;
float[][] motors = {{0, 0}, {0,0}};
float d = 0.8 * width;
void setup() {
  size(640,360);
  motors[0][0] = width * 0.1;
  motors[1][0] = width * (1 - 0.1);
  
  motors[0][1] = height * 0.1;
  motors[1][1] = height * (0.1);

}

void motor_radi(int m, float r){
  fill(100,40,30);
  ellipse(motors[m][0], motors[m][1], 10, 10);
  noFill();
  ellipse(motors[m][0], motors[m][1], 2*r, 2*r);
}


void draw(){
  background(100);
  print("x: " + (mouseX - motors[0][0]) + " y: " + (mouseY - motors[0][1]) +" x2: " +( (motors[1][0]) - mouseX ) +"\n");
  r1 = sqrt( pow((mouseY - motors[0][1]), 2) + pow((mouseX - motors[0][0]), 2));
  r2 = sqrt( pow((mouseY - motors[0][1]), 2) + pow(( (motors[1][0]) - mouseX ), 2) );
  motor_radi(0, r1);
  motor_radi(1, r2);
}