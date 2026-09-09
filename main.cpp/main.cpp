#include <iostream>

using namespace std;
class student{
    string name;
     int age;
     float grade;
 public:
     student(){
     name="";
     age=0;
     grade=0;

     }
    student(string n , int a , float g){
    name=n;
   setAge(a);
    setGrade(g);

    }
    void setGrade(float g){
    if(g>=0&&g<=100){
        grade=g;
    }
    else{
        cout<<"invalid grade!"<<endl;
    }
    }

    string getname(){
    return name;
    }
    void setAge(int a){
        if(a>0){
            age=a;
        }
        else{
            cout<<"invalid age"<<endl;
        }
    }
char getGradeLetter(){
    if (grade>=90)
        return 'A';
        else if(grade>=80)
        return 'B';
        else if (grade>=70)
        return 'C';
        else if(grade>=60)
        return 'D';
        else
        return 'F';
    }
void printInfo(){
cout<< "Name" << name<<endl;
cout<< "Age" << age<<endl;
cout<< "Grade"<< grade<<endl;

}

};

int main()
{
    student students[10];
    int studentCount=0;
    int choice;
    do
    {
    cout << "===== Student Management System =====" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Show Students" << endl;
    cout << "3. Exit" << endl;
    cout << "4. Search Student" << endl;
    cout<<"5. Delet Student"<<endl;
       cout << "Enter choice: ";
cin >> choice;
    if (choice == 1)
    {
    if(studentCount<10){
    string name;
     int age;
    float grade;
     cin.ignore();
cout<<"Enter name"<<endl;
    getline(cin , name);
    do{
    cout<<"Enter age"<<endl;
        cin>>age;
        if(age<=0){
            cout<<"invalid age! Enter positive number"<<endl;
        }
    }
    while(age<=0);
    do{
    cout<<"Enter grade"<<endl;
     cin>>grade;
     if (grade<0 || grade>100){
        cout<<"invalid grade , Enter value from 0 to 100"<<endl;
     }
    }
    while(grade<0||grade>100);
    students[studentCount]=student(name , age ,grade);
        studentCount++;
        cout<<"Student added successfully"<<endl;
           }
           else {
             cout << "Maximum number of students reached." << endl;
           }
        }
else if (choice == 2)
    {
     for (int i = 0; i < studentCount; i++)
    {
  cout << "Student " << i + 1 << endl;
students[i].printInfo();
 cout << "Letter Grade: "<< students[i].getGradeLetter()<< endl;
       cout << "----------------" << endl;
            }
        }

else if (choice == 3)
        {
        cout << "Goodbye!" << endl;
        }


else if (choice == 4)
{
    string target;
    bool found = false;

    cin.ignore();

    cout << "Enter student name: ";
    getline(cin, target);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].getname() == target)
        {
cout << "Student found!" << endl;
students[i].printInfo();
cout << "Letter Grade: " << students[i].getGradeLetter()<<endl;
    found = true;
    break;
        }
    }
if (!found)
    {
    cout << "Student not found!" << endl;
    }

}

else if(choice==5){
    string target;
    bool found=false;
    cin.ignore();
    cout<<"Enter student name to delet"<<endl;
    getline(cin , target);
    for(int i =0 ; i<studentCount;i++){
        if(students[i].getname()==target){
            for(int j =i ;j<studentCount-1;j++){
                students[j]=students[j+1];
            }
            studentCount--;
            found=true;
            cout<<"student deleted successfully"<<endl;
            break;
        }
    }
    if(!found){
        cout<<"student not found"<<endl;
    }
    else {
        cout<<"invalid choice!Please choose from 1 to 5"<<endl;
    }
}
    }

    while (choice != 3);

    return 0;
}

