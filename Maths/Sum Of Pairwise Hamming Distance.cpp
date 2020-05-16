#define mod 1000000007

int Solution::hammingDistance(const vector<int> &A) {
    
    vector<int>bitval(32,0);
    int answer = 0;
    
    for(int i=0;i<A.size();i++) {
        int number = A[i];
        int index = 0;
        
        while(number) {
            
            bitval[index] += (number & 1);
            index++;
            number = number/2;
        }
    }
    
    for(int i=0;i<32;i++) {
        answer = (answer + 2*(bitval[i]*(A.size()-bitval[i])))%mod;
    }
    
    return answer;
}

