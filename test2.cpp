#include <iostream>
#include <iostream>
#include <cstring>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

const int Cat = 2;

void printCat(){
    cout<<"Cat = "<< Cat;
    //Cat += 1;

    return;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        struct TreeNode *temp = root;
        while(temp != NULL){
            if(root->left == NULL) {
                output.push_back(temp->val);
                temp = temp->right;
            }
            else {
                output.push_back(temp->left);
                temp = temp->left;
            }
        }
        return output;
    }
};
int main(){
    const int Cat =1;
    cout<<"Cat = "<< Cat;
    //Cat += 1;
    //cout<<"Cat = "<< Cat;
    printCat();
    //int x[] = {1,2};
    //int y[] = {3,4};
    int x= 1;
    int y= 2;
    char a = 't';
    char b = 'f';
    char smaller = (x < y ? a:b);
    cout<<"smaller = "<<smaller<<endl;
    return 0;
    /*
    //using Vint = vector<int>; 하면 밑에 부분 Vint 로 바꿔도 됨
    //for (vector<int>::iterator it = value.begin(); it != value.end(); it++) 
    // iterator 형태가 되고 어디서 부터 시작하나 = value.begin() 그 다음은 if codition, 어떤게 true 일동안 돌리나 이 같은 경우는 끝이 아닐 때 까지 
    // 그 뒤는 ++ 가 앞이던 뒤 던 이 케이스에서는 상관이 없음.
     std::string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)

    std::string str2 = str.substr (3,5);     // "think"
  /*

}   