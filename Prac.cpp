#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool symTree(TreeNode* l, TreeNode* r){
	//cout<<"ENTERED IF ";
	if(l||r != NULL && l->val == r->val){
		//cout<<"RECURSING1 ";
		symTree(l->left,r->right);
		//cout<<"RECURSING2 ";
		symTree(l->right,r->left);
		return true;
	} else if(l==NULL && r==NULL) {
		//cout<<"ENTERED ELSE IF";
		return true;
	}
	else {
		//cout<<"ENTERED ELSE";
		return false;
	}
}
bool check(){
	return true;
}

void insertNode(TreeNode* t){
	if(t==NULL){
		return;
	}
}
int main(void){
	TreeNode * t = new TreeNode;
	t->val = 1;
	TreeNode* temp = new TreeNode;
	temp->val = 2;
	t->left = temp;
	t->right = temp;
	cout<<t->left->val<<' '<<t->right->val<<endl;
	cout<<t->left<<' '<<t->right<<endl;
	cout<<(t->left->left == NULL)<<endl;
	cout<<"SymTree = "<<symTree(t,t)<<endl;
	cout<<"Check = "<<check();
	
	map<int,int> v;
	v[0] = 1;
	cout<<"v.size()= "<<v.size()<<' ';
    map<int, int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); ++iter)
        cout << "<" << (*iter).first << "," << (*iter).second << ">" << " ";

//	for(auto i : v) cout<<"i = "<< i << ' ';
	vector<int> q= { 1,2,3,4,5,6};
	for(int i : q) cout<<"q = "<< i << ' ';
	//unordered_map<int> um1;
	map<vector<int>,int> m1;
	
}