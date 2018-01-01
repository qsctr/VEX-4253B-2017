typedef enum autoMode_t {
    Zone5,
    Zone20
} autoMode_t;

autoMode_t autoMode = Zone20;

typedef enum side_t {
    Left,
    Right
} side_t;

side_t side = Right;

typedef enum matchType_t {
    Normal,
    Skills
} matchType_t;

matchType_t matchType = Skills;

void pre_auton() {
    init_lcd();
    init_lcd_battery();
    set_lcd_choices(" 5", "20");
    while (bIfiRobotDisabled) {
        switch (get_lcd_selected(true, true, false)) {
            case kButtonLeft:
                autoMode = Zone5;
                break;
            case kButtonCenter:
                autoMode = Zone20;
                break;
        }
        update_lcd_battery();
        sleep(25);
    }
}

task autonomous() {

    move_claw(close, 20);
    move_arm(out);
    sleep(250);
    move_arm(out, 20);
    drive_enc(3000);
    drive(stop);
    move_claw(open);
    lift_goal();
    move_claw(close);
    if (autoMode == Zone20 && side == Right) {
        drive_enc(-base_enc(), 127, 85);
    } else {
        drive_enc(-base_enc());
    }
    move_claw(stop);
    drive(stop);
    sleep(200);
    if (autoMode == Zone5) {
        lift_time(500, down);
        if (side == Left) {
            drive_enc_l(-600);
            drive_l(stop);
        } else {
            drive_enc_r(-600);
            drive_r(stop);
        }
        drive_enc(-100);
        drive(stop);
    } else {
        if (side == Left) {
            drive_enc_l(2250);
            drive_l(stop);
        } else {
            drive_enc_r(2350);
            drive_r(stop);
        }
        drive_enc(700);
        drive(stop);
        sleep(200);
        if (side == Left) {
            drive_enc_l(650);
            drive_l(stop);
        } else {
            drive_enc_r(750);
            drive_r(stop);
        }
        sleep(200);
        lift(up);
        drive_enc(400);
        drive(forward);
        sleep(2000);
        lift(stop);
        drive(stop);
        drive_enc(-1200);
        drive(stop);
        lift_time(1000, down);
    }
    move_arm(stop);

    // right
    if (matchType == Skills) {
        /*
        drive_enc_l(2250);
        drive_enc(1000);
        lift_goal();
        drive_enc(-200);
        drive_enc_r(600);
        drive_enc(2000);
        drive_enc_l(1130);
        drive_enc(3000);
        drive_enc_r(600);
        drive_enc(400);
        lift(up);
        drive(forward);
        sleep(2000);
        lift(stop);
        drive(stop);
        drive_enc(-1200);
        drive(stop);
        lift_time(-1000, down);
        */
        drive_enc_l(2000);
        drive_enc(3000);
    }
}
