
int Solution::atoi(const string A) {
    if (A.length() == 0) {
        return 0;
    }

    int signcnt = 0;
    int negFlag = false;
    int i = 0;

    long result = 0;

    while (i < A.length() && A[i] == ' ') {
        i++;
    }

    while (i < A.length() && (A[i] == '+' || A[i] == '-')) {
        signcnt++;

        if (signcnt > 1) {
            return 0;
        }
        if (A[i] == '-') {
            negFlag = true;
        }

        i++;
    }

    while (i < A.length() && A[i] >= '0' && A[i] <= '9') {
        result = result * 10 + (A[i] - '0');

        if (negFlag && result > INT_MAX) {
            return INT_MIN;
        }
        else if (result > INT_MAX) {
            return INT_MAX;
        }

        i++;
    }

    if (negFlag) {
        result = -result;
    }

    return (int)result;
}
