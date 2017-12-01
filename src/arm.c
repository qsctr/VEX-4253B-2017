void move_arm(dir d = in, power p = 127);

void move_arm(dir d, power p) {
    motor[arm] = p * d;
}
