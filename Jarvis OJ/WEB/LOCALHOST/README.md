# LOCALHOST

页面提示只能localhost访问。所以应当是http header，想到要不是Host要不是XFF，都试了一下结果是XFF。

```
curl --header 'X-Forwarded-For: 127.0.0.1' http://web.jarvisoj.com:32774/
```
