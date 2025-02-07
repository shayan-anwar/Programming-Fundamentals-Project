#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
 struct date{
  int day,month,year;
};
struct{

	char pass[4];
	char name[20];
	struct date withdraw;
	struct date deposit;
	char address[100];
	char citizenship[20];
	float amount; 
	char phone[11];
	int id;
	struct date dob;
	struct date tdate;
	struct date send;
	char type[20];
	char account;
}display,user,trans,check,interest,upd,deposit,sender,receive,tmp1,tmp2,transfer;

int confirm(){
	int choice;
	printf("\nAre you sure you want to go through with this transaction?(Press 1 for YES and 2 for NO)");
	scanf("%d",&choice);
 	return choice;
}
//TO DISPLAY THE TRANSFERS MADE.
display_transfer(){
	int check = 0;
	FILE*trans;
	trans = fopen("Transaction.txt","r");
	if(fopen("Transaction.txt","r")==NULL){
		printf("\nFILE NOT FOUND!!!!!");
		exit(1);
	}
	for(;;){
		fflush(stdin);
		fscanf(trans,"%s %d %d %f %d/%d/%d",transfer.type,&sender.id,&receive.id,&sender.amount,&transfer.send.day,&transfer.send.month,&transfer.send.year);
		if (feof(trans)){
			break;
		}
		if(strcmp(transfer.type,"TRANSFER")==0){
			printf("%15s %4d %4d %7f %2d/%2d/%2d\n",transfer.type,sender.id,receive.id,sender.amount,transfer.send.day,transfer.send.month,transfer.send.year);
		}
	}
	fclose(trans);
	admin_cont();
}
//TO DISPLAY THE WITHDRAWALS MADE
display_withdraw(){
	int check = 0;
	FILE*trans;
	trans = fopen("Transaction.txt","r");
	if(fopen("Transaction.txt","r")==NULL){
		printf("\nFILE NOT FOUND!!!!!");
		exit(1);
	}
	for(;;){
		fflush(stdin);
		fscanf(trans,"%s %d %f %d/%d/%d",transfer.type,&sender.id,&sender.amount,&transfer.send.day,&transfer.send.month,&transfer.send.year);
		if (feof(trans)){
			break;
		}
		if(strcmp(transfer.type,"WITHDRAW")==0){
			printf("%15s %4d %7f %2d/%2d/%2d\n",transfer.type,sender.id,sender.amount,transfer.send.day,transfer.send.month,transfer.send.year);
		}
	}
	fclose(trans);
	admin_cont();
}
//TO DISPLAY THE DEPOSITS MADE.
display_deposits(){
	FILE*trans;
	trans = fopen("Transaction.txt","r");
	if(fopen("Transaction.txt","r")==NULL){
		printf("\nFILE NOT FOUND!!!!!");
		exit(1);
	}
	for(;;){
		fflush(stdin);
		fscanf(trans,"%s %d %f %d/%d/%d",transfer.type,&sender.id,&sender.amount,&transfer.send.day,&transfer.send.month,&transfer.send.year);
		if (feof(trans)){
			break;
		}
		if(strcmp(transfer.type,"DEPOSIT")==0){
			fflush(stdout);
			printf("%15s %4d %7f %2d/%2d/%2d\n",transfer.type,sender.id,sender.amount,transfer.send.day,transfer.send.month,transfer.send.year);
		}
		else{
			continue;
		}
	}
	fclose(trans);
	admin_cont();
}
//TO DISPLAY EVERY FORM OF TRANSATION MADE.
display_all(){
	int check = 0;
	char Line[500];
	FILE*trans;
	trans = fopen("Transaction.txt","r");
	if(fopen("Transaction.txt","r")==NULL){
		printf("\nFILE NOT FOUND!!!!!");
		exit(1);
	}
	for(;;){
		fflush(stdin);
		fgets(Line,sizeof Line,trans);
		if (feof(trans)){
			break;
		}
		puts(Line);
	
	}
	fclose(trans);
	admin_cont();
}
//MENU TO DISPLAY TRANSACTIONS
display_transactions(){
	int choice;
	printf("\t\t***TRANSACTIONS***\t\t\n");
	printf("1-Display Transfers\n2-Display Withdrawals\n3-Display Deposits\n4-Display All");
	scanf("%d",&choice);
	do{
		switch(choice){
			case 1:
				system("cls");
				display_transfer();
				break;
			case 2:
				system("cls");
				display_withdraw();
				break;
			case 3:
				system("cls");
				display_deposits();
				break;
			case 4: 
				system("cls");
				display_all();
				break;
			default:
				printf("WRONG CHOICE!!!!!");
		}
	}while(choice<1 || choice >4);
}
//TO ASK A USER IF THEY WISH TO GO BACK TO THE MAIN.
void user_cont(void){
	int choice;
	printf("\nPress 1 to go back to the menu and 0 to exit");
	do{
	
	scanf("%d",&choice);
	switch(choice){
		case 1:
			system("cls");
			user_menu();
			break;
		case 0:
			exit(1);
			break;
		default:
			printf("Wrong Choice Try Again");
	}
}while(choice!=0||choice!=1);
}
//TO ASK THE ADMIN WHETHER TO GO BACK TO THE MENU OR NOT.
void admin_cont(){
	int choice;
	printf("\nPress 1 to go back to the menu and 0 to exit");
	do{
	scanf("%d",&choice);
	switch(choice){
		case 1:
			system("cls");
			admin_menu();
			break;
		case 0:
			exit(1);
			break;
		default:
			printf("Wrong Choice Try Again");
	}
}while(choice!=0||choice!=1);
}
//CREATE A NEW ACCOUNT
void new_account(){
	int test;
	char account;
  	FILE *A;
	 A=fopen("accounts.txt","a+");
  	do{
  		test = 0;
 	printf("\nPLS ENTER A PIN : ");
	scanf("%d",&user.id);
	rewind(A);
	for(;;){
		fscanf(A,"%d %s %s %s %d/%d/%d %d/%d/%d %f %s %c",&check.id,check.name,check.address,check.citizenship,&check.tdate.day,&check.tdate.month,&check.tdate.year,&check.dob.day,&check.dob.month,&check.dob.year,&check.amount,check.phone,&check.account);
		if(feof(A)){
			break;
		}
		if(check.id==user.id){
			printf("\nUser Id already used");
			test=1;
		}
		
		}
	
	}while(test==1);
    printf("PLS ENTER YOUR NAME(NO SPACES): ");
	scanf("%s",user.name);
	printf("PLS ENTER YOUR ADDRESS: ");
	scanf("%s",user.address);
	printf("PLS ENTER YOUR CITIZENSHIP: ");
	scanf("%s",user.citizenship);
	printf("PLS ENTER YOUR PHONE NUMBER: ");
	scanf("%s",user.phone);
    printf("PLS ENTER TODAYS DATE <dd/mm/yyyy>: ");
	scanf("%d/%d/%d",&user.tdate.day,&user.tdate.month,&user.tdate.year);
	printf("ENTER YOUR DOB <dd/mm/yyyy> : ");
	scanf("%d/%d/%d",&user.dob.day,&user.dob.month,&user.dob.year);
	printf("ENTER THE AMOUNT YOU WANT TO DEPOSIT: Rs ");
	scanf("%f",&user.amount);
	printf("What type of account do you want to create: Savings(s),Current(c),Fixed Deposits(f): ");
	scanf(" %c",&user.account);
	switch (user.account)
	{
	  case 's':
	  case 'S':	
        printf("\aYOU HAVE CHOSEN SAVINGS ACCOUNT\n ");
        
		 break;
	 case 'c':
	 case 'C':	
	 	printf("\aYOU HAVE CHOSEN CURRENT ACCOUNT\n");
		break;
	 case 'f':
	 case 'F':	
	 	printf("\aYOU HAVE CHOSEN FIXED DEPOSIT ACCOUNT\n");
		break;
	default:
			printf("\nWrong Value");
}
    fprintf(A,"%d %s %s %s %d/%d/%d %d/%d/%d %.4f %s %c\n",user.id,user.name,user.address,user.citizenship,user.tdate.day,user.tdate.month,user.tdate.year,user.dob.day,user.dob.month,user.dob.year,user.amount,user.phone,user.account);
    fclose(A);
    user_cont();
    
}

