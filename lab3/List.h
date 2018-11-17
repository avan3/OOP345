// Name: Andrew Van
// Student Number: 141267179
// Section Code: SFF
// Date: Sept 27, 2018
// Lab Number: 3
// Email: avan3@myseneca.ca

#ifndef LIST_H
#define LIST_H

template <class T, int N>
class List {
private:
   T arr[N];
   size_t counter;
public:
   // No argument constructor sets object to empty state
   List() {
      counter = 0;
      *arr = {};
   }

   // Query to return number of entries in array
   size_t size() const {
      return counter;
   }

   // Operator that returns the array at the index
   const T& operator[](int index) const {
      return arr[index];
   }

   // Operator that adds to array if space is available
   void operator+=(const T& element) {
      if (counter < N) { // Check if counter is less than total size of array
         arr[counter] = element;
         ++counter;
      }
   }
};
#endif