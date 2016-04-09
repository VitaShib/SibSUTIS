#include "hashtab.h"

#define HASHTAB_MUL 31
#define HASHTAB_SIZE 128

unsigned int hashtab_hash(char *key)  /* Реализация из лекции 6 */
// Он же KPHash
{
	unsigned int h = 0;
	char *p;
	for (p = key; *p != '\0'; p++)
	{
		h = h * HASHTAB_MUL + (unsigned int)*p;
	}
	return h % HASHTAB_SIZE;
}

void hashtab_init(struct listnode **hashtab)
{
	int i;
	for (i = 0; i < HASHTAB_SIZE; i++)
	{
		hashtab[i] = NULL;
	}
}

void hashtab_add(struct listnode **hashtab, char *key, int value)
{
	struct listnode *node;
	int index = hashtab_hash(key);
	// Вставка в начало списка
	node = malloc(sizeof(*node));
	if (node != NULL)
	{
		node->key = key;
		node->value = value;
		node->next = hashtab[index];
		hashtab[index] = node;
	}
}

struct listnode *hashtab_lookup(struct listnode **hashtab, char *key)
{
	int index;
	struct listnode *node;
	index = hashtab_hash(key);
	for (node = hashtab[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
			return node;
	}
	return NULL;
}

void hashtab_delete(struct listnode **hashtab, char *key)
{
	int index;
	struct listnode *p, *prev = NULL;
	index = hashtab_hash(key);
	for (p = hashtab[index]; p != NULL; p = p->next)
	{
		if (strcmp(p->key, key) == 0)
		{
			if (prev == NULL
				hashtab[index] = p->next;
			else
				prev->next = p->next;
			free(p);
			return;
		}
		prev = p;
	}
}

unsigned FNV_Hash(void *key, int len)
{
    unsigned char *p = key;
    unsigned h = 2166136261;
    int i;

    for (i = 0; i < len; i++)
    {
        h = (h * 16777619) ^ p[i];
    }

    return h;
}

unsigned int KP_Hash(char *key)  /* Реализация из лекции 6 */
{
	unsigned int h = 0;
	char *p;
	for (p = key; *p != '\0'; p++)
	{
		h = h * HASHTAB_MUL + (unsigned int)*p;
	}
	return h % HASHTAB_SIZE;
}




unsigned int ADD_Hash(void *key, int len)
{
    unsigned char *p = key;
    unsigned h = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        h += p[i];
    }

    return h;
}

unsigned int XOR_Hash(void *key, int len)
{
    unsigned char *p = key;
    unsigned h = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        h ^= p[i];
    }

    return h;
}

uint32_t JENKINS_one_at_a_time_Hash(char *key, size_t len)
{
    uint32_t hash, i;
    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}
