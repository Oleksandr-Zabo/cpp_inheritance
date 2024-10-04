#include <iostream>
using namespace std;

enum Project_Consts {
	num_legs_mammal=4,
	num_legs_bird = 2,
};

enum TypeAnimal {
	DOG,
	CAT,
	PARROT,
	Unknown
};



class Pet {
protected:
	string _name;
	int _num_legs;
	TypeAnimal _type;
	bool _is_fly;
	int _speed;

public:
	Pet() {
		_name = "No name";
		_num_legs = 0;
		_type = TypeAnimal::Unknown;
		_is_fly = false;
		_speed = 0;
		cout << "Pet created" << endl;
	}
	Pet(string name, int num_legs, TypeAnimal type, bool is_fly, int speed) : Pet() {
		_name = name;
		if (num_legs >= 0)
		{
			_num_legs = num_legs;
		}
		_type = type;
		_is_fly = is_fly;
		_speed = speed;
		cout << "Pet with param" << endl;
	}

	virtual void about() {
		cout << "Pet about: " << endl;
		cout << "Name: " << _name << endl;
		cout << "Number of legs: " << _num_legs << endl;
		cout << "Is fly: ";
		if (_is_fly)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		cout << "Speed: " << _speed << endl;
		cout << "Type : ";
		switch (_type)
		{
		case DOG: {
			cout << "Dog";
		}break;

		case CAT: {
			cout << "Cat";
		}break;

		case PARROT: {
			cout << "Parrot";

		}break;

		case Unknown:
		{
			cout << "Unknown";
		}break;

		default: {
			cout << "Unknown";
		}break;

		}
		cout << endl;
	}
};

class Dog : public Pet
{
public:
	Dog() :Pet() {
		_type = TypeAnimal::DOG;
		_num_legs = Project_Consts::num_legs_mammal;
		_is_fly = false;
		_speed = 20;
	}
	Dog(string name, int speed) : Pet(name, Project_Consts::num_legs_mammal, TypeAnimal::DOG, false, speed) {
	}

	void about() override {
		cout << "Dog about: " << endl;
		cout << "Name: " << _name << endl;
		cout << "Is fly: " << "No" << endl;
		cout << "Speed: " << _speed << endl;
		cout << "Type : Dog" << endl;
		cout << endl;
	}

};

class Cat : public Pet
{
public:
	Cat() :Pet() {
		_type = TypeAnimal::CAT;
		_num_legs = Project_Consts::num_legs_mammal;
		_is_fly = false;
		_speed = 15;
	}
	Cat(string name, int speed) : Pet(name, Project_Consts::num_legs_mammal, TypeAnimal::CAT, false, speed) {
	}

	void about() override {
		cout << "Cat about: " << endl;
		cout << "Name: " << _name << endl;
		cout << "Is fly: " << "No" << endl;
		cout << "Speed: " << _speed << endl;
		cout << "Type : Cat" << endl;
		cout << endl;
	}
};

class Parrot : public Pet
{
public:
	Parrot() :Pet() {
		_type = TypeAnimal::PARROT;
		_num_legs = Project_Consts::num_legs_bird;
		_is_fly = true;
		_speed = 30;
	}
	Parrot(string name, int speed) : Pet(name, Project_Consts::num_legs_bird, TypeAnimal::PARROT, true, speed) {
	}

	void about() override {
		cout << "Parrot about: " << endl;
		cout << "Name: " << _name << endl;
		cout << "Is fly: " << "Yes" << endl;
		cout << "Speed: " << _speed << endl;
		cout << "Type : Parrot" << endl;
		cout << endl;
	}

};

int main() {
	Pet* dog = new Dog("Bob", 20);
	Pet* cat = new Cat("Tom", 15);
	Pet* parrot = new Parrot("Kesha", 30);
	
	dog->about();
	cat->about();
	parrot->about();

	delete dog;
	delete cat;
	delete parrot;
	
	return 0;
}