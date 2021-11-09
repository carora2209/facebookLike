#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct dateofbirth
        {   
            int dd;
            int mm;
            int yy;   
        }t1;

typedef struct details
        {   
            
                char firstname[100];
                char lastname[100];
                char nickname[100];
                char birthplace[100];
                int age;
                struct dateofbirth dob;
                char password[100]; 
                char inviter[100];     
                    
        }t;

typedef struct List
        {
            struct details d;
            struct List *next;
            
        }List;
 
                                        //***********Function Prototypes********//

                                        //***********Starting screens**********//
void mainscreen();          //flash screen
void secondscreen();        // loginscreen

                                    //******Different way for existing and new user*******//

void existinglogin();              //login process for existing user
int newlogin();                    //New User Registration

                                    //********community creation*******//

void communityscreen(char* inviter);                           //Required to ask user whether to create a new community or open an existing one 
void startcreation(char* inviter);                             //creation of a new community
void existingcommunityscreen(char* inviter);                   //opening existing community and loading data  
void operations(List* head,char* communityname,char* inviter); //Menu driven program to execute opeartaion on linked list

                            //*******operations which can we be executed******//

List* loadfunction(char* communityname);                    //load data from file
List* addmembers(List* head, char* username,char* inviter); //add details of the member to the linked list
int printdetails(List* head,char* username);                //print details of a specific member
int whoaddedwhom(char* who,char* communityname);            //Find who all were invited by a particular member
List* delete(List* head,char* username);                    //delete details of a person in a list
int savetofile(List* head , char* communityname);           //save data back to the file 
void printlist(List* head);                                 //print the nIckname of all members in the list

                                //********LIST OF VALIDATIONS CREATED********//

int isuserpresentincommunity(char* username,List* head);   //To check whether user is present in community
int checklogin(char *loginid, char *password);             //To check the credentials during login
int checkusername(char *username);                         //Check the username's existence in the main datatbse i.e. members.txt
int communitycheck(char* communityname);                   //check the existence of a community


//***********************************************STARTING MENU*********************************************//

//The program starts executing from here 
int main()
{   
    //The program starts from here
    mainscreen();
    return 0;
}

//This function is used to display the flash screen
void mainscreen()
{
    char maininput;
    printf("\t\t\t\t\t\t\t FACEBOOK\n");
    printf("\t\t\t\t\t\t\t***********");
    printf("\n\n");
    printf("\t\t\t\t\t WELCOME TO FACEBOOK:\n \t\t\t\t\t\t A COMMUNITY BASED PROJECT DESIGNED TO CONNECT PEOPLE :");
    printf("\n\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tNAME:CHAITANYA ARORA\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tNEPTUN CODE:BWTFX8\n");
    //menu starts 
    printf("ENTER 1 TO CONTINUE :\n");
    printf("ENTER 0 TO EXIT :\n");

    while(1) // used to while(1) loop so that the other inputs besides the one required can be displayed and it gets executed again
    {
        scanf("%c",&maininput);
        fflush(stdin);      // to eat up the enter input
        if(maininput=='0') // declared input as character so that it does not go in a infinite loop
        { exit(0); }
        else if(maininput=='1')
        {   printf("\n\n");
            secondscreen(); 
            break;
        }
        else
        { printf("INVALID ENTRY, ENTER AGAIN :\n");  }
    }
}

//This is required to ask whether the user is a new user or an existing user
void secondscreen()
{   char input;
    int x=0;
    printf("\t\t\t\t\t*********** WELCOME **********\n\n");
    printf("\n\n\n");
    printf("PRESS 1 TO EXISTING LOGIN :\n");
    printf("PRESS 2 FOR NEW USER LOGIN :\n");
    while(1)
    {
        scanf("%c",&input);
        fflush(stdin);
        if(input =='1')
        {  
            printf("\n\n");
            existinglogin();  
            break;          
        }
        else if(input =='2')
        {   if(newlogin())
            {
                printf("ACCOUNT MADE SUCCESSFULLY !!");  
                printf("\n\n"); 
                existinglogin();
                break;
            }
        }
        else
        { printf("INVALID ENTRY, ENTER AGAIN :\n");   }

    }

}

