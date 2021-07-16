#include <iostream>
#include <stdint.h>
#include <bitset>

#include "VariadicTable.h"


void parse_bit32(uint32_t val)
{
  constexpr auto bit_length = 32u;
  
  std::bitset<bit_length>data {val};

  std::cout << "Decimal: " << std::dec << data.to_ulong() << std::endl;;
  std::cout << "Hex: 0x" << std::hex << data.to_ulong() << std::endl;;
  std::cout << "Binary: " << data << std::endl;;

  std::string bit_str = data.to_string();
  for( auto itr = std::next(bit_str.begin(),4); itr != bit_str.end(); std::advance( itr, 5 ) )
  {

    itr = bit_str.insert(itr, ' ');

  }

  std::cout << "Spaced Binary: " << bit_str << std::endl;;


  //build upper 16bit table
  constexpr uint8_t tbl_size = 16u;
  std::vector<std::string> vt_header16_31;

  for (int i = tbl_size+tbl_size-1; i>=tbl_size; i--)
  {
    vt_header16_31.push_back("bit " + std::to_string(i) );
  }

  VariadicTable<int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int> vt_upper16(vt_header16_31);

  vt_upper16.addRow(data[15+tbl_size], data[14+tbl_size],data[13+tbl_size],data[12+tbl_size],data[11+tbl_size],data[10+tbl_size],data[9+tbl_size],data[8+tbl_size],data[7+tbl_size],data[6+tbl_size],data[5+tbl_size],data[4+tbl_size],data[3+tbl_size],data[2+tbl_size],data[1+tbl_size],data[0+tbl_size]);

  vt_upper16.print(std::cout);
  
  
  //build lower 16bit table
  std::vector<std::string> vt_header0_15;

  for (int i = tbl_size-1; i>=0; i--)
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
      std::cout<<"Please enter a number to parse as a 32bit value (e.g. 1024, or 0xBEFF): " ;
      std::cin>>input_arg;
      std::cout<<std::endl;;
    }

    input_val = std::stoul(input_arg, nullptr, 0);

    parse_bit32(input_val);

    if (2 == argc)
    {
      break; //argument invocation skips looping and goes directly to program termination.
    }
    else
    {
      argc = 0;
    }
    std::cout<<std::endl;;
  }

}

