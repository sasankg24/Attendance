#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
template <typename T> class List{
    public:
        List();
        void insertAtFront();
        void makeList();
        void loadMaster();
        void storeMaster();
        void markAbsences();
        void generateReportOne();
        void generateReportTwo();
        void load(ifstream &input);
    private:
        int count;
        Data info[100];
       // Node <Data> *pHead;
};

template <typename T> List<T>::List(){
    count = 0;
}
template <typename T> void List<T>::makeList(){
    ifstream input("classList.csv");
    load(input);
}
template <typename T> void List<T>::loadMaster(){
    ifstream input("master.csv");
    load(input);
}
template <typename T> void List<T>::storeMaster(){
    fstream output("master.csv");
    output << "Record Number,ID,Name,Email,Units,Program,Level" << endl;
    for(int i=0; i<count; i++){
        output << info[i].getRecord() << "," << info[i].getID() << "," << "\"" << info[i].getName() << "\"" << "," << info[i].getEmail() << "," << info[i].getUnits() << "," << info[i].getMajor() << "," << info[i].getLevel();
    }
}
template <typename T> void List<T>::markAbsences(){
    Stack *date = NULL;
    char option = ' ';
    for(int i=0; i<count; i++){
        cout << "Is this student absent: " << info[i].getName() << " " << "Y/N?" << endl;
        cin >> option;
        if(option == 'Y'){
            date = info[i].getDates();
            date->push(option);
        }
        else if(option == 'N'){
            date = info[i].getDates();
            date->push(option);
        }
    }
}
template <typename T> void List<T>::generateReportOne(){
    Stack *option = NULL;
    cout << "Students with the most recent absences:" << endl;
    for(int i = 0; i<count; i++){
        option = info[i].getDates();
        char absent = option->peek();
        if(absent == 'Y'){
            cout << info[i].getName() << endl;
        }
    }
}
template <typename T> void List<T>::generateReportTwo(){
    Stack *yes = NULL;
    int option = 0;
    cout << "Enter amount of absences:" << endl;
    cin >> option;
    for(int i=0; i<count; i++){
        int counter = 0;
        yes = info[i].getDates();
        char *no = yes->getAttend();
        for(int j=0; j<yes->getTop(); j++){
            if(no[j] == 'Y'){
                counter++;
            }
        }
        if(counter >= option){
            cout << info[i].getName() << endl;
        }
    }
}
template <typename T> void List<T>::load(ifstream &input){
    string line;
    count = 0;
    getline(input, line);
    cout << line << endl;
    while(!input.eof()){
        while (getline(input, line)) {
            stringstream ss(line);
            string record, ID, name, email, units, major, level, temp;

            // Read and parse the values using stringstream
            getline(ss, record, ',');
            getline(ss, ID, ',');
            getline(ss, name, '"'); // Handle the quoted name
            getline(ss, name, '"');
            getline(ss, temp, ',');
            getline(ss, email, ',');
            getline(ss, units, ',');
            getline(ss, major, ',');
            getline(ss, level, ',');

            int intRecord = stoi(record);
            int intID = stoi(ID);

            info[count].setRecord(intRecord);
            info[count].setID(intID);
            info[count].setName(name);
            info[count].setEmail(email);
            info[count].setUnits(units);
            info[count].setMajor(major);
            info[count].setLevel(level);

            count ++;
        }
    }
    for(int i=0; i<count; i++){
        cout << info[i].getRecord() << "," << info[i].getID() << "," << info[i].getName() <<  "," << info[i].getEmail() << "," << info[i].getUnits() << "," << info[i].getMajor() << "," << info[i].getLevel() << endl;
    }
}