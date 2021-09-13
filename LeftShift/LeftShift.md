Given an integer d, which is the number of steps.  
Shift all the elements of the array to the left.  
The shifting is 1 unit for each step.  

### Constraints
1 <= n <= 10^5  
1 <= d <= n  
1 <= a[i] <= 10^6  

### Sample Input
5 4  
1 2 3 4 5  

### Sample Output
5 1 2 3 4  

### Explanation
1 2 3 4 5  
--> 2 3 4 5 1  
--> 3 4 5 1 2  
--> 4 5 1 2 3  
--> 5 1 2 3 4  

### Source
The problem can be found at [HackerRank](https://www.hackerrank.com/challenges/array-left-rotation/problem).