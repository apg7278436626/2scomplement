//Gerardo Morales Lab8
#include <iostream>
#include <string>
using namespace std;

int intInputValidation (int input,string name){
    while (input >40){
        cout <<"\n\n\tERROR: "<<name<< "\'s score should be less than 40 :";
        cin>> input;
    }
    return input;
}

string strInputValidation (string input){
    if (input =="Q" || input =="q" || input =="quit" || input =="Quit"){
        input = "q";
    }
    return input;
}

void arrayPrinter (string* strArray ,int* intArray ,int size){
    cout <<"\n\nThese are the players Rated from Highest to Lowest Scores:\n"; 
    for (int i=0;i<size;i++){
        cout <<"\t "<< i+1<<") "<< strArray[i]<<" Score : "<< intArray[i]<<endl;
    }
    
    
}

int golfersData (string* namesArray , int* scores,int size){
    string name;
    int score,len;
    len =0;
    for (int i=0 ; i<size;i++){
        cout <<"\n\nIf you There aren\'t any more user\'s enter \'Q\'\nWhat is the name of "<<i+1<<" golfer: ";
        getline(cin,name);
        name = strInputValidation (name);
        
        if (name == "q"){break;}
        len++;
        namesArray[i] = name;

        cout <<"what is "<<name<< " score? :";
        cin >> score;
        score = intInputValidation (score,name);
        scores[i]=score;
    }
    return len;

}

void swap(string* names,int* scores,int i){
    int intTemp=scores[i];
    string strTemp=names[i];

    scores[i]=scores[i+1];
    scores[i+1]= intTemp;

    names[i]=names[i+1];
    names[i+1]=strTemp;
}

void arraySorter (string* namesArray , int* scores,int size){
    for (int j=0;j<size;j++){
        for (int i=0;i<size-1;i++){
            if (scores[i] < scores[i+1]){
                swap(namesArray,scores,i);   
            }
        }
    }
}

int main (){
    int amountGolfers,arrayLen;
    
    amountGolfers= 24;
    string golferName[amountGolfers];
    int golferScores[amountGolfers];

    cout <<"Please Enter Golfer\'s Name 1st and Their Score 2nd\n";
    arrayLen = golfersData (golferName,golferScores,amountGolfers);
    arraySorter(golferName,golferScores,arrayLen);
    arrayPrinter(golferName,golferScores,arrayLen);

    return 0;
}