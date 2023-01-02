//  array.cpp
//  Xuefan Gao
//  205555927
//  CS31 Project4

#include <string>
#include <cassert>
using namespace std;
//Return the index of the largest item or -1 if n <= 0.
int locateMaximum( const string array[ ], int n ){
    if (n<=0){
        return -1;
    }
    int max = 0;
    for(int i = 0; i < n; ++i){
        if(array[i] > array[max]){
            max = i;
        }
    }
    return max;
}

//If two or more elements of the passed array are identical, return true otherwise return false or if n <= 0 return false.
bool hasDuplicatedValues( const string array[ ], int  n ){
    if (n<=0){
        return false;
    }
    for(int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if(array[i] == array[j]){
                return true;
            }
        }
    }
    return false;
}

bool isVowel(char c){
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='Y' ){
        return true;
        }
        return false;
}

// Return the number of vowels found in each element of the passed array or if n <= 0 return -1 .
int countAllVowels( const string array[ ], int n ){
    if (n<=0)
           return -1;
    int count = 0;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < array[i].length(); j++){
            if(isVowel(array[i][j])){
                count = count+1;
                //cout << "count = " << count << endl;
            }
        }
    }
    return count;
}

//Adjust the passed array, moving the element found in the index value position to the end of the array (index value n-1) and moving the element found at the end of the array (index value n-1) to the index value position, returning the value of position. If n <= 0 or position is < 0 or position >= n, return -1 and do not adjust the passed array at all.
void swap(string &a, string &b){
    string temp = a;
    a = b;
    b = temp;
}
int moveToEnd( string array[ ], int n, int position ){
    if (n<=0 || position < 0 || position >=n)
           return -1;
    string temp = array[position];
    array[position] = array[n-1];
    array[n-1] = temp;
    return position;
}

bool isNum(string s){
    for(int i = 0; i < s.size(); i++){
        if (isdigit(s[i]) == false){
            return false;
        }
    }
    return true;
}
            
//Return the number of integer values found in the passed array or if n <= 0 return -1 . For the purposes of this function, an integer should be made up of solely digit characters with no leading '+', '-' or decimal point.
int countIntegers( const string array[ ], int  n ){
    if (n<=0)
        return -1;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(isNum(array[i]) == true){
            count++;
        }
    }
    return count;
}

//Adjust the passed array, rotating elements in the array amount number of times, returning the total count of all the elements that have been rotated. If n<=0oramount<0,return-1.
int rotateRight( string array[ ], int n, int amount ){
    if (n<=0 || amount < 0)
        return -1;
    for(int j = 0; j < amount; j++){
        string temp = array[n-1];
        for(int i = n-2; i >=0; i--){
            array[i+1] = array[i];
        }
        array[0] = temp;
    }
    
    return n*amount;
}

int shiftLeft( string array[ ], int n, int amount, string placeholder ){
    if (n<=0 || amount <0)
        return -1;
    for (int i = 0; i < amount; i++){
        for(int j = 0; j < n-1; j++){
            array[j] = array[j+1];
        }
        array[n-1] = placeholder;
    }
    if(amount <= n)
        return amount;
    else
        return n;
}
//Shifting elements left amount number of times and using the placeholder value for the left-most positions. Return the total number of times the placeholder value got entered into the array. If n <= 0 or amount < 0, return -1 and do no adjust the passed array at all.



