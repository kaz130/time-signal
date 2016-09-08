# time-signal
時報

## コンパイル
```
$ make
```

## 設定例
小山高専の授業時間と合わせる場合

授業開始5分前と授業終了時に鳴る

wiringPiによるGPIO制御のため、要root権限
```
sudo crontab -e
```
```
45 8 * * 1-5 /home/pi/src/time-signal/time-signal 2
20 10 * * 1-5 /home/pi/src/time-signal/time-signal 0
25 10 * * 1-5 /home/pi/src/time-signal/time-signal 2
0 12 * * 1-5 /home/pi/src/time-signal/time-signal 0
50 12 * * 1-5 /home/pi/src/time-signal/time-signal 2
25 14 * * 1-5 /home/pi/src/time-signal/time-signal 0
30 14 * * 1-5 /home/pi/src/time-signal/time-signal 2
5 16 * * 1-5 /home/pi/src/time-signal/time-signal 0
```
