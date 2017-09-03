# Army Strength

`Scanner`会TLE...所以就手操`InputStream`了，用`InputStreamReader`封装一下，但是这个读入没有buffer，会导致速度更慢，于是再用`BufferedReader`封装一下，一次读取一行，`split(" ")`后得到一个`String[]`，再`Integer.parseInt`。

题意很简单，就是力量弱的会被干掉，大的还活着。这样到最后只会变成强者的竞争，也就是只有最强的会活下来。所以只需要比较最大值即可。
