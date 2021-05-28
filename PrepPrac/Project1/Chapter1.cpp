#include <iostream>
int func(int a , int b = 3); // default value
#define square(x) (x*x);
//using namespace std;
/*
void func(char a = 'a'){ // default value
	std::cout << "func" <<std::endl;
}*/
namespace BestComImpl{
	void SimpleFunc();
	namespace BestIn{
		void SimpleIn(){
			std::cout << "Best In" << std::endl;
		}
	}
}
void BestComImpl::SimpleFunc(){
	std::cout << "Best Com" << std::endl;

}
namespace ProgComImpl{
	void SimpleFunc(){
		std::cout << "Prog Com" << std::endl;
		BestComImpl::SimpleFunc();
	}
}
int func(int a, int b){
	std::cout << "func " << a << b <<std::endl;
	int ab = a;
	return ab,a;
}
int val = 100;
int valfunc(){
	int val = 20;
	val += 3;
	::val += 7;
	return 0;
}
int main(void){
	valfunc();
	std::cout << "val = " << val << std::endl;
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	BestComImpl::BestIn::SimpleIn();
	namespace BB = BestComImpl::BestIn;
	BB::SimpleIn();
	using BestComImpl::SimpleFunc;
	SimpleFunc();
	int ab = 2;
	func(42);
	std::cout << ab <<std::endl;
	char name[10];
	int num = 20;
	int val,val2;
	std::cin >>name>> val>>val2;
	double result = num + val + val2;

	for (int i = 0; i <= 4; i++){
		std::cout << "how many? "<<i << std::endl;
	}
	//func(1);
	int b = func(1);
	int sx = square(2);
	std::cout << "b ="<< b<<"Hello " 
		<< name <<  num << "world" <<func(32) <<"func"
		<< val << " " << result 
		<< "sx" << sx << std::endl;
	system("pause");
	//std::cin.get();
	return 0;
}