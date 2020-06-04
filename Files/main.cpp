#include <iostream>
#include <string>

#include "record.h"

using namespace std;
const string datafile_input_name="databasefile.txt";
const string datafile_output_name="databasefile.txt";
const string datafile_output_ticket="ticket.txt";


int main(){
  //system("clear");
  record r1(datafile_input_name);
  r1.add_product("Test Object 1","Undefined","9.99","6.9");
  r1.modify_quantity_name("Test Object 1", 10);
  r1.save_products(datafile_output_name);
  r1.print_products();
  cout<<"FINISH"<<endl;
  return 0;
}