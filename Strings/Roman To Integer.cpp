
int Solution::romanToInt(string A) {
    unordered_map<char, int>hashmap {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int answer = 0;

    if (A.length() == 0) {
        return 0;
    }

    for (int i = 0; i < A.length() - 1; i++) {
        if (hashmap[A[i]] < hashmap[A[i + 1]]) {
            answer -= hashmap[A[i]];
        }
        else {
            answer += hashmap[A[i]];
        }
    }

    return answer + hashmap[A[A.length() - 1]];
}
