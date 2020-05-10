int Solution::isPower(int A) {
    
     if(A == 1) {
        return 1;
    }
    for(int i=2; i*i <= A;i++) {
        int logval = log(A)/log(i);
        
        if(pow(i,logval) == A) {
            return 1;
        }
    }
    
    return 0;
}
    
    
    
    
    /*
    
    Brute force approach O(sqrt(n)*n)
    
    if(A == 1) {
        return 1;
    }
    for(int i=2; i*i <= A;i++) {
        int j=2;
        while(pow(i,j)<= A) {
            if(pow(i,j) == A) {
                return 1;
            }
            j++;
        }
    }
    return 0;
    */


