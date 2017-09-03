# 2016-2017 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2016)

## Balls and Needles

给出n条边，连接三维空间里的点。问三维空间有没有回路以及在xOy平面的投影有没有回路（交叉不算）。

直接建图深搜。这大概就是STL的强大之处。

## Pascal's Hyper-Pyramids

提升维度的Pascal三角形（杨辉三角），定义也差不多，就是（不支持公式，将就一下）C\_{ijk}=C\_{i-1jk}+C\_{ij-1k}+C\_{ijk-1}。

其实还是二项式公式，不过也是提升维度的多项式公式。

我们知道二项式公式是\binom{n}{k}=\frac{n!}{k!(n-k)!}，多项式公式（我自己取的名字）是\frac{n!}{k\_1!k\_2!...k\_m!}，这里的\sum\_{i=0}^mk\_i=n，m为维度，k为各个维度的坐标。

所以直接爆搜出来就可以了。然后，**codeforces的long类型是32位的**，WA了一个小时在上面。
