void menu() {
  while (1) {
    if (current_screen == 0) {
      if ((digitalRead(BUTTON_UP_PIN) == LOW) && (button_up_clicked == 0)) {  
        item_selected = item_selected - 1;button_up_clicked = 1;                                                
        if (item_selected < 0) {item_selected = NUM_ITEMS - 1;}}
        else if ((digitalRead(BUTTON_DOWN_PIN) == LOW) && (button_down_clicked == 0)) {  
        item_selected = item_selected + 1;                                 
        button_down_clicked = 1;if (item_selected >= NUM_ITEMS) {item_selected = 0;}
      }if ((digitalRead(BUTTON_UP_PIN) == HIGH) && (button_up_clicked == 1)) {button_up_clicked = 0;}
      if ((digitalRead(BUTTON_DOWN_PIN) == HIGH) && (button_down_clicked == 1)) {button_down_clicked = 0;}}
    if ((digitalRead(BUTTON_SELECT_PIN) == LOW) && (button_select_clicked == 0)) {button_select_clicked = 1;}
    if ((digitalRead(BUTTON_SELECT_PIN) == HIGH) && (button_select_clicked == 1)) {button_select_clicked = 0;}
    item_sel_previous = item_selected - 1;
    if (item_sel_previous < 0) { item_sel_previous = NUM_ITEMS - 1; }
    item_sel_next = item_selected + 1;
    if (item_sel_next >= NUM_ITEMS) { item_sel_next = 0; }
    
    if (item_selected == 0 && button_select_clicked == 1) {current_screen = 0;linefollow();}
    if (item_selected == 1 && button_select_clicked == 1) {current_screen = 0;calibrateSensor();}
    if (item_selected == 2 && button_select_clicked == 1) {current_screen = 0;analog_value();}
    if (item_selected == 3 && button_select_clicked == 1) {current_screen = 0;setSpeed();}
    if (item_selected == 4 && button_select_clicked == 1) {current_screen = 0;setKP();}
    if (item_selected == 5 && button_select_clicked == 1) {current_screen = 0;setKD();}
    if (item_selected == 6 && button_select_clicked == 1) {current_screen = 0;set_U_turn();}
    if (item_selected == 7 && button_select_clicked == 1) {current_screen = 0;reset_Setting();}
    if (item_selected == 8 && button_select_clicked == 1) {current_screen = 0;BT_MODE();}
    if (item_selected == 9 && button_select_clicked == 1) {current_screen = 0;motor_test();}
    u8g.firstPage();
    do {if (current_screen == 0) {
        u8g.drawBitmapP(0, 22, 128 / 8, 21, bitmap_item_sel_outline);
        u8g.setFont(u8g_font_7x14);
        u8g.drawStr(25, 15, menu_items[item_sel_previous]);
        u8g.setFont(u8g_font_7x14B);
        u8g.drawStr(25, 15 + 20 + 2, menu_items[item_selected]);
        u8g.setFont(u8g_font_7x14);
        u8g.drawStr(25, 15 + 20 + 20 + 2 + 2, menu_items[item_sel_next]);
        u8g.drawBitmapP(128 - 8, 0, 8 / 8, 64, bitmap_scrollbar_background);
        u8g.drawBox(125, 64 / NUM_ITEMS * item_selected, 3, 64 / NUM_ITEMS);}}
        while (u8g.nextPage());}}