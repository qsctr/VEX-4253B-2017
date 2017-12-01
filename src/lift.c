void lift(dir d, power p = 127);
void lift_time(time t, dir d, power p = 127);
void lift_goal();

void lift(dir d, power p) {
    motor[lift_l] = motor[lift_r] = p * d;
}

void lift_time(time t, dir d, power p) {
    lift(d, p);
    sleep(t);
    lift(stop);
}

void lift_goal() {
    lift(up);
    sleep(200);
    lift(up, 20);
    sleep(100);
    lift(stop);
}
