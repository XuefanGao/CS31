// elevator.cpp
// CS31 Project3
// Xuefan Gao
// UID: 205555927

#include <iostream>
#include <string>
#include <cassert>
#include <ctype.h>
using namespace std;

// helper functions
// returns true if the character is valid(M, O, C, +, - and digit characters)
bool isValidCharacter(char c){
    string v = "MOC+-0123456789";
    for(int i = 0; i < v.size(); i++){
        if (c == v[i])
            return true;
    }
    return false;
}

// returns true if its parameter is a well-formed elevator string, or false otherwise.
bool isValidElevatorString(string elevatorstring){
    string s = elevatorstring;
    bool doorClosed = true; // elevators always start with the doors closed
    int size = int(elevatorstring.size());
    
    // the only characters present should be M, O, C, +, - and digit characters
    for (int i = 0; i < elevatorstring.size(); i++){
        if (isValidCharacter(elevatorstring[i]) == false){
            //cout << "not valid char\n";
            return false;
        }
    }
    
    // an elevator string must begin with M followed by digits
    // This also covers the case with empty string
    if(elevatorstring[0] != 'M'){
        //cout << "not start with M\n";
        return false;
    }
    
    // if there's no floor number followed after 'M' or move to negative floor
    for(int i = 0; i < size; i++){
        if(elevatorstring[i] == 'M'){
            if(isdigit(elevatorstring[i+1]) == false){
                //cout << "no floor# after M\n";
                return false;
            }
            // doors must be closed before the elevator can be called to a different floor
            if(doorClosed == false){
                //cout << "move elevator when door open\n";
                return false;
            }
        }
        // elevators doors can only be opened if they are currently closed; elevator doors can only be closed if they are currently open
        if(elevatorstring[i] == 'O'){
            if (doorClosed == false){
                //cout << "open door when door is opened\n";
                return false;
            }
            doorClosed = false;
        }
        if(elevatorstring[i] == 'C'){
            if (doorClosed == true){
                //cout << "close door when door is closed\n";
                return false;
            }
            doorClosed = true;
        }
        if(elevatorstring[i] == '+' || elevatorstring[i] == '-'){
            if(doorClosed == true){
                //cout << "load people when door is closed\n";
                return false;
            }
            // +, - must be followed by digits
            if(isdigit(elevatorstring[i+1]) == false){
                //cout << "no people# after +/-\n";
                return false;
            }
        }
    }

    // elevator strings must end with either O, C or a digit character and not a +, - or M
    char end = elevatorstring[size-1];
    if(end == '+' || end == '-' || end == 'M'){
        //cout << "wrong ending char\n";
        return false;
    }

    // check for negative passengers
    int sum = 0;
    for(int i = 0; i < size; i++){
        if(s[i] == '+' || s[i] == '-'){
            string num = "";
            // extract the number after +/-
            // iterate from there to the end of the string
            int j = i+1;
            while(j < s.size() && isdigit(s[j])){
                num.push_back(s[j]);
                j = j+1;
            }
            int n = stoi(num);
            //cout << num << "\n";
            num = "";
            //cout << n << "\n";
            if(s[i] == '+'){
                sum = sum + n;
            }
            if(s[i] == '-'){
                sum = sum -n;
            }
            if(sum<0){
                //cout << sum << "negative ppl\n";
                return false;
            }
        }
    }
    return true;//0 is false
}

// If the parameter is a well-formed elevator string, return true if the elevator doors are open at the end; return false otherwise.
bool doorsOpen(string elevatorstring){
    bool temp = false;
    if(isValidElevatorString(elevatorstring) == false){
        return false;
    }
    for (int i = 0; i <elevatorstring.size(); i++){
        if(elevatorstring[i] == 'O'){
            temp = true;
        }
        if(elevatorstring[i] == 'C'){
            temp = false;
        }
    }
    return temp;
}

// If the parameter is a well-formed elevator string, this function should return the number of passenger aboard the elevator at the end of processing the entire elevator string. If the parameter is not a valid elevator string, return -1
int endingPassengers(string elevatorstring){
    if(isValidElevatorString(elevatorstring) == false){
        return -1;
    }
    int sum = 0;
    string s = elevatorstring;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+' || s[i] == '-'){
            string num = "";
            // extract the number after +/-
            int j = i+1;
            while(j < s.size() && isdigit(s[j])){
                num.push_back(s[j]);
                j = j+1;
            }
            int n = stoi(num);
            //cout << num << "\n";
            num = "";
            //cout << n << "\n";
            if(s[i] == '+'){
                sum = sum + n;
            }
            if(s[i] == '-'){
                sum = sum -n;
            }
        }
    }
    return sum;
}

// If the parameter is a well-formed elevator string, this function should return the greatest number of passengers ever aboard the elevator as the elevator string is processed. If the parameter is not a valid elevator string, return -1
int mostPassengers(string elevatorstring){
    if(isValidElevatorString(elevatorstring) == false){
        return -1;
    }
    int sum = 0;
    int max = 0;
    string s = elevatorstring;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+' || s[i] == '-'){
            string num = "";
            // extract the number after +/-
            int j = i+1;
            while(j < s.size() && isdigit(s[j])){
                num.push_back(s[j]);
                j = j+1;
            }
            int n = stoi(num);
            //cout << num << "\n";
            num = "";
            //cout << n << "\n";
            if(s[i] == '+'){
                sum = sum + n;
            }
            if(s[i] == '-'){
                sum = sum -n;
            }
            if(sum > max){
                max = sum;
            }
        }
    }
    return max;
}

