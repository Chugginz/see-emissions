// @ Polygon.cpp

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

Polygon::~Polygon(){
        delete [] vertices;
        vertices = nullptr;
        cout << "Polygon::~Polygon\n";
}

void Polygon::write( std::ostream& strm_out ) const{
    for (int i = 0; i < vertex_count; i++){
        strm_out << "\nVertex " << i << ": (" << vertices[i].x
        << ", " << vertices[i].y << ")";
    }
}