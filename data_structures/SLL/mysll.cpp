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




void SLL :: reverse_recursion_method (){
    
    if (!head) {
        return ;
    }
   
    head = reverse(head);

}


NPTR reverse(NPTR h) {
    if (!h || !h->next) {
        return h;
    }
    
    NPTR t = h->next;
    h->next = NULL;
    NPTR newh = reverse(t);
    t->next = h;
    return newh;
}


int SLL :: delete_node(int _val) {
    NPTR t = head;

    if(t->val == _val) {
        head = t->next;
        delete t;
        return 1;
    }

    while(t->next && t->next->val != _val) {
        t = t->next;
    }

    if(t->next) {
        NPTR d = t->next;
        t->next = t->next->next;
        delete d;
        return 1;
    }
    
    return -1;
}


void SLL :: reverse_alternate() {
    NPTR p, q, r ;
    if (!head || !head->next) {
        return ;
    }
    p = NULL;
    q = head ;

    head = head->next;
    
    r = q->next;

    while(q && r) {
        
        q->next = r->next ;
        r->next = q;

        if(p) {
            p->next = r;
        }
        p = q;

        q = p->next;

        if (q) {
            r = q->next;
        }

        //display();    
    }


}


int main() {

    // declare sll
    SLL s;

    s.add(23);
    s.add(423);
    s.add(623);
    s.append(56);
    s.append(87);
/*    s.display();
    s.reverse_recursion_method();
    s.display();
    s.delete_node(87);
    s.display();
    s.delete_node(56);
    s.display();
    s.delete_node(23);
    s.display();


    for (int i=1 ; i <= 50 ; i++) {
        s.add(i);
    }
*/    
    s.display();

    //s.reverse_recursion_method();


    s.display();

    s.reverse_alternate();


    s.display();

    return 0;
}