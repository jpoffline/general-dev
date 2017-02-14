
#include <algorithm> // std::random_shuffle
#include <exception>
#include <iostream>
#include <string>
#include <vector>
enum SUIT { CLUB, SPADE, HEART, DIAMOND };

class EXCEPTION : public std::exception {
private:
  std::string _msg;

public:
  EXCEPTION();
  EXCEPTION(std::string msg) { _msg = msg; }
  virtual const char *what() { return _msg.c_str(); }
};

class CARD {

public:
  CARD(){};
  CARD(SUIT suit, int value) {
    set_suit(suit);
    set_value(value);
  }
  ~CARD(){};

  void set_suit(SUIT suit) { _suit = suit; }
  int get_suit() { return _suit; }
  void set_value(int value) { _value = value; }
  int get_value() { return _value; }
  void print() { std::cout << suit_conv() << " " << value_conv() << std::endl; }
  std::string print2() { return suit_conv() + " " + value_conv(); }

private:
  SUIT _suit;
  int _value;

  std::string value_conv() {
    if (_value > 0 && _value < 11)
      return std::to_string(_value);
    if (_value == 0)
      return "A";
    if (_value == 11)
      return "J";
    if (_value == 12)
      return "Q";
    if (_value == 13)
      return "K";
    return "NA";
  }

  std::string suit_conv() {
    switch (_suit) {
    case (SUIT::HEART): {
      return "H";
    }
    case (SUIT::DIAMOND): {
      return "D";
    }
    case (SUIT::SPADE): {
      return "S";
    }
    case (SUIT::CLUB): {
      return "C";
    }
    }
  }
};

class DECK {
private:
  std::vector<CARD> _cards;

public:
  DECK() { create_deck(); };
  ~DECK(){};
  void create_deck() {
    for (int i = 0; i <= 13; i++) {
      for (SUIT suit = SUIT::CLUB; suit <= 3; suit = SUIT(suit + 1)) {
        add_card_to_deck(CARD(suit, i));
      }
    }
  }

  void add_card_to_deck(CARD card) {
    if (_cards.size() > 4 * 14) {
      print_ncards();
      throw EXCEPTION("too many cards");
    } else {
      _cards.push_back(card);
    }
  }

  void shuffle() { std::random_shuffle(_cards.begin(), _cards.end()); }

  void print() {
    std::cout << "THE DECK:" << std::endl;
    for (int i = 0; i < _cards.size(); i++)
      _cards[i].print();
  }

  int ncards_in_deck() { return _cards.size(); }
  void print_ncards() {
    std::cout << "# cards in deck: " << ncards_in_deck() << std::endl;
  }

  CARD get_card() {
    if (_cards.size() == 0) {
      throw EXCEPTION("attempting to remove card from empty deck.");
    }
    CARD c = _cards[_cards.size() - 1];
    _cards.pop_back();
    return c;
  }
};

class HAND {

private:
  std::vector<CARD> _cards;

public:
  HAND(){};

  void add_card_from_deck_to_hand(DECK &deck) {
    _cards.push_back(deck.get_card());
  }

  void add_ncards_from_deck_to_hand(int n, DECK &deck) {
    for (int i = 0; i < n; i++) {
      _cards.push_back(deck.get_card());
    }
  }

  void print() {
    for (int i = 0; i < _cards.size(); i++)
      _cards[i].print();
  }

  CARD get_card(int idx) { return _cards[idx]; };
};

class PLAY_SNAP {

private:
  std::vector<HAND> _hands;

public:
  PLAY_SNAP(){};
  void add_hand(HAND hand) { _hands.push_back(hand); };

  void play_turn(int tid) {
    CARD previous_card = _hands[0].get_card(tid);
    for (int h = 1; h < _hands.size(); h++) {
      std::cout << "TOP CARD:  " << previous_card.print2() << std::endl;
      std::cout << "THIS CARD: " << _hands[h].get_card(tid).print2()
                << std::endl;

      if (_hands[h].get_card(tid).get_value() == previous_card.get_value()) {
        std::cout << "SNAP POSSIBLE: same value" << std::endl;
      }
      if (_hands[h].get_card(tid).get_suit() == previous_card.get_suit()) {
        std::cout << "SNAP POSSIBLE: same suit" << std::endl;
      }
      previous_card = _hands[h].get_card(tid);
    }
  }
};

int main2() {

  DECK deck;
  deck.shuffle();

  int ncards_per_hand = 10;

  HAND hand1, hand2;

  hand1.add_ncards_from_deck_to_hand(ncards_per_hand, deck);
  hand2.add_ncards_from_deck_to_hand(ncards_per_hand, deck);

  std::cout << "HAND 1" << std::endl;
  hand1.print();

  std::cout << "HAND 2" << std::endl;
  hand2.print();

  PLAY_SNAP snap;
  snap.add_hand(hand1);
  snap.add_hand(hand2);
  for (int c = 0; c < ncards_per_hand; c++) {
    snap.play_turn(c);
  }

  return 0;
}

int main() {

  try {
    main2();
  } catch (EXCEPTION &e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
  }
}
