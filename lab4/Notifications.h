// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: October 5, 2018

#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <iostream>
#include "Message.h"

namespace w4 {
class Notifications {
private:
   Message* message;
   size_t size;
public:
   Notifications(); // Set empty state
   Notifications(const Notifications&); // Copy Constructor
   Notifications& operator=(const Notifications&); // Copy assignment 
   Notifications(Notifications&&); // Move Constructor
   Notifications&& operator=(Notifications&&); // Move asssignment
   ~Notifications(); // Destructor
   void operator+=(const Message& msg); // Adds message to set
   void display(std::ostream& os) const; // Display function
};
}
#endif // !NOTIFICATIONS_H