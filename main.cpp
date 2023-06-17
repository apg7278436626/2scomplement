#include<iostream>

using namespace std;
class gupta
{
    protected:
    int rollno;
    char * name;
    int age;
    public :
    gupta(){cout<<"gupta constructor";}
    gupta(int r,char * s,int a)
    {
    rollno=r;
    name=s;
    age=a;
    }
    ~gupta()
    {
    cout<<"ANKIT , tata good bye";
    }
    void get(void){
        cout<<rollno<<endl<<name<<endl<<age<<endl;
    }
}g3;
class didi : public gupta{
    char * add;
public:
    didi(int r, char * s,int a, char * adr):gupta(r,s,a){
        add=adr;
    cout<<"inside didi constructor";
    }
    void get(void){
        cout<<rollno<<endl<<name<<endl<<age<<endl<<add<<endl;
    }
};

int main()
{
    gupta g1(1,"ANKIT PRASAD GUPTA",5);
   cout<<"hello world"<<endl;
   g1.get();
   didi d2(1,"PRIYANKA",50,"malda");
   d2.get();
return 0;

}

