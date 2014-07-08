#include "parser.h"
#include "lexer.h"
#include <string.h>
#include <stdlib.h>

/** An array of the different string values of keywords. */
char *keywords[] = {
		"and",
		"or",
		"+",
		"-",
		"*",
		"/",
		"lt",
		"eq",
		"function",
		"struct",
		"arrow",
		"assign",
		"if",
		"while",
		"for",
		"sequence",
		"intprint",
		"stringprint",
		 "readint"};
/** Sister array of keywords. Keeps track of the corresponding enum. */
int enums[] = {
		node_AND,
		node_OR,
		node_PLUS,
		node_MINUS,
		node_MUL,
		node_DIV,
		node_LT,
		node_EQ,
		node_FUNCTION,
		node_STRUCT,
		node_ARROW,
		node_ASSIGN,
		node_IF,
		node_WHILE,
		node_FOR,
	    node_SEQ,
	    node_I_PRINT,
	    node_S_PRINT,
	    node_READ_INT};



extern smap *decls;
extern smap *stack_sizes;
extern smap *num_args;
extern smap *strings;

extern smap *key_enum_arg;


key_type key_table [] = {
	{  "and",			"node_AND",			2 },
	{  "or",			"node_OR", 			2 },
	{  "+",				"node_PLUS", 		2 },
	{  "-",				"node_MINUS", 		2 },
	{  "*",				"node_MUL", 		2 },
	{  "/",				"node_DIV", 		2 },
	{  "lt",			"node_LT", 			2 },
	{  "eq",			"node_EQ", 			2 },
	{  "function",		"node_FUNCTION", 	1 },
	{  "struct",		"node_STRUCT", 		2 },
	{  "arrow",			"node_ARROW", 		2 },
	{  "assign",		"node_ASSIGN", 		2 },
	{  "if",			"node_IF", 			3 },
	{  "while",			"node_WHILE", 		2 },
	{  "for",			"node_FOR", 		4 },
	{  "sequence",		"node_SEQ", 		-1 },
	{  "intprint",		"node_I_PRINT", 	1 },
	{  "stringprint",	"node_S_PRINT", 	1 },
	{  "readint",		"node_READ_INT", 	0 },

};


/** A hashmap used for more efficient lookups of (keyword, enum) pairs. */
smap *keyword_str_to_enum;


/** Initializes keyword_str_to_enum so that it contains a map
 *  from the string value of a keyword to its corresponding enum. */
void initialize_keyword_to_enum_mapping();

//initialize hashmap for num_args
//initialize delcarations

void parse_init() {
    decls = smap_new();
    stack_sizes = smap_new();
    num_args = smap_new();
    strings = smap_new();
    keyword_str_to_enum = smap_new();
}

void parse_close() {
    smap_del_contents(decls);
    smap_del(decls);
    smap_del(stack_sizes);
    smap_del(num_args);
    smap_del(strings);
    smap_del(keyword_str_to_enum);
}

AST *build_ast (lexer *lex) {
    /* TODO: Implement me. */
    /* Hint: switch statements are pretty cool, and they work 
     *       brilliantly with enums. */
	AST level = malloc(sizeof(AST)); //make new AST
	read_token(lex);
	char *current = lex->buffer; //obtain next token

	switch(lex->type){
	case(token_SENTINEL):
		break;
	case(token_OPEN_PAREN):
		//if open-paren, return build_ast to take next token
		//check first token and all the rest go into children
		return build_ast(lex);
	case(token_CLOSE_PAREN):
		return NULL;
	default:
		level->val = current;
		return level;
	}
    return NULL;
}
node_type name_cases(AST st, lexer *lex){//not sure

	//check
}

/*
 * Check the number of arguments a specific node has
 */

void free_ast (AST *ptr) {
    /* TODO: not DONE */
	//dfs
	free(ptr);
}

void check_tree_shape(AST *ptr) {
    /* TODO: Implement me. */
    /* Hint: This function is just asking to be table-driven */

	//WHAT ABOUT STRUCT

	//DFS - Start from top,
	//check_tree_shape child
	//switch case:
	//if(type == node_INT || node_STRING || variable? || node_seq )
	//return;
	//if(type == node_call )
	//check hashmap for specific quantity
	//else{
		//check specific type
		//return hashmap number of arguments
		//if(number of arguments != AST_lst_len(current))
		//exit with problem
	while(1){};
	//check next_tree child while not null
	//
}

void gather_decls(AST *ast, char *env, int is_top_level) {
    /* TODO: Implement me. */
    /* Hint: switch statements are pretty cool, and they work 
     *       brilliantly with enums. */

	//assign types
	//add everything into a general list of
	//add things into string
	//function, include name to number of arguments


}

key_type lookup_keywords(char *str){
	if (smap_get(key_enum_arg, key_table[0]->keywords) == -1){
		initialize_keyword_master();
	}
	return smap_get(key_enum_arg, str);
}

void initialize_keyword_master(){
	size_t num_keywords = sizeof(enums) / sizeof(int);
	for(size_t i = 0; i < num_keywords; i ++){
		smap_put(key_enum_arg, key_table[i]->keywords, key_table[i]);
	}
}

//node_type lookup_keyword_enum(char *str) {
//    if (smap_get(keyword_str_to_enum, keywords[0]) == -1) {
//	initialize_keyword_to_enum_mapping();
//
//    }
//    return smap_get(keyword_str_to_enum, str);
//}
//
//void initialize_keyword_to_enum_mapping() {
//    /* Note that enums is an *array*, not a pointer, so this
//     * sizeof business is reasonable. */
//    size_t num_keywords = sizeof(enums) / sizeof(int);
//    for (size_t i = 0; i < num_keywords; i += 1) {
//	smap_put(keyword_str_to_enum, keywords[i], enums[i]);
//    }
//}

size_t AST_lst_len(AST_lst *lst) {
    int num_fields = 0;
    while (lst) {
	num_fields += 1;
	lst = lst->next;
    }
    return num_fields;
}

