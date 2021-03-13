//THIS SOFTWARE FAILS IF PROGRAM CONSTITUTES BOTH SYMBOLS AND SYMBOLS_LESS

//#include <string>
//#include <regex>
//#include "A_handler.cpp"
//#include "A_instruction.cpp"
//#include <ctype.h>
using namespace std;
using namespace A;

//manager a_command
class A_manager{
private:
 std::string command;
 std::string output;
public:
  A_manager(std::string command)
  {
    this->command=command;
    out_();
  }

//////////////////////////////////////////////////////////////////////////////

bool is_string_digit(std::string str)
{  int i;
  int o=0;
for(i=0;i<str.length();i++)
  {
    o=isdigit(str[i]);
    if(o==0)
    {
      return 0;
    }}
  return 1;
}
/////////////////////////////////////////////////////////////////////////////


int fetch_value(std::string name,bool &val_exist)
{  int o,i;

     for(i=0;i<A::sym_cout;i++)
  {
    if(A::symbol[i].name==name)
    {
      o=A::symbol[i].val;
      val_exist=true;
      break;
    }
    else{

      o=0;
      val_exist=false;
    }

  }
  return o;
}


//////////////////////////////////////////////////////////////////////////////
  void out_()
  {
    std::string str=this->command;//if variable not specified in command
    if(is_string_digit(str.substr(1,str.length()-1)))
    {
         A_handler obj1(this->command);
         this->output=obj1.output();


    }

    else{
         bool val_exist;
         int val;
         val=fetch_value(str.substr(1,str.length()-1),val_exist);
         
         if(val_exist==true)//address memory
         {
            A_handler obj2("@"+to_string(val));
           this->output=obj2.output();
         }




         else{//if variable is specified
          A::symbol[A::sym_cout]={str.substr(1,str.length()-1),A::valu};

          A_handler obj3("@"+to_string(A::valu));
          this->output=obj3.output();
          A::sym_cout++;
          A::valu++;
        }



    }

  }
/////////////////////////////////////////////////////////////////////////////////////////////////


std::string output_()
{
  return this->output;
}

////////////////////////////////////////////////////////////////////////////////////////
};
