/*                ___           ___                       ___
      ___        /  /\         /  /\          ___        /  /\
     /  /\      /  /:/_       /  /:/_        /  /\      /  /:/_
    /  /:/     /  /:/ /\     /  /:/ /\      /  /:/     /  /:/ /\
   /  /:/     /  /:/ /:/_   /  /:/ /::\    /  /:/     /  /:/ /::\
  /  /::\    /__/:/ /:/ /\ /__/:/ /:/\:\  /  /::\    /__/:/ /:/\:\
 /__/:/\:\   \  \:\/:/ /:/ \  \:\/:/~/:/ /__/:/\:\   \  \:\/:/~/:/
 \__\/  \:\   \  \::/ /:/   \  \::/ /:/  \__\/  \:\   \  \::/ /:/
      \  \:\   \  \:\/:/     \__\/ /:/        \  \:\   \__\/ /:/
       \__\/    \  \::/        /__/:/          \__\/     /__/:/
                 \__\/         \__\/                     \__\/


       tests.c
       Created by Adrian Sanchez
       Created on 07/02/2017
*/

/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/


#include <stdlib.h>
#include <stdio.h>
#include "globalconst.h"
#include "String.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "HashMap.h"

void printheader(char *message);
void repeatprint(char c, int times);

/*/$$$$$$  /$$$$$$$$ /$$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$
 /$$__  $$|__  $$__/| $$__  $$|_  $$_/| $$$ | $$ /$$__  $$
| $$  \__/   | $$   | $$  \ $$  | $$  | $$$$| $$| $$  \__/
|  $$$$$$    | $$   | $$$$$$$/  | $$  | $$ $$ $$| $$ /$$$$
 \____  $$   | $$   | $$__  $$  | $$  | $$  $$$$| $$|_  $$
 /$$  \ $$   | $$   | $$  \ $$  | $$  | $$\  $$$| $$  \ $$
|  $$$$$$/   | $$   | $$  | $$ /$$$$$$| $$ \  $$|  $$$$$$/
 \______/    |__/   |__/  |__/|______/|__/  \__/ \______/*/

void test_make_a_new_string(void);
void test_get_the_length_of_string(void);
void test_two_string_equal(void);
void test_append_onto_a_string(void);
void test_delete_the_string_contents(void);
void test_get_string_character_at_index(void);
void test_set_string_character_at_index(void);
void test_copy_a_string(void);
void test_concatenate_two_strings(void);
void test_compare_two_strings(void);
void test_find_first_occurrence_of_character(void);
void test_find_first_occurrence_of_any_of_provided(void);
void test_find_last_occurrence_of_character(void);
void test_get_the_count_of_first_contiguous_occurrences_of_any_of_provided(void);
void test_is_string_a_substring_of_the_other(void);
void test_trim_string_whitespace_from_tail(void);
void test_trim_string_whitespace_from_head(void);
void test_trim_string_whitespace(void);
void test_get_index_of_character(void);
void test_convert_string_to_lowercase(void);
void test_convert_string_to_uppercase(void);
void test_reverse_a_string(void);
void test_count_the_words_in_a_string(void);
void test_does_a_string_start_with_another_string(void);
void test_remove_occurrences_of_character_from_string(void);
void test_tokenize_a_string(void);

/*/$$$$$$  /$$$$$$$  /$$$$$$$   /$$$$$$  /$$     /$$ /$$       /$$$$$$  /$$$$$$  /$$$$$$$$
 /$$__  $$| $$__  $$| $$__  $$ /$$__  $$|  $$   /$$/| $$      |_  $$_/ /$$__  $$|__  $$__/
| $$  \ $$| $$  \ $$| $$  \ $$| $$  \ $$ \  $$ /$$/ | $$        | $$  | $$  \__/   | $$
| $$$$$$$$| $$$$$$$/| $$$$$$$/| $$$$$$$$  \  $$$$/  | $$        | $$  |  $$$$$$    | $$
| $$__  $$| $$__  $$| $$__  $$| $$__  $$   \  $$/   | $$        | $$   \____  $$   | $$
| $$  | $$| $$  \ $$| $$  \ $$| $$  | $$    | $$    | $$        | $$   /$$  \ $$   | $$
| $$  | $$| $$  | $$| $$  | $$| $$  | $$    | $$    | $$$$$$$$ /$$$$$$|  $$$$$$/   | $$
|__/  |__/|__/  |__/|__/  |__/|__/  |__/    |__/    |________/|______/ \______/    |__/*/

void test_create_a_new_arraylist(void);
void test_add_to_an_arraylist(void);
void test_remove_from_an_arraylist(void);
void test_remove_last_from_an_arraylist(void);
void test_set_element_of_arraylist(void);
void test_get_element_of_arraylist(void);
void test_compact_an_arraylist(void);
void test_clear_an_arraylist(void);
void test_copy_an_arraylist(void);
void test_expand_capacity_of_arraylist(void);

/*/$$       /$$$$$$ /$$   /$$ /$$   /$$ /$$$$$$$$ /$$$$$$$  /$$       /$$$$$$  /$$$$$$  /$$$$$$$$
 | $$      |_  $$_/| $$$ | $$| $$  /$$/| $$_____/| $$__  $$| $$      |_  $$_/ /$$__  $$|__  $$__/
 | $$        | $$  | $$$$| $$| $$ /$$/ | $$      | $$  \ $$| $$        | $$  | $$  \__/   | $$
 | $$        | $$  | $$ $$ $$| $$$$$/  | $$$$$   | $$  | $$| $$        | $$  |  $$$$$$    | $$
 | $$        | $$  | $$  $$$$| $$  $$  | $$__/   | $$  | $$| $$        | $$   \____  $$   | $$
 | $$        | $$  | $$\  $$$| $$\  $$ | $$      | $$  | $$| $$        | $$   /$$  \ $$   | $$
 | $$$$$$$$ /$$$$$$| $$ \  $$| $$ \  $$| $$$$$$$$| $$$$$$$/| $$$$$$$$ /$$$$$$|  $$$$$$/   | $$
 |________/|______/|__/  \__/|__/  \__/|________/|_______/ |________/|______/ \______/    |__/*/

void test_create_a_new_linkedlist(void);
void test_insert_element_after_node(void);
void test_insert_element_before_node(void);
void test_insert_element_at_linkedlist_head(void);
void test_insert_element_at_linkedlist_tail(void);
void test_remove_element_from_linkedlist(void);
void test_remove_element_at_linkedlist_head(void);
void test_remove_element_at_linkedlist_tail(void);
void test_convert_array_to_linkedlist(void);
void test_convert_linkedlist_to_array(void);
void test_check_if_item_in_linkedlist(void);
void test_get_linkedlist_item_at_index(void);
void test_get_size_of_a_linkedlist(void);

/*/$$   /$$  /$$$$$$   /$$$$$$  /$$   /$$ /$$      /$$  /$$$$$$  /$$$$$$$
 | $$  | $$ /$$__  $$ /$$__  $$| $$  | $$| $$$    /$$$ /$$__  $$| $$__  $$
 | $$  | $$| $$  \ $$| $$  \__/| $$  | $$| $$$$  /$$$$| $$  \ $$| $$  \ $$
 | $$$$$$$$| $$$$$$$$|  $$$$$$ | $$$$$$$$| $$ $$/$$ $$| $$$$$$$$| $$$$$$$/
 | $$__  $$| $$__  $$ \____  $$| $$__  $$| $$  $$$| $$| $$__  $$| $$____/
 | $$  | $$| $$  | $$ /$$  \ $$| $$  | $$| $$\  $ | $$| $$  | $$| $$
 | $$  | $$| $$  | $$|  $$$$$$/| $$  | $$| $$ \/  | $$| $$  | $$| $$
 |__/  |__/|__/  |__/ \______/ |__/  |__/|__/     |__/|__/  |__/|__/*/

void test_create_a_new_hashmap(void);
void test_set_element_for_key_in_hashmap(void);
void test_get_element_for_key_in_hashmap(void);
void test_remove_element_for_key_in_hashmap(void);
void test_clear_a_hashmap(void);
void test_get_size_of_a_hashmap(void);


/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/


