# HOST me

试着直接改了Host项，但是请求被vhost拦了下来。

我一开始的想法是多条Host，如果服务器看的Host和PHP看的Host不是同一条就可以绕过那个名字叫localhost的vhost，不过没有用。

试了各种姿势

查了别人的题解得知HTTP请求的`GET`后面可以接绝对路径，自己还试验了一下，感觉非常兴奋，仿佛发现新大陆。一开始去查阅HTTP 1.1协议（RFC 2616）并没有发现相关信息。

后来在Wooyun的知识库里发现了[一篇文章](http://drops.wooyun.org/papers/1383)，0x03的最后部分，0x04的上面一点发现了这么一句：

> 但是在RFC2616文档中规定了，如果请求URI是一个绝对的URI，那么host是Request-URI的一部分。在请求中的任何Host header值必须被忽略。
> 也就是说，在Apache和Nginx（只要是遵守此文档的webserver）中，可以通过绝对uri向任意应用发送一个包含有任意host header的请求：

不过我还是没发现什么相关的信息。我还是先记住吧。