//*********************************************LOGIN PROCESS******************************************// 

//Required to executing the login portal for an existing user
void existinglogin()
{   int response;
    char inviter[100],password[100];

    printf("WELCOME TO EXISTING LOGIN SCREEN\n");

  while(response!=1)
  {  
    printf("ENTER YOUR NICKNAME :");
    scanf("%s",inviter);            // taking input for login
    printf("ENTER THE PASSWORD :"); 
    scanf("%s",password);           //taking input for password
   
    response = checklogin(inviter,password);  //This function checks whether the credentials match 
        
        if(response == 1)
        {
            printf("SUCCESSFUL!\n\n");
            communityscreen(inviter);
        }

        else
        {
            printf(" WRONG ENTER AGAIN :\n");
        }
  }

} 

//Required for addtion of a new member in the database
int newlogin()
{  
    struct details S1;
    FILE *fp;
    int status;
    status = 2;
    printf("\t\t\t\t\t-------WELCOME TO NEW LOGIN PAGE-------\n\n");
    printf("PLEASE ENTER THE REQUIRED DETAILS :\n");

    fp = fopen("Members.txt","a");           // opening the file
            if(fp==NULL)
            {
                 printf("Error!");   
                 exit(1);    
            }
            
    // receiving data and entering it in the file    
    printf("ENTER YOUR FIRSTNAME :\n");
    scanf("%s",S1.firstname);
    

    printf("ENTER YOUR LASTNAME :\n");
    scanf("%s",S1.lastname);
   
   while (1)
   {
        printf("ENTER NICKNAME WHICH IS GOING TO BE USED AS USERNAME:\n");
        scanf("%s",S1.nickname);
        int output = checkusername(S1.nickname);
        if(output==0)
        {
            break;
        }
        else
        {
            printf("This Username is already taken , Please enter Again :\n");
        }

   }

    // Taking users Data
    printf("ENTER THE BIRTHPLACE :\n");
    scanf("%s",S1.birthplace);
    
    printf("ENTER DATE OF BIRTH (DD MM YYYY) :\n");
    scanf("%d",&S1.dob.dd);
    scanf("%d",&S1.dob.mm);
    scanf("%d",&S1.dob.yy); 
    
    printf("ENTER YOUR AGE :\n");
    scanf("%d",&S1.age);

    printf("ENTER YOUR PASSWORD :\n");
    scanf("%s",S1.password);
                                     //writing in the file 
    fprintf(fp,"\n%s ",S1.firstname);
    fprintf(fp,"%s ",S1.lastname);
    fprintf(fp,"%s ",S1.nickname);
    fprintf(fp,"%s ",S1.birthplace);
    fprintf(fp,"%d ",S1.dob.dd);
    fprintf(fp,"%d ",S1.dob.mm);
    fprintf(fp,"%d ",S1.dob.yy);
    fprintf(fp,"%d ",S1.age); 
    fprintf(fp,"%s ",S1.password);

    fclose(fp);

    return 1;

}

//*******************************************COMMUNITY CREATION***************************************//

//Required to ask the user whether he wants to create a new community or open existing  community
void communityscreen(char* inviter)
{    // Asking users choice 
    char input;
    printf("\t\t\t\t\t***********WELCOME TO COMMUNITY CREATION PAGE :**********\n\n");
    printf("Enter 1 to start creation :\n");
    printf("Enter 2 to Open Existing Communities :\n");
    printf("Enter 3 to logout :\n");
    printf("Enter 4 to exit :\n");
    fflush(stdin);
    while(1)
    {
        scanf("%c",&input);
        fflush(stdin);
        if(input=='1')
        {   
            printf("\n\n");
            startcreation(inviter);
            break;

        }
        else if(input=='2')
        {   
            printf("\n\n");
            existingcommunityscreen(inviter);
            break;
        }
        else if(input=='3')
        {   
            printf("\n\n");
            secondscreen();
            break;
        }
        else if(input=='4')
        {
            exit(0);
        }
        else
        {
            printf("INVALID INPUT ENTER AGAIN :\n");
        }
    }   
   
}

