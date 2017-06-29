# Training: Net Ports

题目说是remote-port，结果我还真的去访问了wechall.net的42端口。

好吧，得知是对于wechall来说的remote，也就是我们本地的42端口发送请求。

生活在NAT里的无奈，我们需要一个有root权限的反代或者公网IP才行。一开始试了两三次失败，后来才意识到这个问题。

直接用curl就可以做到，`curl --local-port`
