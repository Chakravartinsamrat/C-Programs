#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

void inorder(int tree[], int index, int n) { 
	if (index < n && tree[index] != -1) { 
		inorder(tree, 2 * index + 1, n); 
 		printf("%d ", tree[index]); 
 		inorder(tree, 2 * index + 2, n); 
 	} 
}
 
void preorder(int tree[], int index, int n) { 
 	if (index < n && tree[index] != -1) { 
 		printf("%d ", tree[index]); 
 		preorder(tree, 2 * index + 1, n); 
 		preorder(tree, 2 * index + 2, n); 
 	} 
}
 
void postorder(int tree[], int index, int n) { 
 	if (index < n && tree[index] != -1) { 
 		postorder(tree, 2 * index + 1, n); 
 		postorder(tree, 2 * index + 2, n); 
 		printf("%d ", tree[index]); 
 	} 
} 

void levelOrder(int tree[], int n) { 
 		for (int i = 0; i < n; i++) { 
 		if (tree[i] != -1) { 
 			printf("%d ", tree[i]); 
 		} 
	} 
} 

int main() { 
	int n; 
 	printf("Enter the number of elements: "); 
 	scanf("%d", &n); 
 	int *tree = (int *)malloc(n * sizeof(int)); 
 	memset(tree, -1, n*sizeof(tree[0])); 
 	for (int i = 0; i < n; i++) { 
 		printf("Enter element %d: ", i + 1); 
 		scanf("%d", &tree[i]); 
 	} 
 	int choice; 
 	do { 
 		printf("\nMenu:\n"); 
 		printf("1. Inorder Traversal\n"); 
 		printf("2. Preorder Traversal\n"); 
 		printf("3. Postorder Traversal\n"); 
 		printf("4. Level order Traversal\n"); 
 		printf("5. Exit\n"); 
	 	printf("Enter your choice: "); 
 		scanf("%d", &choice); 
 		switch (choice) { 
 			case 1:
				printf("Inorder Traversal: "); 
 				inorder(tree, 0, n); 
 				printf("\n"); 
 				break; 
		 	case 2: 
				printf("Preorder Traversal: "); 
				preorder(tree, 0, n); 
		 		printf("\n"); 
		 		break; 
		 	case 3: 
		 		printf("Postorder Traversal: "); 
		 		postorder(tree, 0, n); 
		 		printf("\n"); 
		 		break; 
		 	case 4: 
		 		printf("Level Order Traversal: "); 
		 		levelOrder(tree, n); 
		 		printf("\n"); 
		 		break; 
		 	case 5: 
		 		printf("Exiting...\n"); 
		 		break; 
		 	default: 
		 			printf("Invalid choice!\n"); 
		} 
	} while (choice != 5); 
	free(tree); 
	return 0; 
}