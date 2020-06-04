
#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <fstream>

#include "product.h"

using namespace std;

class record : public obj_system{
  protected:
    product *product_list;
    int list_size=0;
    
  public:
    ~record();
    record();
    record(string);
    record(string,string,string);
    
    void load_products(string file_name_);
    void print_products()const;
    void save_products(string file_name_)const;
    
    bool verify_name_existance(string)const;
    bool verify_id_existance(string)const;
    
    void add_product();
    void add_product(string,string,string,string);

    void modify_quantity_id(string,float);
    void modify_quantity_name(string,float);
};

record::~record(){
  delete[] product_list;product_list=NULL;
  cout<<"deleted record object"<<endl;
};

record::record():obj_system(){
  load_products("file.txt");
  print_products();
}

record::record(string file_name_):obj_system(){
  load_products(file_name_);
  print_products();
}

record::record(string file_name_, string name_, string id_):obj_system(name_,id_){
  load_products(file_name_);
  print_products();
}

void record::load_products(string file_name_){
  string *temp_str=new string[4];
  int n,i;i=n=0;

  fstream database;
  database.open(file_name_, ios::in);
  while(getline(database, *temp_str)){list_size++;}
  database.close();
  list_size=list_size/4;
  

  product_list=new product[list_size];
  database.open(file_name_, ios::in);
  while(getline(database, temp_str[n%4])){
    if(n%4==3){
      product_list[i]=product(
        temp_str[0].substr(6),
        temp_str[1].substr(4),
        temp_str[2].substr(8),
        temp_str[3].substr(10));
      i++;
    }
    n++;
  }

  delete[]temp_str;temp_str=NULL;
  database.close();
}

void record::print_products()const{
  for(int i=0;i<list_size;i++){
    product_list[i].print_text();
  }
}

void record::save_products(string file)const{
  fstream database;
  database.open(file, ios::out);

  for(int i=0;i<list_size;i++){
    database<<product_list[i].get_text();
    if(i<list_size-1){database<<endl;}
  }

  database.close();
}

bool record::verify_name_existance(string name_)const{
  // For future changes
  bool existance=false;
  for (int i=0;i<list_size;i++){
    if(product_list[i].get_name()==name_){
      existance=true;
    }
  }
  return existance;
}

bool record::verify_id_existance(string id_)const{
  // For future changes
  bool existance=false;
  for (int i=0;i<list_size;i++){
    if(product_list[i].get_id()==id_){
      existance=true;
    }
  }
  return existance;
}

void record::add_product(){
  // For future changes
  bool test=true,run=true;
  string name_,id_;
  float quantity_,price_;

  cout<<endl<<endl;
  cout<<"\nEnter new product's Name: ";
  getline(cin,name_);
  

  while (verify_name_existance(name_) && run){
    cout<<"Please enter a product name that has not been used... or enter '-1' to exit: ";
    getline(cin,name_);
    run=(name_=="-1")?false:true;
  }

  if(run){
    cout<<"\nEnter new product's id code: ";
    getline(cin,id_);
  }

  while (verify_id_existance(id_) && run){
    cout<<"Please enter an identification code that has not been used... or enter '-1' to exit: ";
    getline(cin,id_);
    run=(id_=="-1")?false:true;
  }

  if(run){
    cout<<"\nEnter new product's amount: ";
    cin>>quantity_;
  }

  while (quantity_<0 && run){
    cout<<"Please enter a nonnegative real number for product's amount... or enter '-1' to exit: ";
    cin>>quantity_;
    run=(quantity_==-1)?false:true;
  }

  if(run){
    cout<<"\nEnter new product's price_: ";
    cin>>price_;
  }

  while (price_<0 && run){
    cout<<"Please enter a nonnegative real number for product's price... or enter '-1' to exit: ";
    cin>>price_;
    run=(price_==((float)(-1)))?false:true;
  }
  if(run){
    add_product(name_,id_,to_string(price_),to_string(quantity_));
  }
}

void record::add_product(string name_,string id_, string price_, string quantity_){
  if ( !( verify_name_existance(name_) || verify_id_existance(id_) ) ){
    list_size++;
    product *aux_pl=new product[list_size];
    for (int i=0;i<(list_size-1);i++){
      aux_pl[i]=product_list[i];
    }
    product_list=aux_pl;
    aux_pl=NULL;
    product_list[list_size-1]=product(name_,id_,price_,quantity_);
    
  }else{
    if (verify_id_existance(id_) && verify_name_existance(name_)){
      cout<<"This exact product already exist in the database..."<<endl<<endl;
    }else{
      if (verify_name_existance(name_)){
        cout<<"This product name already exist, try another..."<<endl<<endl;
      }else {
        cout<<"This id code already exist, try another..."<<endl<<endl;
      }
    }
  }
}

void record::modify_quantity_id(string id_,float modifier_){
  if(verify_id_existance(id_)){
    for(int i =0;i<list_size;i++){
      if(product_list[i].get_id()==id_){
        product_list[i].modify_quantity(modifier_);
      }
    }
  }else{
    cout<<"There isn't a product with such id code..."<<endl<<endl;
  }
}


void record::modify_quantity_name(string name_,float modifier_){
  if(verify_name_existance(name_)){
    for(int i =0;i<list_size;i++){
      if(product_list[i].get_name()==name_){
        product_list[i].modify_quantity(modifier_);
      }
    }
  }else{
    cout<<"There isn't a product with such name..."<<endl<<endl;
  }
}

#endif