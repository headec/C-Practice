#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    cout<<"pb = ";
    for(auto i :phone_book) cout<<i<<' ';
    cout<<endl;
    for (int i = 0; i < phone_book.size() - 1; i++) {
        cout<<"i = "<<i<<"\vpb[i+1] = "<<phone_book[i+1]<<endl;
        cout<<"pb[i] = "<<phone_book[i]<<" pb[i+1].substr(0, pb[i].size()) = "<<phone_book[i + 1].substr(0, phone_book[i].size())<<endl;
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) return false;
    }
    return answer;
}

int main()
{
    map<string,int> m;
    vector<string> str;
    str.push_back("hi");
    str.push_back("hello");
    
    for(auto i: str)
    {
        m[i] += 1;
        cout<<"i = "<<i<<"\tm[i] = "<<m[i]<<endl;
    }

    // str.push_back("hihe");
    // vector<string> aa = {"1","11","2"};
    // string *p;
    // vector<string>::iterator it;

    // for (int i = 1; i<str.size(); i++)
    // {
    //     int endpoint = str[0].size(); 
    //     cout<<"i ="<<i<<endl;
    //     //cout<<find(str[i].begin(),str[i].begin()+endpoint,str[0])<<endl;
    // }
    vector<string> input = {"0","11","123", "21","101","111"};
    solution(input);
    queue<int> q;
    cout<<"q.size() = " << q.size()<<endl;

    vector<int> k = {1,2,3};
    k.erase(k.begin()+1);
    cout<<"k[1] = "<<k[1]<<endl;
    vector<vector<int>> kk = {{1,2},{2,3,4}};
    cout<<"VECTOR OF VECTOR: \n";
    for(int i = 0 ; i<kk.size(); i++){
        cout<<"{ ";
         for(int j = 0; j<kk[i].size();j++){
            cout<<kk[i][j]<<' ';
        }        
        cout<<'}';
    }
    return 0;
}