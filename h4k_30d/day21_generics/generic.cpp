#include <iostream>
#include <vector>

using namespace std;
//----------------------------
/*
template <int>
void printArray(vector<int> &inArg){
    int i;
    for ( i=0; i<inArg.size(); i++){
        cout << inArg[i] << endl;
    }
}*/
template <typename T>
void printArray(const vector<T>& inArg){
    int i;
    for ( i=0; i<inArg.size(); i++){
        cout << inArg[i] << endl;
    }
}

//----------------------------
int main()
{
    vector<int> vInt{1, 2, 3};
    vector<string> vString{"Hello", "World"};
    
    printArray<int>(vInt);
    printArray<string>(vString);
    
    return 0;
}
