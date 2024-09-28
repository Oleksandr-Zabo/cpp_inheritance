#include <iostream>
using namespace std;

enum Project_Consts {
	the_last_year = 5
};

class Student 
{
protected:
	string _name;
	string _surname;
	int* _age;
	string _group;
	int* year_of_study;
public:
	Student() {
		_name = "no name";
		_surname = "no surname";
		_age = nullptr;
		_group = "no group";
		year_of_study = nullptr;
		cout << "Student created" << endl;
	}
	Student(string name, string surname, int age, string group, int year) {
		_name = name;
		_surname = surname;
		_age = new int{ age };
		_group = group;
		year_of_study = new int{ year };
		cout << "Student with param" << endl;
	}
	Student(string name, string surname, int* age, string group, int* year): Student(name, surname, *age, group, *year) {
	}

	Student(const Student& other) {
		_name = other._name;
		_surname = other._surname;
		_age = new int{ *other._age };
		_group = other._group;
		year_of_study = new int{ *other.year_of_study };
		cout << "Student copied" << endl;
	}

	virtual ~Student() {
		delete _age;
		delete year_of_study;
		cout << "Student deleted" << endl;
	}

	virtual void about() {
		cout << "Name: " << _name << endl;
		cout << "Surname: " << _surname << endl;
		cout << "Age: " << *_age << endl;
		cout << "Group: " << _group << endl;
		cout << "Year of study: " << *year_of_study << endl;
	}
};

class Aspirant : public Student
{
protected:
	string _topic;

public:
	Aspirant() : Student() {
		_topic = "no topic";
		year_of_study = new int{ Project_Consts::the_last_year };
		cout << "Aspirant created" << endl;
	}

	Aspirant(string name, string surname, int age, string group, string topic) : Student(name, surname, age, group, Project_Consts::the_last_year) {
		_topic = topic;
		cout << "Aspirant with param" << endl;
	}

	void about() override {
		cout << "Name: " << _name << endl;
		cout << "Surname: " << _surname << endl;
		cout << "Age: " << *_age << endl;
		cout << "Group: " << _group << endl;
		cout << "Topic: " << _topic << endl;
	}

	~Aspirant() {
		cout << "Aspirant deleted" << endl;
	}
};

void print(Student* student) {
	student->about();
}

int main() {

	Student* student = new Student("Ivan", "Ivanov", 20, "K-28", 2);

	print(student);

	Student* aspirant = new Aspirant("Petr", "Petrov", 25, "K-29", "Math");

	print(aspirant);

	delete student;
	delete aspirant;
	
	return 0;
}