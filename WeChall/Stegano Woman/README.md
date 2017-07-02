# Stegano Woman

两张图片提取出来之后，`exif`提取EXIF，提取缩略图，`strings`都没啥用，也就`strings`看到压缩包里有一堆的冗余数据，以及最后很多诡异的空行。

后来又用`strings`跑一下压缩包发现最后非空行是Stegano，后面接着一堆空行，由于辣鸡`vim`装了个打开zip的插件，没法直接用了，于是先提取出部分数据。

```sh
xxd stegano_woman.zip
```

可以看到，最后的数据偏移量是0x13b6a，后面的20是空格，09是Tab，于是`dd`截取

```sh
dd if=stegano_woman.zip of=crypto bs=1 skip=80746 count=265
```

猜想是二进制，试试看先替换了（不知道为啥，编辑器里似乎自动把Tab给我替换成四个空格了？）

```sh
tr '	 ' '10' < crypto
```

似乎没法解码，换个方向

```sh
tr '	 ' '01' < crypto
```

解出来了。
