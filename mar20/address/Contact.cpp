#include "Contact.hpp"

#include <vector>
#include <string>
#include <algorithm>

auto AddressBook::FindContact(const std::string& name) const -> Contact*
{
	for (auto& contact : contacts)
	{
		if (contact.GetName() == name)
		{
			return const_cast<Contact*>(&contact);
		}
	}
	return nullptr;
}

auto AddressBook::UpdateContact(const std::string& name, const std::string& newPhoneNumber) -> Contact*
{
	for (auto& contact : contacts)
	{
		if (contact.GetName() == name)
		{
			contact.SetPhoneNumber(newPhoneNumber);
			return const_cast<Contact*>(&contact);
		}
	}
	return nullptr;
}

auto AddressBook::DeleteContact(const std::string& name) -> void
{
	contacts.erase(std::remove_if(contacts.begin(), contacts.end(),
		[&name](const Contact& contact) { return contact.GetName() == name; }),
		contacts.end());
}