int main(int argc, char **argv) {

/*/$$$$$$  /$$$$$$$$ /$$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$
 /$$__  $$|__  $$__/| $$__  $$|_  $$_/| $$$ | $$ /$$__  $$
| $$  \__/   | $$   | $$  \ $$  | $$  | $$$$| $$| $$  \__/
|  $$$$$$    | $$   | $$$$$$$/  | $$  | $$ $$ $$| $$ /$$$$
 \____  $$   | $$   | $$__  $$  | $$  | $$  $$$$| $$|_  $$
 /$$  \ $$   | $$   | $$  \ $$  | $$  | $$\  $$$| $$  \ $$
|  $$$$$$/   | $$   | $$  | $$ /$$$$$$| $$ \  $$|  $$$$$$/
 \______/    |__/   |__/  |__/|______/|__/  \__/ \______/*/


    test_make_a_new_string();
    test_get_the_length_of_string();
    test_two_string_equal();
    test_append_onto_a_string();
    test_delete_the_string_contents();
    test_get_string_character_at_index();
    test_set_string_character_at_index();
    test_copy_a_string();
    test_concatenate_two_strings();
    test_compare_two_strings();
    test_find_first_occurrence_of_character();
    test_find_first_occurrence_of_any_of_provided();
    test_find_last_occurrence_of_character();
    test_get_the_count_of_first_contiguous_occurrences_of_any_of_provided();
    test_is_string_a_substring_of_the_other();
    test_trim_string_whitespace_from_tail();
    test_trim_string_whitespace_from_head();
    test_trim_string_whitespace();
    test_get_index_of_character();
    test_convert_string_to_lowercase();
    test_convert_string_to_uppercase();
    test_reverse_a_string();
    test_count_the_words_in_a_string();
    test_does_a_string_start_with_another_string();
    test_remove_occurrences_of_character_from_string();
    test_tokenize_a_string();


/*/$$$$$$  /$$$$$$$  /$$$$$$$   /$$$$$$  /$$     /$$ /$$       /$$$$$$  /$$$$$$  /$$$$$$$$
 /$$__  $$| $$__  $$| $$__  $$ /$$__  $$|  $$   /$$/| $$      |_  $$_/ /$$__  $$|__  $$__/
| $$  \ $$| $$  \ $$| $$  \ $$| $$  \ $$ \  $$ /$$/ | $$        | $$  | $$  \__/   | $$
| $$$$$$$$| $$$$$$$/| $$$$$$$/| $$$$$$$$  \  $$$$/  | $$        | $$  |  $$$$$$    | $$
| $$__  $$| $$__  $$| $$__  $$| $$__  $$   \  $$/   | $$        | $$   \____  $$   | $$
| $$  | $$| $$  \ $$| $$  \ $$| $$  | $$    | $$    | $$        | $$   /$$  \ $$   | $$
| $$  | $$| $$  | $$| $$  | $$| $$  | $$    | $$    | $$$$$$$$ /$$$$$$|  $$$$$$/   | $$
|__/  |__/|__/  |__/|__/  |__/|__/  |__/    |__/    |________/|______/ \______/    |__/*/


    test_create_a_new_arraylist();
    test_add_to_an_arraylist();
    test_remove_from_an_arraylist();
    test_remove_last_from_an_arraylist();
    test_set_element_of_arraylist();
    test_get_element_of_arraylist();
    test_compact_an_arraylist();
    test_clear_an_arraylist();
    test_copy_an_arraylist();
    test_expand_capacity_of_arraylist();


/*/$$       /$$$$$$ /$$   /$$ /$$   /$$ /$$$$$$$$ /$$$$$$$  /$$       /$$$$$$  /$$$$$$  /$$$$$$$$
 | $$      |_  $$_/| $$$ | $$| $$  /$$/| $$_____/| $$__  $$| $$      |_  $$_/ /$$__  $$|__  $$__/
 | $$        | $$  | $$$$| $$| $$ /$$/ | $$      | $$  \ $$| $$        | $$  | $$  \__/   | $$
 | $$        | $$  | $$ $$ $$| $$$$$/  | $$$$$   | $$  | $$| $$        | $$  |  $$$$$$    | $$
 | $$        | $$  | $$  $$$$| $$  $$  | $$__/   | $$  | $$| $$        | $$   \____  $$   | $$
 | $$        | $$  | $$\  $$$| $$\  $$ | $$      | $$  | $$| $$        | $$   /$$  \ $$   | $$
 | $$$$$$$$ /$$$$$$| $$ \  $$| $$ \  $$| $$$$$$$$| $$$$$$$/| $$$$$$$$ /$$$$$$|  $$$$$$/   | $$
 |________/|______/|__/  \__/|__/  \__/|________/|_______/ |________/|______/ \______/    |__/*/


    test_create_a_new_linkedlist();
    test_insert_element_after_node();
    test_insert_element_before_node();
    test_insert_element_at_linkedlist_head();
    test_insert_element_at_linkedlist_tail();
    test_remove_element_from_linkedlist();
    test_remove_element_at_linkedlist_head();
    test_remove_element_at_linkedlist_tail();
    test_convert_array_to_linkedlist();
    test_convert_linkedlist_to_array();
    test_check_if_item_in_linkedlist();
    test_get_linkedlist_item_at_index();
    test_get_size_of_a_linkedlist();


/*/$$   /$$  /$$$$$$   /$$$$$$  /$$   /$$ /$$      /$$  /$$$$$$  /$$$$$$$
 | $$  | $$ /$$__  $$ /$$__  $$| $$  | $$| $$$    /$$$ /$$__  $$| $$__  $$
 | $$  | $$| $$  \ $$| $$  \__/| $$  | $$| $$$$  /$$$$| $$  \ $$| $$  \ $$
 | $$$$$$$$| $$$$$$$$|  $$$$$$ | $$$$$$$$| $$ $$/$$ $$| $$$$$$$$| $$$$$$$/
 | $$__  $$| $$__  $$ \____  $$| $$__  $$| $$  $$$| $$| $$__  $$| $$____/
 | $$  | $$| $$  | $$ /$$  \ $$| $$  | $$| $$\  $ | $$| $$  | $$| $$
 | $$  | $$| $$  | $$|  $$$$$$/| $$  | $$| $$ \/  | $$| $$  | $$| $$
 |__/  |__/|__/  |__/ \______/ |__/  |__/|__/     |__/|__/  |__/|__/*/


    test_create_a_new_hashmap();
    test_set_element_for_key_in_hashmap();
    test_get_element_for_key_in_hashmap();
    test_remove_element_for_key_in_hashmap();
    test_clear_a_hashmap();
    test_get_size_of_a_hashmap();


    return 0;
}

/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/

/*
    Note: Ideally, tests should use C's assert method to check for preconditions, postconditions and invariants, but
    this will not allow for custom diagnostic messages and will prohibit more fine grained control of the testing process.
*/


/*/$$$$$$  /$$$$$$$$ /$$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$
 /$$__  $$|__  $$__/| $$__  $$|_  $$_/| $$$ | $$ /$$__  $$
| $$  \__/   | $$   | $$  \ $$  | $$  | $$$$| $$| $$  \__/
|  $$$$$$    | $$   | $$$$$$$/  | $$  | $$ $$ $$| $$ /$$$$
 \____  $$   | $$   | $$__  $$  | $$  | $$  $$$$| $$|_  $$
 /$$  \ $$   | $$   | $$  \ $$  | $$  | $$\  $$$| $$  \ $$
|  $$$$$$/   | $$   | $$  | $$ /$$$$$$| $$ \  $$|  $$$$$$/
 \______/    |__/   |__/  |__/|______/|__/  \__/ \______/*/


void test_make_a_new_string() {
    printheader("Create a String");

    String *str = (String *) malloc(sizeof(String));
    if(String_New(str, "Hello World!")) {
        size_t strhash = String_GetHashCode(str);
        printf("[SUCCESS]: Created string %lu\n", strhash);
        String_Print(str);
        printf("\n");
        String_Free(str);
    }
    else {
        fprintf(stderr, "[ERROR]: Could not allocate space for string\n");
        exit(1);
    }
}

void test_get_the_length_of_string() {
    printheader("String length");

    String *str = (String *) malloc(sizeof(String));
    size_t strhash = String_GetHashCode(str);
    String_New(str, "We must go to great lengths to measure");
    printf("[SUCCESS]: The length of string %lu is %d\n", strhash, (int) String_Len(str));
    String_Print(str); printf("\n");

    String_Free(str);
}

void test_two_string_equal() {
    printheader("String equality");

    String *one = (String *) malloc(sizeof(String));
    String *two = (String *) malloc(sizeof(String));

    String_New(one, "Thing One");
    String_New(two, "Thing Two");

    size_t strhash1 = String_GetHashCode(one);
    size_t strhash2 = String_GetHashCode(two);

    if(String_Equal(one, two) != 0) {
        printf("[SUCCESS]: string %lu is string %lu\n\n", strhash1, strhash2);
        String_Print(one);
    } else {
        printf("[SUCCESS]: string %lu is not string %lu\n", strhash1, strhash2);
        String_Print(one);
        String_Print(two);
        printf("\n");
    }

    String_Free(one); String_Free(two);
}

void test_append_onto_a_string() {
    printheader("Append to String");

    String *original = (String *) malloc(sizeof(String));
    String_New(original, "Forget it Jake");

    size_t oldhash = String_GetHashCode(original);
    printf("[INFO]: Appending onto %lu...\n", oldhash);
    String_Print(original);
    if(String_Append(original, ", it's Chinatown.")) {
        size_t newhash = String_GetHashCode(original);
        printf("[SUCCESS]: String %lu is now %lu\n", oldhash, newhash);
        String_Print(original); printf("\n");
        String_Free(original);
    } else {
        fprintf(stderr, "[ERROR]: String %lu could not be appended to.\n", oldhash);
        String_Free(original);
        exit(2);
    }
}

