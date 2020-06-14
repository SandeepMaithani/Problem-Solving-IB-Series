string Solution::countAndSay(int A) {

    string answer = "1";

    for (int i = 2; i <= A; i++) {
        string mid = "";
        int count = 1;
        for (int j = 0; answer[j]; j++) {
            if (j == answer.length() - 1) {
                mid = mid + to_string(count) + answer[j];
            }
            else if (answer[j] == answer[j + 1]) {
                count++;
            }
            else {
                mid = mid + to_string(count) + answer[j];
                count = 1;
            }
        }
        answer = mid;
    }
    return answer;
}
