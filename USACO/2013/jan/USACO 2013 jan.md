Bronze
======
Problem 1: Mirrors
------------------
直接暴力枚举哪个镜子要转换，然后暴力计算能否到达即可。<br/>
时间复杂度为O(N^3)，貌似有好方法优化到O(N^2logN)。

Problem 2: Painting the Fence
--------------------
最直接的方法就是用线段树，不过貌似时间和空间都可能超。<br/>
考虑问题的特殊性，我们设sum(x)表示区间\[x, Inf)加的次数，然后对于每个线段\[a,b\]，我们只需要sum(a)++, sum(b)--。<br/>
最后依次枚举每个点，递推计算出每个点被加的次数，题目数据比较大，注意离散化。


Problem 3: Liars and Truth Tellers
------------------
赤裸裸的并查集，直接做就可以了

Silver
=======

Problem 1: Painting the Fence
----------------
和Bronze的一样，只不过限制条件修改了一下。

Problem 2: Square Overlap
-------------------
原问题可以转化为找到两个点(xi, yi) (xj, yj) (i≠j)满足|xi-xj|<=k-1 && |yi-yj|<=k-1.<br/>
然后扫描线算法就可以了。

Problem 3: Party Invitations
------------------
题目思路很清晰，用set, map, vector, queue各种乱搞就可以了

Gold
========
Problem 1: Cow Lineup
-----------
问题转化为找出最长的连续序列，使得这个连续序列中不同的数字不超过K+1，然后找到出现次数最多的数字。<br/>
用two pointers+堆优化就可以了。<br/>
稍微优化一下模型可以优化到O(N)

Problem 2: Island Travels
-----------
首先求出任意两个island之间的距离，接下来就是经典的TSP问题。

Problem 3: Seating
-----------
赤裸裸的线段树，貌似有累似的题目在POJ上。

