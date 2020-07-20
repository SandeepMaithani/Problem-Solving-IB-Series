/*

Method 1 :- Binary search

Time complexity : O(Log(m*n));

it is only applicable when : -

1. matrix is row wise and column wise sorted
2. The first integer of each row is greater than or equal to the last integer of the previous row.

*/

int Solution::searchMatrix(vector<vector<int> > &A, int B) {

    if (A.size() == 0) return false;

    int row = A.size();
    int col = A[0].size();

    int left = 0;
    int right = row * col - 1;

    int mid, mid_element;

    while (left <= right) {

        mid = left + (right - left) / 2;
        mid_element = A[mid / col][mid % col];

        if (mid_element == B) {
            return true;
        }
        else if (mid_element < B) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}


/*

Method 2 :- reducing searching area

Time complexity : O(N+M)

it is only applicable when :- matrix is row wise and column wise sorted

*/


int Solution::searchMatrix(vector<vector<int> > &A, int B) {

    if (A.size() == 0) return false;

    int row = 0;
    int col = A[0].size() - 1;

    while (row < A.size() && col >= 0) {
        int checker = A[row][col];

        if (checker == B) {
            return true;
        }
        else if (checker < B) {
            row++;
        }
        else {
            col--;
        }
    }

    return false;
}

