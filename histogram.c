/*    ___                       ___                       ___           ___           ___           ___           ___           ___
     /__/\        ___          /  /\          ___        /  /\         /  /\         /  /\         /  /\         /  /\         /__/\
     \  \:\      /  /\        /  /:/_        /  /\      /  /::\       /  /::\       /  /:/_       /  /::\       /  /::\       |  |::\
      \__\:\    /  /:/       /  /:/ /\      /  /:/     /  /:/\:\     /  /:/\:\     /  /:/ /\     /  /:/\:\     /  /:/\:\      |  |:|:\
  ___ /  /::\  /__/::\      /  /:/ /::\    /  /:/     /  /:/  \:\   /  /:/~/:/    /  /:/_/::\   /  /:/~/:/    /  /:/~/::\   __|__|:|\:\
 /__/\  /:/\:\ \__\/\:\__  /__/:/ /:/\:\  /  /::\    /__/:/ \__\:\ /__/:/ /:/___ /__/:/__\/\:\ /__/:/ /:/___ /__/:/ /:/\:\ /__/::::| \:\
 \  \:\/:/__\/    \  \:\/\ \  \:\/:/~/:/ /__/:/\:\   \  \:\ /  /:/ \  \:\/:::::/ \  \:\ /~~/:/ \  \:\/:::::/ \  \:\/:/__\/ \  \:\~~\__\/
  \  \::/          \__\::/  \  \::/ /:/  \__\/  \:\   \  \:\  /:/   \  \::/~~~~   \  \:\  /:/   \  \::/~~~~   \  \::/       \  \:\
   \  \:\          /__/:/    \__\/ /:/        \  \:\   \  \:\/:/     \  \:\        \  \:\/:/     \  \:\        \  \:\        \  \:\
    \  \:\         \__\/       /__/:/          \__\/    \  \::/       \  \:\        \  \::/       \  \:\        \  \:\        \  \:\
     \__\/                     \__\/                     \__\/         \__\/         \__\/         \__\/         \__\/         \__\/

 histogram.c
 Created by Adrian Sanchez
 Created on 07/04/2017
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

#define MAX_LINE 100000

void fprintheader(FILE *fp, char *message, char sep);
void frepeatprint(FILE *fp, char c, int times);
void fprintcmap(FILE *fp, HashMap *m);
void new_character_map(HashMap *m);
char *charsremove(char *str, char *chars);
void strncopy(char * dest, const char * src, size_t n);

int main(int argc, char **argv) {
    FILE *input_file, *output_file;

    int word_count = 0, line_count = 0, character_count = 0, spaces_count = 0;

    char *out_filename = "File1.log";
    char input_line[MAX_LINE];

    if(argc < 2) {
        printf("Usage: histogram file1 [file2, file3, ...]\n");
        exit(1);
    }

    if(!(output_file = fopen(out_filename, "w"))) {
        fprintf(stderr, "[ERROR]: Could not open output file %s", out_filename);
        exit(2);
    }

    HashMap *word_map = (HashMap *) malloc(sizeof(HashMap));
    HashMap *character_map = (HashMap *) malloc(sizeof(HashMap));
    HashMap_New(word_map);
    HashMap_New(character_map);
    //new_character_map(character_map);

    /* Multiple files are supported */

    while(--argc > 0) {
        if(!(input_file = fopen(*++argv, "r"))) {
            fprintf(stderr, "[ERROR]: Could not open file %s for reading\n\n", *argv);
            HashMap_Free(word_map);
            HashMap_Free(character_map);
            exit(3);
        }

        fprintheader(output_file, *argv, '=');

        /* Get the next line of input from the current file being read */

        while((fgets(input_line, MAX_LINE, input_file))) {
            line_count++;

            String *line = (String *) malloc(sizeof(String));
            String *trimmed_line = (String *) malloc(sizeof(String));
            String_New(line, input_line);

            char newline = '\n';
            trimmed_line = String_TrimChar(line, &newline);
            String_Free(line);


            /* Count the number of characters and spaces in the current line, and update character counts in map */

            char c;
            size_t line_length = String_Len(trimmed_line);
            for(int i = 0; i < line_length; i++) {
                c = String_GetChar(trimmed_line, i);
                if(c == ' ' || c == '\t') spaces_count++;
                else character_count++;

                char character[2];
                sprintf(character, "%c", c);

                int *char_count = (int *) malloc(sizeof(int));
                int *new_char_count = (int *) malloc(sizeof(int));
                if(HashMap_Get(character_map, character)) {
                    int *count_ptr = (int *) HashMap_Get(character_map, character);
                    *new_char_count = *count_ptr + 1;
                    free(count_ptr);
                    HashMap_Set(character_map, character, new_char_count);
                } else {
                    *char_count = 1;
                    HashMap_Set(character_map, character, char_count);
                }
            }

            /* Iterate over the words and increment counts accordingly */

            char *stripped = charsremove(String_Get(trimmed_line), ".,\"';-_:");
            String *stripped_line = (String *) malloc(sizeof(String));
            String_New(stripped_line, stripped);

            String_Free(trimmed_line);

            char *delimiters = " \t";
            char *token = String_Tok(stripped_line, delimiters);

            do {
                word_count++;

                int *num_word = (int *) malloc(sizeof(int));
                int *new_num_word = (int *) malloc(sizeof(int));
                if(HashMap_Get(word_map, token)) {
                    int *count_ptr = (int *) HashMap_Get(word_map, token);
                    *new_num_word = *count_ptr + 1;
                    free(count_ptr);
                    HashMap_Set(word_map, token, new_num_word);
                } else {
                    *num_word = 1;
                    HashMap_Set(word_map, token, num_word);
                }
            } while((token = String_Tok(NULL, delimiters)));


            String_Free(stripped_line);
        }

        fprintf(output_file, "Line Count: %d\n", line_count);
        fprintf(output_file, "Word Count: %d\n", word_count);
        fprintf(output_file, "Character Count: %d\n", character_count);
        fprintf(output_file, "Space Count: %d\n", spaces_count);
        fprintf(output_file, "\n");

        fprintheader(output_file, "WORDS", '-');
        fprintcmap(output_file, word_map);
        fprintf(output_file, "\n");

        fprintheader(output_file, "CHARACTERS", '-');
        fprintcmap(output_file, character_map);
        fprintf(output_file, "\n");

        HashMap_Clear(word_map);
        HashMap_Clear(character_map);
        //new_character_map(character_map);

        fclose(input_file);
    }

    fclose(output_file);

    return 0;
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

