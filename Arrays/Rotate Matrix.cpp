void Solution::rotate(vector<vector<int> > &A) {

    int n = A.size();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }

    for (int i = 0; i < n; i++) {

        int fptr = 0, sptr = n - 1;

        while (fptr < sptr) {

            int temp = A[i][fptr];
            A[i][fptr] = A[i][sptr];
            A[i][sptr] = temp;

            fptr++;
            sptr--;
        }
    }
}
