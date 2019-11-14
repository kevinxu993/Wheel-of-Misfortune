#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "family.h"

/* Number of word pointers allocated for a new family.
   This is also the number of word pointers added to a family
   using realloc, when the family is full.
*/
static int family_increment = 0;


/* Set family_increment to size, and initialize random number generator.
   The random number generator is used to select a random word from a family.
   This function should be called exactly once, on startup.
*/
void init_family(int size) {
    family_increment = size;
    srand(time(0));
}


/* Given a pointer to the head of a linked list of Family nodes,
   print each family's signature and words.

   Do not modify this function. It will be used for marking.
*/
void print_families(Family* fam_list) {
    int i;
    Family *fam = fam_list;
    
    while (fam) {
        printf("***Family signature: %s Num words: %d\n",
               fam->signature, fam->num_words);
        for(i = 0; i < fam->num_words; i++) {
            printf("     %s\n", fam->word_ptrs[i]);
        }
        printf("\n");
        fam = fam->next;
    }
}


/* Return a pointer to a new family whose signature is 
   a copy of str. Initialize word_ptrs to point to 
   family_increment+1 pointers, numwords to 0, 
   maxwords to family_increment, and next to NULL.
*/
Family *new_family(char *str) {
    Family *fam_pt = malloc(sizeof(Family));

    // init signature
    fam_pt->signature = malloc(strlen(str) + 1);
    strcpy(fam_pt->signature, str);

    // init word_ptrs
    fam_pt->word_ptrs = malloc((family_increment+1) * sizeof(char*));
    (fam_pt->word_ptrs)[family_increment] = NULL;

    // init numwords
    fam_pt->num_words = 0;

    // init maxwords
    fam_pt->max_words = family_increment;

    // init next
    fam_pt->next = NULL;

    return fam_pt;
}


/* Add word to the next free slot fam->word_ptrs.
   If fam->word_ptrs is full, first use realloc to allocate family_increment
   more pointers and then add the new pointer.
*/
void add_word_to_family(Family *fam, char *word) {
    if (fam->num_words == fam->max_words) {
        // full
        int new_capacity = fam->max_words + family_increment;
        char **new_array = realloc(fam->word_ptrs, (new_capacity + 1) * sizeof(char *));
        new_array[new_capacity] = NULL;
        fam->max_words = new_capacity;
        fam->word_ptrs = new_array;
        (fam->word_ptrs)[fam->num_words] = word;
        fam->num_words += 1;
    } else if (fam->num_words < fam->max_words) {
        // still at least one place left
        (fam->word_ptrs)[fam->num_words] = word;
        fam->num_words += 1;
    } else { // fam->num_words > fam->max_words
        // shouldn't happen
        fprintf(stderr, "ERROR: fam->num_words > fam->max_words\n");
        exit(1);
    }
}


/* Return a pointer to the family whose signature is sig;
   if there is no such family, return NULL.
   fam_list is a pointer to the head of a list of Family nodes.
*/
Family *find_family(Family *fam_list, char *sig) {
    Family *cur = fam_list;
    while (cur != NULL) {
        if (strcmp(cur->signature, sig) == 0) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}


/* Return a pointer to the family in the list with the most words;
   if the list is empty, return NULL. If multiple families have the most words,
   return a pointer to any of them.
   fam_list is a pointer to the head of a list of Family nodes.
*/
Family *find_biggest_family(Family *fam_list) {
    int max_words = 0;
    Family *biggest_family_ptr = NULL;
    Family *cur = fam_list;
    while (cur != NULL) {
        if (cur->num_words > max_words) {
            max_words = cur->num_words;
            biggest_family_ptr = cur;
        }
        cur = cur->next;
    }
    return biggest_family_ptr;
}


/* Deallocate all memory rooted in the List pointed to by fam_list. */
void deallocate_families(Family *fam_list) {
    Family *cur = fam_list;
    while (cur != NULL) {
        Family *tmp = cur->next;
        free(cur->signature);
        free(cur->word_ptrs);
        free(cur);
        cur = tmp;
    }
}

// Don't forget to free **
char *generate_sig_of_word(char *word, char letter) {
    char *sig = malloc(strlen(word) + 1);
    strcpy(sig, word);
    for (int i = 0; i < strlen(word); i++) {
        if (sig[i] != letter) {
            sig[i] = '-';
        }
    }
    return sig;
}

/* Generate and return a linked list of all families using words pointed to
   by word_list, using letter to partition the words.

   Implementation tips: To decide the family in which each word belongs, you
   will need to generate the signature of each word. Create only the families
   that have at least one word from the current word_list.
*/
Family *generate_families(char **word_list, char letter) {
    int word_count = 0;
    char **cur_word_pt = word_list;
    while ((*cur_word_pt) != NULL) {
        word_count++;
        cur_word_pt += 1;
    }
    char *sig_list[word_count+1];
    int used[word_count];
    sig_list[word_count] = NULL;
    for (int i = 0; i < word_count; i++) {
        sig_list[i] = generate_sig_of_word(word_list[i], letter);
        used[i] = 0; // unused
    }

    Family *head = NULL;
    for (int i = 0; i < word_count; i++) {
        if (used[i] == 1) {
            continue;
        }
        Family *word_family = new_family(sig_list[i]);
        add_word_to_family(word_family, word_list[i]);
        used[i] = 1;
        for (int j = i+1; j < word_count; j++) { 
            if (strcmp(sig_list[i], sig_list[j]) == 0) {
                add_word_to_family(word_family, word_list[j]);
                used[j] = 1;
            }
        }
        word_family->next = head;
        head = word_family;
    }

    for (int i = 0; i < word_count; i++) {
        free(sig_list[i]);
    }

    return head;
}


/* Return the signature of the family pointed to by fam. */
char *get_family_signature(Family *fam) {
    return fam->signature;
}


/* Return a pointer to word pointers, each of which
   points to a word in fam. These pointers should not be the same
   as those used by fam->word_ptrs (i.e. they should be independently malloc'd),
   because fam->word_ptrs can move during a realloc.
   As with fam->word_ptrs, the final pointer should be NULL.
*/
char **get_new_word_list(Family *fam) {
    char **new_word_list = malloc((fam->num_words + 1) * sizeof(char*));
    new_word_list[fam->num_words] = NULL;
    for (int i = 0; i < fam->num_words; i++) {
        new_word_list[i] = (fam->word_ptrs)[i];
    }
    return new_word_list;
}


/* Return a pointer to a random word from fam. 
   Use rand (man 3 rand) to generate random integers.
*/
char *get_random_word_from_family(Family *fam) {
    int random_idx = rand() % (fam->num_words);
    return (fam->word_ptrs)[random_idx];
}
