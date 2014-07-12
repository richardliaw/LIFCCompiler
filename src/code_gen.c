#include "code_gen.h"
#include "parser.h"

/** A counter to prevent the issuance of duplicate labels. */
unsigned label_count = 0;
/** True iff the data segment has already been partially printed. */
int data_seg_opened = 0;
/** True iff the text segment has already been partially printed. */
int text_seg_opened = 0;

void emit_strings() {
    /* TODO: Implement me. */
	string_struct *current = string_list;
	while(current != NULL){
		printf("%s:     .asciiz %s", current->name, current->string_value);
		printf("\n");
	}

	//TODO: HOW to store strings in MIPS


}

void translate_to_instruction(AST* tree){

}

void emit_static_memory() {
    /* TODO: Implement me. */
	//TODO: HOW to store strings in MIPS
	//TODO: Check all top-level AST for assignments and function declarations
	//loop through all static variables in hashmap
	//Hash memory to a number - corresponding to the line emitted

}

void emit_main(AST *ast) {
    /* TODO: Implement me. */
}

void emit_exit() {
    printf("    li $v0 10\n");
    printf("    syscall\n");
}

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

void emit_functions(AST *ast) {
    /* TODO: Implement me. */
	store_regs();
	if(ast->type == node_FUNCTION){
		printf("%s:\t", ast->val);

	}else{

	}
	restore_regs();
}
