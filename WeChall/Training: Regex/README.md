# Training: Regex

对于正则表达式的训练。只需要简单掌握即可通关。

## 第一关

提交一个只匹配空串的正则表达式。

基础知识，`/^$/`。

需要来说说看`//`为什么不行吗，这玩意儿匹配字符串中的任意位置。

## 第二关

提交一个只匹配wechall的正则表达式。

同理`/^wechall$/`。

## 第三关

需要匹配 wechall.ext 或着 wechall4.ext 类型的图片， ext 可以是 jpg gif tiff bmp 或者 png。

这里不对正则进行介绍了，需要的自己去查每个符号的意思好了……`/^wechall4?\.(?:jpg|gif|tiff|bmp|png)$/`。

## 第四关

捕获组的知识，因为上一关就没有捕获后缀名，所以这里只需要加上个括号。`/^(wechall4?)\.(?:jpg|gif|tiff|bmp|png)$/`。

