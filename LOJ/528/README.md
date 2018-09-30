# 「LibreOJ β Round #4」求和

给出 N, M 求 ![\sum_{i=1}^{N}\sum_{j=1}^M\mu^2(\gcd(i,j))](https://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D1%7D%5E%7BN%7D%5Csum_%7Bj%3D1%7D%5EM%5Cmu%5E2%28%5Cgcd%28i%2Cj%29%29). 范围是 10 的 13 次方级别.

枚举 GCD, 化为 ![\sum_{g=1}^{\min(N,M)}\sum_{g|k}\mu^2(g)\mu\left(\frac kg\right)\left\lfloor\frac Ng\right\rfloor\left\lfloor\frac Mg\right\rfloor](https://latex.codecogs.com/gif.latex?%5Csum_%7Bg%3D1%7D%5E%7B%5Cmin%28N%2CM%29%7D%5Csum_%7Bg%7Ck%7D%5Cmu%5E2%28g%29%5Cmu%5Cleft%28%5Cfrac%20kg%5Cright%29%5Cleft%5Clfloor%5Cfrac%20Ng%5Cright%5Crfloor%5Cleft%5Clfloor%5Cfrac%20Mg%5Cright%5Crfloor).

打表找规律, ![f(g)=\sum_{g|k}\mu^2(g)\mu\left(\frac kg\right)](https://latex.codecogs.com/gif.latex?f%28g%29%3D%5Csum_%7Bg%7Ck%7D%5Cmu%5E2%28g%29%5Cmu%5Cleft%28%5Cfrac%20kg%5Cright%29) 的规律为

![f(g)=\begin{cases}\mu(g)&\text{for }g\text{ is a square number.}\\0&\text{otherwise.}\end{cases}](https://latex.codecogs.com/gif.latex?f%28g%29%3D%5Cbegin%7Bcases%7D%5Cmu%28g%29%26%5Ctext%7Bfor%20%7Dg%5Ctext%7B%20is%20a%20square%20number.%7D%5C%5C0%26%5Ctext%7Botherwise.%7D%5Cend%7Bcases%7D)

然后剩下就枚举 N, M 的因子乘上该函数了.
