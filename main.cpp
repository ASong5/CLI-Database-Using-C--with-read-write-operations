#include <iostream>
#include <string>

#include "database.h"

int main()
{

    Database database;

    std::string choice;
    std::cout << "Welcome to our database system. What do you want to do?" << std::endl;
    std::cout << "Options are: Retrieve Database (retrieve) or Create New Database (create): ";
    std::cin >> choice;
    if (choice == "retrieve")
    {
        while (true)
        {
            std::cout << "Enter the database file name:" << std::endl;
            std::cin >> choice;
            if (database.retrieve_database(choice))
            {
                break;
            }
            else
            {
                std::cout << "Enter a valid database file name." << std::endl;
            }
        }
    }
    else if (choice == "create")
    {
        while (true)
        {
            std::cout << "Do you want to add a new item (y/n)?";
            std::cin >> choice;
            if (choice == "y")
            {
                database.add_item();
            }
            else
            {
                break;
            }
        }
    }

    while (true)
    {
        std::cout << "What do you want to do now?" << std::endl;
        std::cout << "[add] new item, [edit] existing item, [display] items, [sell] item, [save] database, or [quit]? ";
        std::cin >> choice;
        if (choice == "add")
        {
            database.add_item();
        }
        else if (choice == "edit")
        {
            int number;
            std::cout << "What is the number of the item you want to edit? ";
            std::cin >> number;
            database.edit_item(number);
        }
        else if (choice == "sell")
        {
            int number;
            std::cout << "What is the number of the item you want to sell? ";
            std::cin >> number;
            database.sell_item(number);
        }
        else if (choice == "display")
        {
            database.display_items();
        }
        else if (choice == "save")
        {
            std::cout << "Enter the database file name:" << std::endl;
            std::cin >> choice;
            if (!database.save_database(choice))
            {
                std::cout << "Could not database file name." << std::endl;
            }
        }
        else if (choice == "quit")
        {
            break;
        }
        else
        {
            std::cout << "Invalid option!" << std::endl;
        }
    }
    return 0;
}