void test_delete_the_string_contents() {
    printheader("Delete String contents");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "I won't be around for long");

    size_t oldhash = String_GetHashCode(str);
    String_Delete(str);
    printf("[SUCCESS]: Removed the contents of string %lu\n\n", oldhash);

    String_Free(str);
}

void test_get_string_character_at_index() {
    printheader("Get String Character");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "The quick brown fox jumped over the lazy dog... The quick brown fox got a trophy");

    size_t index = String_Len(str) / 2 - 1;
    size_t strhash = String_GetHashCode(str);
    char c;
    if(!(c = String_GetChar(str, index))) {
        fprintf(stderr, "[ERROR]: Could not get character from string %lu. Index is out of range.\n", strhash);
        String_Free(str);
        exit(3);
    }

    printf("[SUCCESS]: Character of string %lu at position %d is %c\n", strhash, (int) index, c);
    String_Print(str); printf("\n");

    String_Free(str);
}

void test_set_string_character_at_index() {
    printheader("Set Character at Index");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "School is two easy for kids");

    int position = 11;

    size_t oldhash = String_GetHashCode(str);
    printf("[INFO]: Setting character at index %d for string %lu...\n", position, oldhash);
    String_Print(str);

    String_SetChar(str, position, 'o');
    size_t newhash = String_GetHashCode(str);
    // if(oldhash == newhash) {
    //     fprintf(stderr, "[ERROR]: Could not set character at position %d\n", position);
    //     String_Free(str);
    //     exit(4);
    // }

    printf("[SUCCESS]: Set %c at position %d, New string is now %lu\n", 'o', position, newhash);
    String_Print(str); printf("\n");

    String_Free(str);
}

void test_copy_a_string() {
    printheader("String copy");

    String *to = (String *) malloc(sizeof(String));
    String *from = (String *) malloc(sizeof(String));

    String_New(from, "Which of us is the real string?");
    String_New(to, "");
    size_t fromhash = String_GetHashCode(from);
    printf("[INFO]: Original string is %lu, now copying...\n", fromhash);
    String_Print(from);
    if(!String_Cpy(to, from)) {
        fprintf(stderr, "[ERROR]: Could not copy string %lu\n", fromhash);
        String_Free(from);
        exit(5);
    }

    size_t newhash = String_GetHashCode(to);
    printf("[SUCCESS]: Copied string %lu to string %lu\n", fromhash, newhash);
    String_Print(to); printf("\n");

    String_Free(to); String_Free(from);
}

void test_concatenate_two_strings() {
    printheader("Concatenate Strings");

    String *part1 = (String *) malloc(sizeof(String));
    String *part2 = (String *) malloc(sizeof(String));

    String_New(part1, "O brave new world");
    String_New(part2, ", That has such people in't!");
    size_t part1hash = String_GetHashCode(part1);
    size_t part2hash = String_GetHashCode(part2);

    printf("[INFO]: Concatenating string %lu with string %lu\n", part1hash, part2hash);
    String_Print(part1);
    String_Print(part2);
    if(!String_Cat(part1, part2)) {
        fprintf(stderr, "[ERROR]: Could not concatenate string %lu with string %lu\n", part1hash, part2hash);
        String_Free(part1); String_Free(part2);
        exit(6);
    }

    size_t part1newhash = String_GetHashCode(part1);
    printf("[SUCCESS]: Concatenated strings, resulting string is %lu\n", part1newhash);
    String_Print(part1); printf("\n");

    String_Free(part1); String_Free(part2);
}

void test_compare_two_strings() {
    printheader("Compare Strings");

    String *str1 = (String *) malloc(sizeof(String));
    String *str2 = (String *) malloc(sizeof(String));

    String_New(str1, "This statement is false");
    String_New(str2, "This statement is not true");
    size_t str1hash = String_GetHashCode(str1);
    size_t str2hash = String_GetHashCode(str2);

    printf("[INFO]: Comparing string %lu with string %lu\n", str1hash, str2hash);
    String_Print(str1);
    String_Print(str2);

    int result;
    if((result = String_Cmp(str1, str2)) == 0) {
        printf("[SUCCESS]: String %lu = String %lu\n\n", str1hash, str2hash);
    } else if(result > 0) {
        printf("[SUCCESS]: String %lu > String %lu\n\n", str1hash, str2hash);
    } else {
        printf("[SUCCESS]: String %lu < String %lu\n\n", str1hash, str2hash);
    }

    String_Free(str1); String_Free(str2);
}

void test_find_first_occurrence_of_character() {
    printheader("First Character Occurrence");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "Dude, who stole my horse?");
    size_t strhash = String_GetHashCode(str);

    char c = 'o';

    printf("[INFO]: Looking for %c in string %lu...\n", c, strhash);
    String_Print(str);

    String *found;
    if((found = String_Chr(str, c)) != NULL) {
        size_t newhash = String_GetHashCode(found);
        printf("[SUCCESS]: Found %c in string %lu. New string to first occurrence is %lu\n", c, strhash, newhash);
        String_Print(found); printf("\n");

        String_Free(found);
    } else {
        printf("[SUCCESS]: Could not find %c in %lu\n\n", c, strhash);
    }

    String_Free(str);
}

void test_find_first_occurrence_of_any_of_provided() {
    printheader("Find Any of Characters");

    String *str = (String *) malloc(sizeof(String));
    String *characters = (String *) malloc(sizeof(String));
    String_New(str, "Through three cheese trees three free fleas flew. While these fleas flew, freezy breeze blew.");
    String_New(characters, "wxyz");
    size_t strhash = String_GetHashCode(str);

    printf("[INFO]: Looking for any of '%s' in string %lu...\n", String_Get(characters), strhash);
    String_Print(str);

    String *found;
    if((found = String_pBrk(str, characters)) != NULL) {
        size_t newhash = String_GetHashCode(found);
        printf("[SUCCESS]: Found character %c in string %lu. New string to occurrence is %lu\n", *String_Get(found), strhash, newhash);
        String_Print(found); printf("\n");

        String_Free(found);
    } else {
        printf("[SUCCESS]: Could not find any of %s in string %lu\n\n", String_Get(characters), strhash);
    }

    String_Free(str); String_Free(characters);
}

void test_find_last_occurrence_of_character() {
    printheader("Find Last Occurrence");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "Location location location");
    size_t strhash = String_GetHashCode(str);

    char c = 'o';

    printf("[INFO]: Looking for last '%c' in string %lu...\n", c, strhash);
    String_Print(str);

    String *found;
    if((found = String_rChr(str, c))) {
        size_t newhash = String_GetHashCode(found);
        printf("[SUCCESS]: Found character last '%c' in string %lu. New string to occurrence is %lu\n", c, strhash, newhash);
        String_Print(found); printf("\n");

        String_Free(found);
    } else {
        printf("[SUCCESS]: Could not find '%c' in string %lu\n\n", c, strhash);
    }

    String_Free(str);
}

void test_get_the_count_of_first_contiguous_occurrences_of_any_of_provided() {
    printheader("Count of Contiguous After First Occurrence");

    String *str = (String *) malloc(sizeof(String));
    String *characters = (String *) malloc(sizeof(String));
    String_New(str, "Achievement is its own reward, pride obscures it.");
    String_New(characters, "pqrs");
    size_t strhash = String_GetHashCode(str);

    printf("[INFO]: Looking for any of '%s' in string %lu...\n", String_Get(characters), strhash);
    String_Print(str);

    size_t count = String_spn(str, characters);
    if(count > 0) {
        printf("[SUCCESS]: Found %d contiguous characters from '%s' in string %lu\n\n", (int) count, String_Get(characters), strhash);
    } else {
        printf("[SUCCESS]: Found 0 characters from '%s' in string %lu\n\n", String_Get(characters), strhash);
    }

    String_Free(str); String_Free(characters);
}

void test_is_string_a_substring_of_the_other() {
    printheader("String is Substring");

    String *str1 = (String *) malloc(sizeof(String));
    String *str2 = (String *) malloc(sizeof(String));
    String_New(str1, "Illegally parked cars will be fined.");
    String_New(str2, "Illegally parked cars will be fine");
    size_t str1hash = String_GetHashCode(str1);
    size_t str2hash = String_GetHashCode(str2);

    printf("[INFO]: Checking if string %lu is a substring of string %lu...\n", str1hash, str2hash);
    String_Print(str1);
    String_Print(str2);

    String *substring;
    if((substring = String_Str(str1, str2))) {
        size_t substrhash = String_GetHashCode(substring);
        printf("[SUCCESS]: String %lu is a substring of string %lu. Substring starts as %lu\n", str2hash, str1hash, substrhash);
        String_Print(substring); printf("\n");

        String_Free(substring);
    } else {
        printf("[SUCCESS]: String %lu is not a substring of string %lu\n\n",  str2hash,  str1hash);
    }

    String_Free(str1); String_Free(str2);
}

