//
// Created by Pascal Vigneau on 17/10/2022.
//

#ifndef BA_LEXER_H
#define BA_LEXER_H

#include <stdint.h>
#include <stdlib.h>
#include "stdbool.h"


/**
 id : [a-zA-Z_][a-zA-Z0-9_]

 type : 'string' | 'number' | 'boolean'

 declaration : {id} ':' {type} ';'

 expression : {id}

 assignment : {id} '=' {expression} ';'

 print : 'print' {expression} ';'

 */

static  const uint8_t *KEYWORDS[] = {
        "string", "number", "boolean",  // type
        "print"                         // builtin function
};

static const uint8_t *TYPES[] = {
        "string", "number", "boolean"
};

static const uint8_t ATOMICS[] = {
        ':', ';', '='
};

typedef enum {
    TOKEN_ID,
    TOKEN_TYPE,
    TOKEN_COLON,
    TOKEN_SEMICOLON,
    TOKEN_ASSIGNMENT,
    TOKEN_VALUE,
    TOKEN_PRINT,

    TOKEN_UNKNOWN

} TokenType;

typedef struct {
    uint8_t *val;
    TokenType type;

} Token;

typedef struct Tokens {
    Token token;
    struct Tokens *prev;
} Tokens;

uint8_t *read_entry(char *filename);
Tokens *new_tokens();
void add_token(Tokens **tokens, uint8_t *val, size_val);
void tokenize(Tokens **tokens, uint8_t *seq);
void display_tokens(Tokens *tokens);

uint8_t *process_validstr(Tokens **tokens, uint8_t *seq);
uint8_t *process_atomic(Tokens **tokens, uint8_t *seq);

Token init_token(uint8_t *val, size_t size_val);
TokenType tokenof(uint8_t *val);
uint8_t *stringof_type(TokenType type);

bool isid(uint8_t *val);
bool istype(uint8_t *val);
bool isvalue(uint8_t *val);
bool iskeyword(uint8_t *val);
static bool strcontains(const uint8_t **strings, size_t size, uint8_t *s);
bool isatomic(uint8_t seq);


#endif //BA_LEXER_H
