/* Author:      Bryan Samuels (BryanSamuels2@my.unt.edu) 
   Date: 	    1 March 2022
   Instructor:  Dr. Kethineni
   Description: This program generates elementary animations based on the user input.
 */ 
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <cmath>
#include <unistd.h>
#include <algorithm>
#include <cstring>
#include <typeinfo>
using namespace std;

int main(){

    int length;
    enum Animation {Square = 1, Triangle = 2, Pentagon = 3, Sentence = 4, Quit = 5};
    Animation shapeType2;
    char animChar;
    string myStr;
    string str2;
    int shapeType;
    int counter = 0;
    int count2;
    char quit;
    int z = 0;
    int sentLen = myStr.length();
    
    srand(time(0));
    animChar = (rand() % 32) + 33;
    

    cout<<"How large?"<<endl;
    cin>> length;

    
    while (length % 2 == 0){    //this makes sure the input is odd.
        cout<<"Please enter an odd number."<<endl;
        cin>> length;
    }

    do {
    
    cout<<"What shape would you like to make?:\n"<< "1. Square\n"<< "2. Triangle\n"<< "3. Pentagon\n"<< "4. Sentence\n"<< "5. Quit\n";
    cin.ignore();
    cin>> shapeType;
    shapeType2 = static_cast<Animation>(shapeType);
    
    
    
// add sleep and clear things;
    switch (shapeType2) { 
        case Square:
	   for (int w = 0; w <= length; w++){ //controls loop duration
	   sleep(1);
	   system("clear");

           for (int i = 1; i <= w; i++){ // controls rows
                for (int j = 1; j <= w; j++){ // controls columns.
                    cout<<animChar;
                }
                cout<<endl; 
            }
	    }

            cout<<"Would you like to continue?\nEnter 'q' to quit.\nEnter any other character to continue"<<endl;
                cin>>quit;
                if (tolower(quit) == 'q'){
                    cout<<"See you next time!"<<endl;
                }
            break;

        case Triangle:
	    system("clear");
            for (int i = 1, x = 0; i <= length; ++i, x = 0){ // controls the loop duration.
                for (int j = 1; j <= length - i; ++j){ // controls spacing
                    cout<<" "; 
                }
            
                while (x != 2*i-1){ // outputs characters
                    cout<< animChar;
                    ++x;
                }
                cout<<endl; // breaks line
		        sleep(1);
            }
                cout<<"Would you like to continue?\nEnter 'q' to quit.\nEnter any other character to continue"<<endl;
                cin>>quit;
                if (tolower(quit) == 'q'){
                    cout<<"See you next time!"<<endl;
                }
            break;

        case Pentagon:
	    system("clear");
            for (int i = 1, x = 0; i <= length; ++i, x = 0){ // controls output for triangle; same as triangle until end brace.
                for (int j = 1; j <= length - i; ++j){
                    cout<<" ";
                }
            
                while (x != 2*i-1){
                    cout<< animChar;
                    ++x;
                    
                } 
                cout << endl;
		sleep(1);
                }
                for (int i = 1; i < length; ++i){ // controls duration of loop for rectangle
                    for (int j = 0; j < (length * 2) - 1; ++j){ // outputs characters
                        cout<<animChar;
                    }
                    cout<<endl; // breaks the line
		    sleep(1);
               }
               cout<<"Would you like to continue?\nEnter 'q' to quit.\nEnter any other character to continue"<<endl;
                cin>>quit;
                if (tolower(quit) == 'q'){
                    cout<<"See you next time!"<<endl;
                }
                    break;

            case Sentence: 
                
                

                cout<< "Please enter a Sentence. "<<endl;
                cin.ignore();
                getline(cin, myStr); // allows the user to enter multiple words.
		        system("clear");

                counter = 1;
                cout<<myStr<<endl;
                

                while (z < myStr.length()){ // controls loop duration
                    if (isdigit(myStr.at(z))){ // checks for numbers
                        while (isdigit(myStr.at(z))){ // clears and slows output also counts digits
                            sleep(1);
                            system("clear");
                        for (int i = 0; i < counter; ++i){ // outputs the digits' number of empty lines.
                            cout<<endl;
                        }
                            ++counter;
                            myStr.replace(z, 1, ""); // removes the number
                            sentLen = myStr.length(); // keeps track of  the size.
                            cout<<myStr<<endl; // outputs the new sentence.
                            if (z >= sentLen){
                                break;
                            }
                        }
                    }
                    ++z;
                }

                cout<<"Would you like to continue?\nEnter 'q' to quit.\nEnter any other character to continue"<<endl;
                cin>>quit;
                if (tolower(quit) == 'q'){
                    cout<<"See you next time!"<<endl;
                }
                break;


                case Quit:
                cout<<"See you next time!"<<endl;
                exit(0); //ends program

                default:
                cout<<"Your input was invalid."<<endl;
                cout<<"Would you like to continue?\nEnter 'q' to quit.\nEnter any other character to continue"<<endl;
                cin>>quit;
                if (tolower(quit) == 'q'){ // ends the program only if the user enters q
                    cout<<"See you next time!"<<endl;
                    exit(0);
                }
                
               
    } 
    }while(tolower(quit) != 'q'); // continues until the user enters q.

    




            

    return 0;
}