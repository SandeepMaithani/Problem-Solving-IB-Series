bool isPalin(string str) {
    int srt = 0;
    int end = str.length()-1;
    
    while(srt < end) {
        if(str[srt] != str[end]) {
            return false;
        }
        else {
            srt++;
            end--;
        }
    }
    return true;
}

int Solution::isPalindrome(int A) {
    
    if(isPalin(to_string(A))) {
        return 1;
    }
    return 0;
}

