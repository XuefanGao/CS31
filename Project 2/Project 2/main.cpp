// Xuefan Gao
// CS31 Summer 2021
// Project 2
// 205555927

#include <iostream>

using namespace std;

int main()
{
    string model;
    string color;
    int memory;
    
    //read user input
    cout << "What type of iPhone do you want? ";
    getline(cin, model);
    cout << "What color do you want? ";
    getline(cin, color);
    cout << "How much memory do you want? ";
    cin >> memory;
    
    
    // check model
    // if the user enter "iPhone 12 for the model selection"
    if(model.compare("iPhone 12") == 0){
        // check color
        if(color.compare("White")  == 0 || color.compare("Black")  == 0 ||
        color.compare("Blue")   == 0 || color.compare("Green")  == 0 ||
        color.compare("Red")    == 0 || color.compare("Purple") == 0){
            // check momory
            if (memory == 64){
                cout << "Your " << color << " " << model << " costs $799.00." << endl;
            }
            else if (memory == 128){
                cout << "Your " << color << " " << model << " costs $849.00." << endl;
            }
            else if (memory == 256){
                cout << "Your " << color << " " << model << " costs $949.00." << endl;
            }
            else{
                cout << "Your memory selection is not valid!" << endl;
            }
        }
        else{
            cout << "Your color selection is not valid!" << endl;
        }
    }
    
    // if the user enter "iPhone 12 Mini for the model selection"
    else if(model.compare("iPhone 12 Mini") == 0){
        // check color
        if(color.compare("White")  == 0 || color.compare("Black")  == 0 ||
        color.compare("Blue")   == 0 || color.compare("Green")  == 0 ||
        color.compare("Red")    == 0 || color.compare("Purple") == 0){
            // check momory
            if (memory == 64){
                cout << "Your " << color << " " << model << " costs $699.00." << endl;
            }
            else if (memory == 128){
                cout << "Your " << color << " " << model << " costs $749.00." << endl;
            }
            else if (memory == 256){
                cout << "Your " << color << " " << model << " costs $849.00." << endl;
            }
            else{
                cout << "Your memory selection is not valid!" << endl;
            }
        }
        else{
            cout << "Your color selection is not valid!" << endl;
        }
    }
    
    // if the user enter "iPhone 12 Pro for the model selection"
    else if(model.compare("iPhone 12 Pro") == 0){
        // check color
        if(color.compare("Graphite")  == 0 || color.compare("Silver")  == 0 ||
        color.compare("Blue")   == 0 || color.compare("Gold")  == 0){
            // check momory
            if (memory == 128){
                cout << "Your " << color << " " << model << " costs $999.00." << endl;
            }
            else if (memory == 256){
                cout << "Your " << color << " " << model << " costs $1099.00." << endl;
            }
            else if (memory == 512){
                cout << "Your " << color << " " << model << " costs $1299.00." << endl;
            }
            else{
                cout << "Your memory selection is not valid!" << endl;
            }
        }
        else{
            cout << "Your color selection is not valid!" << endl;
        }
    }
    
    // if the user enter "iPhone 12 Pro Max for the model selection"
    else if(model.compare("iPhone 12 Pro Max") == 0){
        // check color
        if(color.compare("Graphite")  == 0 || color.compare("Silver")  == 0 ||
        color.compare("Blue")   == 0 || color.compare("Gold")  == 0){
            // check momory
            if (memory == 128){
                cout << "Your " << color << " " << model << " costs $1099.00." << endl;
            }
            else if (memory == 256){
                cout << "Your " << color << " " << model << " costs $1199.00." << endl;
            }
            else if (memory == 512){
                cout << "Your " << color << " " << model << " costs $1399.00." << endl;
            }
            else{
                cout << "Your memory selection is not valid!" << endl;
            }
        }
        else{
            cout << "Your color selection is not valid!" << endl;
        }
    }
    
    
    else{
        // if the model is not valid , output error message
        cout << "Your model selection is not valid!" << endl;
    }

    return( 0 );
}