//The community creation process from scratch 
void startcreation(char* inviter)
{   
    struct details d;
    List *head=NULL;
    int secondinput;
    char communityname[100],username[100];
    int input=0 ;
        while(1)
        {
             printf("Enter the name of your community :\n");
             scanf("%s",communityname);                //asking for community name

            if(communitycheck(communityname))          // checking of community is present 
            {
                printf("This File is Already Present \n");
            }
            else
            {
                break;
            }
            
        }

    while(1)
    {       // menu driven program to add members in the commmunity and then saving records
                printf("Press 1 if You want to want to review all the members :\n");
                printf("Press 2 if you want to Enter Members :\n");
                printf("Press 3 if you want to save record :\n");
                printf("Press 4 to exit :");

      while(1)
      { 
          scanf("%d",&input);
          fflush(stdin);
          if(input == 1)
            {   
                printf("\n\n");
                printlist(head);
                break;
            }

        else if(input == 2)
            {   
                    printf("ENTER THE USERNAME :");
                    scanf("%s",username);

                    if(checkusername(username))  // checking the keyfield
                    {  
                        if(isuserpresentincommunity(username,head)) //chekcing if he/she is already added in the linked list
                        {
                             head = addmembers(head,username,inviter);
                             break;
                        }
                        else
                        {
                            printf("This member is already present in the community \n");
                            break;
                        } 
                    }
                    else
                    {
                        printf("NOT FOUND THIS USERNAME IN RECORDS :\n");
                        break;
                    }

            }

        else if(input ==3)      
                    {
                        if(savetofile(head,communityname)) //saving data to the file named as the community name
                        {   
                            printf("\n\n");
                            printf("DATA SAVED SUCCESFULLY !\n");
                            break;
                        } 
                    }   
        else if(input == 4)
                    {   
                        printf("\n\n");
                        communityscreen(inviter);
                        break;
                    }                      
             else
                {
                    printf("INVALID ENTRY , ENTER AGAIN\n");
                    break;
                }    
       }  
        
    }    

}

//The existing community screen process of verifying and loading screen
void existingcommunityscreen(char* inviter)
{   
    char communityname[100];
    List *head ;
    char input ;
    printf("WELCOME TO EXISTING COMMUNITY SCREEN :\n");
    printf("ENTER 1 IF YOU WANT OPEN A COMMUNITY :\n");
    printf("ENTER 2 IF YOU WANT TO KNOW CREATE A NEW COMMUNITY :\n");
    printf("ENTER 3 TO LOGOUT :\n");
    printf("ENTER 4 TO EXIT :\n");
    fflush(stdin);

       while(1)
       {
           scanf("%c",&input);
           fflush(stdin);
           switch (input)
           {
           case '1':

              while(1)
              { 
                 printf("ENTER THE NAME OF YOUR COMMUNITY :\n");
                 scanf("%s",communityname);

                  if(communitycheck(communityname)) // This function is called to check whether the community exists
                {   
                    printf("\n\n");
                    head = loadfunction(communityname); // calling the load function to load data from the file into the linked list
                    printf("Data loaded successfully \n\n");
                    operations(head,communityname,inviter); // Calling Operations to execute tasks like addition , deletion etc. 
                    break;
                }
                 else
                    {
                        printf("This File is not present , Please enter again :\n");
                    }   
              }  
            case '2': 
                printf("\n\n");
                startcreation(inviter);
                break;

            case '3':
                printf("\n\n");
                secondscreen();
                break;

            case '4':
                exit(0);
                break;

           default:
              printf("INVALID INPUT, TRY AGAIN\n");
           }
       } 


}

//******************************************OPERATIONS EXECUTED ON LINKED LIST**************************//

