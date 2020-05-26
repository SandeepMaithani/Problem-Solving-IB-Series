
//Method 1

/*

Time Complexity O(n)
Space Complexity O(1)

*/

vector<int> Solution::subUnsort(vector<int> &A) {
    
    int size = A.size();
    vector<int>answer;
    
    int start = 0,end = 0;
    int minm = INT_MAX,maxm = INT_MIN;
    
    for(int i=0;i<size-1;i++) {
        if(A[i] > A[i+1]) {
            minm = min(minm,A[i+1]);
        }
        
    }
    
    for(int i=size-1;i>0;i--) {
        if(A[i-1] > A[i]) {
            maxm = max(maxm,A[i-1]);
        }
    }
    
    for(int i=0;i<size;i++) {
        if(A[i] > minm) {
            start = i;
            break;
        }
    }
    
    for(int i=size-1;i>=0;i--) {
        if(maxm > A[i]) {
            end = i;
            break;
        }
    }
    
    if(start == end) {
        answer.push_back(-1);
    }
    else {
        answer.push_back(start);
        answer.push_back(end);
    }
    
    return answer;
    
}



//Method 2 

//time complexity O(nlogn) space complexity O(n)

/*

vector<int> Solution::subUnsort(vector<int> &A) {
    int start = 0,end = 0,answer;
        
    vector<int>dup(A);
    sort(dup.begin(),dup.end());
        
    for(int i=0;i<A.size();i++) {
        if(A[i] != dup[i]) {
            start = i;
            break;
        }
    }
        
    for(int i=A.size()-1;i>=start;i--) {
        if(A[i] != dup[i]) {
            end = i;
            break;
        }           
    }
    
    dup.clear();
        
    if(start == end) {
        dup.push_back(-1);
    }
    else {
        dup.push_back(start);
        dup.push_back(end);
    }
    
    return dup;
    
}

*/
