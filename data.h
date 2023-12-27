#include "stack.h"
using namespace std;

class Data{
    public:
        Data();
        Stack *getDates();
        int getRecord();
        int getID();
        string getName();
        string getEmail();
        string getUnits();
        string getMajor();
        string getLevel();

        void setRecord(int record);
        void setID(int ID);
        void setName(string name);
        void setEmail(string email);
        void setUnits(string units);
        void setMajor(string major);
        void setLevel(string level);
    private:
        int record;
        int ID;
        string name;
        string email;
        string units;
        string major;
        string level;
        int absences; 
        Stack *dates;
};


