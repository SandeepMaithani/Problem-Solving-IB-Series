int Solution::pow(int x, int n, int d) {

    if (x == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }

    long long int answer ;

    if (n % 2 == 0) {
        answer = pow(x, n / 2, d);
        answer = ((answer % d) * (answer % d)) % d;
    }
    else {
        answer = (x % d);
        answer = (answer * (pow(x, n - 1, d) % d) % d);
    }
    return (answer + d) % d;

}
