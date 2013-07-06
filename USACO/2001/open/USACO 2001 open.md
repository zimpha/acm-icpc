Green
=====

PROBLEM 1: Cow Relays
--------------
这道题目本质上就是要求我们求出从1到n的k短路。<br/>
求k短路的算法在David·Eppstein的《Finding the K Shortest Paths》有十分详细的讲解，有兴趣可以去看一下。<br/>
考虑一个非常相似的问题：在边权为正的图中求从一个给定顶点出发的前k短路径。我们简单地可以使用宽度优先搜索解决这个问题：维护一个路径长度的优先队列，每次从优先队列中取出长度最短的一条路径，把它删除并加入由这条路径和该路径终点的每条出边分别组成的所有路径，直到得到前k条路径。如果图的度为d，那么时间复杂度不会超过O(kd+klgk)。<br/>
我们可以套用求从一个给定顶点出发的前k短路径的算法来解决这个问题，但需要把结束条件改成得到前k条从1到达n的路径。由于在边权为正的图中，从1到达每个点的路径最多有k条可能成为从1到n的前k短路径的子路径，所以拓展的总路径数最多为kn条。时间复杂度为O(km+knlg(kn))。<br/>

PROBLEM 2: Earthquake
-------------
求最优比率生成树。<br/>
设λ=(F-Σc)/(Σt)，变换一下F=λ(Σt)+Σc，然后我们可以二分λ，反正当λ(Σt)+Σc=F时的λ是最优值。

PROBLEM 3: Cow Sorting
--------------

PROBLEM 4: Cow Signs
--------------

PROBLEM 5: Trapped in the Well
---------------

动态规划，设dp\[i\]\[j\]表示当前高度为i，生命值为j是否可以达到。<br/>
如果dp\[i\]\[j\]可达，那么dp\[i+garb\[k\].H\]\[j\], dp\[i\]\[j+garb\[k\].F\]同样可达。<br/>
首先将所有垃圾按照时间顺序排序，然后按照时间顺序进行dp，如果这时dp\[D\]\[j\]存在，那么最优值就是当前时间。<br/>
对于不能出去的情况，我们之举找到最大的T使得dp[0][T]存在。

Orange
========

PROBLEM 6:  Triangular Design
--------------

直接按题意输出即可。

PROBLEM 7: Sum to N
----------------

暴力枚举每个位置的符号，然后计算。一个小优化就是枚举一半。

PROBLEM 8: Combinations
------------------

设C1=a, 长度为b，然后M=b*(a+a+b-1)/2，于是2M=b*(2a+b-1)。可以看出b不超过sqrt(2M)，我们枚举b然后计算出a就可以了

PROBLEM 9: Picky
---------------

贪心的做法。我们将序列排序，然后得到三段A,B,C，设diff\[i\]\[j\]表示在i段，j的个数，然后答案就是
		int ret=0, tmp;
		for (int i=0; i<3; i++)
			for (int j=i+1; j<3; j++)
			{
				tmp=min(diff[i][j], diff[j][i]);
				ret+=tmp;
				diff[i][j]-=tmp; diff[j][i]-=tmp;
			}
		tmp=0;
		for (int i=0; i<3; i++)
			for (int j=i+1; j<3; j++)
				tmp+=diff[i][j]+diff[j][i];
		ret+=2*tmp/3;

PROBLEM 10: Number Bases
--------------------

暴力枚举。


