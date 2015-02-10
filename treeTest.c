#include "expr_assert.h"
#include "tree.h"
#define say(test_description) int say = printf("**  Description->%s\n\n", test_description)
#define everything void
typedef void (*logger)(char*);

struct con{
	logger log;
};

void log(char* desc){
	printf("%s\n",desc);
}

struct con console = {&log};



void cout(char * d){
	console.log(d);
}
struct system{
	struct{
		void(*println)(char*);
	} out;
};

struct system System = {{cout}};



void test_add_001(){
	assert(add(1,1)==2);
}		

void test_createTreeNode_001() {
	say("create treeNode creates a tree node with given data");
}