//menu driven screen asking the users about what all he wants to
void operations(List* head,char* communityname,char* inviter)
{   
    int input;
    char who[100],username[100];

    while(1)
    {   
        printf("PRESS 1 TO VIEW EXISTING MEMBERS OF THE COMMUNITY :\n");
        printf("PRESS 2 TO ADD MEMBERS IN THE COMMUNITY :\n");
        printf("PRESS 3 TO DELETE MEMBER IN THE COMMUNITY :\n");
        printf("PRESS 4 TO SAVE YOUR DATA BACK TO A FILE :\n");
        printf("PRESS 5 TO LIST ALL THE MEMBERS WHO WERE ADDED BY THE SAME PERSON :\n");
        printf("PRESS 6 TO DISPLAY THE DATA OF A PERSON \n");
        printf("PRESS 7 TO GO BACK :\n");
        printf("PRESS 8 TO EXIT :\n");

        while(1)
        {   
            scanf("%d",&input);
            if(input == 1)
            {   
                printf("\n\n");
                printlist(head);
                break;
            }
            else if(input == 2)
            {
                printf("ENTER THE USERNAME :");
                scanf("%s",username);
                if(isuserpresentincommunity(username,head)) //username not be there in community
                {   
                    if(checkusername(username)) //username should be existing in our database
                    {   
                        printf("\n\n");
                        head = addmembers(head,username,inviter);   // addtion of members
                        break; 
                    }
                    else
                    {
                        printf("This username is not a member of the Facebook Platform\n");
                    }
                } 
                else
                {
                     printf("This member is already present in the community \n");
                     break;
                } 
            }
            else if(input == 3)
            {
                printf("ENTER THE USERNAME YOU WANT TO DELETE :\n");
                scanf("%s",username);
                printf("\n\n");
                head = delete(head,username);  // calling the delete function to delete the details of a username from the linked list
                break;
               
            }
            else if(input == 4)
            {
                if(savetofile(head,communityname))  // saving the updated data back to a file
                {   
                    printf("\n\n");
                    printf("DATA HAS BEEN SAVED SUCCESSFULLY\n");
                    break;
                }
            }
            else if(input == 5)  
            {   
                printf("Enter the username for whom u want to know :\n");
                scanf("%s",who);
                if(whoaddedwhom(who,communityname))  // calling functions to find out the members invited by the same person
                { 
                    break;
                }
                else
                {
                    printf("This member did not add anyone yet :\n");
                    break;
                }
                
            }
            else if(input == 6) //printing specific details of a person
            {
                printf("Please enter the username of the person for whom u want to know the details :");
                if(printdetails(head,username))
                {
                    printf("\n");    
                }
                else
                {
                    printf("Could Not find that member :\n");
                }
                break;
                
            }
            else if(input == 7)
            {   
                printf("\n\n");
                existingcommunityscreen(inviter);
                fflush(stdin);
                break;
            }
            else if(input == 8)
            {   
                exit(0); 
            }
        }
    }
}

//Load function copies the data from the file in the linked list
List* loadfunction(char* communityname)
{   
    struct details S1;
    List *head = NULL;
    
    FILE *file;
    file = fopen(communityname,"r");           // opening the file
        if(file==NULL)
            {
                printf("Error!");   
                exit(1);    
            }

        while(!feof(file))
        {   // creating the linked list and copying data from the file 
            fscanf(file,"%s %s %s %s %d %d %d %d %s\n",S1.firstname,S1.lastname,S1.nickname,S1.birthplace,&S1.dob.dd,&S1.dob.mm,&S1.dob.yy,&S1.age,S1.inviter); 
            List *p = (List*) malloc(sizeof(List));
            strcpy(p ->d.firstname,S1.firstname);
            strcpy(p ->d.lastname,S1.lastname);
            strcpy(p ->d.nickname,S1.nickname);
            strcpy(p ->d.birthplace,S1.birthplace);
            p ->d.age = S1.age;
            p ->d.dob.dd = S1.dob.dd;
            p ->d.dob.mm = S1.dob.mm;
            p ->d.dob.yy = S1.dob.yy;
            strcpy(p ->d.inviter,S1.inviter);
            p ->next = head;
            head = p;

        }
        return head;
}

