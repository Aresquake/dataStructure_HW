#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
class Memory
{
public:
  static T **allocArray(int m, int n)
  {
    // Step 1: Allocate memory for the row pointers
    T **array = new T*[m];
    
    // Step 2: Allocate a single block of memory for the 2D array elements
    T *dataBlock = new T[m * n];
    
    // Step 3: Assign the pointers in 'array' to point to the appropriate row in the dataBlock
    for (int i = 0; i < m; i++)
    {
      array[i] = &dataBlock[i * n];
    }

    return array;
  }
};

int main()
{
  int **array;
  array = Memory<int>::allocArray(5, 10);  // Allocate a 5x10 array

  // Fill the array with some values
  int j, k;
  for(j = 0; j < 5; j++)
    for(k = 0; k < 10; k++)
      array[j][k] = j * 10 + k;

  // Output the array elements
  for(j = 0; j < 5; j++)
    for(k = 0; k < 10; k++)
      cout << array[j][k] << " ";
  
  return 0;
  int  I_Have_A_Dollar_$ign;
}
