GREEN
=====

PROBLEM 1: Cow Dominoes
-------

挺简单的题目，将一块骨排的和求出来，排序之后高精度进位即可。

PROBLEM 2: Cow Plumbing
-------
0/1背包

PROBLEM 3: Dinner Time
-------

贪心。<br/>
记录每个数是否存在，以及每个数的位置；从头开始，判断此数是否已经有ans，若无，判断此数-1是否存在，若存在，记入ans，并把此数-1的ans设为此数（否则总会有较大的数得不到处理）；若不存在，记录此数本身；每次被记入ans的数，设置used为false

PROBLEM 4: Cowese
----------

先排序，然后暴力枚举，一个小优化是如果当前prefix小于最大值，那么下面可以不用枚举<br/>
标准解法貌似是字典树.


ORANGE
======

PROBLEM 5: Power
------

不说了

PROBLEM 6: Dictionary Numbers
-------

暴力做

PROBLEM 7: Hungry Cows
-------

按照区间排序，然后dp就可以了

PROBLEM 8: Cow Shuffle
------

直接暴力做，不过貌似有简单的方法：<br/>
“每个数都回到初始位置”与“一个数回到初始位置”等价，每次shuffle后的位置（ans）<br/>
		if(ans<=n) ans=ans*2-1;
		else ans=(ans-n)*2;

PROBLEM 9: Negative Powers
-------
暴力做
