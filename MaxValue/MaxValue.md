Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the array element between two given indices, inclusive.  
Once all operations have been performed, return the maximum value in the array.  

### Constraints
3 <= n <= 10^7  (number of elements)  
1 <= m <= 2*10^5  (number of operations/queries)  
1 <= a <= b <= n  
0 <= k <= 10^9 (number to be added)  

### Sample Input
5 3  
1 2 100  
2 5 100  
3 4 100  

### Sample Output
200   

### Explanation
100 100   0   0   0  
100 200 100 100 100  
100 200 200 200 100  

### Source
The problem can be found at [HackerRank](https://www.hackerrank.com/challenges/crush/problem).