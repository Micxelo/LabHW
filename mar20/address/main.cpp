#include "Contact.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main(int argc, char const *argv[])
{
    AddressBook addressBook;
    int q;
    std::cin >> q;
    std::cin.ignore(); // 忽略换行符

    for (int i = 0; i < q; ++i) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "add") {
            std::string name, phone;
            iss >> name >> phone;
            bool exists = false;
            for (const auto& contact : addressBook.GetContacts()) {
                if (contact.GetName() == name) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                addressBook.AddContact(Contact(name, phone));
            }
        } else if (command == "update") {
            std::string name, phone;
            iss >> name >> phone;
            Contact* contact = addressBook.UpdateContact(name, phone);
            if (contact) {
                contact->SetPhoneNumber(phone);
            }
        } else if (command == "delete") {
            std::string name;
            iss >> name;
            addressBook.DeleteContact(name);
        } else if (command == "find") {
            std::string name;
            iss >> name;
            const Contact* contact = nullptr;
            for (const auto& c : addressBook.GetContacts()) {
                if (c.GetName() == name) {
                    contact = &c;
                    break;
                }
            }
            if (contact) {
                std::cout << contact->GetPhoneNumber() << std::endl;
            } else {
                std::cout << "NOT FOUND" << std::endl;
            }
        } else if (command == "print") {
            const auto& contacts = addressBook.GetContacts();
            if (contacts.empty()) {
                std::cout << "EMPTY" << std::endl;
            } else {
                for (size_t j = 0; j < contacts.size(); ++j) {
                    std::cout << contacts[j].GetName() << ":" << contacts[j].GetPhoneNumber();
                    if (j < contacts.size() - 1) {
                        std::cout << " ";
                    }
                }
                std::cout << std::endl;
            }
        }
    }

    return 0;
}

