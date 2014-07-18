#include "code_gen.h"
#include "parser.h"

/** A counter to prevent the issuance of duplicate labels. */
unsigned label_count = 0;
/** True iff the data segment has already been partially printed. */
int data_seg_opened = 0;
/** True iff the text segment has already been partially printed. */
int text_seg_opened = 0;

char *env = 0;
/*
 * It is a decision to make $a0 the key register
 */

//NEED TO DETERMINE ARROW AT RUNTIME
void emit_strings() {
    /* TODO: Implement me. */
	smap *map = strings;
    for (size_t i = 0; i < map->num_buckets; i += 1) {
    	for (size_t j = 0; j < map->buckets[i].num_pairs; j += 1) {
    		if(map->buckets[i] != NULL){
    			printf("str$%d: .asciiz \"%s\"\n", map->buckets[i].pairs[j].val, map->buckets[i].pairs[j].key);
    		}
    	}
    }
}

void return_None(){
	printf("addiu $a0, $0, $0\n");
}

void push(){
	printf("addiu $sp, $sp, -4\n");
	printf("sw $a0, 0($sp)\n");
}

void pop(int regstr){
	printf("lw $t%d, 0($sp)\n", regstr);
	printf("addiu $sp, $sp, 4\n");
}

void cgen_simple(AST* tree){
	node_type type = tree->type;
	char *check;
	pop(0);
	pop(1);
	switch(type){
	case(node_PLUS):
		check = "add";
		break;
	case(node_MINUS):
		check = "sub";
		break;
	case(node_LT):
		check = "slt";
		break;
	case(node_MUL):
		printf("mul $t%d, $t%d\n", 0, 1);
		printf("mflo $a0\n");
		return;
	case(node_DIV):
		printf("div $t%d, $t%d\n", 0, 1);
		printf("mflo $a0\n");
		return;
	default:
		break;
	}
	printf("%s $a0, $t%d, $t%d", check, 0, 1);
}

void cgen_pre_eval(AST *tree, int current_count){
	node_type type = tree->type;
	switch(type){
		case(node_AND):
			cgen(tree->children->node);	//evaluate the first operand
			printf("beq $a0, $0, end$%d\n", current_count);	//if return value is None, jump to end
			push();
			cgen(tree->children->next->node); //evaluate the second operand
			printf("end$%d: \n", current_count); //End(counter)
			break;

		case(node_OR):
			cgen(tree->children->node);

			printf("bne $a0, $0, end$%d\n", current_count);
			push();
			cgen(tree->children->next->node);
			printf("end$%d: \n", current_count);
			break;
		case(node_IF):
			//evaluate the first operand
			cgen(tree->children->node);
			printf("beq $a0, $0, if_false$%d\n", current_count);

			printf("if_true$%d: \n", current_count);
			cgen(tree->children->next->node);
			printf("j if_end$%d\n", current_count);

			printf("if_false$%d: \n", current_count);
			cgen(tree->children->next->next->node);

			printf("if_end$%d: \n", current_count);
			break;

		case(node_WHILE):
			//evaluate first operand - predicate
			printf("while$%d: \n", current_count);
			cgen(tree->children->node);
			printf("\tbeq $a0, $0, while_end$%d\n", current_count);


			cgen(tree->children->next->node);
			printf("j while$%d", current_count);

			printf("while_end$%d: \n", current_count);
			return_None();
			break;
		case(node_FUNCTION):
			return_None();
			return;
		case(node_FOR):
			//evaluate Init
			cgen(tree->children->node);
			//Evaluate Predicate
			cgen(tree->children->next->node);
			printf("\tbeq $a0, $0, end$%d\n",current_count)
			//if condition meet, jump to end
			//Evaluate Body
			cgen(tree->children->next->next->node);
			//Evaluate Increment, loop to Predicate
			return_None();
			//end
			printf("end$%d: \n", current_count);
			return_None();
			break;
		default:
			break;
		}

}

