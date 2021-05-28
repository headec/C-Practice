#include <iostream>
#include <vector> // vector �� ������ ���
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

// ���̸� ������ �� �ִ� �迭..!
// array ó�� �迭�� ���̰� �ٲ� ������ �ٲ�� �޸𸮸� �Ű� �� �ʿ䰡 ����!
    cout<<"Vector\n";
    //v.erase(unique(v.begin(), v.end()), v.end());
    //���� ���� ���� �ڵ带 �ۼ��ϸ�, ���Ϳ��� �ʿ� ���� ������ �����ϰ� �ߺ� ���� �����͸� ���� �� �ֽ��ϴ�

    vector<int> v1;
    vector<int> v2(6, 1);
    vector<int> v3 = {1, 2, 3, 4, 5};

    // .push_back(' ') �� ����ϸ� ���� �ڿ� �����͸� �߰� �� �� �ִ�.
    vector<int> a = {1, 2, 3, 4, 5};
    a.push_back(6); // [1, 2, 3, 4, 5, 6]
    a.push_back(7); // [1, 2, 3, 4, 5, 6, 7]
    
    // .pop_back() �� ���� ���� �����͸� �����´�.
    a.pop_back(); // [1, 2, 3, 4, 5, 6]

    // �迭 ����
    //a.clear(); // []

    // �迭�� ����.. �ַ� ������ ���� �� ����
    a.size();

    // �迭ó�� �ε����� ����ؼ� �ڷ� ���� ����
    for (int i=0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }

    // a.begin(), a.end()�� �Է��ϸ� iterator �� ��ȯ�ȴ�. sort ���̺귯���� �� �� ����
    for (vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
        cout <<"*it = "<< *it << ' ';
    }
    cout<<endl;


// Pair //   

// �� �ڷ����� �ϳ��� ��(pair)���� ���´�.
// ù��° �����ʹ� first, �ι�° �����ʹ� second�� ���� ����
// vector, algorithm �� ������Ͽ� include �ϰ� �ֱ� ������ ������ utility ����� ���� �ʿ䰡 ����.
// ���������� ������ �����ϴٰ� �����Ǵ� ���̺귯��
    cout<<"\nPair\n";
    pair<int, int> p1;
    cout << p1.first << ' ' << p1.second << '\n'; // 0 0 ���
    p1 = make_pair(1, 2);
    cout << p1.first << ' ' << p1.second << '\n'; // 1 2 ���

    // Pair �ӿ� Pair �� ��ø�ؼ� ��� ����
    pair<pair<int,int>, pair<int,int>>  p = make_pair(make_pair(1,2), make_pair(3,4));

    cout << p.first.first << ' ' << p.first.second << ' '; 
    cout << p.second.first << ' ' << p.second.second << '\n'; // 1 2 3 4 ���

  
// Set //

// Associative �����̳�
// ���� ���� Ʈ���� �����Ǿ��ִ�.
// Key�� �Ҹ��� ���ҵ��� �������� �̷���� �ִ�.
// Key���� �ߺ����� �ʴ´�!
// insert�� ���� �Է��ϸ� �ڵ� ���ĵȴ�
// ��, �ߺ��� ���ϸ鼭 ���ı��� ����ϰ� ������ �ſ� ����
    cout<<"\nSet\n";
    set<int> s;

    s.insert(10);
    s.insert(30);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(60);

    set<int>::iterator it;
    
    s.insert(10); // �ߺ� �Ұ�

    for (it = s.begin(); it != s.end(); ++it) {
        cout << *it << " "; // 10 20 30 40 50 60 ���
    }
    cout<<endl;
    // �� ���� ���� Ȯ��
    it = s.find(30); //30�� �ִ� �ݺ��ڰ� �ֳ� Ȯ��
    if ( it != s.end() ) { //���� ������� �ִ� �Ÿ� ����
        cout << *it << " ����" << endl;
    } else {
        cout << "�������� ����" << endl;
    }
    

// Map //

// Associative �����̳�
// set�� ���Ұ����� key �ϳ����� ����������, map�� <key, value>�� ��(pair)���� ����
// �ߺ� ������� �ʴ´�!
// setó�� �����̳ʿ� ���� (key, value�� ��)�� �����ϴ� ��� �Լ� insert()�� ����.
// map�� [] �����ڸ� �����Ͽ� key�� �ش��ϴ� ������ value�� ���� �����ϰų� ������ �� �ִ�.
    cout<<"\nMap\n";
    map<int, int> m;

    //pair ��ü insert()
    m.insert(pair<int, int>(5, 100));
    m.insert(pair<int, int>(3, 100)); 
    pair<int, int> p2(9, 50);     
    m.insert(p2);                

    // [] �����ڷ� key/value ����
    m[11] = 200;            
    m[12] = 200;
    m[13] = 40;

    map<int, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter)
        cout << "<" << (*iter).first << "," << (*iter).second << ">" << " ";
    cout << endl;
    // ��� <3,100> <5,100> <9,50> <11,200> <12,200> <13,40>

    // [] �����ڷ� key/value ���� ����
    m[13] = 140;        

    pair<map<int, int>::iterator, bool > pr;

    // �ߺ� ������ ���� �Ұ�
    pr = m.insert(pair<int, int>(10, 30));
 
    if (true == pr.second)
        cout << "key : " << pr.first->first << ", value : " << pr.first->second << " ���� �Ϸ�!" << endl;
    else
        cout << "key 10�� �̹� m�� �ֽ��ϴ�." << endl;


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

    //empty() : ������ ��������� true �ƴϸ� false�� ��ȯ
    //size() : ���� ����� ��ȯ
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
    priority_queue< int, vector<int>, less<int> > pq; //������ �۾��� greater<int> = ������ Ŀ��

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
    // bitset<100000> a1(76),b1(44); // ���� 76, 44�� ��Ʈ�� �Էµ�
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

//�� this�� �ڱ� �ڽ��� ��ü�� ����Ű�� ���Դϴ�. 
//���� this->num�� �Ű�����A(int num)�� ����Ű�� ���� �ƴ� �ɹ������� ����Ű�� ���Դϴ�.
}