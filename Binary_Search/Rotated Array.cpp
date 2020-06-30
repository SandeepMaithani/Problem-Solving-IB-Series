int Solution::findMin(const vector<int> &nums) {

    int n = nums.size();
    int start = 0, answer = INT_MAX;
    int end = n - 1;

    if (nums[start] < nums[end] || start == end) {
        return nums[start];

    }

    while (start <= end) {

        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if (nums[mid] < nums[next] && nums[mid] < nums[prev]) {
            return nums[mid];

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
