#include <stdio.h>   
  
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
};      
   
int size = 0;  
struct node *head, *tail = NULL;  
   
void addNode(int data) {  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    if(head == NULL) {  
        head = tail = newNode;  

        head->previous = NULL;  

        tail->next = NULL;  
    }  
    else {  
  
        tail->next = newNode;  
  
        newNode->previous = tail;  
       
        tail = newNode;  
        
        tail->next = NULL;  
    }  
    
    size++;  
}  
   

void rotateList(int n) {  

    struct node *current = head;  
      
    //n should not be 0 or greater than or equal to number of nodes present in the list  
    if(n == 0 || n >= size)   
        return;  
    else {  
        //Traverse through the list till current point to nth node  
        //after this loop, current will point to nth node  
        for(int i = 1; i < n; i++)   
            current = current->next;  
          
        //Now to move entire list from head to nth node and add it after tail  
        tail->next = head;  
        //Node next to nth node will be new head  
        head = current->next;  
        //Previous node to head should be NULL  
        head->previous = NULL;  
        //nth node will become new tail of the list  
        tail = current;  
        //tail's next will point to NULL  
        tail->next = NULL;  
    }  
}  
   

void display() {  
   
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    while(current != NULL) {  
        
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
   
int main()  
{  
    //Add nodes to the list  
    addNode(1);  
    addNode(2);  
    addNode(3);  
    addNode(4);  
    addNode(5);  
      
    printf("Original List: \n");  
    display();  
      
    //Rotates list by 3 nodes  
    rotateList(3);  
      
    printf("Updated List: \n");  
    display();  
   
    return 0;  
}  
