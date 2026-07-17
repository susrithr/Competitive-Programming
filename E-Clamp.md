Problem Statement

You are given an integer sequence 
A=(A 1,A 2,…,A N) of length N.
You are given Q queries, which you should process in order. Each query is in one of the following formats:
1 x y : Change the value of 
A 
x
​
  to 
y.
2 l r : Find the value of 
1≤i≤N
∑
​
 max(l,min(r,A 
i
​
 )).

 Constraints

1≤N≤5×10 
5
 
1≤Q≤2×10 
5
 
0≤A 
i
​
 ≤5×10 
5
 
For queries of the first type,
1≤x≤N
0≤y≤5×10 
5
 
For queries of the second type,
0≤l,r≤5×10 
5
 
All inputs are integers.
