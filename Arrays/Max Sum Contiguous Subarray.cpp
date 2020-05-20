int Solution::maxSubArray(const vector<int> &A) {
    int globalmax = INT_MIN,localmax = 0;
    int start = 0,end = 0,nsrt = 0;
    
    for(int i=0;i<A.size();i++) {
        localmax += A[i];
        
        if(globalmax < localmax) {
            globalmax = localmax;
            start = nsrt;
            end = i;
        }
        if(localmax < 0) {
            localmax = 0;
            nsrt = i+1;
        }
    }
    return globalmax;
}

