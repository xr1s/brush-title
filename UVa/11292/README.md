# Dragon of Loowater

恶龙有n个头，每个头的直径为di的头，王国里有m个身高为hi的骑士，一个身高为hi的骑士能砍掉直径小于等于hi的头。问如何雇佣骑士能砍掉所有恶龙的头且使得身高总和最小。

很明显贪心就好了，只需要雇佣比恶龙头直径大的最矮的那个骑士就可以砍掉它的头，就没必要雇佣更高的。所以排序一下，枚举恶龙头的时候往后找更高的骑士，骑士找完了就卢滑铁，头枚举完就胜利。