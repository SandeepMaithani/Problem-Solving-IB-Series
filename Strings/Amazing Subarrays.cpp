int Solution::solve(string A) {
    int n = A.length();
    int count = 0;
    
    for(int i=0;A[i];i++) {
        if(A[i] == 'A' || A[i] == 'a'|| A[i] == 'e' || A[i] == 'E'|| A[i] == 'i' || A[i] == 'I'|| A[i] == 'o' || A[i] == 'O'|| A[i] == 'u' || A[i] == 'U'){
            count += n-i;
        }
    }
    
    return count%10003;
}

