# Factorial

首先我们知道一个数末尾的10只和这个数2和5的幂次有关，因为一个2和一个5组成了一个10,所以只考虑二者中的出现次数的较小值。

很显然，在阶乘里，2出现的次数不可能比5要多，所以题目就变成了这个数阶乘的质因数5的幂次。

接下来用到一个基础数论知识——n的阶乘分解质因数后每个质因数p的幂次为（这里没有数学公式有点儿不方便……）n不停除以p的和。

证明很显然，不说啥了，就是不停除以5然后加起来。
