
  int login(); //login function new
  
  void addRecord();
  
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

  
  
