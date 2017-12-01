task usercontrol() {

    init_lcd_battery();

    while (1) {

        if      (vexRT[Btn6U])  lift(up);
        else if (vexRT[Btn6D])  lift(down);
        else if (vexRT[Btn8U])  lift(up, 10);
        else                    lift(stop);

        int main_drive_l = vexRT[Ch3];
        int main_drive_r = vexRT[Ch2];

        drive_l(forward, abs(main_drive_l) > 20 ? main_drive_l : vexRT[Ch3Xmtr2]);
        drive_r(forward, abs(main_drive_r) > 20 ? main_drive_r : vexRT[Ch2Xmtr2]);

        if      (vexRT[Btn5UXmtr2]) linear(up);
        else if (vexRT[Btn5DXmtr2]) linear(down);
        else                        linear(stop);

        static int prev_arm_toggle = 0;
        static bool arm_hold = false;

        int cur_arm_toggle = vexRT[Btn7UXmtr2];

        if (cur_arm_toggle && !prev_arm_toggle) {
            arm_hold = !arm_hold;
        }

        prev_arm_toggle = cur_arm_toggle;

        if      (vexRT[Btn6UXmtr2]) move_arm(in);
        else if (vexRT[Btn6DXmtr2]) move_arm(out);
        else if (arm_hold)          move_arm(out, 20);
        else                        move_arm(stop);

        if      (vexRT[Btn8LXmtr2]) move_claw(open);
        else if (vexRT[Btn8RXmtr2]) move_claw(close);
        else                        move_claw(stop);

        update_lcd_battery();

        sleep(25);

    }

}
