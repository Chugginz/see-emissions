/**
 *******************************************************************************
 * @file    Polygon.cpp
 * @brief   All function definitions for the header file Polygon that helps
 *          provide information about a Shape data type that is a circle.
 *
 * @author  Christian Huggins
 * @date    November 17th, 2020
 *******************************************************************************
**/

#include "Polygon.h"
#include<string>
    using std::string;

Polygon::Polygon( const Point2D* vertices, int vertex_count ) 
    : Shape{vertices[0].x, vertices[0].y}{
    this->vertices = new Point2D [vertex_count];
    
    for (int i = 0; i < vertex_count; i++){
        this->vertices[i] = vertices[i];
    }
    
    this->vertex_count = vertex_count;
}

Polygon::Polygon(std::istream& fin) : Shape{fin}{
    cout << "DEBUG: Executing Polygon constructor...\n";
    int i = 0;
    Point2D* copy = new Point2D [100];
    
    while (fin.get() != ';'){
        fin >> copy[i].x;
        fin >> copy[i].y;
        i++;
    }
    vertex_count = i;
    
    vertices = new Point2D [vertex_count];
    for (int j = 0; j < vertex_count; j++){
        vertices[j] = copy[j];
    }
    
    delete [] copy;
    copy = nullptr;
}

void Polygon::write( std::ostream& strm_out ) const{
    strm_out << "\nVertex 1: (" << Shape::get_ref_x() << ", " 
        << Shape::get_ref_y() << ")";
    int j = 1;
    for (int i = 0; i < vertex_count; i++){
        strm_out << "\nVertex " << j + 1 << ": (" << vertices[i].x
        << ", " << vertices[i].y << ")";
        j++;
    }
    
}

double Polygon::area() const{
    //Prevent excessive calls of functions
    double v1_x = Shape::get_ref_x();
    double v1_y = Shape::get_ref_y();
    double length = vertices[0].x - v1_x;
    double height = vertices[0].y - v1_y;
    double area = length * height;
    
    //Way to find polygon area
    length = v1_x - vertices[vertex_count].x;
    height = v1_y - vertices[vertex_count].y;
    area += length * height;
    
    //As loop increments, add to the area
    for (int i = 1; i < vertex_count; i++){
        length = vertices[i].x - vertices[i - 1].x;
        height = vertices[i].y - vertices[i - 1].y;
        area += length * height;
    }
    
    return area;
}

double Polygon::perimeter() const{
    //Prevent to call functions multiple times
    double v1_x, v1_y;
    v1_x = Shape::get_ref_x();
    v1_y = Shape::get_ref_y();
    //Initialize sum as first line's distance
    double sum = sqrt(pow((vertices[0].x - v1_x), 2)
        + pow((vertices[0].y - v1_y), 2));
    
    //Add final line distance
    sum += sqrt(pow((vertices[vertex_count].x - v1_x), 2)
        + pow((vertices[vertex_count].y - v1_y), 2));
    
    //While looping, at line distance to sum
    for (int i = 1; i < vertex_count; i++){
        sum += sqrt(pow((vertices[i - 1].x - vertices[i].x), 2)
            + pow((vertices[i - 1].y - vertices[i].y), 2));
    }
    
    return sum;
}

bool Polygon::contains(double p_x, double p_y) const{
    //Set closest to defaults
    double closest = sqrt(pow((p_x - Shape::get_ref_x()), 2) 
        + pow((p_y - Shape::get_ref_y()), 2));
    double farthest = sqrt(pow((p_x - Shape::get_ref_x()), 2) 
        + pow((p_y - Shape::get_ref_y()), 2));
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

Polygon::~Polygon(){
        //Delete all vertices
        delete [] vertices;
        vertices = nullptr;
        cout << "Polygon::~Polygon\n";
}