# 2016-2017 CT S03E02: Codeforces Trainings Season 3 Episode 2 - 2004-2005 OpenCup, Volga Grand Prix

## B. Square Root

Java和Python自带高精度类，所以……have fun.

## G. Pair

在数列里找到一对数字使一个数可以被另一个整除。

直接桶排序找。

## H. The Fence

在01串里找到两个距离是K的倍数的1。

暴力找就行了，调和级数求和是log级别的。

## I. Painting the natural numbers

让求一种涂色方案，使得下标a+b的颜色和a和b的颜色都不一样。下标从1开始。

这题不能按照题目给出的套路来，构造的方法还是看源码吧。

## J. Selection

在0..N中选出3个数字使和为偶数，问方案数。

公式题，不说了。

## K. Parquet

问一个N\*M的地板能否用2\*3的地砖铺满。

当时比赛的时候瞎猜的规律，现在不会证明了。详见代码吧。

## L. Closing the Loop

给出S条红或蓝丝带的长度，要求扎成红蓝相间的彩环，而且每次连接两条彩带都会消耗1cm长度，问最后最长的环能有多长。

贪心，找最长的，蓝红找相同的数量，取前min数量个，减去消耗的长度求总长。

