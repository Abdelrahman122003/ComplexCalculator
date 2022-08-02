/*FACULTY OF COMPUTERS AND ARTIFICIAL INTELLIGENCE, CAIRO UNIVERSITY
Author : Abdelrhman sayed ali
Program Name: Complex Number Calculator.c plus plus*/
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <map>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include<windows.h>
using namespace std;


double FcoefWComplexNum, ScoefWComplexNum, ScoefComplexNum, FcoefComplexNum;

string checkVaildateFirstStr();
string checkVaildateSecondStr();
string displaymenu();
void divisionExperation();

void Addition();
void subtraction();
void multiplication();
void dividation();

int CoefficientWithoutComplexNumber(string strComplex);
string substring(int first, int last, string str);


void setTextColor(int n);

int main ()
{
    setTextColor(4);
    system("cls");
    cout << "         ===================================================================================\n";
    cout << "                       ******[---- Welcome User to Complex Number Calculator ----]******"<<endl;
    cout << "         ===================================================================================="<<endl;
    string choice;
    while (true)
    {
        
        choice = displaymenu();
        if (choice == "1")
        {
            system("cls");
            divisionExperation();
            Addition();
             cout << "\n\n                ==--------------------------------------------------------------------------==\n\n";
            continue;
        }
        else if (choice == "2")
        {
            system("cls");
            divisionExperation();
            subtraction();
            cout << "\n\n                ==--------------------------------------------------------------------------==\n\n";
            continue;
        }
        else if (choice == "3")
        {
            system("cls");
            divisionExperation();
            multiplication();
            cout << "\n\n                ==--------------------------------------------------------------------------==\n\n";
            continue;
        }
        else if (choice == "4")
        {
            system("cls");
            divisionExperation();
            dividation();
            cout << "\n\n                ==--------------------------------------------------------------------------==\n\n";
            continue;
        }
        else (choice == "5")
        ;{
            
            cout << "\n\n              **** Thank you for using FCAI Complex Number Calculator ****\n\n";
            return 0;
        }
    
    }
  
}
string displaymenu()
{
    string choice;
    cout<<endl;
    cout << "1) Add" << endl;
    cout << "2) Subtract" << endl;
    cout << "3) Multiply" << endl;
    cout << "4) Divide" << endl;
    cout << "5) Quit" << endl;
    cout << endl;
    cout << "<<<Enter the operation you want: \n>>>";
    cin >> choice;
    
    regex filter("[1-5]?");
    if (regex_match(choice, filter))
    {
        return choice;
    }
    else 
    {
        cout << "         **** invaild input! ****" << endl;
        displaymenu();
    }
   
}

string checkVaildateFirstStr()
{
    string firstComplexNum;
    cout << "\n";
    cout << "<<<Please user, Enter the first complex experation(+-num+-numi) : \n>>>" ;
    cin >> firstComplexNum;
    regex filter("[(]{1}[+-]?[0-9]+(.[0-9]*)*[+-][0-9]+(.[0-9]*)*[i][)]{1}");

    if (regex_match(firstComplexNum, filter))
    {
        return firstComplexNum;
    }
    else
    {
        cout << "         **** invaild experation! ****" << endl;
        checkVaildateFirstStr();
    }
}
string checkVaildateSecondStr()
{
    string secondComplexNum;
    cout << "\n\n";
    cout << "<<<Please user, Enter the second complex experation(+-num+-numi) : \n>>>" ;
    cin >> secondComplexNum;
    regex filter("[(]*[+-]?[0-9]+(.[0-9]*)*[+-][0-9]+(.[0-9]*)*[i][)]*");

    if (regex_match(secondComplexNum, filter))
    {
        return secondComplexNum;
    }
    else
    {
        cout << "         **** invaild experation! ****" << endl;
        checkVaildateSecondStr();
    }    
}

void divisionExperation()
{
    string firstComplexNum, secondComplexNum;
    //89-889i
    firstComplexNum = checkVaildateFirstStr();
    //72-73i
    secondComplexNum = checkVaildateSecondStr();
    int index1 = CoefficientWithoutComplexNumber(firstComplexNum);
    int index2 = CoefficientWithoutComplexNumber(secondComplexNum);
    //first input (string) from user coefficient without complex number ....>>> 89
    string FcoefWComplexNumber = substring(1, index1, firstComplexNum);
    //second input (string) from user coefficient without complex number ....>>> 72
    string ScoefWComplexNumber = substring(1, index2, secondComplexNum);

   //first input (string) from user coefficient with complex number(i) ....>>> 89
    string FcoefComplexNumber = substring(index1, firstComplexNum.size() - 2, firstComplexNum);
    //second input (string) from user coefficient with complex number(i) ....>>> 72
    string ScoefComplexNumber = substring(index2, secondComplexNum.size() - 2, secondComplexNum); 

   //FcoefWComplexNum ---->>>> first input (double) from user coefficient without complex number ....>>> 889(i)
    FcoefWComplexNum = stod(FcoefWComplexNumber);
    //ScoefWComplexNum ---->>>> second input (double) from user coefficient without complex number ....>>> 73(i)
    ScoefWComplexNum = stod(ScoefWComplexNumber);


    //FcoefWComplexNum ---->>>> first input (double) from user coefficient with complex number ....>>> 889(i)
    FcoefComplexNum = stod(FcoefComplexNumber);
    //ScoefWComplexNum ---->>>> second input (double) from user coefficient with complex number ....>>> 73(i)
    ScoefComplexNum = stod(ScoefComplexNumber);
}

