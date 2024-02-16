#include<stdio.h>
#include<stdlib.h>
#include<String.h> //music name will be in string that why i have use string file

struct node {
	char data[40];// to store music file name
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
struct node *current;// this will to move next or previous node(music)
char temp[40];

void insert(){
	
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter Music Name:\n");
	while((getchar())!='\n');
	scanf("%[^\n]%*c",newnode->data);
	
	newnode->prev=NULL;
	newnode->prev=NULL;
	
	if(head==NULL){
		head=newnode;
		current=head;
	}
	else{
		current->next=newnode;
		newnode->prev=current;
		current=newnode;
	}
 printf("Music \"%s\" added to the playlist.\n", newnode->data);
	
}

void Delete_element(){
	
	    if (head == NULL) {
        printf("Playlist is empty. Cannot delete.\n");
        return;
    }

	
	char delete_ele[40];
	printf("Enter Music name to delete\n");
	while((getchar())!='\n');
	scanf("%[^\n]%*c",delete_ele);
	
	struct node *temp=head;
	
	while(temp!=NULL){
		if(strcmp(temp->data,delete_ele)==0){//this will return 0 is two string is equal
			if(temp->prev!=NULL){
				temp->prev->next=temp->next;
			}else{//it song to delete is the first song
				head=temp->next;
				if(head!=NULL){
					head->prev=NULL;
				}
			}
			if(temp->next!=NULL){
				temp->next->prev=temp->prev;
			}
			free(temp);
			printf("Music \"%s\" deleted from the playlist.\n",delete_ele);
			return;
	}
	temp=temp->next;//to traverse upto searching element
		}
}
void show(){
	struct node *temp=head;
	
	if(temp==NULL){
		printf("Playlist is empty\n");
		return;
	}
	
	printf("\n----Playlist----\n");
	while(temp!=NULL){
		printf("%s\n",temp->data);
		temp=temp->next;
	}
	printf("------------------\n");
}
void next_song(){
	 if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Playing next song: %s\n", current->data);
    } else {
        printf("No next song available.\n");
    }
}

void prev_song(){
	if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Playing previous song: %s\n", current->data);
    } else {
        printf("No previous song available.\n");
    }
} 	
void first_song(){
	if (head != NULL) {
        current = head;
        printf("Playing first song: %s\n", current->data);
    } else {
        printf("Playlist is empty.\n");
    }
}
void last_song(){
	if (head != NULL) {
        while (current->next != NULL) {
            current = current->next;
        }
        printf("Playing last song: %s\n", current->data);
    } else {
        printf("Playlist is empty.\n");
    }
}
void spec_song(){
if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
   char song[40];
    printf("Enter the music name to play: ");
    while ((getchar()) != '\n'); 
    scanf("%[^\n]%*c", song); 

	struct node* temp = head;
	while (temp != NULL) {
        if (strcmp(temp->data, song) == 0) {
            current = temp;
            printf("Playing specific song: %s\n", current->data);
            return;
        }
        temp = temp->next;
    }

    printf("Music \"%s\" not found in the playlist.\n", song);

}

int main(){
	
	int choice;
		 
	 while(1){
	//menu;
	printf("\n----Menu for Playlist-----\n");
	printf("1. Add Music\n");
	printf("2. Remove Music\n");
	printf("3. Show Playlist\n");
	printf("4. Play next file\n");
	printf("5. Play previous file\n");
	printf("6. Play first file\n");
	printf("7. Play Last file\n");
	printf("8. Play specific file\n");
	printf("9. Exit\n");
	scanf("%d",&choice);

	 
	switch(choice){
		case 1:
			insert();
			break;
		case 2:
			Delete_element();
			break;
		case 3:
			show();
			break;
		case 4:
			next_song();
			break;
		case 5:
			prev_song();
			break;
		case 6:
			first_song();
			break;
		case 7:
			last_song();
			break;
		case 8:
			spec_song();
			break;
		default:
		
		 	exit(0);
	} 
}
	return 0;
}
























