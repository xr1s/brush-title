# Farey Sequence

[题目来自室友的博客](http://blog.chrstm.com/2017/08/26/Farey_Sequence/)

求第n个Farey序列的数字个数。Farey序列的定义为所有大小介于0, 1之间且分母不大于n的最简分数。此题的0, 1为开区间。

明显，|F\_n|=|F\_{n-1}|+\varphi(n)，这里varphi为欧拉函数，也就是小于等于n中与n互质的数个数。

欧拉筛求出欧拉函数值，前缀和累加即可，注意一下爆int。
