#ifndef RECORD_H
#define RECORD_H

#include "product.h"

using namespace std;

class record:public general{
  protected:
    product *p_list=new product[0];
    int pl_size=0;
    
  public:
    ~record();
    record();
    record(string);

    bool verif_existance(string)const;
    product* get_product(string);

    virtual string to_string() const=0;
    virtual string get_data() const=0;

};
record::~record(){
  delete[]p_list;p_list=NULL;
}

record::record():general("NONAME"){}

record::record(string name_):general(name_){}

bool record::verif_existance(string data_) const {
  
  for(int i=0;i<pl_size;i++){
    if(p_list[i].get_name()==data_ || p_list[i].get_id()==data_){
      return true;
    }
  }
  return false;
}

product* record::get_product(string info_){
  product *auxp=NULL;
  if (verif_existance(info_)){
    bool auxbool=true;
    for(int i=0;i<pl_size;i++){
      if (auxbool && (p_list[i].get_name()==info_ || p_list[i].get_id()==info_)){
        auxp=p_list+i;
        auxbool=false;
        return auxp;
      }
    }
  }
  cout<<"\nThere is no product with such data.\n";
  return auxp;
}

#endif

