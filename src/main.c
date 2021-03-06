#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           claw,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           base_fr,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           base_br,       tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port4,           base_bl,       tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port5,           base_fl,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift_r,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           lift_l,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           arm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           linear_u,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          linear_d,      tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Vex_Competition_Includes.c"
#include "util.c"
#include "base.c"
#include "lift.c"
#include "arm.c"
#include "linear.c"
#include "claw.c"
#include "lcd.c"
#include "auto.c"
#include "driver.c"