void Addition()
{
    if (FcoefComplexNum + ScoefComplexNum > 0)
    {
        cout << "\n\nThe result of the operation (Addition) on this expression ----->>>>> ";
        cout << FcoefWComplexNum + ScoefWComplexNum << "+" << FcoefComplexNum + ScoefComplexNum << "i";
    }
    else if(FcoefComplexNum + ScoefComplexNum == 0)
    {
        cout << "\n\nThe result of the operation (Addition) on this expression ----->>>>> ";
        cout << FcoefWComplexNum + ScoefWComplexNum << endl;

    }
    else 
    {
        cout << "\n\nThe result of the operation (Addition) on this expression ----->>>>> ";
        cout << FcoefWComplexNum + ScoefWComplexNum << FcoefComplexNum + ScoefComplexNum << "i";
    }  
}

void subtraction()
{
    if (FcoefComplexNum - ScoefComplexNum > 0)
    {
        cout << "\n\nThe result of the operation (Subtraction) on this expression ----->>>>> ";
        cout << FcoefWComplexNum - ScoefWComplexNum << "+" << FcoefComplexNum - ScoefComplexNum << "i";
    }
    else if(FcoefComplexNum - ScoefComplexNum == 0)
    {
        cout << "\n\nThe result of the operation (Subtraction) on this expression ----->>>>> ";
        cout << FcoefWComplexNum - ScoefWComplexNum << endl;

    }
    else 
    {
        cout << "\n\nThe result of the operation (Subtraction) on this expression ----->>>>> ";
        cout << FcoefWComplexNum - ScoefWComplexNum << FcoefComplexNum - ScoefComplexNum << "i";
    }   
}



void multiplication()
{
    //without complex number
    double real = (ScoefWComplexNum * FcoefWComplexNum) + ((FcoefComplexNum * ScoefComplexNum) * -1);
    /*cout << "fW1 : " << FcoefWComplexNum << endl;
    cout << "sW1 : " << ScoefWComplexNum << endl;
    cout << "f1 : " << FcoefComplexNum << endl;
    cout << "s1 : " << ScoefComplexNum << endl;*/

    //with complex number
    double img = (FcoefComplexNum * ScoefWComplexNum) + (FcoefWComplexNum * ScoefComplexNum);
    if (img > 0)
    {
        cout << "\n\nThe result of the operation (Multiplication) on this expression ----->>>>> ";
        cout << real << "+" << img << "i";
    }
    else if(img == 0)
    {
        cout << "\n\nThe result of the operation (Multiplication) on this expression ----->>>>> ";
        cout << real << endl;

    }
    else 
    {
        cout << "\n\nThe result of the operation (Multiplication) on this expression ----->>>>> ";
        cout << real << img << "i";
    }   

}

void dividation()
{
    double real = ((FcoefWComplexNum * ScoefWComplexNum) + (FcoefComplexNum * ScoefComplexNum))/
    ((ScoefWComplexNum * ScoefWComplexNum) + (ScoefComplexNum * ScoefComplexNum));
    double img = ((FcoefComplexNum * ScoefWComplexNum) - (FcoefWComplexNum * ScoefComplexNum))/
    ((ScoefWComplexNum * ScoefWComplexNum) + (ScoefComplexNum * ScoefComplexNum));
    if (img > 0)
    {
        cout << "\n\nThe result of the operation (Dividation) on this expression ----->>>>> ";
        cout << real << "+" << img << "i";
    }
    else if(img == 0)
    {
        cout << "\n\nThe result of the operation (Dividation) on this expression ----->>>>> ";
        cout << real << endl;
    }
    else 
    {
        cout << "\n\nThe result of the operation (Dividation) on this expression ----->>>>> ";
        cout << real << img << "i";
    }   

}


/*this function return index of plus or minus in experation //89[-+]]889i to i can cut first numer 
that is without  complex Number example : 78-56i  ---->>> 78
*/
int CoefficientWithoutComplexNumber(string strComplex)//.... >>>> 89 for first input || 72 for first input
{
    for (int i = 0; i < strComplex.size(); i++)
    {
       if((strComplex[i] == '+' || strComplex[i] == '-') && (i != 0))
       {
            return i;
            break;
       }
    }
  
}

string substring(int first, int last, string str)
{
   
    string substr = ""; 
   
   
    for (int i = first; i < last; i++)
    {
        substr += str[i];
    }
    return substr;
}

 
void setTextColor(int n)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, n);
}
