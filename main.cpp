#include "header.h"

int main() 
{
  char subject[SUBJECT];  //Declaring the variables in the structure
  char question[QUESTION];
  char date[DATE];
  int choice = 0;   //This variable will hold the user choice of the options diplayed
  int counter = 0;  //This variable will hold the index of the arrays of structures
  practice quests[10];  //Define the array of structure

  load_in(quests, counter); //Intialinzing the structures and the counter

  while(choice != 4)  //Dsplay option and will be closed if the user decided to 
  {
    choice = menu(choice);  //Resturn the user choice from menu
    
    if(choice == 1)
    {
      read_in( quests, counter);  //If the user chose to enter a new question
      
    }

    if(choice == 2) //If the user chose to get questions based on subject
    {
      read_out_question(quests, counter);
    }

    if(choice == 3)
    {
      display_all(quests,counter);  //If the user decided to display all the questions
    }

  }

  save_question(quests, counter);  //Save all the array of structers entered to the data.txt file
  return 0;
}
