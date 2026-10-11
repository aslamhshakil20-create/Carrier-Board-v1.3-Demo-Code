void linefollow() {
  blackTimer = 0;
  u8g.setFont(u8g_font_7x14B);
  u8g.firstPage();
  do {
    u8g.drawStr(30, 35, "Line Follow");
    u8g.drawStr(40, 50, "Activated");
  } while (u8g.nextPage());
  delay(500);
  while (1) {
a:
    read_black_line();
    if (sumOnSensor > 0) {line_position = sensorWight / sumOnSensor;
      error = center_position - line_position;}
    if (s[0] == 0 && s[13] == 1) { direction = 1; }
    if (s[0] == 1 && s[13] == 0) { direction = 2; }
    if(s[0]||s[1]||s[2]){error=65;}
    if (sumOnSensor == 0) {
      uint32_t timer1 = millis();
      while (sumOnSensor == 0) {
        motor(turnSpeed, turnSpeed);read_black_line();
        if (millis() - timer1 > U_turn_time) {(direction == 1) ? motor(turnSpeed, -turnSpeed) : motor(-turnSpeed, turnSpeed);
          while (s[6] == 0 && s[7] == 0) { read_black_line(); }
          break;}}
    }else if (sumOnSensor == sensorNumber) {
      if (blackTimer == 0) { blackTimer = millis(); }
      if (millis() - blackTimer >= 25) {
        motor(0, 0);
        u8g.firstPage();
        do {u8g.drawStr(40, 30, "FINISH");
          u8g.drawStr(25, 50, "STOPPED");
        } while (u8g.nextPage());
        while (1) {if (digitalRead(BUTTON_DOWN_PIN) == LOW) {delay(200);return menu();}}}
    }else{blackTimer=0;}
    right_motor_correction = base_speed + ((error * kp) + ((error - previous_error) * kd));
    left_motor_correction = base_speed - ((error * kp) + ((error - previous_error) * kd));
    previous_error = error;
    motor(left_motor_correction, right_motor_correction);
    if (digitalRead(BUTTON_DOWN_PIN) == LOW) {motor(0, 0);delay(200);return menu();}}}