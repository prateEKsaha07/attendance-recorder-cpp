#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
using namespace std;

void header();  //defined
int admin_view(); // defined
int admin_login(); // define 
int student_view(); // half defined 
int student_login(); // defined 
int register_student(); //defined 
int delete_student_by_rollNo();
int get_all_student_by_roll_number();
int _check_present_count_by_rollNo();



int delay();
int check_credential(string username,string password);

void header(){
        cout<<"----------------------------------"<<endl;    //tried something new
        cout<<"   attendance management system   "<<endl;
        cout<<"----------------------------------"<<endl;
}
int admin_view(){
    int goBack = 0;
    while (1){
        system("cls");
        header();
        cout<<"           ADMIN LOGIN            "<<endl;
        cout<<"----------------------------------"<<endl;
        cout <<"1--> register a student "<<endl;
        cout <<"2--> delete all student name "<<endl;
        cout <<"3--> check list of student registered by user name "<<endl;
        cout <<"4--> check present count of any student by roll number "<<endl;
        cout <<"5--> get present count of any student by roll number "<<endl;
        cout <<"6--> delete student by roll number "<<endl;
        cout <<"0--> go back "<<endl;
        cout<<"----------------------------------"<<endl;

        int choice ;
        cout << "--> enter your choice :: ";
        cin >> choice ;

        switch(choice){
            case '1':
            break;               //didn't declared ant of them
            case '2':
            break;
            case '3':
            break;
            case '4':
            break;
            case '5':
            break;
            case '6':
            break;
            case '0': goBack= 1; break;
            default:
            cout<<"invalid selection try again!!";
            getchar();
        }if(goBack == 1){
            break;
        }
    }
    return 0;
}                                          //general function definition is complete need to define those sub functions 
int student_login(){                        //defined 
    system("cls");
    header();
    cout<<"          STUDENT LOGIN           "<<endl;
    cout<<"----------------------------------"<<endl;
    student_view();
    cout<<"----------------------------------"<<endl;
    delay();
    return 0;
}
int student_view(){
    string username ,password;
    cout << "enter username :: "<< endl;
    cout << "enter password :: "<< endl;
    int res = check_credential(username,password); //have to define it later 
    if (res == 0 ){
        cout <<"/n invalid credentials !!";
        cout <<"/n press any key for main menu ..";
        getchar();
        return 0;
    }
    int goBack = 0 ;
    while (1){
        system ("cls");
        cout<<"1-->mark attendance for today "<<endl;
        cout<<"2-->count my attendance "<<endl;
        cout<<"0-->go back  "<<endl;

        int choice ;
        cout <<"--> enter your choice :: ";
        cin >> choice ;

        switch (choice)
        {
        case '1':break;
        case '2':break;
        case '0': goBack =1 ; break;        
        default: cout <<" invalid choice ! enter again .. "; break;
        getchar();
        }if(goBack ==1 ){
            break; //just break it here !!
        }
    }
}

