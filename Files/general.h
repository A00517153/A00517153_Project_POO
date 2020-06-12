#ifndef GENERAL_H
#define GENERAL_H

using namespace std;

class general{
  protected:
    string name;

  public:
    general();
    general(string);
    string get_name() const;    
    virtual string to_string() const=0;
    virtual string get_data() const=0;

};

general::general():name("NONAME"){
  //Open to changes
}

general::general(string name_):name(name_){
  //Open to changes
}

string general::get_name() const{
  return name;
}


#endif

