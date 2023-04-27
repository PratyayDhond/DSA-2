#include<stdio.h>
#include "avl.h"

int main(){
   AVL avl;
   initAVL(&avl);
   insertAVL(&avl,"Pratyay4");
   insertAVL(&avl,"Pratyay2");
   insertAVL(&avl,"Pratyay5");
   insertAVL(&avl,"Pratyay");
   insertAVL(&avl,"Pratyay1");
   insertAVL(&avl,"Pratyay3");
   insertAVL(&avl,"Pratyay3");
   insertAVL(&avl,"Pratyay6");
   insertAVL(&avl,"Pratyay");

   printf("%d\n",getHeight(avl));
   inorderAVL(avl);

   return 0; 
}
