# Entertainment Box

给出一些区间，问最多能选多少最多重复K次重叠区间。

经典贪心题的数据加强版本。用一个multiset维护K个录音带录到什么时候，对于每一段区间查询multiset里是否有<=区间起点的值，如果没有则不能录，如果有删去这个值并插入区间终点。