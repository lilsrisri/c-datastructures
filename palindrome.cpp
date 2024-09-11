#include <iostream>
#include <cstring>

using namespace std;

int main()
{
   char word[81];
   int p = 0;
  cout << "Please enter in a string below 80 characters, and I will tell you if it is a palindrome or not." << endl;
  cin.getline(word, 81); //reads in an input from a user thats at max 80 characters.
// cout << word << endl;
  for (int g = 0; word[g] != '\0'; g++) { //for loop that runs through each character in the array, and checks if there is a space or punctuation
    if (!ispunct(word[g]) && !isspace(word[g])) { //if there's space or punctuation, ignore! if not, read it to P, which will read it back into the array
      word[p] = tolower(word[g]); //lowercase!!!
      p++; //increments p so I can read in the next correct input for the array
     }
  }
  word[p] = '\0'; //adds the null character at the end so the compliler knows its done
  // cout << word << endl;

  p = strlen(word) - 1; //sets p as the end of the character array
  bool palindrome = true; //variable for later
  for (int g = 0; g < strlen(word); g++, p--) { //for loop that checks if the first and last letter of the are the same, if at any point it doesn't match up, this is not a palindrome!
      if (word[g] != word[p]) {
        cout << "This is not a palindrome!" << endl;
	palindrome = false; //set palindrome to false so I dont get two outputs, then break the loop
        break;
      }    
   }
  if (palindrome) { //Once the for loop has exited (and the condition is met), I will know that all the characters matched, and since the variable starts at true, I know this is a palindrome
      cout << "This is a palindrome!" << endl;
 }
   }
