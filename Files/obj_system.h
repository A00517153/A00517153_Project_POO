#ifndef OBJ_SYSTEM_H
#define OBJ_SYSTEM_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const short int ID_LENGHT = 9;

class obj_system{
  protected:
    string name="UNDEFINED";
    char ID[ID_LENGHT+1]={'0','0','0','0','0','0','0','0','0'}; 
    
  public:
    obj_system();
    obj_system(string,string);

    void set_name(string);
    void set_id(string);
    void set_data(string,string);

    string get_name() const;
    string get_id() const;
    string get_text() const;

    void print_text() const;
};

obj_system::obj_system(){
  // For future changes
}

obj_system::obj_system(string name_, string id_){
  set_data(name_,id_);
}

void obj_system::set_name(string name_){
  name=name_;
}

void obj_system::set_id(string id_){
  id_.copy(ID,ID_LENGHT);
}

void obj_system::set_data(string name_,string id_){
  set_name(name_);
  set_id(id_);
}

string obj_system::get_name()const{return name;}

string obj_system::get_id()const{return (string)(ID);}

string obj_system::get_text()const{
  stringstream aux;
  aux<<"Name: "<<name<<"\nID: "<<ID<<"\n";
  return aux.str();
}

void obj_system::print_text()const{cout<<get_text()<<endl;}
#endif

