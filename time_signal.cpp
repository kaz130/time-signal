#include <iostream>
#include <cstdlib>
#include <wiringPi.h>

void beep(const unsigned int *signal);

int main(int argc, char *argv[])
{
    // ブザーをONにする時間とOFFにする時間を交互に記述する
    // 単位は ミリ秒
    const unsigned int  signals[][7] = {
        {1000, 1000, 1000, 0, 0, 0, 0},
        {500, 500, 500, 500, 500, 0, 0},
        {300, 500, 300, 500, 300, 500, 300}};
    int signalIndex;

    if (argc > 1) {
        signalIndex = atoi(argv[1]);
        if (signalIndex < 0 || signalIndex >= 3) signalIndex = 0;
    } else {
        signalIndex = 0;
    }

    beep(signals[signalIndex]);
}

void beep(const unsigned int *signal)
{
    // GPIO4(7ピン)を使用
    const int pin = 4;

    // GPIO初期化
    if(wiringPiSetupGpio() == -1) std::exit(1);
    pinMode(pin, OUTPUT);

    for (int i = 0; i < 3; i++) {
        digitalWrite(pin, 1);
        delay(signal[i*2]);
        digitalWrite(pin, 0);
        delay(signal[i*2 + 1]);
    }
    digitalWrite(pin, 1);
    delay(signal[6]);
    digitalWrite(pin, 0);
}

