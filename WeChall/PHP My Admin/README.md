# PHP My Admin

首先找到了一个\*.wechall.net/pma/的目录，提示不在当前子域名里。然后我试了很多比如说pma.wechall.net/pma/、db.wechall.net/pma、admin.wechall.net/pma/之类的，没有结果。

跑了一遍端口，0~65535都没有。

然后开始跑字典，跑完了也没跑出来……放弃治疗了。

后来某一天在hammer的帮助下知道了是在https://pma.wechall.net/下……而且还不能加pma这个目录。跪了。
