#include <iostream>
#include <string>

int usage(){
    std::cout << "=========" << std::endl;
    std::cout << "Wrong number of arguments!" << std::endl;
    std::cout << "You need to provide 2 (two) arguments!" << std::endl;
    std::cout << "Example: <programName> <argument 1> <argument 2>" << std::endl;
    std::cout << "=========" << std::endl;

    return 1;
}

int compCharSum(const std::string &input){
    int charSum = 0;
    for (int index = 0; index < static_cast<int>(input.size()); ++index){
    charSum += input[index];}
    return charSum;
}

int calcKey(int charSum, char arg1, int programNameLength){
    return (charSum ^ arg1 * 3) << (programNameLength & 0x1f);
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
    std::cout << "Calculated checksum:" << charSum << std::endl;

    int compKey = calcKey(charSum, arg1, programNameLength);
    std::cout << "Calculated key:" << compKey << std::endl;

    std::cout << "Expected key:" << arg2 << std::endl;

    if (compKey == arg2) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
  else{
    usage();
  }
}