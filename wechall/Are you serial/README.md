# Are you serial

题目给出了几个源码文件，先看code.php。

在处理cookie的逻辑里，可以看到有个`unserialize-getCookie`，参数传递给`$user`。接下去看`$user`，有三个成员函数`->getUsername()`, `->getPassword()`, `->getUserLevel()`。

显然这个`$user`应当是一个SERIAL\_User.php里定义的`SERIAL_User`对象。在code.php里随意登录一下，检查一下cookie，多出了一项：（以下为urldecode后的结果）

```
serial_user=O:11:"SERIAL_User":3:{s:8:"username";s:4:"xris";s:8:"password";s:8:"testtest";s:9:"userlevel";i:0;}
```

把SERIAL\_User的定义扔到php shell里跑一下，再`print_r`一下`unserialize`的结果，就是这个类。

一开始试图改`userlevel`，不过改得超大依然没有什么用，于是又去看了一眼题目。

在SERIAL\_Solution.php这个文件里，定义了一个叫`SERIAL_Solution`的类，有一个方法叫`__wakeup`，如果调用了这个函数就解决了题目。双下划线，应该是魔术方法，所以去php官网查了一下文档。

> 与之相反，`unserialize()`会检查是否存在一个`__wakeup()`方法。如果存在，则会先调用`__wakeup`方法，预先准备对象需要的资源。

于是，之前提到，在code.php里有一个`unserialize`的调用，在这里将一个`SERIAL_solution`类`unserialize`即可，所以在本地构造一个`SERIAL_Solution`类，`serialize`之后在cookie里传回服务器即可。