//Delay
void fordelay(int i){
	int j,k;
	for(k=1;k<=i;k++){
		j=k;
	}
}

//Display Accounts
void display_accounts()
{
	system("cls");
 char Line[100];
 FILE *B;
 B=fopen("accounts.txt","r");
for(;;){
 fgets(Line,sizeof Line,B);
 	if(feof(B)){
		break;
	}
 puts(Line);
}
admin_cont();
}
//User displays their own details only
void user_display(void){
	int test = 1;
	FILE *D;
	printf("Enter your Id:  ");
	scanf("%d",&check.id);
	D = fopen("accounts.txt","r");
		if(D==NULL){
		printf("FIle Not Found");
		exit(1);
	}
	rewind(D);
	for(;;)
	
	{	
		fscanf(D,"%d %s %s %s %d/%d/%d %d/%d/%d %f %s %c",&display.id,display.name,display.address,display.citizenship,&display.tdate.day,&display.tdate.month,&display.tdate.year,&display.dob.day,&display.dob.month,&display.dob.year,&display.amount,display.phone,&display.account);
			if(feof(D)==1){
				break;
			}
			if(display.id==check.id){
				test = 0;
				printf("%-5s %-15s %-20s %-15s %-10s %-10s %-12s %-12s %-8s\n","ID","Name","Address","Citizenship","Created","DOB","Amount","Phone","Account");
				printf("%-5d %-15s %-20s %-15s %-2d/%-2d/%-2d %-2d/%-2d/%-2d %-7.1f %-12s %c",display.id,display.name,display.address,display.citizenship,display.tdate.day,display.tdate.month,display.tdate.year,display.dob.day,display.dob.month,display.dob.year,display.amount,display.phone,display.account);
				
				break;
			}
			else{
				continue;
			}
			
	}
	
	if(test==1){
		printf("\nAccount not found");
	}
	fclose(D);
	user_cont();
}
//Admin Menu
void admin_menu(){
	int choice;
	system("color 1a");
	printf("\n\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FAST(NUCES) Bank \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n\n");
	printf("\t\t\t1-Display Transactions.\n");
	printf("\t\t\t2-Display account names and details.\n");
	printf("Press 0 to exit the program\n");
	do{
	scanf("%d",&choice);
	switch(choice){
		case 1:
			system("cls");
			display_transactions();
			break;
		case 2:
			display_accounts();
			break;
		case 0:
			exit(1);
			break;
		default:
			printf("Wrong choice!! ");			
	}	
}while(choice<0 || choice>2);
	
}
//USER CHANGES THEIR OWN ACCOUNT DETAILS
void user_update(void){


    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("accounts.txt","r");
    newrec=fopen("newaccounts.txt","w");

    printf("\nEnter your account number:");
    scanf("%d",&check.id);
    for(;;)
    {
    
		fflush(stdin);
    	fscanf(old,"%d %s %s %s %d/%d/%d %d/%d/%d %f %s %c",&user.id,user.name,user.address,user.citizenship,&user.tdate.day,&user.tdate.month,&user.tdate.year,&user.dob.day,&user.dob.month,&user.dob.year,&user.amount,user.phone,&user.account);
    	if(feof(old)){
    		break;
		}
        if (check.id==user.id)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Citizenship\n3.Phone\n\nEnter your choice(1 for address and 2 for Citizenship):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {
				printf("Enter the new address:");
                scanf("%s",&upd.address);
                fflush(stdout);
                fprintf(newrec,"%d %s %s %s %d/%d/%d %d/%d/%d %.1f %s %c\n",user.id,user.name,upd.address,user.citizenship,user.tdate.day,user.tdate.month,user.tdate.year,user.dob.day,user.dob.month,user.dob.year,user.amount,user.phone,user.account);
				system("cls");
                printf("Changes saved!");
                
                }
            else if(choice==2)
                {
                printf("Enter your new Citizenship:");
                scanf("%s",upd.citizenship);
                fflush(stdout);
                fprintf(newrec,"%d %s %s %s %d/%d/%d %d/%d/%d %.1f %s %c\n\n",user.id,user.name,user.address,upd.citizenship,user.tdate.day,user.tdate.month,user.tdate.year,user.dob.day,user.dob.month,user.dob.year,user.amount,user.phone,user.account);              
			    system("cls");
                printf("Changes saved!");
                
                }
                else if(choice==3){
                	printf("Enter your new phone number:");
                	scanf("%s",upd.phone);
                	fflush(stdout);
                	fprintf(newrec,"%d %s %s %s %d/%d/%d %d/%d/%d %.1f %s %c\n\n",user.id,user.name,user.address,user.citizenship,user.tdate.day,user.tdate.month,user.tdate.year,user.dob.day,user.dob.month,user.dob.year,user.amount,upd.phone,user.account);              
			   	 	system("cls");
                	printf("Changes saved!");
				}
        }
        else{
        fflush(stdout);
         fprintf(newrec,"%d %s %s %s %d/%d/%d %d/%d/%d %.1f %s %c\n\n",user.id,user.name,user.address,user.citizenship,user.tdate.day,user.tdate.month,user.tdate.year,user.dob.day,user.dob.month,user.dob.year,user.amount,user.phone,user.account);
    }
	}
   fclose(old);
   fclose(newrec);
    remove("accounts.txt");
    rename("newaccounts.txt","accounts.txt");
