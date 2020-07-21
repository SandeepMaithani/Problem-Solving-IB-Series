int start(const vector<int> &A, int B) {
    int answer = -1;
    int left = 0;
    int right = A.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (A[mid] == B) {
            answer = mid;
            right = mid - 1;
        }
        else if (A[mid] < B) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return answer;
}

int end(const vector<int> &A, int B) {
    int answer = -1;
    int left = 0;
    int right = A.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (A[mid] == B) {
            answer = mid;
            left = mid + 1;
        }
        else if (A[mid] < B) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return answer;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector<int>Answer;
    Answer.push_back(start(A, B));
    Answer.push_back(end(A, B));

    return Answer;
}
