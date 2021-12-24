/*
For a given singly linked list of integers, find and return its length. Do it using an iterative method.
*/
int length(Node *head){
    int count=0;
    Node *current = head;
    while(current != NULL){
        current = current -> next;
        count++;
    }
    return count;
}