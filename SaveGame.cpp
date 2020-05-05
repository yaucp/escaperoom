#include <iostream>
#include <fstream>
#include <string>
#include "SaveGame.h"
#include "player.h"
#include "puzzle.h"
#include <vector>
using namespace std;

void SaveGame(Player player, Puzzle puzzle, string filename){
  ofstream fout;
  //Open orginial file or new save file if the player's new
  if (filename == ""){
    cout<<"How do you want your save file named? (Must end with .txt and no space are allowed.)\n";
    cin>>filename;
    fout.open(filename.c_str());

    while(fout.fail()){
      cout<<"Error opening file "<<filename<<" !\n"
          <<"Please enter a new file name:\n";
      cin>>filename;
      fout.open(filename.c_str());
    }
  }
  else {
    fout.open(filename.c_str());
    while(fout.fail()){
      cout<<"Error opening file "<<filename<<" !\n"
          <<"Please enter a new file name:\n";
      cin>>filename;
      fout.open(filename.c_str());
    }
  }
  //Write all the data to the file
  fout<<"location "<<player.location<<endl;
  fout<<"inventory ";
  for (int i = 0; i < player.inventory.size() - 1; ++i){
    fout<<player.inventory[i]<<" ";
  }
  fout<<player.inventory[player.inventory.size()-1]<<endl;
  fout<<"roombtoc "<<puzzle.roombtoc<<endl;
  fout<<"roomc "<<puzzle.roomc<<endl;

  fout.close();
  cout<<"Saved all your current progress!\n";
}