void test_trim_string_whitespace_from_tail() {
    printheader("String Trim Right");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "   An independent string needs its space.    ");
    size_t strhash = String_GetHashCode(str);

    printf("[INFO]: Trimming space off the right of string %lu...\n",  strhash);
    String_Print(str);

    String *rTrimmed;
    if(!(rTrimmed = String_RTrim(str))) {
        fprintf(stderr, "[ERROR]: Could not trim space off the right of string %lu\n",  strhash);
        String_Free(str);
        exit(7);
    }

    size_t newhash = String_GetHashCode(rTrimmed);
    printf("[SUCCESS]: Trimmed space off the right of string %lu, New string is now %lu\n",  strhash,  newhash);
    String_Print(rTrimmed); printf("\n");

    String_Free(str); String_Free(rTrimmed);
}

void test_trim_string_whitespace_from_head() {
    printheader("String Trim Left");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "    Look Ma! I grew white space!    ");
    size_t strhash = String_GetHashCode(str);

    printf("[INFO]: Trimming space off the left of string %lu...\n",  strhash);
    String_Print(str);

    String *lTrimmed;
    if(!(lTrimmed = String_LTrim(str))) {
        fprintf(stderr, "[ERROR]: Could not trim space off the left of string %lu\n",  strhash);
        String_Free(str);
        exit(8);
    }

    size_t newhash = String_GetHashCode(lTrimmed);
    printf("[SUCCESS]: Trimmed space off the left of string %lu, New string is now %lu\n",  strhash,  newhash);
    String_Print(lTrimmed); printf("\n");

    String_Free(str); String_Free(lTrimmed);
}

void test_trim_string_whitespace() {
    printheader("String Trim");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "            It's a small string after all!          ");
    size_t strhash = String_GetHashCode(str);

    printf("[INFO]: Trimming trailing and leading white space from string %lu...\n",  strhash);
    String_Print(str);

    String *trimmed;
    if(!(trimmed = String_Trim(str))) {
        fprintf(stderr, "[ERROR]: Could not trim space from string %lu\n",  strhash);
        String_Free(str);
        exit(9);
    }

    size_t newhash = String_GetHashCode(trimmed);
    printf("[SUCCESS]: Trimmed leading and trailing white space from string %lu, New string is now %lu\n",  strhash,  newhash);
    String_Print(trimmed); printf("\n");

    String_Free(str); String_Free(trimmed);

}


void test_get_index_of_character() {
    printheader("Get Character Index");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "Dial M for Murder");
    size_t strhash = String_GetHashCode(str);
    char c = 'M';

    printf("[INFO]: Looking for character %c in string %lu...\n", c,  strhash);
    String_Print(str);

    int index;
    if((index = String_IndexOfChar(str, c)) > String_Len(str)) {
        printf("[SUCCESS]: Character %c is not in string %lu\n\n", c,  strhash);
    } else {
        printf("[SUCCESS]: Found character %c at index %d of string %lu\n\n", c, index,  strhash);
    }

    String_Free(str);
}

void test_convert_string_to_lowercase() {
    printheader("String to Lowercase");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "TOM: IT'S REALLY LOUD IN HERE!\nJERRY: WHAT??");
    size_t strhash = String_GetHashCode(str);

    printf("[INFO]: Converting string %lu to lowercase...\n",  strhash);
    String_Print(str);

    String *lowercased;
    if(!(lowercased = String_Lower(str))) {
        fprintf(stderr, "[ERROR]: Could not convert string %lu to lowercase\n\n",  strhash);
        String_Free(str);
        exit(10);
    }

    size_t newhash = String_GetHashCode(lowercased);
    printf("[SUCCESS]: Converted string %lu to lowercase, new string is %lu\n",  strhash,  newhash);
    String_Print(lowercased); printf("\n");

    String_Free(str); String_Free(lowercased);
}

void test_convert_string_to_uppercase() {
    printheader("String to Uppercase");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "Don't make me angry.. You wouldn't like me when I'm angry..");
    size_t strhash = String_GetHashCode(str);

    printf("[INFO]: Converting string %lu to uppercase...\n",  strhash);
    String_Print(str);

    String *uppercased;
    if(!(uppercased = String_Upper(str))) {
        fprintf(stderr, "[ERROR]: Could not convert string %lu to uppercase\n\n",  strhash);
        String_Free(str);
        exit(11);
    }

    size_t newhash = String_GetHashCode(uppercased);
    printf("[SUCCESS]: Converted string %lu to upppercase, new string is %lu\n",  strhash,  newhash);
    String_Print(uppercased); printf("\n");

    String_Free(str); String_Free(uppercased);
}

void test_reverse_a_string() {
    printheader("String Reversed");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "A man, a plan, a canal, Panama");
    size_t strhash = String_GetHashCode(str);

    printf("[INFO]: Reversing string %lu...\n",  strhash);
    String_Print(str);

    String *reversed;
    if(!(reversed = String_Reverse(str))) {
        fprintf(stderr, "[ERROR]: Could not reverse string %lu\n\n",  strhash);
        String_Free(str);
        exit(12);
    }

    size_t newhash = String_GetHashCode(reversed);
    printf("[SUCCESS]: Reversed string %lu, new string is %lu\n",  strhash,  newhash);
    String_Print(reversed); printf("\n");

    String_Free(str); String_Free(reversed);
}

void test_count_the_words_in_a_string() {
    printheader("Word Count");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "From a little after two o’clock until almost sundown of the long still hot weary dead September afternoon\
                     they sat in what Miss Coldfield still called the office because her father had called it that – a dim hot airless\
                     room with the blinds all closed and fastened for forty-three summers because when she was a girl someone had\
                     believed that light and moving air carried heat and that dark was always cooler, and which (as the sun shone fuller and fuller\
                     on that side of the house) became latticed with yellow slashes full of dust motes which Quentin thought of as being flecks of the\
                     dead old dried paint itself blown inward from the scaling blinds as wind might have blown them.");
    size_t strhash = String_GetHashCode(str);

    printf("[INFO]: Counting words in string %lu...\n",  strhash);
    String_Print(str);

    size_t words = String_WordCount(str);
    printf("[SUCCESS]: String %lu has %d words\n\n",  strhash, (int) words);

    String_Free(str);
}

void test_does_a_string_start_with_another_string() {
    printheader("String Starts With Another String");

    String *str = (String *) malloc(sizeof(String));
    String *beginning = (String *) malloc(sizeof(String));
    String_New(str, "Open the pod bay doors, please, HAL.");
    String_New(beginning, "Open the pod");
    size_t strhash = String_GetHashCode(str);
    size_t beginhash = String_GetHashCode(beginning);

    printf("[INFO]: Checking if string %lu starts string %lu...\n",  beginhash,  strhash);
    String_Print(str);
    String_Print(beginning);

    if(String_StartsWith(str, beginning))
        printf("[SUCCESS]: String %lu starts string %lu\n\n",  beginhash,  strhash);
    else
        printf("[SUCCESS]: String %lu does not start string %lu\n\n",  beginhash,  strhash);

    String_Free(str); String_Free(beginning);
}

void test_remove_occurrences_of_character_from_string() {
    printheader("Remove Occurrences of Character");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "How much wood would a woodchuck chuck if a woodchuck could chuck wood?");
    size_t strhash = String_GetHashCode(str);

    char *c = "w";

    printf("[INFO]: Removing character %c from string %lu...\n", *c,  strhash);
    String_Print(str);

    String *trimmed;
    if(!(trimmed = String_TrimChar(str, c))) {
        fprintf(stderr, "[ERROR]: Character %c could not be removed from string %lu\n\n", *c,  strhash);
        String_Free(str);
        exit(13);
    }

    size_t newhash = String_GetHashCode(trimmed);
    printf("[SUCCESS]: Removed character %c from string %lu, new string is %lu\n", *c,  strhash,  newhash);
    String_Print(trimmed); printf("\n");

    String_Free(str); String_Free(trimmed);
}

void test_tokenize_a_string() {
    printheader("Split String Into Tokens");

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "A house divided against itself cannot stand");
    size_t strhash = String_GetHashCode(str);

    printf("[INFO]: Splitting string %lu into tokens...\n",  strhash);
    String_Print(str);

    char *tok;
    char *delimiters = " \t";
    if(!(tok = String_Tok(str, delimiters))) {
        fprintf(stderr, "[ERROR]: Could not split string %lu into tokens\n\n",  strhash);
        String_Free(str);
        exit(14);
    }

    int i = 0;
    do {
        printf("[%d] = %s\n", ++i, tok);
        tok = String_Tok(NULL, delimiters);
    } while(tok);

    printf("[SUCCESS]: Split string %lu into %d tokens\n\n",  strhash, i);

    String_Free(str);
}


