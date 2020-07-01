int bsearch(const vector<int>& nums, int target, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return -1;
}

int getind(const vector<int>& nums, int start, int end) {
    int answer = -1;
    int n = nums.size();
    while (start <= end) {
        int mid = start + (end - start) / 2 ;

        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if (nums[mid] < nums[prev] && nums[mid] < nums[next]) {
            answer = mid;
            break;
        }
        else if (nums[mid] < nums[end]) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return answer;
}

int Solution::search(const vector<int> &nums, int target) {
    if (nums.size() == 0) {
        return -1;
    }

    if (nums.size() == 1) {
        if (nums[0] == target) {
            return 0;
        }
        else {
            return -1;
        }
    }

    int answer;
    int minind = getind(nums, 0, nums.size() - 1);

    if (nums[minind] == target) {
        answer = minind;
    }
    else {

        int lt = bsearch(nums, target, 0, minind - 1);
        int rt = bsearch(nums, target, minind + 1, nums.size() - 1);

        if (lt == -1 && rt == -1) {
            answer = -1;
        }
        else if (lt == -1) {
            answer = rt;
        }
        else {
            answer = lt;
        }
    }
    return answer;
}
