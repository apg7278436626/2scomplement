//Gerardo Morales Martinez Project Three
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

struct Element 
{
    string symbol;
    string name;
    int atomicNumber;
    double atomicWeight;
    bool active;
};

void dasher (int len){
    for (int i=0;i<len;i++){
        cout <<"-";
    }
    cout <<"   ";

}

void title(int which){
    string topSentece,x,bottomSentence,z;
    string options[6]={"Define a chemical element.","Search for an element.","Change the visibility of an element.","Define the elements from text file.","Display the elements sorted by symbol. ","Quit."};

    if (which == 1){
        x.assign(23,' ');
        topSentece = x+ "Atomic   Atomic  \n";
        cout << topSentece<<left <<setw(9)<<"Symbol"<<left<<setw(14)<<"Name"<<left<<setw(9)<<"Number"<<right<<setw(7)<<"Weight\n";
        dasher(6);dasher(11);dasher(6);dasher(7);
    }else if (which == 2){
        cout<<"\n\n\nSelect an option number number from the following menu :\nOption   Action\n";
        dasher(6);dasher(57);
        cout <<endl;
        for (int i=0;i<6;i++){
            int j=i+1;
            cout << "   "<<j<<"     "<<options[i]<<"\n";
        }
        //cout <<"Enter your choice: ";
    }
}

void fileValidation (string& fileName){
    ifstream inputFile;
    cout <<"What is the Name of the file or \'a\' for auto : ";
    cin>> fileName;
    bool x=true;
    while(x==true){
        inputFile.open(fileName);
        if(inputFile || fileName == "a"){
            x=false;
            break;
        }
        inputFile.close();
        cout << "    ERROR : Your File was not able to open Please try Again : ";
        cin >>fileName;
    }
}

void arrayPrinter (Element* array, int len){
    //cout <<len <<endl;
    title(1);
    cout <<endl;
    for (int i=0;i<len;i++){
        cout <<setw(8)<<left<<array[i].symbol<<" ";
        cout <<setw(14)<<left<<array[i].name;
        cout <<setw(7)<<array[i].atomicNumber;
        cout <<setw(9)<<right<<array[i].atomicWeight<<"\n";
    }   
}

void option1 (Element* elements,int& totalFileElements,int& maxElements){
    int i=1;
    string tempElementSymbol;

    cout <<"\n\nPlease enter the Element\'s Symbol, Name, Atomic Number, and Atomic Weight\n   ***Keep In mind that you can add as many as you wish all at once\n   ***Once you are done adding Elements Enter \"Done\" when asked for Symbol\n";
    while (totalFileElements <= maxElements){
        cout <<"\n\n   ***If you do Not have any more Elements Enter \"Done\" \n\n      Please enter the "<<i<<" element\'s Symbol : ";
        cin>> tempElementSymbol;
        if (tempElementSymbol == "Done" || tempElementSymbol == "done"){
            i=i-1;
            cout << "   Thanks for adding "<<i<<" Elements \n\n";
            break;
        }        
        
        bool x;
        while (true){
            x=false;
            for (int j=0;j<totalFileElements;j++){
                if (elements[j].symbol == tempElementSymbol){
                    cout<<"      *** "<<tempElementSymbol <<" Has already been entered, Please enter another value : ";
                    cin>>tempElementSymbol;
                    x=true;
                }
            }
            if (x==false){
                elements[totalFileElements].symbol=tempElementSymbol;
                break;
            }
        }

        cout <<"   What is "<<elements[totalFileElements].symbol<<" Name : ";
        cin >> elements[totalFileElements].name;
        
        cout <<"   What is "<<elements[totalFileElements].name<<" Atomic Number  : ";
        cin >> elements[totalFileElements].atomicNumber;
        
        cout <<"   What is "<<elements[totalFileElements].name<<" Atomic Weight  : ";
        cin >> elements[totalFileElements].atomicWeight;
        i++;
        totalFileElements++;
    }
}

void option2 (Element* elements,int& totalElementsStored){
    string whichElement;
    cout << "\n\nWhat Element do you want to see ? :";
    cin >> whichElement;

    bool found = false;
    for (int i=0;i<totalElementsStored;i++){
        if (elements[i].symbol == whichElement){
            title(1);
            cout <<"\n"<<setw(8)<<left<<elements[i].symbol<<" ";
            cout <<setw(14)<<left<<elements[i].name;
            cout <<setw(7)<<elements[i].atomicNumber;
            cout <<setw(9)<<right<<elements[i].atomicWeight<<"\n";
            found = true;
        }
    }
    if (found == false){
        cout <<"Currently "<<whichElement<<" is not stored please select Option 1 to add the values\n";
    }
}

void option3 (Element* elements,int& totalElementsStored){
    string whichElement;
    cout << "\n\nWhat Element do you want to Be active ? :";
    cin >> whichElement;
    //whichElement=toupper(whichElement[0]);

    bool x=false;
    for (int i=0;i<totalElementsStored;i++){
        if (elements[i].symbol == whichElement){
            elements[i].active = false;
            cout<< "\nSucces\n";
            x=true;
        }
    }
    if (x==false){
        cout <<"Currently , "<<whichElement<<" is not stored please select Option 1 to add the values Than try again \n";
    }
}

void option4 (Element* elements,int& totalElementsStored){
    ifstream file;
    string x,filename;
    fileValidation (filename);
    if (filename == "a"){
        filename ="elements.txt";
    }

    int j,atomicNum;
    double weight;

    file.open (filename);
    j=0;
    bool z=true;
    while (file>>x){
        if (j==0){
            for (int i=0;i<totalElementsStored;i++){
                if (x==elements[i].symbol){
                    z=false;
                }
            }
            if(z==true){
                elements[totalElementsStored].symbol=x;
            }
            j++;
            continue;
        }else if (j==1){
            if(z==true){
                elements[totalElementsStored].name=x;
            }           
            j++;
            continue;
        }else if (j==2){
            if(z==true){
                atomicNum = stoi(x);
                elements[totalElementsStored].atomicNumber = atomicNum;                
            }
            j++;
            continue;
        }else if (j==3){
            if(z==true){
                weight = stod(x);
                elements[totalElementsStored].atomicWeight = weight; 
                totalElementsStored++;               
            }
            j=0;
            z=true;
            continue;
        }
    }
    file.close();
}

void swap(Element* elements,int i){
    Element Temp;
    Temp = elements[i];
    elements[i]=elements[i+1];
    elements[i+1]=Temp;
    
}

void option5 (Element* element,int& totalElementsStored){
    for (int j=0;j<totalElementsStored;j++){
        for (int i=0;i<(totalElementsStored-1);i++){
            if (element[i].symbol> element[i+1].symbol){
                swap(element,i);
            }
        }
    }
}

int main (){
    int totalElementsStored=0;
    const int totalElements = 118;
    int maxElements = totalElements;
    Element elements[totalElements];

    string option;
    title(2);
    while (true){
        cout<<"which option : ";
        cin >> option;
        if (option == "1"){
            option1(elements,totalElementsStored,maxElements);
        }else if (option == "2"){
            option2(elements,totalElementsStored);
        }else if (option == "3"){
            option3(elements,totalElementsStored);
        }else if (option == "4"){
            option4(elements,totalElementsStored);
        }else if (option == "5"){
            option5(elements,totalElementsStored);
            arrayPrinter(elements,totalElementsStored);
        }else if (option== "6"){
            cout<<"Thanks Have a Good One \n";
            break;     
        }else{
            title(2); 
        }
    }
    return 0;
}