/*/$$$$$$  /$$$$$$$  /$$$$$$$   /$$$$$$  /$$     /$$ /$$       /$$$$$$  /$$$$$$  /$$$$$$$$
 /$$__  $$| $$__  $$| $$__  $$ /$$__  $$|  $$   /$$/| $$      |_  $$_/ /$$__  $$|__  $$__/
| $$  \ $$| $$  \ $$| $$  \ $$| $$  \ $$ \  $$ /$$/ | $$        | $$  | $$  \__/   | $$
| $$$$$$$$| $$$$$$$/| $$$$$$$/| $$$$$$$$  \  $$$$/  | $$        | $$  |  $$$$$$    | $$
| $$__  $$| $$__  $$| $$__  $$| $$__  $$   \  $$/   | $$        | $$   \____  $$   | $$
| $$  | $$| $$  \ $$| $$  \ $$| $$  | $$    | $$    | $$        | $$   /$$  \ $$   | $$
| $$  | $$| $$  | $$| $$  | $$| $$  | $$    | $$    | $$$$$$$$ /$$$$$$|  $$$$$$/   | $$
|__/  |__/|__/  |__/|__/  |__/|__/  |__/    |__/    |________/|______/ \______/    |__/*/

void test_create_a_new_arraylist() {
    printheader("Create an ArrayList");

    printf("[INFO]: Creating a new ArrayList instance...\n");
    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    if(!ArrayList_New(list)) {
        fprintf(stderr, "[ERROR]: Could not create a new ArrayList\n\n");
        exit(15);
    }

    printf("[SUCCESS]: Created a new ArrayList!\n\n");

    ArrayList_Free(list);
}

void test_add_to_an_arraylist() {
    printheader("Add to ArrayList");

    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayList_New(list);

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "Elementary, my dear Watson");
    size_t strhash = String_GetHashCode(str);

    printf("[INFO]: Attempting to add string %lu to ArrayList instance...\n",  strhash);
    String_Print(str);
    if(!ArrayList_Add(list, str)) {
        fprintf(stderr, "[ERROR]: Could not add string %lu to ArrayList instance\n\n",  strhash);
        String_Free(str); ArrayList_Free(list);
        exit(17);
    }

    printf("[SUCCESS]: Added string %lu to ArrayList instance\n",  strhash);
    ArrayList_Print(list); printf("\n");

    String_Free(str); ArrayList_Free(list);
}

void test_remove_from_an_arraylist() {
    printheader("Remove from ArrayList");

    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayList_New(list);

    String *str1 = (String *) malloc(sizeof(String));
    String_New(str1, "I am an intruder. Remove me.");
    String *str2 = (String *) malloc(sizeof(String));
    String_New(str2, "I am with the intruder. Remove me.");
    size_t str1hash = String_GetHashCode(str1);
    size_t str2hash = String_GetHashCode(str2);

    printf("[INFO]: Adding strings %lu and %lu to new ArrayList...\n",  str1hash,  str2hash);
    ArrayList_Add(list, str1); ArrayList_Add(list, str2);
    ArrayList_Print(list);

    printf("[INFO]: Attempting to remove string %lu from ArrayList...\n",  str2hash);
    if(!ArrayList_Remove(list, 1)) {
        fprintf(stderr, "[ERROR]: Could not remove string %lu from ArrayList\n\n",  str2hash);
        ArrayList_Free(list);
        String_Free(str1); String_Free(str2);
        exit(18);
    }

    printf("[SUCCESS]: Removed string %lu from ArrayList\n",  str2hash);
    ArrayList_Print(list);

    String_Free(str1); String_Free(str2);
    ArrayList_Free(list);
}

void test_remove_last_from_an_arraylist() {
    printheader("Remove Last from ArrayList");

    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayList_New(list);

    String *str1 = (String *) malloc(sizeof(String));
    String_New(str1, "Pop Quiz");
    String *str2 = (String *) malloc(sizeof(String));
    String_New(str2, "Question 1");
    String *str3 = (String *) malloc(sizeof(String));
    String_New(str3, "Question 2");
    String *str4 = (String *) malloc(sizeof(String));
    String_New(str4, "Question 2");

    size_t str1hash = String_GetHashCode(str1);
    size_t str2hash = String_GetHashCode(str2);
    size_t str3hash = String_GetHashCode(str3);
    size_t str4hash = String_GetHashCode(str4);

    printf("[INFO]: Adding strings %lu, %lu, %lu and %lu to new ArrayList...\n",  str1hash,  str2hash,  str3hash,  str4hash);
    ArrayList_Add(list, str1); ArrayList_Add(list, str2); ArrayList_Add(list, str3); ArrayList_Add(list, str4);
    ArrayList_Print(list);

    printf("[INFO]: Attempting to remove string %lu from ArrayList...\n",  str4hash);
    if(!ArrayList_RemoveLast(list)) {
        fprintf(stderr, "[ERROR]: Could not remove last element from ArrayList\n\n");
        String_Free(str1); String_Free(str2); String_Free(str3); String_Free(str4);
        ArrayList_Free(list);
        exit(19);
    }

    printf("[SUCCESS]: Removed last element from ArrayList\n");
    ArrayList_Print(list);
    printf("\n");

    ArrayList_Free(list);
    String_Free(str1); String_Free(str2); String_Free(str3); String_Free(str4);
}

void test_set_element_of_arraylist() {
    printheader("Set Element of ArrayList");

    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayList_New(list);

    String *str1 = (String *) malloc(sizeof(String));
    String_New(str1, "I'm taking my sabbaticle");
    String *str2 = (String *) malloc(sizeof(String));
    String_New(str2, "I'll hold your place in line");

    size_t str1hash = String_GetHashCode(str1);
    size_t str2hash = String_GetHashCode(str2);

    printf("[INFO]: Adding string %lu to new ArrayList...\n",  str1hash);
    ArrayList_Add(list, str1);
    ArrayList_Print(list);

    printf("[INFO]: Attempting to replace string %lu with string %lu...\n",  str1hash,  str2hash);
    if(!ArrayList_Set(list, 0, str2)) {
        fprintf(stderr, "[ERROR]: Could not replace string %lu with string %lu\n\n",  str1hash,  str2hash);
        String_Free(str1); String_Free(str2);
        ArrayList_Free(list);
        exit(20);
    }

    printf("[SUCCESS]: Replaced string %lu with string %lu\n",  str1hash,  str2hash);
    ArrayList_Print(list);
    printf("\n");

    String_Free(str1); String_Free(str2);
    ArrayList_Free(list);
}

void test_get_element_of_arraylist() {
    printheader("Get Element of ArrayList");

    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayList_New(list);

    String *line1 = (String *) malloc(sizeof(String));
    String_New(line1, "And on the pedestal, these words appear");
    String *line2 = (String *) malloc(sizeof(String));
    String_New(line2, "My name is Ozymandias, King of Kings;");
    String *line3 = (String *) malloc(sizeof(String));
    String_New(line3, "Look on my Works, ye Mighty, and despair!");
    String *line4 = (String *) malloc(sizeof(String));
    String_New(line4, "Nothing beside remains. Round the decay");
    String *line5 = (String *) malloc(sizeof(String));
    String_New(line5, "Of that colossal Wreck, boundless and bare");
    String *line6 = (String *) malloc(sizeof(String));
    String_New(line6, "The lone and level sands stretch far away.");

    size_t line1hash = String_GetHashCode(line1);
    size_t line2hash = String_GetHashCode(line2);
    size_t line3hash = String_GetHashCode(line3);
    size_t line4hash = String_GetHashCode(line4);
    size_t line5hash = String_GetHashCode(line5);
    size_t line6hash = String_GetHashCode(line6);

    printf("[INFO]: Adding strings %lu, %lu, %lu, %lu, %lu and %lu to new ArrayList...\n",  line1hash,  line2hash,  line3hash,  line4hash,  line5hash,  line6hash);
    ArrayList_Add(list, line1); ArrayList_Add(list, line2); ArrayList_Add(list, line3); ArrayList_Add(list, line4); ArrayList_Add(list, line5); ArrayList_Add(list, line6);
    ArrayList_Print(list);

    String *gotten;
    size_t index = 2;
    if(!(gotten = (String *) ArrayList_Get(list, index))) {
        fprintf(stderr, "[ERROR]: Could not get string at index %d of ArrayList\n\n", (int) index);
        String_Free(line1); String_Free(line2); String_Free(line3); String_Free(line4); String_Free(line5); String_Free(line6);
        ArrayList_Free(list);
        exit(21);
    }

    size_t gottenhash = String_GetHashCode(gotten);
    printf("[SUCCESS]: Fetched element %d from ArrayList, String is %lu\n", (int) index,  gottenhash);
    String_Print(gotten); printf("\n");

    String_Free(line1); String_Free(line2); String_Free(line3); String_Free(line4); String_Free(line5); String_Free(line6);
    ArrayList_Free(list);
}

