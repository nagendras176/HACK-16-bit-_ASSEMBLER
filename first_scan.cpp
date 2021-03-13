#include <fstream>
//#include <string>
//#include <iostream>
//#include "A_instruction.cpp"
using namespace std;
using namespace A;
class first_scan{
private:
  int cl=0;
  int no=0;
  std::string file_name;




public:
 first_scan(std::string file_name)
 { this->file_name=file_name;
   core();
 }
  //*************************************************************************************
  //************************************************************************************
  std::string getvar(std::string l)
  {  int p,q,i;
          for(i=2;i<l.length();i++)
         {
           if(l[i]==')')
           {
             q=i;
              break;
           }}
  return l.substr(1,q-1);
  }


     void insert(std::string s)
     {
        A::symbol[A::sym_cout]={s,this->cl-this->no};
        A::sym_cout++;

     }


//****************************************************************************************
//***************************************************************************************




  void core(){

  std::ifstream fin(file_name);
  while(!fin.eof())
  {
    std::string line,temp;
    getline(fin,line);
    if(line.length()==1||line[0]=='/')
    {
      this->no++;
    }
    if(line[0]=='(')
    {

    temp=getvar(line);
    insert(temp);
     this->no++;
  }




    this->cl++;
}
}
//*****************************************************************************************

};
