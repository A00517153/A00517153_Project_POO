#ifndef OBJ_SYSTEM_H
#define OBJ_SYSTEM_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class obj_system{
  protected:
    string name;
    char ID[10]; 
    int ID_lenght = sizeof(ID)/sizeof(char);

  public:
    obj_system(){
      name="UNDEFINED";
      for (int i = 0; i < ID_lenght; i++) {
        ID[i]=name[i];
      };      
    };

    obj_system(string n,string i){
      name=n;
      stringstream aux; aux<<i;
      aux>>ID;
    }

    void set_data(string n,string i){
      name=n;
      stringstream aux; aux<<i;
      aux>>ID;
    }
    
    string get_ID(){return (string)(ID);}
    
    string get_name(){return (string)(name);}

    string get_text()const{
      stringstream aux;
      aux<<"Name: "<<name<<"\nID: "<<ID<<"\n";
      return aux.str();
    };
    
    void print_text()const{cout<<get_text()<<endl;}


};

#endif

