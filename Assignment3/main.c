#include<stdio.h>
#include "avl.h"

int main(){
   AVL avl;
   initAVL(&avl);
   insertAVL(&avl,"January");
   insertAVL(&avl,"February");
   insertAVL(&avl,"March");
   insertAVL(&avl,"April");
   insertAVL(&avl,"May");
   insertAVL(&avl,"June");
   insertAVL(&avl,"July");
   insertAVL(&avl,"August");
   insertAVL(&avl,"September");
   insertAVL(&avl,"October");
   insertAVL(&avl,"November");
   insertAVL(&avl,"December");
   printf("%d\n",getHeight(avl));
   traverse(avl);
   return 0; 
}
