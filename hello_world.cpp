#include <iostream>
#include <string>

// The program asks for the user's name, then prints a greeting!
int main()
{
  std::string name;
  std::cout << "Enter your name: ";
  std::cin >> name;
  std::cout << "Hello world from " << name << std::endl;
  return 0;
}
