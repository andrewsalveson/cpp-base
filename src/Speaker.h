#ifndef SPEAKER__
#define SPEAKER__
#include <iostream>
#include <string>

class Speaker
{
  public:
    std::string speak();

};


std::string Speaker::speak()
{
  return "Howdy, world.";
}
#endif
