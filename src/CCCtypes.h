#ifndef CCCTYPES_H
#define CCCTYPES_H

#include <string.h>
#include <malloc.h>
#include <stdio.h>

typedef          char   i8;
typedef          short  i16;
typedef          int    i32;
typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;
typedef          float  f32;
typedef          double f64;

// create a new string in heap, inserting another string
// where - after which index insert
char *CCCstr_insert(char *str, u32 where, char *what)
{
    size_t str_len  = strlen(str);
    size_t what_len = strlen(what);

    if (where >= str_len) {
        return NULL;
    }
    
    char *res = (char*)malloc(str_len + what_len + 1);
    for (int i = 0; i < where; i++) {
        res[i] = str[i];
    }
    for (int i = 0; i < what_len; i++) {
        res[where + i] = what[i];
    }
    for (int i = where; i < str_len; i++) {
        res[what_len + i] = str[i];
    }
    res[str_len + what_len] = '\0';

    return res;
}

// create a new string in heap
// delete part of str and replace to what
char *CCCstr_replace(char *str, u32 repl_start, u32 repl_end, char *repl)
{
    size_t str_len  = strlen(str);
    size_t repl_len = strlen(repl);
    
    if (repl_start > str_len || repl_end > str_len || repl_end <= repl_start) {
        return NULL;
    }

    char *res = (char*)malloc(str_len - (repl_end - repl_start) + repl_len + 1);
    for (int i = 0; i < repl_start; i++) {
        res[i] = str[i];
    }
    for (int i = 0; i < repl_len; i++) {
        res[repl_start + i] = repl[i];
    }
    for (int i = repl_end; i < str_len; i++) {
        res[abs((repl_end - repl_start) - repl_len) + i] = str[i];
    }
    res[str_len - (repl_end - repl_start) + repl_len] = '\0';

    return res;
}

#endif