#include "header.h"

int menu(int choice)  // Display menu
{
  cout<<"Hello! Welcome to the practice program."<<'\n'<<"Enter the number of the option you choose:"<<'\n'<<"(1) Enter a new question."<<'\n'<<"(2) Get questions by subject."<<'\n'<<"(3) Display all the question"<<'\n'<<"(4) Exit the program."<<'\n'<<"What do you want to do: ";

  cin>>choice;
  cin.ignore(100,'\n');

return choice;  //Return choice 
}

void load_in(practice quests[], int & counter)  //Load in the data.txt file
{  
  char line[225]; 
  char delimiter = '|';
  ifstream in_file; //Creating a variable for input
  in_file.open("data.txt"); //Opening the file

  if(in_file) //Connect
  {
    in_file.get(line,225,delimiter);  //Get everything before the delimiter
    while(in_file && !in_file.eof() && counter < 10)  //Get every question from the file 
    {
      in_file.ignore(100,delimiter);
      strcpy(quests[counter].subject, line);  //Subject
      in_file.get(line,225,delimiter);
      in_file.ignore(100,delimiter);  
      strcpy(quests[counter].question, line); //Question
      in_file.get(line,225,'\n');
      in_file.ignore(100,'\n');
      strcpy(quests[counter].date, line); //Data

      counter = counter + 1;  //Move to the next structure

      in_file.get(line,225,delimiter);

    }

    in_file.close();    //Close the file

  }

}

void read_in(practice quests[], int & counter)  //Read in the quests data
{
  cout<<'\n'<<"What subject (Make sure not to capitalize any letter): ";
  cin.get(quests[counter].subject,SUBJECT,'\n');
  cin.ignore(100,'\n');
  cout<<'\n'<<"Type in the question: ";
  cin.get(quests[counter].question,QUESTION,'\n');
  cin.ignore(100,'\n');
  cout<<"Enter the date: ";
  cin.get(quests[counter].date,DATE,'\n');
  cin.ignore(100,'\n');

  cout<<'\n';

  counter = counter + 1;  //Make sure that the next question will move to the next array

}

void read_out_question(practice quests[], int counter) //Read question based on subject
{
  char sub[21]; //Create a variable that holds the users input of subject

  cout<<"What subject would you like (Make sure not to capitalize any letter): ";
  cin.get(sub,20,'\n');
  cin.ignore(100,'\n');
  
  for(int i = 0; i < counter; ++i)
  {
    if(strcmp(quests[i].subject , sub) == 0)  //Compare the subject entered to the subject saved in the files
      {
      cout<< '\n' << i+1 << ')' << quests[i].subject << ": "  << quests[i].question << '\n' << quests[i].date <<   '\n'<<'\n';
      }        
    
  }
}

void save_question(practice quests[], int counter)  //Saving the quests data 
{
  ofstream out;

  out.open("data.txt");

  if(out)
  {
    for(int i = 0; i < counter; ++i)
    {
      out<< quests[i].subject<<'|'<<quests[i].question<<'|'<<quests[i].date<<'\n';
    }
  }

}

void display_all(practice quests[], int counter)  //Display all the questions for the user
{
  for(int i = 0; i < counter; ++i)
  {
    cout<< '\n' << i+1 << ')' << quests[i].subject << ": " << quests[i].question << '\n' << quests[i].date << '\n';
  }
}
