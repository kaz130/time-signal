#include <iostream>
#include <cstdlib>
#include <wiringPi.h>

void beep(int time);

int main(int argc, char *argv[])
{
    // 1度に鳴らす回数
    int time;

    if (argc > 1) {
        time = atoi(argv[1]);
        if (time < 0) time = 0;
    } else {
        time = 0;
    }

    beep(time);
}

void beep(int time)
{
    // GPIO4(7ピン)を使用
    const int pin = 4;

    // GPIO初期化
    if(wiringPiSetupGpio() == -1) std::exit(1);
    pinMode(pin, OUTPUT);

    int howLong = 1000 / time;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < time-1; j++) {
            digitalWrite(pin, 1);
            delay(howLong);
            digitalWrite(pin, 0);
            delay(howLong);
        }
        digitalWrite(pin, 1);
        delay(howLong);
        digitalWrite(pin, 0);
        delay(1000);
    }
}

