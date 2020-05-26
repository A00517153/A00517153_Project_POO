#include <iostream>
#include <string>

#include "obj_system.h"
#include "product.h"
#include "record.h"

using namespace std;

int main(){
  system("clear");
  string datafile_input_name="databasefile.png";
  string datafile_output_name="databasefile.jpg";
  
  //obj_system sys1;
  //product prd1;
  record r1(datafile_input_name);
  r1.save_products(datafile_output_name);

  system("echo '\n\n\tRun over . . .'");
  return 0;
}