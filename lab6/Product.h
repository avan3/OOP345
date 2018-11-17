// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: October 30, 2018

#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H

#include <iomanip>
#include "iProduct.h"

namespace w6 {
   class Product : public iProduct {
      private:
         long prodCode;
         double price;
      public:
         Product(long pc, double pr) : prodCode{pc}, price{pr} {};
         double getPrice() const;
         void display(std::ostream&) const;
   };
}
#endif