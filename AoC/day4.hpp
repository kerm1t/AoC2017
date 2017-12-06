#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include <algorithm> // sort

// Zeit etwa 6:18 bis 6:42

namespace AoC
{
  // Tokenizer, https://stackoverflow.com/questions/53849/how-do-i-tokenize-a-string-in-c
  std::vector<std::string> split(const char *str, char c = ' ')
  {
    std::vector<std::string> result;

    do
    {
      const char *begin = str;

      while (*str != c && *str)
        str++;

      result.push_back(std::string(begin, str));
    } while (0 != *str++);

    return result;
  }
  
  // https://stackoverflow.com/questions/18267407/check-whether-two-strings-are-anagrams-c
  bool is_anagram(std::string s1, std::string s2)
  {
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return s1 == s2;
  }
  
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


