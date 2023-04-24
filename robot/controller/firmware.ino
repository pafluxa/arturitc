#include <SPI.h>
#include "cobs.h"
#include "firmware_data.h"

// SPI slave select port
#define SLAVE_SELECT 10

// buffer with commands received/transfered over SPI
volatile uint8_t recv_commandBuffer[N_CMD + 1];
volatile uint8_t send_commandBuffer[N_CMD + 1];
volatile size_t nbytes;
volatile uint8_t motorAStatus;
volatile uint8_t motorBStatus;

void setup() 
{
  // Initialize serial port
  Serial.begin(9600);
  while(!Serial)
  {
    delay(10);
  }

  // initialize SPI :
  pinMode(SLAVE_SELECT , INPUT); // Set SlaveSelection as input
  pinMode(13, OUTPUT);   // Set clk as output
  pinMode(11, OUTPUT);   // Set MOSI as output
  pinMode(12, INPUT);    // Set MISO as input
  // SPCR - SPI Control Register
  // According to struct table we enable the SPI and Interface
  SPCR  |= 0b11000000;
  // SPSR - SPI Status Register
  SPSR  |= 0x00;   
}

ISR (SPI_STC_vect)
{
  // encode current command buffer
  nbytes = cobs::encode(send_commandBuffer, N_CMD);

  // receive overhead byte and transfer overhead byte
  recv_commandBuffer[0] = SPI.transfer(send_commandBuffer[0]);

  // receive/transfer rest of the buffer
  for(i = 1; i <= N_CMD; i++) 
  {
    recv_commandBuffer[i] = SPI.transfer(send_commandBuffer[i]);
  }

  // decode received buffer
  nbytes = cobs::decode(recv_commandBuffer, N_CMD);

  // if motor A is idle, set status to "moving"
  if(motorAStatus == STATUS_MOTOR_A_IDLE) 
  {
    motorAStatus = STATUS_MOTOR_A_MOVING;
  }

  // if motor B is idle, set status to "moving"
  if(motorBStatus == STATUS_MOTOR_B_IDLE)
  {
    motorBStatus = STATUS_MOTOR_B_MOVING;
  }
}

void loop() 
{
  // interrupts can happend at any time!
  if(motorAStatus == STATUS_MOTOR_A_)
  delay(1000);
}

/*
  if(received)
  {
    noInterrupts();
    // change pin mode
    if(pin_last_action == CHANGE_MODE)
    {
      if(pin_mode == MODE_OUTPUT) pinMode(pin_id, OUTPUT);
      if(pin_mode == MODE_INPUT) pinMode(pin_id, INPUT);
    }
    // change pin status
    if(pin_last_action == CHANGE_STATUS && pin_mode == MODE_OUTPUT)
    {
      if(pin_status == STATUS_LOW) digitalWrite(pin_id, LOW);
      if(pin_status == STATUS_HIGH) digitalWrite(pin_id, HIGH);
    }
    
    Serial.print(pin_id);
    Serial.print(":");
    Serial.print(pin_mode);
    Serial.print(":");
    Serial.print(pin_status);
    Serial.println("");

    received = false;
  }
  interrupts();
*/
