typedef long long int lli;
#define mod 1000000007

lli power(lli a,lli b) {
    if(a == 0) {
        return 0;
    }
    if(b == 0) {
        return 1;
    }
    
    lli temp;
    
    if(b%2 == 0) {
        temp = power(a,b/2);
        temp = (temp*temp)%mod;
    }
    else {
        temp = ((a%mod)* power(a,b-1)%mod)%mod;
    }
    
    return (temp%mod);
}

int Solution::solve(int A, vector<int> &B) {
    
    vector<int>chunks;
    vector<lli>fact(A+1);
    
    sort(B.begin(),B.end());
    
    lli numtr = 0, dmtr = 1,answer;
    
    fact[0] = 1;
    
    for(lli i=1;i<=A;i++) {
        fact[i] = (fact[i-1]%mod * (i%mod))%mod;
    }
    
    chunks.push_back(B[0]-1);
    
    for(int i=1;i<B.size();i++) {
        chunks.push_back(B[i]-B[i-1]-1);
    }
    
    chunks.push_back(A-B[B.size()-1]);
    
    for(int i=0;i<chunks.size();i++) {
        numtr = numtr + chunks[i];
        dmtr = ((dmtr%mod)*(fact[chunks[i]]%mod))%mod;
    }
    
    numtr = fact[numtr];
    
    answer = ((numtr%mod)*power(dmtr,mod-2)%mod)%mod;
    
    for(int i=1;i<chunks.size()-1;i++) {
        if(chunks[i] > 0) {
            answer = ((answer%mod)*(power(2,chunks[i]-1)%mod))%mod;
        }
    }
    
    return (int)answer;
    
}

