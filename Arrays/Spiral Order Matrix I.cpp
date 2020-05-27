vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int>result;
    int l = 0,t = 0,dir = 0;
    int b = A.size() - 1;
    int r = A[A.size()-1].size() - 1;
    
    while(l <= r && t <= b) {
        if(dir == 0) {
            for( int i = l;i <= r; i++) {
                result.push_back(A[t][i]);
            }
            t++;
        }
        if(dir == 1) {
            for( int i = t; i <= b; i++) {
                result.push_back(A[i][r]);
            }
            r--;
        }
        if(dir == 2) {
            for( int i = r; i >= l; i--) {
                result.push_back(A[b][i]);
            }
            b--;
        }
        if(dir == 3) {
            for( int i = b; i >= t; i--) {
                result.push_back(A[i][l]);
            }
            l++;
        }
        dir = (dir + 1)%4;
    }
    return result;
}

