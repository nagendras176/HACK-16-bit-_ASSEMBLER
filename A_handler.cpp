//this is handler for A A_instruction
//#include <bitset>

class A_handler{
private:
  std::string a_string;
  int addr;
  std::string binary;
public:
  A_handler(std::string a_str)
  {
    this->a_string=a_str;
    num_conv();
    binarize();

  }

  void num_conv()
  { this->a_string[0]='0';
    this->addr=std::stoi(this->a_string);
  }

  void binarize()
  {
    binary=std::bitset<15>(this->addr).to_string();
  }

  std::string output()
  {
    return "0"+this->binary;
  }



};
