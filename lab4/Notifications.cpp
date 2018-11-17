// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: October 5, 2018

#include "Notifications.h"

namespace w4 {
Notifications::Notifications() {
   message = nullptr;
   size = 0;
}

Notifications::Notifications(const Notifications& rhs) {
   this->message = nullptr;
   *this = rhs;
}

Notifications& Notifications::operator=(const Notifications& rhs) {
   if (this != &rhs) {
      delete [] message;
      message = new Message[rhs.size];
      size = rhs.size;
      for (size_t i = 0; i < size; i++) {
         message[i] = rhs.message[i];
      }
   }
   return *this;
}

Notifications::Notifications(Notifications&& rhs) {
   *this = std::move(rhs);
}

Notifications&& Notifications::operator=(Notifications&& rhs) {
   if (this != &rhs) {
      message = rhs.message;
      size = rhs.size;
      rhs.message = nullptr;
      rhs.size = 0;
   }
   return std::move(*this);
}

Notifications::~Notifications() {
   delete [] message;
}

void Notifications::operator+=(const Message& msg) {
   if (size < 10) {
      Message* tmp;
      tmp = new Message[size+1];
      if (message != nullptr) {
         for (size_t i = 0; i < size; i++) {
            if (message[i].empty() == false) {
               tmp[i] = message[i];
            }
         }
         delete[] message;
      }
      
      message = new Message[size+1]; 
      tmp[size] = msg;
      size++;
      for (size_t i = 0; i < size; i++) {
         message[i] = tmp[i];
      }
      delete [] tmp;
   }
}

void Notifications::display(std::ostream& os) const {
   for (size_t i = 0; i < size; i++) {
      message[i].display(os);
   }
}
}