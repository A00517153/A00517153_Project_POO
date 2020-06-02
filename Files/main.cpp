#include <iostream>
#include <string>

#include "record_v1.h"

using namespace std;
const string datafile_input_name="databasefile.txt";
const string datafile_output_name="databasefile.txt";


int main(){
  //system("clear");
  
  record r1(datafile_input_name);
  r1.save_products(datafile_output_name);
  cout<<"FINISH"<<endl;
  return 0;
}