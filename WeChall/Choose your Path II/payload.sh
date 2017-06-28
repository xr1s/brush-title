sed "s,/home/user/xris,$HOME,g" --in-place wc.c
gcc -O3 -Wall -Wextra -Wpedantic -o wc wc.c
cd /home/level/11/ && ./charp2 . && cd - 

