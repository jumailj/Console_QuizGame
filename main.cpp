#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;
// functions
void WelcomeScreen();
int randomgenertor(int min, int max);
string Randommessage(int randomInput);
string RandommessageWrong(int randomInput);
enum gameDiffLevel { easy, medium, hard };
struct ScoreSystem {int CurrentScore = 0;}score;

int main()
{
	int randnums[21];
	srand(time(0));

	cout << "Maths Quiz game" << endl;
	cout << "correct answers get +5 point & wrong answers get -2 points" << endl; 
	cout << "10 questions total" << endl;
	cout << "[use enter key when needed...]" << endl;
    go:
	WelcomeScreen();
	gameDiffLevel Diffucility;

	string diflevel;
	string difString = "";

	getline(cin, diflevel);

	if (diflevel == "easy") {
		Diffucility = easy;
		difString = "Easy";
	}
	else if (diflevel == "medium") {
		Diffucility = medium;
		difString = "Medium"; 
	}
	else if (diflevel == "hard") {
		Diffucility = hard;
		difString = "Hard";
	}
	else {
		cout << "sorry it's set ";
		Diffucility = medium;
		difString = "Medium";
	}
	cout << "Diffucility = " << difString << endl;
	
	int minnumber = 20;
	int maxnumber = 30;

	if (Diffucility == easy)
	{
		minnumber = 10;
		maxnumber = 20;
	}
	else if (Diffucility == medium)
	{
		minnumber = 50;
		maxnumber = 100;
	}
	else if (Diffucility == hard) 
	{
		minnumber = 100;
		maxnumber = 200;
	}else 
	{
		minnumber = 50;
		maxnumber = 100;
	}
	//setting the random number array;
	for (int i = 0; i <= 20; i++)
	{
		randnums[i] = randomgenertor(minnumber, maxnumber);
	}

	// main game loop;
	for (int i = 0; i <= 9; i++)
	{
		int answer[10];
		cout << i + 1 << ") " << randnums[i] << " + " << randnums[i + 10] << " = ";
		cin >> answer[i];
		


		if (answer[i] == randnums[i] + randnums[i + 10])
		{
			string message;
			int randMesg = randomgenertor(1, 3);
			message = Randommessage(randMesg);
			cout << message << " ";
			score.CurrentScore = score.CurrentScore + 5;
	
			cout << "score total = " << score.CurrentScore << endl;
			cout << "\n";
		} else
		{
			string message;
			int randMesg = randomgenertor(1, 3);
			message = RandommessageWrong(randMesg);
			cout << message << " ";
			cout << "correct answer was: " << randnums[i] + randnums[i + 10] << ",";
			score.CurrentScore = score.CurrentScore - 2;
			cout << "  Score total = " << score.CurrentScore << endl;
			cout << "\n";
		}	
		
	}

	cout << "total Score: " << score.CurrentScore << endl;
	cout << "\n";
	
	cin.get();

	string userInput = "";
	cout << "do you wan't to player again [yes ' no]? " << endl;
	getline(cin, userInput);

	if(userInput == "yes") 
	{
		cout << " play once more" << endl;
		score.CurrentScore = 0;
		goto go;
	} else if (userInput == "no" ) 
	{
		cout << "you are quiting" << endl;
		return 0;
	} else 
	{
		return 0;
	}
	
	// balance;
}

	
void WelcomeScreen() 
{
	cout << " Type one>> easy, medium, hard: ";
}

int randomgenertor(int min, int max)
{
	start:
	int ReturnValue;
	ReturnValue = rand() % max + 1;
	if ( ReturnValue < min)
	{
		goto start;
	}
	return ReturnValue;

}

string Randommessage(int randomInput) 
{
	string outputString = "";
	switch(randomInput)
	{
	case 1:
		outputString = "wow Cool! ,";
		break;

	case 2:
		outputString = "yes true answer! ,";
		break;

	case 3:
		outputString = "yaa right ,";
		break;

	default:
		outputString = "correct! ,";
		break;

	}

	return outputString;

}

string RandommessageWrong(int randomInput)
{
	string outputString = "";
	switch (randomInput)
	{
	case 1:
		outputString = "sorry ! ,";
		break;

	case 2:
		outputString = "answer was wrong! ,";
		break;

	case 3:
		outputString = "false sorry , ";
		break;

	default:
		outputString = "wrong!, ";

	}

	return outputString;

}