string Solution::convertToTitle(int A) {
    
    string answer = "";
    int ind;
    
   string map = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    while(A > 0) {
        A = A-1;
        ind = A%26;
        A = A/26;
        
        answer = map[ind] + answer;
    }
    
    return answer;
}

