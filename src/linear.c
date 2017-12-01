void linear(dir d = up, power p = 127);

void linear(dir d, power p) {
    motor[linear_u] = motor[linear_d] = p * d;
}
