#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
    int mat[9][9] = {0};
    struct cord{
        int x;
        int y;
    };
    string EightQueens(vector<cord>);
    bool isculprit(cord);
    int main(){
        vector <cord> que ;   
        string input;
        int i = 0,j = 0;
        char comma;
        for (size_t n = 0; n < 8; n++){
            cin >> input;
            stringstream(input)>>i>>comma>>j;
            mat[i][j] = 1;
            que.push_back(cord());
            que[n].x=i;que[n].y=j;
            // cout<<i<<endl<<j<<endl<<comma<<endl;
        }
        cout<<EightQueens(que);

        return 0;
    }

    string EightQueens(vector <cord> A){
        string culprit = "true";
        for(auto i = A.begin(); i<A.end(); i++){
            // cout<<(*i).x<<"-"<<(*i).y<<endl;
            if(isculprit(*i)){
                        culprit.clear();
                        culprit.push_back('(');
                        culprit.push_back('1'+(*i).x-1);
                        culprit.push_back(',');
                        culprit.push_back('1'+(*i).y-1);
                        culprit.push_back(')');
                        // cout<<"**-+";
                        return culprit;
            }
            // else 
            //     continue;
        }
        // cout<<"**"; 
        return culprit;
    }

bool isculprit(cord pt){
    int row = pt.x;
    int col = pt.y;
    int sum = 0;
    bool truth = true;
    for(int j = 1; j<=8; j++){
        if (j==col)continue;
        if(mat[row][j]) {return true; }
    }

    for(int i =1; i<=8; i++){
        if(i==row)continue;
        if(mat[i][col]) {return true; }
        sum = row+col;
    if(sum > 9){
        for(int i = 8,j= sum - 8; i>=1 && j<=8; i--,j++){
            if((i == row)&&(j==col))continue;
            if(mat[i][j]){ return true;  }
        }
    }
    else{
        for(int i= sum-1,j=1; i>=1 && j<=8; i--,j++){
            if( (i == row)&&(j == col) )continue;
            if(mat[i][j]){return true;  } 
        }
    }
    
    }

    for(int i = row,j=col; i>=1 && j>=1; i--,j--){
        if((i == row)&&(j==col))continue;
        if(mat[i][j]){ return true;  } 
    }

     for(int i = row,j=col; i<=8 && j<=8; i++,j++){
        if((i == row)&&(j==col))continue;
        if(mat[i][j]){ return true;  } 
    }
    
    return false;
}