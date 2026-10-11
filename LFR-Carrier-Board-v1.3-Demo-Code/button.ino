uint8_t button(byte buttonNumber) {
  uint32_t delayCount = 0;
  if (!digitalRead(buttonNumber)) {    delay(50);
    while (!digitalRead(buttonNumber)) {
      delay(50);delayCount += 40;
      if (delayCount > 490) {digitalWrite(led, 1);digitalWrite(buzzer, 1);}}
    digitalWrite(led, 0);
    digitalWrite(buzzer, 0);
    if (delayCount > 490) {return 2;}else {return 1;}}return 0;}