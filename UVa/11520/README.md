# Fill the Square

要求用 A 到 Z 填满方阵, 相邻两项不相同, 字典序最小

显然每个点都只会被相邻的四个点影响, 所以直接填就好了, 因为字典序最小, 所以直接从最左上的开始依次填充, 这样可以保证最重要的被影响最小.
