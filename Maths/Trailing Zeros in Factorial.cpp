int Solution::trailingZeroes(int A) {
    
    int count = 0;
    
    while(A != 0) {
        count = count + A/5;
        A = A/5;
    }
    
    return count;
}


/*

count the occurence of 5 as it contribute to zero and recursively divide by 5 as 25 contribute 5
2 times and 125 contribute 3 time so check for these also by recursive division.

*/
