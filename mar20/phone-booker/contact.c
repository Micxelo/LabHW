#include "contact.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define CONTACT_DEFAULT_CAPACITY			20

char *_strdup(const char *s)
{
	size_t len = strlen(s);
	char *copy = (char *) malloc(len + 1);
	strcpy(copy, s);
	return copy;
}

/**
 * @brief 扩展容量（当前 * 2）
 */
static void contact_expand_capacity(addrbook_t *addrbook)
{
	size_t new_capacity = addrbook->contact_capacity * 2;
	contact_t **new_contacts = (contact_t **) malloc(sizeof(contact_t *) * new_capacity);
	memcpy(new_contacts, addrbook->contacts, sizeof(contact_t *) * addrbook->contact_count);
	free(addrbook->contacts);
	addrbook->contacts = new_contacts;
	addrbook->contact_capacity = new_capacity;
}

/**
 * @brief 查找联系人
 */
contact_t *contact_find(addrbook_t *addrbook, const char *name)
{
	for (size_t i = 0; i < addrbook->contact_count; i++)
		if (strcmp(addrbook->contacts[i]->name, name) == 0)
			return addrbook->contacts[i];

	return NULL;
}

/**
 * @brief 添加联系人
 */
void contact_add(addrbook_t *addrbook, const char *name, const char *phone)
{
	contact_t *contact = contact_find(addrbook, name);
	if (contact != NULL)
		return;

	if (addrbook->contact_count >= addrbook->contact_capacity)
		contact_expand_capacity(addrbook);

	contact = (contact_t *) malloc(sizeof(contact_t));
	contact->name = _strdup(name);
	contact->phone = _strdup(phone);
	addrbook->contacts[addrbook->contact_count++] = contact;
}

/**
 * @brief 删除联系人
 */
void contact_delete(addrbook_t *addrbook, const char *name)
{
	for (size_t i = 0; i < addrbook->contact_count; i++) {
		if (strcmp(addrbook->contacts[i]->name, name) == 0) {
			free(addrbook->contacts[i]->name);
			free(addrbook->contacts[i]->phone);
			free(addrbook->contacts[i]);
			for (size_t j = i; j < addrbook->contact_count - 1; j++)
				addrbook->contacts[j] = addrbook->contacts[j + 1];
				
			addrbook->contact_count--;
			return;
		}
	}
}

/**
 * @brief 更新联系人电话
 */
contact_t *contact_update(addrbook_t *addrbook, const char *name, const char *phone)
{
	contact_t *contact = contact_find(addrbook, name);
	if (contact == NULL)
		return NULL;

	free(contact->phone);
	contact->phone = _strdup(phone);
	return contact;
}

/**
 * @brief 打印联系人列表
 */
void contact_print(addrbook_t *addrbook)
{
	if (addrbook->contact_count == 0) {
		fprintf(stdout, "EMPTY\n");
		return;
	}

	for (size_t i = 0; i < addrbook->contact_count; i++)
		fprintf(stdout, "%s:%s ", addrbook->contacts[i]->name, addrbook->contacts[i]->phone);

	fprintf(stdout, "\n");
}

/**
 * @brief 清理
 */
void contact_cleanup(addrbook_t *addrbook)
{
	for (size_t i = 0; i < addrbook->contact_count; i++) {
		free(addrbook->contacts[i]->name);
		free(addrbook->contacts[i]->phone);
		free(addrbook->contacts[i]);
	}
	free(addrbook->contacts);
	addrbook->contacts = NULL;
	addrbook->contact_count = 0;
	addrbook->contact_capacity = 0;
}

/**
 * @brief 创建地址簿
 */
addrbook_t *addrbook_create(void)
{
	addrbook_t *addrbook = (addrbook_t *) malloc(sizeof(addrbook_t));
	addrbook->contacts = (contact_t **) malloc(sizeof(contact_t *) * CONTACT_DEFAULT_CAPACITY);
	addrbook->contact_count = 0;
	addrbook->contact_capacity = CONTACT_DEFAULT_CAPACITY;
	return addrbook;
}

/**
 * @brief 销毁地址簿
 */
void addrbook_cleanup(addrbook_t *addrbook)
{
	for (size_t i = 0; i < addrbook->contact_count; i++) {
		free(addrbook->contacts[i]->name);
		free(addrbook->contacts[i]->phone);
		free(addrbook->contacts[i]);
	}
	free(addrbook->contacts);
	free(addrbook);
}
