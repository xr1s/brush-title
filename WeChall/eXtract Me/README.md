# eXtract Me

`binwalk`没跑出东西来（这个比较诡异，其实是有东西的，是一个Z archive）。

首先拿到一个zip，解压还是一个zip，继续解压是同名的zip，怀疑了一下是同样的文件，比较了一下sha512sum，确认第一次解压与第二次解压出来的是同一个文件，于是先放过。

比较了一下原文件和解压一次的文件后面，发现原文件440字节偏移开始有多余的字节。（因为`binwalk`没认出来所以）用`dd`提取出来`file`检查了一番提示

> compress'd data 16 bits

这个是.Z文件，解压用`uncompress`命令，或者用`zcat`命令。第二层用`file`检查发现是xar文件，用`xar`解压即可。

第四层，`file`查看还是Z文件，继续用`uncompress`解压。

第五层，`file`查看是RAR文件，直接用`unrar`解压。另外又出来了一串hex编码的字符，留待后用。

第六层，`file`查看是XZ文件，用`xz`或者`xzcat`解压。

第七层，`file`查看是Zoo文件，`pacman`下不过来了（不知道为什么403了）于是手动编译了一发。我只想说CNMD这个源码写的是什么破烂玩意儿，上古我不吐槽了，这个makefile里根本无视你的CFLAGS，虽然开头有一句是接收你的CFLAGS，然后后面每个target都是`make CFLAGS="啥玩意儿自己写的根本无视你的CFLAGS"`，卧槽ZZ吧？必须要手动去改每个编译选项才能通过。

第八层，`file`查看是ARJ文件，直接用`arj`解压即可。

第九层，`file`查看是7-Zip文件，直接用`7z`解压即可。

第十层，`file`查看是bzip2文件，直接用`bzip2`解压即可。

然后出来明文

> L0LYouThInkiTSh0uldB3SoEasY?

显然是假的……回到之前第四层的hex字符，解码后是乱码，保存之后发现是LZMA文件，用`lzma`解压。

继续出来一个RAR，继续解压，需要密码。用之前的十层解出来的明文即可得到solution。
