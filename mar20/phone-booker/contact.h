#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct contact_t {
	char *name;
	char *phone;
} contact_t;

typedef struct addrbook_t {
	contact_t **contacts;
	size_t contact_count;
	size_t contact_capacity;
} addrbook_t;

void contact_add(addrbook_t *addrbook, const char *name, const char *phone);
void contact_delete(addrbook_t *addrbook, const char *name);
contact_t *contact_find(addrbook_t *addrbook, const char *name);
contact_t *contact_update(addrbook_t *addrbook, const char *name, const char *phone);
void contact_print(addrbook_t *addrbook);
void contact_cleanup(addrbook_t *addrbook);
addrbook_t *addrbook_create(void);
void addrbook_cleanup(addrbook_t *addrbook);

#ifdef __cplusplus
}
#endif

#endif
