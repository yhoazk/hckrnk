#include <iostream>
#include <string>

using namespace std;

typedef struct {
    int count;
    int card;
} element;

/* Create a table of entries for each possible value in the universe of the 
 * input, in this case, lowercase ascii */
element universe['z'-'a'+1] = {0};

char get_uniq(string& str)
{
    char* c = &str[0];
    char r = 0;
    int n = 12250;
    cout << "Str Len: " <<str.length() << "\n";
    for(int i=0; i < str.length(); ++i)
    {
       // cout << "c_: " << *(i+c) << "\n";
        universe[*(c+i) - 'a'].count++;
        universe[*(i+c) - 'a'].card = i;
    }
    for(int i=0; i < sizeof(universe)/sizeof(universe[0]); ++i)
    {
       // cout << "char: " << 'a'+i <<  " i: " << i << " cout: " << universe[i].count << " card: " << universe[i].card << "\n";
        if(universe[i].count == 1 )
        {
            if(universe[i].card < n)
            {
                n = universe[i].card;
                r = i + 'a';
         //       cout << "r: " << int(r) << "\n";
            }
            //n = universe[i].card;
        }
    }
    return r;
}

int main()
{
    string s;
    cin >> s;
    cout << "Siye " << sizeof(universe)/sizeof(universe[0]) << "\n";
    char c = get_uniq(s);
    cout << c;
    //cout << s << s;
}
