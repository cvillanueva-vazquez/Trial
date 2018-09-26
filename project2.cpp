//Cesar Villanueva-Vazquez
//CS 2308
#include <iostream>
#include <string>
using namespace std;

/*Project 2:
this project is going to sort through an  unsorted array
using bubble sort. After it has sorted the array from smallest
to largest it will search for the entered student ID, student name
and corresponding email using sequential and binary
search. This will then display the Student ID, Student Name, and
Student Email */
//This is a test//
const int NUM_Elems = 12;
const int MIN_STUDID = 1100;
const int MAX_STUDID = 1111;

//Function prototypes
int getStudID() ;
int binarySearch( int [], int, int); //binary function
int linearSearch(const int [], int, int);  //linear function
void binarydisplayStudID(const string[],const string [], int,const int []);
void lineardisplayStudID(const string[], const string[], int, const int[]);
void bubbleSort( int[], string[], string [] ,int); //try using double sort from page 491 in book
void swapp(int &, int &);
void swapp( string &, string &);
void swapp2( string &, string &);

int main()
{
////////////Student ID Array/////////////////////////
	int id[NUM_Elems] = {1108, 1101, 1104, 1103, 1102, 1107, 1106, 1105,
								1100, 1111, 1110, 1109};
////////////Student Name Array/////////////////////////
	string studName[NUM_Elems] =
		  { "Berry Allen",
			"Joseph Avilez",
			"Ken Brown",
            "Kyle Brown",
			"Billy Batson",
			"Tim Drake",
			"John Jones",
			"Hall Jordan",
			"Clark Kent",
			"Victor Stone",
			"Oliver Queen",
			"Bruce Wayne",
			};
////////////Student Email Array/////////////////////////
	string studEmail[NUM_Elems] =
		{
			"berry.allen@txstate.edu",
			"joseph.avilez@txstate.edu",
			"ken.brown@txstate.edu",
            "kyle.brown@txstate.edu",
			"billy.batson@txstate.edu",
			"tim.drake@txstate.edu",
			"john.jones@txstate.edu",
			"hall.Jordan@txstate.edu",
			"clark.kent@txstate.edu",
			"victor.stone@txstate.edu",
			"oliver.queen@txstate.edu",
			"bruce.wayne@txstate.edu",
		};

/////display of entire array////////////
	for(int i = 0; i <NUM_Elems;i++)
	{
	cout << "Student ID:" << id[i] << "  " ;
	cout << "Student Name:" << studName[i] << "  ";
	cout << "Student email:" << studEmail[i] << endl;
	}

cout << "________________________________________________________________________________"
     << endl << endl;

//HOLDERS
	int id_stud;    //to hold a students name
	int index;       //to hold search results for binarySearch
	int ind;        //to hold search result for linear Search
	char again;      //for Y or N ans
////////////////////////////////////////////////////////////////
//////display sorted array////////////////////////////
////////////////////////////////////////
//sort the arrays
		bubbleSort( id , studEmail, studName, NUM_Elems);
    //display new sorted array
    cout << "Sorted Arrays:   " << endl;
    for(int i = 0; i <NUM_Elems;i++)
	{
	cout << "Student ID:" << id[i] << "  " ;
	cout << "Student Name:" << studName[i] << "  ";
	cout << "Student email:" << studEmail[i] << endl;
	}
//////////////////////////////////////////////////////////
///////////////////////////////////////////////////
	do
	{
	
		//get the desired student ID
	id_stud = getStudID();
		//Search for the Student NAME
		index = binarySearch( id, NUM_Elems, id_stud );

		ind = linearSearch(id , NUM_Elems, id_stud);





		//display the results of the search
		if (index == -1)
		{
			cout << "The Student ID entered is not in the system. \n";
		}
		else{

        	binarydisplayStudID(studName,studEmail,index,id);
			lineardisplayStudID(studName, studEmail, ind, id);
		//Does the user want to retry?
		cout << "would you like to look up another student? (Y/N)";
		cin >> again;
		}

	} while (again == 'Y' || again == 'y');


	return 0;

}
/*******************************************************
**********using the getStudID funtion*******************
********************************************************/
    int getStudID()
{
	int id_stud; //student ID

	 cout << "Please enter a student ID you wish to search for(from 1100 - 1111): \n" ;
	 cin >> id_stud;
	 //validate input


     while ( id_stud < MIN_STUDID || id_stud > MAX_STUDID )
	{
		cout << "Enter a student ID in the range of " << MIN_STUDID;
		cout << " through " << MAX_STUDID << ".\n";
		cin >> id_stud;
	}

 return id_stud;

 }
/*******************************************************
**********************Bubble Sort***********************
*******************************************************/
void bubbleSort( int arr2[], string name[], string email[], int NUM_Elems)
{
    int maxElems;
    int index;

    for(maxElems=NUM_Elems - 1;maxElems> 0;maxElems--)
    {
        for (index = 0; index < maxElems; index++)
        {
            if (arr2[index] > arr2[index+1])
            {
                swapp(arr2[index],arr2[index+1]);
				swapp(email[index], email[index+1]);
				swapp2(name[index], name[index+1]);
            }
        }
    }
}
/*******************************************************
**********************Swapps*****************************
******************************************************/
void swapp(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void swapp(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}
void swapp2(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

/*****************************************************
***********searching using binary***********************
*******************************************************/
int binarySearch( int array[], int numElems, int value)
{
	int first = 0,			//first array element
	last = numElems - 1,     //last array element ***declare num elems****
	middle,                 //midpoint of each search
	posit = -1;          //position of search value
	bool found = false;     //flag

		while (!found && first <= last)
		{
			middle = (first + last) / 2; //calculate midpoint
			if (array[middle] == value) //if balue is found at mid
			{
				found = true;
				posit = middle;

			}
			else if (array[middle] > value) //if value is in lower region of array
			{
				last = middle - 1;
			}
			else if(array[middle] < value) //if value is in upper region of array
			{
				first = middle + 1;
			}
		}
		return posit;
}
/******************************************************
********Searching using Sequential search**************
*******************************************************/
int linearSearch(const int arr[], int numElems, int value)
{
	int ind = 0; //used to go through numELems from 0 - 12
	int position = -1;
	bool found = false;

	while(ind < numElems && !found)  //initiate the while loop until position is found
	{
		if(arr[ind] == value) //if the value is found
		{
		found = true;
		position = ind; 		//record where position is
		}
	ind++; 					//go to the next element
	}
	return position;

}


/******************************************************
***********End of Sequential Search***********************
*******************************************************/

/*******************************************************
***********DISPLAY of Binary displayStudID funtction*************
*******************************************************/

void binarydisplayStudID(const string studName[], const string studEmail[], int index,const int id[])
{


	cout <<  "Binary: \n";
	cout << "Student ID:" << id[index] << "  " ;
	cout << "Student Name:" << studName[index] << "  ";
	cout << "Student email:" << studEmail[index] << endl;
}
/*******************************************************
***********DISPLAY of Linear displayStudID funtction*************
*******************************************************/
void lineardisplayStudID(const string studName[], const string studEmail[], int ind,const int id[])
{


	cout <<  "Linear: \n";
	cout << "Student ID:" << id[ind] << "  " ;
	cout << "Student Name:" << studName[ind] << "  ";
	cout << "Student email:" << studEmail[ind] << endl;
}
