string Solution::multiply(string num1, string num2) {
    int n = num1.length();
    int m = num2.length();

    vector<int>answer(n + m, 0);
    string solution = "";

    if (n == 0 || m == 0) {
        return solution;
    }

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {

            int fpos = m - i - 1;
            int spos = n - j - 1;

            int prod = (num2[i] - '0') * (num1[j] - '0');

            answer[fpos + spos] += prod;

            answer[fpos + spos + 1] += answer[fpos + spos] / 10;
            answer[fpos + spos] %= 10;

        }
    }

    while (!answer.empty() && !answer.back()) {
        answer.pop_back();
    }

    if (answer.size() == 0) {
        return "0";
    }
    else {
        for (auto ch : answer) {
            char temp = ch + '0';
            solution = temp + solution;
        }
    }

    return solution;
}
