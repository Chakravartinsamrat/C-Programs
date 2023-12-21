#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct Route { 
 	char destIP[20]; 
 	char nextHop[20]; 
}Route; 

typedef struct Node { 
 	Route route; 
 	struct Node* left; 
 	struct Node* right; 
}Node; 

Node* createNode(Route route) { 
	Node* newNode = (Node*)malloc(sizeof(Node)); 
	if (newNode) { 
 		newNode->route = route; 
 		newNode->left = NULL; 
 		newNode->right = NULL; 
	} 
	return newNode; 
} 

Node* insert(Node* root, Route route) { 
 	if (root == NULL) 
 	return createNode(route); 
 	if (strcmp(route.destIP, root->route.destIP) < 0) 
 		root->left = insert(root->left, route); 
 	else 
		 root->right = insert(root->right, route); 
 	return root; 
} 

Node* findMin(Node* node) { 
	if (node == NULL) 
	return NULL; 
	while (node->left != NULL) 
 	node = node->left; 
 	return node; 
} 

Node* deleteNode(Node* root, char destIP[]) { 
	if (root == NULL) 
 		return root; 
 	if (strcmp(destIP, root->route.destIP) < 0) 
 		root->left = deleteNode(root->left, destIP); 
 	else if (strcmp(destIP, root->route.destIP) > 0) 
 		root->right = deleteNode(root->right, destIP); 
 	else { 
 		if (root->left == NULL) { 
 			Node* temp = root->right; 
 			free(root); 
 			return temp; 
 		} else if (root->right == NULL) { 
 			Node* temp = root->left; 
 			free(root); 
 			return temp; 
 		} 
 		Node* temp = findMin(root->right); 
 		root->route = temp->route; 
 		root->right = deleteNode(root->right, temp->route.destIP); 
 	} 
 	return root; 
}
 
char* lookup(Node* root, char destIP[]) { 
 	if (root == NULL) 
 		return "Route not found"; 
 	if (strcmp(destIP, root->route.destIP) == 0) 
 		return root->route.nextHop; 
	else if (strcmp(destIP, root->route.destIP) < 0) 
	 	return lookup(root->left, destIP); 
	else 
 		return lookup(root->right, destIP); 
} 

void freeTree(Node* root) { 
 	if (root == NULL) 
 	return; 
 	freeTree(root->left); 
 	freeTree(root->right); 
 	free(root); 
}

int main() { 
 	Node* routingTable = NULL; 
 	Route route1 = {"192.168.1.0", "Gateway A"}; 
 	Route route2 = {"10.0.0.0", "Gateway B"}; 
 	Route route3 = {"172.16.0.0", "Gateway C"}; 
 	routingTable = insert(routingTable, route1); 
 	routingTable = insert(routingTable, route2); 
 	routingTable = insert(routingTable, route3); 
 	char destIP[20]; 
 	strcpy(destIP, "10.0.0.0"); 
 	printf("Destination IP: %s, Next Hop: %s\n", destIP, lookup(routingTable, destIP)); 
 	strcpy(destIP, "192.168.1.0"); 
	printf("Destination IP: %s, Next Hop: %s\n", destIP, lookup(routingTable, destIP)); 
 	strcpy(destIP, "172.16.0.0"); 
 	printf("Destination IP: %s, Next Hop: %s\n", destIP, lookup(routingTable, destIP)); 
 	// Delete a route 
 	strcpy(destIP, "10.0.0.0"); 
 	routingTable = deleteNode(routingTable, destIP); 
 	printf("Route deleted: %s\n", destIP); 
 	strcpy(destIP, "10.0.0.0"); 
 	printf("Destination IP: %s, Next Hop: %s\n", destIP, lookup(routingTable, destIP)); 
 	freeTree(routingTable); 
 	return 0; 
} 