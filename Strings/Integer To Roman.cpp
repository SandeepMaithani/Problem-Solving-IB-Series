
string Solution::intToRoman(int A) {

	int numRep[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	string romanRep[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

	string output = "";

	for (int i = 0; A != 0 && i <= 12; i++) {
		while (A >= numRep[i]) {
			A = A - numRep[i];
			output += romanRep[i];
		}
	}
	return output;
}
