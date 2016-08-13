// sll.h


struct node {
    int val;
    struct node *next;
};
typedef node* NPTR;


class SLL {
private :
    NPTR head;

    NPTR getNode(int _val) {
    	NPTR t = new node;
    	t->next = NULL;
    	t->val = _val;
    	return t;
    }

public:
    SLL() {
        head=NULL;
    } 

	void display();

	void add(int val) ;

	void append(int val) ;

	void reverse_pointer_method();

	void reverse_newh_method();

	void reverse_recursion_method();

	int delete_node(int val);

	void reverse_alternate();

	void merge_alternate(SLL other) ;

	void reverse_k_node(int _k);

	void  find_middle() ;

};


NPTR reverse(NPTR h) ;