/*
 * This is an address book. It supports:
 * 1. show contact's information,
 * 2. add contacts,
 * 3. delete contacts,
 * 4. find contacts.
 * */

#include <iostream>
#include <string>
#include <unistd.h>
#include "Functions.h"

using namespace std;

int main() {
    // Initiate.
    Contact *address_book = init();

    // User interaction.
    string operation;
    while(true){
        cout << "------- MENU -------" << endl;
        cout << "Choose the operation you want:" << endl;
        cout << "1. Add a new contact.\t2. Delete a contact.\t3. Find a contact.\t4. Show the complete address book."
                "\t5. Exit" << endl;
        cin >> operation;
        if(operation == "1"){
            cout << "Enter <Name,Job,Description,Phone Number> of the new contact:" << endl;
            string new_information;
            cin.ignore();
            getline(cin, new_information);
            string name, job, description, number;
            information_split(name, job, description, number, new_information);
            add_contact(name, job, description, number, address_book);
        }
        else if(operation == "2"){
            cout << "Enter the name or the phone number of the contact you want to delete." << endl;
            string target;
            cin.ignore();
            getline(cin, target);
            delete_contact(target, address_book);
        }
        else if(operation == "3"){
            cout << "Enter the clue to find the contact:" << endl;
            string clue;
            cin.ignore();
            getline(cin, clue);
            find_contact(clue, address_book);
        }
        else if(operation == "4"){
            show_complete_address_book(address_book);
        }
        else if(operation == "5"){
            cout << "------ Bye~ --------" << endl;
            break;
        }else{
            cout << "The code you chosen is not correct, please try again." << endl;
            cin.ignore();
        }
        cout << "--------------------" << endl;
        sleep(1);
    }

    // Clean the pile.
    clean_up(address_book);
    return 0;
}