# facebookLike

Introduction:
Facebook is a community-based platform designed to connect people. It is a user-friendly interactive menu driven project, involving extensive use of file handling and dynamic memory handling. I have made use of linked list in the project. It involves use of hardcore topics like pointers, functions etc. The key field/ primary key in the project is Nickname/User’s Login ID.
Why Linked List?
Since we have different data for each member (first name, last name etc.) and we are not sure about how many people will be added in a community, linked list is used. By having a random number as the array’s limit, we would be wasting a lot memory. So, an efficient solution would be to use linked List where each element of list consists of all the data of a member. This way it is easy to load it from the file as well as perform operations on it.
The project is basically divided into three major parts:
• The login Process:
• The community Creation Process:
• Opera tions:
Login Process:
Firstly, in order to execute the project, we needed to make sure that the user should be registered to our platform in order to make the project sound and more authentic. In order to develop that, I have created a login portal, which allows the existing users to login into the Facebook platform. It also allows new users to make their new accounts. This process has a set of validations involved with it to make sure that the program does not fail during edge cases. The user has to enter his/her login ID/Nickname and password. The login/Nickname, our primary key, is used to identify each user uniquely. After verification of the login ID and Password from our file “members.txt” the user is made to go further.
Community Creation:
The Community creation process is divided into two parts: New community creation and existing communities. Facebook-Users can create their own communities with their own choice of name. They can add existing Facebook- users in community by their Nickname. This operation of addition is executed on the linked list, the data is stored to a file on user’s command.
The user can access an existing community as well by entering its name. Since we cannot have two communities with the same name, the community name has to be unique to avoid confusion and bugs.
Opera ti ons :
This is the most important part of the project. It involves the use of all major tasks like loading of data, addition, deletion of members. Operations like, printing the details of a specific user, finding out members who were invited by the same person, finally saving the data etc. can be easily carried out on linked List. The details of the working of each task will be explained further.
Structure of the Project:
Description of Code:
The source code divides the projects into screens like the flash screen, login screen, community screen etc. The important functions and validations are made in separate user defined functions so that we do not have to rewrite the code again. The source code is well guided with descriptive comments to ease the task during evaluation.
Functions in the Code:
 
The functions listed below are in the chronological order of how the program will run:
➢ Login Process
➢ Community: void communityscreen(char* inviter);
➢Operations:
➢ Validations:
Description of Functions and Algorithm for Implementation:
➢ Main Screen:
The function ‘mainscreen’ do not take in any parameters or return anything. It is used to basically display our flash screen. This function is called inside the ‘int main’ function in order to commence the program.
➢ Second Screen:
This function doesn’t have any return input or in any parameters. In this function we ask the user if he/she is an existing user or a new user. Based on the input we take the user to the demanded screens namely “newlogin” and “existinglogin”.
➢NewLogin:
➢ void mainscreen();
 ➢ void secondscreen();
  o int newlogin();
 o void existinglogin();
 o void startcreation(char* inviter);
 o void existingcommunityscreen(char* inviter);
 o void operations(List* head,char* communityname,char* inviter);
 o List* loadfunction(char* communityname);
 o List* addmembers(List* head, char* username,char* inviter);
 o int printdetails(List* head,char* username);
 o int whoaddedwhom(char* who,char* communityname);
 o List* delete(List* head,char* username);
 o int savetofile(List* head , char* communityname);
 o void printlist(List* head);
 o int isuserpresentincommunity(char* username,List* head);
 o int checklogin(char *loginid, char *password);
 o int checkusername(char *username);
 o int communitycheck(char* communityname);

This function does not take in any input but returns 1 to the “secondscreen”. This function registers the user to the main database of members i.e., “membrs.txt”. The Algorithm to execute this function includes opening the file in append mode to enter users personal details like first name , last name etc. After taking in the value of Nickname we call the function “checkusername”. In this function we open our database i.e., “members.txt” in read mode and look for this username, to make sure no one has taken that login ID to avoid any bugs.
➢ Existing login:
Though this function does not take any parameters or return anything. This function is important because it involves the login process of the existing user. It is called when the user chooses the option to login as an existing user in the “secondscreen”. In this function we ask the user to enter his/her Nickname/login Id and password. After which we call the “checklogin” function which takes the login ID and Password. It opens the file “members.txt” and searches for these two records, if both of them match then it returns 1 or else 0 value is returned.
➢ Community Screen:
After successfully verifying the credentials the user is taken to the “communityscreen”. This function takes the login id of the user as parameters which is required further. Over here we display a menu asking the user whether he wants to create a new community or Open an existing community. Based on the user’s input we take him/her to the required screen i.e., “startcreation” or “existingcommunity”.
➢ Start Creation:
Start Creation function does not return anything, it requires the username of the inviter as a parameter because while saving the records we need to save the record of the inviter as well. We ask the user as to what he/she wants to name his/her community. After the input we ask the user about the basic operations like addition of members, saving records by calling functions like “addmembers” and “savetofile”.
➢ Existing Community:
After successfully creating the community we can open our existing community. Here we ask the user about the name of the community and we check the existence of the community by calling the “checkcommunity” function to check whether this community exits or not. After this we ask the

