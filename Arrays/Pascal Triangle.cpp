vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>>answer;
    if(A == 0)  {
        return answer;
    }
    
    vector<int>temp1;
    
    temp1.push_back(1);
    answer.push_back(temp1);
    
    if(A == 1) {
        return answer;
    }
    
    temp1.push_back(1);
    
    answer.push_back(temp1);
    
    for(int i = 2;i<A;i++) {
        vector<int>temp;
        temp.push_back(1);
        
        for(int j = 1;j<i;j++) {
            int x = answer[i-1][j-1] + answer[i-1][j];
            temp.push_back(x);
        }
        
        temp.push_back(1);
        answer.push_back(temp);
    }
    
    return answer;
}

