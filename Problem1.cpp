#include <iostream>
#include <fstream>
using namespace std;

// addding a comment

int arraySize = 100;

void printArray(int arrayToPrint[], int arraySize)
{
    cout << "array: ";
    for (int i = 0; i < arraySize; i++)
    {
        cout << arrayToPrint[i] << ", ";
    }
    cout << endl;
}

int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
    if (numEntries >= arraySize)
    {
        return numEntries;
    }

    //cout << "insert " << newValue << " " << numEntries << endl;

    bool flag = false;

    if (numEntries == 0)
    {
        myArray[numEntries] = newValue;
    }
    else
    {
        for(int i = 0; i < numEntries; i++)
        {
            if (flag == true || newValue <= myArray[i])
            {

                int tempValue = myArray[i];
                myArray[i] = newValue;
                newValue = tempValue;
                flag = true;
            }
        }

        myArray[numEntries] = newValue;
    }

    numEntries++;

    return numEntries;
}


int main(int argc, char* argv[])
{
    int array[100];
    int size = 0;

    string filename = argv[1];
    ifstream inFile;
    inFile.open(filename.c_str());

    if (inFile.is_open())
    {
        string line1;

        while(getline(inFile, line1))
        {
            size = insertIntoSortedArray(array, size, stoi(line1));
            printArray(array, size);
            cout << endl;
            // cout << line1 << " " << stoi(line1) << endl;
        }
    }

    inFile.close();

}