// If the parameter is a well-formed elevator string, this function should return the floor the elevator ended on at the end of processing the entire elevator string. If the parameter is not a valid elevator string, return -1.
int endingFloor(string elevatorstring){
    if(isValidElevatorString(elevatorstring) == false){
        return -1;
    }
    string s = elevatorstring;
    string num = "";
    int floor = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'M'){
            int j = i+1;
            while(j < s.size() && isdigit(s[j])){
                num.push_back(s[j]);
                j = j+1;
            }
            floor = stoi(num);
            num = "";
        }
    }
    return floor;
}

// If the parameter is a well-formed elevator string, this function should return the greatest floor the elevator moved to as the elevator string is processed. If the parameter is not a valid elevator order string, return -1.
int highestFloor(string elevatorstring){
    if(isValidElevatorString(elevatorstring) == false){
        return -1;
    }
    string s = elevatorstring;
    string num = "";
    int floor = 0;
    int max = 0;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'M'){
            int j = i+1;
            while(j < s.size() && isdigit(s[j])){
                num.push_back(s[j]);
                j = j+1;
            }
            floor = stoi(num);
            num = "";
            if(floor > max){
                max = floor;
            }
        }
    }
    return max;
}
bool mostAndHighestAreEqual(string elevatorstring){
    if(isValidElevatorString(elevatorstring) == false){
        return false;
    }
    if(mostPassengers(elevatorstring) == highestFloor(elevatorstring)){
        return true;
    }
    else{
        return false;
    }
}

int main() {

    assert(isValidElevatorString("M1") == true);
    assert(isValidElevatorString("M1O+3") == true);
    assert(isValidElevatorString("M1O+1+1+1") == true);
    assert(isValidElevatorString("M1O+1+1+1CM5") == true);
    assert(isValidElevatorString("M1O+1+1+1CM5O-2+4") == true);
    assert(isValidElevatorString("M1O+3CM5O+1+1+1+1-1-1") == true);

    assert(isValidElevatorString("M12") == true);
    assert(isValidElevatorString("M12O+1-0C") == true);
    assert(isValidElevatorString("M12O+1CM3") == true);
    assert(isValidElevatorString("M0") == true);
    assert(isValidElevatorString("M1O+0004C") == true);
    assert(isValidElevatorString("M3O+3COCOCM2") == true);
    assert(isValidElevatorString("M12O+1-1+1-1+1") == true);
    assert(isValidElevatorString("M10M8M9") == true);
    assert(isValidElevatorString("M2OCOC") == true);
    assert(isValidElevatorString("M2OCM1") == true);
    assert(isValidElevatorString("M2OCO") == true);
    assert(isValidElevatorString("M2O+3CO-1CO") == true);


    assert(isValidElevatorString("M") == false);
    assert(isValidElevatorString("M1C") == false);
    assert(isValidElevatorString("M1OCOO") == false);
    assert(isValidElevatorString("M1O-12+50") == false);
    assert(isValidElevatorString("M1O+4-3-1CM2O-1") == false);
    assert(isValidElevatorString("M1O+-C") == false);
    assert(isValidElevatorString("M-3") == false);
    assert(isValidElevatorString("") == false);
    
    assert( isValidElevatorString("    ")== false);
    assert( isValidElevatorString("") == false );
    assert( doorsOpen( "    " ) == false );
    assert( endingPassengers( "      " ) == -1 );
    assert( mostPassengers( "      " ) == -1 );
    assert( endingFloor( "       " ) == -1 );
    assert( highestFloor( "       " ) == -1 );
    assert( isValidElevatorString( "M1O+3-5C" ) == false);
    assert( isValidElevatorString( "M1O+3-2C" ) );
    assert( doorsOpen( "M1O+3-2C" ) == false );
    assert( endingPassengers( "M1O+3-2C" ) == 1 );
    assert( mostPassengers( "M1O+3-2C" ) == 3 );
    assert( endingFloor( "M1O+3-2C" ) == 1 );
    assert( highestFloor( "M1O+3-2C" ) == 1 );
    
    //test functions
    string s = "M1O+1+1+1CM2OCOCM99O+50CM9999O-3CM2O-50CO+1CO+9";
    assert(isValidElevatorString(s));
    assert(endingFloor(s) == 2);
    assert(highestFloor(s) == 9999);
    assert(mostPassengers(s) == 53);
    assert(endingPassengers(s) == 10);
    //cout << "pass\n";
    s = "M10O+10";
    assert(mostAndHighestAreEqual(s));
    cout<< mostPassengers(s)<< endl;
    cout<< highestFloor(s)<< endl;
    s = "M10O+100";
    assert(!mostAndHighestAreEqual(s));
    cout<< mostPassengers(s)<< endl;
    cout<< highestFloor(s)<< endl;
    return 0;
}