void cgen(AST* tree){
	//things to be evaluated beFore recursion
	//if, while, function, for, arrow,assign?
	node_type type = tree->type;
	int current_count = label_count ++;

	if(type == node_AND || type == node_OR || type == node_IF || type == node_WHILE ||
			type == node_FOR || type == node_FUNCTION){
		cgen_pre_eval(tree, current_count);
		return;
	}

	AST_lst *current_child = tree->children;
	while(current_child != NULL){
		cgen(current_child->node);
		push();
		current_child = current_child->next;
	}

	switch(type){
		case(node_NONE):
			return_None();
			break;

		/*==============PRINT CASES================*/
		case(node_S_PRINT):
			printf("\tli $v0, 4\n");
			printf("\tsyscall\n");
			break;
		case(node_I_PRINT):
			printf("\tli $v0, 1\n");
			printf("\tsyscall\n");
			break;
		case(node_READ_INT):
			printf("\tli $v0, 5\n");
			printf("\tsyscall\n");
			printf("\tmove $a0 $v0");
			break;

		/*================DATA CASES================*/
		case(node_INT):
			printf("\tli $a0, %s\n", tree->val);
			break;
		case(node_STRING):
			//loads string address into accumulator
			printf("\tla $a0, str$%d\n", smap_get(tree->val));
			break;
		case(node_VAR):
			int len = strlen(tree->val);
			len += strlen(env);
			char check[len + 2];
			strcpy(check, tree->val);
			strcat(check, "$");
			strcat(check, env);
			if(smap_get(decls, check) != -1){
				printf("\tlw $a0, %d($fp)\n", smap_get(decls, check)*4);
			}else if(smap_get(decls, tree->val) == -1){
				fprintf("There is a problem with assigning this variable");
				exit(1);
			}else{
				printf("\tlw $a0, _%s\n", tree->val);
			}
			break;
		case(node_CALL):
			printf("\tjal %s\n", tree->val);
			break;


		/*================BASIC OPERATION CASES==================*/
		case(node_PLUS):
		case(node_MINUS):
		case(node_MUL):
		case(node_DIV):
		case(node_LT):
			cgen_simple(tree);
			break;


		case(node_EQ):
			//pop t0
			pop(0);
			//pop t1
			pop(1);
			printf("\t beq $t0, $t1, equal_true$%d\n", current_count);
			printf("\t li $a0 0\n");
			printf("\t j equal_end$%d\n");
			printf("equal_true$%d: \n", current_count);
			printf("\t li $a0 1\n");
			printf("equal_end$%d: \n");
			break;
		case(node_STRUCT):
			//need to return POINTER to struct
			//TODO: FIX PARSER TO MOVE FP ENOUGH

			//because other operands needed to have been evaluated
			//Store amount into the stack, return sp address
			//check for how many words needed
			//
			break;
		case(node_ARROW):
			//pop first item (counter)
			pop(0);
			//pop second item (struct address)
			pop(1);
			printf("\t addiu $t2, $0, 4\n")
			printf("\t mul $t0, $t2\n");
			printf("\t mflo $t2\n");
			printf("\t add $a0, $t1, $t0\n");
			break;
		case(node_ASSIGN):

			pop(0);
			int len = strlen(tree->val);
			len += strlen(env);
			char check[len + 2];
			strcpy(check, tree->val);
			strcat(check, "$");
			strcat(check, env);

			if(smap_get(decls, check) != -1){
				printf("\t sw $t0, %d($fp)\n", smap_get(decls, check) *4);
			}else if(smap_get(decls, tree->val) == -1){
					fprintf("There is a problem with assigning this variable");
					exit(1);
			}else{
				printf("\t sw $t0, _%s\n", tree->val);
			}
			printf("\t add $a0, $0, $t0\n");
			break;

		case(node_SEQ):
			break;
		default:
			break;
	}
}

void emit_static_memory() {
    /* TODO: Implement me. */
	//TODO: HOW to store strings in MIPS
	//TODO: Check all top-level AST for assignments and function declarations
	//loop through all static variables in hashmap
	//Hash memory to a number - corresponding to the line emitted
	smap *map = decls;
	for (size_t i = 0; i < map->num_buckets; i += 1) {
		for (size_t j = 0; j < map->buckets[i].num_pairs; j += 1) {
			if(map->buckets[i]->pairs->val == -2){
				printf("_%s:    .space  %d\n", map->buckets[i]->pairs->key, 4);
			}
		}
	}


	printf("\n");
	printf("\t \t .text\n");
	printf("main: \n");


}

void emit_main(AST *ast) {
	//initialize the stackframe
	if(ast->type == node_FUNCTION){
		return;
	}
	cgen(ast);
	printf("\n");
    /* TODO: Implement me. */
}

void emit_exit() {
    printf("    li $v0 10\n");
    printf("    syscall\n");
}

/*
 * Restores the registers of the program
 */
//void store_regs(){
//	printf("addiu $sp, $sp, -100"); //stores everything
//	for(int x = 2; x < 26; x ++){
//		int y = x - 2;
//		printf("lw $%d, %d($sp)\n", y, y*4);
//		printf("\n");
//	}
//}
//
//void restore_regs(){
//	for(int x = 2; x < 26; x ++){
//		int y = x - 2;
//		printf("sw $%d, %d($sp)", y, y*4);
//		printf("\n");
//	}
//	printf("addiu $sp, $sp, 100"); //restores everything

}


/*
 * The frame pointer will point to the beginning of the frame
 *
 */
void emit_functions(AST *ast) {
    /* TODO: Implement me. */
//	store_regs();
	if(ast->type != node_FUNCTION ){
		return;
	}
	env = ast->children->node->val;
	printf("%s:\n", ast->val);
	printf("\t addiu $sp, $sp, -%d\n", smap_get(stack_sizes, ast->children->node->val));
	printf("\t move $fp, $sp\n");
	printf("\t sw $ra, 0($fp)\n");

	cgen(ast->last_child);

	printf("\t move $sp, $fp\n");
	printf("\t addiu $sp, $sp, -%d\n", smap_get(stack_sizes, ast->children->node->val));
	//	restore_regs();
	printf("\t lw $ra, 0($sp)\n");
	printf("\t jr $ra\n");

	printf("\n");
}
