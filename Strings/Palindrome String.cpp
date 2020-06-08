int Solution::isPalindrome(string A) {
    string rev = "";
    
    for(int i=0;A[i];i++) {
        if(A[i] >= 'a' && A[i] <= 'z') {
            rev += A[i];
        }
        else if(A[i] >= 'A' && A[i] <= 'Z') {
            rev += (A[i]+32);
        }
        else if(A[i] >= 48 && A[i] <=57) {
            rev += A[i];
        }
    }
    
    int srt = 0,end = rev.length()-1;
    
    while(srt < end) {
        if(rev[srt] == rev[end]) {
            srt++;
            end--;
        }
        else {
            return 0;
        }
    }
    
    return 1;
}

