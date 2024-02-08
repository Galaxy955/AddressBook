#ifndef ADDRESSBOOK_CONTACT_H
#define ADDRESSBOOK_CONTACT_H

#include <iostream>

using namespace std;

/*
 * Define the contact class, which includes the base information of a contact
 * and the function of showing the information of the contact.
 * */
class Contact{
public:
    // The base information of a contact.
    string name;
    string job;
    string description;
    string number;

    // The next pointer.
    Contact *next;

    // Initiate.
    Contact();

    // Showing information function.
    void show();
};

#endif //ADDRESSBOOK_CONTACT_H
