# Simple Arithmetics

这题的加减乘实现起来很容易，就是一个高精度，问题就在于输出。

我被坑的地方在于没注意到有这么一句话：

> The horizontal line is always as long as necessary to reach the left and right end of both numbers (and operators) directly below and above it.

这句话的意思是横线必须要和它上下相邻的两个数字（包括运算符）中最长的那个一样长。并不是和全局最长的保持统一，需要的是和相邻的两个保持。

其它（可能）需要注意的比如说一整行的0注意只保留一个（样例有），乘法中间运算只有一个的时候只需要输出一个横线。

说好在SPOJ学Java，然后就用纯C写了个题。
