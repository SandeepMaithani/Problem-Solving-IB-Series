string Solution::solve(string A) {
    vector<string>rev;
    string word = "";
    string answer = "";  
    for(int i=0;A[i];i++) {
        if(A[i] != ' ') {
            word += A[i];
            if(i == A.length()-1) {
                rev.push_back(word);
            }
        }
        else {
            if(word.length() != 0) {
                rev.push_back(word);
            }
            word = "";
        }
    }
    
    for(int i=rev.size()-1;i>0;i--) {
        answer += rev[i];
        answer += " ";
    }
    
    answer = answer + rev[0];
    
    return answer;
}
