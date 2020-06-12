#ifndef BILL_H
#define BILL_H

#include "storage.h"

using namespace std;

tm* get_date(){
  time_t rawtime;
  struct tm* timeinfo;

  time(&rawtime);
  timeinfo=localtime(&rawtime);
  return timeinfo;
}

class bill:public storage{
  protected:
    float balance;
  public:
    bill();
    bill(string);

    bool verif_existance(string) const;

    void add_product(storage &,string,float);
    void calc_balance();

    float get_balance();

    string to_string();
    string get_data();

    void save_data(string,string);

};

bill::bill():storage(){}

bill::bill(string customername_):storage(customername_){}

bool bill::verif_existance(string data_)const{
  for(int i=0;i<pl_size;i++){
    if(p_list[i].get_name()==data_ || p_list[i].get_id()==data_){
      return true;
    }
  }
  return false; 
}

void bill::add_product(storage &storage_, string data_, float amount_){
  if(amount_>0){
    product *auxpr=NULL;
    if(storage_.modif_data(AMOUNT,data_,-amount_)){
      if(verif_existance(data_)){
        auxpr=get_product(data_);
        auxpr->modif_amount(amount_);
      } else {
        pl_size++;
        product *auxpr2=NULL,*temp_list=new product[pl_size];
        auxpr2=storage_.get_product(data_);

        for(int i=0;i<pl_size-1;i++){
          temp_list[i]=p_list[i];
        }
        temp_list[pl_size-1]=product(auxpr2->get_name(),auxpr2->get_id(),auxpr2->get_price(),amount_);
        delete[] p_list;p_list=temp_list;
        auxpr2=NULL;
        temp_list=NULL;
      }
    }
  }
}

void bill::calc_balance(){
  balance=0;
  for(int i=0;i<pl_size;i++){
    balance+=(p_list[i].get_price())*(p_list[i].get_amount());
  }
}

float bill::get_balance(){
  calc_balance();
  return balance;
}

string bill::to_string(){
  stringstream aux;
  aux<<"----------\nCustomer: "<<name;
  for(int i=0;i<pl_size;i++){
    aux<<p_list[i].to_string();
  }
  aux<<"TOTAL: $"<<get_balance()<<endl;
  return aux.str();
}

string bill::get_data(){
  stringstream aux;
  aux<<"Date,"<<asctime(get_date())<<endl;
  aux<<"Customer,"<<name;
  aux<<endl<<"Purchased Amount,Item Name,Cost Per Unit";
  for(int i=0;i<pl_size;i++){
    aux<<endl<<p_list[i].get_amount()<<","<<p_list[i].get_name()<<",$"<<p_list[i].get_price();
  }
  aux<<"\n,TOTAL,$"<<get_balance()<<endl;

  return aux.str();
}

void bill::save_data(string ticket_,string ticket_record_){
  fstream savefile;
  savefile.open(ticket_,ios::out);
  savefile<<get_data();
  savefile.close();

  savefile.open(ticket_record_,ios::in);

  stringstream auxsstr;
  string line;

  while(getline(savefile,line)){
    auxsstr<<line<<endl;
  }

  savefile.close();
  savefile.open(ticket_record_,ios::out);

  savefile<<auxsstr.str()<<"'----------------\n\n";
  savefile<<get_data();

  
  savefile.close();

}

#endif

