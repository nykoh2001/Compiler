#include "Parser.c"

FILE *astFile;

void printNode(Node* pt, int indent);
void printTree(Node* pt, int indent);

void printTree(Node* pt, int indent)
{
	Node* p = pt;
	while (p != NULL) {
		printNode(p, indent);
		if (p->noderep == nonterm) printTree(p->son, indent + 5);
		p = p->brother;
	}
}

void printNode(Node* pt, int indent)
{
	int i;

	for (i = 1; i <= indent; i++) fprintf(astFile, " ");
	if (pt->noderep == terminal) {
		if (pt->token.number == tident)
			fprintf(astFile, " Terminal: %s", pt->token.value.id);
		else if (pt->token.number == tnumber)
			fprintf(astFile, " Terminal: %d", pt->token.value.num);
	}
	else { // nonterminal node
		i = (int)(pt->token.number);
		fprintf(astFile, " Nonterminal: %s", nodeName[i]);
	}
	fprintf(astFile, "\n");
}

int main (int argc, char* args[]) {
	astFile = fopen("astFile.txt", "w");
	char* sourceFilePath = args[1];
	Node * AST_ROOT =  parser(sourceFilePath);
	printTree(AST_ROOT, 4);
	fclose(astFile);
}
