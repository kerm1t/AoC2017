#pragma once
#include <string>
#include <vector>

// Zeit: 6:33 - 8:10 (part1)

namespace AoC
{
#define MEM_BANKS 16  
  int aMem[MEM_BANKS] = { 5,	1,	10,	0	,1,	7,	13	,14,	3	,12,	8	,10,	7	,12,	0,	6 };  // <-- vector
  
  struct max_bank {
    int idx;
    int max;
  };

  max_bank max() // std.-funktion auf vektor
  {
    max_bank bank;
    bank.idx = -1;
    bank.max = 0;
    for (int i = 0; i < MEM_BANKS; i++)
    {
      if (aMem[i] > bank.max)
      {
        bank.idx = i;
        bank.max = aMem[i];
      }
    }
    return bank;
  }

  std::string hash()
  {
    std::string s;
    for (int i = 0; i < MEM_BANKS; i++)
    {
      s = s + "," + std::to_string(aMem[i]); // ohne Komma könn(t)en sich Doppeldeutigkeiten ergeben!
    }
    return s;
  }

  class day6
  {
    int part1()
    {
      std::vector<std::string> v_hash;

      std::string sHash = "!";
      int reorder = 0;
      std::vector<std::string>::iterator it; // part2
      it = std::find(v_hash.begin(), v_hash.end(), sHash); // part2
      while (it == v_hash.end()) // hash not repeated         <-- part2
//      while (std::find(v_hash.begin(), v_hash.end(), sHash) == v_hash.end()) // hash not repeated   <-- part1
      {
        v_hash.push_back(sHash);

        max_bank bank = max();
        
        int incr = bank.max / (MEM_BANKS - 1);
        if (incr == 0) incr = 1;
        int distributed = 0;
        int idx = bank.idx % MEM_BANKS;
        while ((idx+1) != bank.idx)
        {
          idx = (idx+1) % MEM_BANKS;
          aMem[idx] += incr;
          distributed++;
          if (distributed == bank.max) break;
        }
        aMem[bank.idx] -= distributed;
        
        reorder++;
        sHash = hash();
        it = std::find(v_hash.begin(), v_hash.end(), sHash); // part2
      }
      std::cout << reorder << " redistribution cycles." << std::endl;
      std::cout << "reached after " << std::distance(it, v_hash.end()) << " loops." << std::endl; // part2
      return 0;
    }

    int part2(std::string cap)
    {
      return 0;
    }
  public:
    void test()
    {
      std::cout << "============== DAY6 ==============" << std::endl;
      part1();

      //      part2(captcha6);
    }
  };
}
