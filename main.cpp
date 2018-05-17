

//We will solve many problems in this given .cpp file
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <ctime>


//Function prototypes

//Two String addition and then print the result in a string datatype.
std::string twoSum(std::string a,std::string b);
std::string helperSum(std::string larger, std::string smaller);

//Checking if a string is a palindrome while ignoring non-alphabet characters
bool isPalindrome(std::string & sentence);
void convertToLower(std::string & word);

std::vector<int> mergingTwoArrays( std::vector<int> vectA, std::vector<int> vectB,std::vector<int> & myVectAnswer);


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


	//We will now solve the N-queens problem
	std::cout << "\n\n\nWe will now solve the N-Queens problem.\n\n";









	//Find the first non repeating character in string problem
	std::cout << "\n\n\nWe will now solve the first non-repeating character in a string.\n\n";

	

	//We will solve, Get the k-lowest elements in an unsorted Array.
	

	//Write a function to check if a word is a palindrome. 
	//What about for sentences, and ignoring capitals, punctuation, and spaces?  
	std::cout << "\n\nEnter a sentence and we will determine if we have a Palindrome: ";
	std::string mySentence;
	getline(std::cin, mySentence);
	
	std::cout <<"\nChecking if the sentence is a palindrome:\n" << mySentence
       			<< "      = " << isPalindrome(mySentence) << "\n\n";

	//Two array with n-elements, Merge those arrays using a recursive algortihm 
	//so that the integers in the final array are sorted.

	std::cout << "\n\nWe will now solve the mergin problem:\n\n";
       //we need to create two array that are sorted
       srand(time(NULL));

       std::cout << "How big will our arrays be: ";
       int size;
       std::cin >> size ;


	//Create our two vectors
	std::vector<int> vectA;
	std::vector<int> vectB;


	int prevOne = 23;
	int prevTwo = 24;

	for(int i = 0; i < size ; i++)	
	{
		int randOne = rand() % 100000 + 1;
		int randTwo = rand() % 100000 + 1;
		

		while(prevOne > randOne){
			randOne = rand() % 100000 + 1;
	
				
		}
		prevOne = randOne;
		vectA.push_back(prevOne);

		while(prevTwo > randTwo){
			randTwo = rand() % 100000 + 1;
		}
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

	std::cout << std::endl;


	return 0;
}






std::string twoSum(std::string a, std::string b) {




	std::string stringAnswer;

	if(b.length() >= a.length()){
		stringAnswer = helperSum(b,a);
	}
	else
	{	
		stringAnswer = helperSum(a,b);
	}



	return stringAnswer;
	

}


std::string helperSum(std::string larger, std::string smaller){

	
	int endA = larger.length() - 1;
	int endB = smaller.length() - 1;



	int size = smaller.length();

	int carry = 0;
	int sum = 0;
	
	int digitA;
	int digitB;
	
	std::stack<int> answerStack;



	for(int i = 0; i < size ; i++){
	
		//Starting at the end of both strings
		

		digitA = larger.at(endA - i) - 48;
		digitB = smaller.at(endB -i) - 48;


		//Get the sum and then mod it by 10, The sum value range is: [0-18]
		sum = carry + digitA + digitB;
		//Do we have to carry over?

		if(sum < 10){
			carry = 0;
			//Sum remains the same and then I carry nothing
			
			//Place this digit into the stack
			answerStack.push(sum);	
		}
		else{
			carry = 1;
			//We carry one and then push the digit by modding by 10 first.
			sum = sum % 10;		
			answerStack.push(sum);	
		}


	
	}

	std::stack<int> answerStack1 = answerStack; 




	//Now we push the rest of the values
	

	if(carry == 1){
		
	
		int startingIndex = larger.length() - size -1;
		//Simply push the rest of the elements into the stack from the larger string
		for(int m = startingIndex ;  m >= 0 ; m-- ){
			
			int currentIndexVal = int(larger.at(m)) - 48;

			
			int value =  carry + currentIndexVal;
			
			//Place the largerString values into the stack
			//Remember in terms of values.
			if(value < 10){
				carry = 0;
				answerStack.push(value);
			} else{
				carry = 1;
				value = value %10;
				answerStack.push(value);
			}
		}
		
		
		if(carry == 1);
		{
			answerStack.push(1);
		}


	}
	else{
	
		int startingIndex = larger.length() - size -1;
		//Simply push the rest of the elements into the stack from the larger string
		for(int m = startingIndex ;  m >= 0 ; m-- ){
		
			//Place the largerString values into the stack
			//Remember in terms of values.
			
			int theVal = int(larger.at(m)) - 48;

			answerStack.push(theVal);

		}
	
	
	
	}


	std::cout << "The Answer is:\n"; 
	while(!answerStack.empty()){
	
		std::cout << answerStack.top() ;
		answerStack.pop();
	}


	return "HELLO";




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
	

			//Shift until we are in a correct position, for both i ad j
			while( (int)sentence[i] < 97 || (int)sentence[i] >122){
			
				if(i > sentence.length() - 1){
					return 0;
				}
		
				std::cout << "Increment i\n";		
				++i;
			}
	
			//Shift until we are in a correct position, for both i ad j
			while( (int)sentence[j] < 97 || (int)sentence[j] >122){
			
				if(j < 2){
					return 0;
				}
				
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

std::vector<int> mergingTwoArrays( std::vector<int> vectA, std::vector<int> vectB,std::vector<int> & myVectAnswer){	
	
	int nSize = vectA.size();

	//Keep track of two indices
	int i = 0;
	int j = 0;

	//While we are in the correct positions	
	while( i != nSize && j != nSize)
	{
		int iVal = vectA[i];
		int jVal = vectB[j];
		if(iVal < jVal)
		{
			//Insert the smaller value
			myVectAnswer.push_back(iVal);
			++i;	
		
		}
		else{
			//The jvalue is smaller 
			myVectAnswer.push_back(jVal);
			++j;	
		}
	}


	//If we reach here we are done with one of the arrays, i
	//so we must place the rest of the element into our vector answer

	//Determine which of our arrays is done
	
	if( i ==  nSize){
		//The first vector is complete so place the elements of our second vector 
		//into the answer vector

	       while(j != nSize){
	       		myVectAnswer.push_back(vectB[j]);	
		       ++j;
	       }	
	
	}
	else{

	       while(i != nSize){
	       		myVectAnswer.push_back(vectA[i]);	
		       ++i;
	       }	
	}






	return myVectAnswer;

}
