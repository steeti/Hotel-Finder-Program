#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

// class Hotel that includes hotelname, cityname, stars, price, countryname, address;
class Hotel
{
private:
	string hotelname, cityname, stars, price, countryname, address;
public:
	Hotel() {}
	Hotel(string hotelname, string cityname, string stars, string price, string countryname, string address)
	{
		this -> hotelname=hotelname;
		this -> cityname=cityname;
		this -> stars=stars;
		this -> price=price;
		this -> countryname=countryname;
		this -> address=address;
	}
	string getcityname()
		{
			return this->cityname;
		}
	string gethotelname()
		{
			return this->hotelname;
		}
	string gethotelcityname()
	{
		return this->hotelname + ',' +this->cityname;
	}
	// display method for class hotel
	void display()
	{
		cout<<this->hotelname<<","<<this->cityname<<","<<this->stars<<","<<this->price<<","<<this->countryname<<","<<this->address<<endl;
	}
	// display 2 method for class hotel used i dump
	string display2()
	{
		return this->hotelname + ',' +this->cityname + ',' +this->stars + ',' + this->price+ ',' +this->countryname+ ',' +this->address;
	}
	
};
class HashNode
{
	private:
		string key;
		Hotel value;
	public:
		HashNode(string key, Hotel value)
		{
			this->key = key;
			this->value = value;

		}
		string getKey()
		{
			return this->key;
		}
		void setValue(Hotel value)
		{
			this->value = value;
		}
		Hotel getValue()
		{
			return this->value;
		}

};

class HashMap
{
	private:
		list<HashNode> *buckets;		// Array of Pointers to Hash Nodes
		vector<string> keysvector;
		int size;					    //Current Size of HashMap
		int capacity;				    // Total Capacity of HashMap
	public:
		HashMap(int capacity);
		long hashCode(const string key);
		void insert(const string key, Hotel value);
		void insert1(const string key, Hotel value);
		void remove(const string key);
		void remove1(const string key);
		void search(const string key);
		void allincity(const string key);
		void dump(const string key);
		int getSize();
		~HashMap();

};
bool isPrime(long);// function to check if prime
int countcomma(string , char ); // function to count comma
#endif