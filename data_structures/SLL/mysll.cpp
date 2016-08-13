#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <execinfo.h>
#include <unistd.h>
#include "sll.h"



void SLL :: display() {

    NPTR h = head;
    printf("\nhead-->");
    while(h){
        printf("%d-->", h->val);
        h = h->next;
    }
    printf("NULL\n");
}

void SLL :: add(int val) {
    NPTR n = getNode(val);
    if(head){
        n->next = head;
    }    
    head = n;
}


void SLL :: append(int val) {
    NPTR n,t = head ;
    n = getNode(val);
    if(t) {
        while(t->next) {
            t=t->next;
        }
        t->next=n;
    }else {
        head=n;
    }
    
}



void SLL :: reverse_pointer_method (){
    NPTR p, q ,r ;
    if (!head) {
        return ;
    }
    p = head ;
    q = p->next;
    p->next = NULL;
    while(q) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head = p;
}


int main() {

    // declare sll
    SLL s;

    s.add(23);
    s.add(423);
    s.add(623);

    s.append(56);
    s.append(87);
    s.display();
    s.reverse_pointer_method();

    s.display();
 

    return 0;
}