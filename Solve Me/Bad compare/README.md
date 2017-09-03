# Bad compare

需要GET一串……乱码，浏览器无法解码UTF-8，于是显示为replacement character，也就是U+FFFD。所以我们应当获取raw response，这里我直接用了python的`urllib.request.urlopen`来得到原生字符串。

最后再urlencode一下GET回去。
