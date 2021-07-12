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

  cout << "data = 0x" << hex << data.to_ulong() << endl;
  cout << "Binary: " << data << endl;

  string bit_str = data.to_string();
  for( auto itr = std::next(bit_str.begin(),4); itr != bit_str.end(); std::advance( itr, 5 ) )
  {
    // cout << "size before insert: " << dec <<bit_str.size() << endl;
    // cout << "iterator index before insert: " <<dec << itr - bit_str.begin() << endl;
    itr = bit_str.insert(itr, ' ');
    // cout << "size after insert: " << dec << bit_str.size() << endl;
    // cout << "iterator index after insert: " <<dec << itr - bit_str.begin() << endl;
    // cout<<"debug:  spaced bin: " << bit_str << endl;
  }
  // auto itr = bit_str.begin()+4;
  // bit_str.insert(itr, ' ');
  cout << "Spaced Binary: " << bit_str << endl;

  for(size_t i=0u; i < data.size(); i++ )
  {
    cout << " bit " << dec<< i<< ": " << data[i] << endl;
  }

}