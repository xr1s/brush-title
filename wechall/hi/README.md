# hi

Hi, imagine this situation.

There is an IRC channel #wechall on irc.idlemonkeys.net.


The server sends the messages to all people in the channel, also back to the sender himself.

When every minute one person joins and says hi,

how many "hi" messages were totally sent for this channel after 0xfffbadc0ded minutes ?

No one ever leaves the channel, so there are 0xfffbadc0ded people at the end ;)


Further explanation for 3 minutes:

the channel is empty and there have been sent 0 messages 1st person joins, sends hi, the server sends hi back to 1 persons.

2nd person joins, sends hi, the server sends hi back to 2 persons.

3rd person joins, sends hi, the server sends hi back to 3 persons.


Minute 1: 2 messages sent

Minute 2: 3 messages sent

Minute 3: 4 messages sent

Adding these up means for 3 minutes are 9 messages sent.


Conversion Notes: 0xfffbadc0ded is hexadecimal which converts to 17.591.026.060.781 (Thats around 20 trillion minutes).Please submit your solution in the decimal system.

## 翻译

假设某个IRC服务器每分钟给所有登录的人发送一句hi，而从第一分钟开始就有人接入，而且每个接入的人都会给服务器发一句hi。问在第0xfffbadc0ded分钟，服务器里总共发送和接收了多少hi。

拿前三分钟举了个例子，

第一分钟一个人进入，给服务器发了1句hi，服务器给所有1个人发了hi

第二分钟一个人进入，给服务器发了1句hi，服务器给所有2个人发了hi

第三分钟一个人进入，给服务器发了一句hi，服务器给所有3个人发了hi

所以前三分钟总共有1+1+1+2+1+3=9句hi

## 题解

等差数列求和。

