# time-signal
時報

## コンパイル
```
$ make
```

## 使い方
引数で1秒間に鳴らす回数を指定する。
ブザーは1秒開けて2度繰り返す。
次のコマンドを実行すれば、1秒間に3回鳴った後、1秒開けて再び3回鳴る。

```
$ ./time-signal 3
```

## 設定例
小山高専用の設定例。
授業開始5分前と授業開始時、授業終了時に鳴る。
wiringPiによるGPIO制御のため、要root権限。

```
$ sudo crontab -e
```

```
45 8 * * 1-5 /home/pi/src/time-signal/time-signal 2
50 8 * * 1-5 /home/pi/src/time-signal/time-signal 4
20 10 * * 1-5 /home/pi/src/time-signal/time-signal 1
25 10 * * 1-5 /home/pi/src/time-signal/time-signal 2
30 10 * * 1-5 /home/pi/src/time-signal/time-signal 4
0 12 * * 1-5 /home/pi/src/time-signal/time-signal 1
50 12 * * 1-5 /home/pi/src/time-signal/time-signal 2
55 12 * * 1-5 /home/pi/src/time-signal/time-signal 4
25 14 * * 1-5 /home/pi/src/time-signal/time-signal 1
30 14 * * 1-5 /home/pi/src/time-signal/time-signal 2
35 14 * * 1-5 /home/pi/src/time-signal/time-signal 4
5 16 * * 1-5 /home/pi/src/time-signal/time-signal 1

```
