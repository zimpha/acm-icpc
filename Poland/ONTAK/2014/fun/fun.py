#!/usr/bin/env python2
import string

print '#include <bits/stdc++.h>'
print 'using namespace std;'
print ''
print 'int a[70][70]={'

for i in range(0, 70):
    s = ''
    for j in range(0, i + 1):
        x,y=map(int,raw_input().split())
        y %= 1000000007
        s = s + repr(y) + ','
    for j in range(i + 1, 70):
        s = s + '0,'
    print s
print '};'
