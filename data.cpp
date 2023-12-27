#include <iostream>
#include "data.h"
Data::Data(){
    dates = new Stack();
}
Stack *Data::getDates(){
    return dates;
}
int Data::getRecord(){
    return record;
}
int Data::getID(){
    return ID;
}
string Data::getName(){
    return name;
}
string Data::getEmail(){
    return email;
}
string Data::getUnits(){
    return units;
}
string Data::getMajor(){
    return major;
}
string Data::getLevel(){
    return level;
}
void Data::setRecord(int record){
    this->record = record;
}
void Data::setID(int ID){
    this->ID = ID;
}
void Data::setName(string name){
    this->name = name;
}
void Data::setEmail(string email){
    this->email = email;
}
void Data::setUnits(string units){
    this->units = units;
}
void Data::setMajor(string major){
    this->major = major;
}
void Data::setLevel(string level){
    this->level = level;
}




