# Play with Floor and Ceil

给定 x, k, 求 p, q 使得 ![p\left\lfloor\frac xk\right\rfloor+q\left\lceil\frac xk\right\rceil=x](http://latex.codecogs.com/gif.latex?p%5Cleft%5Clfloor%5Cfrac%20xk%5Cright%5Crfloor+q%5Cleft%5Clceil%5Cfrac%20xk%5Cright%5Crceil%3Dx).

![\left\lfloor\frac xk\right\rfloor](http://latex.codecogs.com/gif.latex?%5Cleft%5Clfloor%5Cfrac%20xk%5Cright%5Crfloor) 和 ![\left\lceil\frac xk\right\rceil](http://latex.codecogs.com/gif.latex?%5Cleft%5Clceil%5Cfrac%20xk%5Cright%5Crceil) 顶多相差一个 1, 而 ![x-k\left\lfloor\frac xk\right\rfloor](http://latex.codecogs.com/gif.latex?x-k%5Cleft%5Clfloor%5Cfrac%20xk%5Cright%5Crfloor) 最多不超过 ![k](http://latex.codecogs.com/gif.latex?k), 所以不足的用 ![\left\lceil\frac xk\right\rceil](http://latex.codecogs.com/gif.latex?%5Cleft%5Clceil%5Cfrac%20xk%5Cright%5Crceil) 补上就好了.
