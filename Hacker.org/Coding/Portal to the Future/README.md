# Portal to the Future

运行，Java报错版本太低，怎么可能嘛，pacman的jre可是最新的Java 9。

然后就去查了一下class文件的文件头，发现有两个字节表示的是最低运行要求，改成Java 8和7都会崩溃，改成6就行了（可见有一定年头了）。
