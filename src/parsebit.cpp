#include <iostream>
#include <stdint.h>
#include <bitset>

#include <VariadicTable.h>

using namespace std;

void parse_bit32(uint32_t val)
{

  constexpr auto bit_length = 32u;
  
  bitset<bit_length>data {val};

  cout << "Decimal: " << dec << data.to_ulong() << endl;
  cout << "Hex: 0x" << hex << data.to_ulong() << endl;
  cout << "Binary: " << data << endl;

  string bit_str = data.to_string();
  for( auto itr = std::next(bit_str.begin(),4); itr != bit_str.end(); std::advance( itr, 5 ) )
  {

    itr = bit_str.insert(itr, ' ');

  }

  cout << "Spaced Binary: " << bit_str << endl;


  //build upper 16bit
  vector<std::string> vt_header16_31;

  for (int i = 15+16; i>=0+16; i--)
  {
    vt_header16_31.push_back("bit " + std::to_string(i) );
  }
  VariadicTable<int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int> vt_upper16(vt_header16_31);


  vt_upper16.addRow(data[15+16], data[14+16],data[13+16],data[12+16],data[11+16],data[10+16],data[9+16],data[8+16],data[7+16],data[6+16],data[5+16],data[4+16],data[3+16],data[2+16],data[1+16],data[0+16]);

  vt_upper16.print(std::cout);
  
  
  //build lower 16bit table
  vector<std::string> vt_header0_15;

  for (int i = 15; i>=0; i--)
  {
    std::string width_compen{};
    if (i<10)
    {
      width_compen.push_back(' '); //for single digit, add space to increase column width, compensating the limit in table template
    }
    vt_header0_15.push_back("bit " + width_compen + std::to_string(i));
  }
  VariadicTable<int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int> vt_lower16(vt_header0_15);


  vt_lower16.addRow(data[15], data[14],data[13],data[12],data[11],data[10],data[9],data[8],data[7],data[6],data[5],data[4],data[3],data[2],data[1],data[0]);

  vt_lower16.print(std::cout);

}

int main( int argc, char *argv[] )
{
  uint32_t input_val = 0u;
  std::string input_arg{};

  while(1)
  {

    if(argc==2)
    {
      input_arg = argv[1];
    }
    else
    {
      std::cout<<"Please enter a number to parse as a 32bit value (e.g. 1024, or 0xBEFF): " << endl;
      std::cin>>input_arg;
    }

    input_val = std::stoul(input_arg, nullptr, 0);

    parse_bit32(input_val);

    argc = 0;
    std::cout<<endl;
  }

}

