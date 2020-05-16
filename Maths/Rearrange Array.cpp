// Method 1
//Time complexity O(N) and space complexity O(1)


/*

Explaination here is we will store both no in same array at same index i.e both old and new value

eg :- suppose A[i] = 3 and A[A[i]] = 4 and size is 5 
        so A[i] become 3 + 4*5 = 23 so 23/5 = A[A[i]] = 4 and 23%5 = A[i] = 3  

we will modify each element as:-

 A[i] = A[i] + ((A[A[i]] % size)*size);
 
where new number can be obtain by divide new number by size and old number can be obtained by
taking modulo of size on new number   

note :- while using equation we use modulo to avoid using updated value while calculating value using eq

*/

void Solution::arrange(vector<int> &A) {
    
    int size = A.size();
    
    for(int i=0;i<A.size();i++) {
        A[i] = A[i] + ((A[A[i]] % size)*size);
    }
    
    for(int i = 0; i<A.size();i++) {
        A[i] = A[i]/size;
    }
    
}

// Method 2
//Time complexity O(N) and space complexity O(N)

/*
void Solution::arrange(vector<int> &A) {
    
    vector<int>solution(A.size());
    
    for(int i=0;i<A.size();i++) {
        solution[i] = A[A[i]];
    }
    
    A = solution;
}
*/
