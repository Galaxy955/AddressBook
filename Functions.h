#ifndef ADDRESSBOOK_FUNCTIONS_H
#define ADDRESSBOOK_FUNCTIONS_H

#include "Contact.h"

// Initiate.
Contact *init();

// Add a contact.
void add_contact(string &name, string &job, string &description, string &number, Contact *address_book);

// Find a contact.
void find_contact(string &clue, Contact *address_book);

// Delete a contact.
void delete_contact(string &target, Contact *address_book);

// Show the complete address book.
void show_complete_address_book(Contact *address_book);

// Clean the storage of the pile.
void clean_up(Contact *address_book);

// Split a string.
void information_split(string &name, string &job, string &description, string &number, string &isstream);

#endif //ADDRESSBOOK_FUNCTIONS_H
