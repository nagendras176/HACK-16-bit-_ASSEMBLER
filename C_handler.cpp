//this is utility to handle C_instruction
//this file includes C_instruction.cpp which contains data files
//string.h files should be included



//C instruction structure
//
#include <iostream>
#include <string> //included for testing purpose only
#include "C_instruction.cpp"
#include<bits/stdc++.h>
using namespace std;

class C_handler{
private:
  std::string c_str;
  int comp_posx,comp_posy;


public:
  C_handler(std::string c_str)
  {
    this->c_str=c_str;
    this->out();


  }
  //in C_instruction,three tables are defined for ::control bits(a c1 c2 c3 c4 c5 c6) in structure comp {string "sym",string "val"}
  //                                              ::destination in structure dest {string "sym",string "val"}
  //                                              ::jump in structre jump {string "sym",string "val"}


  //parsing of destination bits

  //linear search for finding string bits corresponding to destination bits d1 d2 d3*******************************************************
  std::string dest_bits(std::string s)
  {  int i;

     std::string out="000";
    for(i=0;i<8;i++)
    {
      if(s==dest[i].sym)
      {
        out=dest[i].val;

        break;
      }
    }

    return out;
  }
  //dest_linear_search********************************************************************************************************************
  //function to return destination bits
  std::string dest_()
  {
    //if '=' exist in the command that implies c_commond consists destination or else "000"
    std::string dest_str=this->c_str;

    int i,p;
    for(i=1;i<=4;i++)
    {
      if(dest_str[i]=='=')
      {
        p=i;

        break;
      }
    }

    switch (p) {
      case 1:{

        std::string s;
        dest_str=s+this->c_str[0];
        dest_str=dest_bits(dest_str);
        this->comp_posx=p+1;

        break;
      }
      case 2:{
       dest_str=this->c_str.substr(0,2);
       dest_str=dest_bits(dest_str);
       this->comp_posx=p+1;
        break;

      }
      case 3:
      {

       dest_str=this->c_str.substr(0,3);
       cout<<dest_str<<"\n";
       dest_str=dest_bits(dest_str);
       this->comp_posx=p+1;
        break;
      }
      default:{
         this->comp_posx=0;
        dest_str="000";}
    }


    return dest_str;
  }
  //destination function *****************************************************************************************************
  //**************************************************************************************************************************
  //parsing of jump bits

  //linear search for finding string bits corresponding to destination bits j1 j2 j3*******************************************************
  std::string jump_bits(std::string s)
  {  int i;

     std::string out="000";
    for(i=0;i<8;i++)
    {
      if(s==jump[i].sym)
      {
        out=jump[i].val;

        break;
      }
    }

    return out;
  }
  //dest_linear_search********************************************************************************************************************
  //function to return destination bits
  std::string jump_()
  {
    //if '=' exist in the command that implies c_commond consists destination or else "000"
    std::string jump_str=this->c_str;

    if(jump_str[this->c_str.length()-4]==';')
    {
      jump_str=this->c_str.substr(this->c_str.length()-3,this->c_str.length()-1);
      jump_str=jump_bits(jump_str);
      this->comp_posy=this->c_str.length()-6;



    }
    else
    {
      jump_str="000";
        this->comp_posy=this->c_str.length()-1;
    }

    return jump_str;
  }

  //*****************************************************************************************************************************************
  //******************************************************************************************************************************************

  //functon to parse control bits
  std::string comp_bits(std::string s)
  {  int i;

       std::string out;
    for(i=0;i<28;i++)
    {
      if(s==comp[i].sym)
      {
        out=comp[i].val;

        break;
      }
    }
     cout<<out;
    return out;
  }

  std::string comp_() {
    std::string comp_str=this->c_str.substr(this->comp_posx,this->comp_posy);
    comp_str=comp_bits(comp_str);
    return comp_str;
  }

  std::string out()
  { std::string dest=dest_();
    std::string jump=jump_();
    std::string comp=comp_();
    return "111"+comp+dest+jump;
  }

};


int main()
{

C_handler obj("M=D+1;JMP");
cout<<obj.out();


  return 0;
}
