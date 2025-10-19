// Exp 9 : OOPS Project
// TUTOR HIRING SYSTEM
// Eric Pinto <23CO12>
#include<iostream>
#include<stdexcept>
using namespace std;

class tutor1  //tutor1 is the base class
 {
public:
    string name;
    int graduation, age, experience;
    tutor1(string nm):name(nm){}
    void input()
     {
        cout<<"Enter graduation (first year to be entered as 13, second year as 14 and so on): ";
        cin>>graduation;
        cout<<"Enter age: ";
        cin>>age;
     }
    void input(int e)
     {
         experience=e;
     }
 };

class tutor2:public tutor1  //tutor2 is the derived class
 {
public:
    //initializer list
    tutor2(string n):tutor1(n){}
   //applicant information
   void display()
     {
        cout<<"\nNAME: "<<name;
        cout<<"\nGRADUATION: "<<graduation;
        cout<<"\nAGE: "<<age;
        cout<<"\nEXPERIENCE: "<<experience;
        cout<<"\n------------------------------------------"<<endl;
     }
   friend void check(tutor2 &obj,int c);
};
//Friend function for checking applicants' details and displaying results
void check(tutor2 &obj,int c)
  {
    if((c==1)&&(obj.graduation>=12)&&(obj.age>=20)&&(obj.experience>4))
    {
        cout<<"\nCONGRATULATIONS "<<obj.name;
        cout<<", you have been selected as a PHYSICS tutor. Report to our institute on the 4th of November for further details.\n"<<endl;
    }
    else if((c==2)&&(obj.graduation>=12)&&(obj.age>=20)&&(obj.experience>4))
    {
        cout<<"\nCONGRATULATIONS "<<obj.name;
        cout<<", you have been selected as a CHEMISTRY tutor. Report to our institute on the 5th of November for further details.\n"<<endl;
    }
    else if((c==3)&&(obj.graduation>=12)&&(obj.age>=20)&&(obj.experience>2))
    {
        cout<<"\nCONGRATULATIONS "<<obj.name;
        cout<<", you have been selected as a MATHS tutor. Report to our institute on the 6th of November for further details.\n"<<endl;
    }
    else
    {
        cout<<"\nHARD LUCK, "<<obj.name<<" ....you couldn't make it! Better luck next time.\n"<<endl;
    }
  }

int main()
  {
    int num,choice,e;
    string n;
    cout<<"*************MENU*************\n1] PHYSICS (std 11 and 12)\n2] CHEMISTRY (std 11 and 12)\n3] MATHS (std 11 and 12)\n******************************\n";
    cout<<"\n\nEnter the number of applicants: ";
    cin>>num;
    for(int i=1;i<=num;i++)
    {
        cout<<"\nApplicant "<<i<<", enter your choice: ";
        cin>>choice;
        cout<<"Please enter your details\n";
        cout<<"Enter name: ";
        cin>>n;
        tutor2 obj(n);
        obj.input();
        //Exception handling for the experience factor
        while(true)
         {
            try{
                cout<<"Enter experience (in years): ";
                cin>>e;
                if(e<0)
                 {
                    throw invalid_argument("Experience (in years) cannot be negative.");
                 }

                obj.input(e);
                break;
               }
            catch(const invalid_argument& ex)
              {
                cout<<"Error: "<<ex.what()<<"Please enter a valid experience."<<endl;
              }
         }
        //Each applicant can choose either of the three options provided
        switch(choice)
         {
            case 1:
                cout<<"\n------------------------------------------\n-->Enrollment for the PHYSICS department";
                break;
            case 2:
                cout<<"\n------------------------------------------\n-->Enrollment for the CHEMISTRY department";
                break;
            case 3:
                cout<<"\n------------------------------------------\n-->Enrollment for the MATHS department";
                break;
            default:
                cout<<"\nInvalid input\n";
         }
    obj.display();
    check(obj,choice);
    }
    return 0;
 }

