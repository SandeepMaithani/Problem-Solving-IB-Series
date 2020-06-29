int Solution::searchInsert(vector<int> &A, int B) {

    int answer = -1;

    int start = 0, end = A.size() - 1;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if (A[mid] == B) {
            answer = mid;
            end = mid - 1;
        }
        else if (A[mid] > B) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    if (answer == -1) {
        answer = start;
    }

    return answer;
}
