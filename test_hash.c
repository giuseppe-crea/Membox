#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include "icl_hash.h"
//#include "icl_hash.c"

/* ---------------------------------------------------------------------- 
 * Hashing funtions
 * Well known hash function: Fowler/Noll/Vo - 32 bit version
 */
static inline unsigned int fnv_hash_function( void *key, int len ) {
    unsigned char *p = (unsigned char*)key;
    unsigned int h = 2166136261u;
    int i;
    for ( i = 0; i < len; i++ )
    {
        h = ( h * 16777619 ) ^ p[i];
    }
    return h;
}
static inline unsigned int ulong_hash_function( void *key ) {
    int len = sizeof(unsigned long);
    unsigned int hashval = fnv_hash_function( key, len );
    return hashval;
}
static inline int ulong_key_compare( void *key1, void *key2  ) {
    return ( *(unsigned long*)key1 == *(unsigned long*)key2 );
}
/* --------------------------------------------------------------------- */

/*
int main() {

    icl_hash_t *hash = icl_hash_create(1024, ulong_hash_function, ulong_key_compare);
	icl_entry_t* value;
    long key1 = 1;
    long key2 = 2;
    long key3 = 3;
    long key4 = 4;
    long key5 = 5;
    int len1 = 1;
    int len2 = 1;
    int len3 = 1;
    int len4 = 1;
    int len5 = 1;

    value = icl_hash_insert(hash, &key1, &len1, (void*)key1);
    printf("key 1: %u\n", *(unsigned int*)value->key);
    value = icl_hash_insert(hash, &key2, &len2, (void*)key2);
    printf("key 2: %u\n", *(unsigned int*)value->key);
    value = icl_hash_insert(hash, &key3, &len3, (void*)key3);
    printf("key 3: %u\n", *(unsigned int*)value->key);
    value = icl_hash_insert(hash, &key4, &len4, (void*)key4);
    printf("key 4: %u\n", *(unsigned int*)value->key);
    value = icl_hash_insert(hash, &key5, &len5, (void*)key5);
    printf("key 5: %u\n", *(unsigned int*)value->key);

    icl_hash_delete(hash, &key3, NULL, NULL, NULL);
    icl_hash_delete(hash, &key5, NULL, NULL, NULL);

    if ( icl_hash_find(hash, &key1) != NULL) printf("Chiave %ld trovata\n", key1);
    else printf("Chiave %ld NON trovata\n", key1);
    if ( icl_hash_find(hash, &key2) != NULL) printf("Chiave %ld trovata\n", key2);
    else printf("Chiave %ld NON trovata\n", key2);
    if ( icl_hash_find(hash, &key3) != NULL) printf("Chiave %ld trovata\n", key3);
    else printf("Chiave %ld NON trovata\n", key3);
    if ( icl_hash_find(hash, &key4) != NULL) printf("Chiave %ld trovata\n", key4);
    else printf("Chiave %ld NON trovata\n", key4);
    if ( icl_hash_find(hash, &key5) != NULL) printf("Chiave %ld trovata\n", key5);
    else printf("Chiave %ld NON trovata\n", key5);

    icl_hash_destroy(hash, NULL, NULL, NULL);

    return 0;

}
//*/
