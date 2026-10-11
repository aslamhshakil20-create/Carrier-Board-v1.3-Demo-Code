void BT_MODE() {
  motorSpeed=EEPROM.read(54);
  u8g.setFont(u8g_font_7x14B);
  u8g.firstPage();
  do {
    u8g.drawStr(30, 10, "Bluetooth");
    u8g.drawStr(35, 25, "Activated");
  } while (u8g.nextPage());
  delay(500);
  while (1) {
    if (digitalRead(BUTTON_DOWN_PIN) == LOW) {
      motor(0, 0);
      delay(200);
      return menu();
    }
    if (Serial.available()) {
      char command = Serial.read();
      // Convert lowercase to uppercase
      if (command >= 'a' && command <= 'z') {
        command = command - 32;
      }
      switch (command) {
        case 'F':
          digitalWrite(led, 1);
          motor(motorSpeed, motorSpeed);
          break;
        case 'B':
          digitalWrite(led, 1);
          motor(-motorSpeed, -motorSpeed);
          break;
        case 'L':
          digitalWrite(led, 1);
          motor(-motorSpeed, motorSpeed);
          break;
        case 'R':
          digitalWrite(led, 1);
          motor(motorSpeed, -motorSpeed);
          break;
        case 'S':
          digitalWrite(led, 0);
          motor(0, 0);
          break;
        case '0':
          motorSpeed = 80;
          EEPROM.write(54, motorSpeed);
          break;
        case '1':
          motorSpeed = 100;
          EEPROM.write(54, motorSpeed);
          break;
        case '2':
          motorSpeed = 120;
          EEPROM.write(54, motorSpeed);
          break;
        case '3':
          motorSpeed = 140;
          EEPROM.write(54, motorSpeed);
          break;
        case '4':
          motorSpeed = 160;
          EEPROM.write(54, motorSpeed);
          break;
        case '5':
          motorSpeed = 180;
          EEPROM.write(54, motorSpeed);
          break;
        case '6':
          motorSpeed = 200;
          EEPROM.write(54, motorSpeed);
          break;
        case '7':
          motorSpeed = 220;
          EEPROM.write(54, motorSpeed);
          break;
        case '8':
          motorSpeed = 240;
          EEPROM.write(54, motorSpeed);
          break;
        case '9':
          motorSpeed = 250;
          EEPROM.write(54, motorSpeed);
          break;
        case 'Q':
          motorSpeed = 255;
          EEPROM.write(54, motorSpeed);
          break;
      }
    }
  }
}