void test_compact_an_arraylist() {
    printheader("Compact an ArrayList");

    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayList_New(list);

    String *str1 = (String *) malloc(sizeof(String));
    String *str2 = (String *) malloc(sizeof(String));
    String_New(str1, "Absence makes the heart grow fonder");
    String_New(str2, "The shortest distance between two points is a straight line");
    size_t str1hash = String_GetHashCode(str1);
    size_t str2hash = String_GetHashCode(str2);

    printf("[INFO]: Adding string %lu to ArrayList and string %lu 205 elements later...\n",  str1hash,  str2hash);
    ArrayList_Add(list, str1);
    ArrayList_Set(list, 205, str2);
    ArrayList_Print(list);
    printf("[INFO]: ArrayList capacity at %d\n", (int) list->reserved);

    if(!ArrayList_Compact(list)) {
        fprintf(stderr, "[ERROR]: Could not compact ArrayList\n\n");
        String_Free(str1); String_Free(str2);
        ArrayList_Free(list);
        exit(22);
    }

    printf("[SUCCESS]: Compacted ArrayList. Capacity is now %d\n", (int) list->reserved);
    ArrayList_Print(list);
    printf("\n");

    String_Free(str1); String_Free(str2);
    ArrayList_Free(list);
}

void test_clear_an_arraylist() {
    printheader("Clear an ArrayList");

    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayList_New(list);

    String *str1 = (String *) malloc(sizeof(String));
    String *str2 = (String *) malloc(sizeof(String));
    String *str3 = (String *) malloc(sizeof(String));
    String *str4 = (String *) malloc(sizeof(String));
    String *str5 = (String *) malloc(sizeof(String));
    String_New(str1, "Empty your mind. Be formless, shapeless, like water.");
    String_New(str2, "If you put water into a cup, it becomes the cup.");
    String_New(str3, "If you put water into a bottle, it becomes the bottle.");
    String_New(str4, "If you put water into a tea pot, it becomes the tea pot.");
    String_New(str5, "Now, water can flow or it can crash... be water my friend.");
    size_t str1hash = String_GetHashCode(str1);
    size_t str2hash = String_GetHashCode(str2);
    size_t str3hash = String_GetHashCode(str3);
    size_t str4hash = String_GetHashCode(str4);
    size_t str5hash = String_GetHashCode(str5);

    printf("[INFO]: Adding strings %lu, %lu, %lu, %lu and %lu to ArrayList...\n",  str1hash,  str2hash,  str3hash,  str4hash,  str5hash);
    ArrayList_Add(list, str1); ArrayList_Add(list, str2); ArrayList_Add(list, str3); ArrayList_Add(list, str4); ArrayList_Add(list, str5);
    ArrayList_Print(list);

    printf("[INFO]: Attempting to clear ArrayList...\n");
    if(!ArrayList_Clear(list)) {
        fprintf(stderr, "[ERROR]: Could not clear the ArrayList\n\n");
        String_Free(str1); String_Free(str2); String_Free(str3); String_Free(str4); String_Free(str5);
        ArrayList_Free(list);
        exit(23);
    }

    printf("[SUCCESS]: Cleared ArrayList\n");
    ArrayList_Print(list);
    printf("\n");

    String_Free(str1); String_Free(str2); String_Free(str3); String_Free(str4); String_Free(str5);
    ArrayList_Free(list);
}

void test_copy_an_arraylist() {
    printheader("Copy an ArrayList");

    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayList *copy = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayList_New(list);
    ArrayList_New(copy);

    String *str1 = (String *) malloc(sizeof(String));
    String *str2 = (String *) malloc(sizeof(String));
    String *str3 = (String *) malloc(sizeof(String));
    String_New(str1, "Duplication station");
    String_New(str2, "Twin Strings");
    String_New(str3, "Reproduction Function");
    size_t str1hash = String_GetHashCode(str1);
    size_t str2hash = String_GetHashCode(str2);
    size_t str3hash = String_GetHashCode(str3);

    printf("[INFO]: Adding strings %lu, %lu and %lu to ArrayList...\n",  str1hash,  str2hash,  str3hash);
    ArrayList_Add(list, str1); ArrayList_Add(list, str2); ArrayList_Add(list, str3);
    ArrayList_Print(list);

    printf("[INFO]: Attempting to copy ArrayList...\n");
    if(!ArrayList_Copy(copy, list)) {
        fprintf(stderr, "[ERROR]: Could not copy list\n\n");
        String_Free(str1); String_Free(str2); String_Free(str3);
        ArrayList_Free(list);
        exit(24);
    }

    printf("[SUCCESS]: Copied ArrayList to it's destination, new list is:\n");
    ArrayList_Print(copy); printf("\n");

    String_Free(str1); String_Free(str2); String_Free(str3);
    ArrayList_Free(list);
}

void test_expand_capacity_of_arraylist() {
    printheader("Expand ArrayList Capacity");

    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayList_New(list);

    size_t oldcap = list->reserved;
    size_t newcap = 303;
    printf("[INFO]: Attempting to expand ArrayList of capacity %d to new capacity %d\n", (int) oldcap, (int) newcap);
    if(!ArrayList_ExpandReserved(list, newcap)) {
        fprintf(stderr, "[ERROR]: Could not expand ArrayList to new capacity\n\n");
        ArrayList_Free(list);
        exit(25);
    }

    size_t cap = list->reserved;
    printf("[SUCCESS]: Expanded ArrayList to capacity %d\n\n", (int) cap);
    ArrayList_Free(list);
}


/*/$$       /$$$$$$ /$$   /$$ /$$   /$$ /$$$$$$$$ /$$$$$$$  /$$       /$$$$$$  /$$$$$$  /$$$$$$$$
 | $$      |_  $$_/| $$$ | $$| $$  /$$/| $$_____/| $$__  $$| $$      |_  $$_/ /$$__  $$|__  $$__/
 | $$        | $$  | $$$$| $$| $$ /$$/ | $$      | $$  \ $$| $$        | $$  | $$  \__/   | $$
 | $$        | $$  | $$ $$ $$| $$$$$/  | $$$$$   | $$  | $$| $$        | $$  |  $$$$$$    | $$
 | $$        | $$  | $$  $$$$| $$  $$  | $$__/   | $$  | $$| $$        | $$   \____  $$   | $$
 | $$        | $$  | $$\  $$$| $$\  $$ | $$      | $$  | $$| $$        | $$   /$$  \ $$   | $$
 | $$$$$$$$ /$$$$$$| $$ \  $$| $$ \  $$| $$$$$$$$| $$$$$$$/| $$$$$$$$ /$$$$$$|  $$$$$$/   | $$
 |________/|______/|__/  \__/|__/  \__/|________/|_______/ |________/|______/ \______/    |__/*/

void test_create_a_new_linkedlist() {
    printheader("Create a LinkedList");

    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));

    printf("[INFO]: Creating a new LinkedList...\n");
    if(!LinkedList_New(list)) {
        fprintf(stderr, "[ERROR]: Could not create a new LinkedList...\n");
        exit(26);
    }

    printf("[SUCCESS]: Created a new LinkedList instance\n\n");
    LinkedList_Free(list);
}

void test_insert_element_after_node() {
    printheader("Insert Element After List Node");

    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    String *str = (String *) malloc(sizeof(String));
    String_New(str, "How to pin the tail on the donkey");
    node->data = str;
    size_t strhash = String_GetHashCode(str);

    String *tail = (String *) malloc(sizeof(String));
    String_New(tail, "Like this");
    size_t tailhash = String_GetHashCode(tail);

    printf("[INFO]: Adding string %lu after node with string %lu...\n",  tailhash,  strhash);
    String_Print(str);
    String_Print(tail);
    if(!LinkedList_InsertAfter(node, tail)) {
        fprintf(stderr, "[ERROR]: Could not add node with string %lu after node with string %lu\n",  tailhash,  strhash);
        String_Free(str); String_Free(tail);
        free(node);
        exit(28);
    }

    printf("[SUCCESS]: Added string %lu after node with string %lu\n",  strhash,  tailhash);
    ListNode_Print(node);
    ListNode_Print(node->next);
    printf("\n");

    String_Free(str); String_Free(tail);
    free(node->next); free(node);
}

void test_insert_element_before_node() {
    printheader("Insert Element Before List Node");

    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    String *str = (String *) malloc(sizeof(String));
    String_New(str, "It follows that");
    node->data = str;
    size_t strhash = String_GetHashCode(str);

    String *head = (String *) malloc(sizeof(String));
    String_New(head, "this precedes");
    size_t headhash = String_GetHashCode(head);

    printf("[INFO]: Adding string %lu before node with string %lu...\n",  headhash,  strhash);
    String_Print(str);
    String_Print(head);

    if(!LinkedList_InsertBefore(node, head)) {
        fprintf(stderr, "[ERROR]: Could not add node with string %lu before node with string %lu\n",  headhash,  strhash);
        String_Free(str); String_Free(head);
        free(node);
        exit(29);
    }

    printf("[SUCCESS]: Added string %lu before node with string %lu\n",  headhash,  strhash);
    ListNode_Print(node);
    ListNode_Print(node->prev);
    printf("\n");

    String_Free(str); String_Free(head);
    free(node->prev); free(node);
}

