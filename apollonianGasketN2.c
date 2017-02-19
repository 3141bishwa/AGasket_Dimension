#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	  long a,b,c,d,e;
	    struct NODE* next;
} node;

void push(node** head, node* n)
{
  n->next = *head;
  *head = n;
}

node* pop(node** head)
{
  node* ris;
  ris = *head;
  if(ris!=NULL){
    *head = ris->next;
    ris->next = NULL;
  }
  return ris;
}

int isNull(node* list) {
  return list == NULL;
}

void usage(char* p){
  printf("Usage: %s -b first -e last [-p]\n",p);
  exit(0);
}

int main(int argc, char **argv)
{
  node* z,* list,* tmp,*z1,*z2,*z3;
  int i, first, last;
  double *k; 
  long *n;
  long boundary=0;
  int print=0;
  //  float base = 2;
  float base;
  float exponent;

  for (i=1; i<argc; i++){
    if(argv[i][0] != '-') usage(argv[0]);
    switch(argv[i][1]){
    case 'p':
      print=1;
      break;
    case 'b':
      sscanf(argv[++i],"%f",&base);
      break;
    case 'e':
      sscanf(argv[++i],"%f",&exponent);
      break;
    case 'f':
      sscanf(argv[++i],"%d",&first);
      break;
    case 'l':
      sscanf(argv[++i],"%d",&last);
      break;
    default:
      usage(argv[0]);
    }
  }


  k = (double*)malloc((last+1)*sizeof(double));
  if(k==NULL){
    printf("Error in allocating memory1\n");
    return 1;
  }

  n = (long*)malloc((last+1)*sizeof(long));
  if(n==NULL){
    printf("Error in allocating memory2\n");
    return 1;
  }

  printf("base = %f\n",base);
  printf("exponent = %f\n",exponent);
  
  for( i=first; i<=last; i++ ) {
    k[i] = pow(base,(i+1)*exponent);
    //   printf("k[%d] = %.16f\n",i,k[i]);
    n[i] = 0;

    printf("asdasd");
  }
  z = (node*)malloc(sizeof(node));

  if(z==NULL) {
    printf("Error in allocating memory\n");
    return 1;
  }
  z->next = NULL;

  list = NULL;
  
  //  while(scanf("%d %d %d %d %d",&z->a,&z->b,&z->c,&z->d,&z->e)!=EOF){
  while(scanf("%ld %ld %ld %ld",&z->a,&z->b,&z->c,&z->d)!=EOF){

	  z->e = z->a+z->b+z->c+2*z->d;

    push(&list,z);

    while(list != NULL) {

    tmp = pop(&list);

      if( tmp->e >= k[last] ) 
      {

	boundary++;
	if( print )
	  printf("%ld %ld %ld %ld\n",tmp->a,tmp->b,tmp->c,tmp->d);

      } else {
	i=last;
        while( tmp->e < k[i] )
          n[i--]++;

	z1 = (node*)malloc(sizeof(node));
	if(z1==NULL){
	  printf("Error in allocating memory\n");
	  exit(1);
	}
	z1->a = tmp->a;
	z1->b = tmp->b;
	z1->c = tmp->a+tmp->b+tmp->c+2*tmp->d;
	z1->d = tmp->a+tmp->b+tmp->d;
	z1->e = z1->a+z1->b+z1->c+2*z1->d;
	z1->next = NULL;
	push(&list,z1);

	z2 = (node*)malloc(sizeof(node));
	if(z2==NULL){
	  printf("Error in allocating memory\n");
	  exit(1);
	}
	z2->a = tmp->a;
	z2->b = tmp->c;
	z2->c = tmp->a+tmp->b+tmp->c+2*tmp->d;
	z2->d = tmp->a+tmp->c+tmp->d;
	z2->e = z2->a+z2->b+z2->c+2*z2->d;
	z2->next = NULL;
	push(&list,z2);

	z3 = (node*)malloc(sizeof(node));
	if(z3==NULL){
	  printf("Error in allocating memory\n");
	  exit(1);
	}

	z3->a = tmp->b;
	z3->b = tmp->c;
	z3->c = tmp->a+tmp->b+tmp->c+2*tmp->d;
	z3->d = tmp->b+tmp->c+tmp->d;
	z3->e = z3->a+z3->b+z3->c+2*z3->d;
	z3->next = NULL;
	push(&list,z3);

    }
      if(tmp!=z) 
	free(tmp);
      tmp =NULL;
    }
}

  for( i=first; i<=last; i++ ) 
    printf("n[%d] = %ld, k[%d] = %.16f\n",i+1,n[i],i+1,k[i]);
  
  printf("boundary = %ld\n",boundary);

  return 0;
}
