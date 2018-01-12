#ifndef SPEAKER__
#define SPEAKER__
#include <iostream>
#include <string>

class Speaker
{
  public:
    static std::string GREETING;
    std::string speak();

};


std::string Speaker::GREETING = "Howdy";

std::string Speaker::speak()
{
  return Speaker::GREETING + ", world.";
}
#endif
