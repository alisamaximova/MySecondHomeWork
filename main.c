#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

int main(void) {
	system("chcp 1251");
	system("cls");
	
	int n; // Number of vertices
	int i, j, p; // Counters
	int **gr; // Pointer to pointer to string of elements
	int t;
	bool r = true;
	int pos, e = 0;
	
	printf("Enter the number of vertices in the graph n: ");
	scanf("%d", &n); // Enter the number of vertices/dimension of the adjacency matri
	gr = (int**) malloc(n * sizeof(int*)); // Allocating memory for pointers to lines
	for (i = 0; i < n; i++) { // Loop through the lines
		gr[i] = (int*) malloc(n * sizeof(int)); // Allocating memory for strings
		printf("Enter the rate table: ");
		for (j = 0; j < n; j++) { // Cycle by column
			scanf("%d", &t);
				gr[i][j] = (t);
		}
	}
	
	printf("The table of the preset graph reads as follows: ");
	printf("\n"); // Going to a new line
	for (i = 0;i < n; i++) { // Measurement output
		for (j = 0; j < n; j++) {
			printf("%5d", gr[i][j]); // 5 Space for single power unit
		}
		printf("\n"); // Going to a new line
	}
	
	FILE* file = fopen("./graph.gv", "w+b"); // Create a .gv file for writing and saving a graph
	fputs("graph MySecondHomeWork {\n", file); // Writing the first line in the file
	for (i = 0;i < n; i++) 
		for (j = i; j < n; j++)
			if (gr[i][j] == 1) // If we are entering the matrix of the unit
							   //(i.e. there is a link between the top)
				fprintf(file, "\t%d -- %d;\n", i+1, j+1); // We write down the link in the created file
														  // "\ t" - horizontal tabulation, call right to write the code in the file
	fputs("}", file); // End of the code
	fclose(file); // Closing a file
	system("dot -Tpng graph.gv -o graph.png"); // Creating a graphic visualization using a .gv file
	
	p = pos;
	bool* ch = (bool*) calloc(n, sizeof(bool)); // We create an index on the mass for checking the cycle of the graph
	
	for (i = 0; i < n - 1; ++i) {
		ch[p] = true; // The top of the line is marked
		for (j = 0; j < n; ++j) { // Cycle by line
			if ((gr[i][j] == true) && (ch[j] == false)) {
				p = j;
				break;
			}
		}
		if (j == n) // If the counter j is the correct mass length / number of points
			r = false; // The r variable takes on the value "false"
	}
	if (gr[p][pos] == false) 
		r = false;
	
	for (i = 0; i < n; ++i) {
		for (j = i; j < n ; ++j)
			if (gr[i][j] == true)
				++e;
	}
	if (e != n) // If e is not equal to the number of vertices, then
		r = false; // The r variable takes on the value "false"
	
	if (r == true) // If r is true, then the graph is a simple cycle
		printf("The graph is a simple cycle");
	else 
		printf("The graph is not a simple cycle"); // Otherwise, a message is displayed stating that the graph is not a simple cycle
	
	for (i = 0; i < n; i++) // Clearing memory, looping through the lines
		free(gr[i]); // Freeing memory for a string
	free(gr);
	getchar();	
	return 0;
}
