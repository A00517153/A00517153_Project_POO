
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <sstream>

#include "obj_system_v2.h"

using namespace std;

class product : public obj_system{
  protected:
    float *price=new float[1];
    float *quantity=new float[1];
  public:
    ~product(){
      delete [] price;price = NULL;
      delete [] quantity;quantity = NULL;
    };
    product();
    product(string,string,string,string);
    void set_data(string, string, string, string)
    float get_price() const;
    float get_quantity()const;
    string get_text()const;
    void print_text()const;
    
};



#endif