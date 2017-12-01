#define DRIVE_MAX_L 127
#define DRIVE_MAX_R 115

void drive(dir d = forward, power pl = DRIVE_MAX_L, power pr = DRIVE_MAX_R);
void drive_l(dir d = forward, power p = 127);
void drive_r(dir d = forward, power p = 127);
enc base_enc();
enc base_enc_l();
enc base_enc_r();
void drive_enc(enc e, power pl = DRIVE_MAX_L, power pr = DRIVE_MAX_R);
void drive_enc_l(enc e, power p = 127);
void drive_enc_r(enc e, power p = 127);
dir enc_dir(enc e);

void drive(dir d, power pl, power pr) {
    drive_l(d, pl);
    drive_r(d, pr);
}

void drive_l(dir d, power p) {
    motor[base_fl] = motor[base_bl] = p * d;
}

void drive_r(dir d, power p) {
    motor[base_fr] = motor[base_br] = p * d;
}

enc base_enc() {
    return (base_enc_l() + base_enc_r()) / 2;
}

enc base_enc_l() {
    return nMotorEncoder(base_bl);
}

enc base_enc_r() {
    return nMotorEncoder(base_br);
}

void base_reset() {
    resetMotorEncoder(base_fr);
    resetMotorEncoder(base_br);
    resetMotorEncoder(base_bl);
    resetMotorEncoder(base_fl);
}

#define drive_encf(drivef, encf, e) \
    base_reset(); \
    drivef; \
    while (e > 0 ? encf() < e : encf() > e);

void drive_enc(enc e, power pl, power pr) {
    drive_encf(drive(enc_dir(e), pl, pr), base_enc, e)
}

void drive_enc_l(enc e, power p) {
    drive_encf(drive_l(enc_dir(e), p), base_enc_l, e)
}

void drive_enc_r(enc e, power p) {
    drive_encf(drive_r(enc_dir(e), p), base_enc_r, e)
}

dir enc_dir(enc e) {
    return e > 0 ? forward : backward;
}
