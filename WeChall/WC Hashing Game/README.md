# WC Hashing Game

就是道爆破题，只要找对了词典就很轻松了。当然，dic自己找，我不给。

但是我一开始用Go写（自带md5和sha1而且跑得相对快）被array和slice坑死了。

WC4的`hashgame_wc4_salt`看着可怕，但是它最后把`$salt`明文嵌回字符串了，所以可以直接截取后四位作为`$salt`接着算。
