#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "avl.h"

int main(){
   AVL avl;
   initAVL(&avl);
   int input;
   int flag = 1;

      printf("-----AVL Implementation-----\n");
      printf("1.Insert Into AVL Tree\n2.Remove from AVL Tree\n3.Traverse AVL\n4.Destroy Tree (Warning!There's No going back)\n5.exit\n : ");
   
   char temp[10] = {""};
   while(flag){
      scanf("%d",&input);
      switch(input){
         case 1:
            printf("Enter '-1' to stop inserting\n");
            while(1){
            scanf("%s",temp);
            if(strcmp(temp,"-1") == 0)
               break;
            insertAVL(&avl,temp);
            printf(" '%s' inserted into AVL\n : ",temp);
            }
            break;
         case 2:
            scanf("%s",temp);
            removeAVL(&avl,temp);
            printf(" '%s' removed from AVL\n : ",temp);
            break;            
         case 3:
            printf("---  AVL Traversal  ---\n");
            traverse(avl);
            printf("-----------------------\n");
            break;
         case 4:
            destroyAVL(&avl);
            printf("AVL Tree destroyed successfully\n");
            break;
         case 5:
               flag = 0;
               getHeight(avl);
               exit(0);
               break;
         default:
            printf("Incorrect Input. Please select one of the following options.\n");
            system("clear");
            break;
      }
      printf("\n------------------------\n");
      printf("1.Insert Into AVL Tree\n2.Remove from AVL Tree\n3.Traverse AVL\n4.Destroy Tree (Warning!There's No going back)\n5.exit");
      printf("\n : ");
   }
   return 0; 
}
