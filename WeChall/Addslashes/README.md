# Addslashes

怎么也想不到辣鸡GBK会被德国佬拿来出题，哈哈哈哈蛤。

经典的GBK绕过addslashes题，利用%bf%5c在gbk里是一个有意义的字符，让`\`失效，来闭合引号。

剩下的简单UNION SELECT一下就好了，不过为了避免使用引号，都得用hex编码了。

