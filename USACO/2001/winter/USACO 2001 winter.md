Green
=====

PROBLEM 1: Counting Cows
-------------

PROBLEM 2: Herd Splitting
--------------
我的方法没有AC，过不了最后四组数据<br/>
我的方法是令dp\[i\]\[j\]\[k\]表示前i个数第一组为j第二组为k能否达到。然后普通的三维dp

PROBLEM 3: Treasure Hunting
------------
我们可以得到一个朴素的dp，设dp\[i\]\[j\]表示到位置i(位置i必须挖)，花费时间j的最大价值。然后dp\[i\]\[j\]=max{dp\[k\]\[j-dis\[i\]\[k\]-2*z\[i\]]}+V\[i\]，这样的话肯定会超时+超内存。<br/>
注意到时间肯定是离散分布的，于是我们可以通过离散化dp的第二维来解决这道题目，具体实现参考我的程序就可以了。

PROBLEM 4: Cow Pool
---------------
将图形分成上下两个矩形。对于上面部分，求出g\[i\]\[j\]\[k\]表示左下角为(i,j)右下角最大为(i,k)的最大矩形；对于下面部分，求出f\[i\]\[j\]\[k\]表示左上角为(i,j)右上角最大为(i,k)的最大矩形。最后枚举(i,j,k)取max{g\[i-1\]\[j\]\[k-1\]+f\[i\]\[j\]\[k\]};

PROBLEM 5: Cows In Bed [Burch, 2001]
对于这种题目我们能想到的方法就是枚举答案，然后判定。由于答案不具有单调性，我们不能通过二分答案来优化枚举时间，因此我们只能优化判定时间。
题目就是让我们找出一个K，使得∀i,j≤N,i≠j, Si≢Sj(mod K)。令diff\[x\]表示是否存在i和j使得abs(S\[i\]-S\[j\])=x。
然后ans满足条件等价于diff\[ans\]|diff\[2×ans\]|...|diff\[k×ans\]=false，其中k×ans<=max{S\[i\]}, (k+1)×ans>max{S\[i\]}.
这样对于每个ans，我们判定时间就只需要max{S\[i\]}/ans。于是总的时间复杂度为O(N^2+MlogM) M=max{S\[i\]}.

Orange
======

PROBLEM 6: Word Diamonds
-------

PROBLEM 7: Factorial Power
----------

PROBLEM 8: Sum25
-----------

PROBLEM 9: Mother's Milk
--------

PROBLEM 10: Cows In Bed
-----------

