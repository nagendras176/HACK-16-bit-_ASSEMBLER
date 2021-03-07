#include <iostream>
#include <string>
#include "C_instruction.cpp"

std::string dummy="D=M";

std::string dest_search(std::string str)//fucking linear search
{
  int i=0;
  for(i=0;i<8;i++)
  {
    if(str==dest[i].sym)
    {
      return dest[i].val;
    }
  }
}

   std::string dest_()
   {
     int i;
     std::string d;
     for(i=1;i<=4;i++)
     {
       if(dummy[i]=='=')
       {
         break;
       }
     }


     if(i==4)//no "=" means no destination
     {
       return "000";
     }
     else{
     std::string str;
       switch(i)
       {
         case 1:
         {

            str[0]=dummy[0];
            str[1]='\0';
            return dest_search(str);
         }

         case 2:
         {

            str[0]=dummy[0];
            str[1]=dummy[1];
            str[2]='\0';
            return dest_search(str);

         }

         case 3:
         {

           str[0]=dummy[0];
           str[1]=dummy[1];
           str[2]=dummy[2];
           str[3]='\0';
            return dest_search(str);
       }

       default:return "000";



     }
}


   }





int main()
{

  std::cout<<dest_();
  return 0;
}
