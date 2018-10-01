# Coco Monkey

S 个人分椰子, 分 S 轮, 每一轮将所有剩下的椰子平均分成 S 堆, 总是多出 M 个, 去掉一堆和多余的 M 个之后进入下一轮. 在 S 轮之后剩下的椰子恰好是 S 的倍数, 问在 [l, r] 区间内有哪些值可能是最初的椰子数.

这种题就是逆推了.

首先设 ![R_k](https://latex.codecogs.com/gif.latex?R_k) 为倒数第 k 轮剩下的椰子数, 可得 ![R_k=M+\frac S{S-1}R_{k-1}](https://latex.codecogs.com/gif.latex?R_k%3DM+%5Cfrac%20S%7BS-1%7DR_%7Bk-1%7D) 这个递推式. 直接展开就是一个等比级数相加：

![\begin{aligned}R_S&=M\sum_{k=0}^{S-1}\left(\frac S{S-1}\right)^k+R_0\left(\frac S{S-1}\right)^S\\&=M\frac{\left(\frac S{S-1}\right)^S-1}{\frac S{S-1}-1}+R_0\frac{S^S}{(S-1)^S}\\&=M\frac{S^S-(S-1)^S}{(S-1)^{S-1}}+R_0\frac{S^S}{(S-1)^S}\\&=(M(S-1)+R_0)\frac{S^S}{(S-1)^S}-M(S-1)\end{aligned}](https://latex.codecogs.com/gif.latex?%5Cbegin%7Baligned%7DR_S%26%3DM%5Csum_%7Bk%3D0%7D%5E%7BS-1%7D%5Cleft%28%5Cfrac%20S%7BS-1%7D%5Cright%29%5Ek+R_0%5Cleft%28%5Cfrac%20S%7BS-1%7D%5Cright%29%5ES%5C%5C%26%3DM%5Cfrac%7B%5Cleft%28%5Cfrac%20S%7BS-1%7D%5Cright%29%5ES-1%7D%7B%5Cfrac%20S%7BS-1%7D-1%7D+R_0%5Cfrac%7BS%5ES%7D%7B%28S-1%29%5ES%7D%5C%5C%26%3DM%5Cfrac%7BS%5ES-%28S-1%29%5ES%7D%7B%28S-1%29%5E%7BS-1%7D%7D+R_0%5Cfrac%7BS%5ES%7D%7B%28S-1%29%5ES%7D%5C%5C%26%3D%28M%28S-1%29+R_0%29%5Cfrac%7BS%5ES%7D%7B%28S-1%29%5ES%7D-M%28S-1%29%5Cend%7Baligned%7D)

保证最后的解为整数, 则要求 ![(S-1)^S|M(S-1)+R_0](https://latex.codecogs.com/gif.latex?%28S-1%29%5ES%7CM%28S-1%29+R_0), 又因为最后恰好可以被平分为 S 份, 有 ![S|R_0](https://latex.codecogs.com/gif.latex?S%7CR_0), 则满足以上条件即为可行解. 但是由于 ![(S-1)^S](https://latex.codecogs.com/gif.latex?%28S-1%29%5ES) 可能会很大, 需要特判一下.
