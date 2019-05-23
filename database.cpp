#include <iostream>
#include <string>
#include <fstream>
#include "database.h"
using namespace std;

Database::Database()
{
    this->num_items_ = 0;
    this->items_ = nullptr;
}

Database::~Database()
{
    delete[] this->items_;
}

void Database::edit_item(int item)
{
    if (item >= this->num_items_ || item < 0)
        cout << endl
             << "Not a valid item number!" << endl
             << endl;
    else
        this->items_[item]->edit();
}

bool Database::add_item()
{
    string type;

    Item **ptr = new Item *[this->num_items_ + 1];
    if (ptr == nullptr)
        return false;
    for (int i = 0; i < this->num_items_; i++)
        ptr[i] = this->items_[i];
    cout << endl
         << "Enter the product type: ";
    cin >> type;

    ptr[this->num_items_] = new_item(type);
    delete[] this->items_;
    this->items_ = ptr;
    this->num_items_++;

    return true;
}

void Database::display_items()
{
    for (int i = 0; i < this->num_items_; i++)
    {
        cout << endl
             << i + 1 << ": " << endl;
        this->items_[i]->display();
    }
}

bool Database::save_database(string fileName)
{
    ofstream file;
    file.open(fileName, ios::out);
    if (!file)
    {
        cout << "Could not open the file." << endl;
        return false;
    }
    file << this->num_items_ << '\n';
    for (int i = 0; i < this->num_items_; i++)
    {
        file << this->items_[i];
        if (i != this->num_items_ - 1)
            file << '\n';
    }
    return true;
}

bool Database::retrieve_database(string fileName)
{
    ifstream file;
    string type;

    file.open(fileName, ios::in);
    if (!file)
    {
        cout << "Could not open the file." << endl;
        return false;
    }

    file >> this->num_items_;

    this->items_ = new Item *[this->num_items_];

    for (int i = 0; i < this->num_items_; i++)
    {
        file >> type;
        this->items_[i] = retrieve_item(file, type);
    }

    file.close();
    return true;
}

void Database::sell_item(int item)
{
    if (item >= this->num_items_ || item < 0)
        cout << endl
             << "Not a valid item number." << endl
             << endl;
    else if (!this->items_[item]->in_stock())
        cout << "Item out of stock!" << endl;
    else
    {
        this->items_[item]->operator--(0);
        cout << "Item sold!" << endl;
    }
}
