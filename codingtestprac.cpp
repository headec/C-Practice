#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

// void solution(){

//     std::vector<std::string> repo = {"mobile","mouse","moneypot","monitor","mousepad"};
//     std::vector<std::string> answer;
//     int j;
//     for(int i = 0; i<repo.size();i++){
//         std::string s = repo[i];
//         j = 0;
//         while(j < s.size()){
//             answer[i].push_back(tolower(s[j]));
//             j++;
//         }
//     }
//     // for(int k = 0 ; k < answer.size(); k++){
//     //     cout<< answer[k] << endl;
//     // }
//     //for(auto &i : answer) cout << i << " ";
//     for (auto k = answer.begin(); k != answer.end(); ++k) {
//         std::cout << *k << ' ';
//     }
//     std::cout<<"completed";
//     //eturn 1;
// }

int main(){
    char str[] = "Geeks for Geeks";
    char *token;
    char *rest = str;
    
    while ((token = strtok_r(rest, " ", &rest)))
        cout<<token<<"\n";
    
    //#2
    string line = "GeeksForGeeks is a must try";
      
    // Vector of string to save tokens
    vector <string> tokens;
      
    // stringstream class check1
    stringstream check1(line);
      
    string intermediate;
      
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
      
    // Printing the token vector
    for(int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << '\n';

    stack<char> s;
    string hi = "hello";
    cout<<"hi.size() = " <<hi.size()<<endl;
    for(int i = 0; i <hi.size();i++){
        s.push(hi[i]);
    }  
    
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<'\n'<<string(hi.rbegin(),hi.rend())<<endl;

    map<string,int> m;
    m["hi"] =1;
    for(auto i : m) cout<<i.first<<endl;
    for(auto it = m.begin(); it!=m.end();++it) cout<<*it<<endl;


}