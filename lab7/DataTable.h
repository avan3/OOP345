// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: November 8, 2018

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <fstream>

namespace w7 {
   template <class T>
   class DataTable {
      private:
         std::vector<T>xVal;
         std::vector<T>yVal;
         size_t widthField;
         size_t numDec;
      public:
         DataTable() : xVal{0}, yVal{0} {};
         DataTable(std::ifstream& fin, size_t fieldWidth, size_t decimals) {
            T tmpX, tmpY;
            widthField = fieldWidth;
            numDec = decimals;
            while (fin >> tmpX && fin >> tmpY) {
               xVal.push_back(tmpX);
               yVal.push_back(tmpY);
            }
         };

         T mean() const{
            return std::accumulate(yVal.begin(), yVal.end(), (T)0) / yVal.size();
         };

         T sigma() const {
            T upper = std::accumulate(yVal.begin(), yVal.end(), (T)0, [=] (T A, T B) { return A + pow(B - mean(), 2);});
            T stddev = sqrt(upper / (getSize() - 1));
            return stddev;
         };

         T median() const{
            std::vector<T> tmp = yVal;
            std::sort(tmp.begin(), tmp.end());
            int mid = tmp.size()/2;
            return tmp[mid];
         };  

         void regression(T& slope, T& y_intercept) const {
            T sumX = std::accumulate(xVal.begin(), xVal.end(), (T)0);
            T sumY = std::accumulate(yVal.begin(), yVal.end(), (T)0);
            T prodXY = std::inner_product(xVal.begin(), xVal.end(), yVal.begin(), (T)0, std::plus<T>(), [=] (T A, T B) {return getSize()*A*B;});
            T prodXX = std::inner_product(xVal.begin(), xVal.end(), xVal.begin(), (T)0, std::plus<T>(), [=] (T A, T B) {return getSize()*A*B;});
            
            slope = (prodXY - sumX*sumY) / (prodXX - sumX*sumX);
            y_intercept = (sumY - slope*sumX) / (getSize());
         };

         void display(std::ostream& os) const {
            os << std::setw(widthField) << "x" << std::setw(widthField) << "y" << std::endl;
            for (size_t i = 0; i < xVal.size(); i++) {
               os << std::fixed << std::setw(widthField) << std::setprecision(numDec) << xVal[i];
               os << std::fixed << std::setw(widthField) << std::setprecision(numDec) << yVal[i];
               os << std::endl;
            }
         };
         size_t getSize() const {
            return yVal.size();
         };
   };
   template <typename T> 
   std::ostream& operator<< (std::ostream& os, const DataTable<T>& rhs) {
      rhs.display(os);
      return os;
   }
}
#endif