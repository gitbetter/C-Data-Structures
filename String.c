/*    ___                       ___                       ___           ___
     /  /\          ___        /  /\        ___          /__/\         /  /\
    /  /:/_        /  /\      /  /::\      /  /\         \  \:\       /  /:/_
   /  /:/ /\      /  /:/     /  /:/\:\    /  /:/          \  \:\     /  /:/ /\
  /  /:/ /::\    /  /:/     /  /:/~/:/   /__/::\      _____\__\:\   /  /:/_/::\
 /__/:/ /:/\:\  /  /::\    /__/:/ /:/___ \__\/\:\__  /__/::::::::\ /__/:/__\/\:\
 \  \:\/:/~/:/ /__/:/\:\   \  \:\/:::::/    \  \:\/\ \  \:\~~\~~\/ \  \:\ /~~/:/
  \  \::/ /:/  \__\/  \:\   \  \::/~~~~      \__\::/  \  \:\  ~~~   \  \:\  /:/
   \__\/ /:/        \  \:\   \  \:\          /__/:/    \  \:\        \  \:\/:/
     /__/:/          \__\/    \  \:\         \__\/      \  \:\        \  \::/
     \__\/                     \__\/                     \__\/         \__\/


     String.m
     Created by Adrian Sanchez
     Created on 07/02/2017
*/

/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/


#include "String.h"

void strncopy(char * dest, const char * src, size_t n);
void strnappend(char * dest, const char * src, size_t n);
int strcontains(char *str, char c);
void reverse(char *str);
int isws(char c);

/*
 * Populate a pre-allocated String * with the given string
 * and extra data (hash and length)
 */
int String_New( String *strObj, char *str ) {
    if(strObj == NULL || str == NULL)
        return 0;

    int strLength = String_ChrLen(str);
    size_t strHash = String_CreateHash(str);

    strObj->size = strLength;
    strObj->hashcode = strHash;
    if(!(strObj->str = (char *) malloc(strLength + 1)))    // (Length of string * Length of char (1, implicit) + 1 for \0 character
        return 0;

    strncopy(strObj->str, str, strLength);

    return strLength;
}

/*
 * Free up a previously allocated String * in memory
 */
void String_Free( String *strObj ) {
    if(strObj == NULL) return;
    if(strObj->str) free(strObj->str);
    strObj->str = NULL;
    free(strObj);
}

/*
 * Get the string length using the provided character pointer,
 * excluding the null termination character '\0'
 */
size_t String_ChrLen(char *str) {
    size_t i;
    char *p = str;
    for(i = 0; *p++ != '\0'; i++) ;
    return i;
}

/*
 * Check for String * length equality
 */
int String_EqualLen(String *lhs, String *rhs) {
    return lhs->size == rhs->size;
}

/*
 * Check for String * string equality, character by character,
 * also taking into account the length
 */
int String_Equal( String *lhs, String *rhs ) {
    int same_characters = String_EqualN(lhs, rhs, lhs->size);
    int same_length = String_EqualLen(lhs, rhs);
    return same_length & same_characters;
}

/*
 * Check for String * string equality, up to n characters
 */
int String_EqualN(String *lhs, String *rhs, size_t n)
{
    for (int i = 0; i < n; i++)
        if (lhs->str[i] != rhs->str[i])
            return 0;

    return 1;
}

/*
 * Return the char * contained in the String *
 */
char *String_Get(String *strObject) {
    return strObject->str;
}

/*
 * Add strAppend to the end of the String * string,
 * making sure to overwrite the first '\0' and write a new
 * one at the end. Memory reallocation is required to accomodate
 * the new string.
 */
int String_Append( String *strObj, char *strAppend ) {
    size_t newStringLen = String_ChrLen(strAppend);
    if(!(strObj->str = (char *) realloc(strObj->str, newStringLen + strObj->size)))
        return 0;

    char *p = strObj->str;
    for( ; *p++ != '\0'; ) ;        // Walk the pointer to the null character
    strncopy(--p, strAppend, newStringLen);    // Copy the new string to the end of the existing string

    strObj->hashcode = String_CreateHash(strObj->str);

    return 1;
}

/*
 * Clear the strObj entry by resetting the length and hash,
 * and freeing up the memory allocated for the internal char *
 */
