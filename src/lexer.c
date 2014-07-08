#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "lexer.h"
#include "util/util.h"
#include "parser.h"
#include "regex.h"

#define INIT_BUFFER_SIZE 256

void init_lex(lexer *luthor) {
    luthor->file = NULL;
    luthor->buffer = NULL;
    luthor->type = token_SENTINEL;
    luthor->buff_len = 0;
}

void open_file(lexer *lex, char *filename) {
    if (lex) {
	lex->file = fopen(filename, "r");
	if (!lex->file) {
	    fatal_error("Could not read input file.\n");
	}
	lex->buff_len = INIT_BUFFER_SIZE;
	lex->buffer = safe_calloc(INIT_BUFFER_SIZE * sizeof(char));
    }
}

void close_file(lexer *lex) {
    if (lex) {
	fclose(lex->file);
	free(lex->buffer);
	lex->buff_len = 0;
	lex->buffer = NULL;
    }
}

void read_token(lexer *lex) {
    /* TODO: Implement me. */
	//get next character, store it into buffer
	//if parenthesis, then return
	int integerCheck = 1;
	int c;
	if((c = fgetc(*(lex->file))) == EOF){
		lex->type = token_END;
		return;
	}
	char pointer = lex->buffer;
	switch (c){
	case '(':
		lex->type = token_OPEN_PAREN;
		*(pointer) = c;
		break;
	case ')':
		lex->type = token_CLOSE_PAREN;
		*(pointer) = c;
		break;
	case '\"':
		while((c = fgetc(*(lex->file))) != '\"'){
			*pointer++ = c;
			if(c == '\\'){
				c = fgetc(*(lex->file));
				*pointer++ = c;

			}
		}
		lex->type = token_STRING;
		break;
	case ' ':
		while((c = fgetc(*(lex->file))) == ' ');
		ungetc();
		read_token(lex);
		break;
	default:
		do{
			if((c != 45 && c != 46 && c < 48) || c > 59){ //an int
				integerCheck = 0;
			}
			if(c == ')' || c == ' ' || c =='('){
				ungetc();
				break;
			}else if(c == '\n'){
				//ensure that there is incrementation in fgetc
				continue;
			}
			*pointer++ = c;
		}while((c = fgetc(*(lex->file))) != EOF);

		if(integerCheck){
			lex->type = token_INT;
		}else if(lookup_keyword_enum(lex->buffer) != -1){
			lex->type = token_KEYWORD;
		}else{
			lex->type = token_NAME;
		}
		break;

	}
	*pointer++ = '\0';

	//if close paren, then ungetc
    /* HINT: fgetc() and ungetc() could be pretty useful here. */
}

token_type peek_type(lexer *lex) {
    if (!lex) {
	return token_SENTINEL;
    }
    if (lex->type == token_SENTINEL) {
	read_token(lex);
    }
    return lex->type;
}

char *peek_value(lexer *lex) {
    if (!lex) {
	return NULL;
    }
    if (lex->type == token_SENTINEL) {
	read_token(lex);
    }
    return lex->buffer;
}
