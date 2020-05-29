// Method 1 --> O(N) time and O(1) space

/*
we will use equation to find missing and repeated numbers 

arr = [w,y,y,z]  then  

sum = w+y+y+z  and totsum = w+x+y+z
sqsum = w^2 + y^2 + y^2 + z^2   and   totsqsum = w^2 + x^2 + y^2 + z^2

eq1 = totsum - sum = x-y
eq2 = totsqsum - sqsum = x^2 - y^2 = (x-y)*(x+y)
eq3 = eq2/eq1 = x+y

miss = (eq1 + eq3)/2 = 2*x/2 = x
rpt = eq3 - miss = x+y-x = y

so we got missing and repeated no using above equations


*/
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    if(A.size() == 0) {
        return A;
    }
    
    long long int n = A.size();
   
    vector<int>answer;
    
    long long int sum = 0;
    long long int sqsum = 0;
    int rpt,miss;
    
    for(int i=0;i<A.size();i++) {
        sum += A[i];
        sqsum += (long long int)A[i]*A[i];
    }
    
    
    long long int totsum = (n*(n+1))/2;
    long long int totsqsum = (n*(n+1)*((2*n)+1))/6;
    
    long long int eq1 = totsum - sum;
    long long int eq2 = totsqsum - sqsum;
    long long int eq3 = eq2/eq1;
    
    miss = (eq1 + eq3)/2;
    rpt = eq3 - miss;
    
    answer.push_back(rpt);
    answer.push_back(miss);
    
    return answer;
}

// Method 2 --> O(N) time and less then O(n) space

/*
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    if(A.size() == 0) {
        return A;
    }
    
    long long int n = A.size();
    vector<bool>check(n,false);
    vector<int>answer;
    
    long long int sum = 0;
    int rpt,miss;
    
    for(int i=0;i<A.size();i++) {
        sum += A[i];
        
        if(check[A[i]] != false) {
            rpt = A[i];
        }
        else {
            check[A[i]] = true;
        }
    }
    
    long long int totsum = (n*(n+1))/2;
    miss = totsum -(sum-rpt);
    
    answer.push_back(rpt);
    answer.push_back(miss);
    
    return answer;
}

*/

