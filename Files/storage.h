#ifndef STORAGE_H
#define STORAGE_H

#include "record.h"

#include <fstream>

using namespace std;

enum config_Type {PRICE=1,AMOUNT};

class storage:public record{
  protected:
    // No new variables.
  public:
    storage();
    storage(string);

    bool verif_existance(string,string)const;
    bool verif_existance(string)const;
    void add_product(string,string,float,float);

    void import_data(string);
    
    bool modif_data(int,product*,float);
    bool modif_data(int,string,float);

    string to_string() const;
    string get_data() const;

    void save_data(string) const;

};

storage::storage():record(){}

storage::storage(string name_):record(name_){}

bool storage::verif_existance(string name_, string id_) const{
  bool exist_name=false,exist_id=false;

  for (int i=0;i<pl_size;i++){
    if (p_list[i].get_name()==name_ && !exist_name){
      exist_name=true;
      if (name_!=id_){
        cout<<"The name '"<<name_<<"' already exists.\n"; 
      }
    }
    if (p_list[i].get_id()==id_ && !exist_id){
      exist_id=true;
      if (name_!=id_){
        cout<<"The id '"<<id_<<"' already exists.\n";
      }
    }
  }
  bool existance=(exist_name || exist_id)? true:false;
  return existance;
}

bool storage::verif_existance(string data_) const {
  if(!record::verif_existance(data_)){

  cout<<"\nThere is no product with such data.\n";
  return false;
  }
  return true;
}

void storage::add_product(string name_, string id_, float price_, float amount_){
  if (!verif_existance(name_,id_)){
    product *temp_p_list=new product[pl_size+1];
    for (int i=0;i<pl_size;i++){
      temp_p_list[i]=p_list[i];
    }
    pl_size++;
    delete [] p_list;
    p_list=temp_p_list;
    temp_p_list=NULL;
    
    p_list[pl_size-1]=product(name_,id_,price_,amount_);
  }
}

void storage::import_data(string filename){
  fstream database;
  database.open(filename, ios::in);
  bool check=false;

  string line,name_,id_,tempstr;
  float price_,amount_;
  while(getline(database,line)){
    if(check){
      stringstream ss(line);
      getline(ss,name_,',');
      getline(ss,id_,',');
      getline(ss,tempstr,',');
      price_=stof(tempstr);
      getline(ss,tempstr,',');
      amount_=stof(tempstr);
      add_product(name_,id_,price_,amount_);
    } else {
      check=true;
    }
  }

  database.close();
}

bool storage::modif_data(int conf_, product *pr_, float modif_){
  // 1. Change Price.
  // 2. Modif Amount.
  if (pr_!=NULL){
    if(conf_==PRICE){
      pr_->set_price(modif_);
      return true;
    } else{
      if (conf_==AMOUNT){
        pr_->modif_amount(modif_);
        return true;
      }
    }
  }
  return false;
}

bool storage::modif_data(int conf_, string data_, float modif_){
  product *pr=NULL;
  pr=get_product(data_);
  return modif_data(conf_,pr,modif_);
}

string storage::to_string() const{
  stringstream aux;
  for (int i=0; i<pl_size;i++){
    aux<<p_list[i].to_string()<<endl;
  }
  return aux.str();
}

string storage::get_data() const{
  stringstream aux;
  for (int i=0; i<pl_size;i++){
    aux<<p_list[i].get_data();
  }
  return aux.str();
}

void storage::save_data(string filename) const{
  fstream database;
  database.open(filename, ios::out);
  database<<"name,id,price,amount"<<get_data();

  database.close();
}

#endif

