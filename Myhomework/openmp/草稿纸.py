from collections import deque
from typing import List
st = '9'
# str = "abc123"
n=9
l = [[0,2,2],[4,2,4],[2,13,1000000000]]
# for i in l:
#     print(i)
# for i in str:
#     if i.isdigit() :
#         print( (int(i),i) )
#print( (int(st),str))
# i = 0
# while i < 3:
#     i = 4
#     print( (int(i),i) )
# t = Solution()
# print(t.decodeString("10[we]"))
dict = {n %3: 0}
degree = [i for i in range(8)]
dq = deque([1,2,3])

# print (2 in dict.keys())
f = open('log.txt','w')
for i in range(1,400*400+1,1):
    print(str(1),end= " ", file=f)
f.close()