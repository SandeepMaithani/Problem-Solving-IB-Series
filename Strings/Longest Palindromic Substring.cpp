
void palinHelper(string &A, int left, int right, int &maxLen, int &start) {
    int tempLen = 0;

    while (left >= 0 && right < A.length() && A[left] == A[right]) {
        left--;
        right++;
    }

    tempLen = right - left - 1;

    if (tempLen > maxLen) {
        maxLen = tempLen;
        start = left + 1;
    }
}

string Solution::longestPalindrome(string A) {

    if (A.length() <= 1) {
        return A;
    }

    int maxLen = 1;
    int start = 0;

    for (int i = 0; i < A.length() - 1; i++) {
        palinHelper(A, i, i, maxLen, start);
        palinHelper(A, i, i + 1, maxLen, start);
    }

    return A.substr(start, maxLen);
}
