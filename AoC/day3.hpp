#pragma once
#include <string>
#include <iostream>

// Zeit: mehrere Stunden (insbesondere der Turtle Teil, der noch nicht fertig ist.

namespace AoC
{
  struct pt
  {
    int x;
    int y;
  };
  typedef pt vec;
  // richtung
  enum ri { unten, rechts, oben, links };
  vec ri_coords[4] = { { 0,-1 },{ 1,0 },{ 0,1 }, {-1,0} };
  class turtle
  {
    char richtung;
//    char schritte_in_richtung;
  public:
    // nach unten immer einen Schritt weniger, da wir sozusagen auf dem 2. Feld der linken Seite anfangen
    pt walk(int zahl)
    {
//      if (zahl == 1) return { 0, 0 }; // Sonderfall
      // zahl > 1 --> wir stellen uns auf das 2. Feld
      pt pos = { 0, 0 };
      richtung = oben;

      int schale = 1;
      int schrittegesamt = 0;
      int schritte_in_richtung = 0;
//      int seite = 0;
      int seitenlaenge;
      while (schrittegesamt < zahl-1)
      {
        seitenlaenge = schale * 2 - 2; // eigentlich #elemente einer Seite, die ist Seitenlänge-1
        schritte_in_richtung++;
        if (
          ((richtung == unten) && (schritte_in_richtung < seitenlaenge-1)) // nach unten einen Schritt weniger (s.o.)
          ||
          (schritte_in_richtung > seitenlaenge)
          )
        {
          schritte_in_richtung = 0;
          richtung++;
        }
        if (richtung > 3) // oben
        {
          richtung = 0; // links
          schale++;
        }
        // erst nachdem die Richtung passt, die Schritte ausführen
        pos.x += ri_coords[richtung].x;
        pos.y += ri_coords[richtung].y;
        schrittegesamt++;
      }
      return pos;
    }
  };

  class day3
  {
    std::string spiral_sheet = {
      "25 24 23 22 21"
      "10  9  8  7 20"
      "11  2  1  6 19"
      "12  3  4  5 18"
      "13 14 15 16 17"
    };
    // beispielzahlen
    int spiralzahl1 = 1;
    int spiralzahl2 = 12;
    int spiralzahl3 = 23;
    int spiralzahl4 = 1024;
    // testzahl
    int spiralzahl5 = 361527;
    
    int schalengroesse1(int nSchale)
    {
      if (nSchale == 0)
        return 0;
      else
        return (nSchale * 2 - 1)*
               (nSchale * 2 - 1);
    }

    int schalengroesse2(int nSchale) // auch ohne rekursion? ja, s.o. :-)
    {
      if (nSchale == 0)
        return 0;
      else if (nSchale == 1)
        return 1;
      else
        return 8*(nSchale -1) + schalengroesse2(nSchale -1);
    }

    int schalenseite(int nSchale)
    {
      return (nSchale * 2 - 1);
    }

    int schalenrand(int nSchale)
    {
      if (nSchale == 1)
        return 1;
      else
        return 8 * (nSchale - 1);
    }

    int schale(int zahl)
    {
      int i = 1;
      while (zahl > schalengroesse1(i)) i++;
      return i;
    }

    int part1(int zahl)
    { 
      if (zahl == 1) return 1;
      int i = 0;
      int _schale = schale(zahl);
      int _randzahl = (zahl - schalengroesse1(_schale - 1));
      int _seitenlaenge = schalenseite(_schale);
      int _mitte = _seitenlaenge / 2;
      int tmp = ((_randzahl) % (_seitenlaenge-1)); // Seitenlänge 5 --> modulo 4
      int _schritte_y = abs(tmp-_mitte);

      std::cout << "spiralzahl " << zahl << ", auf Schale " << _schale << std::endl;
      std::cout << "Zahl-Schale " << _randzahl << std::endl;
      std::cout << "Seitenlaenge " << _seitenlaenge  << std::endl;
      std::cout << "Mitte " << _mitte << std::endl;

      std::cout << "spiralzahl " << zahl << ", " << (_schale - 1) << " Schritte n. aussen, " << _schritte_y << " Schritte zur Seite, insges. " << ((_schale - 1) + _schritte_y) << std::endl;
      std::cout << std::endl;
      return 0;
    }
        
    int part2(int zahl)
    {
      turtle liese;
      pt dist = liese.walk(zahl);
      std::cout << zahl << " : " << dist.x << "," << dist.y << " Schritte." << std::endl;
      return 0;
    }
  public:
    void test()
    {
/*      std::cout << "============== DAY3 ==============" << std::endl;
      std::cout << schalengroesse1(1) << ", " << schalenrand(1) << ", " << schalenseite(1) << std::endl;
      std::cout << schalengroesse1(2) << ", " << schalenrand(2) << ", " << schalenseite(2) << std::endl;
      std::cout << schalengroesse1(3) << ", " << schalenrand(3) << ", " << schalenseite(3) << std::endl;
      std::cout << schalengroesse1(4) << ", " << schalenrand(4) << ", " << schalenseite(4) << std::endl;
      std::cout << schalengroesse1(5) << ", " << schalenrand(5) << ", " << schalenseite(5) << std::endl;

      part1(spiralzahl1);
      part1(spiralzahl2);
      part1(spiralzahl3);
      part1(spiralzahl4);
      part1(spiralzahl5);
*/
      part2(spiralzahl1);
      part2(spiralzahl2);
      part2(spiralzahl3);
      part2(spiralzahl4);
      part2(spiralzahl5);
    }
  };
}

