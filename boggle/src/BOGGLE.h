

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "DICE.h"

namespace BOGGLE_DIE{
  std::vector<std::string> die1 = {"R", "I", "F", "O", "B", "X"};
  std::vector<std::string> die2 = {"I", "F", "E", "H", "E", "Y"};
  std::vector<std::string> die3 = {"D", "E", "N", "O", "W", "S"};
  std::vector<std::string> die4 = {"U", "T", "O", "K", "N", "D"};
  std::vector<std::string> die5 = {"H", "M", "S", "R", "A", "O"};
  std::vector<std::string> die6 = {"L", "U", "P", "E", "T", "S"};
  std::vector<std::string> die7 = {"A", "C", "I", "T", "O", "A"};
  std::vector<std::string> die8 = {"Y", "L", "G", "K", "U", "E"};
  std::vector<std::string> die9 = {"Qu", "B", "M", "J", "O", "A"};
  std::vector<std::string> die10 = {"E", "H", "I", "S", "P", "N"};
  std::vector<std::string> die11 = {"V", "E", "T", "I", "G", "N"};
  std::vector<std::string> die12 = {"B", "A", "L", "I", "Y", "T"};
  std::vector<std::string> die13 = {"E", "Z", "A", "V", "N", "D"};
  std::vector<std::string> die14 = {"R", "A", "L", "E", "S", "C"};
  std::vector<std::string> die15 = {"U", "W", "I", "L", "R", "G"};
  std::vector<std::string> die16 = {"P", "A", "C", "E", "M", "D"};
}



class BOGGLE{

  private:
    std::vector<DICE<std::string>> _all_boggle_die;
    void _gen_boggle_die_set(){
      auto d1 = gen_string_dice(BOGGLE_DIE::die1);
      auto d2 = gen_string_dice(BOGGLE_DIE::die2);
      auto d3 = gen_string_dice(BOGGLE_DIE::die3);
      auto d4 = gen_string_dice(BOGGLE_DIE::die4);
      auto d5 = gen_string_dice(BOGGLE_DIE::die5);
      auto d6 = gen_string_dice(BOGGLE_DIE::die6);
      auto d7 = gen_string_dice(BOGGLE_DIE::die7);
      auto d8 = gen_string_dice(BOGGLE_DIE::die8);
      auto d9 = gen_string_dice(BOGGLE_DIE::die9);
      auto d10 = gen_string_dice(BOGGLE_DIE::die10);
      auto d11 = gen_string_dice(BOGGLE_DIE::die11);
      auto d12 = gen_string_dice(BOGGLE_DIE::die12);
      auto d13 = gen_string_dice(BOGGLE_DIE::die13);
      auto d14 = gen_string_dice(BOGGLE_DIE::die14);
      auto d15 = gen_string_dice(BOGGLE_DIE::die15);
      auto d16 = gen_string_dice(BOGGLE_DIE::die16);


      d1.set_id(1);
      d2.set_id(2);
      d3.set_id(3);
      d4.set_id(4);
      d5.set_id(5);
      d6.set_id(6);
      d7.set_id(7);
      d8.set_id(8);
      d9.set_id(9);
      d10.set_id(10);
      d11.set_id(11);
      d12.set_id(12);
      d13.set_id(13);
      d14.set_id(14);
      d15.set_id(15);
      d16.set_id(16);



      _all_boggle_die.push_back(d1);
      _all_boggle_die.push_back(d2);
      _all_boggle_die.push_back(d3);
      _all_boggle_die.push_back(d4);
      _all_boggle_die.push_back(d5);
      _all_boggle_die.push_back(d6);
      _all_boggle_die.push_back(d7);
      _all_boggle_die.push_back(d8);
      _all_boggle_die.push_back(d9);
      _all_boggle_die.push_back(d10);
      _all_boggle_die.push_back(d11);
      _all_boggle_die.push_back(d12);
      _all_boggle_die.push_back(d13);
      _all_boggle_die.push_back(d14);
      _all_boggle_die.push_back(d15);
      _all_boggle_die.push_back(d16);
      
    }


    void _shuffle_die_set(){

      for(int d = 0; d < _all_boggle_die.size(); d++){

        _all_boggle_die[d].roll_dice();

      }

      std::random_shuffle(_all_boggle_die.begin(), _all_boggle_die.end());

    }


    void _banner(std::ostream& out){

      out << "Welcome to Boggle" << "\n";

    }

  public:

    BOGGLE(){

      _gen_boggle_die_set();
      std::cout << std::endl;
      _banner(std::cout);
      std::cout << std::endl;

    }

    void print_random_dice_side(std::ostream& out){

      for(int d = 0; d < _all_boggle_die.size(); d++){
        out << _all_boggle_die[d].pick_random_side() << "\n";
      }
    }

    void print_die_id(std::ostream& out){

      for(int d = 0; d < _all_boggle_die.size(); d++){
        out << _all_boggle_die[d].get_id() << "\n";
      }
    }

    void shuffle(){
      _shuffle_die_set();
    }

    void print_boggle_board(std::ostream& out, int idx){
      out << "\n";
      out << "The boggle board:" << "\n";
      for(int d = 0; d <_all_boggle_die.size(); d++){
        out << _all_boggle_die[d].get_side_data(idx) << " ";
        if((d+1)%4 == 0){
          out<< "\n";
        }
      }
      out << "\n";
    }

    void print_boggle_board_id(std::ostream& out){
      out << "\n";
      out << "The boggle board:" << "\n";
      for(int d = 0; d <_all_boggle_die.size(); d++){
        out << _all_boggle_die[d].get_id() << " ";
        if((d+1)%4 == 0){
          out<< "\n";
        }
      }
      out << "\n";
    }

    void new_game(){
      std::cout << "Shuffling" << std::endl;
      shuffle();
      print_boggle_board(std::cout, 3);
    }



};
