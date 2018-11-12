#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<boost/algorithm/string.hpp>

using namespace std;


// void vector<vector<string>> program_open()	//I don't think you need this now 
// {
// 	string file_name = "db.csv", delimeter = ",";

// 	ifstream file(file_name);
// 	vector<vector<string>> dataList;
// 	string line = "";

// 	while(getline(file, line))
// 	{
// 		vector<string> vect;
// 		boost::algorithm::split(vect, line, boost::is_any_of(delimeter));
// 		dataList.push_back(vect);
// 	}

// 	return dataList;
// }

void store_value()	//stores all IDs, names and room nos in separate vectors
{
	string file_name = "db.csv", delimeter = ",";

	ifstream file(file_name);
	
	vector<string> nm_v, rm_v, id_v;

	string line = "";

	getline(file, line);

	while(getline(file, line))
	{
			vector<string> vect;
			boost::algorithm::split(vect, line, boost::is_any_of(delimeter));
			
			id_v.push_back(vect[0]);
			nm_v.push_back(vect[1]);
			rm_v.push_back(vect[2]);
	}

	// file.close();

	for (int i = 0 ; i < 40 ; i++)	//display all the vectors (delete if you don't want)
  	{
	   cout <<  id_v[i] << " " << nm_v[i] << " " << rm_v[i] << endl;
  	}
      file.close();
}

int main()
{
    // program_open();
    store_value();


    return 0;
}
