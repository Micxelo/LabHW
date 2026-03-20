#ifndef __CONTACT_H__
#define __CONTACT_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct contact_t {
	char *name;
	char *phone;
} contact_t;

void contact_init(void);
contact_t *contact_find(const char *name);
void contact_add(const char *name, const char *phone);
void contact_delete(const char *name);
contact_t *contact_update(const char *name, const char *phone);
void contact_print(void);
void contact_cleanup(void);

#ifdef __cplusplus
}
#endif

#endif