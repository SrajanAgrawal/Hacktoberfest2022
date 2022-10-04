/**
 * async multi threading with c++
 * Language : C++
 * Author : Cvar1984
 * Github : https://github.com/Cvar1984
 * Compile flag : -pthread -std=c++0x
 */

#include <thread>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

class MyClass {
    public:
    auto doStuff()->void
    {
        std::cout << "doing stuff so long" << std::endl;
        sleep(3);
    }
    auto doAnotherStuff()->void
    {
        std::cout << "doing another stuff" << std::endl;
    }
};

int main()
{
    sleep(3); // give a time to open task manager
    MyClass app;

    std::thread worker1(&MyClass::doStuff, app);
    std::thread worker2(&MyClass::doAnotherStuff, app);

    if(worker1.joinable()) worker1.join();
    if(worker2.joinable()) worker2.join();
}
