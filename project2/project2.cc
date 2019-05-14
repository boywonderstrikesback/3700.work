#include "project2.h"
using namespace std;


int main(void){
    Read();
    Solve();

return 0;
};

void Read(){
cout << "Enter Numbers: " << endl;
    for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char input;
                cin >> input;
                if (input == '.') {
                board[i][j] = 0;
            } else {
                board[i][j] = (input - '0');
                board[i][j] = board[i][j] | FILL_MASK;
            }

        }
    }
};

void Solve(){
    uint8_t top;
    int i,j,computermove;
    findbest();

        while (true){
            top=computer.peek();
            i=top>>4;
            j=top&VALUE_MASK;
                computermove=validchoice(i,j);
            if(computermove==0){
                board[i][j]&= ~(FILL_MASK);
                computer.pop();
            if(computer.isEmpty()){
                print();
                return; 
            }
        continue;
        } else {
            board[i][j] &= ~(VALUE_MASK);
            board[i][j] |= (FILL_MASK);
            board[i][j] |= (computermove);
            board[i][j] &= ~(FILL_MASK << computermove);
        }
        if (!findbest()){
            break;
        }
    }
    print();
};

bool findbest(){
    int Low=10;
    uint8_t ibest, jbest, bestchoice;
    
for (int i = 0; i<9; i++){
    for (int j=0; j<9; j++){
            if (!(board[i][j] & FILL_MASK))
            board[i][j] |= VALID_MASK;
        }
    }
for (int i=0; i<9; i++){
    for(int j=0; j<9; j++){
        if (board[i][j] & FILL_MASK){
            for(int y=0; y<9; y++){
                if (!(board[i][y] & FILL_MASK))
                        board[i][y] &= ~(FILL_MASK << (board[i][j] & VALUE_MASK));
                    if (!(board[y][j] & FILL_MASK))
                        board[y][j] &= ~(FILL_MASK << (board[i][j] & VALUE_MASK));
                }
            invalidchoice(i, j);
         }
    }
}
for (int i=0; i<9; i++){
    for(int j=0; j<9;j++){
        if (!(board[i][j] & FILL_MASK)){
                 count = count(board[i][j]);
                if (count < Low){
                    Low = count;
                   ibest = i; jbest = j;
             }
        }
     }
}     
 if(Low==10)
    return false;
 board[ibest][jbest] |= FILL_MASK;
    bestchoice = ibest; bestchoice <<= 4;
    bestchoice |= jbest;
    computer.push(bestchoice); 
    return true;
};

int Count(int bit){
    while (int bit != 0){
       int count++;
        bit &= bit - 1;
    }
    return count;
};

void invalidchoice(int row, int col){
    int rowQ = row / 3;
    int colQ = col / 3; 
    
    for (int i = rowQ * 3; i < (3 * rowQ + 3); i++){
        for (int j = colQ * 3; j < (3 * colQ + 3); j++){
            if (!(board[i][j] & FILL_MASK)) {
                board[i][j] &= ~(FILL_MASK << (board[row][col] & VALUE_MASK));
            }
        }
    }
};

int validchoice(int i, int j){
    unsigned short int cell = board[i][j];
    
    for (int y = 1; y <= 9; y++)
        if ((FILL_MASK << y) & cell)
            return y;
    return 0;
};



void print(){
    cout << "Solution is: " << endl;
        for (int i = 0; i < 9; i++){
             for (int j = 0; j < 9; j++){
                unsigned short int output;
                output = (board[i][j] & VALUE_MASK);
                cout << output;
            }
                cout << endl;
    }
};