user to chose if he wants to open the existing community, if the input is positive then we call the other “loadfunction” which loads the data from the file to the linked list. If the data was loaded successfully, we take the user further to the “operations” function.
➢Operations:
This is a menu driven function which asks the user to do what all functions he/she would like to perform. We can add, delete members, print all members of the community, print details of a specific member, find out the members who were invited by the same person. For each of these operations we have a separate function like “addmembers”, “delete”, “whoaddedwhom”, “printlist”, “printdetails”.
➢LoadFunction:
This function requires the community name as a parameter because we want to open that file in order to retrieve data from it to a linked list. This can be done by basically opening the given file in the ‘r’ mode. Since it is the load function, it also implies that the file should exist because in order to extract data from it. After opening the file, we will read till the end of the file and will copy those values in the structure of the linked list after each line we create a new node and add all the values in it like first name, last name etc. using the ‘strcmp’ function, except the password as the user should not be able to access someone else’s password. After successfully adding all records it returns the head pointer so that the list can be accessed.
➢AddMembers:
This function requires the head pointer of the list, username of the person who is supposed to be added, and the name of the inviter. Over here we open the file “members.txt”, read till the end and see whether the username of the person and the one we received in the parameters match. Then we add this data to the list at the head and return the head pointer.
➢Print details:
This function requires the head pointer and the username of the person of whom we want to print the details of. It starts a loop from the head till the end of the list and searches for the member. If it finds the details, then it gets printed and returns 1 and if they are not found then we return 0.
➢Whoaddedwhom:

This function requires two parameters the username of the person for whom we want to know who all he/she added, and the name of the community. In this function we open the community in ‘r’ mode and read till the end of file wherever the name of inviter matches the input of the username we display the username of that person.
This could also have been done on the linked list but the reason to execute it on a file is because the function operations consist of a while(1) loop which and all data in the linked list is subject to change. So, in order to print the final data we print the one which is saved inside the file
➢Delete:
This function is called in the operation function. It requires the head pointer of the list and the username of the person we want to delete. In the function we run the linked list till the end and search for that username and if we find it then it will be deleted or else we notify the user that the username is not yet let alone being deleted.
➢Savetofile:
This function requires the community name and the head pointer. In this function we open the file in the ‘w’ mood and by opening the file in this mood we clear the file every time we open it. After which we enter data in it by running a loop from the head of the pointer till the end.
➢ Print List:
This function requires the head of the list as parameters. In this we run a loop from the head of the list till the end and we print the usernames of the people,
➢ Validations
Validations have been included in the program to avoid breaking of code in case of edge cases. I have tried my best to avoid all types of validations. Below the validations are explained briefly
➢ Is Username present in community?
This function takes in two parameters username and the head of the list. This validation is required during addition of members, before adding members both times in “startcreation” as well as “operations”, we call this function to check whether this member is already present in the community to avoid any repetition. This function runs a loop from the head of the list to till the end

to see if we have a matching username that is already in the list, if yes then we don’t add them in the record.
➢ Check Login
This function is called once when we are trying to login in the “secondscreen”, it requires the login ID and password as parameters. It opens the file ‘members.txt’ in ‘r’ mode and compares the password and username. If both match, then the user is allowed to log in.
➢ Check username
This validation is used to check whether a username is present in the main
file ‘members.txt’ or not.
➢ Community check
This is used to make sure that the community name entered by the user is unique while creation, it is also called in the existing user screen. When we take input of the community screen from the user, it works by just opening the community file in the ‘r’ mode. Because in order to open a file in ‘r’ mode the file must exist.
Testing/ P rocedure
1. The screenshot below shows the terminal when the project is run, Initially the flash screen is displayed,
a. Press 1 to move forward.
2. After entering 1, if you are a new member press 1 or press 2 for new user and existing user login respectively.
a. Press 2
   
  3. After entering 1 on the previous input you have to enter some personal details namely (first name, last name, Birth place, Nickname, Date of birth, Age etc.)
3.1) After the successful creation of the account you have to login by entering your respective credentials(Nickname, Password).
CAUTION !!: Do Not Share your Nickname and Password with Anyone.
     
4. After finishing the login process, you see this, over here we start the second part of the structure i.e., the community creation process.
 4.1) After successfully creating the community, you can open our community under the “existing community category”. Over there you can enter the name of the community. And perform operations i it.
 
 
