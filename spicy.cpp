#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville){
    int answer = 0;
    int mix = 0;
    int flag = 0;
    sort(scoville.begin(),scoville.end());
    for(int i = 0 ; i < scoville.size(); i++){
        i -= flag;
        flag = 0;
        if(scoville[i]<K){
            mix = scoville[i] + scoville[i+1]*2;
            scoville.erase(scoville.begin()+i);
            scoville.at(i) = mix;
            sort(scoville.begin(),scoville.end());
            answer++;
            flag = 1;
        }
        else if(answer==0) return 0;
    }
    if(scoville[0] < K){
        return -1;
    }
    return answer;
}
//yet to be completed