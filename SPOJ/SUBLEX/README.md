# Lexicographical Substring Search

暑假集训做到了这题，于是索性在SPOJ也交了这题。

为此特地去研究了半天的后缀自动机，学的第一个自动机，也是第一个（除hash外的，然而我hash都不熟练）字符串处理方法。大概要回去补补后缀数组？

思路是求出每棵SAM子树的size，然后求第K大的时候直接在树里遍历即可，如果比当前节点的size大，则往字典序更大的兄弟走，是一个很经典的思路。

求子树用了比较巧妙的办法——maxlen大的肯定比maxlen小的靠近根，所以先计数排序，求前缀和，然后枚举SAM节点，对于每个节点的maxlen，往排好序的数组插入一个的时候记录计数排序的数量减小一个，这样恰好一个格子塞入一个值没有冲突而且还是排好序的。

从hzwer学习了SAM的代码，顺带理解了一晚上的SAM，但是完全不会用，这个只是最基础的用法。如果想掌握，怕是还要做很多题。
