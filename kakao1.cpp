#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer;
    string hand_use;
    int LH = 4;
    int RH = 4;
    int Ldist,Rdist = 0;
    if (hand == "right") hand_use = "R";
    else hand_use = "L";
    map<int,int> m1;
    m1[0] = 4;

    for(int a = 1; a<4; a++){
        m1[a] = 1;
        m1[a+3] = 2;
        m1[a+6] = 3;
    }

    int temp = 4;

    for(int i = 0; i<numbers.size(); i++){
        temp = m1[numbers[i]];
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
            answer += "L";
            LH = temp;
            cout<<"numbers[i] =" <<numbers[i] <<", Left " <<endl;
            cout<<"LH = "<<temp<<endl;
        } 
        else if(numbers[i] == 3 || numbers[i]==6 || numbers[i]==9){
            answer += "R";
            RH = temp;
            cout<<"numbers[i] =" <<numbers[i] <<", Right " <<endl;
            cout<<"RH = "<<temp<<endl;
        }
        else {
            cout<<"numbers[i] =" <<numbers[i] <<", LR " <<endl;
            Ldist = abs(temp - LH);
            cout<<"temp - LH = Ldist " <<temp<<' '<<LH<<' '<<Ldist<<endl;
            Rdist = abs(temp - RH);
            cout<<"temp - RH = Rdist " <<temp<<' '<<RH<<' '<<Rdist<<endl;
            if(Ldist - Rdist == 0) {
                answer += hand_use;
                cout<<"hand_use = " <<hand_use<<endl;
                if(hand_use=="L") LH = temp;
                else RH = temp;
            }
            else if(Ldist < Rdist) {
                answer += "L";
                LH = temp;
            }
            else {
                answer += "R";
                RH = temp;
            }
        }
    }
    return answer;
}

int main(){
    vector<int> v1 = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string h1 = "right";
    cout<<solution(v1,h1)<<endl;
}
// LRLLLRLLRRL
// LRLLLRLLLRL