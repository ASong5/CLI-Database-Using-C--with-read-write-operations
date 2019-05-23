#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "items.h"

using namespace std;

Item::Item()
{
    this->name_ = "";
    this->type_ = "";
    this->qtd_ = 0;
    this->price_ = 0;
}

Item::Item(string name, string type, int qtd, float price)
{
    this->name_ = name;
    this->type_ = type;
    this->qtd_ = qtd;
    this->price_ = price;
}

void Item::display()
{
    cout << left << setw(16) << "Product Name" << left << setw(16) << "Product Type" << left << setw(16) << "Product Qtd" << left << setw(16) << "Product Price" << endl
         << "----------------------------------------------------------------" << endl;
    cout << left << setw(16) << this->name_ << left << setw(16) << this->type_ << left << setw(16) << this->qtd_ << left << setw(16) << fixed << setprecision(2) << this->price_ << endl;
}

void Item::edit()
{
    char option;
    cout << "Would you like to change the product name? (y/n): ";
    cin >> option;
    if (option == 'y')
    {
        cout << "Enter the new product name: ";
        cin >> this->name_;
        cout << "Product name has been changed to " << this->name_ << endl;
    }
    cout << "Would you like to change the product type? (y/n): ";
    cin >> option;
    if (option == 'y')
    {
        cout << "Enter the new product type: ";
        cin >> this->type_;
        cout << "Product type has been changed to " << this->type_ << endl;
    }
    cout << "Would you like to change the product quantity? (y/n): ";
    cin >> option;
    if (option == 'y')
    {
        cout << "Enter the new product quantity: ";
        cin >> this->qtd_;
        cout << "Product quantity has been changed to " << this->qtd_ << endl;
    }
    cout << "Would you like to change the product price? (y/n): ";
    cin >> option;
    if (option == 'y')
    {
        cout << "Enter the new product price: ";
        cin >> this->price_;
        cout << "Product price has been changed to " << this->price_ << endl;
    }
}

bool Item::in_stock()
{
    return this->qtd_ ? true : false;
}

void Item::operator--(int)
{
    --this->qtd_;
}

ofstream &operator<<(ofstream &file, Item *item)
{
    if (item->type_ == "Phone")
    {
        Phone *phone = (Phone *)item;
        file << phone;
    }
    else if (item->type_ == "Tablet")
    {
        Tablet *tablet = (Tablet *)item;
        file << tablet;
    }
    else if (item->type_ == "Peripheral")
    {
        Peripheral *peripheral = (Peripheral *)item;
        file << peripheral;
    }
    return file;
}

ifstream &operator>>(ifstream &file, Item *item)
{

    string line;
    if (file.is_open())
    {
        file >> item->type_;
        file >> item->name_;
        file >> item->qtd_;
        file >> item->price_;
    }
    else
    {
        cout << "File is not open";
    }

    return file;
}

Item *new_item(string type)
{
    if (type == "Phone")
    {
        Phone *newItem;
        newItem = newItem->Phone::new_phone();
        return newItem;
    }
    else if (type == "Tablet")
    {
        Tablet *newItem;
        newItem = newItem->Tablet::new_tablet();
        return newItem;
    }
    else if (type == "Peripheral")
    {
        Peripheral *newItem;
        newItem = newItem->Peripheral::new_peripheral();
        return newItem;
    }
    else
    {
        Item *newItem;
        return newItem;
    }
}

Item *retrieve_item(ifstream &file, string type)
{
    if (type == "Phone")
    {
        Phone *newPhone = new Phone();
        file >> newPhone;
        return (Item *)newPhone;
    }

    else if (type == "Tablet")
    {
        Tablet *newTablet = new Tablet();
        file >> newTablet;
        return (Item *)newTablet;
    }

    else if (type == "Peripheral")
    {
        Peripheral *newPeripheral = new Peripheral();
        file >> newPeripheral;
        return (Item *)newPeripheral;
    }
    else
    {
        Item *newItem;
        return newItem;
    }
}

Phone::Phone(string name, string model, string os, string carrier, int qtd, float price)
{
    this->type_ = "Phone";
    this->name_ = name;
    this->model_ = model;
    this->os_ = os;
    this->carrier_ = carrier;
    this->qtd_ = qtd;
    this->price_ = price;
}
void Phone::display()
{
    this->Item::display();
    cout << endl << left << setw(16) << "Product Model" << left << setw(16) << "Product OS" << left << setw(16) << "Product Carrier" << endl
         << "----------------------------------------------------------------" << endl;
    cout << left << setw(16) << this->model_ << left << setw(16) << this->os_ << left << setw(16) << this->carrier_ << endl
         << endl;
}

void Phone::edit()
{
    char option;
    this->Item::edit();
    cout << "Would you like to change the product model? (y/n): ";
    cin >> option;
    if (option == 'y')
    {
        cout << "Enter the new product model: ";
        cin >> this->model_;
        cout << "Product model has been changed to " << this->model_ << endl;
    }

    cout << "Would you like to change the product OS? (y/n): ";
    cin >> option;
    if (option == 'y')
    {
        cout << "Enter the new product OS: ";
        cin >> this->os_;
        cout << "Product os has been changed to " << this->os_ << endl;
    }

    cout << "Would you like to change the product carrier? (y/n): ";
    cin >> option;
    if (option == 'y')
    {
        cout << "Enter the new product carrier: ";
        cin >> this->carrier_;
        cout << "Product carrier has been changed to " << this->carrier_ << endl;
    }
}

