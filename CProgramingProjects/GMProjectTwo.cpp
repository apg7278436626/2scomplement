//Gerardo Morales Martinez Project1
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Checks if you are able to open File
void fileValidation (string& fileName){
    ifstream inputFile;
    bool x=true;
    while(x==true){
        inputFile.open(fileName);
        if(inputFile){
            x=false;
            break;
        }
        inputFile.close();
        cout << "    ERROR : Your File was not able to open Please try Again : ";
        cin >>fileName;
    }
}

// this function tells the computer how many items are on a Text files, Usually to creat a preset array, or how many times it should loop 
int fileLen (string fileName){
    ifstream fileIn;
    string x;

    fileIn.open (fileName);

    int i =0;
    //while there's an input add 1 to i 
    while (fileIn >> x){
        i= i+1;
    }
    fileIn.close ();
    return i;
}

//this function takes in a file name and generates an array so the computer can do something with it 
void makeArrayFromFile (string* array , string fileName ){

    ifstream fileIn ;
    string placeHol;

    fileIn.open (fileName);

    int i = 0;
    while (fileIn >> placeHol){
        array [i]= placeHol;
        i = i +1;    
    }
    fileIn.close ();    
}

//Simply prints an  string array. 
void arrayPrinter (string* array , int lenght){
    for (int i=0; i < lenght;i++){
        cout <<endl<< array [i];
    }
    cout << endl << endl;
}

//simply prints out an integer array
void intArrayPrinter (int* array , int lenght){
    for (int i=0; i < lenght;i++){
        cout <<endl<< array [i]<<endl;
    }
    cout << endl << endl;
}

//this function makes sure that the input from the user is in a designated array
//it also allows the user to enter Q,q,Quit,quit to end the program
string footballTeamValidation (string fTeam,int arrayLen ,string* teamHigh,bool* breaker){
    
    while (true){
        bool z=true;
        //this loop checks if a string is in the array while also repeating asking the user to input an answer in the array.
        for (int i =0 ; i< arrayLen ; i++){
            if (fTeam == teamHigh [i]){
                fTeam = teamHigh [i];
                z=false;
                break;
            }
        }
        //if it likes the imput it will break the while loop and return the answer 
        if (z == false){
            break;
        }
        //this allows the user to enter a breaking point for the Whole loop.
        if (fTeam == "quit" or fTeam == "q" or fTeam == "Q" or fTeam == "Quit"  ){
            breaker [0] = false;
            cout << "Thanks Have a Good Day \n";
            break;
        }
        //This prints out all possible answers it could accept 
        cout << "\nPlease enter a Valid NFL Team with the first Letter to be capital : ";
        for (int i = 0 ; i < arrayLen; i++){
            cout << teamHigh [i] << " | ";      
        }
        cout << "\n Enter a Valid Name Listed above : ";
        cin >> fTeam;   
    }
    return fTeam;
}

//This functions checks how many time a string is in a list
void numTimesOnList (string team , int arrayLen, string* array,int which,int* sum,int* numTimesOnLs) {
    
    //I didin't want to make 2 functions so I re-used it but made two seperate parts.
    if (which == 1 ){
        //This checks how many times it is in a list and ads it into  an array
        for (int i =0; i<arrayLen ; i++){
            if (team == array[i]){
            //I had problems compiling with Int variable so I had to use an array;
            sum[0] = sum [0]+1;
            }
        }
    }
    
    //this just tells the computer to add something into the first slop of an array
    int times = 0;
    if (which == 2){
        for (int i =0; i<arrayLen ; i++){
            if (team == array[i]){
                //it adds the slot where the value exist in the array
                numTimesOnLs[times] = i+1;
                //this just tells the computer to fill the next spot in the array
                times = times +1 ;
            }
        }
    }
}

//this just prints out the years where the football team won
void finalQ (int* array,int leng){
    for (int i =0;i<leng;i++){
        if (i!= leng-1){
            int out = array[i];
            out = out + 1966;
            cout << out << " and ";
        }else{
            int out = array[i];
            out = out + 1966;
            cout << out<<"\n\n" ;

        }
        
    }

}

void mainCode (bool* breaker,string* superBowlWinners,string* nflTeams,int superBowlWinnerLen,int nflTeamLen){
    string footballTeam ;
    
    cout << "What football team do you want to See stats ?: ";
    cin >> footballTeam;
    footballTeam = footballTeamValidation (footballTeam,nflTeamLen,nflTeams,breaker);

    int sum [2] ,dummyArr[2];
    int dummyVar ;

    sum [0] = 0;
    dummyVar = 0;

    numTimesOnList (footballTeam,superBowlWinnerLen,superBowlWinners,1,sum,dummyArr);
    dummyVar =sum [0];

    int numTimeOnLs [dummyVar];

    numTimesOnList (footballTeam,superBowlWinnerLen,superBowlWinners,2,sum,numTimeOnLs);
    //intArrayPrinter (numTimeOnLs,dummyVar);
    
    if (breaker [0] == true){
        if (sum[0] > 0){
            cout << "\n\n The "<< footballTeam << " Have won "<< dummyVar<< " times on ";
            finalQ (numTimeOnLs,dummyVar);
            cout <<endl;

        }else{
            cout << "\n\nThe "<< footballTeam << " Have not won any SuperBowls from 1967 - 2022 \n";

        }

    }
}

int main (){
    string teamFileName,winnerFileName;
    cout << "What is the NFL Team file name :";
    cin >> teamFileName;
    fileValidation(teamFileName);

    cout << "What is the Super Bowl Winners file name :";
    cin >> winnerFileName;
    fileValidation(winnerFileName);

    const int nflTeamLen = fileLen (teamFileName);
    const int superBowlWinnerLen = fileLen (winnerFileName);

    string nflTeams[nflTeamLen],superBowlWinners[superBowlWinnerLen] ;

    makeArrayFromFile (nflTeams , teamFileName);
    makeArrayFromFile (superBowlWinners, winnerFileName);
//I was having ussies compyling pointer variables so I had to Use a pointer array
    bool breaker [2];
    breaker [0]=true;
    cout << "\n\nSuper Bowl Winners\nThis program will tell you how many times and in which years a\nfootball team won the Super Bowl. Enter a name of 'quit' to exit.\n\n";
    while (breaker[0] != false){
        mainCode (breaker,superBowlWinners,nflTeams,superBowlWinnerLen,nflTeamLen);
    }
}
