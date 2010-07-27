/* *****************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010 LeafLabs LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * ****************************************************************************/

/**
 *  @file example_main.cpp
 *
 *  @brief Sample main.cpp file. Blinks an LED, sends a message out USART2 and
 *  the USB virtual COM port, and turns on PWM on pin 2
 */

#ifndef _EXAMPLE_MAIN_H_
#define _EXAMPLE_MAIN_H_

#endif
#include "wiring.h"
#include "HardwareSerial.h"
#include "HardwareUsb.h"
#include "math.h"
#include "usb.h"
#include "i2c.h"

#define LED_PIN 13
#define PWM_PIN  2

HardwareUsb Usb;

uint8 buf[4];
void setup()
{
    /* Set up the LED to blink  */
    pinMode(LED_PIN, OUTPUT);

    /* Send a message out USART2  */
//    Serial2.begin(115200);
//    Serial2.println("Hello world!");

    /* Turn on PWM on pin PWM_PIN */
//    pinMode(PWM_PIN, PWM);
//    pwmWrite(PWM_PIN, 0x8000);

    /* Send a message out the USB virtual com port  */
//    Usb.println("Hello world!");
    i2c_init(I2C2, 100);
//    i2c_master_write(I2C2, 0x10, &cnt, 1);
//    ASSERT(0);
    buf[0] += 5;
    buf[1] += 10;
    buf[2] += 20;
    buf[3] += 30;
    i2c_master_write(I2C2, 0x10, buf, 4);
}

int toggle = 0;

void loop() {
    toggle ^= 1;
    digitalWrite(LED_PIN, toggle);
    delay(1000);
    buf[0] += 5;
    buf[1] += 10;
    buf[2] += 20;
    buf[3] += 30;
    i2c_master_write(I2C2, 0x10, buf, 4);
//    i2c_master_write(I2C2, 0x11, &cnt, 1);
//    ASSERT(0);
//    Serial2.println(cnt, DEC);
    //i2c_master_write(I2C2, 0x10, &cnt, 1);
}


int main(void) {
    init();
    setup();

    while (1) {
        loop();
    }
    return 0;
}

/* Required for C++ hackery */
/* TODO: This really shouldn't go here... move it later
 * */
extern "C" void __cxa_pure_virtual(void) {
    while(1)
        ;
}
