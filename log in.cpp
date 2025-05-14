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

  
  
