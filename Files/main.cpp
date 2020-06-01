#include <iostream>
#include <string>

#include "record_v2.h"

using namespace std;


int main(){
  /*system("clear");
  string datafile_input_name="databasefile.txt";
  string datafile_output_name="databasefile.txt";
  
  //obj_system sys1;
  //product prd1;
  record r1(datafile_input_name);
  r1.save_products(datafile_output_name);
  *//*
  list <obj_system> obj_list;
  cout<<obj_list.size()<<endl;
  obj_system test("object test","012345678901");
  obj_list.resize(40000);
  
  obj_system *p;
  p=obj_list.get_allocator().allocate(obj_list.size());

  cout<<obj_list.size()<<endl;
  
  for (int i=0; i<obj_list.size();i++){p[i]=test;}
  for (int i=0; i<20;i++){p[i].print_text();}

  system("echo '\n\n\tRun over . . .'");
  return 0;
  delete p;*/
  
  cout<<sizeof(record)<<endl;
  return 0;
}