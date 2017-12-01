void move_claw(dir d = open, power p = 50);

void move_claw(dir d, power p) {
    motor[claw] = p * d;
}
