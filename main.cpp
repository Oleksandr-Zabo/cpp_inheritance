#include <iostream>
#include <ostream>
#include <bitset>//to convert binary to int

using namespace std;

class my_string
{
protected:
	char* buf = nullptr;
	unsigned int size = 0;

public:

	//constructors
	my_string() 
	{
		buf = nullptr;
		size = 0;
	}

	my_string(const char* const buffer)
	{
		size = strlen(buffer);
		buf = new char[size + 1]; // + 1 for \0
		strncpy_s(buf, size + 1, buffer, size); // copy 
	}

	my_string(const my_string& obj)
	{
		size = obj.size;
		buf = new char[size + 1]; // + 1 for \0
		strncpy_s(buf, size + 1, obj.buf, size); // copy 
	}

	//methods
	void cleanup()
	{
		if (buf != nullptr)
		{
			delete[] buf;
		}
		size = 0;
	}

	my_string& operator=(const my_string& obj) // copy assignment
	{
		cleanup(); // cleanup any existing data

		// Copy data from the newly assigned my_string object
		size = obj.size;
		buf = new char[size + 1]; // + 1 for \0
		strncpy_s(buf, size + 1, obj.buf, size); // copy 
		return *this;
	}

	my_string(my_string&& obj) // move constructor
	{
		cleanup(); // cleanup any existing data

		// Copy data from the incoming object
		size = obj.size;

		// Transfer ownership of underlying char buffer from incoming object to this object
		buf = obj.buf;
		obj.buf = nullptr;
	}

	my_string& operator=(my_string&& obj) // move assignment
	{
		cleanup(); // cleanup any existing data

		// Copy data from the incoming object
		size = obj.size;

		// Transfer ownership of underlying char buffer from incoming object to this object
		buf = obj.buf;
		obj.buf = nullptr;

		return *this;
	}

	my_string operator+(const my_string& obj) // concatenation
	{
		my_string s; // create a new string named 's'
		s.size = this->size + obj.size;
		s.buf = new char[s.size + 1]; // allocate memory to keep the concatenated string
		strncpy_s(s.buf, this->size + 1, this->buf, this->size); // copy the 1st string
		strncpy_s(s.buf + this->size, obj.size + 1, obj.buf, obj.size);

		return s;
	}

	my_string& operator+=(const my_string& obj) // concatenation
	{
		size += obj.size;
		char* temp = new char[size + 1]; // allocate memory to keep the concatenated string
		strncpy_s(temp, size + 1, buf, size - obj.size); // copy the 1st string
		strncpy_s(temp + size - obj.size, obj.size + 1, obj.buf, obj.size);
		delete[] buf;
		buf = temp;
		return *this;
	}

	bool operator==(const my_string& obj) // comparison
	{
		if (size != obj.size)
		{
			return false;
		}
		return strcmp(buf, obj.buf) == 0;
	}

	bool operator!=(const my_string& obj) // comparison
	{
		if (size != obj.size)
		{
			return true;
		}
		return strcmp(buf, obj.buf) == 1;
	}

	unsigned int length()
	{
		return size;
	}

	const char* c_str() const
	{
		return buf;
	}

	// destructor
	~my_string() 
	{
		cleanup();
	}

};

class Binary_string : public my_string
{
public:

    // Check if the string is binary
    bool check_is_binary(const char* const buffer) {
        for (unsigned int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] != '0' && buffer[i] != '1')
            {
                return false;
            }
        }

        return true;
    }

    //constructors
    Binary_string() :my_string() {
    }

    Binary_string(const char* const buffer) : my_string(buffer)
    {
        // Check if the string is binary
        if (!check_is_binary(buffer)) {
            cout << "Invalid binary string";
            size = 0;
            buf = nullptr; // Set buf to nullptr to indicate an empty string
        }
    }

    // copy constructor
    Binary_string(const Binary_string& obj) : my_string(obj)
    {
    }

    // destructor
    ~Binary_string()
    {
    }

    Binary_string operator+(const Binary_string& obj) // concatenation
    {
        Binary_string s; // create a new string named 's'
        s.size = this->size + obj.size;
        s.buf = new char[s.size + 1]; // allocate memory to keep the concatenated string
        strncpy_s(s.buf, this->size + 1, this->buf, this->size); // copy the 1st string
        strncpy_s(s.buf + this->size, obj.size + 1, obj.buf, obj.size);

        return s;
    }

    Binary_string& operator=(const Binary_string& obj)
    {
        if (this != &obj) // check for self-assignment
        {
            // Cleanup any existing data
            cleanup();

            // Check if the string is binary
            if (!check_is_binary(obj.buf))
            {
                cout << "Invalid binary string";
                size = 0;
                buf = nullptr; // Set buf to nullptr to indicate an empty string
            }
            else
            {
                // Copy data from the newly assigned Binary_string object
                size = obj.size;
                buf = new char[size + 1]; // + 1 for \0
                strncpy_s(buf, size + 1, obj.buf, size); // copy 
            }
        }
        return *this;
    }

    Binary_string& operator+=(const Binary_string& obj) // concatenation add Checking for correct input
    {
        // Check if the string is binary
        if (!check_is_binary(obj.buf))
        {
            cout << "Invalid binary string";
            return *this;
        }

        size += obj.size;
        char* temp = new char[size + 1]; // allocate memory to keep the concatenated string
        strncpy_s(temp, size + 1, buf, size - obj.size); // copy the 1st string
        strncpy_s(temp + size - obj.size, obj.size + 1, obj.buf, obj.size);
        delete[] buf;
        buf = temp;
        return *this;
    }

    bool operator==(const Binary_string& obj) // comparison
    {
        if (size != obj.size)
        {
            return false;
        }
        return strcmp(buf, obj.buf) == 0;
    }

    bool operator!=(const Binary_string& obj) // comparison
    {
        if (size != obj.size)
        {
            return true;
        }
        return strcmp(buf, obj.buf) != 0;
    }

	void negate() {
		if (size == 0) return;
		for (int i = 0; i < size; ++i) {
			buf[i] = (buf[i] == '0') ? '1' : '0';
		}
		// add 1 to itarate num
		for (int i = size - 1; i >= 0; --i) {
			if (buf[i] == '0') {
				buf[i] = '1';
				break;
			}
			else {
				buf[i] = '0';
			}
		}
	}
};


ostream& operator<<(ostream& cout, const my_string& obj)
{
	cout << obj.c_str();
	return cout;
}

int main()
{
	my_string a("FirstName");
	my_string b("LastName");
	my_string c = a + b;
	cout << c << endl;

	my_string d("MiddleName");
	c += d;

	cout << c << endl;

	cout << "Length of c: " << c.length() << endl;

	my_string e = c;
	cout << e << endl;
	cout << "e == c: " << (e == c) << endl;

	my_string f("FirstNameLast");
	cout << "f != c: " << (f != c) << endl;

	Binary_string binary1("101010");
	Binary_string binary2("110011");
	cout << "binary1binary1 == binary1: " << (binary1 == binary1) << endl;
	cout << "binary1binary1 != binary2: " << (binary1 != binary2) << endl;

	Binary_string binary3 = binary1 + binary2;
	cout << binary3 << endl;

	Binary_string binary4("111100");
	binary4 += binary3;
	cout << binary4 << endl;

	unsigned long decimal = bitset<32>(binary4.c_str()).to_ulong();//convert binary to int
	cout << "decimal = " << decimal << endl;

	binary4.negate();
	cout << binary4 << endl;


	decimal = bitset<32>(binary4.c_str()).to_ulong();
	cout << "decimal = " << decimal << endl;

	system("pause");
	return 0;
}