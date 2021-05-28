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
    
    stack<int> s; // �信 ���� ����
 // s.push(0); //�ʱ�ȭ
    cout<<"board.size() = " <<board.size()<<endl;
    int c,count = 0; // c = ���� row , count = ��
    for(int b : moves) {
        c = b-1; // index �� ����ϱ� ����
        cout<<"moves �� ����: "<<b<<"�Դϴ�\n";
        for(int i = 0; i<board.size();i++){ // �� row ����
            if(board[i][c]!=0){ // 0 �� �ƴ� ����
                if(!s.empty() && s.top()==board[i][c]) { // ���� ���ÿ� ����ִ� ���̸�
                    cout<<"1�� ȹ�� s.pop() = "<<s.top()<<endl;
                    board[i][c] = 0; // ���ְ�
                    s.pop(); // 2���� �ǹǷ� ���ְ�
                    count+=2;  // 2�� ȹ��
                    break;
                    }
                else {
                    s.push(board[i][c]); // �ƴϸ� ���� ���ÿ� �� �ֱ�
                    board[i][c] = 0; // �� ���� 0���� �ʱ�ȭ
                    cout<<"s.push() = "<<s.top()<<endl;
                    break;
                }
            }
            else cout<<"0 �� ����ֽ��ϴ�.";
            cout<<endl;
        }
    }
    cout<<"Return = "<<count<<endl;
}