#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "functions.h"

namespace AoC
{

  class day7
  {
    int part1()
    {
      std::ifstream file("C:\\Projekte\\AoC\\programs.txt");
      std::string line;

      if (file)
      {
        while (std::getline(file, line))
        {
          std::vector<std::string> tokens = split(line.c_str(), ' ');
          for (int i = 0; i < tokens.size(); i++)
          {
            std::cout << tokens[i] << std::endl;
          }
        }
      }
//      std::cout << num_pp << " passphrases." << std::endl;
      return 0;
    }

    int part2(std::string cap)
    {
      return 0;
    }
  public:
    void test()
    {
      std::cout << "============== DAY7 ==============" << std::endl;
      part1();

      //      part2(captcha6);
    }
  };
}


