
#include <iostream>

template<class T1>
class table
{
public:
   table(T1 a, T1 b) : row(a), colums(b) 
   {
       array = new T1*[row];

      for (T1 i = 0; i < row; ++i)
      {
         array[i] = new T1[colums];
      }
     
   };

   ~table()
   {
      for (T1 i = 0; i < row; ++i)
      {
         delete[] array[i];
      }
      delete[] array;
   }

   T1* operator[](T1 s)
   {
      if (s >= 0 || s < row)
         return array[s];
   }

  const T1* operator[](T1 s) const
   {
      if (s >= 0 || s < row)
         return array[s];
   }
private:
   T1 row{}, colums{};
   T1** array;
};

int main()
{
   auto test = table<int>(2, 3);
   test[0][0] = 4;
   std::cout << test[0][0]; 
   test[1][2] = 5;
   std::cout <<std::endl<< test[1][2];
}

