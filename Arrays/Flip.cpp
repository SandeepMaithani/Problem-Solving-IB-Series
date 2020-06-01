/*

here we are using Kadane's algorithm with sight modification we will add 1 to diff if we get 0 in string and subtract 1 
if we get 1 in array if at any point diff < 0 we will discard that subarray as it have more no of 1 which on fliping incerase
no of 0 so we will look for substring having most positive value of diff.

*/

vector<int> Solution::flip(string A) {
    
    int left = 0,start = 0,right = 0;
    int diff = 0,maxdiff = 0;
    
    vector<int>answer;
    
    for(int i=0;A[i];i++) {
        
        if(A[i] == '0') {
            diff += 1;
        }
        else {
            diff -= 1;
        }
        
        if(diff > maxdiff) {
            maxdiff = diff;
            start = left+1;
            right = i+1;
        }
        
        if(diff < 0) {
            diff = 0;
            left = i+1;
        }
    }
    
    if(right == 0) {
        return answer;
    }
    else {
        answer.push_back(start);
        answer.push_back(right);
    }
    
    return answer;
}

