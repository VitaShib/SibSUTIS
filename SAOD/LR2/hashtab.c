#include "hashtab.h"

unsigned int hashtab_hash(char *key)  /* Реализация из лекции 6 */
{

}

void hashtab_init(struct listnode **hashtab)
{

}

void hashtab_add(struct listnode **hashtab, char *key, int value)
{

}

struct listnode *hashtab_lookup(struct listnode **hashtab, char *key)
{

}

void hashtab_delete(struct listnode **hashtab, char *key)
{

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
