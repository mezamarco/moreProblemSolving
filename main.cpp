


//We will solve many problems in this given .cpp file
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <ctime>


//Function prototypes

//Two String addition and then print the result in a string datatype.
std::string twoSum(std::string& a,std::string& b);

//Checking if a string is a palindrome while ignoring non-alphabet characters
bool isPalindrome(std::string & sentence);
void convertToLower(std::string & word);


std::vector<int> mergeNoRecursion(std::vector<int> & a , std::vector<int> & b);



char nonRepeatingChar(std::string word);

int main(){

	//We will solve the two string addition problem
	std::cout << "\nWe will solve the two string problem.\n\n";

	std::string a;
	std::string b;



	std::cout << "Enter the First value:"; 
	getline(std::cin, a);
	std::cout << "Enter the Second value:"; 
	getline(std::cin, b);

	std::cout << "\n\nSum("<< a << " , " << b << ")" << " = " << twoSum(a,b) <<"\n\n";





	//Find the first non repeating character in string problem
	std::cout << "\n\n\nWe will now solve the first non-repeating character in a string.\n\n";

	
	std::cout << "Enter a string with repeated characters, except for one character: ";
	std::string theString;	
	getline(std::cin,theString);

	std::cout << "Finding the non-repeated character: \n";
	std::cout  << "We found it, the first non-repeated character: "<< nonRepeatingChar(theString);
	std::cout << "\n\n";
	
	
	
	
	
	
	
	
	
	//Write a function to check if a word is a palindrome. 
	//What about for sentences, and ignoring capitals, punctuation, and spaces?  
	std::cout << "\n\nEnter a sentence and we will determine if we have a Palindrome: ";
	std::string mySentence;
	getline(std::cin, mySentence);
	
	std::cout <<"\nChecking if the sentence is a palindrome:\n" << mySentence
       			<< "      = " << isPalindrome(mySentence) << "\n\n";

	
	
	
	
	
	
	
	
	
	//Two array with n-elements, 
	//Merge those arrays using a recursive algortihm 
	//so that the integers in the final array are sorted.
	//And also merge without recursion

	std::cout << "\n\nWe will now solve the merging problem:\n\n";
       //we need to create two array that are sorted
       srand(time(NULL));

       std::cout << "How big will our arrays be: ";
       int size;
       std::cin >> size ;


	//Create our two vectors
	std::vector<int> vectA;
	std::vector<int> vectB;


	int prevOne = 5;
	int prevTwo = 5;

	for(int i = 0; i < size ; i++)	
	{
		int randOne = (rand() % (1000)+1) + prevOne;
		int randTwo = (rand() % (1000)+1) + prevTwo;
		

		prevOne = randOne;
		vectA.push_back(prevOne);

		prevTwo = randTwo;
		vectB.push_back(prevTwo);

	}

	std::cout << "LETS PRINT what is in vect A and vect B\n\n";

	for(int num: vectA){
		std::cout << num << "  ";
	}
	std::cout << "\n\n";
	for(int number: vectB){
		std::cout << number << "  ";
	}

	std::vector<int>mergedNoRecursionVect = mergeNoRecursion(vectA, vectB); 

	std::cout << std::endl;

	std::cout << "Merging without Recursion: \n";
	//We are merging with the no recursion vector
	for(int val:mergedNoRecursionVect){
		std::cout << val << "   ";
	}

	std::cout << "\n\n";

	return 0;
}






