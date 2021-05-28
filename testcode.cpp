#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX_NUM = 10;
class Check{
    private:
        int prv = 0;
    public:
        Check(int prv){
            this->prv = prv; 
        }
        void print(){
            cout<<"prv = "<<prv<<endl;
        }
};
int main(){
    // vector<int> v1;
    // int n = 3;
    // int ai1[3] = {1,2,3};
    // int* pi1 = new int[n];
    // pi1[0] = 1;
    // cout<<"RESULTS: "<<ai1<<' '<<*pi1<<' ';
    // for(int i : ai1) cout<< i << ' ' ;
    // delete pi1;
    // cout<<pow(2,2)<<endl;
    // int d[7];
    // fill_n(d,7,1); // 1로 다 채워라!
    // cout<<d[5]<<endl;
    // vector<vector<int>> tri = {{1},{2,3},{4,5,6}};
    // int i =0 ;
    // // while(i<tri.size()){
    // //     tri[i]
    // // }
    // vector<int> a = {3,4,5,2,1};
    // a = vector<int>(a.begin()+2,a.end());
    // for(int &i : a ) cout<< i <<' ';


    vector<int> array = {1,5,2,6,3,7,4};
    vector<vector<int>> commands = {{2,5,3},{4,4,1},{1,7,3}};
    int i,j,k;
    vector<int> temp = array;
    vector<int> answer;
    
    temp = vector<int>(temp.begin()+1,temp.begin()+5);
    for(int i : temp ) cout<< i << ' ';
    sort(temp.begin(),temp.end());
    for(int i : temp ) cout<< i << ' ';
    cout<<"Answer = "<<temp[2];
    for(int x = 0; x < commands.size(); x++){
        i = commands[x][0]-1;
        j = commands[x][1];
        k = commands[x][2]-1;
        temp = vector<int>(temp.begin()+i,temp.begin()+j);
        sort(temp.begin(),temp.end());
        answer.push_back(temp[k]);
       // temp.clear();
        temp = array;
    cout<<"\n i , j , k = "<<i<<' '<<j<<' '<<k;
    }
    cout<<"\nANSWER: \n";
    for(int i : answer) cout<<i<< ' ';

    vector<int> z(3,0);
    cout<<'\n';
    for(int i : z) cout<<i<<' ';
    vector<string> x = {"1","2","3"};
    sort(x.begin(),x.end(),greater<string>());
    
    Check c(2);
    c.print();

    vector<vector<int>> edge = {{3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2}};
    sort(edge.begin(),edge.end());
    cout<<edge.size()<<endl;
    for(auto &i : edge) {
        for(auto &j : i) cout<<j<<' ';
    }
}