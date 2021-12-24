#include <iostream>
#include <cctype>
#include <fstream>
#include <cstring>
using namespace std;


//This program will be a great tool for Computer Science students to practice coding. The user can enter questions categorized by subjects. So whenever they need to practice a certain subject they could just enter it.

const int SUBJECT = 21;  //Setting up constatns for the arrays of characters inside the structure
const int QUESTION = 101;
const int DATE = 11;

struct practice   //This struct will hold all the stuff related to the question
{
  char subject[SUBJECT];
  char question[QUESTION];
  char date[DATE];
};

//Prototypes
int menu(int choice);   //This function will display the options to the user and will return their choice
void load_in(practice quests[], int & counter); //This functoion will load the file to intialize the questions that have been already entered to the structures
void read_in(practice quests[], int & counter); //This function will read in the question that the user has entered 
void read_out_question(practice quests[], int counter); //This function will display the questions based on the subjects has entered
void save_question(practice quests[], int counter); //This function will save the structures to the data.txt file
void display_all(practice quests[], int counter);  //This function will display all the questions that are saved in the file