ofstream &operator<<(ofstream &file, Phone *item)
{
    file << item->type_ << "\n"
         << item->name_ << "\n"
         << item->qtd_ << "\n"
         << fixed << setprecision(2) << item->price_ << "\n"
         << item->model_ << "\n"
         << item->os_ << "\n"
         << item->carrier_;

    return file;
}

ifstream &operator>>(ifstream &file, Phone *item)
{

    string line;
    if (file.is_open())
    {
        file >> item->name_;
        file >> item->qtd_;
        file >> item->price_;
        file >> item->model_;
        file >> item->os_;
        file >> item->carrier_;
    }
    else
    {
        cout << "File is not open";
    }

    return file;
}

Tablet::Tablet(string name, string model, string os, string size, int qtd, float price)
{
    this->type_ = "Tablet";
    this->name_ = name;
    this->model_ = model;
    this->os_ = os;
    this->size_ = size;
    this->qtd_ = qtd;
    this->price_ = price;
}

void Tablet::display()
{
    this->Item::display();
    cout << endl << left << setw(16) << "Product Model" << left << setw(16) << "Product OS" << left << setw(16) << "Product Size" << endl
         << "----------------------------------------------------------------" << endl;
    cout << left << setw(16) << this->model_ << left << setw(16) << this->os_ << left << setw(16) << this->size_ << endl
         << endl;
}

void Tablet::edit()
{
    char option;
    this->Item::edit();
    cout << "Would you like to change the product model? (y/n): ";
    cin >> option;
    if (option == 'y')
    {
        cout << "Enter the new product model: ";
        cin >> this->model_;
        cout << "Product model has been changed to " << this->model_ << endl;
    }

    cout << "Would you like to change the product OS? (y/n): ";
    cin >> option;
    if (option == 'y')
    {
        cout << "Enter the new product OS: ";
        cin >> this->os_;
        cout << "Product os has been changed to " << this->os_ << endl;
    }

    cout << "Would you like to change the product size? (y/n): ";
    cin >> option;
    if (option == 'y')
    {
        cout << "Enter the new product size: ";
        cin >> this->size_;
        cout << "Product size has been changed to " << this->size_ << endl;
    }
}

ofstream &operator<<(ofstream &file, Tablet *item)
{
    file << item->type_ << "\n"
         << item->name_ << "\n"
         << item->qtd_ << "\n"
         << fixed << setprecision(2) << item->price_ << "\n"
         << item->model_ << "\n"
         << item->os_ << "\n"
         << item->size_;

    return file;
}

ifstream &operator>>(ifstream &file, Tablet *item)
{

    string line;
    if (file.is_open())
    {
        file >> item->name_;
        file >> item->qtd_;
        file >> item->price_;
        file >> item->model_;
        file >> item->os_;
        file >> item->size_;
    }
    else
    {
        cout << "File is not open";
    }

    return file;
}

Peripheral::Peripheral(string name, int qtd, float price)
{
    this->type_ = "Peripheral";
    this->name_ = name;
    this->qtd_ = qtd;
    this->price_ = price;
}

void Peripheral::display()
{
    Item::display();
}

void Peripheral::edit()
{
    Item::edit();
}

ofstream &operator<<(ofstream &file, Peripheral *item)
{
    file << item->type_ << "\n"
         << item->name_ << "\n"
         << item->qtd_ << "\n"
         << fixed << setprecision(2) << item->price_ << "\n";

    return file;
}

ifstream &operator>>(ifstream &file, Peripheral *item)
{

    string line;
    if (file.is_open())
    {
        file >> item->name_;
        file >> item->qtd_;
        file >> item->price_;
    }
    else
    {
        cout << "File is not open";
    }

    return file;
}

Phone *Phone::new_phone()
{
    string name;
    string model;
    string os;
    string carrier;
    int qtd;
    float price;

    addField("name", name);
    addField("model", model);
    addField("os", os);
    addField("carrier", carrier);
    addField("qtd", qtd);
    addField("price", price);
    Phone *new_phone = new Phone(name, model, os, carrier, qtd, price);
    return new_phone;
}

Tablet *Tablet::new_tablet()
{
    string name, model, os, size;
    int qtd;
    float price;
    addField("name", name);
    addField("model", model);
    addField("os", os);
    addField("size", size);
    addField("quantity", qtd);
    addField("price", price);
    Tablet *new_tablet = new Tablet(name, model, os, size, qtd, price);
    return new_tablet;
}

Peripheral *Peripheral::new_peripheral()
{
    string name;
    int qtd;
    float price;
    addField("name", name);
    addField("quantity", qtd);
    addField("price", price);
    Peripheral *new_peripheral = new Peripheral(name, qtd, price);
    return new_peripheral;
}

Phone::Phone()
{
    this->type_ = "Phone";
}
Tablet::Tablet()
{
    this->type_ = "Tablet";
}
Peripheral::Peripheral()
{
    this->type_ = "Peripheral";
}