bool isprime(int x) {
    if(x == 2 || x == 3) {
        return true;
    }
    
    if(x%2 == 0 || x%3 == 0) {
        return false;
    }
    else {
        for(int i = 4 ; i*i <= x;i++) {
            if(x%i == 0) {
                return false;
            }
        }
    }
    return true;
    
}


vector<int> Solution::primesum(int A) {
    
    vector<int>answer;
    
    for(int i = 2;i<A;i++) {
        if(isprime(i) && isprime(A-i)) {
            answer.push_back(i);
            answer.push_back(A-i);
            break;
        }
    }
    
    return answer;
}

