int Solution::reverse(int A) {
    
    int reverse = 0;
    
    while(A != 0) {
        int digit = A%10;
        int temp = digit + reverse*10;
        A = A/10;
        
        if(temp/10 != reverse) {
            return 0;
        }
        
        reverse = temp;
        
    }
    
    return reverse;
}

