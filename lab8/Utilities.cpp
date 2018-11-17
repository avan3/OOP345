// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: November 13, 2018

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
      for (size_t i = 0; i < desc.size(); i++) {
         for (size_t j = 0; j < price.size(); j++) {
            if (desc[i].code == price[j].code) {
               Product* ptr = new Product(desc[i].desc, price[j].price);
               ptr->validate();
               priceList += std::move(ptr);
               delete ptr;
            }
         }
      }
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
      for (size_t i = 0; i < desc.size(); i++) {
         for (size_t j = 0; j < price.size(); j++) {
            if (desc[i].code == price[j].code) {
               std::unique_ptr<Product> ptr(new Product(desc[i].desc, price[j].price));
               ptr->validate();
               priceList += std::move(ptr);
            }
         }
      }

		return priceList;
	}
}