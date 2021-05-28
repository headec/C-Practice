#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    vector<vector<int>> board = 
    {{0,0,0,0,0},
    {0,0,1,0,3},
    {0,2,5,0,1},
    {4,2,4,4,2},
    {3,5,1,3,1}
    };
    // board.push_back({0,0,0,0,0});
    // board.push_back({0,0,1,0,3});
    // board.push_back({0,2,5,0,1});
    // board.push_back({4,2,4,4,2});
    // board.push_back({3,5,1,3,1});
    cout<<"board: \n";
    for(int i = 0 ; i <board.size(); i++){
        for(int j = 0; j<board[i].size();j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    cout<<"moves: \n";
    vector<int> moves = {1,5,3,5,1,2,1,4}; //4,3,1,1,3,2,0,4
    for(int a : moves ) cout<< a << ' ';
    
    cout<<endl;
    
    stack<int> s; // 답에 들어가는 스택
 // s.push(0); //초기화
    cout<<"board.size() = " <<board.size()<<endl;
    int c,count = 0; // c = 벡터 row , count = 답
    for(int b : moves) {
        c = b-1; // index 로 사용하기 위해
        cout<<"moves 는 현재: "<<b<<"입니다\n";
        for(int i = 0; i<board.size();i++){ // 각 row 마다
            if(board[i][c]!=0){ // 0 이 아닌 값이
                if(!s.empty() && s.top()==board[i][c]) { // 정답 스택에 들어있는 값이면
                    cout<<"1점 획득 s.pop() = "<<s.top()<<endl;
                    board[i][c] = 0; // 빼주고
                    s.pop(); // 2개가 되므로 빼주고
                    count+=2;  // 2점 획득
                    break;
                    }
                else {
                    s.push(board[i][c]); // 아니면 정답 스택에 값 넣기
                    board[i][c] = 0; // 뺀 값은 0으로 초기화
                    cout<<"s.push() = "<<s.top()<<endl;
                    break;
                }
            }
            else cout<<"0 이 들어있습니다.";
            cout<<endl;
        }
    }
    cout<<"Return = "<<count<<endl;
}