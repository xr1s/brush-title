# Leading and Trailing

求 n^k 的高三位和低三位.

低位很好求, 取模即可. 高位显然无法通过保留一定精度求得.

考虑对式子取对数 k\*log10(n), 我们知道整数部分只影响小数点位置, 所以可以直接把整数部分改成 2, 求出来之后保留整数即可.