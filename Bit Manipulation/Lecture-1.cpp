// Count Set Bits - Brian and Kerningham Algorithm
#include <bits/stdc++.h>
using namespace std;

unsigned int countSetBits(int n)
{
   unsigned int count = 0;
   while (n)
   {
      n &= (n - 1);
      count++;
   }
   return count;
}

/*

//Using Look Up Table

int table[256];

// recursive function to count set bits
void initialize()
{

   // To initially generate the table algorithmically:
   table[0] = 0;
   for (int i = 0; i < 256; i++)
   {
      table[i] = (i & 1) + table[i / 2];
   }
}

int countSetBits(int n)
{
   return table[n & 0xff] +
          table[(n >> 8) & 0xff] +
          table[(n >> 16) & 0xff] +
          table[n >> 24];
}
*/

/*
   Using Right Shift Operator
   void countSetBits(int n){
      int count = 0;
      while(n){
         if(n&1)
            count++;
         n >>= 1;
      }
      cout<<count;
   }
*/

int main()
{
   int i = 9;
   cout << countSetBits(i);
   return 0;
}
