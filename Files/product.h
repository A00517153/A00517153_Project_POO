#ifndef PRODUCT_H
#define PRODUCT_H

#include "general.h"

#include <cmath>
#include <sstream>

using namespace std;

class product:public general{
  protected:
    string id;
    float price,amount;

  public:
    product();
    product(string,string,float,float);

    void set_name(string);
    void set_price(float);
    void modif_amount(float);

    string get_id() const;
    float get_price() const;
    float get_amount() const;

    string to_string() const;
    string get_data() const;
};


product::product()
  :general(),id("00000000000000000"),price(0.0),amount(0.0){}

product::product(string name_, string id_, float price_, float amount_):
  general(name_),id(id_),price(price_),amount(amount_){}

void product::set_name(string name_){
  name=name_;
}

void product::set_price(float price_){price=price_;}

void product::modif_amount(float amount_){
  if(amount_>=0 || (amount+amount_)>(-1e-8)){
    amount+=amount_;
  } else {
    cout<<"There's not enough product to do this operation.\n";
  }
}

string product::get_id() const{return id;}
float product::get_price() const{return price;}
float product::get_amount() const{return amount;};

string product::to_string() const{
  stringstream aux;
  aux<<"\nName: "<<name
      <<"\nID: "<<id
      <<"\nPrice: $"<<price
      <<"\nAmount: "<<amount;
  return aux.str();
}

string product::get_data() const{
  stringstream aux;
  aux<<"\n"<<name<<","<<id<<","<<price<<","<<amount;
  return aux.str();
}


#endif