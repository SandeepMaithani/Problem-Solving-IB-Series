vector<int>to_array(int c) {
    vector<int>num;
    
    while(c != 0) {
        int digit = c%10;
        num.insert(num.begin(),digit);
        c = c/10;
    }
    
    return num;
}

int Solution::solve(vector<int> &A, int B, int C) {
    
    vector<int>numarr = to_array(C);
    
    if(numarr.size() < B || C == 0 || A.size() == 0) {
        return 0;
    }
    else if(numarr.size() > B) {
        
        if(A[0] == 0 && B != 1) {
            return ((A.size()-1)*pow(A.size(),B-1));
        }
        else {
            return pow(A.size(),B);
        }
    }
    else {
        vector<int> lesser(11,0);
		
		int count1 = 0,count2 = 0; 
  
        for (int i = 0; i < A.size(); i++) 
            lesser[A[i] + 1] = 1; 
        for (int i = 1; i < lesser.size(); i++) 
            lesser[i] = lesser[i - 1] + lesser[i];
			
		if(A[0] == 0 && B != 1) {
			count1 = (lesser[numarr[0]]-1)*pow(A.size(),B-1);
		}
		else {
			count1 = (lesser[numarr[0]])*pow(A.size(),B-1);
		} 
		
		if(find(A.begin(),A.end(),numarr[0]) != A.end()) {
		    
		    int temp = 0;
		    
		    for(int i=1;i<numarr.size();i++) {
		        if(find(A.begin(),A.end(),numarr[i]) != A.end()) {
		            temp += lesser[numarr[i]]*pow(A.size(),B-i-1);
		        }
		        else {
		            temp += lesser[numarr[i]]*pow(A.size(),B-i-1);
		            break;
		        }
		    }
		    count2 =temp;
		}
		return(count1 + count2);
    }
}

