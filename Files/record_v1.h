
#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "obj_system.h"
#include "product.h"

using namespace std;

class record : public obj_system{
  protected:
    vector<product> product_list;
    
  public:
    record();
    record(string f);
    void print_products();
    void save_products(string file);
    void load_products(string file);
};

record::record():obj_system(){
  load_products("file.txt");
  print_products();
}

record::record(string f):obj_system(){
  load_products(f);
  print_products();
}

void record::print_products(){
  for(int i=0;i<product_list.size();i++){
    product_list[i].print_text();
  };
}

void record::save_products(string file){
  fstream database;
  database.open(file, ios::out);
  for(int i=0;i<product_list.size();i++){
    database<<product_list[i].get_text();
  };
  database.close();
}

void record::load_products(string file){
  fstream database;
  database.open(file, ios::in);
  string str[500];
  int n=0,i=0;
  while(getline(database, str[n])){n++;}
  n=(n-n%4)/4;
  for (i=0;i<n;i++){
    string a,b,c,d;
    a=str[i*4].substr(6);
    b=str[i*4+1].substr(4);
    c=str[i*4+2].substr(8);
    d=str[i*4+3].substr(10);
    product_list.resize(i+1);
    product_list[i]=product(a,b,c,d);
  }
  database.close();
}

#endif