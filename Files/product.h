
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <sstream>

#include "obj_system.h"

using namespace std;

class product : public obj_system{
  protected:
    float price=0,quantity=0;
  public:
    product();
    product(string,string,string,string);

    void set_price(string);
    void set_quantity(string);
    void set_data(string,string,string,string);

    float get_price() const;
    float get_quantity() const;
    string get_text() const;

    void print_text() const;

    bool check_avariability(float)const;
    bool modify_quantity(float);
};

product::product():obj_system(){
  // For future changes
}

product::product(string name_,string id_,string price_,string quantity_):obj_system(){
  set_data(name_,id_,price_, quantity_);
}

void product::set_price(string price_){
  price=stof(price_);
}

void product::set_quantity(string quantity_){
  quantity=stof(quantity_);
}

void product::set_data(string name_,string id_,string price_,string quantity_){
  obj_system::set_data(name_, id_);
  set_price(price_);
  set_quantity(quantity_);
}

float product::get_price() const {return price;}

float product::get_quantity() const {return quantity;}

string product::get_text() const {
  stringstream aux;
  aux<<obj_system::get_text()<<"Price: $"<<price<<"\nQuantity: "<<quantity;
  return aux.str();
}

void product::print_text() const {cout<<get_text()<<endl<<endl;}

bool product::check_avariability(float amount_)const{
  if (amount_<0){
    return (quantity>=(-amount_))?true:false;
  } else {
    return true; 
  }
  return (quantity>amount_)?true:false;
}

bool product::modify_quantity(float modifier_){
  if(check_avariability(modifier_)){
    quantity+=modifier_;
    return true;
  }else{
    cout<<"There is not enough product to do that"<<endl<<endl;
    return false;
  }
}
#endif