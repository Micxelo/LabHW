#include "contact.h"

#include <stdio.h>
#include <string.h>

static addrbook_t *addrbook;

static void command_runnner(void)
{
	char command[10], arg1[50], arg2[50];
	
	fscanf(stdin, "%s", command);

	if (strcmp(command, "add") == 0) {
		fscanf(stdin, "%s %s", arg1, arg2);
		contact_add(addrbook, arg1, arg2);
	} else if (strcmp(command, "update") == 0) {
		fscanf(stdin, "%s %s", arg1, arg2);
		contact_update(addrbook, arg1, arg2);
	} else if (strcmp(command, "delete") == 0) {
		fscanf(stdin, "%s", arg1);
		contact_delete(addrbook, arg1);
	} else if (strcmp(command, "find") == 0) {
		fscanf(stdin, "%s", arg1);
		contact_t *contact = contact_find(addrbook, arg1);
		if (contact != NULL)
			printf("%s\n", contact->phone);
		else
			printf("NOT FOUND\n");
	}
	else if (strcmp(command, "print") == 0) {
		contact_print(addrbook);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	fscanf(stdin, "%d", &n);

	addrbook = addrbook_create();
	while (n--)
		command_runnner();

	addrbook_cleanup(addrbook);
	return 0;
}

