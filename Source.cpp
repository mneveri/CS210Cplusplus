//Melanie Neceda
// 2.17.23

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class cornerGrocer {
private:
    map<string, int> items;

public:
    void readFile(string fileName) { //function to read file (used for item file)
        ifstream inputFile; //class to read file
        inputFile.open(fileName);

        if (inputFile.is_open()) {
            string item;
            while (inputFile >> item) {
                items[item]++;
            }
            inputFile.close(); //closes file
        }
        else {
            cout << "Unable to find file" << endl; //error if file cannot be opened
        }
    }

    void writeFile(string fileName) { //function to write file (used for frequency.dat)
        ofstream outputFile; //class to write file
        outputFile.open(fileName);

        if (outputFile.is_open()) {
            for (auto const& item : items) {
                outputFile << item.first << " " << item.second << endl;
            }
            outputFile.close(); //closes file
        }
        else {
            cout << "Unable to find file" << endl; //error if file cannot be opened
        }
    }

    int findItem(string item) {
        if (items.count(item) > 0) { //checks to make sure item count is greater than 0
            return items[item];
        }
        else {
            return 0; //returns 0 if item is not shown
            //function to find item in file, and prints the frequency
        }
    }

    void printFrequency() {
        for (auto const& item : items) {
            cout << item.first << " " << item.second << endl;
            //function to print the frequency of all items in the list
        }
    }

    void printHistogram() {
        for (auto const& item : items) {
            cout << item.first << " ";
            for (int i = 0; i < item.second; i++) {
                cout << "*";
            }
            cout << endl;
            //function to print histograms of the frequency in all items
        }
    }
};

int main() {
    cornerGrocer grocer;
    grocer.readFile("CS210_Project_Three_Input_File.txt");
    grocer.writeFile("frequency.dat");
    cout << "***------Corner Grocer-----***" << endl;
    //Opens input file and writes frequency.dat file

    int choice;
    string item;
    do {
        cout << "\n1) Item Frequency" << endl;
        cout << "2) Frequency of all items purchased" << endl;
        cout << "3) Histogram of all items purchased" << endl;
        cout << "4) Exit the program" << endl;
        cout << "Select menu option: ";
        cin >> choice;

        //Menu that offers choice of finding item frequency, frequency of all items in the file, histogram of all of the items in the file, and an exit program option

        switch (choice) {
        case 1:
            cout << "Item name: ";
            cin >> item;
            cout << "Item frequency: " << grocer.findItem(item) << endl;
            break;
            //Selection for item frequency
        case 2:
            grocer.printFrequency();
            break;
            //Selection for frequency of all items
        case 3:
            grocer.printHistogram();
            break;
            //selection for histogram
        case 4:
            break;
            //selection to end program
        default:
            cout << "Invalid choice" << endl;
            break;
            //error if an invalid choice is made
        }
    } while (choice != 4);

    return 0;
}
