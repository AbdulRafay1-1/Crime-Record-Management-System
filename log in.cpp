#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define FILENAME "records.dat"

// Structure For Crime Records
typedef struct {
	int caseID ;
	char criminalName[50] ;
	char crimeType[50] ;
	char crimeLocation[50] ;
	char date[20] ;
	char caseStatus[50] ;
}CrimeRecord;

  int login(); //login function new
  void addRecord();
  void deleteRecord();    //delete function
  int loadFromFile(CrimeRecord*);
  
  int main(){

	int choice,caseID;
	
	while (1){
		printf("\n---Crime Records Management System---\n");
		printf("1.Add crime records\n");
		printf("2.View All Records\n");
		printf("3.Search by case ID\n");
		printf("4.Delete Records\n");
		printf("5.Exit\n");
		
		printf("Enter your choice: ");
		
		if (scanf("%d",&choice) !=1){
			printf("Invalid input! please enter a valid number.\n");
			while (getchar() != '\n');// clear invalid input
			continue;
		}
		switch (choice){
			case 1: addRecord();
			break;
			case 2: viewRecord();
			break;
			case 3: 
			printf("Enter case Id to search:");		
	    	if(scanf("%d",&caseId) !=1){
				printf("Invalid input! please enter a valid number.\n");
				while(grtchar()!='\n');//clear buffer
				continue;
			}
			searchByCaseID(caseID);
			break;
			case 4: deleteRecord();
			break;
			case 5: 
			printf("Exiting program.Goodbye!\n");
			exit(0);
			default:
				printf("Invalid choice!please try again.\n ");
			
		}
		
	}
	return 0;
  //login function 
  int login(){
  	char username[20],password[20];
  } 
  
  int attemps = 0;
  while(attempts<3){
  	
  	printf("\n--Login Page--\n");
  	printf("Username");
	scanf("%s",&username);
  	printf("Password");
  	scanf("%s",&password);
  	
  	// you modify credentials
  	if(strcmp(username,"Cslab@123")==&& strcmp(password,"1234")==0)
{
	printf("Login Successful! Welcome,%s.\n",username);
	
	return 1;
}
	else{
		
	printf("Incorrect username or password :plz Try again/n");
	
}
// function (add new crime record)
void addRecord(){
	FILE *fp = fopen(FILENAME,"ab");     //append in binary mode
	if(!fp) {
		printf("Error Opening File!\n");
		return;
	}
	
	CrimeRecord cr;
	printf("Enter Case ID:");
	if (scanf("%d",&cr.caseID) !=1) {
		printf("Invalid Input! Case ID Must Be a Number.\n");
		while(getchar() !='\n');
		fclose (fp);
		return;
	}
	
	getchar(); //clear newline
	
	printf("Enter Criminal name:");
	fgets(cr.criminalName,sizeof(cr.criminalName),stdin);
	cr.criminalName[strcspn(cr.criminalName,"\n")] = '\0';
	
	printf("Enter Crime Type:");
	fgets(cr.crimeType,sizeof(cr.crimeType),stdin);
	cr.crimeType,[strcspn(cr.crimeType,"\n")] ='\0';
	
}
//function to search record by case ID
void searchByCaseID(int id){
	CrimeRecord cr;
	FILE*fp =fopen(FILENAME,"rb");
	if(!fp){
		printf("Error opening file!\n");
		return;
	}
	int found = 0;
	while(fread(&cr,sizeof(CrimeRecord),1,fp)){
		if(cr.caseID ==id){
			printf("\nRecord Found:\n");
			printf("CaseID:%d\n",cr.caseID);
			printf("Criminal Name:%s\n",cr.criminalName);
			printf("Crime Type:%s\n",cr.crimeType);
			printf("Crime Location:%s\n",cr.crimeLocation);
			printf("Date:%s\n",cr.date);
			printf("Case Status:%s\n",cr.caseStatus);
			found = 1;
			break;
		}
	}
	fclose(fp);
	if(!found)
	printf("Record With Case ID %d not found.\n",id);
	
}


void deleteRecord() {
	int caseID;
	printf("Enter Case ID to Delete: ");
	 
	if (scanf("%d",&caseID) != 1) {
		printf("Invalid Input! Case ID must be a number.\n");
		while (getchar() != '\n');           //clear buffer
		return;
		
	}
	
	FILE *fp = fopen(FILENAME, "rb");
	if (!fp){
		printf("Error opening file!\n");
		return;
	}
	
	FILE *temp = fopen("temp.dat", "wb");
	if(!temp){
		printf("Error opening temporary file!\n");
		fclose(fp);
		return;
	}
	
	CrimeRecord cr;
	int found = 0;
	while (freaf(&cr, sizeof(CrimeRecord), 1, fp)) {
		if (cr.caseID == caseID) {
			found = 1;	
		}
		else{
			fwrite(&cr, sizeof(CrimeRecord), 1, temp);
		}
	}
	
	fclose(fp);
	fclose(temp);
	
	if (found) {
		remove(FILENAME);
		rename("temp.dat",FILENAME);
		printf("Record with Case ID %d deleted successfully.\n", caseID);
		
	}
	else{
		printf("Record with Case ID %d not found.\n",caseID);
	}
	
}


// Function to Load All Records From File
int loadFromFile(CrimeRecord *records){
	FILE *fp = fopen(FILENAME, "rb");
	if(!fp){
	return 0;}
	
	int count = 0;
	while (fread(&records[count], sizeof(CrimeRecord), 1, fp)){
		count++;
		if(count >= MAX)
		break;
	}
	
	fclose(fp);
	return count;
} 
  
  
