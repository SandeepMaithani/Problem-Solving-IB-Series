string Solution::longestCommonPrefix(vector<string> &A) {
    
    int n = A.size();
    
    sort(A.begin(),A.end());
    string answer = "",small = A[0],longer = A[n-1];
    
    for(int i=0;small[i];i++) {
        if(small[i] == longer[i]) {
            answer += small[i]; 
        }
        else {
            break;
        }
    }
    
    return answer;
}

