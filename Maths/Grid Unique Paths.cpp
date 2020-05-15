//Method 1
//Combinatorics solution complexity O(max(A,B))

/*

Explaination

for 3*3 we will have something like "RRDD" we can see no 'R' and 'D' of
will always be fixed which can be arranged in as 

[4!/(2!*2!)] ways where 'R' and 'D' are repeated twice

or

{[((A-1)+(B-1))!]/[(A-1)! * (B-1)!]} == (A+B-2)C(A-1)

*/

int comb(int n,int k) {
    long long res = 1;
    
    if(k > n-k) {
        k = n-k;
    }
    
    for(int i=0;i<k;i++) {
        res *= n-i;
        res /= i+1;
    }
    
    return (int)res;
}

int Solution::uniquePaths(int A, int B) {
    
    int answer = 1;
    
    if(A == 1 || B == 1) {
        return answer;
    }
    else {
        answer = comb(A+B-2,A-1);
    }
    
    return answer;
    
}

//Method 2
// DP solution complexity O(A*B)

/*

{
   
    int dp[A][B];
    
    for(int i=0;i<A;i++) {
        dp[i][0] = 1;
    }
    
    for(int j=0;j<B;j++) {
        dp[0][j] = 1;
    }
    
    for(int i=1;i<A;i++) {
        for(int j=1;j<B;j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return(dp[A-1][B-1]);
}

*/

//Method 3
//recursion solution complexity O(2^N)

/*

int Solution::uniquePaths(int A, int B) {
    if(A == 1 || B == 1) {
        return 1;
        
    }
    return (uniquePaths(A-1,B) + uniquePaths(A,B-1));
    
}

*/