void String_Delete( String *strObj ) {
    strObj->size = 0;
    strObj->hashcode = 0;
    free(strObj->str);
    strObj->str = NULL;
}

/*
 * Return the character in the position specified by index, or
 * null if the index is out of bounds
 */
char String_GetChar( const String *strObj, const size_t index ) {
    if(index > strObj->size)
        return 0;

    return strObj->str[index];
}

/*
 * Replace the character in the position specified by index with c,
 * or do nothing if the index is out of bounds
 */
void String_SetChar( String *strObj, const size_t index, const char c ) {
    if(index > strObj->size)
        return;

    strObj->str[index] = c;
    strObj->hashcode = String_CreateHash(strObj->str);   // TODO: Parameter declaration should not be const so as to allow recomputing of hash
}

/*
 * Copy the source String * and all relevant data to the destination String *
 */
String *String_Cpy ( String *destination, const String *source ) {
    return String_nCpy(destination, source, source->size);
}

/*
 * Copy the source String * to the destination String *, up to num characters,
 * and compute a new hash and length
 */
String *String_nCpy ( String *destination, const String *source, size_t num ) {
    if(!(destination->str = (char *) realloc(destination->str, num + 1)))
        return NULL;

    strncopy(destination->str, source->str, num);
    destination->hashcode = String_CreateHash(destination->str);
    destination->size = num;

    return destination;
}

/*
 * Concatenate the the source String * with the destination String *
 * and return the result in a new String *
 */
String *String_Cat ( String *destination, const String *source ) {
    return String_nCat(destination, source, source->size);
}

/*
 * Concatenate num characters of the source String * with the destination String * and return
 * a new String * with all the relevant information
 */
String *String_nCat ( String *destination, const String *source, size_t num ) {
    if((destination->str = (char *) realloc(destination->str, destination->size + num + 1)) == NULL)
        return NULL;

    strnappend(destination->str, source->str, num);
    destination->hashcode = String_CreateHash(destination->str);
    destination->size = destination->size + num;

    return destination;
}

/*
 * Compare str1 with str2, character by character, using the
 * minimum of the two string sizes to limit the comparison
 */
int String_Cmp ( const String *str1, const String *str2 ) {
    size_t min_n = str1->size < str2->size ? str1->size : str2->size;  // Compare at most the size of the smallest string
    return String_nCmp(str1, str2, min_n);
}

/*
 * Compare up to num characters of str1 with str2
 */
int String_nCmp ( const String *str1, const String *str2, size_t num ) {
    char *first = str1->str;
    char *second = str2->str;
    for(int i = 0; i < num; i++)
        if(first[i] != second[i])
            return first[i] < second[i] ? -1 : 1;

    return 0;
}

/*
 * Return a String * to the first occurrence of character
 * in str
 */
String *String_Chr ( String *str, int character ) {
    char *p = str->str;
    while(*p != character && *p != '\0') p++;
    if(*p != '\0') {
        String *found = (String *) malloc(sizeof(String));
        String_New(found, p);
        return found;
    }
    return NULL;
}

/*
 * Returns the number of characters read from str1 before
 * any of the characters in str2 are encountered
 */
size_t String_cSpn ( const String *str1, const String *str2 ) {
    size_t i;
    for(i = 0; str1->str[i] != '\0'; i++)
        if(strcontains(str2->str, str1->str[i]))
            return i;

    return i;
}

/*
 * Returns a String * to the first occurrence in str1 of any of
 * the characters in str2
 */
String *String_pBrk ( const String *str1, const String *str2 ) {
    size_t span;
    if((span = String_cSpn(str1, str2) > str1->size))
        return NULL;

    String *strP = (String *) malloc(sizeof(String));
    String_New(strP, (str1->str + span));
    return strP;
}

/*
 * Return a String * to the last occurrence of character in str
 */
String *String_rChr ( const String *str, int character ) {
    String *pr = NULL;
    char *p = str->str;

    for(; *p != '\0'; p++)
      if(*p == character) {
        if(pr) String_Free(pr);
        pr = (String *) malloc(sizeof(String));
        String_New(pr, p);
      }

    return pr;
}

/*
 * Return the length (span) of the number of characters encountered after, and
 * including, the first occurrence of any of the characters in str2 in str1, which
 * are also in str2
 */
