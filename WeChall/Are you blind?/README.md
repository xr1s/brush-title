# Are you blind?

是瞎眼系列的最后一题了，也是基于Bool的注入，利用了数据库出错会显示Database error的特性，其实利用了一个神奇的特性，不过我还是不理解，至今存疑。

就是

```sql
SELECT 1 UNION SELECT IF(1,1,(SELECT 1 UNION SELECT 2));  # 不报错
SELECT 1 UNION SELECT IF(0,1,(SELECT 1 UNION SELECT 2));  # 会报错
```

这么个特性，但是让我不解的是

```sql
SELECT 1 UNION SELECT IF(1,1,(SELECT 1, 2));  # 会报错
SELECT 1 UNION SELECT IF(0,1,(SELECT 1, 2));  # 会报错
```

存疑。
