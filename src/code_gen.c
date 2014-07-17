#include "code_gen.h"
#include "parser.h"

/** A counter to prevent the issuance of duplicate labels. */
unsigned label_count = 0;
/** True iff the data segment has already been partially printed. */
int data_seg_opened = 0;
/** True iff the text segment has already been partially printed. */
int text_seg_opened = 0;


/*
 * It is a decision to make $a0 the key register
 */

//NEED TO DETERMINE ARROW AT RUNTIME
void emit_strings() {
    /* TODO: Implement me. */
	string_struct *current = string_list;
	while(current != NULL){
		printf("%s:\t.asciiz %s", current->name, current->string_value); //may need to modify for scope and reassignment issues
		printf("\n");
	}

	//TODO: HOW to store strings in MIPS
}

void push(){
	printf("addi $sp, $sp, -4")
	printf("sw $a0, 0($sp)\n");
}

void pop(int regstr){
	printf("lw $t%d, 0($sp)\n", regstr);
	printf("addi $sp, $sp, 4\n");
}

void cgen_simple(AST* tree){
	node_type type = tree->type;
	char *check;
	//load bottom stack pointer into $t0
	//load top stack pointer into $t1
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

void cgen(AST* tree){
	//things to be evaluated beFore recursion
	//if, while, function, for, arrow,assign?
	node_type type = tree->type;
	int current_count;
	switch(type){

	case(node_AND):
		current_count = label_count ++;
		//evaluate the first operand
		cgen(tree->children->node);
		//if return value is None, jump to end
		printf("beq $a0, $0, end.%d\n", current_count);
		push();
		//evaluate the second operand
		cgen(tree->children->next->node);
		//if return value is None, jump to end
		//End(counter)
		printf("end.%d: \n", current_count);

		printf("end.%d")
		return;
	case(node_OR):
		current_count = label_count ++;
		//evaluate the first operand
		cgen(tree->children->node);
		//if return value is True, jump to end
		printf("bne $a0, $0, end.%d\n", current_count);
		push();
		//evaluate the second operand
		cgen(tree->children->next->node);
		//if return value is True, jump to end
		printf("bne $a0, $0, end.%d\n", current_count);
		//End(counter)
		break;
	case(node_IF):
		current_count = label_count ++;
		//evaluate the first operand
		cgen(tree->children->node);
		//evaluate the first operand
		//bne something something
		printf("beq $a0, $0, if_false$%d\n", current_count);
		printf("if_true$%d: \n", current_count);
		//True segment right after
		cgen(tree->children->next->node);
		//jump to end
		printf("j if_end$%d\n", current_count);
		//make a label for the first operand as _____ False.(counter)
		printf("if_false$%d:\n", current_count);
		cgen(tree->children->next->next->node);
		printf("if_end$%d: \n", current_count);
		//End.counter
		break;
	case(node_WHILE):
		cgen(tree->children->node);

		//evaluate first operand
		//store first operand somewhere
		//beq 0, jump to end
		//loop.counter body
		//evaluate second operand
		//jump back to beginning of while loop
		//RETURN NONE
			break;
	case(node_FUNCTION):
		return;
	case(node_FOR):
		//evaluate Init
		cgen(tree->children->node);
		//Evaluate Predicate
		cgen(tree->children->next->node);
		//if condition meet, jump to end
		//Evaluate Body
		//Evaluate Increment, loop to Predicate
		//RETURN NONE
		//end
		break;
	case(node_ARROW):
		//if next value is struct
		//evaluate the struct
		//evaluate second operand
		//store correct word into top of stack
			break;
	default:
		break;
	}



	AST_lst *current_child = tree->children;
	while(current_child != NULL){
		cgen(current_child->node);
		printf("move $t0,")
		pop(0);
		current_child = current_child->next;
	}
	switch(type){
	case(node_NONE):
		break;

	/*==PRINT CASES==*/
	case(node_S_PRINT):
		//!!==Assumes that $a0 contains the integer to print ==!!
		printf("li $v0, 4\n");
		printf("syscall\n");
		break;
	case(node_I_PRINT):
		//!!==Assumes that $a0 contains the integer to print ==!!
		printf("li $v0, 1\n");
		printf("syscall\n");
		break;
	case(node_READ_INT):
		printf("li $v0, 5\n");
		printf("syscall\n");
		printf("move $a0 $v0");
		break;

	/*==DATA CASES==*/
	case(node_INT):
		//load int into accumulator register
		printf("li $a0, %s\n", tree->val);
		break;
	case(node_STRING):
		//loads string address into accumulator
		//FIX
		break;
	case(node_VAR):
		//load whatever is inside the
		break;
	case(node_CALL):
		//jump to function label
		break;
	/*==BASIC OPERATION CASES==*/
	case(node_PLUS):
	case(node_MINUS):
	case(node_MUL):
	case(node_DIV):
	case(node_LT):
		cgen_simple(tree);
		break;
	case(node_EQ):
		//pop t0
		//pop t1
		//beq $t0 $t1 item
		//store $t0 as 0
		//item: store $t0 as 1
		//push onto stack
		break;
	case(node_SEQ)://do nothing because should have already evaluated in above
			//need to make sure return value is right
		break;
	case(node_STRUCT):
		//because other operands needed to have been evaluated
		//Store amount into the stack, return sp address
		//check for how many words needed
		//
		break;
	case(node_ARROW):
		//pop first item (counter)
		//pop second item (struct address)
		//return address on
		break;
	case(node_ASSIGN):
		//TODO
		//if string or variable
		//allocate space, and then
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
			if(map->buckets[i]->pairs->val){
				printf("%s:    .space  %d\n", map->buckets[i]->pairs->key, 4);
			}
		}
	}


}

void emit_main(AST *ast) {
	printf("");
    /* TODO: Implement me. */
}

void emit_exit() {
    printf("    li $v0 10\n");
    printf("    syscall\n");
}

/*
 * Restores the registers of the program
 */
void store_regs(){
	printf("addi $sp, $sp, -100"); //stores everything
	for(int x = 2; x < 26; x ++){
		int y = x - 2;
		printf("lw $%d, %d($sp)", y, y*4);
		printf("\n");
	}
}

void restore_regs(){
	for(int x = 2; x < 26; x ++){
		int y = x - 2;
		printf("sw $%d, %d($sp)", y, y*4);
		printf("\n");
	}
	printf("addi $sp, $sp, 100"); //restores everything

}


/*
 * The frame pointer will point to the beginning of the frame
 *
 */
void emit_functions(AST *ast) {
    /* TODO: Implement me. */
	int stack_push = 0;
	store_regs();
	if(ast->type == node_FUNCTION){
		printf("%s:\t", ast->val);
		//allocate memory according to stack size
		printf("move $fp $sp\n");
		printf("addi $sp, $sp, -%d", smap_get(stack_sizes, ast->children->node->val));
		printf("\n");
		printf("sw $ra, %d($sp)", stack_push);
		//generate a hashmap to store all parameters and local assignments
		//remove at the end of the function
	}else{

	}
	restore_regs();
}
