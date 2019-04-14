#include <iostream>

using namespace std;
/******************************************/
/*****    START OF OUR CODE    ************/
/******************************************/

/*
 * Create classes Rectangle and RectangleArea
 */
template<typename NUM_T>
class Rectangle {
public:

    void display(){
        cout << width << " "  << height << endl;
    }
    NUM_T width{0};
    NUM_T height{0};
};


template<typename NUM_T>
class RectangleArea: public Rectangle {
public:
    void read_input(){
        cin >> width >> height;
    }
    
    void display(){
        cout <<   width * height << endl; 
    }
};

/******************************************/

int main(){
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}
