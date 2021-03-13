#include <iostream>
#include <fstream>
//#include "C_handler.cpp"


using namespace std;

std::string c_filter(std::string str)
{  int i;
   for(i=0;i<str.length();i++)
   {
     if(str[i]==' ')
     {
       break;
     }
   }
  return str.substr(0,i-1);
}

int main()
{  std::string temp;
  ifstream fin("Max.asm");

  while(!fin.eof())
  {   getline(fin,temp);
    if(temp[0]=='/'||temp.length()==1||temp[0]=='('||temp.length()==0);
    else
    {  std::string l=c_filter(temp);
      cout<<l<<" "<<l.length()<<"\n";
  }
}

return 0;
}
