void Solution::setZeroes(vector<vector<int>> &matrix) {

    bool frow = false, fcol = false;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {

            if (matrix[i][j] == 0 && i == 0) {
                frow = true;
            }

            if (matrix[i][j] == 0 && j == 0) {
                fcol = true;
            }

            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[i].size(); j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (frow) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[0][j] = 0;
        }
    }

    if (fcol) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][0] = 0;
        }
    }

}
