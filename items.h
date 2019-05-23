#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <iostream>
using namespace std;

class Item
{
protected:
  string name_;
  string type_;
  int qtd_;
  float price_;

public:
  Item();
  Item(string, string, int, float);
  virtual void display() = 0;
  virtual void edit() = 0;
  bool in_stock();
  void operator--(int);
  friend ofstream &operator<<(ofstream &, Item *);
  friend ifstream &operator>>(ifstream &, Item *);
};

class Phone : public Item
{
  string model_;
  string os_;
  string carrier_;

public:
  Phone();
  Phone(string, string, string, string, int, float);
  void display();
  void edit();
  Phone *new_phone();
  friend ofstream &operator<<(ofstream &, Phone *);
  friend ifstream &operator>>(ifstream &, Phone *);
};

class Tablet : public Item
{
  string model_;
  string os_;
  string size_;

public:
  Tablet();
  Tablet(string, string, string, string, int, float);
  void display();
  void edit();
  Tablet *new_tablet();
  friend ofstream &operator<<(ofstream &, Tablet *);
  friend ifstream &operator>>(ifstream &, Tablet *);
};

class Peripheral : public Item
{
public:
  Peripheral();
  Peripheral(string, int, float);
  void display();
  void edit();
  Peripheral *new_peripheral();
  friend ofstream &operator<<(ofstream &, Peripheral *);
  friend ifstream &operator>>(ifstream &, Peripheral *);
};

Item *new_item(string);
Item *retrieve_item(ifstream &, string);

template <typename T>
void addField(string name, T &field)
{
  T value;
  std::cout << "Enter the value for " << name << endl;
  std::cin >> value;
  field = value;
}

#endif