#include "my_string.h"

//Copy string
char* my_strcpy(char* destination, const char* source )
{
    	size_t my_num;
  	const char* my_src = source;
  	char* my_dest = destination;
	//if the memory addresses are the same, don't need to copy
  	if (my_dest == my_src)
    		return destination;
	//copy each character from source into dest
	//stop at delimeter of \0
  	for (my_num = 0; my_src[my_num] != '\0'; my_num++)
      			*(my_dest + my_num) = *(my_src + my_num); 
  	
  	return destination;
}

//Locate first occurrence of character in string
char* my_strchr (char* str, int character)
{
	size_t my_num = 0;

	//loop to find first occ. of char or until end
    	while(str[my_num] != character && str[my_num]!='\0'){

		my_num++;
	}

      	if(character == '\0' ||  str[my_num]!='\0') //check if reached \0 (unless \0 is target)
		return str+my_num;
	else
		return NULL;
		
				
    
}

//Move block of memory
void* my_memmove (void* destination, const void* source, size_t num)
{
  	size_t my_num = num;
  	const char* my_src = source;
  	char* my_dest = destination;
	//if the memory addresses are the same, don't need to copy
  	if (my_dest == my_src)
    		return destination;
  	else 
	{
    		while (num-- != 0)
      			*(my_dest + num) = *(my_src + num);
  	}
	
  	return destination;
}

//Append characters from string
char* my_strncat (char* destination, const char* source, size_t num)
{
	size_t i,j;
	//loop to end of destination
	for (i = 0; destination[i] != '\0'; i++);
	//append num chars from source to destination
	for (j = 0; source[j] != '\0' && num > 0; j++){

		destination[i+j] = source[j];
		num--;
	}
	//null terminator
	destination[i+j] = '\0';

	return destination;
}

//Compare characters of two strings
int my_strncmp (const char* str1, const char* str2, size_t num)
{
	size_t my_num;
  	char char1, char2;
  	for (my_num = 0; my_num < num; my_num++) {
    		char1 = *(str1++);
    		char2 = *(str2++);
    	if (char1 > char2)
      		return 1;
    	else if (char1 < char2)
      		return -1;
    	else if (char1 == char2 && char1 == 0)
      		return 0;
  	}
  	return 0;
}

//Compare two strings
int my_strcmp (const char* str1, const char* str2)
{
	//compare characters
	while(*str1 && *str2){
		str1++;
		str2++;
	}
	//str1 is asciibetically bigger
	if(*str1 > *str2)
		return 1;
	//str1 is asciibetically smaller
	else if(*str1 < *str2)
		return -1;
	return 0;
}
 
//Locate last occurrence of character in string
char* my_strrchr (char* str, int character)
{
   	size_t my_num = 0;
	char* res = NULL;
	//keep going until end
    	while(str[my_num]!='\0'){
		if(str[my_num] == character)
			res = (str+my_num);//track most recent occurrence
		my_num++;
	}
      	if(character == '\0')
		return (str+my_num);
  
	return res;
}

//Locate substring
char* my_strstr (char *str1, const char *str2)
{
    	char *pos, *char1, *char2;
	for(pos = &str1[0]; *pos != '\0'; pos++){
		char1 = pos;
		char2 = str2;
		//check if at current char in str1 there is the substring str2
		while(*char2 != '\0'){
			if(*char1 != *char2)
				break;
			char1++;
			char2++;		
		}
		if(*char2 == '\0')
			return pos;

	}
	 
    	return NULL;
}
