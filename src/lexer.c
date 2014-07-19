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
    luthor->prev = 0;
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


/*
 * Methods in place for regex
 */
int isAlphabet(int c){
	return !(c < 65 || (c > 90 && c < 97 )|| c > 122);
}

int invalidNameCheck(int c){
	return (c < 48 || (!isAlphabet(c) && c != 95));
}


void read_token(lexer *lex) {
    /* TODO: Implement me. */
	//get next character, store it into buffer
	//if parenthesis, then return
	int integerCheck = 1;
	int validName = 1;
	int c;

	if(lex->type != token_SENTINEL){
		lex->prev = lex->type;
	}
	if((c = fgetc(lex->file)) == EOF){
		lex->type = token_END;
		*(lex->buffer) = '\0';
		return;
	}
	char *pointer = lex->buffer;
	switch (c){

	//for comments
	case ';':
		while((c = fgetc(lex->file)) != '\n'){

		};
		read_token(lex);
		return;
	case '\t':
	case '\n':
		read_token(lex);
		return;
	case '(':
		lex->type = token_OPEN_PAREN;
		*(pointer++) = c;
		break;
	case ')':
		lex->type = token_CLOSE_PAREN;
		*(pointer++) = c;
		break;
	case '\"':
		do{
			*pointer++ = c;
			if(c == '\\'){
				c = fgetc(lex->file);
				*pointer++ = c;
			}
		} while((c = fgetc(lex->file)) != '\"');
		*pointer++ = c;

		lex->type = token_STRING;
		break;
	case ' ':
		while((c = fgetc(lex->file)) == ' '){};
		ungetc(c, lex->file);
		read_token(lex);
		return;
	default:
		do{
			if(c == ')' || c == ' ' || c =='(' || c == '\n'){
				ungetc(c, lex->file);
				break;
			}
			if(invalidNameCheck(c)){
				validName = 0;
			}
			if(c == 45){
				int temp = fgetc(lex->file);
				if((temp != 46 && temp < 48) || temp > 59){
					integerCheck = 0;
				}
				ungetc(temp, lex->file);
			}else if((c != 46 && c < 48) || c > 59){ //an int
				integerCheck = 0;
			}
			*pointer++ = c;
		}while((c = fgetc(lex->file)) != EOF);
		*pointer = '\0';

		if(integerCheck){
			lex->type = token_INT;
		}else if((int)lookup_keyword_enum(lex->buffer) != -1){
			lex->type = token_KEYWORD;
		}else if(validName && isAlphabet(*(lex->buffer))){
			lex->type = token_NAME;
		}else{
			fprintf(stderr, "Invalid Name and Not Keyword - Problem in Input \"%s\"", lex->buffer);
			exit(1);
		}
		break;

	}
	*pointer = '\0';


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
