#ifndef myHashTab
#define myHashTab

unsigned int hashtab_hash(char *key);  /* Реализация из лекции 6 */
void hashtab_init(struct listnode **hashtab);
void hashtab_add(struct listnode **hashtab, char *key, int value);
struct listnode *hashtab_lookup(struct listnode **hashtab, char *key);
void hashtab_delete(struct listnode **hashtab, char *key);

#endif
