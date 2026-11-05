// Design N-Queens matrix having first Queen placed. Use backtracking to place remaining Queens to generate the final N-queen.

#include<iostream>
#include<vector>

using namespace std;

class NQ{
    int n,placeCol,placeRow;
    vector<vector<int>> solvedBoard;
    public:
    NQ(){
        this->n=4;
        this->placeCol=2;
        this->placeRow=1;
    }
    NQ(int n,int r,int c){
        this->n=n;
        this->placeRow=r;
        this->placeCol=c;
    }
    void change(int n,int r,int c){
        this->n=n;
        this->placeRow=r;
        this->placeCol=c;
    }

    void printBoard(vector<vector<int>>&board){
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j])cout<<"Q ";
                else cout<<". ";
            }
            cout<<endl;
        }
    }
    void printBoardDetails(){
        cout<<"Size of board : "<<n<<endl;
        cout<<"Placed row : "<<placeRow+1<<endl;
        cout<<"Placed column : "<<placeCol+1<<endl;
        vector<vector<int>> board(n,vector<int>(n,0));
        board[placeRow][placeCol]=1;
        printBoard(board);
    }
    
    vector<vector<int>> solvePlaced(int n,int row,int col){
        this->n=n;
        this->placeRow=row;
        this->placeCol=col;

        vector<vector<int>> board(n,vector<int>(n,0));
        board[row][col]=1;

        if(solveNQ(0,board)){
            printBoard(board);
        }else{
            cout<<"No solution exists"<<endl;
        }
        return board;
    }
    void solvePlaced(){
        solvePlaced(n,placeRow,placeCol);
    }

    bool solveNQ(int row,vector<vector<int>> &board){
        if(row>=n)return true;

        if(row==placeRow){
            if(solveNQ(row+1,board)){
                return true;
            }else{
                return false;
            }
        }

        for(int j=0;j<n;j++){
            if(isSafe(row,j,board)){
                board[row][j]=1;
                if(solveNQ(row+1,board)){
                    return true;
                }
                board[row][j]=0;
            }
        }
        return false;
    }
    bool isSafe(int row,int col,vector<vector<int>> &board){
        for(int i=0;i<n;i++) if(board[i][col])return false;
        for(int j=0;j<n;j++) if(board[row][j])return false;

        for(int i=row,j=col;i>=0&&j>=0;i--,j--) if(board[i][j])return false;
        for(int i=row,j=col;i<n&&j<n;i++,j++) if(board[i][j])return false;
        
        for(int i=row,j=col;i>=0&&j<n;i--,j++) if(board[i][j])return false;
        for(int i=row,j=col;i<n&&j>=0;i++,j--) if(board[i][j])return false;

        return true;
    }
};

int main(){
    NQ nq;
    nq.solvePlaced(4,0,1);


    int n,col,row;
    cout<<"Enter size of board : ";
    cin>>n;
    cout<<"Enter placed row : ";
    cin>>row;
    cout<<"Enter placed column : ";
    cin>>col;
    nq.change(n,row-1,col-1);


    string menu="1. Enter board details. \n2. Solve board. \n3. Show board details. \n4. Exit.";
    cout<<menu;

    while(true){
        int choice;
        cout<<endl<<"Enter choice : ";
        cin>>choice;
        if(choice==1){
            int n,col,row;
            cout<<"Enter size of board : ";
            cin>>n;
            cout<<"Enter placed row : ";
            cin>>row;
            cout<<"Enter placed column : ";
            cin>>col;
            nq.change(n,row-1,col-1);
            nq.solvePlaced();
        }else if(choice==2){
            nq.solvePlaced();
        }else if(choice==3){
            nq.printBoardDetails();
        }else if(choice==4){
            cout<<"Thank You !"<<endl;
            break;
        }else{
            cout<<"Invalid input !"<<endl;
        }
    }

    return 0;
}