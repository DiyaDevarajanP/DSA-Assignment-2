#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10


// Tree node
struct Node
 {
    char name[20];
    struct Node *child[MAX];
    int childCount;
};


// Create a new node
struct Node* createNode(char name[])
 {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->childCount = 0;
    return newNode;
}


// Add child to a node
void addChild(struct Node *parent, struct Node *child)
 {
    parent->child[parent->childCount++] = child;
}


// Level-order traversal
void levelOrder(struct Node *root)
 {
    struct Node *queue[20];
    int front = 0, rear = 0;
    queue[rear++] = root;
    printf("\nLevel-order Traversal:\n");


    while (front < rear)
    {
        struct Node *current = queue[front++];
        printf("%s  ", current->name);
        for (int i = 0; i < current->childCount; i++)
            queue[rear++] = current->child[i];
    }
    printf("\n");
}


// Linear Search
int linearSearch(char dept[][20], int n, char key[], int *comparisons)
 {
    *comparisons = 0;
    for (int i = 0; i < n; i++) 
   {
        (*comparisons)++;
        if (strcmp(dept[i], key) == 0)
            return i;
    }
    return -1;
}


// Binary Search
int binarySearch(char dept[][20], int n, char key[], int *comparisons)
 {
    int low = 0, high = n - 1;
    *comparisons = 0;
     while (low <= high)
  {
        int mid = (low + high) / 2;
        (*comparisons)++;


        if (strcmp(dept[mid], key) == 0)
            return mid;


        if (strcmp(key, dept[mid]) < 0)
            high = mid - 1;


        else
            low = mid + 1;
    }
    return -1;
}


int main()
 {


    // Construct organisational hierarchy
    struct Node *CEO = createNode("CEO");
    struct Node *HR = createNode("HR");
    struct Node *Finance = createNode("Finance");
    struct Node *IT = createNode("IT");
    struct Node *Development = createNode("Development");
    struct Node *Testing = createNode("Testing");
    struct Node *Frontend = createNode("Frontend");
    struct Node *Backend = createNode("Backend");


    addChild(CEO, HR);
    addChild(CEO, Finance);
    addChild(CEO, IT);


    addChild(IT, Development);
    addChild(IT, Testing);


    addChild(Development, Frontend);
    addChild(Development, Backend);


    // Part A
    levelOrder(CEO);


    // Sorted department names for searching
    char departments[8][20] = {
        "Backend",
        "CEO",
        "Development",
        "Finance",
        "Frontend",
        "HR",
        "IT",
        "Testing"
    };


    int n = 8;
    char key[20];
    int linearComp, binaryComp;
    printf("\nDepartments available for searching:\n");
    for (int i = 0; i < n; i++)
        printf("%s  ", departments[i]);


    printf("\n\nEnter department name to search: ");
    scanf("%19s", key);


    int linearResult = linearSearch(departments, n, key, &linearComp);
    int binaryResult = binarySearch(departments, n, key, &binaryComp);


    printf("\nSearch Result for: %s\n", key);


    if (linearResult != -1)
        printf("Linear Search: Found, Comparisons = %d\n", linearComp);
    else
        printf("Linear Search: Not Found, Comparisons = %d\n", linearComp);


    if (binaryResult != -1)
        printf("Binary Search: Found, Comparisons = %d\n", binaryComp);
    else
        printf("Binary Search: Not Found, Comparisons = %d\n", binaryComp);


    return 0;
}
