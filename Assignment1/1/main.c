#include "my_dll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    my_dll dblist=CreateList();
    char inp[15];
    while(scanf("%s",inp)!=EOF){
        if(!strcmp(inp,"insert")){
            int temp;
            scanf("%d",&temp);
            insert(&dblist,temp);
        }else if(!strcmp(inp,"insert_at")){
            int x,pos;
            scanf("%d%d",&x,&pos);
            insert_at(&dblist,x,pos);
        }else if(!strcmp(inp,"delete")){
            int temp;
            scanf("%d",&temp);
            delete(&dblist,temp);
        }else if(!strcmp(inp,"find")){
            int temp;
            scanf("%d",&temp);
            printf("%d\n",Find(&dblist,temp));
        }else if(!strcmp(inp,"prune")){
            prune(&dblist);
        }else if(!strcmp(inp,"print")){
            print(dblist);
        }else if(!strcmp(inp,"print_reverse")){
            print_reverse(dblist);
        }else if(!strcmp(inp,"get_size")){
            printf("%u\n",get_size(dblist));
        }else if(!strcmp(inp,"exit")){
            return 0;
        }
        else{
            printf("Invalid command\n");
        }
    }
}