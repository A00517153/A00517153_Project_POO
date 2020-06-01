#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <fstream>

#include "product_v2.h"

using namespace std;

class record : public obj_system{
  protected:
    product *product_list=new product[1];
    int *list_size=new int[1];
    
  public:
    ~record();
    record();
    record(string);
    record(string,string,string);
    void load_products(string file);
    void print_products();
    void save_products(string file);
    
};

record::~record(){
  delete[] product_list;product_list=NULL;
  delete[] list_size;list_size=NULL;
};

record::record():obj_system(){
  load_products("file.txt");
  print_products();
}

record::record(string f):obj_system(){
  load_products(f);
  print_products();
}

record::record(string name, string id, string file_name):obj_system(name,id){
  load_products(file_name);
  print_products();
}

void record::load_products(string file){
  delete [] product_list; product_list=NULL;
  delete [] list_size; list_size=NULL;
  string *temp_str=new string[5];
  int *n=new int;
  int *i=new int;

  fstream database;
  database.open(file, ios::in);

  while(getline(database, *temp_str)){*list_size++;}

  *list_size=*list_size/4;

  product_list=new product[*list_size];
  while(getline(database, *temp_str)){
    temp_str[*i%4+1]=*temp_str;
    if((*n)%4==3){
      product_list[*i]=product(temp_str[1],temp_str[2],temp_str[3],temp_str[4]);
      *i++;
    }
    *n++;
  }
  delete[]n;n=NULL;
  delete[]i;i=NULL;
  delete[]temp_str;temp_str=NULL;
  database.close();
}

void record::print_products(){
  int *i=new int;
  for(*i<*list_size;*i++;){
    product_list[*i].print_text();
  }
  delete [] i; i=NULL;
}

void record::save_products(string file){
  int *i=new int;

  fstream database;
  database.open(file, ios::out);

  for(i<list_size;*i++;){
    database<<product_list[*i].get_text();
  }

  database.close();
  delete [] i; i=NULL;
}


#endif