# Euclid's Game

SG 打表找规律. OEIS 找数列.

读入的两个数设为 m, n, 仅考虑 n < m 的情况, 有 $m\in(n, \lfloor\varphi n\rfloor]$ 时为先手必败, 其余情况必胜. 这里 $\varphi=(1+\sqrt5)/2$.

该数列被称为 Lower Wythoff 序列.
