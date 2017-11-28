#include <stdio.h>

#define N sizeof(country_codes)/sizeof(country_codes[0])

struct dialing_code {
    char *country;
    int code;
};

int main(void)
{
	struct dialing_code country_codes[MAX] = 
		{{"Argentina",			  54}, {"Bangladesh",		   880}, 
		 {"Brazil",				  55}, {"Burma (Myanmar",		95}, 
		 {"China",				  86}, {"Colombia",				57}, 
		 {"Congo, Dem. Rep. of", 243}, {"Egypt",				20}, 
		 {"Ethiopia",			 251}, {"France",				33}, 
		 {"Gremany",			  49}, {"India",				91}, 
		 {"Indonesia",			  62}, {"Iran",					98}, 
		 {"Italy",				  39}, {"Japan",				81}, 
		 {"Mexico",				  52}, {"Nigeria",			   234}, 
		 {"Pakistan",			  92}, {"Philippines",			63}, 
		 {"Poland",				  48}, {"Russia",				 7}, 
		 {"South Africa",		  27}, {"Korea",				82}, 
		 {"Spain",				  34}, {"Sudan",			   249}, 
		 {"Thailand",			  66}, {"Turkey",				90}, 
		 {"Ukraine",			 380}, {"United Kingdom",		44}, 
		 {"United States",		   1}, {"Vietnam",				84}};
	int i, code;
	
	printf("Enter the dailing code: ");
	scanf(" %d", &code);
	
	for (i = 0; i < N; i++)
        if (country_codes[i].code == code){
            printf("The country with dialing code %d is %s\n", code, country_codes[i].country);
            break;
        }
	
	if (i = N){
		printf("Didn't find the country!\n");
	}
    
    return 0；
} 
