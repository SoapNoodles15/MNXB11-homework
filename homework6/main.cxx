#include <iostream>
#include <string>

int compCharSum(const std::string &input){
    int charSum = 0;
    for (int index = 0; index < static_cast<int>(input.size()); ++index){
    charSum += input[index];}
    return charSum;
}

int main(int argCount, char *argValues[]) {
bool reqArgCount = (argCount == 3);
  if (reqArgCount) {
    std::string programName{argValues[0]};
    auto arg1{*(argValues[1])};
    auto programNameLength{programName.size()};
    auto arg2{std::atoi(argValues[2])};
    std::string arg1text{argValues[1]};
    
    int charSum = compCharSum(arg1text);

    if ((charSum ^ arg1 * 3) << (programNameLength & 0x1f) == arg2) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}