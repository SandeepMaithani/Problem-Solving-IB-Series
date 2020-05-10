int Solution::gcd(int A, int B) {
    if(B == 0) {
        return A;
    }
    else if(A == 0) {
        return B;
    }
    
    return gcd(B,A%B);
}

/*

//using library function

return __gcd(A,B);

*/
