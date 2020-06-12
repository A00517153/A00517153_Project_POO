#include <iostream>
#include <string>
#include <unistd.h>

#include "bill.h"

using namespace std;

const string datafile="save.csv";
const string lastticket="./TicketData/ticket.csv";
const string historytickets="./TicketData/history.csv";

enum recordType {RECORD,STORAGE,BILL};



int main(){
  while(true){
    break;
  }
  storage a("T1");
  a.import_data(datafile);
  a.save_data(datafile);

  cout<<a.to_string()<<endl;

  bill billy("WILLIAM SHAKESPEAR");
  billy.add_product(a, "OBJ1", 3);
  billy.add_product(a, "OBJ3", 5);
  billy.add_product(a, "OBJ2", 9);

  billy.save_data(lastticket, historytickets);
}