void test_insert_element_at_linkedlist_head() {
    printheader("Insert Element at List Head");

    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    LinkedList_New(list);

    char *pointers[] = {"Never was a night", "so well served by ladies", "as was Lancelot when", "he from Brittany came"};
    size_t num_pointers = 4;

    for(int i = 0; i < num_pointers; i++) {
        String *str = (String *) malloc(sizeof(String));
        String_New(str, pointers[i]);
        size_t strhash = String_GetHashCode(str);

        printf("[INFO]: Inserting string %lu at beginning of LinkedList...\n",  strhash);
        String_Print(str);
        if(!LinkedList_InsertBeginning(list, str)) {
            fprintf(stderr, "[ERROR]: Could not insert string %lu at beginning of LinkedList\n\n",  strhash);
            String_Free(str);
            LinkedList_Free(list);
            exit(30);
        }

        printf("[SUCCESS]: Inserted string %lu at beginning of LinkedList\n",  strhash);
        String_Free(str);
    }

    LinkedList_Print(list);
    printf("\n");

    LinkedList_Free(list);
}

void test_insert_element_at_linkedlist_tail() {
    printheader("Insert Element at List Tail");

    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    LinkedList_New(list);

    char *pointers[] = {"Such fire was not by fire to be drown'd", "Nor he his nature changed by changing ground"};
    size_t num_pointers = 2;

    for(int i = 0; i < num_pointers; i++) {
        String *str = (String *) malloc(sizeof(String));
        String_New(str, pointers[i]);
        size_t strhash = String_GetHashCode(str);

        printf("[INFO]: Inserting string %lu at end of LinkedList...\n",  strhash);
        String_Print(str);
        if(!LinkedList_InsertEnd(list, str)) {
            fprintf(stderr, "[ERROR]: Could not insert string %lu at end of LinkedList\n\n",  strhash);
            String_Free(str);
            LinkedList_Free(list);
            exit(31);
        }

        printf("[SUCCESS]: Inserted string %lu at end of LinkedList\n",  strhash);
        String_Free(str);
    }

    LinkedList_Print(list);
    printf("\n");

    LinkedList_Free(list);
}

void test_remove_element_from_linkedlist() {
    printheader("Remove Element from LinkedList");

    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    LinkedList_New(list);

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "Man proposes, and God disposes");
    size_t strhash = String_GetHashCode(str);

    printf("[INFO]: Adding string %lu to LinkedList...\n",  strhash);
    String_Print(str);
    LinkedList_InsertBeginning(list, str);

    printf("[INFO]: Removing string %lu from LinkedList...\n",  strhash);

    String *removed;
    if(!(removed = LinkedList_Remove(list, str))) {
        fprintf(stderr, "[ERROR]: Could not remove string %lu from LinkedList\n\n",  strhash);
        String_Free(str);
        LinkedList_Free(list);
        exit(32);
    }

    size_t removedhash = String_GetHashCode(str);
    printf("[SUCCESS]: Removed string %lu from LinkedList\n\n",  removedhash);

    String_Free(str);
    LinkedList_Free(list);
}

void test_remove_element_at_linkedlist_head() {
    printheader("Remove Element from LinkedList Head");

    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    LinkedList_New(list);

    char *pointers[] = {"'Twas the night before Christmas,", "when all thro' the house", "Not a creature was stirring,", "not even a mouse;"};
    size_t num_pointers = 4;
    for(int i = 0; i < num_pointers; i++) {
        String *str = (String *) malloc(sizeof(String));
        String_New(str, pointers[i]);
        size_t strhash = String_GetHashCode(str);

        printf("[INFO]: Adding string %lu to new LinkedList...\n",  strhash);
        String_Print(str);
        LinkedList_InsertBeginning(list, str);
    }

    LinkedList_Print(list);

    for(int i = 0; i < num_pointers; i++) {
        String *removed;
        if(!(removed = LinkedList_RemoveFirst(list))) {
            fprintf(stderr, "[ERROR]: Could not remove first LinkedList element\n\n");
            LinkedList_Free(list);
            exit(33);
        }

        size_t remhash = String_GetHashCode(removed);
        printf("[SUCCESS]: Removed string %lu from beginning of LinkedList\n",  remhash);
        String_Free(removed);
    }

    LinkedList_Print(list);
    printf("\n");

    LinkedList_Free(list);
}

void test_remove_element_at_linkedlist_tail() {
    printheader("Remove Element from LinkedList Tail");

    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    LinkedList_New(list);

    char *pointers[] = {"'Twas the night before Christmas,", "when all thro' the house", "Not a creature was stirring,", "not even a mouse;"};
    size_t num_pointers = 4;
    for(int i = 0; i < num_pointers; i++) {
        String *str = (String *) malloc(sizeof(String));
        String_New(str, pointers[i]);
        size_t strhash = String_GetHashCode(str);

        printf("[INFO]: Adding string %lu to new LinkedList...\n",  strhash);
        String_Print(str);
        LinkedList_InsertBeginning(list, str);
    }

    LinkedList_Print(list);

    String *removed;
    while((removed = LinkedList_RemoveLast(list))) {
        size_t remhash = String_GetHashCode(removed);
        printf("[SUCCESS]: Removed string %lu from the end of LinkedList\n",  remhash);
        String_Free(removed);
    }


    LinkedList_Print(list);
    printf("\n");
    
    LinkedList_Free(list);

}

void test_convert_array_to_linkedlist() {
    printheader("Convert Array to LinkedList");

    char *pointers[] = {"This land", "was made", "for you", "and me"};
    int num_pointers = 4;

    printf("[INFO]: Converting array of length %d to LinkedList...\n", num_pointers);
    LinkedList *list;
    if(!(list = LinkedList_toList(pointers, num_pointers))) {
        fprintf(stderr, "[ERROR]: Could not convert list of length %d to LinkedList\n\n", num_pointers);
        exit(35);
    }

    printf("[SUCCESS]: Converted array of length %d to LinkedList\n", num_pointers);
    LinkedList_Print(list); printf("\n");

    LinkedList_Free(list);
}

void test_convert_linkedlist_to_array() {
    printheader("Convert LinkedList to Array");

    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    LinkedList_New(list);

    String *nike = (String *) malloc(sizeof(String));
    String *GE = (String *) malloc(sizeof(String));
    String *IMAX = (String *) malloc(sizeof(String));
    String *EA = (String *) malloc(sizeof(String));
    String_New(nike, "Just Do It");
    String_New(GE, "Imagination At Work");
    String_New(IMAX, "Think Big");
    String_New(EA, "Challenge Everything");

    LinkedList_InsertEnd(list, nike); LinkedList_InsertEnd(list, GE); LinkedList_InsertEnd(list, IMAX); LinkedList_InsertEnd(list, EA);
    printf("[INFO]: Converting new LinkedList to pointer array...\n");
    LinkedList_Print(list);

    void **arr;
    if(!(arr = LinkedList_toArray(list))) {
        fprintf(stderr, "[ERROR]: Could not convert LinkedList to array\n\n");
        String_Free(nike); String_Free(GE); String_Free(IMAX); String_Free(EA);
        LinkedList_Free(list);
        exit(36);
    }

    printf("[SUCCESS]: Converted LinkedList to pointer array, array starts at %p\n\n", arr);
    String_Free(nike); String_Free(GE); String_Free(IMAX); String_Free(EA);
    LinkedList_Free(list);
}

void test_check_if_item_in_linkedlist() {
    printheader("LinkedList Contains Item");

    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    LinkedList_New(list);

    String *str = (String *) malloc(sizeof(String));
    String_New(str, "The word 'listen' contains the same letters as the word 'silent'");
    size_t strhash = String_GetHashCode(str);

    printf("[INFO]: Adding string %lu to new LinkedList...\n",  strhash);
    String_Print(str);
    LinkedList_InsertEnd(list, str);

    printf("[INFO]: Checking if string %lu is in LinkedList...\n",  strhash);
    if(!LinkedList_Contains(list, str)) {
        fprintf(stderr, "[ERROR]: Item added to LinkedList could not be found\n\n");
        String_Free(str);
        LinkedList_Free(list);
        exit(37);
    }

    printf("[SUCCESS]: Found string %lu in LinkedList\n\n",  strhash);

    String_Free(str);
    LinkedList_Free(list);
}

