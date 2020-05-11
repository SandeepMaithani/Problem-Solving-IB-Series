#define mod 1000003

long long int power(long long int A,long long int B) {
    if(A == 0) {
        return 0;
    }
    if(B == 0) {
        return 1;
    }
    
    long long int result ;
    
    if(B%2 == 0) {
        result = power(A,B/2);
        result = ((result%mod) * (result%mod))%mod;
    }
    else {
        result = ((A%mod)*(power(A,B-1)%mod))%mod;
    }
    
    return result;
}

int Solution::findRank(string A) {
    int n = A.length();
    int answer = 0;
    vector<long long int>fact(n);
    
    fact[0] = 1;
    
    for(int i=1;i<n;i++) {
        fact[i] = ((fact[i-1]%mod)*(i%mod))%mod;
    }
    
    for(int i=0;A[i];i++) {
        int countless = 0;
        int countsame = 0;
        
        for(int j = i+1;A[j];j++) {
            if(A[i] > A[j]) {
                countless++;
            }
        }
        
        map<char,int>hashmap;
        
        for(int j=i;A[j];j++) {
            hashmap[A[j]]++;
        }
        
        long long int d = 1;
        
        for(auto ch : hashmap) {
            d = ((d%mod)*(fact[ch.second]))%mod;
        }
        
        answer = ((answer%mod) + ((countless%mod)*(fact[n-i-1]%mod)*power(d,mod-2))%mod)%mod;
    }
    
    return ((answer + 1)%mod);
}

