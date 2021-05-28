#include <iostream>
#include <cstring>

using namespace std;

void incDecRef(int * x, int * y){
	*x += 1;
	*y -= 1;
}

void incDecRef(int &x, int &y){
	x += 1;
	y -= 1;
}

int * incAddress(int * x){
	x += 1;
	return x + 1;
}

int & incRAddress(int & x){
	x++;
	return x;
}

char * MakeStrAdr(int len){
	char * str = (char*)malloc(sizeof(char)*len);
	return str;
}

int main(){
	int num1 = 200;
	int *ptr = &num1;
	cout << "*ptr = " << *ptr << "ptr = " << ptr << "&ptr = " << &ptr << endl;
	int &num2 = num1;
	cout << "&num2 = " << &num2 << "num2 = " << num2 << endl;
	int **ptr2 = &ptr;
	cout << "*ptr2 = " << *ptr2 << "ptr2 = " << ptr2 << "&ptr2 = " << &ptr2 << endl;
	int **ptr3 = ptr2;
	cout << "*ptr3 = " << *ptr3 << "ptr3 = " << ptr3 << "&ptr3 = " << &ptr3 << endl;
	int *(&pref) = ptr;
	cout << "*(&pref) = " << *(&pref) << " pref = " << pref << endl;


	int v1 = 10;
	int v2 = 20;
	incDecRef(&v1, &v2);
	cout << "v1 and v2 = " << v1 << " " << v2
		<< " &v1 = " << &v1 << endl;
	incDecRef(v1, v2);
	cout << "v1 and v2 = " << v1 << " " << v2 
		 << " &v1 = " << &v1 << endl;
//	incAddress(&v1);
//	cout << "&v1 = " << &v1 << endl;
	int *x1 = incAddress(&v1);
	cout << "&v1 and x1 = " << &v1 << " " << x1 << " v1 = " << v1 << endl;
	int x2 = incRAddress(v1);
	cout << "v1 and x2 = " << v1 << " " << x2 << endl;

	const int num = 10;
	const int &ref = num;
	cout << "num & ref = " << num << " " << ref << endl;

	//new & delete

	char * str = MakeStrAdr(20);
	strcpy(str, "I am so happy");
	cout << str << endl;
	free(str);

	system("pause");
	return 0;
}
