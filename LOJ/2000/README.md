# 「SDOI2017」数字表格

给定 m, n, 求 \prod\_{i=1}^n \prod\_{j=1}^m Fibonacci[gcd(i, j)].

考虑枚举 gcd, 转换为 \prod\_{k=1}^{\min(m,n)} Fibonacci[k]^{f(k)}

其中 f(k) 为 (m,n) 之内所有数对 gcd 为 k 的个数, 这个式子我在[博客](http://xr1s.me/2018/08/31/differenct-mobius-inverse-magic/)里有推导过, 请参考博客.

最后化为 \prod\_{k=1}^{\min(m,n)} \prod\_{r=1}^{\min(m,n)/k} Fibonacci[k]^{\mu(r)\floor(n/(kr))\floor(m/(kr))}. 于是可以预处理 F(kr)=Fibonacci[k]^{\mu(r)}. 预处理复杂度为 O(n\log n), 每次询问复杂度为 O(n\sqrt n\log n).
