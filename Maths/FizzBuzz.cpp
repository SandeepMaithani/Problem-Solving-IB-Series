vector<string> Solution::fizzBuzz(int A) {
    vector<string>answer;
    
    for(int i=1;i<=A;i++) {
        if(i%3 == 0 && i%5 == 0) {
            answer.push_back("FizzBuzz");
        }
        else if(i%3 == 0) {
            answer.push_back("Fizz");
        }
        else if(i%5 == 0) {
            answer.push_back("Buzz");
        }
        else {
            answer.push_back(to_string(i));
        }
    }
    return answer;
}