//add members the linked list 
List* addmembers(List* head, char* username,char* inviter)
{   
    struct details d,S1;
    FILE *file;
    file = fopen("Members.txt","r");           // opening the file
        if(file==NULL)
            {
                printf("Error!");   
                exit(1);    
            }
    //reading data from a file 
    fscanf(file,"%s %s %s %s %d %d %d %d %s",S1.firstname,S1.lastname,S1.nickname,S1.birthplace,&S1.dob.dd,&S1.dob.mm,&S1.dob.yy,&S1.age,S1.password); 
    
    while(!feof(file))
        {   // finding the exact data through key field 
            if(strcmp(S1.nickname,username)== 0)
            {
                break; //if found
            }
        fscanf(file,"\n%s %s %s %s %d %d %d %d %s",S1.firstname,S1.lastname,S1.nickname,S1.birthplace,&S1.dob.dd,&S1.dob.mm,&S1.dob.yy,&S1.age,S1.password); 
                
        }

    // Addition of that members at the head 
    List *p = (List*) malloc(sizeof(List));
    strcpy(p ->d.firstname,S1.firstname);
    strcpy(p ->d.lastname,S1.lastname);
    strcpy(p ->d.nickname,S1.nickname);
    strcpy(p ->d.birthplace,S1.birthplace);
    p ->d.age = S1.age;
    p ->d.dob.dd = S1.dob.dd;
    p ->d.dob.mm = S1.dob.mm;
    p ->d.dob.yy = S1.dob.yy;
    strcpy(p ->d.inviter,inviter);
    p ->next = head;
    head = p;

    fclose(file);
    return head;
}

//Print all details of a specific person 
int printdetails(List* head,char* username)
{   
    struct details d;
    List *p ;
     for(p = head; p!= NULL ; p = p->next)
     {  
        if(strcmp(username,p->d.nickname)==0)
        {
            printf("%s ", p ->d.firstname);
            printf("%s ", p ->d.lastname);
            printf("%s ", p ->d.nickname);
            printf("%s ", p ->d.birthplace);
            printf("%d ", p ->d.dob.dd);
            printf("%d ", p ->d.dob.mm);
            printf("%d ", p ->d.dob.yy);
            return 1;
        }
        
     }
    free(p);
     return 0;
}

//This function is called who all were invited by the same person 
int whoaddedwhom(char* who,char* communityname)
{  
    int flag=0; 
    struct details S1;
    FILE *m;
    m = fopen(communityname,"r");           // opening the file
        if(m == NULL)
            {
                printf("Error!");   
                exit(1);    
            }

        fscanf(m,"%s %s %s %s %d %d %d %d %s",S1.firstname,S1.lastname,S1.nickname,S1.birthplace,&S1.dob.dd,&S1.dob.mm,&S1.dob.yy,&S1.age,S1.inviter); 
    
       while(!feof(m))
       {    
           if(strcmp(S1.inviter,who)==0)
           {    
               flag++;
               printf("%s\n",S1.nickname);
           }

         fscanf(m,"%s %s %s %s %d %d %d %d %s",S1.firstname,S1.lastname,S1.nickname,S1.birthplace,&S1.dob.dd,&S1.dob.mm,&S1.dob.yy,&S1.age,S1.inviter); 
    
       }

    return flag;

}

// Delete Members from the list 
List *delete(List* head,char* username)
{   
    struct details d;
    List * p = head ;
 if (head == NULL) return head ; // checking if list is already empty

 if (strcmp(head -> d.nickname,username) == 0) // if the first element is the one that we want to delete
    {
        List *p = head ;
        head = head -> next ;
        free (p);
        return head;
    }
        List *cur;
        cur = head ;
        while (cur -> next -> next != NULL )
        {
            cur = cur -> next ;
        } 
        if(strcmp(cur->next->d.nickname,username)==0)
        {
            free (cur -> next );
            cur -> next = NULL;
            return head;
        }

   while ((p != NULL) &&  (strcmp( p -> next -> d.nickname,username) == 1)) //iterating till the end to find the guy to be deleted
            {     
                 p = p -> next ;
            } 
            if (p->next != NULL )
            {   
                List *q = p->next;
                p -> next = q -> next ;
                free (q);
            }
    
   
    return head ;


}

