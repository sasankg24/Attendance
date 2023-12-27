#include <iomanip>
#include <ctime>
#include "stack.h"
Stack::Stack(){
    top = 0;
}
char *Stack::getAttend(){
    return attend;
}
int Stack::getTop(){
    return top;
}
string Stack::getTime(){
    string convert = "";
    char time_to_s[50];
    const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    const std::time_t time = std::chrono::system_clock::to_time_t(now);

    cout << "date of: " << std::put_time(std::localtime(&time), "%D") << endl;

    tm* latestAb = std::localtime(&time);
    std::strftime(time_to_s, sizeof(time_to_s), "%x", latestAb);

    convert = time_to_s;
    return convert;
}
void Stack::push(char attendance){
    attend[top] = attendance;
    dates[top] = getTime();
    top++;
}
char Stack::peek(){
    char option = 'N';
    option = attend[top-1];
    return option;
}
