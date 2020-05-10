int Solution::titleToNumber(string A) {
    
    int sum = 0;
    
    for(int i=0;A[i];i++) {
        
        sum = (26*sum)+(A[i]-'A'+1);
    }
    
    return sum;
}

/*

explaination 

eg :- ABA

iteration 1 

sum = 26*sum + (A-A+1)   -->  sum = 0 + 1 = 1

iteration 2

sum = 26*1 + (B-A+1)   --> sum = 26 + 2 = 28

iteration 3

sum = 26*28 + (A-A+1) --> sum = 728 + 1 = 729 

/*
