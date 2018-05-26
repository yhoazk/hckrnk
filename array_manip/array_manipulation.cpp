#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
// As it would be wasteful to create an array with all the n 
// elemets we could find the  weighted overlaping ranges
// the order of the operations does not matter 
// We could use a patch structure, where the number of 
// patches is the number of areas separated by 0s
// and every patch keeps it's max value at the end we just
// collect the max of every patch. The problem with approach 
// are:
// - sparce patches that may consume memory
// - unbalancend patches which may have big differences in value
// - 
//
// TODO find intersecting planes in 2D
#define NAIVE
#ifdef NAIVE
vector<long> values;
long arrayManipulation(int n, vector<vector<int>> queries) {
  values.resize(n);
  long max = 0;

  

  return max;
}
#else
long arrayManipulation(int n, vector<vector<int>> queries) {
}
#endif
int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    long result = arrayManipulation(n, queries);

    cout << result << "\n";

    //fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

