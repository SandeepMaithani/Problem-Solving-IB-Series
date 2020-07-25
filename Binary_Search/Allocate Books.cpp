/*

Method : Modified Binary Search( Divide and Conquor )              Verdict : Accepted

Complexity Analysis:

Time Complexity: O(N*Log(N)).

As Binary search function will take O(Log(N)) time and for each binary search iteration we are checking if it is a valid choice or not which take O(N) time so total it will take O(N*log(N)) time.

Space Complexity: O(1).

*/

bool isvalid(vector<int> &A, int B, long long int mid) {
    int count = 1;
    long long int sum = 0;

    for (int i = 0; i < A.size(); i++) {
        sum += A[i];

        if (sum > mid) {
            count++;
            sum = A[i];
        }

        if (count > B) {
            return false;
        }
    }

    return true;
}

int Solution::books(vector<int> &A, int B) {

    if (B > A.size()) {
        return -1;
    }

    long long int max = 0;
    int min = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
        max += A[i];
        if (A[i] > min) {
            min = A[i];
        }
    }

    int answer = -1;

    while (min <= max) {
        long long int mid = min + (max - min) / 2;

        if (isvalid(A, B, mid)) {
            answer = mid;
            max = mid - 1;
        }
        else {
            min = mid + 1;
        }
    }

    return answer;
}
