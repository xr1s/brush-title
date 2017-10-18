# MediumRSA

用openssl检查了一下，是256位的Modulus。

```
$ openssl rsa -pubin -in pubkey.pem -text -noout

Public-Key: (256 bit)
Modulus:
    00:c2:63:6a:e5:c3:d8:e4:3f:fb:97:ab:09:02:8f:
    1a:ac:6c:0b:f6:cd:3d:70:eb:ca:28:1b:ff:e9:7f:
    be:30:dd
Exponent: 65537 (0x10001)
```

是一个相对比较小的模数，所以可以尝试暴力破解。

首先试用系统自带的`factor`分解，跑了几秒钟无果放弃。去网上搜了一波，WolframAlpha也没跑出来。

接下来就试试看`yafu`了，跑了155s+，出了结果。

最后结果是275127860351348928173285174381581152299和319576316814478949870590164193048041239。

然后用py解密一下即可。
