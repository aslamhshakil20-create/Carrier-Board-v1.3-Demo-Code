void setSpeed() {
  while (1) {
    if (button(BUTTON_UP_PIN) == 1) base_speed = base_speed + 5;
    if (button(BUTTON_DOWN_PIN) == 1) base_speed = base_speed - 5;
    if (base_speed > 250) base_speed = 250;
    if (base_speed < 5) base_speed = 5;
    // Set the font
    u8g.firstPage();
    do {
      //title print
      u8g.setFont(u8g_font_7x14B);
      u8g.drawStr(20, 30, "Speed = ");
      //value print
      u8g.setPrintPos(80, 30);
      u8g.print(base_speed);
    } while (u8g.nextPage());
    while (button(BUTTON_SELECT_PIN) == 2) {
      EEPROM.write(50, base_speed);
      return menu();
    }
  }
}

void setKP() {
  while (1) {
    if (button(BUTTON_UP_PIN) == 1) kp = kp + 1;
    if (button(BUTTON_DOWN_PIN) == 1) kp = kp - 1;
    if (kp > 50) kp = 0;
    if (kp < 0) kp = 0;
    // Set the font
    u8g.firstPage();
    do {
      //title print
      u8g.setFont(u8g_font_7x14B);
      u8g.drawStr(20, 30, "KP = ");
      //value print
      u8g.setPrintPos(80, 30);
      u8g.print(kp);
    } while (u8g.nextPage());
    while (button(BUTTON_SELECT_PIN) == 2) {
      EEPROM.write(51, kp);
      return menu();
    }
  }
}

void setKD() {
  while (1) {
    if (button(BUTTON_UP_PIN) == 1) kd = kd + 20;
    if (button(BUTTON_DOWN_PIN) == 1) kd = kd - 20;
    if (kd > 2500) kd = 0;
    if (kd < 0) kd = 0;
    // Set the font
    u8g.firstPage();
    do {
      //title print
      u8g.setFont(u8g_font_7x14B);
      u8g.drawStr(20, 30, "KD = ");
      //value print
      u8g.setPrintPos(80, 30);
      u8g.print(kd);
    } while (u8g.nextPage());
    while (button(BUTTON_SELECT_PIN) == 2) {
      EEPROM.write(52, (kd / 10));
      return menu();
    }
  }
}

void set_U_turn() {
  while (1) {
    if (button(BUTTON_UP_PIN) == 1) U_turn_time = U_turn_time + 20;
    if (button(BUTTON_DOWN_PIN) == 1) U_turn_time = U_turn_time - 20;
    if (U_turn_time > 2500) U_turn_time = 0;
    if (U_turn_time < 0) U_turn_time = 0;
    // Set the font
    u8g.firstPage();
    do {
      //title print
      u8g.setFont(u8g_font_7x14B);
      u8g.drawStr(20, 30, "U Turn = ");
      //value print
      u8g.setPrintPos(80, 30);
      u8g.print(U_turn_time);
    } while (u8g.nextPage());
    while (button(BUTTON_SELECT_PIN) == 2) {
      EEPROM.write(53, (U_turn_time / 10));
      return menu();
    }
  }
}
