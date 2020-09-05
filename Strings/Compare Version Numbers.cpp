int Solution::compareVersion(string A, string B) {

    unsigned long long int num1, num2;
    int i = 0, j = 0;

    while (i < A.length() || j < B.length()) {
        num1 = num2 = 0;

        while (i < A.length() && A[i] != '.') {
            num1 = num1 * 10 + (A[i] - '0');
            i++;
        }

        while (j < B.length() && B[j] != '.') {
            num2 = num2 * 10 + (B[j] - '0');
            j++;
        }

        if (num1 > num2) {
            return 1;
        }
        else if (num2 > num1) {
            return -1;
        }

        i++;
        j++;
    }

    return 0;
}
