# CppAGOS


## Test


1. Replace a path to debug dir with your local path.

```bash
PRODUCTS_PATH=/Users/admin/Library/Developer/Xcode/DerivedData/CppAGOS-chpicopqxleupjfsxjmfhenpgqii/Build/Products/Debug
```

2. run test.sh

```bash
// bash test.sh [Exe file name] [Path to dir]
bash test.sh PipeConnection '/path/to/test-data-dir/'
```

#### output

```bash
bash test.sh PipeConnection /Users/admin/Downloads/mcf
.........xxxx.xxxxxxxxxxxxx.xxxxxxxxx.xxxx.xxxxxxx...

[[[Done]]]
success=16 fail=37


[[[successes]]]
mcf.01.in: answer: 0 time: 51 ms
mcf.02.in: answer: 2 time: 34 ms
mcf.03.in: answer: 2 time: 37 ms
mcf.04.in: answer: 4 time: 42 ms
mcf.05.in: answer: 4 time: 41 ms
mcf.06.in: answer: 1 time: 45 ms
mcf.07.in: answer: 7 time: 40 ms
mcf.08.in: answer: 6 time: 37 ms
mcf.09.in: answer: 4 time: 43 ms
mcf.14.in: answer: 0 time: 47 ms
mcf.28.in: answer: 0 time: 929 ms
mcf.38.in: answer: 0 time: 44 ms
mcf.43.in: answer: 0 time: 931 ms
mcf.sample.01.in: answer: 1 time: 36 ms
mcf.sample.02.in: answer: 2 time: 44 ms
mcf.sample.03.in: answer: 0 time: 41 ms


[[[fails]]]
mcf.10.in: expected:5 got:4
mcf.11.in: expected:999 got:231
mcf.12.in: expected:736 got:6
mcf.13.in: expected:503 got:29
mcf.15.in: expected:680 got:206
mcf.16.in: expected:406 got:199
mcf.17.in: expected:648 got:166
mcf.18.in: expected:719 got:242
mcf.19.in: expected:741 got:4
mcf.20.in: expected:592 got:118
mcf.21.in: expected:15229 got:110
mcf.22.in: expected:25801 got:174
mcf.23.in: expected:43417 got:242
mcf.24.in: expected:40496 got:239
mcf.25.in: expected:30041 got:219
mcf.26.in: expected:33799 got:140
mcf.27.in: expected:37403 got:61
mcf.29.in: expected:21105 got:229
mcf.30.in: expected:99999 got:159
mcf.31.in: expected:262 got:34
mcf.32.in: expected:146 got:160
mcf.33.in: expected:220 got:241
mcf.34.in: expected:998 got:230
mcf.35.in: expected:421 got:180
mcf.36.in: expected:480 got:214
mcf.37.in: expected:315 got:73
mcf.39.in: expected:376 got:140
mcf.40.in: expected:408 got:160
mcf.41.in: expected:26831 got:132
mcf.42.in: expected:47070 got:185
mcf.44.in: expected:40069 got:63
mcf.45.in: expected:21548 got:88
mcf.46.in: expected:43864 got:213
mcf.47.in: expected:31710 got:1
mcf.48.in: expected:15599 got:240
mcf.49.in: expected:36020 got:172
mcf.50.in: expected:99998 got:158
```
