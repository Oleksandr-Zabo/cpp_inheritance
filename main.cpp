#include <iostream>
using namespace std;


//for visa data
struct Data {
private:
	int day;
	int month;
	int year;
public:
	Data() {
		day = 0;
		month = 0;
		year = 0;
	}
	Data(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	void print_data() const {
		cout << day << "." << month << "." << year << endl;
	}
};

//for ForeignPassport
struct Visa {
private:
	string country;
	int year;
	long long num_visa;
	Data* data;
public:
	Visa() {
		string country = "no country";
		int year = 0;
		long long num_visa = 0;
		Data* data = nullptr;
	}
	Visa(string country, int year, long long num_visa, Data data) {
		this->country = country;
		this->year = year;
		this->num_visa = num_visa;
		this->data = new Data{ data };

	}

	void print_visa() const {
		cout << "Country: " << country << endl;
		cout << "Number of years of validity: " << year << endl;
		cout << "Number(id) of visa: " << num_visa << endl;
		cout << "Data of created visa: ";
		data->print_data();
		cout << endl;

	}
};

class Passport
{
protected:
	string _name;
	string _surname;
	string _patronymic;
	int* _age;
	long long* id;
public:
	Passport() {
		_name = "No name";
		_surname = "No surname";
		_patronymic = "No patronymic";
		_age = new int(0);
		id = new long long(0);
		cout << "Passport created" << endl;
	}
	Passport(string name, string surname, string patronymic, int age, long long id) {
		_name = name;
		_surname = surname;
		_patronymic = patronymic;
		_age = new int(age);
		this->id = new long long(id);
		cout << "Passport created with param" << endl;
	}
	Passport(string name, string surname, string patronymic, int* age, long long* id): Passport(name, surname, patronymic, *age, *id){
	}

	virtual void about() const {
		cout << "Name: " << _name << endl;
		cout << "Surname: " << _surname << endl;
		cout << "Patronymic: " << _patronymic << endl;
		cout << "Age: " << *_age << endl;
		cout << "ID: " << *id << endl;
	}

	virtual ~Passport() {
		delete _age;
		delete id;
		cout << "Passport deleted" << endl;
	}

};




class ForeignPassport: public Passport
{
protected:
	long long* _num_passport;
	Visa* _visas;
	int* _num_visas;
public:
	ForeignPassport() : Passport() {
		_num_passport = nullptr;
		_visas = nullptr;
		_num_visas = nullptr;
	}
	ForeignPassport(string name, string surname, string patronymic, int age, long long id, long long num_passport, Visa* visas, int num_visas) : Passport(name, surname, patronymic, age, id) {
		_num_passport = new long long{ num_passport };
		_visas = new Visa;
		_visas = visas;
		_num_visas = new int{ num_visas };
	}

	void about() const override {
		Passport::about();
		cout << "Number of passport: " << *_num_passport << endl;
		for (size_t i = 0; i < (*_num_visas); i++)
		{
			cout << "Visa #" << i + 1 << endl;
			_visas[i].print_visa();
		}
	}

	~ForeignPassport() {
		delete _num_passport;
		delete[] _visas;
		delete _num_visas;
		cout << "Foreign Passport destroyed" << endl;
	}
};

void print(Passport* passport) {
	passport->about();
}

int main() {
    Passport *passport1 = new Passport("John", "Doe", "Smith", 30, 123456789);
    passport1->about();

    Visa visa1("Uganda", 2023, 1234543, Data(1, 12, 2025));
    Visa visa2("USA", 2022, 654321, Data(10, 6, 2026));
    Visa* visas = new Visa[2]{ visa1, visa2 };

    ForeignPassport* foreignPassport1 = new ForeignPassport("Jane", "Doe", "Smith", 25, 987654321, 9876543210, visas, 2);
    foreignPassport1->about();

    delete passport1;
    delete foreignPassport1;
    

    return 0;
}