int main() {
    //test locate Maximum
    string a[5] = {"a", "a", "c", "d", "e"};
    string b[5] = {"5", "4", "3", "2", "2"};
    assert(locateMaximum(a, 3) == 2);
    assert(locateMaximum(a, 5) == 4);
    assert(locateMaximum(b, 1) == 0);
    assert(locateMaximum(b, 5) == 0);
    // test duplicatedValues
    string c[2] = {"e", "e"};
    assert(hasDuplicatedValues(c, 2));
    assert(!hasDuplicatedValues(c, 1));
    assert(hasDuplicatedValues(a, 3));
    assert(!hasDuplicatedValues(b, 4));
    assert(hasDuplicatedValues(b, 5));
    assert(hasDuplicatedValues(a, 2));
    assert(!hasDuplicatedValues(c, 0));
    // test countAllVowels
    assert(countAllVowels(a, 0)==-1);
    assert(countAllVowels(a, 1)==1);
    assert(countAllVowels(a, 2)==2);
    assert(countAllVowels(a, 3)==2);
    assert(countAllVowels(a, 5)==3);
    assert(countAllVowels(b, 5)==0);
    string v[7] = {"ag05eaea", "ikl", "qo", "uu", "Yp", "AETTIOU", "yyy"};
    assert(countAllVowels(v, 7)==18);
    assert(countAllVowels(v, 1)==5);
    // test move to end
    //eacda
    assert(moveToEnd(a, 5, 0)==0);
    assert(a[0] == "e");
    assert(a[4] == "a");
    //eacda
    assert(moveToEnd(a, 5, 1)==1);
    assert(a[1] == "a");
    assert(a[4] == "a");
    //eaadc
    assert(moveToEnd(a, 5, 2)==2);
    assert(a[2] == "a");
    assert(a[4] == "c");
    assert(moveToEnd(a, 5, 4)==4);
    assert(a[4] == "c");
    // test countIntegers
    assert(countIntegers(b, 1) == 1);
    assert(countIntegers(b, 5) == 5);
    string i[5] = {"1q1", "303", "o8", "0", "-4"};
    assert(countIntegers(i, 1) == 0);
    assert(countIntegers(i, 2) == 1);
    assert(countIntegers(i, 3) == 1);
    assert(countIntegers(i, 4) == 2);
    assert(countIntegers(i, 5) == 2);
    assert(countIntegers(a, 5) == 0);
    // test rotateRight
    string r[5] = {"a", "b", "c", "d", "e"};
    assert(rotateRight(r, 4, 0) == 0);
    assert(r[0] == "a");
    assert(r[1] == "b");
    assert(r[2] == "c");
    assert(r[3] == "d");
    assert(r[4] == "e");
    //cdabe
    assert(rotateRight(r, 4, 2) == 8);
    assert(r[0] == "c");
    assert(r[1] == "d");
    assert(r[2] == "a");
    assert(r[3] == "b");
    assert(r[4] == "e");
    assert(rotateRight(r, 4, 2) == 8);
    assert(r[0] == "a");
    assert(r[1] == "b");
    assert(r[2] == "c");
    assert(r[3] == "d");
    assert(r[4] == "e");
    assert(rotateRight(r, 1, 0) == 0);
    assert(r[0] == "a");
    assert(r[1] == "b");
    assert(r[2] == "c");
    assert(r[3] == "d");
    assert(r[4] == "e");
    assert(rotateRight(r, 5, 3) == 15);
    assert(r[0] == "c");
    assert(r[1] == "d");
    assert(r[2] == "e");
    assert(r[3] == "a");
    assert(r[4] == "b");
    // test shiftLeft
    string s[5] = {"a", "b", "c", "d", "e"};
    assert(shiftLeft(s, 5, 2, "0")==2);
    assert(s[0] == "c");
    assert(s[1] == "d");
    assert(s[2] == "e");
    assert(s[3] == "0");
    assert(s[4] == "0");
    string s1[5] = {"a", "b", "c", "d", "e"};
    assert(shiftLeft(s1, 5, 7, "0")==5);
    assert(s1[0] == "0");
    assert(s1[1] == "0");
    assert(s1[2] == "0");
    assert(s1[3] == "0");
    assert(s1[4] == "0");
    string s2[5] = {"a", "b", "c", "d", "e"};
    assert(shiftLeft(s2, 3, 2, "0")==2);
    assert(s2[0] == "c");
    assert(s2[1] == "0");
    assert(s2[2] == "0");
    assert(s2[3] == "d");
    assert(s2[4] == "e");
    
    // test cases in project documentations
    string folks[8] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "llewmas", "noj" };
    string values[5] = { "jon", "mamabbcc!", "jon", "123", "45" };
    assert(locateMaximum( folks, 5 ) == 4);
    assert(locateMaximum( folks, 4 ) == 0);
    assert(hasDuplicatedValues( folks, 8 ) == false);
    assert(hasDuplicatedValues( values, 5 ) == true);
    assert(countAllVowels( folks, 5 ) == 14);
    assert(countAllVowels( folks, 8 ) == 19);
    assert(countIntegers( values, 5 ) == 2);
    assert(countIntegers( folks, 5) == 0);
//    tested
//    assert(moveToEnd( folks, 5, 1 ) == 1);
//    assert(folks[1] == "tyrion");
//    assert(folks[4] == "jon");
//    // tested
//    assert(rotateRight(folks,5,1) == 5);
//    assert(folks[ 0 ] == "tyrion");
//    assert(folks[ 1 ] == "samwell");
//    assert(folks[ 2 ] == "jon");
//    assert(folks[ 3 ] == "margaery");
//    assert(folks[ 4 ] == "daenerys");
//    // tested
//    assert(rotateRight( folks, 5, 2 ) == 10);
//    assert(folks[ 1 ] == "tyrion");
//    assert(folks[ 2 ] == "samwell");
//    assert(folks[ 3 ] == "jon");
//    assert(folks[ 4 ] == "margaery");
//    assert(folks[ 0 ] == "daenerys");
//    //
//    assert(shiftLeft( folks, 5, 1, "foo" ) == 1);
//    assert(folks[ 0 ] == "jon");
//    assert(folks[ 1 ] == "margaery");
//    assert(folks[ 2 ] == "daenerys");
//    assert(folks[ 3 ] == "tyrion" );
//    assert(folks[ 4 ] == "foo");
    //
    assert(shiftLeft( folks, 5, 2, "foo" ) == 2);
    assert(folks[ 4 ] == "foo");
    assert(folks[ 0 ] == "margaery");
    assert(folks[ 1 ] == "daenerys");
    assert(folks[ 2 ] == "tyrion" );
    assert(folks[ 3 ] == "foo");
    
    string x[6] = { "123", "456", "delta", "gamma", "beta", "delta" };
    assert(hasDuplicatedValues(x, 6 ) == true);
    assert(hasDuplicatedValues(x, 3 ) == false);

    //cout << "finished";
    return 0;
}



