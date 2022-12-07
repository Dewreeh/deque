#include <stdio.h>
#include <stdlib.h>

typedef struct deque_tag{
    int data;
    struct deque_tag *next, *prev;

}deque;

deque * first(deque*L) { return L; }
deque * next(deque*L) { return L->next; }

deque* init()
{
      deque *head = malloc(sizeof(deque));
      head->next = head->prev = head;
      return head;
}

int isempty(deque*L)
{
        return L->next ? 1 : 0;
}
deque* last(deque*L)
{
   return L->prev;
}

deque* pop(deque*L)
{
     deque* n = last(L); 
     if(n == L) return n;  
     printf("\ndeleting %d\n", n->data);
     n->prev->next = n->next;
     n->next->prev = n->prev;
     free(n);
     return n;

}

deque* pop_start(deque*L)
{
     deque* n = first(L)->next;   
     if(n == L) return n; 
     printf("\ndeleting %d\n", n->data);
     n->prev->next = n->next;
     n->next->prev = n->prev;
     free(n);
     return n;

}

void destroy(deque*L)
{
    while(!isempty(L)) {
        pop_start(L);
    }
    free(L);
}
deque* create(int data)
{
    deque *n = malloc(sizeof(deque));
    n->next = n->prev = n;
    n->data = data;
    return n;
}
void push(deque*L, int num)
{
    deque* n = create(num);
    deque* p = last(L);
    if(!(p->next)){
        n->next = L;
        L->prev = n;
        n->prev->next = n;
        p->next = n;
    }
    n->next = p->next; n->prev = p;
    p->next = n;
    n->next->prev = n;
    if(n == last(L)) L->prev = n;
}
void push_start(deque*L,int num)
{
    deque* n = create(num);
    deque* p = L;
    if(!(p->next)){
        n->next = L;
        L->prev = n;
        n->prev->next = n;
        p->next = n;
    }
    n->next = p->next; n->prev = p;
    p->next = n;
    n->next->prev = n;
    if(n == last(L)) L->prev = n;
}

deque* fill(deque*L, int N){
    int n;
    for(int i = 0; i <= N; i++){
        n = rand();
        push_start(L, n);
    }
}

deque* print_deque(deque *L){
    printf("-----------------------\n");
    for(deque* i = L->next; i != L; i=i->next){
        printf("%d\n", i->data);
    }
}
int main(void){
    deque* dL = create(0);
    print_deque(dL);
    fill(dL, 5);
    print_deque(dL);
    pop_start(dL);
    push_start(dL, 10);
    print_deque(dL);
    return 0;
}