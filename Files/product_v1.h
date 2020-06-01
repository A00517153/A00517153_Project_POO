
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <sstream>

#include "obj_system.h"

using namespace std;

class product : public obj_system{
  protected:
    float price,quantity,quantity_sold;
  public:
    product():obj_system(){
      price=0.00;
      quantity=0.00;
    };

    product(string n,string i,string p,string q):obj_system(n,i){
      stringstream aux; aux<<p;
      aux>>price;
      stringstream aux2; aux2<<q;
      aux2>>quantity;
    }

    void set_data(string n,string i,string p,string q){
      obj_system::set_data(n,i);
      stringstream aux; aux<<p;
      aux>>price;
      stringstream aux2; aux2<<q;
      aux2>>quantity;
    }

    float get_price()const{return (float)(price);}

    float get_quantity()const{return (float)(quantity);}

    string get_text()const{
      stringstream aux;
      aux<<"Name: "<<name<<"\nID: "<<ID<<"\nPrice: $"<<price<<"\nQuantity: "<<quantity<<"\n";
      return aux.str();
    };
    
    void print_text()const{cout<<get_text()<<endl;}
};



#endif