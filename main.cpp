#include <iostream> 
#include "data.h"
#include "list.h"
using namespace std;

int main(void){
    List <Data> yes;
    int option = 0;
    
    while(option != 7){
        cout << "Enter an option 1-7" << endl;
        cin >> option;
        if(option == 1){
            yes.makeList();
        }
        else if(option == 2){
            yes.loadMaster();
        }
        else if(option ==3){
            yes.storeMaster();
        }
        else if(option == 4){
            yes.markAbsences();
        }
        else if(option ==6){
            int option = 0;
            cout << "Enter 1 to generate a report for all students. Enter 2 to generate a report for student with a certain amount of absences." << endl;
            cin >> option;
            if(option == 1){
                yes.generateReportOne();
            }
            else if(option == 2){
                yes.generateReportTwo();
            }
        }
    }
    
}