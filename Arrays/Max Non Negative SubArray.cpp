vector<int> Solution::maxset(vector<int> &A) {
    
    vector<int>answer;
    
    int gstart = 0,gend = 0;
    long long int gsum = INT_MIN,lsum = 0;
    int lstart = 0;
    
    for(int i=0;i<A.size();i++) {
        lsum += A[i];
        
        if(gsum < lsum) {
            gsum = lsum;
            gstart = lstart;
            gend = i;
        }
        else if(gsum == lsum && i-lstart > gend - gstart) {
             gsum = lsum;
             gstart = lstart;
             gend = i;
        }
        
        if(A[i] < 0) {
            lsum = 0;
            lstart = i+1;
        }
        
    }
    
    for(int i=gstart;i<=gend && A[i] >= 0;i++) {
        answer.push_back(A[i]);
    }
    
    return answer;
}

