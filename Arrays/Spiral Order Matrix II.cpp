vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>>result(A,vector<int>(A));
    int l = 0,t = 0,dir = 0;
    int b = A - 1;
    int r = A - 1;
    int num = 1;
    
    while(l <= r && t <= b) {
        if(dir == 0) {
            for( int i = l;i <= r; i++) {
                result[t][i] = num;
                num++;
            }
            t++;
        }
        if(dir == 1) {
            for( int i = t; i <= b; i++) {
                result[i][r] = num;
                num++;
            }
            r--;
        }
        if(dir == 2) {
            for( int i = r; i >= l; i--) {
                result[b][i] = num;
                num++;
            }
            b--;
        }
        if(dir == 3) {
            for( int i = b; i >= t; i--) {
                result[i][l] = num;
                num++;
            }
            l++;
        }
        dir = (dir + 1)%4;
    }
    return result;
}