if(test!=1)
        {   
		system("cls");
            printf("\nRecord not found!!\a\a\a"); 
}
	user_cont();
}

void user_withdraw()
{
   int choice,test=0,withdraw;
   char type[20] = "Withdraw";
   FILE *old,*tran,*tmp;
   old=fopen("accounts.txt","r");
   tran=fopen("Transaction.txt","a");
   tmp = fopen("temp.txt","w");
    printf("\nEnter the account no. of the customer for withdrawing");
    scanf("%d",&check.id);
    for(;;)
    {	
    	
    	
		fflush(stdin);
    	fscanf(old,"%d %s %s %s %d/%d/%d %d/%d/%d %f %s %c",&trans.id,trans.name,trans.address,trans.citizenship,&trans.tdate.day,&trans.tdate.month,&trans.tdate.year,&trans.dob.day,&trans.dob.month,&trans.dob.year,&trans.amount,trans.phone,&trans.account);
    	if(feof(old)){
    		break;
		}
    
        if (check.id==trans.id)
        {   
       	 test = 1;
       	 printf("The Total Balance in Your Account is : %.2f",trans.amount);
         
         
         do{
        printf("\nAmount You want to withdraw");
		 scanf("%d",&withdraw);
         user.amount = trans.amount - withdraw;
		 if (withdraw <= trans.amount )
			{	
		  printf("PLS ENTER TODAYS DATE <dd/mm/yyyy>: ");
	      scanf("%d/%d/%d",&trans.withdraw.day,&trans.withdraw.month,&trans.withdraw.year);
	      if(confirm()==2){
	      	fclose(old);
			fclose(tran);
			fclose(tmp);
			remove("temp.txt");
			system("cls");
			user_menu();      	
		  }
		  printf("Successfully Withdrawn! Thank You!!");
          fprintf(tran,"%15s %4d %7d %2d/%2d/%2d\n","WITHDRAW",trans.id,withdraw,trans.withdraw.day,trans.withdraw.month,trans.withdraw.year);
          fprintf(tmp,"%d %s %s %s %d/%d/%d %d/%d/%d %f %s %c\n",trans.id,trans.name,trans.address,trans.citizenship,trans.tdate.day,trans.tdate.month,trans.tdate.year,trans.dob.day,trans.dob.month,trans.dob.year,user.amount,trans.phone,trans.account);
			}
		 else
		 {
		  printf("\nWithdraw Amount is more than amount in the account!! Try Again ");  
	}
}while(withdraw > trans.amount);
		  
}
else{
	fprintf(tmp,"%4d %20s %40s %15s %2d/%2d/%2d %2d/%2d/%2d %10f %s %c\n",trans.id,trans.name,trans.address,trans.citizenship,trans.tdate.day,trans.tdate.month,trans.tdate.year,trans.dob.day,trans.dob.month,trans.dob.year,trans.amount,trans.phone,trans.account);
}
}

    fclose(old);
	fclose(tmp);
	fclose(tran);
	remove("accounts.txt");
	rename("temp.txt","accounts.txt");
if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            exit(1);

               
}

	user_cont();
}

