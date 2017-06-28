# Repeating History

This challenge is about researching the [WeChall challenges](https://www.wechall.net/challenge/) and the [GWF3 codebase](https://github.com/gizmore/gwf3).

I have put 2 passwords somewhere, but ....

where the hack did I put them?!

The first password is obvious and the second is very subversive. Both are near. Combine them without any separator.

Good luck on your research!

space and gizmore

Greets to kwisatz. Thank you for motivation :)

## 翻译

题目把答案放在了上述两个链接中，一个是网站的目录结构，一个是寄存在github的源码（看了一下github的commit信息，似乎以前不是在github上），请找到它。

## 解题报告

去challenges里，找到了本题的文件夹，同一个目录下还有个文件夹和一个php，分别戳进去看了一下，real\_solution.php里什么都没有，repeating文件夹里有一个what\_do\_you\_want\_here.php，戳进去看了一下，只有一行字。

> Oh right... the solution to part one is '' without the PHP comments and singlequotes.

看了一下页面源码，啥都没有，大概是真的需要PHP源码了，于是去第二个链接给出了源码里搜了一下原文就拿到了第一小关题解。

在进了history文件夹就是题目，在第二个链接里看了一下有个install.php，里面有一行给`$solution`变量赋值，虽然不知道是不是答案，不过试着提交一下。

果断失败。抱着试一试的心态拿去给md5解码，解出来是“wrong"（我不会告诉你我拿着wrong又提交了一次的）

去原题试图打开install.php，没用，总是提示没有登录。

去看了一下installChallege的源码，从逻辑上感觉`$solution`就应该是题解，于是猜测在历史代码里的`$solution`是正确的。因为不知道怎么在github上某个文件的历史commit记录，直接把整个源码仓库拷贝了下来。`git log filename`查看某个文件的修改记录，`git diff commit-id -- filename`查看修改记录。得到题解。

