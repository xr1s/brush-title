# Training: Warchall - The Beginning

很基础的shell题，一共0~5六题，别像我一开始一样去做了第6题……

## level 0

关卡在/home/level/0，就是一个README.txt，查看即获得第一关答案（实际上就是题目里那个）。

## level 1

关卡在/home/level/1，照常，先读取README.txt，提示"follow the black cursor"。看不懂（摔）。

没有`tree`的情况下，可以`ls -RAl`，也可以看到文件夹下的所有文件。

特地去看了一下另外两个路的尽头……玩儿我呢？

## level 2

关卡在/home/level/2。

只有两个文件夹，继续`ls -RAl`，就看到一个.solution文件，直接`cat`就拿到了。

## level 3

关卡在/home/level/3。

什么都没有，继续`ls -RAl`，有一堆.bash\_开头的配置文件和历史记录。

查看历史记录，可以获得题解。

## level 4

关卡在$HOME/level/4。

需要更改权限，原来是没有权限读的，`chmod +r`即可。

### level 5

关卡在$HOME/level/5。

需要更改目录权限，让其它用户没有访问权限。直接`chmod 700`最稳。

