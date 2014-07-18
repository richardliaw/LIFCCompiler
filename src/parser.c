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
		"None",
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
		node_NONE,
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


unsigned int str_counter = 0;
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
	{  "None",			node_NONE,			0},
	{  "lt",			node_LT, 			2 },
	{  "eq",			node_EQ, 			2 },
	{  "function",		node_FUNCTION, 	2 },
	{  "struct",		node_STRUCT, 		2 },
	{  "arrow",			node_ARROW, 		2 },
	{  "assign",		node_ASSIGN, 		2 },
	{  "if",			node_IF, 			3 },
	{  "while",			node_WHILE, 		2 },
	{  "for",			node_FOR, 		4 },
	{  "sequence",		node_SEQ, 		-2 },
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
	char *current = lex->buffer; //obtain next token

	level->val = safe_calloc(strlen(current)*sizeof(char) + 1);
	strcpy(level->val, lex->buffer);

	switch(lex->type){
	case(token_SENTINEL):
		break;
	case(token_OPEN_PAREN):
		//if open-paren, return build_ast to take next token
		//check first token and all the rest go into children
		read_token(lex);
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
		read_token(lex);
		return (level);
	case(token_CLOSE_PAREN):
		return NULL;
	case(token_KEYWORD):
		level->type = lookup_keyword_enum(current); //if keyword doesn't match anything
		if((int)level->type == -1){
			fprintf(stderr, "This is a problem");
			exit(1);
		}
		break;
	case(token_INT):
		level->type = node_INT;
		break;
	case(token_STRING):
		level->type = node_STRING;
		break;
	case(token_END):
		//Making assumption that there is no way the parser will see a EOF
		fprintf(stderr, "This is a problem - Incorrect Usage of Parentheses");
		exit(1);

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
	read_token(lex);
    return (level);

}

void add_function_args(AST *ast){
	if(ast->type != node_FUNCTION){
		fprintf(stderr, "Miscall");
		exit(1);
	}else{
		AST *declarations_tree = ast->children->node;
		char *name = declarations_tree->val;
		int num_of_args = AST_lst_len(declarations_tree->children);
		if(smap_get(num_args, name) != -1){
			fprintf(stderr, "This function \"%s\" has been declared multiple times", name);
			exit(1);
		}
		smap_put(num_args, name, num_of_args);
	}
}

void free_ast (AST *ptr) {
    /* TODO: not DONE - NEED TO FREE STRINGS and STRING SCOPE KEYS */
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
	AST_lst *current = ptr->children;
	int arg_count = 0;
	switch(check){

	case(node_INT):
	case(node_STRING):
	case(node_VAR):
		arg_count = 0;
		break;
	case(node_CALL):
		arg_count = lookup_function_args(ptr->val);
		break;
	case(node_SEQ):
	case(node_STRUCT):
		current = ptr->children;
		if(ptr->children == NULL){
			fprintf(stderr, "Structs must contain at least one field.");
			exit(1);
		}
		while(current != NULL){
			check_tree_shape(current->node);
			current = current->next;
		}
		return;
	default:
		if(check == node_ARROW){
			if(current->node->type != node_VAR && current->node->type != node_STRUCT){
				fprintf(stderr, "Arrow must point to a Struct");
				exit(1);
			}
		}
		arg_count = lookup_arg(check);
		break;
	}

	if(AST_lst_len(ptr->children) != arg_count){
		fprintf(stderr, "This is a problem - Inconsistency between arg_count and expected for \"%s\"", ptr->val);
		exit(1);
	}

	for(int x = 0; x < arg_count; x++){
		check_tree_shape(current->node);
		current = current->next;
	}

}


char * str_to_scope_key(char *str, char* env){
	char *newKey = safe_calloc(sizeof(char)*(strlen(str) + strlen(env) + 2));
	strcpy(newKey, str);
	strcat(newKey, "$");
	strcat(newKey, env);
	return (newKey);
}

void gather_decls(AST *ast, char *env, int is_top_level) {
    /* TODO: Implement me. */
    /* Hint: switch statements are pretty cool, and they work 
     *       brilliantly with enums. */

	node_type current_type = ast->type;
	char *current_string = ast->val;
	char *newKey = str_to_scope_key(current_string, env);

	AST_lst *child_list = ast->children;
	char *key; //first argument VALUE

	AST * value;
	char *new_env = env;

	switch(current_type){
	//Check for use before Assign - (function is already taken care of)
	case(node_VAR):
			//check for current enviro + stack
		if((smap_get(decls, newKey) == -1) && (smap_get(decls, current_string) == -1)){
			fprintf(stderr, "There is a usage before assignment for variable \"%s\"", current_string);
			exit(1);
		}
		free(newKey);
		break;
	//Count Stack Size for Function Frame -
	case(node_FUNCTION):
		return (gather_function_decls(ast, env, is_top_level));
	case(node_STRING):
		smap_put(strings, ast->val, str_counter);
		str_counter ++;
		break;
	//Generate Something for the Statics AND Locals
	case(node_ASSIGN):
		key = child_list->node->val;
		value = child_list->next->node;
		if(!is_top_level){
			smap_increment(stack_sizes, env, 1);//Increment Environment if not string
			if(value->type == node_STRUCT){
				smap_increment(stack_sizes, env, AST_lst_len(value->children));
			}
			smap_put(decls, str_to_scope_key(key, env), smap_get(stack_sizes, env));
		}
		else{
			smap_put(decls, key, -2);
		}
		//All Strings are statics
		break;
	//Default Case:
	default:
		break;
	}

	for(int x = AST_lst_len(child_list); x > 0; x --){
		gather_decls(child_list->node, new_env, 0);
		child_list = child_list->next;
	}
	//Check declarations recursively

}

void gather_function_decls(AST *ast, char *env, int is_top_level){
	if(ast->type != node_FUNCTION){
		fprintf(stderr, "Should not be calling this method on a non-function element");
		exit(1);
	}
	AST_lst *child_list = ast->children;

	AST *fn_decl_tree = child_list->node;
	char *new_env = fn_decl_tree->val;
	//For all subsequent gather declarations of children, env = function name
	//TODO: Store function declaration - first node on LEFT
	if(!is_top_level){
		fprintf(stderr, "Error when parsing \"%s\" - Functions must be on the top level", new_env);
		exit(1);
	}
	//One is stored just as return address space
	smap_put(stack_sizes, new_env, 1);
	//Increment by number of parameters
	AST_lst *parameters = fn_decl_tree->children;
	for(int x = lookup_function_args(new_env); x > 0; x --){
		smap_increment(stack_sizes, new_env, 1);
		smap_put(decls, str_to_scope_key(parameters->node->val, new_env), smap_get(stack_sizes, new_env));
		parameters = parameters->next;
	}
	printf("Added New Function \"%s\"\n", new_env);
	gather_decls(child_list->next->node, new_env, 0);
}

int lookup_arg(node_type type){
	if(type == 0){ //TODO: may be a problem
		fprintf(stderr, "There is some error with the input - no Type");
		exit(1);
	}
	int x = 0;
	key_type_t *current = &key_table[x];
	while(current->enums != 0){
		if(current->enums == type){
			return (current->args);
		}
		current = &key_table[++x];
	}
	return (-1);

}


node_type lookup_keyword_enum(char *str) {
    if (smap_get(keyword_str_to_enum, keywords[0]) == -1) {
	initialize_keyword_to_enum_mapping();

    }
    return (smap_get(keyword_str_to_enum, str));
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

