// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: October 30, 2018

#include <string>
#include <sstream>
#include "ProdUtil.h"
#include "Product.h"
#include "TaxableProduct.h"

namespace w6 {
   std::ostream& operator<<(std::ostream& os, const iProduct& p) {
      p.display(os);
      os << std::endl;
      return os;
   }

   iProduct* readProduct(std::ifstream& fin) {
         long pcTmp;
         double prTmp;
         char tTmp;
         std::string temp;
         std::getline(fin, temp);
         if (temp == "\0") {
            throw nullptr;
         }
         else if (temp.find('M') == 12 || temp.find('C') == 12) {
            throw std::string("Unrecognizable Tax Code!");
         }
         else {
            std::istringstream iss(temp);
            iss >> pcTmp; // First field is product code
            iss >> prTmp; // Second field is price
            if (temp.find('H') == 12 || temp.find('P') == 12) {
               iss >> tTmp;
               iProduct* tmp = new TaxableProduct(pcTmp, prTmp, tTmp);
               return tmp;
            }
         }
      iProduct* tmp = new Product(pcTmp, prTmp);
      return tmp;
   }     
}