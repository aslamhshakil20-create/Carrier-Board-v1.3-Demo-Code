void read_black_line() {
  sumOnSensor = 0;sensorWight=0;bitSensor=0;
  for (int i = 0; i < sensorNumber; i++) {
    selectChannel(i);delayMicroseconds(20);
    sensorADC[i] = analogRead(SIG_PIN);
    if (sensorADC[i] > Reference_ADC[i]) {
      if (inverseON == 0) {s[i] = 1;} else {s[i] = 0;}}
      else {if (inverseON == 0) {s[i] = 0;} else {s[i] = 1;}}
    sumOnSensor += s[i];
    sensorWight += s[i] * WeightValue[i];
    bitSensor += s[i] * bitWeight[(sensorNumber - 1) - i];}}

void selectChannel(int channel) {
  digitalWrite(S0, bitRead(channel, 0));digitalWrite(S1, bitRead(channel, 1));
  digitalWrite(S2, bitRead(channel, 2));digitalWrite(S3, bitRead(channel, 3));}

void analog_value() {
  while (1) {
    for (int channel = 0; channel < sensorNumber; channel++) {
      selectChannel(channel);
      sensorADC[channel] = analogRead(SIG_PIN);
    }
    u8g.setFont(u8g_font_profont12);  // Set the font
    u8g.firstPage();
    do {
      u8g.setFont(u8g_font_7x14B);
      u8g.setPrintPos(5, 15);
      u8g.print(sensorADC[0]);
      u8g.setPrintPos(35, 15);
      u8g.print(sensorADC[1]);
      u8g.setPrintPos(65, 15);
      u8g.print(sensorADC[2]);
      u8g.setFont(u8g_font_profont12);
      u8g.setPrintPos(10, 30);
      u8g.print(sensorADC[3]);
      u8g.setPrintPos(40, 30);
      u8g.print(sensorADC[4]);
      u8g.setPrintPos(70, 30);
      u8g.print(sensorADC[5]);
      u8g.setPrintPos(100, 30);
      u8g.print(sensorADC[6]);
      u8g.setPrintPos(10, 45);
      u8g.print(sensorADC[7]);
      u8g.setPrintPos(40, 45);
      u8g.print(sensorADC[8]);
      u8g.setPrintPos(70, 45);
      u8g.print(sensorADC[9]);
      u8g.setPrintPos(100, 45);
      u8g.print(sensorADC[10]);
      u8g.setFont(u8g_font_7x14B);
      u8g.setPrintPos(40, 60);
      u8g.print(sensorADC[11]);
      u8g.setPrintPos(70, 60);
      u8g.print(sensorADC[12]);
      u8g.setPrintPos(100, 60);
      u8g.print(sensorADC[13]);
    } while (u8g.nextPage());
    while (button(BUTTON_DOWN_PIN) == 1) return;
  }
}
void digital_value() {
  while (1) {
    read_black_line();
    u8g.firstPage();
    do {
      u8g.setFont(u8g_font_profont12);
      u8g.drawStr(30, 15, "");  //Set Your Team Name
      u8g.setFont(u8g_font_7x14B);
      u8g.setPrintPos(5, 60);
      u8g.print(s[0]);
      u8g.setPrintPos(15, 60);
      u8g.print(s[1]);
      u8g.setPrintPos(25, 60);
      u8g.print(s[2]);
      u8g.setFont(u8g_font_7x14B);
      u8g.setPrintPos(20, 40);
      u8g.print(s[3]);
      u8g.setPrintPos(30, 40);
      u8g.print(s[4]);
      u8g.setPrintPos(40, 40);
      u8g.print(s[5]);
      u8g.setPrintPos(50, 40);
      u8g.print(s[6]);
      u8g.setPrintPos(60, 40);
      u8g.print(s[7]);
      u8g.setPrintPos(70, 40);
      u8g.print(s[8]);
      u8g.setPrintPos(80, 40);
      u8g.print(s[9]);
      u8g.setPrintPos(90, 40);
      u8g.print(s[10]);
      u8g.setPrintPos(100, 60);
      u8g.print(s[11]);
      u8g.setPrintPos(110, 60);
      u8g.print(s[12]);
      u8g.setPrintPos(120, 60);
      u8g.print(s[13]);
    } while (u8g.nextPage());
    while (button(BUTTON_DOWN_PIN) == 1) return;}}
