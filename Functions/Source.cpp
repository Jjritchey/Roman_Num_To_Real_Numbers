//Justin Ritchey Machine Problem 4 Fucntions. 6/22/2020

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


//Fucntions
void GetData(string, string, char);                                      //Function that starts everything off while opening up the attached file
void ConvertRomanToDecimal(string, string, char);                        //Fucntion that resides inside GetData and takes 2 strings of roman numerals and 1 character of operation and assigns them whole numbers instead of roman numerals, prints out the all final data
int RomanOperator(int, int, char);                                       //Called by ConvertRomanToDecimal and is used to take the two interger values and apply the operation
string RomanMath(int);                                                   //Called by ConvertRomanToDecimal and is used to take the final whole number and return a roman numeral

string number1 = "";                                                     //string to hold the first roman numeral value for each loop
string number2 = "";                                                     //string to hold the second roman numeral value for each loop
char letter = '\0';                                                      //Char to hold the operation value for each loop
int FinalNumber = 0;                                                     //Holds the final whole number for each loop
string FinalRoman = "";                                                  //Holds the final roman numeral value for each loop


int main()
{
 
    GetData(number1, number2, letter);                                   //Calls the GetData function

}

void GetData(string number1, string number2, char letter)                //Starting function to open the file and start the loop to gather all of the data
{
    ifstream file("mp4romanletrdata.txt");                               //Opening file

    if (file.is_open());                                                 //Starting loop to grab all info while the file is open
    {
         while (file >> number1 >> number2 >> letter)                    //Starting while loop to assign each line of data to their own values
        {

             ConvertRomanToDecimal(number1, number2, letter);            //Opening function
            
        }
    }
}

void ConvertRomanToDecimal(string number1, string number2, char letter)      //Starring fucntion to convert a roman numeral to a decimal number and prints it out
{

    int RealNumber1 = 0;                                                     //To hold the decimal number of the first roman numeral
    int RealNumber2 = 0;                                                     //To hold the decimal number of the second roman numeral

    for (char & c : number1)                                                 //Starting loop that assigns indivual letters into a char value and then assigns a decimal number
    {
        if (c == 'M')
            RealNumber1 = RealNumber1 + 1000;

        else if (c == 'D')
            RealNumber1 = RealNumber1 + 500;

        else if (c == 'C')
            RealNumber1 = RealNumber1 + 100;

        else if (c == 'L')
            RealNumber1 = RealNumber1 + 50;

        else if (c == 'X')
            RealNumber1 = RealNumber1 + 10;

        else if (c == 'V')
            RealNumber1 = RealNumber1 + 5;

        else if (c == 'I')
            RealNumber1 = RealNumber1 + 1;

        else
            break;
           
    }

    for (char& c : number2)                                               //Starting loop for the second roman numeral
    {
        if (c == 'M')
            RealNumber2 = RealNumber2 + 1000;

        else if (c == 'D')
            RealNumber2 = RealNumber2 + 500;

        else if (c == 'C')
            RealNumber2 = RealNumber2 + 100;

        else if (c == 'L')
            RealNumber2 = RealNumber2 + 50;

        else if (c == 'X')
            RealNumber2 = RealNumber2 + 10;

        else if (c == 'V')
            RealNumber2 = RealNumber2 + 5;

        else if (c == 'I')
            RealNumber2 = RealNumber2 + 1;

        else
            break;
    }

    RomanOperator(RealNumber1, RealNumber2, letter);                                           //Calling RomanOperator function
    RomanMath(FinalNumber);
  

    cout << "The First number is: " << number1 << "( " << RealNumber1 << " )" << "\n";        //Printing off the results for each loop
    cout << "The Second number is: " << number2 << "( " << RealNumber2 << " )" << "\n";
    cout << "The operator is: " << letter << "\n";
    cout << "The final number is: " << FinalNumber << " ( " << FinalRoman << " )" << "\n";
    cout << "******************************" << "\n\n";

        
}

int RomanOperator(int RealNumber1, int RealNumber2, char letter)                             //Does the math to get the final number for each loop
{

    if (letter == '+')
        FinalNumber = RealNumber1 + RealNumber2;
    else if (letter == '-')
        FinalNumber = RealNumber1 - RealNumber2;
    else if (letter == '*')
        FinalNumber = RealNumber1 * RealNumber2;
    else
        FinalNumber = RealNumber1 / RealNumber2;     
    
    return FinalNumber;
}

string RomanMath(int FinalNumber)                                                           //Does the math to convert the final decimal number into a final roman numeral number
{
    FinalRoman = "";
    int math = 0;

    math = FinalNumber;
    while (math > 0)
    {
        if (math >= 1000)
        {
            math = math - 1000;
            FinalRoman += "M";
        }
        else if ((math < 1000) && (math >= 500))
        {
            math = math - 500;
            FinalRoman += "D";
        }
        else if ((math < 500) && (math >= 100))
        {
            math = math - 100;
            FinalRoman += "C";
        }
        else if ((math < 100) && (math >= 50))
        {
            math = math - 50;
            FinalRoman += "L";
        }
        else if ((math < 50) && (math >= 10))
        {
            math = math - 10;
            FinalRoman += "X";
        }
        else if ((math < 10) && (math >= 5))
        {
            math = math - 5;
            FinalRoman += "V";
        }
        else if ((math < 5) && (math >= 1))
        {
            math = math - 1;
            FinalRoman += "I";
        }
    }
    return FinalRoman;
}