std::string twoSum(std::string& a, std::string& b) {
	if(a.length() == 0)
		return b;
	if(b.length() == 0)
		return a;

	std::string smaller = (a.length() <= b.length()) ? a:b; 
	std::string larger = (a.length() <= b.length()) ? b:a;
	std:::stack<char> myStack;
	int carry = 0;
	int sum = 0;

	//We need to start from the back, take into account the size of the smaller string
	int i = smaller.length() - 1;
	int j = larger.length() - 1;
	//i belongs string a and j belong to string j
	while( i >=0 )
	{	
		//Note theat the ASCII character of '0' is decimal:48
		int numA = ( (int)smaller[i] - 48);
		int numB = ( (int)larger[j] - 48);
		sum = numA + numB + carry;

		if(sum < 10){
			carry = 0;
			myStack.push( (char)(sum + 48));
		}
		else{
			carry = 1;
			int digit = sum % 10;
			myStack.push((char)(digit + 48));
		}
		
		--i;
		--j;
	}	
	//We are done with the smaller string, finish up the remaining character of the second string
	while( j >= 0 ){
		sum = ( (int)(larger[j] - 48)) + carry;	
		if(sum < 10){
			carry = 0;
			myStack.push((char)(sum +48));	
		}
		else{
			carry = 1;
			int digit = sum % 10;
			myStack.push((char)(digit + 48));
		}
		--j;
	}

	if(carry == 1)
		myStack.push('1');

	//Traverse the stack and combine into a string.
	std::string ans = "";
	
	while(!myStack.empty()){
		ans = ans + myStack.top();
		myStack.pop();
	}

	return ans;
}




bool isPalindrome(std::string & sentence){

	//For all the letters, make sure to ignore: (spaces and punctuations)
	
	//Make everything lowerCase, before solding this problem
	//We need to make a helper function for this to work
	convertToLower(sentence);


	//Two trackers are needed, one for the start and one for the end
	int i = 0;
	int  j = sentence.length() - 1;


	while( i < j )
	{

		int valOne = (int)sentence[i];
		int valTwo = (int)sentence[j];
		std::cout << "VALUE ONE  =  " << valOne << "      Valuetwo = " << valTwo << "\n";
		
		//Check for valid inputs only, remember we do not want to get spaces or punctuations.
		if(  valOne >= 97 && valOne <= 122 && valTwo >= 97 && valTwo <=122 ){
		
			if(valOne != valTwo){
				return 0;
			}
			++i;
			--j;
		}
		else{
			//This is for the case that we have invalid characters

			//Shift until we are in a correct position, for both i ad j
			while( (int)sentence[i] < 97 || (int)sentence[i] >122){
				//If we are in the last index, we can no longer increment i
				//Return false.
				if(i > sentence.length() - 1){
					return false;
				}
		
				std::cout << "Increment i\n";		
				++i;
			}
	
			//Shift until we are in a correct position, for both i ad j
			while( (int)sentence[j] < 97 || (int)sentence[j] >122){
				//If j is index 1, then we can decrement, return false
				if(j < 2)
					return false;
				
				--j;
			}
		}
	



	}


	return 1;

}





void convertToLower(std::string & word)
{
	//For all the characters convert them into lowerCase
	for(int i = 0; i < word.length(); i++){
	
	
		word[i] = tolower(word[i]);
	}

	//Every character has been converted, so return
	
	return;


}



char nonRepeatingChar(std::string word){
	
	//Make a counter for every single character;
	std::vector<int> myVect(128,0);

	//For every character in the string
	for(int i =0; i < word.length(); i++){
		int index = (int)word[i];
		myVect[index] += 1;

	}	

	//We are looking for the FIRST non repeated character so traverse the 
	//given word in order
	for(int i = 0; i < word.length();i++){
		int index = (int)word[i];

		if(myVect[index] == 1){
			return word.at(i);
		}
		
	}
	


 	//We found no answer, return '!';
 	return '!';

}


//Easy solution, when not using recursion for merging sorted arrays
std::vector<int> mergeNoRecursion(std::vector<int> & a , std::vector<int> & b){
    
	int size = a.size();


	std::vector<int> c;


	int i =0;
	int j =0;


	//For all the elements in the both vector
	while(i < size && j <size){
		
		if(a[i]<b[j]){
		
			//The smaller one is a[i], so insert that element into our vector c
			c.push_back(a[i]);
			++i;
		}
		else{
			c.push_back(b[j]);
			++j;
		}
	}

	//Store the remaining elements of the first array

	while(i<size){
		c.push_back(a[i]);
		++i;
	}
	//Store the remaining elements of the second array
	while(j < size){
		c.push_back(b[j]);
		++j;
	}



	return c;	
}

