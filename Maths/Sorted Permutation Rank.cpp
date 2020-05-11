#define mod 1000003

//Time complexity O(nlogn)

int Solution::findRank(string A) {
	
    int n = A.length();
    int answer = 0;
    
    vector<long long int>fact(n);
    set<char>hashset;
    set<char>::iterator lower;
    
    fact[0] = 1;
    
    for(int i=1;i<n;i++) {
        fact[i] = ((fact[i-1]%mod)*(i%mod))%mod;;
    }
    
    for(int i=0;A[i];i++) {
        hashset.insert(A[i]);
    }
    
    for(int i=0;A[i];i++) {
        
        int count = 0;
        lower = hashset.find(A[i]);
        
        count = distance(hashset.begin(), lower);
        hashset.erase(A[i]);
        
        answer = ((answer%mod) + ((count%mod) * (fact[n-i-1]%mod))%mod)%mod;
        
    }
    
    return (answer+1)%mod;
}


/*

//time complexity of this solution is O(n^2)

int Solution::findRank(string A) {
    int n = A.length();
    int answer = 0;
    vector<long long int>fact(n);
    fact[0] = 1;
    
    for(int i=1;i<n;i++) {
        fact[i] = ((fact[i-1]%mod)*(i%mod))%mod;;
    }
    
    for(int i=0;A[i];i++) {
        int count = 0;
        for(int j = i+1;A[j];j++) {
            if(A[i] > A[j]) {
                count++;
            }
        }
        
        answer = ((answer%mod) + ((count%mod) * (fact[n-i-1]%mod))%mod)%mod;
    }
    return (answer+1)%mod;
}


*/
