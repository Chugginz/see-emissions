/**
 *******************************************************************************
 * @file    Polygon.cpp
 * @brief   All function definitions for the header file Polygon that helps
 *          provide information about a Shape data type that is a circle.
 *
 * @author  Christian Huggins
 * @date    April 11th, 2021
 *******************************************************************************
**/

#include "Polygon.h"
#include<string>
    using std::string;

/**
 * @brief       This is the constructor given an array of points and the
 *              vertex count
 *
 * @detailed    Provided the x and y for the reference point, the constructor
 *              passes these values to the base classes constructor while
 *              the r is stored as the radius.
 *              
 * @param       const Point2D* vertices     Takes an array of points to
 *                                          store in the current class's
 *                                          vertices
 * 
 * @param       int vertex_count            Stores number of vertices into
 *                                          the current class's vertex count
**/

Polygon::Polygon(const Point2D* vertices, int vertex_count) 
    : Shape{vertices[0].x, vertices[0].y}{
    //Set the current class's vertices to be a new Point2D array the size
    // of vertex count
    this->vertices = new Point2D [vertex_count];
    
    //Until the counter is equal to vertex count, store the new vertice
    // values in the current class's vertice index
    for (int i = 0; i < vertex_count; i++){
        this->vertices[i] = vertices[i];
    }
    
    //Set the current class's vertex count to be the same as the other
    // vertex count
    this->vertex_count = vertex_count;
}

/**
 * @brief       This is the constructor for reading from a file
 *
 * @detailed    Given a file stream, the constructor will sink the fist
 *              coords into shape, and then moves them over to the copy
 *              of the array to dynamically allocate it to the proper size.
 *              After are elements are copied, the copy is deleted.
 *              
 * @param       std::istream& fin     File stream used for reading points
**/

Polygon::Polygon(std::istream& fin) : Shape{fin}{
    //Tell user constructor running
    cout << "DEBUG: Executing Polygon constructor...\n";
    //Set i to one for number of vertices
    int i = 1;
    //Create copy of array of Point2D pointers
    Point2D* copy = new Point2D [100];
    //Set copy of array's first coordinates
    copy[0].x = Shape::get_ref_x();
    copy[0].y = Shape::get_ref_y();
    
    //While not the end of the line
    while (fin.get() != ';'){
        //Store value into x
        fin >> copy[i].x;
        //Store value into y
        fin >> copy[i].y;
        //Increment i
        i++;
    }
    //Set vertex count to i, which is number of vertices
    vertex_count = i;
    
    //set vertices to size of vertex count
    vertices = new Point2D [vertex_count];
    //While not vertex count, increment while copying each vertex
    for (int j = 0; j < vertex_count; j++){
        vertices[j] = copy[j];
    }
    
    //Delete copy
    delete [] copy;
    //Set copy to nullptr so not accidentally called later
    copy = nullptr;
}

/**
 * @brief       This writes to a stream object
 *
 * @detailed    As the loop increments until the counter equals the vertex
 *              count, write the vertex and it's coordinates to the stream
 *              
 * @param       std::ostream& strm_out      Stream being written to
**/

void Polygon::write(std::ostream& strm_out) const{
    //As loop increments, write each vertex to stream
    for (int i = 0; i < vertex_count; i++){
        strm_out << "\nVertex " << i + 1 << ": (" << vertices[i].x
        << ", " << vertices[i].y << ")";
    }
}

/**
 * @brief       This writes to a stream object
 *
 * @detailed    Calls the polygon class's write function passing it the stream,
 *              then returning it
 *              
 * @param       std::ostream& strm_out      Stream being passed to write method
 * 
 * @param       const Polygon& p            Object that will be written
 * 
 * @return      Returns the stream object passed through the parameter
**/

std::ostream& operator<<(std::ostream& strm_out, const Polygon& p){
    p.write(strm_out);
    
    return strm_out;
}

/**
 * @brief       Calculates the area of a polygon
 *
 * @detailed    Taking the vertices of the polygon, the method will calculate
 *              the area of each individual section, eventually adding it all
 *              together for the total area
 *              
 * @return      Returns the area found by the area formula of a polygon
**/

