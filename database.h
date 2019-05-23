#ifndef DATABASE_H
#define DATABASE_H

#include "items.h"

class Database
{
  Item **items_;
  int num_items_;

public:
  Database();
  ~Database();
  void edit_item(int);
  bool add_item();
  void display_items();
  bool save_database(string);
  bool retrieve_database(string);
  void sell_item(int);
};

#endif