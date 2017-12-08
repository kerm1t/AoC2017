#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "functions.h"

// Zeit: 6:00 bis 6:50, ich hatte Schwierigkeiten mit atoi, was ich eigentlich nicht brauchte sondern "Ord"

namespace AoC
{
#define MAX_REG (26*26*26)
  int a_reg[MAX_REG]; // 3 letter registers

  class day8
  {

    int register_hash(std::string reg) // "sum" of single chars / digits
    {
      int z100 = 0;
      int z10 = 0;
      int z1 = 0;
      if (reg.size()>2) z100 = reg[2]-65; // a = 65
      if (reg.size()>1) z10  = reg[1]-65;
      z1                     = reg[0]-65;
      return z100*26*26 + z10*26 + z1;
    }

    int part1()
    {
      std::ifstream file("C:\\Projekte\\AoC\\instructions.txt");
      std::string line;
     
      for (int i = 0; i < MAX_REG; i++) a_reg[i] = 0;

      int maxregever = 0; // part2
      if (file)
      {
        while (std::getline(file, line))
        {
          std::vector<std::string> tokens = split(line.c_str(), ' ');

          int regDst = register_hash(tokens[0]);
          int regSrc = register_hash(tokens[4]);
          int incr = atoi(tokens[2].c_str());

          std::string op = tokens[1];
          
          int VZ;
          if (op.compare("inc") == 0) VZ = 1; else VZ = -1;
          
          std::string cmpOp = tokens[5];
          
          int cmp = atoi(tokens[6].c_str());
          
          if (cmpOp.compare(">")==0)
            if (a_reg[regSrc] > cmp)  a_reg[regDst] += (VZ*incr);
          if (cmpOp.compare("<") == 0)
            if (a_reg[regSrc] < cmp)  a_reg[regDst] += (VZ*incr);
          if (cmpOp.compare(">=") == 0)
            if (a_reg[regSrc] >= cmp) a_reg[regDst] += (VZ*incr);
          if (cmpOp.compare("<=") == 0)
            if (a_reg[regSrc] <= cmp) a_reg[regDst] += (VZ*incr);
          if (cmpOp.compare("==") == 0)
            if (a_reg[regSrc] == cmp) a_reg[regDst] += (VZ*incr);
          if (cmpOp.compare("!=") == 0)
            if (a_reg[regSrc] != cmp) a_reg[regDst] += (VZ*incr);

          if (a_reg[regDst] > maxregever) maxregever = a_reg[regDst]; // part2
        }
      }
      int maxreg = 0;
      for (int i = 0; i < MAX_REG; i++)
      {
        if (a_reg[i] > maxreg) maxreg = a_reg[i];
      }
      std::cout << "max_reg=" << maxreg << std::endl;
      std::cout << "max_reg_ever=" << maxregever << std::endl; // part2
      return 0;
    }

    int part2(std::string cap)
    {
      return 0;
    }
  public:
    void test()
    {
      std::cout << "============== DAY8 ==============" << std::endl;
      part1();

      //      part2(captcha6);
    }
  };
}


