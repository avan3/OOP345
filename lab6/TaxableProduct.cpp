// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: October 30, 2018

#include "TaxableProduct.h"

namespace w6 {
   double TaxableProduct::taxArr[] { 1.13, 1.08 };

   double TaxableProduct::getPrice() const {
      if (taxCode == 'H') {
         return Product::getPrice() * taxArr[0];
      }
      else if (taxCode == 'P') {
         return Product::getPrice() * taxArr[1];
      }
      return 0;
   }

   void TaxableProduct::display(std::ostream& os) const {
      Product::display(os);
      if (taxCode == 'H') {
         os << " HST";
      }
      else if (taxCode == 'P') {
         os << " PST";
      }
   }
}