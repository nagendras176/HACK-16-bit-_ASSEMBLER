//#include <fstream>
//include "data.cpp"
//#include "first_scan.cpp"
//#include "A_manager.cpp"
//#include "C_handler.cpp"

using namespace DATA;


class routien{
  public:
    routien()
        {
          first_scan obj(DATA::file_name);
          init();

        }
        std::string c_filter(std::string str)
        {  int i;
           for(i=0;i<str.length();i++)
           {
             if(str[i]==' ')
             {
               break;
             }
           }
          return str.substr(0,i);
        }


   void init()
   {
     ifstream fin(DATA::file_name);
     cout<<">>opening file "+DATA::file_name+"\n";
     ofstream fout("out");
     int i=0;
     while(!fin.eof())
     {  std::string line;
       getline(fin,line);



      std::string temp=line;


       if(temp[0]=='/'||temp.length()==1||temp[0]=='('||temp.length()==0);
       else
       {
          temp=c_filter(line);
          //cout<<temp<<"\n";
          //cout<<temp.length()<<"\n";
          if(temp[0]=='@')
          {
             A_manager obj1(temp.substr(0,temp.length()-1));

           fout<<obj1.output_()<<"\n";

          }
          else{


             C_handler obj2(temp.substr(0,temp.length()-1));

             fout<<obj2.out()<<"\n";
          }
       }



       }

     }




};
