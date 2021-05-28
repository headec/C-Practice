#include <iostream>
#include <string>
//#include <typeinfo>

using namespace std;

int main () {
    string s = "book";
    cout << s << ": " << s.size() << '\n'; // 4
    cout << s << ": " << s.length() << '\n'; // 4
    s = "";
    cout << s << ": " << s.size() << '\n'; // 0

    // printf 출력
    printf("%s\n",s.c_str());

    // insert, append, push_back
    string ss = "e"; // "e"
    ss.insert(0, "H"); // "He"
    ss.insert(2, "o"); // "Heo"
    ss.insert(2, 3, 'l').append(" "); // "Hello "
    string world = "Half the World Away";
    ss.insert(6, world, 9, 5).push_back('!'); // ss의 6번째에 world 변수를 9번째 부터 +5까지만 넣고 뒤에 !를 추가 "Hello World!"
    cout<<"ss = "<<ss<<endl;

    //  stoi
    string str = "10";
    int number = stoi(str);
    cout<<"number = "<<number<<"type = "<<typeid(stoi(str)).name()<<endl; 

    // to_string
    int n1 = 1;
    int n2 = 2;
    double n3 = 3.4;
    string s1 = to_string(n1);
    string s2 = to_string(n2);
    cout << s1 + ' ' + s2 << '\n';
    //cout<<typeid(s1).name()<<endl;
    return 0;
}