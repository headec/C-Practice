#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    q.push(0);
    int answer;
    for(int i = 0 ; i < truck_weights.size(); i++)
    {
        cout<<"i = "<<i<<endl;
        if(truck_weights[i]>weight)
        {
            answer += bridge_length;

            cout<<"FIRST IF"<<endl;
        }
        else
        {
            cout<<"FIRST ELSE"<<endl;
            if((q.back()+truck_weights[i])<=weight)
            {
                cout<<"SECOND IF"<<endl;
                q.push(truck_weights[i]+q.back());
                answer += 1;
            }
            else
            {
                cout<<"SECOND ELSE"<<endl;
                answer+=bridge_length;    
                q = queue<int>();
                q.push(0);
            }
            
        }
        cout<<"answer = "<<answer<<endl;
    }
    answer+=bridge_length;
    return answer;
}

int main(){
    int b = 2;
    int w = 10;
    vector<int> v = {7,4,5,6};
    int sol = solution(b,w,v);
    cout<<"solution = "<<sol<<endl;
}