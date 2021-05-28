#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>
 
using namespace std;
int GetRandom(int max){
    srand(time(NULL));
    return rand() % max;
}
/*----- END SIMPLE THREAD EXAMPLE ----- */
 
std::string GetTime(){
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime = 
            std::chrono::system_clock::to_time_t(nowTime);
    return std::ctime(&sleepTime);
}

void ExThr(int id){
    auto nowTime = chrono::system_clock::now();
    time_t sleepTime = chrono::system_clock::to_time_t(nowTime);
    tm myLocalTime = *localtime(&sleepTime);
}
double acctBalance = 100;
 
// Protects shared data from being accessed at the
// same time
std::mutex acctLock;
 
void GetMoney(int id,
        double withdrawal){
    
    // The exception safe way to protect access
    // to code within its scope. The lock is released 
    // after execution leaves this scope
    std::lock_guard<std::mutex> lock(acctLock);
    
    // Blocks access between lock and unlock
    // until execution completes
    // This isn't good to use however if an error 
    // occurs between lock and unlock
    // acctLock.lock();
    
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    std::cout << id << 
            " tries to withdrawal $" <<
            withdrawal << " on " <<
            GetTime() << "\n";
            
    if((acctBalance - withdrawal) >= 0){
        acctBalance -= withdrawal;
        std::cout << "New Account Balance is $" <<
                acctBalance << "\n";
    } else {
        std::cout << "Not Enough Money in Account\n";
        std::cout << "Current Balance is $" <<
                acctBalance << "\n";
    }
    // acctLock.unlock();
}
 
int main()
{
    /* ----- SIMPLE THREAD EXAMPLE -----
    // Create a thread and pass a parameter
    // to the function
    std::thread th1 (ExecuteThread, 1);
    
    // Join the thread to the main thread
    // meaning main waits for this thread to
    // stop executing before continuing execution
    // of code in main
    th1.join();
    
    std::thread th2 (ExecuteThread, 2);
    th2.join();
    ----- END SIMPLE THREAD EXAMPLE ----- */
    
    // We will create a pool of threads that
    // will access a bank account in no particular
    // order
}