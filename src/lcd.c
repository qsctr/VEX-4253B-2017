void init_lcd();
void init_lcd_battery();
void update_lcd_battery();
void set_lcd_choices(const string a = "", const string b = "", const string c = "");
void set_lcd_selected(TControllerButtons b);
TControllerButtons get_lcd_selected(bool l_enabled, bool m_enabled, bool r_enabled);

void init_lcd() {
    bLCDBacklight = true;
}

void init_lcd_battery() {
    clearLCDLine(0);
    displayLCDString(0, 0, "BATTERY X.XXX V ");
}

void update_lcd_battery() {
    static char s[6];
	sprintf(s, "%1.3f", nImmediateBatteryLevel * 0.001);
	displayLCDString(0, 8, s);
}

void set_lcd_choices(const string a, const string b, const string c) {
    clearLCDLine(1);
    displayLCDString(1, 1, a);
    displayLCDString(1, 7, b);
    displayLCDString(1, 13, c);
    set_lcd_selected(kButtonLeft);
}

void set_lcd_selected(TControllerButtons b) {
    switch (b) {
        case kButtonLeft:
            displayLCDChar(1, 0, '[');
            displayLCDChar(1, 3, ']');
            displayLCDChar(1, 6, ' ');
            displayLCDChar(1, 9, ' ');
            displayLCDChar(1, 12, ' ');
            displayLCDChar(1, 15, ' ');
            break;
        case kButtonCenter:
            displayLCDChar(1, 0, ' ');
            displayLCDChar(1, 3, ' ');
            displayLCDChar(1, 6, '[');
            displayLCDChar(1, 9, ']');
            displayLCDChar(1, 12, ' ');
            displayLCDChar(1, 15, ' ');
            break;
        case kButtonRight:
            displayLCDChar(1, 0, ' ');
            displayLCDChar(1, 3, ' ');
            displayLCDChar(1, 6, ' ');
            displayLCDChar(1, 9, ' ');
            displayLCDChar(1, 12, '[');
            displayLCDChar(1, 15, ']');
            break;
    }
}

TControllerButtons get_lcd_selected(bool l_enabled, bool m_enabled, bool r_enabled) {
    TControllerButtons b = nLCDButtons;
    if (b == kButtonLeft && l_enabled
     || b == kButtonCenter && m_enabled
     || b == kButtonRight && r_enabled) {
         set_lcd_selected(b);
    }
    return b;
}

/*

typedef enum lcd_side {
    lcd_side_l,
    lcd_side_m,
    lcd_side_r
} lcd_side;

void set_lcd_opt(lcd_side side, string *opts, int len);
void update_lcd_opts();
int get_lcd_opt(lcd_side side);

string *lcd_opts[3];
int lcd_cur_opts[3] = { 0, 0, 0 };
int lcd_opt_lens[3] = { 0, 0, 0 };

void set_lcd_opt(lcd_side side, string *opts, int len) {
    lcd_opts[side] = lcd_cur_opts[side] = opts;
    lcd_opt_lens[side] = len;
}

void update_lcd_opts() {
    static TControllerButtons prev = kButtonNone;
    TControllerButtons cur = nLCDButtons;
    if (!prev) {
        switch (cur) {
            case kButtonLeft:
                if (lcd_opt_lens[lcd_side_l]) {
                    lcd_cur_opts[lcd_side_l]++;
                    if (lcd_cur_opts[lcd_side_l] >= lcd_opt_lens[lcd_side_l])
                        lcd_cur_opts[lcd_side_l] = 0;
                }
}

int get_lcd_opt(lcd_side side) {
    return 0;
}

*/
