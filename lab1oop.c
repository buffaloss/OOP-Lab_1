#include<stdlib.h>
#include <stdio.h>
 
 // creating the data structure and its nodes
struct node
{
        int info;
        struct node *next;
};

struct node *start=NULL; //the pointer head/start which points to the our first node
// we declare it here so we can  use it in all our functions, not just main()



//FUNCTION TO CREATE THE LIST NODE BY NODE
void createLinkedList(){

        struct node *temp,*ptr; //create pointers temp and ptr
        temp=(struct node *)malloc(sizeof(struct node)); //allocate it memory

        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n"); //if allocation is unsuccesful,warn the user
                exit(0);
        }

             printf("\nEnter the data value for the node: \t");
             scanf("%d",&temp->info); //scan the value and store it as the info in the node
             temp->next=NULL;  //set the link t the next as NULL temporarily
        
             if (start==NULL)
             {
                start=temp; //set start 'node' as temp if no elements so far
             }
             else
             {
                ptr=start; //otherwise set ptr as start
                
                while(ptr->next != NULL) //until we reach the lats node
                {
                        ptr=ptr->next; //do the loop of setting ptr as the link to the next node each iteration
                }

                ptr->next=temp;
             }
             
        
}



//FUNCTION TO PRINT THE LIST
void printLinkedList(struct node *start){
    
    if(start == NULL) //if the start node is empty, there are no elements
      printf("The linked list is empty. ");

    struct node *ptr = NULL; //create pointer ptr
    ptr = start; // assign the addres in the start pointer to ptr 
    printf("\nLinked list: ");

    while(ptr != NULL){ //until we reach the last node with next adress as NULL
        printf("%d -> ",ptr->info); //print list
        ptr = ptr->next; //update ptr to next adress
    }

    printf("NULL\n");
}



// FUNCTION TO WRITE LINKED LIST TO A FILE (SAVE IT IN A FILE)
void writeToFile() {
    int input;
    FILE *outfile;
     
    // open file for writing
    outfile = fopen ("full3.txt", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }
    
        if(start == NULL) //if the start node is empty, there are no elements
        printf("The linked list is empty. ");

       struct node *ptr = NULL; //create pointer ptr
       ptr = start; // assign the addres in the start pointer to ptr 
        while(ptr != NULL){ //until we reach the last node with next adress as NULL
          input = ptr->info;
              // write struct to file
          fwrite (&input, sizeof(struct node), 1, outfile);

          ptr = ptr->next; //update ptr to next adress
    }
     
    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
 
    // close file
    fclose (outfile);
    }



//FUNCTION TO LOAD LINKED LIST FROM A FILE 
void loadFromFile() {

    FILE *infile; //use FILE 
    struct node input;
     
    // open  the specific file for reading
    infile = fopen ("full3.txt", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n"); //statement if opening file fails
        exit (1);
    }
     
    // read files' contents until teh end of it
    while(fread(&input, sizeof(struct node), 1, infile))
        printf ("%d -> ", input.info);
        
    // close teh file
    fclose (infile);
    printf("NULL    \n");

}
 


// FUNCTION TO ADD NODE AT THE BEGINNING (prepend)
void prependList(){
    
    struct node *temp; //create poiinter temp 
        temp=(struct node *)malloc(sizeof(struct node)); //allocate memory
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the data value for the node: \t" );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }


}



//FUNCTION TO ADD VALUE TO SPECIFIC INDEX
void addToIndex() {
    struct node *ptr,*temp; //create poiinters ptr and temp again
        int i,pos; //integers i and tpos = posiiton 
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space: \n");
                return;
        }
        printf("\nEnter the position for the new node to be inserted: \t");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node: \t");
        scanf("%d",&temp->info) ;
  
        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++) { ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found:[Handle with care]\n");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }


}



//FUNCTION TO REMOVE VALUE FROM A SPECIFIC INDEX
void removeFromIndex(){
     int i,pos;
        struct node *temp,*ptr; //create pointers
        if(start==NULL)
        {
                printf("\nThe List is Empty: \n");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be deleted: \t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("\nThe deleted element is: %d \t",ptr->info  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found: \n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%d \t",ptr->info );
                        free(ptr);
                }
        }


}



int main()     {
     

     //CREATING THE LIST MANUALLY 

    /*start = (struct node *)malloc(sizeof(struct node));// creating teh node and allocating memory for it
    //the start pointer stores the address of the node now, instead of NULL
     
     start->info = 15;//accesing the data pf the first node(15)
     start->next = NULL; //accessing the pointer to the next node(NULL)
     
     struct node *current = (struct node *)(malloc(sizeof(struct node)));
     current->info = 98;
     current->next = NULL;
     start->next = current;

     current = (struct node *)(malloc(sizeof(struct node)));
     current->info = 3;
     current->next = NULL;

     start->next->next = current; */

     int choice;
     while(1){
         printf("\n                                                   \t");
         printf("\n          | MENU |                            \n");
         printf("\n 1.Create Linked List By Adding Nodes [APPEND]   \n");
         printf("\n 2.Print Linked List    \n");
         printf("\n 3.Write Linked List To File    \n");
         printf("\n 4.Load Linked List from File    \n");
         printf("\n 5.Add Node At Beginning [PREPEND]   \n");
         printf("\n 6.Add Value To A Specific Index     \n");
         printf("\n 7.Remove Value From A Specific Index    \n");
         printf("\n 8.Exit               \n");

         printf("\n                                                   \n");

         
         scanf("%d",&choice);
         switch(choice){ //for each option call the needed function
            case 1:
                   createLinkedList();
                   break;
            case 2:
                   printLinkedList(start);
                   break;
            case 3:
                   writeToFile();
                   break;
            case 4:
                   loadFromFile();
                   break;
            case 5:
                   prependList();
                   break;
            case 6:
                   addToIndex();
                   break;
            case 7:
                   removeFromIndex();
                   break;
            case 8:
                   exit(0); //exiit the menu 
          
                }

         }

    return 0;
}