void fprintheader(FILE *fp, char *message, char sep) {
    size_t message_length = String_ChrLen(message);
    frepeatprint(fp, sep, (int) message_length + 16);
    fprintf(fp, "\t     %s\t\n", message);
    frepeatprint(fp, sep, (int) message_length + 16);
    fprintf(fp, "\n");
}

void frepeatprint(FILE *fp, char c, int times) {
    for(int i = 0; i < times; i++) {
        if(times - 1 == i)
            fprintf(fp, "%c\n", c);
        else
            fprintf(fp, "%c", c);
    }
}

void new_character_map(HashMap *m) {
    int character_count = 'z' - 'a';
    char current_char[2];
    int zero = 0;
    for(int i = 0; i < character_count; i++) {
        sprintf(current_char, "%c", 'a' + i);
        HashMap_Set(m, current_char, &zero);
    }
}

void fprintcmap(FILE *fp, HashMap *m) {
    size_t alist_size = m->table->reserved;

    fprintf(fp, "{");
    for(int i = 0; i < alist_size; i++) {
        LinkedList *llist = (LinkedList *) ArrayList_Get(m->table, i);
        for(ListNode *node = llist->head; node != NULL; node = node->next) {
            MapEntry *entry = (MapEntry *) node->data;
            fprintf(fp, "['%s'] = %d, ", String_Get(entry->key), *((int *) entry->value));
        }
    }
    fseek(fp, -2L, SEEK_END);
    fprintf(fp, "}\n");
}

char *charsremove(char *str, char *chars) {
    size_t chars_len = String_ChrLen(chars);

    char *new = str;
    for(int i = 0; i < chars_len; i++) {
        String *edit_this = (String *) malloc(sizeof(String));
        String_New(edit_this, new);

        String *edited = String_TrimChar(edit_this, &chars[i]);
        String_Free(edit_this);

        strncopy(new, String_Get(edited), String_Len(edited));
        String_Free(edited);
    }

    return new;
}


/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/
