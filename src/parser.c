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



smap *decls;
smap *stack_sizes;
smap *num_args;
smap *strings;
smap *declFrames;
string_struct *string_list;
string_struct *current_string;

/** A hashmap used for more efficient lookups of (keyword, enum) pairs. */
smap *keyword_str_to_enum;

key_type_t key_table [] = {
	{  "and",			node_AND,			2 },
	{  "or",			node_OR, 			2 },
	{  "+",				node_PLUS, 		2 },
	{  "-",				node_MINUS, 		2 },
	{  "*",				node_MUL, 		2 },
	{  "/",				node_DIV, 		2 },
	{  "lt",			node_LT, 			2 },
	{  "eq",			node_EQ, 			2 },
	{  "function",		node_FUNCTION, 	1 },
	{  "struct",		node_STRUCT, 		2 },
	{  "arrow",			node_ARROW, 		2 },
	{  "assign",		node_ASSIGN, 		2 },
	{  "if",			node_IF, 			3 },
	{  "while",			node_WHILE, 		2 },
	{  "for",			node_FOR, 		4 },
	{  "sequence",		node_SEQ, 		-1 },
	{  "intprint",		node_I_PRINT, 	1 },
	{  "stringprint",	node_S_PRINT, 	1 },
	{  "readint",		node_READ_INT, 	0 },
	{  "DONE",			0,					0 }

};






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
    string_list = safe_calloc(sizeof(string_struct));
    current_string = string_list;
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
	AST *level = safe_calloc(sizeof(AST)); //make new AST
	read_token(lex);
	char *current = lex->buffer; //obtain next token

	switch(lex->type){
	case(token_SENTINEL):
		break;
	case(token_OPEN_PAREN):
		//if open-paren, return build_ast to take next token
		//check first token and all the rest go into children
		level = build_ast(lex);
		AST *child;
		while((child = build_ast(lex)) != NULL){
			AST_lst *levelchild = safe_calloc(sizeof(AST_lst));
			levelchild->node = child;
			if(!level->children){
				level->children = levelchild;
			}else{
				level->last_child->next = levelchild;
			}
			level->last_child = levelchild;
		}
		if(level->type == node_FUNCTION){ //if there is a function, add to argument map
			add_function_args(level);
		}
		return level;
	case(token_CLOSE_PAREN):
		return NULL;
	case(token_KEYWORD):
		level->type = lookup_keyword_enum(current); //if keyword doesn't match anything
		if((int)level->type == -1){
			printf("This is a problem");
			exit(0);
		}
		break;
	case(token_INT):
		level->type = node_INT;
		break;
	case(token_STRING):
		level->type = node_STRING;
		break;
	case(token_END):
		break;
	case(token_NAME):
		if(lex->prev == token_OPEN_PAREN){ //if a "var/name", check if it is CALL or VARIABLE
			level->type = node_CALL;

		}else{
			level->type = node_VAR;
		}
		break;

	default:

		break;
	}
	level->val = current;
    return level;

}

/*
 * Check the number of arguments a specific node has
 */

void add_function_args(AST *ast){
	if(ast->type != node_FUNCTION){
		printf("Miscall");
		exit(0);
	}else{
		AST *declarations_tree = ast->children->node;
		char *name = declarations_tree->val;
		int num_of_args = AST_lst_len(declarations_tree->children);
		smap_put(num_args, name, num_of_args);
	}
}

/*
 *
 */
void add_function_decl(AST *ast){
	if(ast->type != node_FUNCTION){
			printf("Miscall");
			exit(0);
	}else{
		AST *declarations_tree = ast->children->node;
		char *name = declarations_tree->val;
		AST *func_body = ast->children->next->node;
		smap_put(decls, name, (int)func_body); //may be a problem
	}
}

void free_ast (AST *ptr) {
    /* TODO: not DONE */
	//dfs
	AST_lst *childs = ptr->children;
	while(ptr->last_child != NULL){
		free_ast(childs->node);
		AST_lst *nex_List = childs->next;
		free(childs);
		childs = nex_List;
	}
	free(ptr);
}


