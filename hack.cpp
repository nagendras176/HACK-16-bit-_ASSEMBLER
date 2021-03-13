#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <regex>
#include <bits/stdc++.h>
#include <ctype.h>
//standard header files *************************************************
#include "A_instruction.cpp"
#include "C_instruction.cpp"
#include "data.cpp"
#include "A_handler.cpp"
#include "A_manager.cpp"
#include "C_handler.cpp"
#include "first_scan.cpp"
#include "routien.cpp"


using namespace std;




void ui()
{
  cout<<"*********************************************************************************\n";
  cout<<"HI,THIS IS THIS IS ASSEMBLER SOFTWARE FOR 16 BIT HACK COMPUTER\n";
  cout<<"**********************************************************************************\n";
  cout<<"->make sure that assembly code you written exist in current directory\n";
  cout<<"->out put file will be in current directory after this software terminats\n";
  cout<<"->this softare do not debug the code you wrote \n";
  cout<<"***********************************************************************************\n";
  cout<<"************************************************************************************\n";
  cout<<"ENTER THE FILE NAME::::::";
  cin>>file_name;
  cout<<"\n";

}

int main()
{
//command line user interface
ui();
routien obj;
return 0;
};
