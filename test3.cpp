#include <iostream>
#include <vector> // vector 를 물려서 사용
#include <set> 
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

int main() {
// Vector //

// 길이를 변경할 수 있는 배열..!
// array 처럼 배열의 길이가 바뀔 때마다 바뀌는 메모리를 신경 쓸 필요가 없다!
    cout<<"Vector\n";
    //v.erase(unique(v.begin(), v.end()), v.end());
    //따라서 위와 같은 코드를 작성하면, 벡터에서 필요 없는 값들은 삭제하고 중복 없는 데이터를 얻을 수 있습니다

    vector<int> v1;
    vector<int> v2(6, 1);
    vector<int> v3 = {1, 2, 3, 4, 5};

    // .push_back(' ') 을 사용하면 가장 뒤에 데이터를 추가 할 수 있다.
    vector<int> a = {1, 2, 3, 4, 5};
    a.push_back(6); // [1, 2, 3, 4, 5, 6]
    a.push_back(7); // [1, 2, 3, 4, 5, 6, 7]
    
    // .pop_back() 은 가장 뒤의 데이터를 꺼내온다.
    a.pop_back(); // [1, 2, 3, 4, 5, 6]

    // 배열 비우기
    //a.clear(); // []

    // 배열의 길이.. 주로 루프를 돌릴 때 유용
    a.size();

    // 배열처럼 인덱스를 사용해서 자료 접근 가능
    for (int i=0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }

    // a.begin(), a.end()를 입력하면 iterator 가 반환된다. sort 라이브러리를 쓸 때 유용
    for (vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
        cout <<"*it = "<< *it << ' ';
    }
    cout<<endl;


// Pair //   

// 두 자료형을 하나의 쌍(pair)으로 묶는다.
// 첫번째 데이터는 first, 두번째 데이터는 second로 접근 가능
// vector, algorithm 의 헤더파일에 include 하고 있기 때문에 별도로 utility 헤더를 물릴 필요가 없다.
// 개인적으로 굉장히 유용하다고 생각되는 라이브러리
    cout<<"\nPair\n";
    pair<int, int> p1;
    cout << p1.first << ' ' << p1.second << '\n'; // 0 0 출력
    p1 = make_pair(1, 2);
    cout << p1.first << ' ' << p1.second << '\n'; // 1 2 출력

    // Pair 속에 Pair 를 중첩해서 사용 가능
    pair<pair<int,int>, pair<int,int>>  p = make_pair(make_pair(1,2), make_pair(3,4));

    cout << p.first.first << ' ' << p.first.second << ' '; 
    cout << p.second.first << ' ' << p.second.second << '\n'; // 1 2 3 4 출력

  
// Set //

// Associative 컨테이너
// 균형 이진 트리로 구현되어있다.
// Key라 불리는 원소들의 집합으로 이루어져 있다.
// Key값은 중복되지 않는다!
// insert를 통해 입력하면 자동 정렬된다
// 즉, 중복을 피하면서 정렬까지 사용하고 싶으면 매우 유용
    cout<<"\nSet\n";
    set<int> s;

    s.insert(10);
    s.insert(30);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(60);

    set<int>::iterator it;
    
    s.insert(10); // 중복 불가

    for (it = s.begin(); it != s.end(); ++it) {
        cout << *it << " "; // 10 20 30 40 50 60 출력
    }
    cout<<endl;
    // 값 존재 여부 확인
    it = s.find(30); //30이 있는 반복자가 있나 확인
    if ( it != s.end() ) { //끝에 닿기전에 있는 거면 존재
        cout << *it << " 존재" << endl;
    } else {
        cout << "존재하지 않음" << endl;
    }
    

// Map //

// Associative 컨테이너
// set은 원소값으로 key 하나만을 저장하지만, map은 <key, value>의 쌍(pair)으로 저장
// 중복 저장되지 않는다!
// set처럼 컨테이너에 원소 (key, value의 쌍)를 삽입하는 멤버 함수 insert()를 제공.
// map은 [] 연산자를 제공하여 key에 해당하는 원소의 value에 쉽게 접근하거나 변경할 수 있다.
    cout<<"\nMap\n";
    map<int, int> m;

    //pair 객체 insert()
    m.insert(pair<int, int>(5, 100));
    m.insert(pair<int, int>(3, 100)); 
    pair<int, int> p2(9, 50);     
    m.insert(p2);                

    // [] 연산자로 key/value 삽입
    m[11] = 200;            
    m[12] = 200;
    m[13] = 40;

    map<int, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter)
        cout << "<" << (*iter).first << "," << (*iter).second << ">" << " ";
    cout << endl;
    // 출력 <3,100> <5,100> <9,50> <11,200> <12,200> <13,40>

    // [] 연산자로 key/value 갱신 가능
    m[13] = 140;        

    pair<map<int, int>::iterator, bool > pr;

    // 중복 데이터 삽입 불가
    pr = m.insert(pair<int, int>(10, 30));
 
    if (true == pr.second)
        cout << "key : " << pr.first->first << ", value : " << pr.first->second << " 저장 완료!" << endl;
    else
        cout << "key 10가 이미 m에 있습니다." << endl;


// Stack //


    cout<<"\nStack\n";
    stack<int> s1;
    s1.push(6);
    s1.push(4);
    s1.push(1);
    s1.pop();
    s1.push(3);
    s1.push(10);
    s1.pop();
    s1.push(11);

    while ( !s1.empty()) {
        cout << s1.top() << ' ';
        s1.pop();
    }

    //empty() : 스택이 비어있으면 true 아니면 false를 반환
    //size() : 스택 사이즈를 반환
    cout<<endl;


// Queue //


    cout<<"\nQueue\n";
    queue<int> q;
    q.push(6);
    q.push(4);
    q.push(1);
    q.pop();
    q.push(3);
    q.push(10);
    q.pop();
    q.push(11);

    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
    cout<<endl;

// Priority Queue //
    cout<<"\nPriority Queue\n";
    priority_queue< int, vector<int>, less<int> > pq; //갈수록 작아짐 greater<int> = 갈수록 커짐

    // push(element)
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(9);
    pq.push(1);
    pq.push(14);

    // pop()
    pq.pop();
    pq.pop();

    // top();
    cout << "pq top : " << pq.top() << '\n';

    // empty(), size()
    if(!pq.empty()) cout << "pq size : " << pq.size() << '\n';

    // pop all
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << '\n';


// Bitset //


    // cout<<"\nBitset\n";
    // bitset<100000> a1(76),b1(44); // 각각 76, 44의 비트가 입력됨
    // cout << (a1 & b1) << '\n';
    // cout << (a1 | b1) << '\n';
    // cout << (a1 ^ b1) << '\n';
    // cout << (~a1) << '\n';
    // cout << (~b1) << '\n';
    

// This //

// class A {
//     int num;
// public:
     
//     A(int num) {
//         this->num = num;
//     }
 
//     int get_Num() {
//         return num;
//     }
// };
 
// int main(void) {
 
//     A a(10);
 
//     cout << a.get_Num() << endl;
//     return 0;
// }

//     return 0; 

//즉 this는 자기 자신의 객체를 가르키는 것입니다. 
//따라서 this->num은 매개변수A(int num)를 가르키는 것이 아닌 맴버변수를 가리키는 것입니다.
}