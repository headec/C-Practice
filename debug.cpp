 #include <iostream>

 using namespace std;

char grading(int marks){
     if(marks <= 60) return 'D';
     else if((marks>=61)&&(marks<=75)) return 'C';
     else if((marks>=76)&&(marks<=90)) return 'B';
     else return 'A';
 }

 int main(){
    int mark;
    cout<<"Enter Your Marks: ";
    cin>>mark;
    cout<<"Grade: ";
    cout<<grading(mark)<<endl;

 }