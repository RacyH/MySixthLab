/*
Racy Halterman
C++ Fall 2020
Due: November 16th
Lab 6 Binary to Decimal Conversion
Write a C++ program that reads characters representing binary (base 2) numbers from a data file
and translates them to decimal (base 10) numbers.*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void heading();
void file();
int width(string w);
int width2(int w2);
int width3(int w3);

int main()
{
	heading();//The heading of the program
	file();//The function that calls the file, reads it, and outputs the information gathered.
	//At the end of your file, remember to have an end of line to force the end of file, or it will not read the last line
	return 0;
}

void heading()
{ //This function calls the heading at the top of the program. I made them both have a width of 21, and put a divider between the two.
	cout << setw(17) << "Binary Number" << setw(4) << "|" << setw(21) << "Decimal Equivalent" << endl;
}

void file()
{
	string y = ""; // This is the string where the binary number, if valid, is saved.
	ifstream inFile;
	inFile.open("BinaryIn.dat"); //Opens the file.
	char x; //The character used to read in the character one at a time.
	int n = 0; //Counting number to keep track of whether the binary number has started or not, so that it can skip spaces in front of it
	int deci = 0;
	bool a = true, b = false; //Bools to keep some of this all in line.

	//inFile.get(x);
	//inFile >> x;

	while (inFile.get(x))          // Loops getting single characters from the file
	{
		if (a == true) //a becomes false if there is an endline or end of file, which forces an if statement if n > 0, n counting how many binary digits are on a line
		{
			if (x == '1') //The next several if statements allow the program to test if the things that determine if an input is valid and which input does what
			{
				y = y + x;  //If the input is a 1, adds the character x, which is 1, to the string y, which at the beginning is "". Loops for all the 1's in the number
				n++; //Adds 1 to n, which is set as 0 for every new line, with the exception of lines that have no binary input
				deci = (deci * 2) + 1;
			}
			if ((n > 0 && x != '0' && x != '1' && x != '\n') || (n == 0 && x != ' ' && x != '0' && x != '1' && x != '\n'))
			{/*This crazy looking bit of code is a simple way of doing an if else statement. If all of the first things are met, then this happens. If
			 n, the count of binary inputs of the code is greater than 0, and x is not equal to a good input, then the line is set as bad, and the following
			 error statment is outputted, and then b is set to true, which dissalows the output of the binary number or it's decimal equivalent to be
			 outputted.*/


				cout << setw(20) << "Bad digit on input\n";
				b = true;
			}
			if (x == '0' && n > 0)
			{
				y = y + x; //Same logic as the identical line earlier, but for 0's this time
				deci = (deci * 2) + 0;
			}
			if (x == '\n')
			{
				a = false;//Makes it so the a becomes false, forcing an endline character to be outputted, if there has been a binary input, or a bad input
			}
			if (inFile.eof()) //Remember to include an endl at the end of file to force an eof
			{
				a = false; //Makes a false if the file ends, which forces the if statement this is in to stop working
			}
		}

		if (b == false && a == false && n > 0)
		{ /*b stands for bad. If it is bad, than b becomes true, and doesn't allow this to happen. a has to be true, which means the input was
			an end of line, and n, the count of whether binary input has started has to be greater than 1, ignoring all blank lines*/
			int len = width(y), len2 = len + 10; // Some number crunching to set the width of the numbers in their columns
			int wid = 21 + width2(deci) - width3(len);

			cout << setw(len2) << y; // Outputs the integer version of the binary input, as a string, getting rid of spaces and 0's in front of it
			cout << setw(wid) << deci << endl; //Outputs the decimal number
			y = ""; //These three lines reset the deci, y, and n variables for every new line, and at the end of file
			n = 0;
			deci = 0;
		}
		if (b == true) //If b came back as true, then the following happens
		{
			b = false; //Resets the value of b
			y = ""; //Resets values every time a string becomes invalid
			n = 0; //Resets n
			deci = 0; //Resets deci
			inFile.ignore(200, '\n'); //Ignores the line that the error is in
		}
		a = true; //Sets a to be true, even if there weren't any binary numbers inputted, allowing empty lines to be inputted without them printing
	}
	inFile.close();                //Closes file
}

int width(string w)
{
	int width = 0;
	switch (w.length())
	{
	case 1:width = 1;
		break;
	case 2:width = 1;
		break;
	case 3:width = 2;
		break;
	case 4:width = 2;
		break;
	case 5:width = 3;
		break;
	case 6:width = 3;
		break;
	case 7:width = 4;
		break;
	case 8:width = 4;
		break;
	case 9:width = 5;
		break;
	case 10:width = 5;
		break;
	case 11:width = 6;
		break;
	case 12:width = 6;
		break;
	case 13:width = 7;
		break;
	case 14:width = 7;
		break;
	case 15:width = 8;
		break;
	case 16:width = 8;
		break;
	case 17:width = 9;
		break;
	case 18:width = 9;
		break;
	case 19:width = 10;
		break;
	case 20:width = 10;
		break;
	default:width = 11;
		break;
	}
	return width;
}

int width2(int w2)
{
	int width2 = 0;
	if (w2 < 10)
	{
		width2 = 0;
	}
	else if (10 <= w2 && w2 < 1000)
	{
		width2 = 1;
	}
	else if (1000 <= w2 && w2 < 100000)
	{
		width2 = 2;
	}
	else if (100000 <= w2 && w2 < 10000000)
	{
		width2 = 3;
	}
	else if (10000000 <= w2 && w2 < 1000000000)
	{
		width2 = 4;
	}
	else if (1000000000 <= w2 && w2 < 1000000000)
	{
		width2 = 5;
	}
	else if (1000000000 <= w2 && w2 < 100000000000)
	{
		width2 = 6;
	}
	return width2;
}

int width3(int w3)
{
	int wid3;
	switch (w3)
	{
	case 1: wid3 = 0;
		break;
	case 2: wid3 = 1;
		break;
	case 3: wid3 = 2;
		break;
	case 4: wid3 = 3;
		break;
	case 5: wid3 = 4;
		break;
	case 6: wid3 = 5;
		break;
	case 7: wid3 = 6;
		break;
	case 8: wid3 = 7;
		break;
	case 9: wid3 = 8;
		break;
	case 10: wid3 = 9;
		break;
	default: wid3 = 10;
		break;
	}
	return wid3;
}
