#ifndef USER_H
#define USER_H

#include <unordered_map>
#include <vector>
#include "archive.h"


namespace Consumer { //start of consumer namespace

 struct Receipt 
 {
    int qty;
    double price;
    double cash;
    double tax;
    double total;
    std::string title;
 };

 class User 
 {
    private:
      std::unordered_map<std::string, std::vector<Receipt> > user;
      std::vector<Receipt> records;
      std::string name;
      double cash;
      bool buy(Book& entry);        //archive here to store values
      bool ismap_filled(const std::string& msg, std::unordered_map
                             <std::string, std::vector<Receipt> >::iterator& eu);
                       

    public:
        //modifying functions
        User();
        void wallet(void);
        void find(Archive& arch);

        //non modifying functions
        void get_balance(void);
        void history(void);
        void recent(void);

 };     

//overload operators
std::ostream& operator <<(std::ostream& os, Receipt& rcpt);


} //end of Consumer namespace

#endif
