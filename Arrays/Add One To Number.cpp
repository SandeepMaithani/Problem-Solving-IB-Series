vector<int> Solution::plusOne(vector<int> &A) {
    
    int k = 1;
    
    while(A[0] == 0) {
        A.erase(A.begin());
        if(A.empty()) {
            A.push_back(k);
            return A;
        }
    }
    
    for(int i = A.size()-1;i >= 0;i--) {
        
        if(k == 0) {
            return A;
        }
        else {
            A[i] = A[i] + k;
             
             if(i == 0 && A[i] >= 10) {
                 k = A[i]/10;
                 A[i] = A[i]%10;
                 A.insert(A.begin(),k);
                 break;
             }
             else {
                 k = A[i]/10;
                 A[i] = A[i]%10;
             }
        }
        
    }
    
    return A;
}

