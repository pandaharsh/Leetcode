typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    struct node *front1;
    struct node *back1;

    struct node *front2;
    struct node *back2;

    int top;

} MyStack;


MyStack* myStackCreate() {

    MyStack *st = (MyStack*) malloc(sizeof(MyStack));

    st->front1 = NULL;
    st->back1 = NULL;
    st->front2 = NULL;
    st->back2 = NULL;

    return st;
    
}

void myStackPush(MyStack* obj, int x) {
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    obj->top = x;

    Node **front, **back;
    if(obj->front1 != NULL){
        front = &(obj->front1);
        back = &(obj->back1);
    }
    else {
        front = &(obj->front2);
        back = &(obj->back2);
    }

    if(*front == NULL)
        *front = newNode;
    else
        (*back)->next = newNode;

    *back = newNode;
}

void push(Node **front, Node **back, int value)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(*front == NULL)
        *front = newNode;
    else
        (*back)->next = newNode;

    *back = newNode;
}

int myStackPop(MyStack* obj) {

    Node **head1, **tail1, **head2, **tail2;

    if(obj->front1 == NULL)
    {
        head1 = &(obj->front2);
        tail1 = &(obj->back2);
        head2 = &(obj->front1);
        tail2 = &(obj->back1);
    }
    else
    {
        head1 = &(obj->front1);
        tail1 = &(obj->back1);
        head2 = &(obj->front2);
        tail2 = &(obj->back2);
    }

    Node *tempNode;

    while((*head1)->next != NULL)
    {
        push(head2, tail2, (*head1)->data);
        tempNode = *head1;
        obj->top = (*head1)->data;
        *head1 = (*head1)->next;
        free(tempNode);
    }

    int returnValue = (*head1)->data;
    free(*head1);
    *head1 = *tail1 = NULL;

    return returnValue;
    
}

int myStackTop(MyStack* obj) {
    return obj->top;
}

bool myStackEmpty(MyStack* obj) {
    return obj->front1 == NULL && obj->front2 == NULL;
}

void myStackFree(MyStack* obj) {

    Node *deletedNode;

    while(obj->front1 != NULL)
    {
        deletedNode = obj->front1;
        obj->front1 = obj->front1->next;
        free(deletedNode);
    }

    while(obj->front2 != NULL)
    {
        deletedNode = obj->front2;
        obj->front2 = obj->front2->next;
        free(deletedNode);
    }
    
    obj->front1 = obj->back1 = obj->front2 = obj->back2 = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/