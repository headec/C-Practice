#include <iostream>
#include <cstring>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

/*
const 는 function 이든 variable 이든 그 안에서 그 값 유지.
static 은 값이 한 메모리 공간에 저장되어 share 함.
inheritance 할 때 protected 면 그 밑으로는 다 protected 가 됨.
protected 된 variable 은 interited 된 class 에서 바꿀 수 있음. private 은 불가능.
상속된 function 이나 value 는 상속한 class에서 사용가능. 중복 된 이름 사용시 상속한 class 걸로 오버로딩.
endl 보다 \n 이 속도가 빠름. endl 은 output buffer 를 매번 flushing 해야 하기에 속도가 느려짐. 대신 \n은 메모리를 잡아먹음.
#ifdef (보통 이게 밑) 지시자를 사용하면 전처리기가 이전에 #define 이 정의되었는지 아닌지를 확인한다. 정의되었다면 #ifdef와 해당 #endif 사이의 코드가 컴파일된다. 그렇지 않으면 코드가 무시된다.
#ifndef (보통 이건 위)는 ifdef의 반대다. 식별자(identifier)가 아직 정의되지 않았는지 확인한다. 정의되지 않았다면 실행된다.
오버로딩(Overloading) - 함수 중복 정의
오버로딩은 같은 이름의 함수에 매개변수를 다르게 사용하여 매개 변수에 따라 다른 함수가 실행되는 것.
오버라이딩(Overriding) - 함수 재정의
오버라이딩은 상속받았을때 부모클래스의 함수를 사용하지 않고 다른 기능을 실행할때 함수를 자식클래스에 같은 이름, 매개변수로 재정의 해서 사용하는 것
*/

enum{NUM =7, BER=8};

//두 개 이상 parameter 받을 수 있음. 첫번째 데이터 타입 두번째 int.
template <typename T, int len>
class Simplearray
{
    private: 
        T arr = 1;
    public:
        T add(T n1)
        {
            return arr + n1 + len;
        }
};

//datatype 에 따라 다르게 static이 유지됨.
template <class T>
void multiplier()
{
    static T n1 = 2;
    n1*=2;
    cout<<n1<<" ";
}

class SimpleClass
{
private:
    int num1=NUM;
    int num2;
    char * str1 = new char[10];
    char str2[10];
    char str3;
    static int num3;
protected:
    float dec1 = 0;
public:
    SimpleClass()
    {
        num1=NUM;
        num2=BER;
        strcpy(str1,"nothing");
        strcpy(str2,"hi");
        str3='1';
        num3 += 1;
    }
    SimpleClass(char * n)
    {
        num1=0;
        num2=0;
        str1=n;
        strcpy(str2,"bye");
        str3='2';
        num3 += 2;
    }
    SimpleClass(int n1, int n2){
        num1=n1;
        num2=n2;
    }
    void showData() const
    {
        cout<<"num1 = "<<num1<<" num2 = "<<num2<<" str1 = "<<str1<<" str2 = "<<str2<<" str3 = "<<str3<<
        " num3 = "<<num3<<endl;
        delete str1;
    }

    int add(int n1, int n2)
    {
        int result = n1+n2;
        cout<<"int Add = "<<result<<endl;
        return result;
    }
    template <typename T>
    T add(T n1, T n2)
    {
        T result = n1+n2;
        cout<<"T Add = "<<result<<endl;
        return result;
    }
    
   // void showVal(T n1=0,T n2=0) const;
};

//밖에 할 경우 class 위에도 template 추가해야함
    // template <typename T>
    // void SimpleClass<T>::showVal(T n1, T n2) const
    // {
    //     cout<<"n1 = "<<n1<<" n2 = "<<n2<<endl;
    // }

class SsimpleClass : public SimpleClass
{
private:
    int num4;
    char str4;
public:
    SsimpleClass(char val)
        : SimpleClass()
    {
        num4 = 0;
        str4 = val;
    }
    void DisplayData() const
    {
        cout<<"num4 = "<<num4<<" str4 = "<<str4<<endl;
    }
};
class TsimpleClass : protected SimpleClass
{
private:
    int num5;
protected:
    float dec2;
public:
    char str6[10] = "check";
    void addData()
    {
        //num1 += 1;
        dec1 += 1;
    }
    void showData() const
    {
        cout<<"num5 = "<<num5<<" dec1,2 = "<<dec1<<","<<dec2<<" str6 = "<<str6<<endl;
    }
};

