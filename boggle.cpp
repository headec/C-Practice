#include <iostream>
#include <cstring>
using namespace std;

#define M 3
#define N 3
int main(){
    string dic[] = {"GEEKS","FOR","QUIZ","GO"};
    char boggle[M][N] = {{'G', 'I', 'Z'},
                       {'U', 'E', 'K'},
                       {'Q', 'S', 'E'}};
    
    
    cout << "boggle[][] = "<<*boggle<<endl;
    return 0;
}