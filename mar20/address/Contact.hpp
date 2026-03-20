#pragma once

#include <string>
#include <vector>

class Contact
{
private:
	std::string name;
	std::string phoneNumber;
public:
	Contact() = default;
	Contact(const std::string& name, const std::string& phoneNumber) : name(name), phoneNumber(phoneNumber) {}
	~Contact() = default;
	auto GetName() const -> std::string { return name; }
	auto GetPhoneNumber() const -> std::string { return phoneNumber; }
	auto SetName(const std::string& newName) -> void { name = newName; }
	auto SetPhoneNumber(const std::string& newPhoneNumber) -> void { phoneNumber = newPhoneNumber; }
};

class AddressBook
{
private:
	std::vector<Contact> contacts;
public:
	AddressBook() = default;
	~AddressBook() = default;
	auto AddContact(const Contact& contact) -> void { contacts.push_back(contact); }
	auto GetContacts() const -> std::vector<Contact> { return contacts; }
	auto FindContact(const std::string& name) const -> Contact*;
	auto UpdateContact(const std::string& name, const std::string& newPhoneNumber) -> Contact*;
	auto DeleteContact(const std::string& name) -> void;
};
