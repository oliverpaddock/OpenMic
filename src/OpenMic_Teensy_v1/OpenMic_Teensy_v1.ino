#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#define ADR 0b01001100
#define DAC_ADR 0b01001000
#define PIN_SHD PIN_A3 // 17 pull low to reset
#define PIN_SHD_DAC PIN_A0 // 16

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=365.2708206176758,361.96064281463623
AudioOutputUSB           usb1;           //xy=535.2707862854004,361.9606456756592
AudioConnection          patchCord1(i2s1, 0, usb1, 0);
AudioConnection          patchCord2(i2s1, 1, usb1, 1);
AudioOutputI2S2          i2s2;
AudioInputUSB            usb2;
AudioConnection          patchCord3(usb2, 0, i2s2, 0);
AudioConnection          patchCord4(usb2, 1, i2s2, 1);
// GUItool: end automatically generated code



byte I2C_write(uint8_t address, uint8_t reg, uint8_t data) {
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.write(data);
  return Wire.endTransmission();
}

void ADC_setup() {
  // pull SHD high
  // wait at least 1 ms
  digitalWrite(PIN_SHD, LOW);
  delay(10);
  digitalWrite(PIN_SHD, HIGH);
  delay(1);

  // write to P0_R2 to disable sleep mode
  // wait 1 ms
  I2C_write(ADR, 0x02, 0x81);
  delay(2);

  // I2S, 16 bit output
  I2C_write(ADR, 0x07, 0x40);

  // enable input channels by writing to P0_R115
  I2C_write(ADR, 0x73, 0xC0); // enable channel 1-2
  I2C_write(ADR, 0x3C, 0xB0); // ch1 line input, 0x30 for mic input
  I2C_write(ADR, 0x41, 0xB0); // ch2 line input

  // enable audio serial interface output channels by writing to P0_R116
  I2C_write(ADR, 0x74, 0xC0); // channel 1-2 output

  // channel slots
  I2C_write(ADR, 0x0B, 0x00); // channel 1 L slot 0
  I2C_write(ADR, 0x0C, 0x20); // channel 2 R slot 0

  // power up ADC, MICBIAS, and PLL by writing to P0_R117
  I2C_write(ADR, 0x75, 0x60);
}

void dac_setup() {
  digitalWrite(PIN_SHD_DAC, LOW);
  delay(2);
  digitalWrite(PIN_SHD_DAC, HIGH);
  delay(2);
  digitalWrite(PIN_SHD_DAC, LOW);
  delay(2);
  digitalWrite(PIN_SHD_DAC, HIGH);
  I2C_write(DAC_ADR, 0x00, 0x00);
  I2C_write(DAC_ADR, 0x01, 0x0C);
  I2C_write(DAC_ADR, 0x04, 0x00);
  I2C_write(DAC_ADR, 0x05, 0x68);
  I2C_write(DAC_ADR, 0x06, 0x4A);
  I2C_write(DAC_ADR, 0x07, 0x80);
  I2C_write(DAC_ADR, 0x08, 0x10);
  I2C_write(DAC_ADR, 0x0A, 0x05);
  I2C_write(DAC_ADR, 0x0B, 0x02);
  I2C_write(DAC_ADR, 0x0C, 0x5A);
  I2C_write(DAC_ADR, 0x0D, 0x40);
  I2C_write(DAC_ADR, 0x0E, 0x8A);
  I2C_write(DAC_ADR, 0x0F, 0x00);
  I2C_write(DAC_ADR, 0x10, 0x00);
  I2C_write(DAC_ADR, 0x11, 0x7F);
  I2C_write(DAC_ADR, 0x12, 0xFF);
  I2C_write(DAC_ADR, 0x13, 0xFF);
  I2C_write(DAC_ADR, 0x14, 0xFF);
}

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  pinMode(PIN_SHD, OUTPUT);
  pinMode(PIN_SHD_DAC, OUTPUT);
  ADC_setup();
  dac_setup();
  AudioMemory(120);
}

void loop() {

  // put your main code here, to run repeatedly:
  // for (int i=0; i<100; i++) {
  //   queue1.play(0x0FFF);
  // }
  //   for (int i=0; i<100; i++) {
  //   queue1.play(0x0000);
  // }
}
