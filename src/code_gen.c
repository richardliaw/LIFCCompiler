#include "code_gen.h"
#include "parser.h"
#include <stdlib.h>

/** A counter to prevent the issuance of duplicate labels. */
unsigned label_count = 0;
/** True iff the data segment has already been partially printed. */
int data_seg_opened = 0;
/** True iff the text segment has already been partially printed. */
int text_seg_opened = 0;

char *env = "";
/*
 * It is a decision to make $a0 the key register
 */

//NEED TO DETERMINE ARROW AT RUNTIME
void emit_strings() {
	if(data_seg_opened == 0){
		printf("\t .data\n");
		data_seg_opened = 1;
	}
    smap_emit_strings(strings);
    printf("\n");

//	if(node_TYPE )
}

void return_None(){
	printf("\t add $a0, $0, $0  #return_None\n");
}

void push(){
	printf("\taddi $sp, $sp, -4 #push\n");
	printf("\tsw $a0, 0($sp)\n\n");
}

void pop(int regstr){
	printf("\tlw $t%d, 0($sp) #pop\n", regstr);
	printf("\taddiu $sp, $sp, 4\n\n");
}

void cgen_simple(AST* tree){
	node_type type = tree->type;
	char check[10];
	pop(0);
	pop(1);
	switch(type){
	case(node_PLUS):
		strcpy(check, "add");
		break;
	case(node_MINUS):
		strcpy(check,"sub");
		break;
	case(node_LT):
		strcpy(check,"slt");
		break;
	case(node_MUL):
		strcpy(check,"mul");
		break;
	case(node_DIV):
		printf("\tdiv $t%d, $t%d\n", 1, 0);
		printf("\tmflo $a0\n");
		return;
	default:
		fprintf(stderr, "Should not have reached this step for this Nodetype");
		exit(1);
		break;
	}
	printf("\t %s $a0, $t%d, $t%d\n", check, 1, 0);
}

void cgen_pre_eval(AST *tree, int current_count){
	node_type type = tree->type;
	switch(type){
		case(node_AND):
			cgen(tree->children->node);	//evaluate the first operand
			printf("beq $a0, $0, end$%d\n", current_count);	//if return value is None, jump to end
			push();
			cgen(tree->children->next->node); //evaluate the second operand
			printf("\t end$%d: \n", current_count); //End(counter)
			break;

		case(node_OR):
			cgen(tree->children->node);

			printf("\t bne $a0, $0, end$%d\n", current_count);
			push();
			cgen(tree->children->next->node);
			printf("\t end$%d: \n", current_count);
			break;
		case(node_IF):
			//evaluate the first operand
			cgen(tree->children->node);
			printf("\t beq $a0, $0, if_false$%d\n", current_count);

			printf("if_true$%d: \n", current_count);
			cgen(tree->children->next->node);
			printf("\t j if_end$%d\n", current_count);

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
			printf("\t j while$%d", current_count);

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
			printf("\tbeq $a0, $0, end$%d\n",current_count);
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

	char variable_check[strlen(tree->val) + strlen(env) + 2]; //check for
	char global_check[strlen(tree->val) + 2];
	switch(type){
		case(node_NONE):
			return_None();
			break;

		/*==============PRINT CASES================*/
		case(node_S_PRINT):
			pop(0);
			printf("\t move $a0, $t0\n");
			printf("\tli $v0, 4\n");
			printf("\tsyscall\n");
			break;
		case(node_I_PRINT):
			pop(0);
			printf("\t move $a0, $t0\n");
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
			printf("\tla $a0, str$%d\n", smap_get(strings, tree->val));
			break;
		case(node_VAR):
			strcpy(variable_check, tree->val);
			strcat(variable_check, "$");
			strcat(variable_check, env);

			strcpy(global_check, "_");
			strcat(global_check, tree->val);
			if(smap_get(decls, variable_check) != -1){
				printf("\tlw $a0, %d($fp)\n", smap_get(decls, variable_check)*4);
			}else if(smap_get(decls, tree->val) == -1){
				fprintf(stderr, "There is a problem with assigning this variable");
				exit(1);
			}else{
				printf("\tlw $a0, %s\n", global_check);
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
			printf("\t j equal_end$%d\n", current_count);
			printf("equal_true$%d: \n", current_count);
			printf("\t li $a0 1\n");
			printf("equal_end$%d: \n", current_count);
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
			printf("\t addiu $t2, $0, 4\n");
			printf("\t mul $t0, $t2\n");
			printf("\t mflo $t2\n");
			printf("\t add $a0, $t1, $t0\n");
			break;
		case(node_ASSIGN):

			pop(0);

			strcpy(variable_check, tree->children->node->val);
			strcat(variable_check, "$");
			strcat(variable_check, env);

			strcpy(global_check, "_");
			strcat(global_check, tree->children->node->val);
			if(smap_get(decls, variable_check) != -1){
				printf("\t sw $t0, %d($fp)\n", smap_get(decls, variable_check) *4);
			}else if(smap_get(decls, tree->children->node->val) == -1){
					fprintf(stderr, "There is a problem with ASSIGNING this variable");
					exit(1);
			}else{
				printf("\t sw $t0, %s\n", global_check);
			}
			printf("\tadd $a0, $0, $t0\n");
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
	smap_emit_statics(decls);


}

void emit_main(AST *ast) {
	//initialize the stackframe
	if(text_seg_opened == 0){
		printf("\n");
		printf("\t.text\n");
		printf("main: \n");
		text_seg_opened = 1;
	}
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

	cgen(ast->last_child->node);

	printf("\t move $sp, $fp\n");
	printf("\t addiu $sp, $sp, -%d\n", smap_get(stack_sizes, ast->children->node->val));
	//	restore_regs();
	printf("\t lw $ra, 0($sp)\n");
	printf("\t jr $ra\n");

	printf("\n");
}
