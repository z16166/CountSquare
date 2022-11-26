# CountSquare
深度优先搜索，穷举如下问题：四根长度为3、两根长度为4、四根长度为7的木棍能围成多少种不同的矩形。无需每次用完所有木棍。

如果一个矩形经过一系列的如下操作，能得到另一个矩形，则认为这两个矩形相同（同构）：上下翻转、左右翻转、旋转、交换构成矩形的同一条边的几根木棍的顺序。

由于共有10根木棍，所以搜索的深度为10。每根木棍穷举其5种状态（0表示没用到这根木棍，1到4表示这根木棍属于矩形的第1到4条边）。穷举空间是5^10=9,765,625，不大，所以中间没有剪枝。

**解的消重方法：**

将构成矩形的4条边的所有木棍按长度递增排序，保证这个序列不重复即可。一条边的尾数和另一条边之间的首数之间要插入一个分隔符'-'。

先将矩形的4条边按边长递增排序，再将每条边内部的木棍按长度递增排序即可。

假定矩形的四条边依次为e1、e2、e3、e4，其中e1和e3是对边，e2和e4是对边。注意对边的长度相等。

一、如果矩形不是正方形，先将短的两条对边a、b排在前面，长的两条对边c、d在后。

a和b谁在前面，取决于a、b内的最短木棍、最长木棍的长度。也就是按a、b中的各个木棍在数轴上的左右顺序来决定a、b的前后顺序。

比较a、b的Compare()函数的逻辑如下：

1、如果a拥有a和b中最短的那个木棍，那么a在前。因为最短木棍在数轴最左侧。

2、如果a拥有a和b中最长的那个木棍，那么b在前。因为最长木棍在数轴最右侧。

3、如果a、b都拥有最短木棍、最长木棍，那么比较a、b各自拥有的的木棍个数。实际上就是比较a、b各自的单根木棍的平均长度，因为a、b的长度相等。

由于题目中的数字的特殊性，a、b的平均长度相等时，a、b包含的木棍集合也是相同的。代码中用断言验证了这点。

如果题目中的条件换成其他数字，并不一定能保证这点。

c和d谁在前，是类似的。

二、如果矩形是正方形，那么到底是a、b在前，还是c、d在前，直接比较a+b、c+d的单根木棍的平均长度，平均长度短的那组对边在前。

结果：

3 x 3
        sorted solution 1: 3-3-3-3
3 x 4
        sorted solution 2: 3-3-4-4
3 x 7
        sorted solution 3: 3-3-34-34
        sorted solution 4: 3-3-34-7
        sorted solution 5: 3-3-7-7
3 x 10
        sorted solution 6: 3-3-37-37
3 x 11
        sorted solution 7: 3-3-47-47
3 x 14
        sorted solution 8: 3-3-3344-77
        sorted solution 9: 3-3-347-347
        sorted solution 10: 3-3-347-77
        sorted solution 11: 3-3-77-77
3 x 17
        sorted solution 12: 3-3-377-377
3 x 18
        sorted solution 13: 3-3-477-477
3 x 21
        sorted solution 14: 3-3-33447-777
        sorted solution 15: 3-3-3477-3477
4 x 6
        sorted solution 16: 4-4-33-33
4 x 7
        sorted solution 17: 4-4-7-7
4 x 10
        sorted solution 18: 4-4-37-37
4 x 13
        sorted solution 19: 4-4-337-337
4 x 14
        sorted solution 20: 4-4-77-77
4 x 17
        sorted solution 21: 4-4-377-377
4 x 20
        sorted solution 22: 4-4-3377-3377
6 x 7
        sorted solution 23: 33-33-7-7
6 x 11
        sorted solution 24: 33-33-47-47
6 x 14
        sorted solution 25: 33-33-77-77
6 x 18
        sorted solution 26: 33-33-477-477
7 x 7
        sorted solution 27: 34-34-7-7
        sorted solution 28: 34-7-34-7
        sorted solution 29: 34-7-7-7
        sorted solution 30: 7-7-7-7
7 x 10
        sorted solution 31: 34-34-37-37
        sorted solution 32: 34-7-334-37
        sorted solution 33: 34-7-37-37
        sorted solution 34: 7-7-334-334
        sorted solution 35: 7-7-334-37
        sorted solution 36: 7-7-37-37
7 x 11
        sorted solution 37: 7-7-47-47
7 x 13
        sorted solution 38: 7-7-337-337
7 x 14
        sorted solution 39: 34-34-77-77
        sorted solution 40: 34-7-347-77
        sorted solution 41: 7-7-3344-77
        sorted solution 42: 7-7-347-347
7 x 17
        sorted solution 43: 34-34-377-377
        sorted solution 44: 34-7-3347-377
        sorted solution 45: 7-7-33344-377
        sorted solution 46: 7-7-3347-3347
10 x 10
        sorted solution 47: 37-37-37-37
10 x 11
        sorted solution 48: 37-37-47-47
10 x 14
        sorted solution 49: 334-334-77-77
        sorted solution 50: 334-37-347-77
        sorted solution 51: 37-37-3344-77
        sorted solution 52: 37-37-347-347
11 x 13
        sorted solution 53: 47-47-337-337
total solutions: 53

Execution time: 0.182 s
