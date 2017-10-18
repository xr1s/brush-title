# Login

HTTP响应头里有一句

```
Hint: Hint:"select * from `admin` where password='".md5($pass,true)."'"
```

挺毒的。看到了就是套路题了，`md5($pass, true)`是返回未经hexlify的raw md5，有不少特殊的字符串可以做到永真，这里不提供。
