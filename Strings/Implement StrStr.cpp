//Brute Force solution
// Time Complexity O(m*n)

int Solution::strStr(const string A, const string B) {
    int ptlen = B.length();
    int stlen = A.length();

    if (ptlen == 0 || (ptlen == 0 && stlen == 0) || ptlen > stlen) {
        return -1;
    }
    else {
        for (int i = 0; i <= (stlen - ptlen); i++) {
            int ptr1 = i;
            int ptr2 = 0;

            while (ptr2 < ptlen) {
                if (A[ptr1] == B[ptr2]) {
                    ptr1++;
                    ptr2++;
                }
                else {
                    break;
                }
            }

            if (ptr2 == ptlen) {
                return i;
            }
        }
    }
    return -1;
}
