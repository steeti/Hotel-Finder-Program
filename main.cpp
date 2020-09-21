//Saad Teeti
//sht318
#include "header.h"
#include "myfunctions.h"
using namespace std;
int main(int argc, char* args[])
{
	string filename;
	for (int i = 1; i < argc; i++) {
		if (strcmp(args[i],"-f")==0) 
			filename=args[i+1];
		}
	// opening file
	ifstream fin(filename);
	if(! fin.is_open())
	{
		cout<<"Can't open the file"<<endl;
		return EXIT_FAILURE;

	}
	string line2;
	// counter for the size of hash map, 
	unsigned long counter=0;
	while(!fin.eof())
	{
		getline(fin,line2);
		counter++;
	}
	// gets line by line and increamt the counter
	// clearing the file and starting fromt he begining for the next function
	fin.clear();
	fin.seekg(0, std::ios::beg);

	//size of the hashmap before finding the next prime
	unsigned long size= (1.333*counter)+1;
	unsigned long nextprime;
	// while loop to find the next prime
	while (true)
	{
		if (isPrime(size)==true)
		{
			nextprime=size;
			break;
		}
		else
		{
			size++;
		}
	}
	// creating two hashmaps, 
	//the first is for when the key is both hotelname and city name
	// the second is for when the key is cityname, used for all in the city
	HashMap HashMap1(nextprime);
	HashMap HashMap2(nextprime);
	string line;
	getline(fin, line);
	// while loop to get the key and the value
	while(!fin.eof()) 
	{
		string hotelname, cityname, stars, price, countryname, address;
		getline(fin,hotelname,',');
		getline(fin,cityname,',');
		getline(fin,stars,',');
		getline(fin,price,',');
		getline(fin,countryname,',');
		getline(fin,address,'\n');
		string key= hotelname + ','+cityname;
		string key2=cityname;
		// insert method, for the value, it is the same for both
		Hotel value(hotelname, cityname, stars, price, countryname, address);
		HashMap1.insert(key, value);
		HashMap2.insert1(key2, value);
	}

	
	fin.close();

	string command;
	cout<<"Choose one of the following commands, find, add, allinCity, delete, dump, quit"<<endl;
	while (true)
	{
		int count;
		getline(cin, command);
		vector<int> commapostions;
		int commacounter=countcomma(command,',');
		// if the user enters "quit" we exit the program
		if (command.find("quit")!=string::npos) 
				break;
		// if the user enters find, then we implemt the search method for the first hashmap
		// and the commas in the entries must be 1
		else if((command.find("find ")!=string::npos)&&(commacounter==1))
		{
			HashMap1.search(command.substr(5, command.length()));
		}
		// if the user enters add, then we implemt the add method for the both hashmaps
		// and the commas in the entries must be 5

		else if((command.find("add ")!=string::npos)&&(commacounter==5))
		{
			string fullinfo=command.substr(4, command.length());
			for(int i=0;i<=fullinfo.size();i++)
			{
				if (fullinfo[i]==',')
					commapostions.push_back(i);
			}
			//from the user intrence 
			string hotelname3=fullinfo.substr(0, commapostions[0]);
			string cityname3=fullinfo.substr(commapostions[0]+1, commapostions[1]-commapostions[0]-1); 
			string stars3= fullinfo.substr(commapostions[1]+1, commapostions[2]-commapostions[1]-1);
			string price3= fullinfo.substr(commapostions[2]+1, commapostions[3]-commapostions[2]-1);
			string countryname3= fullinfo.substr(commapostions[3]+1, commapostions[4]-commapostions[3]-1); 
			string address3= fullinfo.substr(commapostions[4]+1, fullinfo.length());
			string key3= hotelname3 + ','+cityname3;
			string key4=cityname3;
			Hotel value2(hotelname3, cityname3, stars3, price3, countryname3, address3);
			cout<<hotelname3<<endl;
			cout<<cityname3<<endl;
			cout<<stars3<<endl;
			cout<<price3<<endl;
			cout<<countryname3<<endl;
			cout<<address3<<endl;
			HashMap1.insert(key3, value2);
			HashMap2.insert1(key4, value2);

		}
		// if the user enters allinCity, then we implemt the allincity method for the second hashmap
		// and the commas in the entries must be 0
		else if ((command.find("allinCity ")!=string::npos)&&(commacounter==0))
		{
			HashMap2.allincity(command.substr(10, command.length()));
		}
		// if the user enters remove, then we implemt the remove method for the both hashmaps
		// and the commas in the entries must be 1		
		else if ((command.find("delete ")!=string::npos)&&(commacounter==1))
		{
			HashMap1.remove(command.substr(7, command.length()));
			HashMap2.remove1(command.substr(7, command.length()));
			
		}
		// if the user enters remove, then we implemt the dump method for the first hashmap
		// and the commas in the entries must be 1

		else if ((command.find("dump ")!=string::npos)&&(commacounter==0))
		{
			HashMap1.dump(command.substr(5, command.length()));
		}
		else
		{
			cout<<"error in input"<<endl;

		}
	}
	return 0;


}
