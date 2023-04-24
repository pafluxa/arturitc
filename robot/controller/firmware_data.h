/*
    Header with commands to control motors.
*/
#ifdef _FIRMWARE_DATA_HEADER_
#define _FIRMWARE_DATA_HEADER_

// commands for motor A
// - enable motor A
#define CMD_MOTOR_A_ENABLE 0xA0
// - disable motor a
#define CMD_MOTOR_A_DISABLE 0xA1
// - motor a goes forward
#define CMD_MOTOR_A_FORWARD 0xA2
// - motor a goes backwards
#define CMD_MOTOR_A_BACKWARD 0xA3

// commands for motor B
// - enable motor b
#define CMD_MOTOR_B_ENABLE 0xB0
// - disable motor b
#define CMD_MOTOR_B_DISABLE 0xB1
// - motor b goes forward
#define CMD_MOTOR_B_FORWARD 0xB2
// - motor b goes backwards
#define CMD_MOTOR_B_BACKWARD 0xB3

// buffer indexes of commands
// - number of commands
#define N_CMD 10
// motor a
// - status of motor a (enabled/disabled)
#define IDX_MOTOR_A_STATUS 1
// - direction of motor a (forward/backards)
#define IDX_MOTOR_A_DIRECTION 2
// - PWM value of motor a (i.e. speed)
#define IDX_MOTOR_A_PWM 3
// - Timeout of motor a to reach desired counts (in ms)
#define IDX_MOTOR_A_TIMEOUT_MS 4
// - Target counts of motor a 
#define IDX_MOTOR_A_TARGET_COUNTS 5

// motor b
// - status of motor b
#define IDX_MOTOR_B_STATUS 6
// - direction of motor b
#define IDX_MOTOR_B_DIRECTION 7
// - PWM of motor b (i.e. speed)
#define IDX_MOTOR_B_PWM 8
// - timeout of motor b to reach desired counts (in ms)
#define IDX_MOTOR_B_TIMEOUT_MS 9
// - target counts of motor b
#define IDX_MOTOR_B_TARGET_COUNTS 10

// pin definitions
// - motor A status
#define PIN_MOTOR_A_STATUS 7
// - motor B status
#define PIN_MOTOR_B_STATUS 8 

// status definitions
// motor a
// - motor A is idle
#define STATUS_MOTOR_A_IDLE 0xA4
// - motor A is time'd out
#define STATUS_MOTOR_A_TIMEOUT 0xA5
// - motor A is moving
#define STATUS_MOTOR_A_MOVING 0xA6
// motor b
// - motor B is idle
#define STATUS_MOTOR_B_IDLE 0xB4
// - motor B is time'd out
#define STATUS_MOTOR_B_TIMEOUT 0xB5
// - motor B is moving
#define STATUS_MOTOR_B_MOVING 0xB6

#endif