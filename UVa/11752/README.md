# The Super Power

找到所有 `u64` 以内的数字, 使得它们能表示成至少两个正整数的幂次.

显然只有某个数的合数次幂才能满足, 因为最小的合数是 4, 所以只需要枚举到 2^{64/4} 即可.

顺便注意 `long double` (binary64 extended) 恰好存不下 `uint64_t`.
