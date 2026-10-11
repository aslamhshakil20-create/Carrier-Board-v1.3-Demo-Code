void motor(int LPWM, int RPWM) {
  if (LPWM > 0) {digitalWrite(left_motor_forward, HIGH);digitalWrite(left_motor_backward, LOW);}
  else {digitalWrite(left_motor_forward, LOW);digitalWrite(left_motor_backward, HIGH);}
  if (RPWM > 0) {digitalWrite(right_motor_forward, HIGH);digitalWrite(right_motor_backward, LOW);}
  else {digitalWrite(right_motor_forward, LOW);digitalWrite(right_motor_backward, HIGH);}
  LPWM = constrain(LPWM, -255, 255);RPWM = constrain(RPWM, -255, 255);
  analogWrite(left_motor_speed, abs(LPWM));analogWrite(right_motor_speed, abs(RPWM));}

void motor_test() {
  while (1) {
    u8g.setFont(u8g_font_7x14B);  // Set the font
    u8g.firstPage();
    do {
      u8g.drawStr(5, 10, "Motor Testing...");
      u8g.drawStr(5, 25, "1. Both Forward");
      u8g.drawStr(5, 40, "2. LeftM Back");
    } while (u8g.nextPage());
    motor(150, 150);digitalWrite(led, HIGH);
    delay(2000);motor(0, 0);
    digitalWrite(led, LOW);delay(200);
    motor(-150, 0);digitalWrite(led, HIGH);
    delay(2000);motor(0, 0);
    return;}}

void brake(){motor(-255,-255);delay(10);motor(0,0);}
