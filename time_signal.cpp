#include <iostream>
#include <cstdlib>
#include <wiringPi.h>

void beep(const unsigned int *beepType);

int main(int argc, char *argv[])
{
    // ブザーをONにする時間とOFFにする時間を交互に記述する
    // 単位は ms
    const unsigned int  beepTypes[][7] = {
        {1000, 1000, 1000, 0, 0, 0, 0},
        {500, 500, 500, 500, 500, 0, 0},
        {300, 500, 300, 500, 300, 500, 300}};
    int beepType;

    if (argc > 1) {
        beepType = atoi(argv[1]);
        if (beepType < 0 || beepType >= 3) beepType = 0;
    } else {
        beepType = 2;
    }
    std::cout << beepType << std::endl;
    beep(beepTypes[beepType]);
}

void beep(const unsigned int *beepType)
{
    // GPIO4(7ピン)を使用
    const int pin = 4;

    if(wiringPiSetupGpio() == -1) std::exit(1);
    pinMode(pin, OUTPUT);

    for (int i = 0; i < 3; i++) {
        digitalWrite(pin, 1);
        std::cout << "ON" << std::endl;
        delay(beepType[i*2]);
        digitalWrite(pin, 0);
        std::cout << "OFF" << std::endl;
        delay(beepType[i*2 + 1]);
    }
    digitalWrite(pin, 1);
    std::cout << "ON" << std::endl;
    delay(beepType[6]);
    digitalWrite(pin, 0);
}

