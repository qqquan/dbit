#include <iostream>
#include <stdint.h>
#include <bitset>

using namespace std;
int main()
{
  auto cpp_ver = __cplusplus;

  cout << "Hello Cpp! \n";
  cout << "C++ version number: " << cpp_ver << '\n';


  constexpr auto bit_length = 32u;
  bitset<bit_length>data {0x05a0af};

  cout << "data = " << hex << data.to_ulong() << endl;
  cout << "Binary: " << data << endl;

  for(auto i=0u; i < bit_length; i++ )
  {
    cout << " bit " << dec<< i<< ": " << data[i] << endl;
  }

}