double Polygon::area() const{
    //Initialize length, height, and area
    double length, height, area = 0;
    
    //As loop increments, add to the area
    for (int i = 1; i < vertex_count; i++){
        length = vertices[i].x - vertices[i - 1].x;
        height = (vertices[i].y + vertices[i - 1].y) / 2;
        area += length * height;
    }
    
    //Add final values connecting final point to first
    length = vertices[0].x - vertices[vertex_count - 1].x;
    height = (vertices[0].y + vertices[vertex_count - 1].y) / 2;
    area += length * height;
    
    return area;
}

/**
 * @brief       Calculates the perimeter of a polygon
 *
 * @detailed    Taking the distance of each line between each vertex, the
 *              distances are all added together to give the perimeter of
 *              the polygon
 *              
 * @return      Returns the value found by the perimeter formula for a polygon
**/

double Polygon::perimeter() const{
    //Initialize sum
    double sum = 0;
    
    //While looping, at line distance to sum
    for (int i = 1; i < vertex_count; i++){
        sum += sqrt(pow((vertices[i - 1].x - vertices[i].x), 2)
            + pow((vertices[i - 1].y - vertices[i].y), 2));
    }
    
    //Add final line distance
    sum += sqrt(pow((vertices[0].x - vertices[vertex_count - 1].x), 2)
        + pow((vertices[0].y - vertices[vertex_count - 1].y), 2));
    
    return sum;
}

/**
 * @brief       Calculates whether or not a coordinate is in a polygon
 *
 * @detailed    By tracking the distance of the line from the given coordinate,
 *              it will determine if the given point is in between the closest
 *              and farther point
 *              
 * @param       double p_x      The x value of a given point
 * 
 * @param       double p_y      The y value of a given point
 * 
 * @return      Returns true of false depending on if point is in the circle
**/

bool Polygon::contains(double p_x, double p_y) const{
    //Set closest to defaults
    double closest = sqrt(pow((p_x - vertices[0].x), 2) 
        + pow((p_y - vertices[0].y), 2));
    double farthest = sqrt(pow((p_x - vertices[0].x), 2) 
        + pow((p_y - vertices[0].y), 2));
    int closestPoint = -1;
    int farthestPoint = -1;
    //set result to false at first
    bool result = false;
    
    //While looping, if new closest or farthest, replace.
    for (int i = 0; i < vertex_count; i++){
        if (sqrt(pow((p_x - vertices[i].x), 2) + pow((p_y - vertices[i].y), 2)) 
            < closest){
            //
            closest = sqrt(pow((p_x - vertices[i].x), 2) 
                + pow((p_y - vertices[i].y), 2));
            closestPoint = i;
        }
        if (sqrt(pow((p_x - vertices[i].x), 2) + pow((p_y - vertices[i].y), 2)) 
            > farthest){
            //
            farthest = sqrt(pow((p_x - vertices[i].x), 2) 
                + pow((p_y - vertices[i].y), 2));
            farthestPoint = i;
        }
    }
    
    //If the closest point is the original, use this method
    if (closestPoint == -1 || farthestPoint == -1){
        //If the points distance is farther than the closest point and
        // farthest points distance, than the point is not in the polygon
        if (sqrt(pow((vertices[farthestPoint].x - Shape::get_ref_x()), 2) 
        + pow((vertices[farthestPoint].y - Shape::get_ref_y()), 2)) 
        > farthest)
            result = true;
    }
    //Otherwise, use this method to find if it's located
    else if (sqrt(pow((vertices[farthestPoint].x - vertices[closestPoint].x), 2) 
        + pow((vertices[farthestPoint].y - vertices[closestPoint].y), 2)) 
        > farthest)
               result = true;
               
    //return if true or false
    return result;
}

/**
 * @brief       Destructor of the class Polygon
 *
 * @detailed    Deletes array and nforms the user that the Polygon class 
 *              has closed (destructed)
**/

Polygon::~Polygon(){
        //Delete all vertices
        delete [] vertices;
        vertices = nullptr;
        cout << "Polygon::~Polygon\n";
}