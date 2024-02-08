#include "Contact.h"
#include <iostream>

using namespace std;

Contact::Contact() {
    name = "Unknown";
    job = "Unknown";
    description = "This is a blank contact.";
    number = "Unknown";
    next = nullptr;
}

void Contact::show(){
    cout << "--------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Job: " << job << endl;
    cout << "Description: " << description << endl;
    cout << "Phone Number: " << number << endl;
}