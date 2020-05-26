
//Method to find duplicates if read only array is given

/*

time complexity O(n) 
space complexity < O(n)

*/

int Solution::repeatedNumber(const vector<int> &A) {
   vector<bool>checker(A.size()+1);
   
   for(int i=0;i<A.size();i++) {
       if(checker[A[i]]) {
           return A[i];
       }
       else {
           checker[A[i]] = true;
       }
   }
   return -1;
}

//Method to find duplicates if normal array is given

/*

time complexity O(n) 
space complexity O(1)

*/

/*

int Solution::repeatedNumber(vector<int> &A) {
   
   for(int i=0;i<A.size();i++) {
       if(A[abs(A[i])] < 0) {
           return abs(A[i]);
       }
       else {
           A[A[i]] = -A[A[i]];
       }
   }
   return -1;
}

*/
