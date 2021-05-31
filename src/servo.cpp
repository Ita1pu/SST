#include <Arduino.h>
#include "Servo.h"

Servo::Servo(int pwmPinNum, int pwmFreq, int pwmChannel, int pwmResuoltion){
    this->pwm_channel = pwmChannel;
    this->pwm_resolution = pwmResuoltion;
    this->pwm_freq = pwmFreq;
    this->pwm_pinNum = pwmPinNum;
    this->pwm_offset = 889;
    this->pwm_steps = 117;
    // put your setup code here, to run once:
    ledcSetup(this->pwm_channel, this->pwm_freq , this->pwm_resolution);
    /* Attach the LED PWM Channel to the GPIO Pin */
    ledcAttachPin(this->pwm_pinNum , this->pwm_channel);
}

bool Servo::goToPosition(int position){
    bool retVal = false;
    int duty = 0;
    if(position <= 100 && position >= 0){
        duty = (position / 100.0 * this->pwm_steps);
        ledcWrite(this->pwm_channel, duty + this->pwm_offset);
        retVal = true;
    }
    return retVal;
}

void Servo::goHome(){
    this->goToPosition(0);
}

void Servo::goMax(){
    this->goToPosition(100);
}