#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void delete_course_details() {
    string course_name;
    cin.ignore();
	cout << "Enter name of course: ";
	getline(cin,course_name);
    char confirm;
    ifstream file1("change course details.txt");
    ofstream file2("delete course.txt");
    if (!file1.is_open()) {
        cout << "ERROR OPENING FILE !" << endl;
        return;
    }
    if (!file2.is_open()) {
        cout << "ERROR OPENING TEMPORARY FILE!" << endl;
        return;
    }

    bool found = false;

    string line;
    while (getline(file1, line)) {
        if (line.find("COURSE NAME: " + course_name) != string::npos) {
            found = true;
            cout << "\nCourse found. Are you want to delete it.Enter  (Y/y): ";
            cin>>confirm;
            if (confirm == 'Y' || confirm == 'y') {
                while (getline(file1, line) && line != "__________________________________") {
                    // Skip the lines related to the course being deleted
                }
                continue;
            }
        }
        file2 << line << endl;
    }
    file1.close();
    file2.close();
    remove("change course details.txt");
    rename("delete course.txt", "change course details.txt");
    if (found) {
        cout << "\nCourse deleted successfully." << endl;
    } else {
        cout << "\nCourse not found." << endl;
    }
}
void delete_student_details()//create function is used to delete student details
{
    string NIC;
    cin.ignore();
	cout << "Enter STUDENT NIC: ";
	getline(cin,NIC);
    char confirm;
    ifstream file1("register student details.txt");
    ofstream file2("delete student details.txt");
    if (!file1.is_open()) {
        cout << "ERROR OPENING FILE !" << endl;
        return;
    }
    if (!file2.is_open()) {
        cout << "ERROR OPENING TEMPORARY FILE!" << endl;
        return;
    }

    bool found = false;

    string line;
    while (getline(file1, line)) {
        if (line.find(NIC) != string::npos) {
            found = true;
            cout << "\nID found. Are you want to delete it.Enter  (Y/y): ";
            cin>>confirm;
            if (confirm == 'Y' || confirm == 'y') {
                while (getline(file1, line) && line != "__________________________________") {
                    // Skip the lines related to the course being deleted
                }
                continue;
            }
        }
        file2 << line << endl;
    }
    file1.close();
    file2.close();
    remove("register student details.txt");
    rename("delete student details.txt", "register student details.txt");
    if (found) {
        cout << "\n deleted successfully." << endl;
    } else {
        cout << "\nID NOT FOUND." << endl;
    }
}
void change_course_details()//create function is used to add courses
{
    string name, uni_code, duration, fee, week, weekend, start_date, enroll_stu, available;// Declare variables to store course details
    char option;
    fstream file;// Open the file
    do {// Perform course details entry in a loop
        cout << "ADD NEW COURSE, PLEASE ENTER:" << endl;
        cin.ignore(); //any remaining newline characters or other unwanted characters in the buffer after reading input from
        cin.clear();
        cout << "\t\tCOURSE NAME      : ";// Prompt for and get course details from the user
        getline(cin, name);// using getline() to handle input with spaces
        cout << "\t\tCOURSE UNI CODE  : ";
        getline(cin, uni_code);
        cout << "\t\tDURATION         : ";
        getline(cin, duration);
        cout << "\t\tCOURSE FEES      : ";
        getline(cin, fee);
        cout << "\t\tWEEK DAYS AVAILABLE        : ";
        getline(cin, week);
        cout << "\t\tWEEKEND DAYS AVAILABLE     : ";
        getline(cin, weekend);
        cout << "\t\tCOURSE START DATE          : ";
        getline(cin, start_date);
        cout << "\t\tENROLL STUDENTS FOR COURSE : ";
        getline(cin, enroll_stu);
        cout << "\t\tCOURSE ARE AVAILABLE       : ";
        getline(cin, available);
        // Display entered course details
        cout << "\t\tCOURSE NAME      : " << name << endl;
        cout << "\t\tCOURSE UNI CODE  : " << uni_code << endl;
        cout << "\t\tDURATION         : " << duration << endl;
        cout << "\t\tCOURSE FEES      : " << fee << endl;
        cout << "\t\tWEEK DAYS AVAILABLE        : " << week << endl;
        cout << "\t\tWEEKEND DAYS AVAILABLE     : " << weekend << endl;
        cout << "\t\tCOURSE START DATE          : " << start_date << endl;
        cout << "\t\tENROLL STUDENTS FOR COURSE : " << enroll_stu << endl;
        cout << "\t\tCOURSE ARE AVAILABLE       : " << available << endl;
        file.open("change course details.txt", ios::out | ios::app);// file is opened for output, and  appending new content to the existing file
        if (!file.is_open()) {
            cout << "ERROR OPENING FILE FOR WRITING ! " << endl;
            return;
        }
        // Write the entered course details to the file
        file << "COURSE NAME: " << name << "\n\n";
        file << "COURSE UNI CODE: " << uni_code << "\n\n";
        file << "DURATION: " << duration << "\n\n";
        file << "COURSE FEES: " << fee << "\n\n";
        file << "WEEK DAYS AVAILABLE: " << week << "\n\n";
        file << "WEEKEND DAYS AVAILABLE: " << weekend << "\n\n";
        file << "COURSE START DATE: " << start_date << "\n\n";
        file << "ENROLL STUDENTS FOR COURSE: " << enroll_stu << "\n\n";
        file << "COURSE ARE AVAILABLE: " << available << "\n\n";
        file << "__________________________________" << "\n\n";
        file.close();
        cout << "\n\nDO YOU WANT TO ADD A NEW COURSE? PLEASE TYPE '1' FOR YES OR '2' FOR NO:\n\n ";
        cin >> option;//input your choice
        cin.ignore();//any remaining newline characters or other unwanted characters in the buffer after reading input from
    } while (option == '1');
    cout << "COURSE ADDED\n\n" << endl;
    if(option == '2'){
            cout<<"\nEXIT\n";
    }
    file.close();
}
void Viewing_course(){//create function is used to view courses
    string line;
    fstream file;// Declare a file stream object
    file.open("change course details.txt",ios::in);// Open the file read mode
    // Read and display each line of the file
    while(getline(file,line)){
            cout<<line<<"\n";
    }
    file.close();

    }
