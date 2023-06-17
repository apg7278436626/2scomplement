//Gerardo Morales Martinez GMProject1

#include <iostream>
#include <string>
#include <iomanip>
using namespace std ;

string strInpValidation (string rtn,int wichTest){
    if (wichTest == 1)
    {
        while (rtn != "S" and rtn != "s" and rtn != "R" and rtn != "r" and rtn != "T" and rtn != "t")
        {
            
            cout << "Don't forget that here in Planet Qwork We only have the Genders [R,r,S,s,T,t] ";
            cin>> rtn;
        }
    }else if (wichTest == 2){
        while (rtn != "y" and rtn != "Y" and rtn != "N" and rtn != "n" ){
            cout << "your Input should be \"Y or N \"";
            cin >> rtn;

        }
    }
    
    return rtn;
}

float inputValidation (int x){
    while (x<=0){
        cout <<"    ERROR : Enter a value That is Non-Zero and Positive: ";
        cin >>x;
    }

    return x;
}

float genderId (string gender){
    float x;
    if (gender == "R" or gender == "r"){
        x= 7.28;

    }else if (gender == "S" or gender == "s"){
        x= 2.82;

    }else if (gender == "T" or gender == "t"){
        x= 5.36;
    }
    return x;
    
    
}

string recTreat (float bmi,string name){
    string xtrQ,out,overide;
    cout << "\nwant to manually Overide "<<name<<"\'s BMI Index \n   HINT : for Debugging/Grading purpose \n   (Y/N)? :";
    cin >>overide;
    overide = strInpValidation(overide,2);

    if (overide == "y" or overide == "Y"){
        cout << "   What do you want your manual BMI to be ? :";
        cin>>bmi;
    }

    if (bmi >= 185){
        xtrQ="\n        Be Carefull, this habitants is \"Highly Contagious\" \n"; 
    }else if (bmi < 185 ){
        xtrQ ="\n";
    }
    
    if (bmi<75){
        out ="Mild case, no treatment Required" + xtrQ;
    }else if (bmi >= 75 and bmi <127.5){
        out = "Serious case, medication treatment " + xtrQ;
  
    }else if (bmi >=127.5 and bmi < 255){
        out =  "Acute case, ultraviolet treatment " + xtrQ;
    
    }else if (bmi >=255 and bmi < 375){
        out =  "Severe case, replacement therapy " + xtrQ;

    }else if (bmi >=375){
        out = "Extreme case, hospitalization "+ xtrQ;

    }
    
    return out;

} 

int finalQ(string treat,string name,float weight,float age, float bix,string gender,float bmi){

    cout<<"\n\nBiximent Metabolic Index Report for Patient : "<<name<<"\n";
    cout<<"  Gender: "<<gender<<"\n";
    cout<<"  Age: "<< age << " solar cycles\n" ;
    cout<<"  weight: "<<weight<< " kilograms\n";
    cout<<"  Biximent Level: "<< bix<<"\n";
    cout<<"  BMI: "<<setprecision(5)<<bmi <<"\n";
    cout<<"  Recommended treatment: "<< treat;

    return 0;

}

int mainCode (int i){
    string gender ;
    string name,treat;
    float weight, age,bixLevels,genderFactor,bmi;

    cout <<"\n\nWhat is the "<<i<<" patient name ?: ";
    cin >> name;
    cout <<"Hello ,\n Go ahead and Answer this Questions for Patient: "<<name<<". Answers [Weigth,Age,Bix Levels] must be Greater than 0";
    
    cout<<"\n\nWhat is "<<name<<" Weight : ";
    cin >> weight;
    weight = inputValidation(weight);

    cout <<"How old is "<<name<<"? in Solar Cycles: ";
    cin>> age;
    age = inputValidation(age);

    cout << "What is "<<name<<" Gender:";
    cin>>gender;
    gender = strInpValidation (gender,1);

    cout<<"What is the current Biximent Levels :";
    cin >> bixLevels;
    bixLevels = inputValidation(bixLevels);

    genderFactor= genderId(gender);
    bmi = 2.17 *age+((bixLevels*394)/(weight*genderFactor));
    treat = recTreat(bmi,name);
    finalQ(treat,name,weight,age,bixLevels,gender,bmi);
    
    return 0;

}

int main(){

    int numLoops;
    cout <<"How many Patients do you have ?";
    cin >> numLoops;

    for (int i =0;i<numLoops;i++){
        mainCode(i+1);
    }
}