void test_get_linkedlist_item_at_index() {
    printheader("Get Item at LinkedList Index");

    char *pointers[] = {"To die, to sleep -- ",
                        "to sleep -- perchance to dream;", "ay, there's the rub,",
                        "For in that sleep of death what dreams may come",
                        "When we have shuffled off this mortal coil,",
                        "Must give us pause."};
    size_t num_pointers = 6;
    LinkedList *list = LinkedList_toList(pointers, num_pointers);

    char *found;
    int index = 3;

    printf("[INFO]: Looking for item at index %d of LinkedList...\n", index);
    LinkedList_Print(list);

    if(!(found = LinkedList_ItemAtIndex(list, index))) {
        printf("[SUCCESS]: Did not find item at index %d of LinkedList\n\n", index);
    } else {
        printf("[SUCCESS]: Found item at index %d of LinkedList\n", index);
        printf("list[%d] = %s\n\n", index, found);
    }

    LinkedList_Free(list);
}

void test_get_size_of_a_linkedlist() {
    printheader("Get LinkedList Size");

    char *pointers[] = {"Step up and I'll guess you're size",
                        "5?", "4?", "3?", "2?", "1?",
                        "I'll tell ya.."};
    size_t num_pointers = 7;
    LinkedList *list = LinkedList_toList(pointers, num_pointers);

    printf("[INFO]: Getting size of newly created LinkedList...\n");
    LinkedList_Print(list);

    size_t size = LinkedList_GetSize(list);
    printf("[SUCCESS]: LinkedList has %d elements\n\n", (int) size);

    LinkedList_Free(list);
}

/*/$$   /$$  /$$$$$$   /$$$$$$  /$$   /$$ /$$      /$$  /$$$$$$  /$$$$$$$
 | $$  | $$ /$$__  $$ /$$__  $$| $$  | $$| $$$    /$$$ /$$__  $$| $$__  $$
 | $$  | $$| $$  \ $$| $$  \__/| $$  | $$| $$$$  /$$$$| $$  \ $$| $$  \ $$
 | $$$$$$$$| $$$$$$$$|  $$$$$$ | $$$$$$$$| $$ $$/$$ $$| $$$$$$$$| $$$$$$$/
 | $$__  $$| $$__  $$ \____  $$| $$__  $$| $$  $$$| $$| $$__  $$| $$____/
 | $$  | $$| $$  | $$ /$$  \ $$| $$  | $$| $$\  $ | $$| $$  | $$| $$
 | $$  | $$| $$  | $$|  $$$$$$/| $$  | $$| $$ \/  | $$| $$  | $$| $$
 |__/  |__/|__/  |__/ \______/ |__/  |__/|__/     |__/|__/  |__/|__/*/

void test_create_a_new_hashmap() {
    printheader("Create a HashMap");

    HashMap *map = (HashMap *) malloc(sizeof(HashMap));
    printf("[INFO]: Creating a new HashMap...\n");
    if(!HashMap_New(map)) {
        fprintf(stderr, "[ERROR]: Could not create a new HashMap...\n");
        exit(40);
    }

    printf("[SUCCESS]: Created a new HashMap instance\n\n");
    HashMap_Free(map);
}

void test_set_element_for_key_in_hashmap() {
    printheader("Set HashMap Entry");

    HashMap *map = (HashMap *) malloc(sizeof(HashMap));
    HashMap_New(map);

    printf("[INFO]: Setting new HashMap key/value entry...\n");
    int wonders_of_the_world = 7;
    if(!HashMap_Set(map, "wonders", &wonders_of_the_world)) {
       fprintf(stderr, "[ERROR]: Could not set new entry in HashMap\n\n");
       HashMap_Free(map);
       exit(41);
    }

    printf("[SUCCESS]: Set new entry for HashMap\n");
    HashMap_Print(map);
    printf("\n");

    HashMap_Free(map);
}

void test_get_element_for_key_in_hashmap() {
    printheader("Get HashMap Value for Key");

    HashMap *map = (HashMap *) malloc(sizeof(HashMap));
    HashMap_New(map);

    printf("[INFO]: Setting new HashMap key/value entry...\n");
    char *log_buffer[] = {"Error on line 3", "Error on line 9000", "Error on HAL", "You broke the internet. Thanks."};
    char *key = "error_log";
    HashMap_Set(map, key, log_buffer);
    HashMap_Print(map);

    printf("[INFO]: Getting HashMap value for key '%s'...\n", key);
    char **error_log;
    if(!(error_log = HashMap_Get(map, key))) {
        fprintf(stderr, "[ERROR]: Could not get value for recently set key/value entry of HashMap\n\n");
        HashMap_Free(map);
        exit(42);
    }

    printf("[SUCCESS]: Got value for key '%s'\n", key);
    printf("%s = %p\n\n", key, error_log);

    HashMap_Free(map);
}

void test_remove_element_for_key_in_hashmap() {
    printheader("Remove HashMap Entry");

    HashMap *map = (HashMap *) malloc(sizeof(HashMap));
    HashMap_New(map);

    float *pi = (float *) malloc(sizeof(float));
    *pi = 3.14f;
    char *key = "PI";
    printf("[INFO]: Setting new HashMap value for key %s...\n", key);
    HashMap_Set(map, key, pi);
    HashMap_Print(map);

    if(!HashMap_Remove(map, key)) {
        fprintf(stderr, "[ERROR]: Could not remove entry for key %s\n\n", key);
        HashMap_Free(map);
        exit(43);
    }

    free(pi);
    printf("[SUCCESS]: Removed entry for key %s\n", key);
    HashMap_Print(map); printf("\n");

    HashMap_Free(map);
}

void test_clear_a_hashmap() {
    printheader("Clear a HashMap");

    HashMap *map = (HashMap *) malloc(sizeof(HashMap));
    HashMap_New(map);

    String *str1 = (String *) malloc(sizeof(String));
    String *str2 = (String *) malloc(sizeof(String));
    String *str3 = (String *) malloc(sizeof(String));
    String_New(str1, "What happens to a dream deferred?");
    String_New(str2, "Does it dry up");
    String_New(str3, "Like a raisin in the sun?");

    printf("[INFO]: Populating HashMap with Langston Hughes...\n");
    HashMap_Set(map, "line 1", str1);
    HashMap_Set(map, "line 2", str2);
    HashMap_Set(map, "line 3", str3);
    HashMap_Print(map);

    if(!HashMap_Clear(map)) {
        fprintf(stderr, "[ERROR]: Could not clear HashMap\n\n");
        String_Free(str1); String_Free(str2); String_Free(str3);
        HashMap_Free(map);
        exit(44);
    }

    printf("[SUCCESS]: Cleared and reset HashMap\n");
    HashMap_Print(map); printf("\n");
    HashMap_Free(map);
}

void test_get_size_of_a_hashmap() {
    printheader("Get HashMap Size");

    HashMap *map = (HashMap *) malloc(sizeof(HashMap));
    HashMap_New(map);

    String *str1 = (String *) malloc(sizeof(String));
    String *str2 = (String *) malloc(sizeof(String));
    String_New(str1, "All's well that ends well");
    String_New(str2, "Goodbye World!");

    printf("[INFO]: Populating HashMap with entries...\n");
    HashMap_Set(map, "ending 1", str1);
    HashMap_Set(map, "ending 2", str2);
    HashMap_Print(map);

    printf("[INFO]: Getting the HashMap size...\n");
    size_t size = HashMap_GetSize(map);
    printf("[SUCCESS]: HashMap size is %d\n\n", (int) size);

    String_Free(str1); String_Free(str2);
    HashMap_Free(map);
}

/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/

/* /$$   /$$ /$$$$$$$$ /$$       /$$$$$$$  /$$$$$$$$ /$$$$$$$   /$$$$$$
  | $$  | $$| $$_____/| $$      | $$__  $$| $$_____/| $$__  $$ /$$__  $$
  | $$  | $$| $$      | $$      | $$  \ $$| $$      | $$  \ $$| $$  \__/
  | $$$$$$$$| $$$$$   | $$      | $$$$$$$/| $$$$$   | $$$$$$$/|  $$$$$$
  | $$__  $$| $$__/   | $$      | $$____/ | $$__/   | $$__  $$ \____  $$
  | $$  | $$| $$      | $$      | $$      | $$      | $$  \ $$ /$$  \ $$
  | $$  | $$| $$$$$$$$| $$$$$$$$| $$      | $$$$$$$$| $$  | $$|  $$$$$$/
  |__/  |__/|________/|________/|__/      |________/|__/  |__/ \______/*/

void printheader(char *message) {
    size_t message_length = String_ChrLen(message);
    repeatprint('-', (int) message_length + 16);
    printf("\t%s\t\n", message);
    repeatprint('-', (int) message_length + 16);
    printf("\n");
}

void repeatprint(char c, int times) {
  for(int i = 0; i < times; i++) {
    if(times - 1 == i)
      printf("%c\n", c);
    else
      printf("%c", c);
    }
}


/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/
