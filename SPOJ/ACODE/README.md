# Alphacode

一串1~26的连续编码，问可以分解成多少种可能的数字。

几天前的集训刚做过这题，于是找了原题代码交了。

简单来说，如果当前数字符合条件（1~9范围内）那么就可以从上一个字符转移过来，如果上两个数字符合条件（10~26范围内）就可以从前数第二个状态转移过来。所以就是一发DP。
