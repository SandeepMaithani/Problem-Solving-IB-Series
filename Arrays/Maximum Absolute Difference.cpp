/*

idea here is to find max value from 2 cases

1. (A[i] + i) - (A[j] + j)
2, (A[i] - i) - (A[j] - j)


we get these equation from analysing 4 cases which are 

1. (A[i] > A[j]) and i > j
2. (A[i] > A[j]) and i < j
3. (A[i] < A[j]) and i > j
4. (A[i] < A[j]) and i < j
 
*/


int Solution::maxArr(vector<int> &A) {
    
    vector<int>indsum;
    vector<int>indiff;
   
   for(int i=0;i<A.size();i++) {
       indsum.push_back(A[i]+i);
       indiff.push_back(A[i]-i);
   }
   
   int ans1 = *max_element(indsum.begin(),indsum.end()) - (*min_element(indsum.begin(),indsum.end()));
   int ans2 = *max_element(indiff.begin(),indiff.end()) - (*min_element(indiff.begin(),indiff.end()));
   
    return max(ans1,ans2);
}

