# 

嘛……CDOJ上似乎已经把题目撤下来了。

题目大意是空间里有个长方体和一个点，给出立方形的边界，给出点的坐标，求这个点到立方体的最短欧几里得距离的平方。

各种判断，如果点在长方体内，毫无疑问是0。

如果点在长方体六个面出去的六个方向上，距离是到这个面的距离。

如果点在上一条六个方向两两组成的平面上，距离是到最近那条边的距离。

其余情况是到最近的点的距离。