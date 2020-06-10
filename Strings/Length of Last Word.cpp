int Solution::lengthOfLastWord(const string A) {
    int i=0,length = 0;
    int j= A.length()-1;
    
    while(A[j] == ' ') {
        j--;
    }
    
    while(A[i] && i<=j) {
        if(A[i] == ' ') {
            length = 0;
        }
        else {
            length++;
        }
        i++;
    }
    return length;
}

