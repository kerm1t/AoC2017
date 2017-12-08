#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "functions.h"

// Zeit etwa 6:18 bis 6:42

namespace AoC
{
  // 7.12.: split() und is_anagram() in functions ausgelagert

  // -----------------------------------------
  // Für diesen Tag wäre es einfacher gewesen,
  // Python zu nutzen,
  // das hat z.B. Tokenizer eingebaut
  // -----------------------------------------
  class day4
  {
    int part1()
    {
      std::ifstream pp("C:\\Projekte\\AoC\\passphrases.txt");
      std::string line;

      int num_pp = 0;
      if (pp)
      {
        while (std::getline(pp, line))
        {
          bool bDouble = false;
          std::vector<std::string> tokens = split(line.c_str(),' ');
          for (int i = 0; i < tokens.size(); i++)
          {
            for (int j = i + 1; j < tokens.size(); j++)
            {
//              if (tokens[i].compare(tokens[j]) == 0) // part 1
              if (is_anagram(tokens[i],tokens[j])) // part 2
              {
                bDouble = true;
              }
            }
          }
          if (bDouble == false) num_pp++;
        }
      }
      std::cout << num_pp << " passphrases." << std::endl;
      return 0;
    }

    int part2(std::string cap)
    {
      return 0;
    }
  public:
    void test()
    {
      std::cout << "============== DAY4 ==============" << std::endl;
            part1();

      //      part2(captcha6);
    }
  };
}


