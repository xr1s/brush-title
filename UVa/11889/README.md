# Benefit

给出 A 和 LCM(A, B), 问最小可能的 B.

这题的难点在于, LCM = A * B / GCD, 然而 GCD 和 A, B 的值共同有关, 所以没有直接的公式可以求出 B.

这里希望把 A 中的 GCD 影响消除, 也就是找到 X | A, 且 GCD(X, C / X) = 1, 我们可以通过不停求出 GCD(A, C / A), 然后用这个值除掉 A, 使得最终 GCD(A, C / A) = 1 即可.