void change_company_details(){//create function is used to change company details
    string enter,address,email,phonenumber;
    cin.ignore();//any remaining newline characters or other unwanted characters in the buffer after reading input from
    cin.clear();
    cout<<"\nCHANGE COMPANY DETAILS:\n";
    cout<<"WHO WE ARE:";
    getline(cin,enter);// Prompt for and get course details from the user
    cout<<"ADDRESS:";
    getline(cin,address);
    cout<<"EMAIL:";
    getline(cin,email);
    cout<<"PHONE NUMBER:";
    getline(cin,phonenumber);

    cout << "\t\tWHO WE ARE      : " << enter << endl;
    cout << "\t\tADDRESS  : " << address << endl;
    cout << "\t\tEMAIL         : " << email << endl;
    cout << "\t\tPHONE NUMBER      : " << phonenumber << endl;
    fstream file;//create file
    file.open("company details.txt",ios::out);//this emplyees type somthing he can change company details and store it
    file << "\t\tWHO WE ARE      : " << enter << endl;
    file << "\t\tADDRESS  : " << address << endl;
    file << "\t\tEMAIL         : " << email << endl;
    file << "\t\tPHONE NUMBER      : " << phonenumber << endl;
    file.close();
    }
void view_company_details()//create function is used to view company details
{
    fstream file;//open file
    file.open("company details.txt",ios::in);// Open the file "company details.txt" in input mode
     // Check if the file was successfully opened
    if(file.is_open()){
        string line;
        // Read and display each line of the file
        while(getline(file,line)){
            cout<<line<<endl;
        }
        file.close();
    }
}
//input and checks if all characters in the string are digits
bool Number(string Number) {
  //iterates over each character in the input string
  for (char c : Number) {
    // checks if the current character is not a digit using the isdigit() function
    if (!isdigit(c)) {
        return false;
        }
    }
        return true;
}
//input and checks if not use @
bool Email( string Email) {
return Email.find('@') != string::npos; // Returns true if "@" is found in the email string
}
//This function allows the student registration
bool valid_name(string name) {
    //iterates over each character in the input string
    for (char c : name) {
        if (!isalpha(c) && !isspace(c)) { // check if name contains only letters and spaces
            return false;
        }
    }
    return true;
}
void stu_reg() {//create function is used to student registration details
    string fname,lname,email,mobile,nic,dof,gender,course,comment;
    char choice;
        cout<<"ENTER CORRECT DETAILS\n\n ";
    bool value=0;//check student registration
    bool valid=false;//check phone number 10 digits or 15 digits
    cin.ignore();// function is used to ignore or clear one or more characters from the input buffer
    do{
    cout<< "FIRST NAME : ";
    getline(cin,fname);
    // check user enter digit
    if (!valid_name(fname)) {
        cout << "INVALID NAME FORMAT\n";
        return; // exit function if name is invalid
    }
    fname = fname.substr(0,10);//line of code extracts the first 10 characters
    cout<< "LAST NAME  : ";
    getline(cin,lname);
    if (!valid_name(lname)) {
        cout << "INVALID NAME FORMAT\n";
        return; // exit function if name is invalid
    }
    lname = lname.substr(0,10);//line of code extracts the first 10 characters
    cout << "NIC NUM    : ";
    getline(cin,nic);
    nic = nic.substr(0,11);//line of code extracts the first 11 characters
    cout << "\nYOUR PHONE NUMBER HAS 10 DIGITS. ENTER 1:" << endl;
    cout << "\nYOUR PHONE NUMBER HAS 15 DIGITS. ENTER 2:" << endl;
        cin >> choice;
        cin.ignore();//any remaining newline characters or other unwanted characters in the buffer after reading input from
        if (choice == '1') {
            while (true) {
                cout << "MOBILE NUMBER (10 DIGITS): ";
                getline(cin, mobile);
                //check length in input number
                if (Number(mobile) && mobile.length() == 10) {
                    break;
                } else {
                    cout << "INVALID MOBILE NUMBER. PLEASE ENTER A 10-DIGIT NUMERIC MOBILE NUMBER\n";
                }
            }
        } else if (choice == '2') {
            while (true) {
                cout << "MOBILE NUMBER (15 DIGITS): ";
                getline(cin, mobile);
                //check length in input number
                if (Number(mobile) && mobile.length() == 15) {
                    break;
                } else {
                    cout << "INVALID MOBILE NUMBER. PLEASE ENTER A 15-DIGIT NUMERIC MOBILE NUMBER\n";
                }
            }
        } else {
            cout << "INVALID CHOICE. PLEASE ENTER EITHER (1 OR 2)\n";
        }
    }while (choice != '1' && choice != '2');//not use choice
    cout << "DATE OF BIRTH (DATE/MAONT/YEAR)   : ";
    getline(cin,dof);
    dof = dof.substr(0,8);
    cout << "GENDER : ";
    getline(cin,gender);
    gender = gender.substr(0,6);
    cout << "WRITE YOUR SELECT COURSES         : ";
    getline(cin,course);
    course = course.substr(0,20);
    while(true){
    cout << "ENTER YOUR EMAIL ADDRESS: ";
    getline(cin, email);
    if (Email(email)) {
        cout << "EMAIL ADDRESS IS VALID" << endl;
        break;

    } else {
        cout << "EMAIL ADDRESS IS INVALID. MAKE SURE TO INCLUDE THE '@' SYMBOL" << endl;
    }
    }
    while (true) {
        cout << "WEEK DAYS OR WEEKEND DAYS: ";
        getline(cin, comment);
        if (comment == "week days" || comment == "weekend days" || comment=="weekdays and weekend days") {
            break;
        } else {
            cout << "INVALID INPUT ! PLEASE ENTER EITHER: 'week days' or 'weekend days' or 'weekdays and weekend days' .\n";
        }
    }
    cout<<"NIC:"<<nic <<endl;
    cout <<"FIRST NAME:" <<fname<<endl;
    cout<<"LAST NAME:"<<lname <<endl;
    cout<<" EMAIL:"<<email<<endl;
    cout<< "GENDER:" <<gender<<endl;
    cout<< "DOF:" <<dof<<endl;
    cout<< "MOBILE:"<<mobile<<endl;
    cout<<"WEEK DAYS OR WEEKENAYS :"<<comment<<endl;
    cout<<"COURSES: "<<course<<endl;
    cout <<"---------------------------------------"<<"|\n";
    if(!fname.empty() && !lname.empty() && !nic.empty() && !email.empty() && !course.empty() && !comment.empty() && !mobile.empty()){
            value=1;// user type this option he can success registration and empty () function mean user first name not type this function not work
    }               //"&&" this work boolean logic and operater,its mean 0.1=0,1.1=1,0.0=0
    if(value==true){//if before condition is true
    cout <<    "REGISTRATION SUCCESSFUL\n";
    fstream myfile;//create file
    myfile.open("register student details.txt", ios::app);//This line of code opens a file named "register student details.txt" in append mode, which means that any new data that is written to the file will be added to the end of the existing data, rather than overwriting it.
    myfile<<"NIC:"<<nic <<endl;
    myfile<<"FIRST NAME:" <<fname<<endl;
    myfile<<"LAST NAME:"<<lname <<endl;
    myfile<<" EMAIL:"<<email<<endl;
    myfile<< "GENDER:" <<gender<<endl;
    myfile<< "DOF:" <<dof<<endl;
    myfile<< "MOBILE:"<<mobile<<endl;
    myfile<<"WEEK DAYS OR WEEKENAYS :"<<comment<<endl;
    myfile<<"COURSES: "<<course<<endl;
    myfile<<"---------------------------------------"<<"|\n";
    myfile.close();
    }
    else{
        cout<<"REGISTRATION UNSUCCESS";
    }
}
void forgot()//create function is used to employee forgot his password
{
        int option;
        system("cls");// Display menu options
        cout<<"\n\n\n\t\t\t1.WRITE YOUR USER NAME\n\n"<<endl;
        cout<<"\t\t\t2.EXIT"<<endl;
        cout<<"\t\t\t\nENTER YOUR CHOICE 1,2 :";
        while(!(cin >> option)) {//in this  fuction use user input invalid number return this massage
	                    cout << "YOUR NUMBER IS NOT VALID: ";
	                    cin.clear();
	                    cin.ignore();//cin.ignore() function is called to clear any extra characters that input buffer.
                        }
        switch(option)
        {
                case 1:
                {
                        int count=0;
                        string search_user,su1,sp1;
                        cout<<"\nENTER YOUR YOUSER NAME :";// Prompt for the user name to search
                        cin>>search_user;
                        ifstream file1("employee password.txt");
                        while(file1>>su1>>sp1)// Search for the user name in the file
                        {
                                if(su1==search_user)
                                {
                                        count=1;
                                         if(count==1)
                        {
                                cout<<"\nYOUR PASSWORD:\n"<<sp1;// If the user name is found, display the corresponding password
                                cin.get();
                                cin.get();
                                break;
                        }
                        }
                        else
                        {
                                cout<<"\nSORRY,PASSWORD NOT FOUND ! PRESS ENTER\n";// If the user name is not found, display a message
                                cin.get();
                                cin.get();
                                break;
                        }
                        }
                        break;
                }
                case 2: {
                  cout << "Exiting..." << std::endl;//displays the message "Exiting..." on the console, followed by a new line
                  break;
                }
        }
}
void show_stu_details(){//create function is used to view student details
    string line;
    fstream file;//create file
    file.open("register student details.txt",ios::in);//user can read detail in this function
    // Read and display each line of the file
    while(getline(file,line)){
        cout<<line<<"\n";
    }
    file.close();
}
void student_backup_details() {//in this function use student details backup
    string fname,lname,email,nic,mobile,dof,gender,course,comment;
    string stud_ID;
    char choice;
    bool value=1;//this use check some add another time student details
    cin.ignore();//This makes it easier to write input words with a space
    do{
    cin.ignore();
    cout<<"STUDENT ID   :";
    getline(cin,stud_ID);
    cout << "FIRST NAME : ";
    getline(cin,fname);
    cout << "LAST NAME  : ";
    getline(cin,lname);
    cout << "NIC NUM    : ";
    getline(cin,nic);
    cout << "MOBILE    : ";
    getline(cin,mobile);
    cout << "DATE of BIRTH    : ";
    getline(cin,dof);
    cout << "GENDER : ";
    getline(cin,gender);
    cout << "WRITE SELECT COURSES  : ";
    getline(cin,course);
    cout << "EMAIL ADDRESS : ";
    getline(cin,email);
    cout << "WEEK DAYS OR WEEKEND DAYS  : ";
    getline(cin,comment);
    cout <<"STUDENT ID" << "|\t" <<"FIRST NAME" <<"|\t"<<"LAST NAME"<<"|\t"<<"NIC"<< "|\t" <<" EMAIL"<<"|\t" << "GENDER" << "|\t" << "DOF" <<"|\t" << "MOBILE" <<"|\t" <<"WEEK DAYS OR WEEKEND DAYS "<<"|\t" <<"COURSES "<< "|\n";
    cout << stud_ID  << "|\t"  << fname      <<"|\t"<< lname     <<"|\t"<< nic << "|\t"  << email <<"|\t" <<  gender  << "|\t" << dof   <<"|\t" << mobile   <<"|\t" << comment                <<"|\t" << course   << "|\n";
    cout  <<"------------------------------------------------------------------------------------------------------------------------------------------"<<"|\n";
    cout <<    "REGISTRATION SUCCESSFUL\n\n";

    fstream myfile;//create file
    myfile.open("backup details.txt",ios::app);//This line of code opens a file named "register student details.txt" in append mode, which means that any new data that is written to the file will be added to the end of the existing data, rather thanoverwriting it.
    myfile <<"STUDENT ID" << "\t|" <<"FIRST NAME" <<"|\t"<<"LAST NAME"<<"|\t"<<"NIC"<< "|\t" <<" EMAIL"<<"|\t" << "GENDER" << "|\t" << "DOF" <<"|\t" << "MOBILE" <<"|\t" <<"WEEK DAYS OR WEEKEND DAYS "<<"|\t" <<"COURSES "<< "|\n";
    myfile << stud_ID  << "\t|"  << fname      <<"|\t"<< lname     <<"|\t"<< nic << "|\t"  << email <<"|\t" <<  gender  << "|\t" << dof   <<"|\t" << mobile   <<"|\t" << comment                <<"|\t" << course   << "|\n";
    myfile  <<"------------------------------------------------------------------------------------------------------------------------------------------"<<"|\n";
    myfile.close();
    cout << "DO YOU WANT TO ADD A NEW DETAILS ENTER (1):\n\n "<<endl;
    cout << "DO YOU WANT TO EXIT ENTER (2)        :\n\n "<<endl;
    cin >> choice;
    cin.ignore();
    } while (choice == '1' );
    cout << "DETAILS ADD" << endl;
    if(choice == '2'){
            system("cls");
            cout<<"EXIT.....";
    }
}
void back_up_file_open()//this use student backup data view
{
    string line;
    fstream file;//creat file
    file.open("backup details.txt",ios::in);//user can read this data
    // Read and display each line of the file
    while(getline(file,line)){
        cout<<line<<"\n";
    }
    file.close();
}
int main() {//this is main menu
    int option;//use this input option
    cout << "\n\n\t\t\t\t\t***WELCOME TO MASTER MIND INSTITUTE***\n";
    do {//do while loop use this To show users repeated data
        cout << "\n\t\t\t\t\t\t1. ABOUT INSTITUTE\n";
        cout << "\n\t\t\t\t\t\t2. OUR PROGRAMMES\n";
        cout << "\n\t\t\t\t\t\t3. STUDENT REGISTATION\n";
        cout << "\n\n\t\t\t\t\t\t4. FORGOT         \n";
        cout << "\n\t\t\t\t\t\t5. EMPLOYEE LOGIN\n";
        cout << "\n\t\t\t\t\t\t6. LOG OUT \n";
        cout << "\n\t\t\t\t\t<<<ENTER YOUR CHOICE (1,2,3,4,5,6):>>> ";
        while(!(cin >> option)) {//user input invalid character return this massage
	    cin.clear();//clear the error state flags cin input
	    cin.ignore();
	    cout << "YOUR NUMBER IS NOT VALID: ";
        }
switch (option) {//this switch option use call function
            case 1:
                system("cls");//this use before system close and enter call interface
                view_company_details();
                break;//condition break
            case 2:
                system("cls");  // Clear the console screen
                Viewing_course();
                break;
            case 3:
                system("cls");  // Clear the console screen
                stu_reg();//call student registration function
                break;
            case 4:
                system("cls");  // Clear the console screen
                forgot();//call forgot function
                break;
            case 5:
                if(option==5){
                system("cls");
                ofstream file1("employee password.txt",ios::app);//employee user name and password rewrite in this function
                file1 << "randunuk.com\n";
                file1 << "1234\n";
                file1 << "kaushalya\n";
                file1 << "5555";
                file1.close();

                string log_user_name, log_user_pass, x, y;
                bool log_in_success = false;//check employee login
                cout << "Enter username:";
                cin >> log_user_name;
                cout << "Enter password: ";
                cin >> log_user_pass;
                ifstream file2("employee password.txt");//include employee user name password
                while (getline(file2, x)) {//function takes two arguments: the input stream to read from, and a string variable to store the line that was read.
                    if (log_user_name == x) {//check condition
                        getline(file2, y);
                        if (log_user_pass == y) {
                            log_in_success = true;
                            break;
                        }
                    }
                }
                if (log_in_success) {
                    cout << "\nLogin successful.\n";
                    while (true) {//menu repeat this is employee menu
                        cout << "\n\t\t\t\t\t\t1. CHANGE COMPANY DETAILS:\n";
                        cout << "\n\t\t\t\t\t\t2. VIEW COMPANY DETAILS\n\n\n";
                        cout << "\n\t\t\t\t\t\t3.CHANGE  COURSE DETAILS\n";
                        cout << "\n\t\t\t\t\t\t4. VIEW  COURSE DETAILS\n";
                        cout << "\n\t\t\t\t\t\t5. VIEW STUDENT AND COURSSE DETAILS\n\n\n";
                        cout << "\n\t\t\t\t\t\t6. BACKUP STUDENT DETAILS\n";
                        cout << "\n\t\t\t\t\t\t7.VIEW BACKUP STUDENT DETAILS\n\n\n";
                        cout << "\n\t\t\t\t\t\t8. DELETE COURSES DETAILS\n";
                        cout << "\n\t\t\t\t\t\t9.RESTORE STUDENT REGISTRATION DETAILS\n\n\n";
                        cout << "\n\t\t\t\t\t\t10. EXIT\n\n\n";
                        cout << "\t\t\t\t\t\tENTER YOUR CHOICE (1,2,3,4,5,6,7,8,9,10)>>>>>>: ";
                        while(!(cin >> option)) {// user input invalid number return this massage
	                    cout << "YOUR NUMBER IS NOT VALID: ";
	                    cin.clear();
	                    cin.ignore();//clear any extra characters that input buffer.
                        }

                        switch (option) {//use call function
                            case 1:
                                system("cls");  // Clear the console screen
                                change_company_details();
                                break;
                            case 2:
                                system("cls");  // Clear the console screen
                                view_company_details();
                                break;
                            case 3:
                                system("cls");  // Clear the console screen
                                change_course_details();
                                break;
                            case 4:
                                system("cls");  // Clear the console screen
                                cout << "COURSE DETAILS\n";
                                Viewing_course();
                                break;
                            case 5:
                                system("cls");  // Clear the console screen
                                cout << "VIEWING STUDENT DETAILS:\n";
                                show_stu_details();
                                break;
                            case 6:
                                cout << "ENTER STUDENT DETAILS:\n";
                                student_backup_details();
                                 system("cls");
                                break;
                            case 7:
                                system("cls");  // Clear the console screen
                                cout<<"STUDENT BACKUP DETAILS\n";
                                 back_up_file_open();
                                break;
                            case 8:
                                system("cls");  // Clear the console screen
                                delete_course_details();
                                break;
                            case 9:
                                system("cls");  // Clear the console screen
                                delete_student_details();
                                break;
                            case 10:
                                system("cls");  // Clear the console screen
                                cout << "\nEXITING.\n";//exit function
                                break;
                            default:
                                system("cls");  // Clear the console screen
                                cout << "YOUR NUMBER IS NOT VALID.\n";
                        }

                            if (option == 10) {//this condition use check this 16 condition
                                break;
                            }
                        }
                    } else {
                        cout << "\nINVALID YOUSER NAME OR PASSWORD.\n";//employee password in not match display this massage
                    }
                    }
                break;

                default :// This code is executed when none of the preceding case labels match the value of 'option'
                    system("cls");  // Clear the console screen
                    cout<<"YOUR NUMBER IS NOT VALID";




}



        }while (option != 6);//repeatedly execute a block of code until a certain condition is met
        system("cls");
           cout << "\nYOU ARE SUCCESSFULY LOGOUT.\n";
        return 0;//Use this to exit this function
    }