//for literals, does nothing
//for function calls, # of arguments is given in above
//checking will continue as planned
void check_tree_shape(AST *ptr) {
    /* TODO: Implement me. */
    /* Hint: This function is just asking to be table-driven */

	//WHAT ABOUT STRUCT - don't need to check probably,
	node_type check = ptr->type;
	int arg_count;
	if(check == node_INT || check == node_STRING){
		arg_count = 0;
	}else if(check == node_CALL){
		arg_count = lookup_function_args(ptr->val);
	}else{
		arg_count = lookup_arg(check);
	}

	if(AST_lst_len(ptr->children) != arg_count){
		printf("This is a problem - Inconsistency between arg_count and expected");
		exit(0);
	}
	AST_lst *current = ptr->children;
	for(int x = 0; x < arg_count; x++){
		check_tree_shape(current->node);
		current = current->next;
	}

}

void store_string(char *variable, char *string){
	current_string->name = variable;
	current_string->string_value = string;
	current_string->next = safe_calloc(sizeof(string_struct));
	current_string = current_string->next;

}

void gather_decls(AST *ast, char *env, int is_top_level) {
    /* TODO: Implement me. */
    /* Hint: switch statements are pretty cool, and they work 
     *       brilliantly with enums. */
	//scope is defined by 
	node_type type = ast->type;
	AST_lst *child_list = ast->children;

	char *key = child_list->node->val;   //first argument VALUE
	AST *value = child_list->next->node; //second argument tree

	switch(type){
	case(node_ASSIGN):
		smap_put(decls, key, (int)value);
		if(value->type == node_STRING){
			//stores the address of the string
			smap_put(strings, key, (int)value->val); //conditionals may screw this up
			store_string(key, value->val);
		}
		smap_put(declFrames, key, (int)env);
		//have to remove this after environment is closed

		break;

	case(node_FUNCTION):
		add_function_decl(ast);
		if(is_top_level == 0){
			printf("Function not on top level");
			exit(0);
		}
		//add variables
		//TODO: how to deal with function itself - STORE RETURN ADDRESS
		break;

	case(node_STRUCT):
		break;
	case(node_VAR):
		if(smap_get(decls, ast->val) == -1 && smap_get(strings, key) == -1){
			exit(0);
		}
		break;

	case(node_CALL):
		if(smap_get(decls, ast->val) == -1){
			printf("There is a problem - Function called before declared");
			exit(0);
		}
		AST_lst *child = ast->children;
		for(int x = AST_lst_len(child); x > 0; x --){
			//sets the function name as environment
			gather_decls(child->node, ast->val, 0);
		}

		break;

	default:
		break;

	}
	AST_lst *current = ast->children;
	for(int x = AST_lst_len(ast->children); x > 0; x --){
		gather_decls(current->node, env, 0);
		current = current->next;
	}



	//assign types
	//add everything into a general list of
	//add things into string
	//function, include name to number of arguments


}

int lookup_arg(node_type type){
	if(type == 0){ //TODO: may be a problem
		printf("ERROR");
	}
	int x = 0;
	key_type_t *current = &key_table[x];
	while(current->enums != 0){
		if(current->enums == type){
			return current->args;
		}
		current = &key_table[++x];
	}
	return 0;

}


node_type lookup_keyword_enum(char *str) {
    if (smap_get(keyword_str_to_enum, keywords[0]) == -1) {
	initialize_keyword_to_enum_mapping();

    }
    return smap_get(keyword_str_to_enum, str);
}

int lookup_function_args(char *fn){
	return smap_get(num_args, fn);
}

void initialize_keyword_to_enum_mapping() {
    /* Note that enums is an *array*, not a pointer, so this
     * sizeof business is reasonable. */
    size_t num_keywords = sizeof(enums) / sizeof(int);
    for (size_t i = 0; i < num_keywords; i += 1) {
	smap_put(keyword_str_to_enum, keywords[i], enums[i]);
    }
}

size_t AST_lst_len(AST_lst *lst) {
    int num_fields = 0;
    while (lst) {
	num_fields += 1;
	lst = lst->next;
    }
    return num_fields;
}

