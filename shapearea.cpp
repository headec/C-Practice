#include <iostream>
using namespace std;
#include <vector>
int shapeArea(int n) {
    if(n==1) 
    {
        cout<<"n = 1"<<endl;
        return 1;
    }
    cout<<"n, 2n-1 = "<<n<<' '<<2*n-1<<endl;
    int result = 0;
    result = 2*n-1+(shapeArea(n-1));
    cout<< "result = "<< result<< endl;
    return result;
}   

bool almostIncreasingSequence(vector<int> sequence) {
    int temp = sequence[0];
    cout<<"temp = "<<temp<<endl;
    bool flag = false;
    for(int i = 0 ; i < sequence.size(); i++) {
       if(sequence[i] == temp) {
            temp+=1;
            cout<<"s,t = "<<sequence[i]<<' '<<temp<<endl;
       }else if (flag == false) flag = true;
       else return false;
    }
    return true;
}


int main()
{
    shapeArea(3);

    cout<<"increasing = " <<almostIncreasingSequence({1,3,2,1})<<endl;

    
}