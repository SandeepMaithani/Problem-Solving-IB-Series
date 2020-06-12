int Solution::sqrt(int x) {
    long long int l = 0,r = x,mid,answer;
    
    while(l<=r) {
        
        mid = (l+r)/2;
        
        if(mid*mid == x) {
            return mid;
        }
        else if(mid*mid < x) {
            l = mid + 1;
            answer = mid;
        }
        else {
            r = mid -1;
        }
    }
    
    return answer;
}