void user_deposit()
{
   int choice,test=0,deposit;
   FILE *old,*tran,*tmp;
   old=fopen("accounts.txt","r");
   tran=fopen("Transaction.txt","a");
   tmp = fopen("temp.txt","w");
    printf("\nEnter the account no. of the customer for depositing");
    scanf("%d",&check.id);
    for(;;)
    {	
    	
    	
		fflush(stdin);
		fscanf(old,"%d %s %s %s %d/%d/%d %d/%d/%d %f %s %c",&trans.id,trans.name,trans.address,trans.citizenship,&trans.tdate.day,&trans.tdate.month,&trans.tdate.year,&trans.dob.day,&trans.dob.month,&trans.dob.year,&trans.amount,trans.phone,&trans.account);
    	if(feof(old)){
    		break;
	}
    
        if (check.id==trans.id)
        {   
       	 test = 1;
       	 printf("The Total Balance in Your Account is : %.2f",trans.amount);
         
         
        
        printf("\nAmount You want to deposit");
		 scanf("%d",&deposit);
         user.amount = trans.amount + deposit;
		  printf("PLS ENTER TODAYS DATE <dd/mm/yyyy>: ");
	      scanf("%d/%d/%d",&trans.deposit.day,&trans.deposit.month,&trans.deposit.year);
	       if(confirm()==2){
	      	fclose(old);
			fclose(tran);
			fclose(tmp);
			remove("temp.txt");
			system("cls");
			user_menu();      	
		  }
		  printf("Successfull deposit\n! Thank You!!");
          fprintf(tran," %15s %4d %7d  %2d/%2d/%2d\n","DEPOSIT",trans.id,deposit,trans.deposit.day,trans.deposit.month,trans.deposit.year);
          fprintf(tmp,"%d %s %s %s %d/%d/%d %d/%d/%d %f %s %c\n",trans.id,trans.name,trans.address,trans.citizenship,trans.tdate.day,trans.tdate.month,trans.tdate.year,trans.dob.day,trans.dob.month,trans.dob.year,user.amount,trans.phone,trans.account);
	  }

else{
	fprintf(tmp,"%d %s %s %s %d/%d/%d %d/%d/%d %f %s %c\n",trans.id,trans.name,trans.address,trans.citizenship,trans.tdate.day,trans.tdate.month,trans.tdate.year,trans.dob.day,trans.dob.month,trans.dob.year,trans.amount,trans.phone,trans.account);
}
}

    fclose(old);
	fclose(tmp);
	fclose(tran);
	remove("accounts.txt");
	rename("temp.txt","accounts.txt");
if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
}
	user_cont();
}


