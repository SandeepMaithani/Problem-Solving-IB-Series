int prefixSub(string &str) {
    int len = 0;
    int i = 1;

    vector<int>lenKeeper(str.length());

    lenKeeper[0] = 0;

    while (i < str.length()) {
        if (str[i] == str[len]) {
            lenKeeper[i] = len + 1;
            len++;
            i++;
        }
        else {
            if (len == 0) {
                lenKeeper[i] = 0;
                i++;
            }
            else {
                len = lenKeeper[len - 1];
            }
        }
    }

    return lenKeeper[lenKeeper.size() - 1];
}

int Solution::solve(string s) {

    if (s.length() <= 1) {
        return 0;
    }

    string rev(s);
    reverse(rev.begin(), rev.end());

    string temp = s + "$" + rev;

    int len = prefixSub(temp);

    return rev.length() - len;
}
