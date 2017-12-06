#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include <algorithm> // sort

// 

namespace AoC
{

  class day5
  {
    int part1()
    {
      std::ifstream pp("C:\\Projekte\\AoC\\maze.txt");
      std::string line;

      int aMaze[1058];

      int nLines = 0;
      int nJumps = 0;
      if (pp)
      {
        while (std::getline(pp, line))
        {
          aMaze[nLines++] = atoi(line.c_str());
        }

        int pc = 0;
        int cmd = 0;
        while (pc < nLines)
        {
          cmd = aMaze[pc];
//          aMaze[pc]++;                   // part1
          if (aMaze[pc] >= 3) aMaze[pc]--; // part2
          else aMaze[pc]++;                // part2
          pc += cmd;
          nJumps++;
        }
      }
      std::cout << nJumps << " jumps." << std::endl;
      return 0;
    }

    int part2(std::string cap)
    {
      return 0;
    }
  public:
    void test()
    {
      std::cout << "============== DAY5 ==============" << std::endl;
      part1();

      //      part2(captcha6);
    }
  };
}