void user_transfer(){
	int choice,test_1=0,test_2=0,transfer,receiver;
   FILE *old,*tran,*tmp,*tmpsnd;
   old=fopen("accounts.txt","r");
   tran=fopen("Transaction.txt","a");
   tmp = fopen("temp.txt","w");
   tmpsnd = fopen("SendReceive.txt","w+");
    chk:
		printf("\nEnter Your Account Number");
    	scanf("%d",&check.id);
   
    
    for(;;){
    	fflush(stdin);
    	fscanf(old,"%d %s %s %s %d/%d/%d %d/%d/%d %f %s %c",&trans.id,trans.name,trans.address,trans.citizenship,&trans.tdate.day,&trans.tdate.month,&trans.tdate.year,&trans.dob.day,&trans.dob.month,&trans.dob.year,&trans.amount,trans.phone,&trans.account);
    	
    	if(feof(old)){
    		break;
	}
	if(check.id==trans.id){
		test_1=1;
			do{
			printf("\nEnter the account number of the receipient");
			scanf("%d",&receiver);
			if(receiver==check.id){
				printf("AMOUNT CAN ONLY BE TRANSFERRED TO A DIFFERENT ACCOUNT");
			}
		}while(receiver==check.id);
		printf("\nThis is the current amount in your account: %7.1f",trans.amount);
		rewind(old);//Resets the pointer to the start of the file.
		for(;;){
			fscanf(old,"%d %s %s %s %d/%d/%d %d/%d/%d %f %s %c",&receive.id,receive.name,receive.address,receive.citizenship,&receive.tdate.day,&receive.tdate.month,&receive.tdate.year,&receive.dob.day,&receive.dob.month,&receive.dob.year,&receive.amount,receive.phone,&receive.account);
			if(feof(old)){
    		break;
			}

			if(receiver==receive.id){
				test_2 = 1;
				do{
				printf("\nENTER THE AMOUNT YOU WANT TO TRANSFER");
				scanf("%d",&transfer);
			}while(transfer>trans.amount);
				if(transfer< trans.amount){
					trans.amount = trans.amount - transfer;
					receive.amount = receive.amount + transfer;
					 printf("PLS ENTER TODAYS DATE <dd/mm/yyyy>: ");
	      			scanf("%d/%d/%d",&trans.deposit.day,&trans.deposit.month,&trans.deposit.year);
	      			if(confirm()==2){
	      				fclose(old);
	      				fclose(tmp);
	      				fclose(tmpsnd);
	      				remove("SendReceive.txt");
	      				remove("temp.txt");
	      				system("cls");
	      				user_cont();
					  }
	      			fprintf(tmpsnd,"%4d %10f\n",trans.id,trans.amount);
		  			fprintf(tmpsnd,"%4d %10f\n",receive.id,receive.amount);
					fprintf(tran,"%15s %4d %4d  %7d %2d/%2d/%2d\n","TRANSFER",trans.id,receive.id,transfer,trans.deposit.day,trans.deposit.month,trans.deposit.year);
					printf("AMOUNT SUCCESSFULLY TRANSFERRED\nTHANK YOU FOR USING OUR SERVICES!!");
						
				}
			}
	
}
	if(test_2==0){
		printf("\nRECEIPIENT ACCOUNT NOT FOUND.PLZ RE-ENTER");
		system("cls");
		user_transfer();
	}
			
	}
	}
	if(test_1==0){
		printf("\nSENDER ACCOUNT NOT FOUND!!!.PLZ RETRY");
		system("cls");
		user_transfer();
	}
	
	rewind(old);
	for(;;){
		fscanf(old,"%d %s %s %s %d/%d/%d %d/%d/%d %f %s %c",&tmp1.id,tmp1.name,tmp1.address,tmp1.citizenship,&tmp1.tdate.day,&tmp1.tdate.month,&tmp1.tdate.year,&tmp1.dob.day,&tmp1.dob.month,&tmp1.dob.year,&tmp1.amount,tmp1.phone,&tmp1.account);
		if(feof(old)){
			break;
		}
		rewind(tmpsnd);
		for(;;){
			fflush(stdin);
			fscanf(tmpsnd,"%d %f",&tmp2.id,&tmp2.amount);
			if(feof(tmpsnd)){
				break;
			}
			if(tmp2.id==tmp1.id){
				tmp1.amount = tmp2.amount;
			}
			else{
				continue;
			}
		}
		fprintf(tmp,"%d %s %s %s %d/%d/%d %d/%d/%d %f %s %c\n",tmp1.id,tmp1.name,tmp1.address,tmp1.citizenship,tmp1.tdate.day,tmp1.tdate.month,tmp1.tdate.year,tmp1.dob.day,tmp1.dob.month,tmp1.dob.year,tmp1.amount,tmp1.phone,tmp1.account);
	}
	fclose(old);
	fclose(tmp);
	fclose(tmpsnd);
	remove("SendReceive.txt");
    remove("accounts.txt");
	rename("temp.txt","accounts.txt");
	
	user_cont();
}
   

