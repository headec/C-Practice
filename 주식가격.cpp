#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int count = 0;
    for(int i=0 ; i < prices.size(); i++)
    {
        count = 0;
        for(int j = i+1; j<prices.size(); j++)
        {
            if(prices[i]<=prices[j]) count++;
            else {count++; break;}
        }
        answer.push_back(count);
    }
    return answer;
}

int main(){
    vector<int> v = {0,3,1,2,3,2,3};
    cout<<"vector v = "<<v[1]<<endl;
    for(auto i : solution(v)) cout<<i<<' ';
    return 0;
}