//Save data back to file 
int savetofile(List* head , char* communityname)
{   
    struct details d;
     FILE *file;
     file = fopen(communityname,"w");  
     if(file==NULL)
            {
                printf("Error!");   
                return 0;   
            } 
    List *p ;
        p = head;


     for(p = head;p!= NULL;p = p->next)
     {
         fprintf(file,"%s ",p->d.firstname);
         fprintf(file,"%s ",p->d.lastname);
         fprintf(file,"%s ",p->d.nickname);
         fprintf(file,"%s ",p->d.birthplace);
         fprintf(file,"%d ",p->d.dob.dd);
         fprintf(file,"%d ",p->d.dob.mm);
         fprintf(file,"%d ",p->d.dob.yy);
         fprintf(file,"%d ",p->d.age);
         fprintf(file,"%s\n",p->d.inviter);

     }

    fclose(file);
    free(p);
    
    return 1;
}

//Print list of all members
void printlist(List* head)
{   
    struct details d;
     List *p ;
    if(head == NULL)
    {
        printf("No members have been added :\n");
    }
         
     for(p = head; p!= NULL ; p = p->next)
     {
         printf("%s ", p ->d.nickname);
         printf("\n");
     }

        free(p);

}

//********************************************VALIDATIONS***************************************************//

// to make sure that the same username is not added twice 
int isuserpresentincommunity(char* username,List* head)
{   
    // struct details m;
    List* p;
    int check=0;
    

    if (head==NULL)
    {
        return 1;
    }
    

    if(head!=NULL)
    {
        for(p = head; p!= NULL ; p = p->next)
        {
            if(strcmp(p->d.nickname,username)==0)
            {
                check++;
                return 0;
            }
        }

    }   
       
          return 1;

}

//To check the credeentails of the user during login
int checklogin(char *loginid, char *password)
{   
   struct details S1;

    int a = 0;
    //open file read till end of file and compare if the nickanme and password are equal, send 1 else 0;
     FILE *fp;

    fp = fopen("Members.txt","r");           // opening the file
            if(fp==NULL)
            {
                 printf("Error!");   
                 exit(1);    
            }

         fscanf(fp,"%s %s %s %s %d %d %d %d %s",S1.firstname,S1.lastname,S1.nickname,S1.birthplace,&S1.age,&S1.dob.dd,&S1.dob.mm,&S1.dob.yy,S1.password); 
                
        while(!feof(fp))
        {   

            if(strcmp(loginid,S1.nickname) == 0 && strcmp(password,S1.password)== 0)
                    { int x;
                        x++;

                        a =1;
                        return a;
                    }

            fscanf(fp,"\n%s %s %s %s %d %d %d %d %s",S1.firstname,S1.lastname,S1.nickname,S1.birthplace,&S1.age,&S1.dob.dd,&S1.dob.mm,&S1.dob.yy,S1.password); 
                
        }

    fclose(fp);
     return a ;

}

//To check whether the user name is in the Main database(members.txt)
int checkusername(char *username)
{   
    struct details S1;
    FILE *p;
    p = fopen("Members.txt","r");
    
     if(p==NULL)
            {
                 printf("Error!");   
                 exit(1);    
            }

    fscanf(p,"%s %s %s %s %d %d %d %d %s",S1.firstname,S1.lastname,S1.nickname,S1.birthplace,&S1.dob.dd,&S1.dob.mm,&S1.dob.yy,&S1.age,S1.password);
    
    while(!feof(p))
    {
        if(strcmp(S1.nickname,username)==0)
        {
            return 1;
        }

         fscanf(p,"\n%s %s %s %s %d %d %d %d %s",S1.firstname,S1.lastname,S1.nickname,S1.birthplace,&S1.dob.dd,&S1.dob.mm,&S1.dob.yy,&S1.age,S1.password);
    
    }

    fclose(p);

    return 0;

}

//To check the existence of of the community
int communitycheck(char* communityname)
{   
    FILE *file;

   if (file = fopen(communityname, "r")) 
   {  
      fclose(file);
      return 1;
   } 
   else 
   {
      return 0;
   }
}