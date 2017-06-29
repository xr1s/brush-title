# Training: GPG

其实就是GPG教程。去网上搜了教程。

首先安装GPG，Ubuntu下是

```sh
apt install gnupg
```

第一次，先生成一个gpg key，跟着流程走即可。

```sh
gpg --gen-key
```

可以测试一下加密和解密

`--sign`表示签名，`--armor`表示输出ASCII字符，也就是base64编码。--recipient是签名者。

```sh
gpg --encrypt --armor --sign --recipient name file
gpg --decrypt file
```

生成完毕后导出公钥，传到Account Setting里。这里WeChall会给注册邮箱发送信息，是GPG加密过的信息。

复制下来用之前的命令解压即可。

然后戳链接，GPG就激活了。回到题目，发送邮件，同理解密后得到题解。
