int Solution::solve(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    for(int i=0;i<A.size();i++) {
        int check = A.size()- (upper_bound(A.begin(),A.end(),A[i]) - A.begin());
        
        if(check == A[i]) {
            return 1;
        }
    }
    
    return -1;
}

