
#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

struct RNG {
    int operator() (int n) {
        return std::rand() / (1.0 + RAND_MAX) * n;
    }
};

template <class T>
class DICE{

  private:
    
    int _id;
    int _nsides;
    std::vector<T> _side_data;

    void _shuffle(){
      // Method to shuffle the sides of the dice
      std::random_shuffle(_side_data.begin(), _side_data.end(), RNG());
    }

  public:

    DICE(){

    };


    DICE(int nsides){

      _nsides = nsides;

    }


    void set_id(int id){

      _id = id;

    }

    int get_id(){

      return _id;

    }

    void add_side_data(T data){

      if(_side_data.size() < _nsides){
        _side_data.push_back(data);
      }
      else{
        std::cout << "NOPE" << std::endl;
      }

    }

    void roll_dice(){
      _shuffle();
    }

    void print(std::ostream& out){

      out << "The dice's sides:\n";
      for(int s = 0; s < _side_data.size(); s++){
        out << "side: " << s+1 << " -> value: " << get_side_data(s) << "\n";

      }

    }

    T get_side_data(int idx){

      return _side_data[idx];

    }

    T pick_random_side(){

      int rand_idx = rand() % _nsides;
      return _side_data[rand_idx];

    }


};

DICE<std::string> gen_string_dice(std::vector<std::string> side_data){
  DICE<std::string> dice(side_data.size());
  for(int i = 0; i < side_data.size(); i++){
    dice.add_side_data(side_data[i]);
  }
  return dice;
}

DICE<int> gen_normal_nd(int nsides){
  DICE<int> dice(nsides);
  for(int i = 1; i <= nsides; i++)
    dice.add_side_data(i);
  return dice;
}
