#include "contact.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define CONTACT_DEFAULT_CAPACITY			20

static size_t contact_count = 0;							/* 当前通讯录数量 */
static size_t contact_capacity = CONTACT_DEFAULT_CAPACITY;	/* 当前通讯录容量 */
static contact_t **contacts = NULL;							/* 通讯录数组 */

char *_strdup(const char *s)
{
	size_t len = strlen(s);
	char *copy = (char *) malloc(len + 1);
	strcpy(copy, s);
	return copy;
}

/**
 * @brief 初始化，默认上限 20 。
 */
void contact_init(void)
{
	contact_count = 0;
	contacts = (contact_t **) malloc(sizeof(contact_t *) * CONTACT_DEFAULT_CAPACITY);
	contact_capacity = CONTACT_DEFAULT_CAPACITY;
}

/**
 * @brief 扩展容量（当前 * 2）
 */
static void contact_expand_capacity(void)
{
	size_t new_capacity = contact_capacity * 2;
	contact_t **new_contacts = (contact_t **) malloc(sizeof(contact_t *) * new_capacity);
	memcpy(new_contacts, contacts, sizeof(contact_t *) * contact_count);
	free(contacts);
	contacts = new_contacts;
	contact_capacity = new_capacity;
}

/**
 * @brief 查找联系人
 */
contact_t *contact_find(const char *name)
{
	for (size_t i = 0; i < contact_count; i++)
		if (strcmp(contacts[i]->name, name) == 0)
			return contacts[i];

	return NULL;
}

/**
 * @brief 添加联系人
 */
void contact_add(const char *name, const char *phone)
{
	contact_t *contact = contact_find(name);
	if (contact != NULL)
		return;

	if (contact_count >= contact_capacity)
		contact_expand_capacity();

	contact = (contact_t *) malloc(sizeof(contact_t));
	contact->name = _strdup(name);
	contact->phone = _strdup(phone);
	contacts[contact_count++] = contact;
}

/**
 * @brief 删除联系人
 */
void contact_delete(const char *name)
{
	for (size_t i = 0; i < contact_count; i++) {
		if (strcmp(contacts[i]->name, name) == 0) {
			free(contacts[i]->name);
			free(contacts[i]->phone);
			free(contacts[i]);
			for (size_t j = i; j < contact_count - 1; j++)
				contacts[j] = contacts[j + 1];
				
			contact_count--;
			return;
		}
	}
}

/**
 * @brief 更新联系人电话
 */
contact_t *contact_update(const char *name, const char *phone)
{
	contact_t *contact = contact_find(name);
	if (contact == NULL)
		return NULL;

	free(contact->phone);
	contact->phone = _strdup(phone);
	return contact;
}

/**
 * @brief 打印联系人列表
 */
void contact_print(void)
{
	if (contact_count == 0) {
		fprintf(stdout, "EMPTY\n");
		return;
	}

	for (size_t i = 0; i < contact_count; i++)
		fprintf(stdout, "%s:%s ", contacts[i]->name, contacts[i]->phone);

	fprintf(stdout, "\n");
}

/**
 * @brief 清理
 */
void contact_cleanup(void)
{
	for (size_t i = 0; i < contact_count; i++) {
		free(contacts[i]->name);
		free(contacts[i]->phone);
		free(contacts[i]);
	}
	free(contacts);
	contacts = NULL;
	contact_count = 0;
	contact_capacity = 0;
}
