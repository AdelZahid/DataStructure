#include<bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int roll;
    vector<pair<string, int>> course;

    Student(string name, int roll, vector<pair<string,int>> &course)
    {
        this->name = name;
        this->roll = roll;
        this->course = course;
    }
} typedef Stu;

void printInfo(const Stu& s)
{
    cout << "Name: " << s.name << endl;
    cout << "Roll: " << s.roll << endl;
    cout << "Courses: " << endl;
    for(auto &i : s.course)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << "-------------------------" << endl;
}

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    vector<Stu> students;
    for (int i = 0; i < n; i++)
    {
        string name;
        int roll;
        vector<pair<string, int>> course;
        cout << "Enter the name of the student " << i + 1 << " : ";
        cin >> name;
        cout << "Enter the roll number of the student " << i + 1 << " : ";
        cin >> roll;
        cout << "Enter the courses of the student (3 subjects) " << i + 1 << " : " << endl;
        for (int j = 0; j < 3; j++)
        {
            string courseName;
            int courseId;
            cout << "Enter course name and id: ";
            cin >> courseName >> courseId;
            course.push_back({courseName, courseId});
        }
        Stu s(name, roll, course);
        students.push_back(s);
        cout << "-------------------------" << endl;
    }

    bool exit = false;
    do
    {
        cout << "Enter the choice: " << endl;
        cout << "1. Create a new course for a particular student" << endl;
        cout << "2. Find the student by his roll and print his information" << endl;
        cout << "3. Enter the information of new students" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int roll;
            cout << "Enter the roll of the student: " << endl;
            cin >> roll;
            bool found = false;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].roll == roll)
                {
                    int m;
                    cout << "Enter the number of courses to add: " << endl;
                    cin >> m;
                    for (int j = 0; j < m; j++)
                    {
                        string courseName;
                        int courseId;
                        cout << "Enter course name and id: ";
                        cin >> courseName >> courseId;
                        students[i].course.push_back({courseName, courseId});
                    }
                    found = true;
                    printInfo(students[i]);
                    break;
                }
            }
            if (!found)
            {
                cout << "There is no student with that roll number." << endl;
            }
        }
        break;

        case 2:
        {
            int roll;
            cout << "Enter the roll number of the student: ";
            cin >> roll;
            bool found = false;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].roll == roll)
                {
                    printInfo(students[i]);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Student with roll number " << roll << " not found." << endl;
            }
        }
        break;

        case 3:
        {
            int newStudents;
            cout << "Enter the number of new students: ";
            cin >> newStudents;
            for (int i = 0; i < newStudents; i++)
            {
                string name;
                int roll;
                vector<pair<string, int>> course;
                cout << "Enter the name of the student " << i + 1 << " : ";
                cin >> name;
                cout << "Enter the roll number of the student " << i + 1 << " : ";
                cin >> roll;
                cout << "Enter the courses of the student (3 subjects) " << i + 1 << " : " << endl;
                for (int j = 0; j < 3; j++)
                {
                    string courseName;
                    int courseId;
                    cout << "Enter course name and id: ";
                    cin >> courseName >> courseId;
                    course.push_back({courseName, courseId});
                }
                Stu s(name, roll, course);
                students.push_back(s);
                cout << "-------------------------" << endl;
            }
            cout << "The information of new students are: " << endl;
            for (int i = 0; i < students.size(); i++)
            {
                printInfo(students[i]);
            }
        }
        break;

        case 4:
            exit = true;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (!exit);

    return 0;
}