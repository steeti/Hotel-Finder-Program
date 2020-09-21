//Saad Teeti
//sht318
#include "header.h"
#include "myfunctions.h"


using namespace std;
//seperate chaining hashmap
HashMap::HashMap(int capacity)
{
	buckets = new list<HashNode>[capacity];
	this->capacity = capacity;
	this->size = 0;
}

// creating hashcode
long HashMap::hashCode(const string key)
{

	//unsigned so we won't get out of the range and we add scci code of each letter times i power 10
	unsigned long sum=0;
	for(int i=0; i<key.length(); i++)
		sum += (long)(key[i]*pow(i,10)) % this->capacity; 		
		sum %= this->capacity;
	return sum;
}
//================================================
// this insert method is used for hashtable with key of hotel name and city name
void HashMap::insert(const string key, Hotel value)
{
	int index = hashCode(key)%this->capacity; 
	
	
	//range loop that goes through the buckets indexes
	for(auto it:buckets[index])
		//if the key already exist then we cout error
		if(it.getKey()==key)				
		{
			cout<<"Key already exist:  "<<key<<endl;				
			return;
		}

	buckets[index].push_back(HashNode(key, value));	//add the new element in the bucket if it doesn't existt
	this->size++;								
	//cout<<"testttt"<<endl;
}
// this insert method is used for hashtable with key of city name
void HashMap::insert1(const string key, Hotel value)
{
	int index = hashCode(key)%this->capacity; 
	
	//range loop that goes through the buckets indexes
	for(auto it:buckets[index])
		//if value is already present in the hash table and here the key is the hotelname
		if(it.getValue().gethotelname()==value.gethotelname())				
		{
			
			return;
		}

	buckets[index].push_back(HashNode(key, value));	//add the new element in the bucket if it doesn't existt
	this->size++;									
}
//===================================================
void HashMap::search(const string key)
{
	int index = hashCode(key)%this->capacity;
	int counter = 0;
	
	//range loop that goes through the buckets indexes
	for(auto it:buckets[index]) 
	{
		Hotel hotel = it.getValue();

		// if the hotelcityname exist in the table
		if(hotel.gethotelcityname()==key)
		{
			//display it
			hotel.display();
			cout<<" (comparisions = "+to_string(++counter)+")"<<endl;
			return;
		}
		counter++;
	}

	cout<< "Hotel not found"<<endl;	// otherwise the hotel is not found
}
//=====================================================

// remove method for the first hashmap 
void HashMap::remove(const string key)
{
	int index = hashCode(key)%this->capacity;	//the index that we get here is for the key(hotelname, cityname)
	for(list<HashNode>::iterator it = buckets[index].begin(); it!=buckets[index].end(); ++it) 
	{
		if(it->getKey()==key)
		{
			cout<<"Deleted : ";
			it->getValue().display();
			
			buckets[index].erase(it);
			
			return;
		}
	}

	cout<<"Cant delete....Record Not Found...!"<<endl;			//conclude that data not found in the array

}
// remove method for the seocnd hashmap
void HashMap::remove1(const string key)
{
	int found= key.find(',');
	int end= key.length();
	string hotelname1=key.substr(0, found);
	string cityname1=key.substr(found+1, end);
	int index = hashCode(cityname1)%this->capacity;	//the index that we get here is for the cityname


	for(list<HashNode>::iterator it = buckets[index].begin(); it!=buckets[index].end(); ++it) 
	{
		if(it->getKey()==cityname1)
		{
			// cout<<"Deleted : ";
			// it->getValue().display();
			
			// buckets[index].erase(it);
			
			return;
		}
	}


}

//method to find all hotels in city
void HashMap::allincity(const string key) //change
{
	int index = hashCode(key)%this->capacity;			//Get the index of the bucket
	int counter = 0;
	// range based loop that goes through the index of the buckets
	for(auto & it:buckets[index]) 
	{
		
		if(it.getKey()==key)
		{
			// if the key is the same we get the value for the key and display it
				it.getValue().display();		
		}
	}

}

// method to dump a sorted hashmap
void HashMap::dump(const string key)
{
	//creating a vector of type Hotel
	vector<Hotel> keysvector;
	//creating a vector of type string
	vector<string> sortedvector;

	// psuhing values of the hashmap into a keys vector
	for(int index=0; index<this->capacity; index++)
	{
		for(auto & it:buckets[index])
			{
				keysvector.push_back(it.getValue());
			}
	}
	
	// for loop to push back the strings values of the objects to the string vectors
	for (int i=0; i<keysvector.size();i++) {
		sortedvector.push_back(keysvector[i].display2());
	}
	// sorting the vector
	sort(sortedvector.begin(), sortedvector.end());
	// dumping it into a file
	ofstream myfile;
	myfile.open(key);
	for (int i=0; i<sortedvector.size();i++) {
		myfile<<sortedvector[i]<<endl;
	}
	myfile.close();
}
//===================================================
// method to get size
int HashMap::getSize()
{
	return this->size;
}

// destructor
HashMap::~HashMap()
{
	delete[] this->buckets;
}

// is prime function used to check if the number is prime or not
bool isPrime(long number)
{
	// goes all the way from 2 to square root of the number
	for (int i=2; i<=sqrt(number); i++)
		if(number%i==0)// if not prime
		{
			return false;
		}
	return true; // prime
}
// count comma function used in error checking in the input
int countcomma(string input, char comma)
{
	int numcomma=0;
	for (int i=0; i<=input.size(); i++)
		{
			if (input[i]==comma)
			{
				numcomma++;
			}

		}
	return numcomma;
}