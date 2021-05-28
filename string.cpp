#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int centuryFromYear(int year) {
    // int cent = year/100;
    // if(cent==0) return 1;
    // if(cent==1) return 2;
    // if(year%cent==0) return cent;
    // else return cent+1;  
    return ceil(year/100);
}

bool checkPalindrome(string inputString) {
    int N = inputString.length();
    for(int i = 0; i<floor(N/2);i++)
        {
            cout<<"i = "<<i<<" [i] = "<<inputString[i]<<" [N-i] = "<<inputString[N-i]<<endl;
            if(inputString[i]!=inputString[N-1]) return false;
            
        }
    return true;    
}

int main()
{
    const char* name1 = "Hello";
    //int* num;
    //num=new int[50];
    //num=10;
    string name = "Hello";
    name = "Change";
    name1 = "Hello1123";
    cout<<name<<' '<<*name1<<' '<<endl;
    cout<<"Tests: "<<ceil(float(1001)/100)<<' '<<ceil(1004)<<endl;
    cout<<centuryFromYear(1001)<<endl;

    //std::cin.get();
    //std::string str = "String Hello";
    //std::cout << pch <<' '<< str << std::endl;
    int n,f = 0;
    n = f =1;
    cout <<n<<' '<<f<<endl;
    cout<<checkPalindrome("abacaba")<<endl;
    
}