# level 1

第一关，有个莫名其妙的Category，点开来是一句描述——这个hackit真酷。我家的猫真甜啊，喵。

喵你妹啊，选择性无视。

然后在username和password注入无果后注意到url里有个参数`?cat=1`，瞬间明白了注入点在GET。

尝试了一下ORDER BY，发现有四列。

然后随便UNION SELECT了一下，发现回显的是第三列和第四列。

列名题目给出了，可以直接爆字段。
