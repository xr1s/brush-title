# Piotr's Ants

说的是一群蚂蚁在一根木棒上爬，速度1单位每秒，两只蚂蚁相撞会立刻掉头往回爬，现在给出每只蚂蚁的初始位置和方向，求T时间后的位置。

因为两只蚂蚁掉头，相当于两个点横穿而过，蚂蚁的相对位置不变，在左侧还是在左侧，在右侧还是在右侧。这就保证了蚂蚁在木棒上的顺序还是按照一开始给出的来，至于位置，则是所有点向各自方向移动T之后的位置。

于是排序排序排序就好了。