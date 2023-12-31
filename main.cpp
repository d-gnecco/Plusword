#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    char plusgrid[5][5] = {
                { '-', '-', '-', '-', '-' },
                { '-', '-', '-', '-', '-' },
                { '-', '-', '-', '-', '-' },
                { '-', '-', '-', '-', '-' },
                { '-', '-', '-', '-', '-' }
                };
    
    /*            
    char plusgrid[5][5] = {
                { 'A', 'P', 'P', 'A', 'L' },
                { 'N', 'O', 'R', 'S', 'E' },
                { 'G', 'R', 'I', 'P', 'E' },
                { 'S', 'T', 'O', 'I', 'C' },
                { 'T', 'O', 'R', 'C', 'H' }
                };
    */
    
    string cluegrid[5][5] = {
                { "1", "2", "3", "4", "5" },
                { "6", "7", "8", "9", "10" },
                { "11", "12", "13", "14", "15" },
                { "16", "17", "18", "19", "20" },
                { "21", "22", "23", "24", "25" }
                };
                
    char answergrid[5][5] = {
                { 'A', 'P', 'P', 'A', 'L' },
                { 'N', 'O', 'R', 'S', 'E' },
                { 'G', 'R', 'I', 'P', 'E' },
                { 'S', 'T', 'O', 'I', 'C' },
                { 'T', 'O', 'R', 'C', 'H' }
                };
    
    string command;
    string subcommand;
    string guess;
    int x_index;
    int y_index;
    
    //print
    cout << "+-------------------x\n";
    for(int x = 0; x < 5; x++)
            {
                cout << "|";
                for(int y = 0; y < 5; y++)
                {
                    cout << "[" << plusgrid[y][x] << "] ";
                }
                cout << endl;
            }
    cout << "y\n";
            
    cout << "\nEnter command: (Q = Quit, G = Guess, C = Clue)\n\n";
    getline(cin, command);
            
    while(command != "q" || command != "Q")
    {
        if(command == "g" || command == "G")
        {
            cout << "\nEnter command in form of: guess,x_index(1-5),y_index(1-5)\n\n";
            getline(cin, guess);
            
            x_index = stoi(guess.substr(2,3));
            y_index = stoi(guess.substr(4));
            plusgrid[y_index - 1][x_index - 1] = toupper(guess[0]);
            
        }
        else if(command == "c" || command == "C")
        {
            cout << "\nEnter command in form of: x_index(1-5),y_index(1-5)\n\n";
            /*getline(cin, guess);
            
            x_index = stoi(guess.substr(2,3));
            y_index = stoi(guess.substr(4));
            
            cout << cluegrid[y_index - 1][x_index - 1] <<*/
        }
        else
        {
            cout << "\n" << command << " is NOT a recognized command\n";   
        }
        
        //print
        cout << "+-------------------x\n";
        for(int x = 0; x < 5; x++)
        {
            cout << "|";
            for(int y = 0; y < 5; y++)
            {
                cout << "[" << plusgrid[y][x] << "] ";
            }
            cout << endl;
        }
        cout << "y\n";
            
        //check
        bool solved = true;
        for(int x = 0; x < 5; x++)
        {
            if(!solved)
            {
                break;
            }
            for(int y = 0; y < 5; y++)
            {
                if(!solved)
                {
                    break;
                }
                if(plusgrid[y][x] != answergrid[y][x])
                {
                    solved = false;
                    break;
                }
            }
        }
        if(solved)
        {
            cout << "\nCONGRATULATIONS! YOU ARE A PLUSLORD OF THE PLUSWORD :)\n";
            command = "Q";
        }
        else
        {
            cout << "\nEnter command: (Q = Quit, G = Guess, C = Clue)\n\n";
            getline(cin, command);
        }
    }
}