#include <iostream>
using namespace std;

enum Project_Consts {
	num_of_all_pasangers = 5,
	weight_of_load = 500,
	Car_wheels = 4,
	Bike_wheels = 2,
	Cart_wheels = 4,
	Car_passengers = 4,
	Bike_passengers = 1,
	Cart_passengers = 5
};

enum TypeVehicle {
	CAR,
	BIKE,
	CART,
	Unknown
};



class Vehicle {
protected:
	string _name;
	int _num_of_wheels, _max_weight, _max_passengers;
	double _standart_time, _price;

	TypeVehicle _type;

public:
	Vehicle() {
		_name = "No name";
		_num_of_wheels = 0; 
		_max_weight = 0;
		_max_passengers = 0;
		_standart_time = 0;
		_price = 0;
		_type = TypeVehicle::Unknown;
		cout << "Vehicle created" << endl;
	}
	Vehicle(string name, int num_of_wheels, int max_weight, int max_passsenger, double standart_time, double price, TypeVehicle type): Vehicle() {
		_name = name;
		if (num_of_wheels >= 0)
		{
			_num_of_wheels = num_of_wheels;
		}
		
		if (max_weight >= 0)
		{
			_max_weight = max_weight;
		}
		
		if (max_passsenger >= 0)
		{
			_max_passengers = max_passsenger;
		}
		
		if (standart_time > 0)
		{
			_standart_time = standart_time;
		}
		
		if (price > 0) {
			_price = price;
		}
		_type = type;
		cout << "Vehicle with param" << endl;
	}

	virtual void about() {
		cout << "Vehicle about: " << endl;
		cout << "Name: " << _name << endl;
		cout << "Number of wheels: " << _num_of_wheels << endl;
		cout << "Max weight: " << _max_weight << endl;
		cout << "Max passengers: " << _max_passengers << endl;
		cout << "Standart time of one delivery: " << _standart_time << endl;
		cout << "Price: " << _name << endl;
		cout << "Type : ";
		switch (_type)
		{
		case CAR: {
			cout << "Car";
		}break;

		case BIKE: {
			cout << "Bike";
		}break;

		case CART:{
			cout << "Cart";
			
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

	void get_total_time_price(int passengers, int weight_load) {
		int total_time = 0;
		int total_price = 0;
		int delivered_passengers = 0;
		int delivered_loads = 0;
		if (delivered_passengers < passengers && delivered_loads < weight_load) //the first deliver(to one way)
		{
			total_time += _standart_time;
			total_price += _price;
			delivered_passengers += _max_passengers;
			delivered_loads += _max_weight;
		}

		while (delivered_passengers < passengers && delivered_loads < weight_load)//others delivers (include comeback and deliver)
		{
			total_time += 2 * _standart_time;
			total_price += 2 * _price;
			delivered_passengers += _max_passengers;
			delivered_loads += _max_weight;
		}

		cout << "Need time: " << total_time << endl;
		cout << "Total price: " << total_price << endl;
	}
};

class Car: public Vehicle
{
public:
	Car():Vehicle() {
		_type = TypeVehicle::CAR;
		_num_of_wheels = Project_Consts::Car_wheels;
	}
	Car(string name, int max_weight, double standart_time, double price): Vehicle(name, Project_Consts::Car_wheels, max_weight, Project_Consts::Car_passengers, standart_time, price, TypeVehicle::CAR) {
	}

	void about() override {
		cout << "Car about: " << endl;
		cout << "Name: " << _name << endl;
		cout << "Max weight: " << _max_weight << endl;
		cout << "Standart time of one delivery: " << _standart_time << endl;
		cout << "Price: " << _name << endl;
		cout << "Type : Car (4 passengers)" << endl;
	}

};


class Bike: public Vehicle
{
public:
	Bike():Vehicle() {
		_type = TypeVehicle::BIKE;
		_num_of_wheels = Project_Consts::Bike_wheels;
	}
	Bike(string name, int max_weight, double standart_time, double price): Vehicle(name, Project_Consts::Bike_wheels, max_weight, Project_Consts::Bike_passengers, standart_time, price, TypeVehicle::BIKE) {
	}

	void about() override {
		cout << "Bike about: " << endl;
		cout << "Name: " << _name << endl;
		cout << "Max weight: " << _max_weight << endl;
		cout << "Standart time of one delivery: " << _standart_time << endl;
		cout << "Price: " << _name << endl;
		cout << "Type : Bike (1 passenger)" << endl;
	}
};

class Cart : public Vehicle
{
public:
	Cart() :Vehicle() {
		_type = TypeVehicle::CART;
		_num_of_wheels = Project_Consts::Cart_wheels;
	}
	Cart(string name, int max_weight, double standart_time, double price) : Vehicle(name, Project_Consts::Cart_wheels, max_weight, Project_Consts::Cart_passengers, standart_time, price, TypeVehicle::CART) {
	}

	void about() override {
		cout << "Cart about: " << endl;
		cout << "Name: " << _name << endl;
		cout << "Max weight: " << _max_weight << endl;
		cout << "Standart time of one delivery: " << _standart_time << endl;
		cout << "Price: " << _name << endl;
		cout << "Type : Cart (5 passenger)" << endl;
	}
};

void print(Vehicle* v) {
	v->about();
}

void price_time(Vehicle* v, int passengers, int weight) {
	v->get_total_time_price(passengers, weight);
}

int main() {
	Vehicle* car = new Car("BMW", 200, 10, 20);

	Vehicle* bike = new Bike("BMX", 200, 50, 10);

	Vehicle* cart = new Cart("Cart", 600, 100, 5);

	print(car);
	print(bike);
	print(cart);

	cout << "Price-time for car: " << endl;
	price_time(car, Project_Consts::num_of_all_pasangers, Project_Consts::weight_of_load);

	cout << "Price-time for bike: " << endl;
	price_time(bike, Project_Consts::num_of_all_pasangers, Project_Consts::weight_of_load);

	cout << "Price-time for cart: " << endl;
	price_time(cart, Project_Consts::num_of_all_pasangers, Project_Consts::weight_of_load);

	delete car;
	delete bike;
	delete cart;

	return 0;
}