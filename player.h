#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

struct Player{
  std::string location;
  std::vector<std::string> inventory;
  std::vector<std::string> lookat;
  bool firststage, secondstage;
};

#endif
