#ifndef PARSER_H
#define PARSER_H

#include "util/smap.h"
#include "util/util.h"
#include "lexer.h"


typedef enum node_type {node_INT /* integer literal */,
			node_STRING /* string literal*/,

			node_VAR /* Name of a variable or a function. */,
			node_CALL /* A call to a function */,

			/* The different built-in utilities. */
			node_AND, //2
			node_OR,  //2
			node_PLUS,  //2
			node_MINUS,  //2
			node_MUL,   //2
			node_DIV,  //2
			node_LT,  //2
			node_EQ,  //2
			node_FUNCTION,  //1
			node_STRUCT,  //keep
			node_ARROW,  //2
			node_ASSIGN,  //2
			node_IF,    //3
			node_WHILE,  //2
			node_FOR,   //4
			node_SEQ,   //keeps going
			node_I_PRINT,     //1
			node_S_PRINT,     //1
			node_READ_INT      //none
			} node_type;

typedef struct AST AST;
typedef struct AST_lst AST_lst;
typedef struct key_type key_type_t;

typedef struct string_node string_struct;

struct string_node{
	char *string_value;
	char *name;
	string_struct *next;
};

struct key_type {
	char *keywords;
	node_type enums;
	int args;
};

struct map_list{
	char *string_value;
	char *name;
	string_struct *next;
};


struct AST {
    node_type type; /* The type of  */
    char *val; /* The source text which spawned this node. */ 
    AST_lst *children; /* A list of all of the children of this node*/
    AST_lst *last_child; /* A minor kludge to avoid O(n) insertion times. */
};

struct AST_lst {
    AST *node;
    AST_lst *next;
};

/** Initializes all global data structures that the parser needs. */
void parse_init();

/** Destroys any global data structures that the parser needed or created. */
void parse_close();

/** Builds an abstract syntax tree from the tokens supplied by LEX. */
AST *build_ast(lexer *lex);

/** Frees the memory allocated to the abstract syntax tree pointed at
 *  by PTR. */
void free_ast(AST *ptr);

/** checks that each node of PTR has an appropriate number of children for its type. */
void check_tree_shape(AST *ptr);

/** Gathers all of the declarations made in AST, and checks for use-before-assign
 *  errors. Assumes that AST is a subtree of the tree definition of ENV_FUNC.
 *  IS_TOP_LEVEL should only be set in the event that AST is not a subtree of any other
 *  abstract syntax tree. */
void gather_decls(AST *ast, char *env_func, int is_top_level);

/** Returns the node_type corresponding to the string STR, or -1 if no node_type 
 *  corresponds. */
node_type lookup_keyword_enum(char *str);


void add_function_args(AST *ast);

void add_function_decl(AST *ast);

void store_string(char *variable, char *string);

int lookup_arg(node_type type);

node_type lookup_keyword_enum(char *str);

int lookup_function_args(char *fn);


/** Returns the number of nodes in LST. */
size_t AST_lst_len(AST_lst *lst);



/** Holds all of the declarations made throughout the program. */
extern smap *decls;

/** Maps from function names to the size of their stack frames. */
extern smap *stack_sizes;

/** Maps from function names to the number of arguments they expect. */
extern smap *num_args;
/** Holds a reference to each of the different string literals appearing throughout 
 *  the program. */
extern smap *strings;

extern smap *keyword_str_to_enum;


extern string_struct *string_list;

extern string_struct *current_string;

#endif