int delay(){
    for (int i = 0; i < 3; i++){
        cout<<"\n record saving....";
        for (int j = 0; j < 20000; j++){
            for (int k = 0; k < 20000; k++){
            }
        }
    }
    cout<<"\n exiting now ....!";
    for (int i = 0; i < 3; i++){
        cout<<"\n record saving....";
        for (int j = 0; j < 20000; j++){
            for (int k = 0; k < 20000; k++){
            }
        }
    }
}
int register_student(){
    header();
    cout <<"           registration           "<<endl;
    cout <<"----------------------------------"<<endl;
    string name,username,password,check,address,fatherName,motherName;
    int roll_number;
    cout <<"entr your name :: ";
    getline(cin,name);
    cout <<"please dont use any spaces while entering password"<<endl;
    cout <<"enter your password :: " ;
    cin>>password;
    cout << "please re enter your password :: ";
    cin >> check;
    if (password == check){
        cout <<"your password is acceptable !!"<<endl;
        cout <<"your may continue to fill the rest of the form ."<<endl;
    }else{
        cout<<"passwords are not matching "<<endl;
    }
    cout << "enter your roll number :: ";
    cin >> roll_number;
    cout <<"entr your father's name :: ";
    getline (cin , fatherName);
    cout << "enter your mother's name :: ";
    getline(cin,motherName);
    cout <<"enter your residence address :: ";
    getline(cin,address);

        //check if the records are already available 
    ifstream read ;
    read.open("database.dat");

        if (read){
            int recordFound = 0;
            string line ;
            while (getline(read,line)){
                if(line == username+".dat"){
                    recordFound = 1 ;
                    break;
                }
            }
            if(recordFound == 1){
                cout <<"the username is already exist in the database..."<<endl;
                cout << "please chose another username !"<<endl;
                getchar();
                delay();
            read.close();
            return 0;
            }
        }
        read.close();
        ofstream out;
            out.open("database.dat",ios :: app);
        out.close();

        ofstream out1;
            string temp = username+".dat";
            out1.open(temp.c_str());
            out1<<name<<"\n";
            out1<<username<<"\n";
            out1<<password<<"\n";
            out1<<roll_number<<"\n";
            out1<<fatherName<<"\n";
            out1<<motherName<<"\n";
            out1<<address<<"\n";
        out1.close();

    cout<<"\n student has bee registered successfully ";
    cout<<"\n press any ley to continue !! ";
        getchar();
return 0 ;
}
int mark_my_attendance(string username){                //will start from here tomorrow .....
    cout << "mark my attendance for today.  "<<endl;
    cout <<"enter any key to continue. "<<endl;
    // note : havto complete this function  later...
    getchar();
    return 0;
} 
int _check_present_count_by_rollNo(){
    cout<<"check present count by roll number ";
    cout<<"press any key to continue ";
    getchar();
    return 0;
}

int count_my_attendance(string username){
    cout <<"count my attendance"<<endl;
    cout <<"entr key to continue"<<endl;
    // note : incomplete function .....
}
int check_all_present_count_by_rollNumber(){
    cout<<"check all present count by rollnumber"<<endl;
    cout<<"press any key to continue "<<endl;
    getchar();
    return 0;
}
int get_all_student_by_name(){
    cout<<"get all student by name"<<endl;
    cout <<"press any key to continue"<<endl;
    getchar();
    return 0;
}
int delete_student_by_rollNo(){          //goin to start from here tomorrow
    cout<<"\n delete student by roll number";
    cout<<"\n press any key to continue ";
    getchar();
    return 0;
}
int get_all_student_by_roll_number(){
    cout <<"list all student by their roll number "<<endl;
    cout <<"please enter any key to continue "<<endl;
    getchar();
    return 0;
}                                      
int admin_login(){
    system("cls");
    header();
    cout <<"          admin login            "<<endl;
    cout<<"----------------------------------"<<endl;
    string username ;
    string password ;
    cout <<" enter your username :: ";
    cin>>username;
    cout << "enter your password ";
    cin>>password;
    if (username=="admin" && password == "prateek"){
        admin_view();
        getchar();
        delay();
    }else{
        cout <<"error: invalid credentials !! "<<endl;
        cout << "press any key for the main menu" <<endl;
        getchar();
    }
    return 0;
}
int main(int argc , char**_argv){
    while(1){
        system("cls");
        header();
        cout <<"1--> student login "<<endl;
        cout <<"2--> admin login "<<endl;
        cout <<"0--> to exit "<<endl;

        cout<<"----------------------------------"<<endl;
        
        int choice;
        cout <<"-->Enter your choice :: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            student_login(); //defined 
            break;
        case '2':
            admin_login();  //defined 
            break;
        case '0':
            while(1){
                system("cls");
                cout <<"are you sure ! you want to exit the program ? (y/n) "<<endl;
                char exit_choice;
                cin>> exit_choice;
                if (exit_choice =='y' || exit_choice == 'Y')
                exit (0);
                else if (exit_choice == 'n' || exit_choice == 'N'){
                    break;
                }else{
                    cout<<"invalid choice !! "<<endl;
                    getchar();
                }
            }
            break;
        default:
        cout <<"invalid choice ! please enter again --> "<<endl;
        getchar();
        }
    }
    return 0;
}