/*

dry run of solution on a sample case : A = [3, 5, 4, 2]

gtr_arr = [5, 5, 4, 2]
lsr_arr = [3, 3, 3, 2]
 
pair we get (3,5), (3,5), (3,4), (2,2)
answer = max val of j-i of all these pair which is 2 here

*/


int Solution::maximumGap(const vector<int> &A) {
    vector<int> gtr_arr(A.size());
    vector<int> lsr_arr(A.size());
    
    int n = A.size();
    
    if(n == 0) {
        return -1;
    }
    else if(n == 1) {
        return 0;
    }
    
    gtr_arr[n-1] = A[n-1];
    
    for(int i= n-2;i>=0;i--) {
        gtr_arr[i] = max(A[i],gtr_arr[i+1]);
    }
    
    lsr_arr[0] = A[0];
    
    for(int i=1;i<n;i++) {
        lsr_arr[i] = min(A[i],lsr_arr[i-1]);
    }
    
    int i=0,j=0,answer = INT_MIN;
    
    while(i<n && j<n) {
        if(lsr_arr[i] <= gtr_arr[j]) {
            answer = max(answer,j-i);
            j++;
        }
        else {
            i++;
        }
    }
    
    return answer;
}