size_t String_spn ( const String *str1, const String *str2 ) {
    size_t start_idx = String_cSpn(str1, str2);
    size_t span_count = start_idx >= str1->size ? 0 : 1;

    char *p = str1->str + start_idx;
    while(strcontains(str2->str, *p++)) ++span_count;
    return span_count;
}

/*
 * Check if str2 is contained in str1, and if so return a new String *
 * to the beginning of str2 in str1. Otherwise, return NULL
 */
String *String_Str ( String *str1, const String *str2 ) {
    char *p1 = str1->str, *p2 = str2->str;

    while(*p1 != *p2) p1++;
    if(*p1 == '\0') return NULL;

    String *sub = (String *) malloc(sizeof(String));
    String_New(sub, p1);

    while(*p1++ == *p2++ && *p2 != '\0') ;

    if(*p2 == '\0')
      return sub;

    String_Free(sub);
    return NULL;
}

/*
 * Simply returns the size field of any String *
 */
size_t String_Len ( const String *str ) {
    if(!str)
        return 0;
    
    return str->size;
}

/*
 * Simply returns the hashcode field of any String *,
 * previously computed by String_CreateHash
 */
size_t String_GetHashCode( const String *str ) {
    if(!str)
        return 0;
    
    return (size_t) str->hashcode;
}

/*
 * Uses a basic hashing algorithm to create a hashcode
 * unique to this collection of characters
 */
size_t String_CreateHash( const char *str ) {
    size_t hash = 0;
    char *p = str;
    for( ; *p++ != '\0' ; ) hash = *str + 37 * hash;
    return hash;
}

/*
 * Return a new string with the trailing and tailing white space of String *str removed
 */
String *String_Trim( String *str ) {
    String *ltrimmed = String_LTrim(str);
    String *trimmed = String_RTrim(ltrimmed);
    
    String_Free(ltrimmed);
    return trimmed;
}

/*
 * Return a new string with white space from the head of String *str removed
 */
String *String_LTrim( String *str ) {
    char *p = (char *) malloc(str->size + 1);
    strncopy(p, str->str, str->size);

    while(isws(*p)) p++;

    String *lTrimmed = (String *) malloc(sizeof(String));
    String_New(lTrimmed, p);
    return lTrimmed;
}

/*
 * Return a new string with white space from the tail of String *str removed
 */
String *String_RTrim( String *str ) {
    char *p;
    String *rTrimmed;
    if(!(p = (char *) malloc(str->size + 1)))
        return NULL;

    strncopy(p, str->str, str->size);

    reverse(p);
    while(isws(*p)) p++;
    reverse(p);

    if(!(rTrimmed = (String *) malloc(sizeof(String))))
        return NULL;

    String_New(rTrimmed, p);
    return rTrimmed;
}

/*
 * Return the character at position index of String *str
 */
size_t String_GetCharFromIndex( const String *str, int index ) {
    return (size_t) String_GetChar(str, (size_t) index);
}

/*
 * Return the index of char c in String *str, otherwise return
 * the index past the last element of the string
 */
 int String_IndexOfChar( const String *str, char c ) {
    int i;
    for(i = 0; i < str->size; i++)
        if(str->str[i] == c)
            return i;

    return i;
}

/*
 * Return a new string with all the characters of String *str converted
 * to lowercase
 */
String *String_Lower( String *str ) {
    char *p;
    if(!(p = (char *) malloc(str->size + 1)))
        return NULL;
    strncopy(p, str->str, str->size);

    for(int i = 0; p[i] != '\0'; i++)
        if(p[i] >= 'A' && p[i] <= 'Z')
            p[i] = p[i] + 'a' - 'A';

    String *lower;
    if(!(lower = (String *) malloc(sizeof(String))))
        return NULL;

    String_New(lower, p);
    return lower;
}

/*
 * Return a new string with all the characters of String *str converted
 * to uppercase
 */
String *String_Upper( String *str ) {
    char *p;
    if(!(p = (char *) malloc(str->size + 1)))
        return NULL;
    strncopy(p, str->str, str->size);

    for(int i = 0; p[i] != '\0'; i++)
        if(p[i] >= 'a' && p[i] <= 'z')
            p[i] = p[i] + 'A' - 'a';

    String *upper;
    if(!(upper = (String *) malloc(sizeof(String))))
        return NULL;

    String_New(upper, p);
    return upper;
}

