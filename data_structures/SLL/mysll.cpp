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

void SLL :: reverse_newh_method (){
    NPTR p, q ;
    if (!head) {
        return ;
    }
    p = head;
    head = NULL;

    while (p) {
        q = p;
        p = p->next;
        
        if(!head) {
            head = q ;
            q->next = NULL;
        } else {
            q->next = head;
            head = q;
        }
    }

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

void  SLL :: reverse_k_node (int k) {
    head = _reverse_k_node (head, k);   
}

NPTR  _reverse_k_node (NPTR _head, int k)
{
    NPTR current = _head;
    NPTR next = NULL;
    NPTR prev = NULL;
    int count = 0;   
     
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
     
    /* next is now a pointer to (k+1)th node 
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
    if (next !=  NULL)
       _head->next = _reverse_k_node(next, k); 
 
    /* prev is new head of the input list */
    return prev;
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
    }
}


void  SLL :: merge_alternate(SLL other) {
    NPTR first, second, firstnext, secondnext;

    first = this->head;
    second = other.head;

    while (first && second) {
        firstnext = first->next;
        secondnext = second->next;

        first->next = second;
        second->next = firstnext;

        first =firstnext;
        second = secondnext;
    }

}


void  SLL :: find_middle() {
    NPTR slow, fast;

    fast = head;
    slow = fast;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    printf("Middle = %d\n", slow->val);
}







int main() {

    // declare sll
    SLL s;
/*
    s.append(1);
    s.append(3);
    s.append(5);
    s.append(7);
    s.append(9);

    SLL o;
    o.append(2);
    o.append(4);
    o.append(6);
    o.append(8);
    o.append(10);
    o.append(12);


   s.display();
    s.reverse_recursion_method();
    s.display();
    s.delete_node(87);
    s.display();
    s.delete_node(56);
    s.display();
    s.delete_node(23);
    s.display();

*/
    for (int i=1 ; i <= 10 ; i++) {
        s.append(i);
    }
    
    s.display();
    //o.display();

    //s.merge_alternate(o);

    s.reverse_k_node(3);


    s.display();


    //s.find_middle();
    //s.reverse_alternate();



    return 0;
}