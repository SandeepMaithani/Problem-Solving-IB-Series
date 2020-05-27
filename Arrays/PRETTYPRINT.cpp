/*

Print concentric rectangular pattern in a 2d matrix.
Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4

Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 



*/

vector<vector<int> > Solution::prettyPrint(int A) {
    int size = (2*A) - 1;
    int lt = 0,top = 0,dir = 0;
    int rt = size - 1;
    int bot = size - 1;
    
    vector<vector<int>>answer(size,vector<int>(size));
    int data = A;
    
    while(lt <= rt && top <= bot) {
        
        if(dir == 0) {
            for(int j = lt; j <= rt; j++) {
                answer[top][j] = data;
            }
            top++;
        }
        else if(dir == 1) {
            for(int i = top; i <= bot; i++) {
                answer[i][rt] = data;
            }
            rt--;
        }
        else if(dir == 2) {
            for(int j = rt; j >= lt ; j--) {
                answer[bot][j] = data;
            }
            bot--;
        }
        else if(dir == 3) {
            for(int i = bot; i >= top; i--) {
                answer[i][lt] = data;
            }
            lt++;
        }
        
        dir = (dir + 1)%4;
        
        if(dir == 0) {
            data = data - 1;
        }
    }
    return answer;
}