/*
 * Return a reverse copy of String *str
 */
String *String_Reverse( String *str ) {
    char *p;
    String *reversed;
    if(!(p = (char *) malloc(str->size + 1)))
        return NULL;
    strncopy(p, str->str, str->size);
    reverse(p);

    if(!(reversed = (String *) malloc(sizeof(String))))
        return NULL;

    String_New(reversed, p);
    return reversed;
}

/*
 * Count the number of words in String *str, which is anything
 * delimited by whitespace
 */
size_t String_WordCount( const String *str ) {
    String *p = String_Trim(str);

    char *trim = p->str;
    int count = 0;
    while(*trim != '\0')
        if(isws(*trim++)) {
          while(isws(*trim)) trim++;
          ++count;
        }

    String_Free(p);
    return count;
}

/*
 * Return str if String *str starts with String *startsWith, or NULL
 * otherwise
 */
String *String_StartsWith( const String *str, const String *startsWith ) {
    String *p;
    if((p = String_Str(str, startsWith)) && String_GetHashCode(p) == String_GetHashCode(str))
      return p;

    String_Free(p);
    return NULL;
}

/*
 * Return a new string with all occurrences of char *c in String *str removed
 */
String *String_TrimChar( String *str, const char *c ) {
    char *p;
    if(!(p = (char *) malloc(str->size + 1)))
        return NULL;

    int c_count = 0;

    int j = 0;
    for(int i = 0; i < str->size; i++) {
        if(str->str[i] == *c) {
            ++c_count;
            continue;
        }
        p[j++] = str->str[i];
    }
    p[j] = '\0';

    char *tmp = p;
    if(!(p = (char *) realloc(p, str->size - c_count + 1))) {
        free(tmp);
        return NULL;
    }

    String *cTrimmed;
    if(!(cTrimmed = (String *) malloc(sizeof(String)))) {
        free(p);
        return NULL;
    }

    String_New(cTrimmed, p);
    return cTrimmed;
}

/*
 * Will split str into tokens, delimited by passed in delimiters pointer.
 * On first invocation, the function takes a String * from which to start tokenizing.
 * The state is saved internally, and subsequent calls must pass in a null pointer
 * to advance to the next token of the initial String *. Calling with a String * again
 * will reset the internal variable and overwrite previous tokenization. If '\0' is encountered
 * on the initial String * during one of the invocations, subsequent calls using null
 * as a parameter will return null.
 */
char *String_Tok( String *str, const char *delimiters ) {
    static char *p;
    if(str) {
        p = (char *) malloc(str->size + 1);
        strncopy(p, str->str, str->size);
    }

    if(!p || !*p)
        return NULL;

    while(*p && strcontains(delimiters, *p)) p++;             // Skip initial delimiters

    size_t p_remaining = String_ChrLen(p);              // Copy remainder of p into new token
    char *q = (char *) malloc(p_remaining + 1);         // pointer
    strncopy(q, p, p_remaining);

    char *s = q;                                        // Save beginning of new copy q
    int token_length = 0;
    while(*p && !strcontains(delimiters, *p)) p++, q++, token_length++;
    *q = '\0';

    s = (char *) realloc(s, token_length + 1);          // Resize token to appropriate length

    return s;                                           // Here's your token
}

void String_Print(String *str) {
    if(str)
        printf("%lu = %s\n", String_GetHashCode(str), String_Get(str));
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


void strncopy(char * dest, const char * src, size_t n) {
    char *d = dest, *s = src;
    size_t limit = 0;
    while((*d++ = *s++) && limit++ < n);

    if(*--d != '\0') *d = '\0';
}

void strnappend(char * dest, const char * src, size_t n) {
    char *p = dest;
    while (*p++ != '\0') ;  // Walk to the end of p
    strncopy(--p, src, n);  // Append src to the new p
}

int strcontains(char *str, char c) {
    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] == c)
            return 1;
    return 0;
}

void reverse(char *str) {
    int c;
    for(int i = 0, j = String_ChrLen(str) - 1; i < j; i++, j--)
       c = str[i], str[i] = str[j], str[j] = c;
}

int isws(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
}


/*/$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$ /$$$$$$
 |______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/|______/*/
