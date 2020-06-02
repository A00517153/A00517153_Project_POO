
#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <fstream>

#include "product_v1.h"

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
  }

  database.close();
}


#endif