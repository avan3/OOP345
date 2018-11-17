// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: October 30, 2018

#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H

#include "Product.h"

namespace w6 {
   class TaxableProduct : public Product {
   private:
      char taxCode;
      static double taxArr[];
   public:
      TaxableProduct(long pcTmp, double prTmp, char tTmp) : Product(pcTmp, prTmp), taxCode{tTmp} {};
      double getPrice() const;
      void display(std::ostream&) const;
   };
}
#endif