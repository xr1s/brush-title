# Help is needed for Dexter

给出一串数字，每次可以任意选择一些数字减去一个正整数，问最少几次可以把全部的减到0。

构造题，每次选择高的一半把他们截断到和另一半一样长，这样就少了一半，所以只需要log步就好了。