class First
{
    public:
        virtual void Func(){cout<<"First"<<endl;}
};
class Second : public First
{
    public:
        virtual void Func(){cout<<"Second"<<endl;}
};

int SimpleClass::num3 = 0; // static 값을 주고 시작.

//try, catch, and throw
void divide(int n1, int n2)
{
    if(n2 == 0) throw n2;
    cout <<"나눗셈의 몫: "<<n1/n2<<endl;
    cout<<"나눗셈의 나머지: "<<n1%n2<<endl;
}

void printLength(const array<int,5>& my_arr) // array 가 안에서 변치 않길 원하면 const
{
    cout<<my_arr.size()<<endl;
}

int main()
{
    SimpleClass sc1;
    sc1.showData();
    sc1.add(1,2);
    sc1.add<int>(1.9,2.1); // template 을 사용한 곳에서 호출
    char * value = new char[10];
    strcpy(value, "hi");
    SimpleClass sc2(value);
    sc2.showData();
    SsimpleClass ssc1('i');
    ssc1.showData();
    ssc1.DisplayData();
    TsimpleClass tsc1;
    tsc1.addData();
    tsc1.showData();
    delete value;

    Second * test2 = new Second();
    First * test1 = test2; //Virtual 을 사용하면 상속받은 Func 가 오버라이딩 된 Func 값을 돌려줌. 사용치 않을 경우에는 각각 해당하는 함수의 값을 돌려줌. 예) Virtual 했을경우 cout 값은 둘다 Second 안했을 경우 First Second

    Simplearray<int, 5> sa1;
    cout<<sa1.add(2)<<endl;

    multiplier<int>();
    multiplier<int>();
    cout<<endl;
    multiplier<double>();
    cout<<endl;
    cout<<typeid(5+3.0).name()<<endl; // 최대한 데이터 loss 가 안 일어나게

    try
    {
        divide(2,0); // throw 에 안 걸릴 경우
        cout<<"나눗셈 끝"<<endl;
    }
    catch(int n)
    {   //throw 에 걸릴 경우
        cout<<"제수가"<<n<<"입니다"<<endl;
    }


// array 및 vector 라이브러리


    vector<int> arr = {1,2};
    cout << "arr = " << arr[1] <<endl;
    int n = 10;
    arr.resize(n);
    cout<<"vector arr = "<<endl;
    for(auto &i : arr) cout << i << " ";
    cout<<'\n'<< arr.size()<< endl;
    vector<int> arr2 = {1,2,3,4,5};
    array<int,5> myArr;
    cout<<"array<int, 5>"<<endl;
    //for(int i = 0 ; i<5 ; i++) cout<<myArr<<' ';
    for(auto &i : myArr) cout<<i<<' ';
    cout<<endl<<"vector arr[2] = "<<arr2[2]<<' '<<arr2.at(2)<<' ' << arr2.size()<<endl; // at 은 없는 사이즈면 예외처리 발생. size는 보통 array 에서는 불가능.
    cout<< arr2.size() <<endl;
    sort(myArr.begin(),myArr.end()); // .rbegin(),.rend() 하면 역순 minmax_element(.begin(),.end()) 미니멈 앞 큰 거 뒤


    for(auto &i : arr2) cout << i <<" ";
    cout << endl;
    int x[3][10] = {{1,2,3,4},{0,0,0,0},{5,6,7,8}};
    for (int i=0; i<3; i++){
        for(int j =0; j<10; j++){
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << x[2][9] << " " <<endl;
    cout<<"arr[-1] = "<<arr.size()<<endl;
 //   vector<int> darr = {{1,2},{3,4},{5,6}};
  //  for(auto &i : darr) cout << i << " ";

    enum Day {SUN, MON ,TUES};
    Day today = MON;
    cout<<"Day = "<<today<<endl;


  
}