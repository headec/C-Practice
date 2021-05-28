#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_CONST
{
    enum
    {
        ID_LEN =20
    };

    void greet(){
        cout<<"Hello There!"<<endl;
    }
}

class Car
{
    private:
    char gamerID[CAR_CONST::ID_LEN];
    
    public:
    void Init(char *ID);
    void ShowCarState();
};

void Car::Init(char *ID)
{
    strcpy(gamerID, ID);
}

void Car::ShowCarState()
{
    cout<<"ID is "<<gamerID<<endl;
}
int main()
{
    CAR_CONST::greet();
    Car mine;
    char input[20];
    cin>> input;
    mine.Init(input);
    mine.ShowCarState();
    return 0;
}