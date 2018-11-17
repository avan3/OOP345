// Name: Andrew Van
// Student Number: 141267179
// Section Code: SFF
// Date: Sept 27, 2018
// Lab Number: 3
// Email: avan3@myseneca.ca

#ifndef PAIR_H
#define PAIR_H

template <class A, class B>
class Pair {
private:
   A first;
   B second;
public:
   // No argument constructor 
   Pair() : first{}, second{} {}

   // Two argument constructor sets the data members to arguments
   Pair(const A& one, const B& two) {
      first = one;
      second = two;
   }

   // Query returns first variable
   const A& getKey() const {
      return first;
   }

   // Query returns second variable
   const B& getValue() const {
      return second;
   }
};

#endif