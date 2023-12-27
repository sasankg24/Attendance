#include <iostream> 
using namespace std;
class Stack{
    public:
        Stack();
        char *getAttend();
        int getTop();
        string getTime();
        void push(char attendance);
        void pop();
        char peek();
        void isEmpty();
    private:
        string dates[200];
        char attend[200];
        int top;
};