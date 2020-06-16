#include <iostream>
#include <string>
#include <unistd.h>

#include "bill.h"

using namespace std;

const string datafile="save.csv";
const string lastticket="./TicketData/ticket.csv";
const string historytickets="./TicketData/history.csv";

enum recordType {RECORD,STORAGE,BILL};

void menu4(storage &s,bill &b){
  string data;
  float a;
  getline(cin,data);
  cout<<"Enter the name or id that you want to add to the transaction: ";
  getline(cin,data);
  cout<<"\nEnter the amount to add to the transaction: ";
  cin>>a;
  b.add_product(s, data, a);
}

void menu3(storage &s){
  bool run=true;
  int menu=0;
  string cname;
  getline(cin,cname);
  cout<<"\nEnter the customer's name: ";
  getline(cin,cname);
  bill b(cname);
  while(run){
    //cin>>cname;
    cout<<"\nWhat do you want to do with this transaction?";
    cout<<"\n\t1.- View all actual sold products."; // Let the program run
    cout<<"\n\t2.- Add a operation."; // Send the user to menu4
    cout<<"\n\t3.- Check actual total balance."; // Let the program run
    cout<<"\n\t4.- View all recorded storage products."; // Let the program run
    cout<<"\n\t0.- Finish transaction."; // Finish the transaction seccion.
    cout<<"\nSelection: ";
    cin>>menu;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    switch(menu){
      case 1:
        cout<<b.get_data()<<endl;
        break;
      case 2:
        menu4(s,b);
        break;
      case 3:
        cout<<"Actual Balance: "<<b.get_balance()<<endl;;
        break;
      case 4:
        cout<<s.to_string()<<endl;
        break;
      case 0:
        run=false;
      default:
        break;
    }
  }
  b.save_data(lastticket, historytickets);

}

void menu2(storage &s){
  string data;
  int menu;
  getline(cin,data);
  cout<<"Enter the name or id of the product: ";
  getline(cin,data);
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  if(s.verif_existance(data)){
    product *temp;
    temp=s.get_product(data);
    cout<<"This product does exist. Do you want to modify a value?\n";
    cout<<"\t0.- No.\n";
    cout<<"\t1.- Yes.\n";
    cout<<"Selection: ";
    cin>>menu;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    if(menu==1){
      cout<<temp->to_string()<<endl;
      cout<<"What do you want to change?:\n";
      cout<<"\t1.- Name.\n";
      cout<<"\t2.- Price.\n";
      cout<<"\t3.- Amount.\n";
      cout<<"\t0.- Cancel.\n";
      cout<<"Selection: ";
      cin>>menu;
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
      string data2;
      switch(menu){
        case 1:
          cout<<"New name: ";
          getline(cin, data2);
          temp->set_name(data2);
          break;
        case 2:
          float aux;
          cout<<"New price: ";
          cin>>aux;
          s.modif_data(PRICE, temp, aux);
          break;
        case 3:
          float aux2;
          cout<<"New amount: ";
          cin>>aux2;
          s.modif_data(AMOUNT, data, aux2);
          break;
        default:
          break;
      }
    }
  }
}

void menu1(storage &s){
  string n,i;
  float p,a;
  int menu;
  cout<<"\nName of the new product: ";
  getline(cin,n);
  getline(cin,n);
  cout<<"Id of the new product: ";
  getline(cin,i);
  cout<<"Price of the new product: ";
  cin>>p;
  cout<<"Amount of the new product: ";
  cin>>a;
  product aux(n,i,p,a);
  cout<<aux.to_string();
  cout<<"\nWhat do you want to do?\n";
  cout<<"\t0.- Return to main menu without saving.\n";
  cout<<"\t1.- Save.\n";
  cout<<"\t2.- Modify.\n";
  cout<<"Selection: ";
  cin>>menu;
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  switch(menu){
    case 1:
      s.add_product(n,i,p,a);
      break;
    case 2:
      menu1(s);
      break;
    default:
      break;
  }
}

void menu0(bool &r,storage &s){
  string test;
  int menu=0;
  
  cout<<"\nWhat do you want to do now?";
  cout<<"\n\t1.- View all recorded products."; // Let the program run
  cout<<"\n\t2.- Add a new product to the record."; // Send the user to menu1
  cout<<"\n\t3.- Search for an existing product."; // Send the user to menu2
  cout<<"\n\t4.- New Sell transaction."; // Send the user to menu 3
  cout<<"\n\t0.- Exit program and save changes."; // Exits the program.
  cout<<"\nSelection: ";
  cin>>menu;
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  switch(menu){
    case 1:
      cout<<s.to_string()<<endl;
      break;
    case 2:
      menu1(s);
      break;
    case 3:
      menu2(s);
      break;
    case 4:
      menu3(s);
      break;
    default:
      r=false;
  }
}



int main(){
  bool run=true;
  cout<<"System Booted...\nPress double enter to start..."<<endl;
  storage a("T1");
  a.import_data(datafile);
  
  while(run){
    menu0(run,a);
  }
  a.save_data(datafile);
}