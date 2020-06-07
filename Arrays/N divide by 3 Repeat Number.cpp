int Solution::repeatedNumber(const vector<int> &A) {
    
    if(A.size() == 0) {
        return -1;
    }
    if(A.size() <= 2) {
        return A[0];
    }
    
    int num1 = A[0],num2;
    int count1 = 0,count2 = 0;
    
    for(int i=0;i<A.size();i++) {
        
        if(num1 == A[i]) {
            count1++;
        }
        else if(count2 == 0) {
            num2 = A[i];
            count2 = 1;
        }
        else if(num2 == A[i]) {
            count2++;
        }
        else if(count1 == 0) {
            num1 = A[i];
            count1 = 1;
        }
        else {
            count1--;
            count2--;
        } 
    }
    
    int target = A.size()/3;
    
    count1 = count2 = 0;
    
    for(int i=0;i<A.size();i++) {
    	
        if(A[i] == num1) {
            count1++;
        }
        else if(A[i] == num2) {
            count2++;
        }
    }
    
    if(count1 > target) {
        return num1;
    }
    
    if(count2 > target) {
        return num2;
    }
    
    return -1;
}

