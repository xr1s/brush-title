# Cheerleaders

把 K 名啦啦队员放到 N\*M 的格子中, 要求每名啦啦队员都占据一个格子, 且第一行最后一行第一列最后一列必须有至少一个啦啦队员, 问有多少种放置方案. 两种方案被认为是不同的当且仅当所有啦啦队员占据的格子不相同.

容斥一下就好了. 计算出任意摆放的, 减去第一行或最后一行没人的, 减去第一列或最后一列没人的, 加上一行一列没人的, 加上两行没人的, 加上两列没人的, 减去两行一列没人的, 减去两列一行没人的, 加上两行两列均没人的. 每个都是组合数取 K 个人.