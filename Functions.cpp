#include <iostream>
#include <string>
#include <sstream>
#include "Functions.h"

using namespace std;

Contact *init(){
    Contact *header = new Contact;
    header->name = "Header";
    header->description = "This is the header of the address book.";
    return header;
}

void add_contact(string &name, string &job, string &description, string &number, Contact *address_book){
    // Logging data.
    Contact *new_contact = new Contact;
    new_contact->name = name;
    new_contact->job = job;
    new_contact->description = description;
    new_contact->number = number;

    // Add the new contact to the head of the address book.
    Contact *p = address_book->next;
    new_contact->next = p;
    address_book->next = new_contact;
}

void find_contact(string &clue, Contact *address_book){
    // isFound status.
    int isFound = 0;
    Contact *p = address_book;
    while(p != nullptr){
        if(p->name == clue || p->job == clue || p->number == clue){
            // Have found the contact. Show the information of the contact.
            p->show();
            isFound = 1;
        }
        p = p->next;
    }
    // The contact you want to find is not existed.
    if(isFound == 0){
        cout << "--------------------" << endl;
        cout << "The contact you want to find is not existed." << endl;
    }
}

void delete_contact(string &target, Contact *address_book){
    // Find the contact first.
    Contact *p = address_book->next;
    Contact *q = address_book;
    while(p != nullptr){
        if(p->name == target || p->number == target){
            // Have found the contact. Show the information of the contact.
            cout << "The contact you want to delete is:" << endl;
            p->show();
            cout << "--------------------" << endl;
            cout << "Enter [Y/y] to confirm." << endl;
            string confirm;
            cin >> confirm;
            if(confirm == "Y" or confirm == "y"){
                // Delete the contact.
                q->next = p->next;
                delete(p);
                p = q->next;
            }else{
                cout << "The delete operation is canceled." << endl;
                q = p;
                p = p->next;
            }
        }else {
            q = p;
            p = p->next;
        }
    }
}

void show_complete_address_book(Contact *address_book){
    Contact *p = address_book->next;
    while(p != nullptr){
        p->show();
        p = p->next;
    }
}

void clean_up(Contact *address_book){
    Contact *p = address_book->next;
    Contact *q = address_book;
    while(p != nullptr){
        q->next = p->next;
        delete(p);
        p = q->next;
    }
    delete(q);
}

void information_split(string &name, string &job, string &description, string &number, string &isstream){
    istringstream iss(isstream);
    string buffer[4];
    for(int i = 0; i < 4; i++){
        getline(iss, buffer[i], ',');
    }
    name = buffer[0];
    job = buffer[1];
    description = buffer[2];
    number = buffer[3];
}