void user_menu(void)
{	
	int choice;
	system("color 1b");
	printf("\n\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FAST(NUCES) Bank \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n\n");
	printf("\t\t\t1-Create a new account.\n");
	printf("\t\t\t2-Change the details of your existing account.\n");
	printf("\t\t\t3-See your account details.\n");
	printf("\t\t\t4-Withdraw amount\n");
	printf("\t\t\t5-Deposit Amount.\n");
	printf("\t\t\t6-Transfer Amount.\n\n\n\n");
	printf("Press 0 to exit the program\n");
	do{
	scanf("%d",&choice);
	switch(choice){
		case 1:
			system("cls");
			printf("*New Account*\n");
			new_account();
	
			break;
		case 2:
			system("cls");
			user_update();
		
			break;
		case 3:
			system("cls");
			user_display();
			
			
			break;
		case 4:
			system("cls");
			user_withdraw();
			printf("Withdraw");
			break;
		case 5:
			system("cls");
			user_deposit();
			printf("deposit");
			break;
		case 6:
			system("cls");
			user_transfer();
		case 0:
			exit(1);
			break;
		default:
			printf("Wrong choice!! ");			
	}
	
}while(choice<0 || choice>6);
	
	
	
	
}
int main(void){
	int i,k;
	char pass[15] = "Hello World";
	char p[15];
	char ad_user_choice;
	printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	system("color 3f");
	printf("\n\n\n\n\t\tTHIS PROJECT IS MADE BY: AHMED MUSTAFA(3370)\n\t\t\t\t\t AAQIB ASLAM(4920)\n\t\t\t\t\t SHAYAN ANWAR(4836) \n\t\t\t\t\t ISRAR AYOUB(4521) ");
    getch();
    system("cls");
	printf("\n\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FAST(NUCES) Bank \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n\n");
	printf("Loading!! Please Wait");
	for(k=1;k<=10;k++){
	
	for(i=1;i<=6;i++){
	
	fordelay(10000000);
	
}	
	
	printf(" . ");
}
	
	printf("\nPress any key to continue");
	getch();
	
	system("cls");
		do{
			system("cls");
	printf("\n\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FAST(NUCES) Bank \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n\n");
	printf("\t\t\tEnter whether you are Admin or User (A or U): ");
	scanf("%c",&ad_user_choice);
	switch (toupper(ad_user_choice)){
		case 'A':
			
			do{
			system("cls");
			printf("\n\n\n\n\n\t\t\t\t\tEnter the password: ");
			gets(p);
			if(strcmp(p,pass)==0){
				system("cls");
				admin_menu();
			}
			else{
				system("cls");
				printf("\nRe-enter");
			}
		}while(strcmp(p,pass)!=0);
		system("cls");
		admin_menu();
			break;
		case 'U':
			system("cls");
			user_menu();
			break;
	}
	
}while(toupper(ad_user_choice)!='A'&&toupper(ad_user_choice)!='U');
}
