int first(const vector<int> &vec, int target, int start, int end) {

	int answer = -1;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (vec[mid] == target) {
			answer = mid;
			end = mid - 1;
		}

		else if (vec[mid] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return answer;
}

int second(const vector<int> &vec, int target, int start, int end) {

	int answer = -1;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (vec[mid] == target) {
			answer = mid;
			start = mid + 1;
		}

		else if (vec[mid] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return answer;
}

int Solution::findCount(const vector<int> &A, int B) {

	int foccur = first(A, B, 0, A.size() - 1);
	int soccur = second(A, B, 0, A.size() - 1);

	int answer;

	if (soccur == -1 || foccur == -1) {
		answer = 0;
	}
	else {
		answer = soccur - foccur + 1;
	}

	return answer;
}
