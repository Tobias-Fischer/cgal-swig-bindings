#ifndef SWIG_CGAL_TRIANGULATION_3_DELAUNAY_TRIANGULATION_3_H
#define SWIG_CGAL_TRIANGULATION_3_DELAUNAY_TRIANGULATION_3_H

#include "../Kernel/Point_3.h"
#include "Triangulation_3.h"
#include <CGAL/Delaunay_triangulation_3.h>

template <class Triangulation,class Vertex_handle, class Cell_handle>
class Delaunay_triangulation_3_wrapper:public Triangulation_3_wrapper<Triangulation,Point_3,Vertex_handle,Cell_handle,CGAL::Tag_false>{
 
public:
  typedef Triangulation_3_wrapper<Triangulation,Point_3,Vertex_handle,Cell_handle,CGAL::Tag_false> Base;
  typedef typename Base::Edge Edge;
  typedef typename Base::Facet Facet;

//Creation
  Delaunay_triangulation_3_wrapper():Base(){}
  Delaunay_triangulation_3_wrapper(const Delaunay_triangulation_3_wrapper& dt):Base(static_cast<const Base&>(dt)){};
//Point moving
  FORWARD_CALL_2(Vertex_handle,move_point,Vertex_handle,Point_3);
//Removal
  FORWARD_CALL_1(void,remove,Vertex_handle)
//Queries
  FORWARD_CALL_2(Bounded_side,side_of_sphere,Cell_handle,Point_3)
  FORWARD_CALL_2(Bounded_side,side_of_circle,Facet,Point_3)
  FORWARD_CALL_3(Bounded_side,side_of_circle,Cell_handle,int,Point_3)
  FORWARD_CALL_1(Vertex_handle,nearest_vertex,Point_3)
  FORWARD_CALL_2(Vertex_handle,nearest_vertex,Point_3,Cell_handle)
  FORWARD_CALL_2(Vertex_handle,nearest_vertex_in_cell,Point_3,Cell_handle)    
  FORWARD_CALL_2(bool,is_Gabriel,Cell_handle,int)
  FORWARD_CALL_3(bool,is_Gabriel,Cell_handle,int,int)
  FORWARD_CALL_1(bool,is_Gabriel,Facet)
  FORWARD_CALL_1(bool,is_Gabriel,Edge)
};

//Creation
// template < class InputIterator > Delaunay_triangulation_3<DelaunayTriangulationTraits_3,TriangulationDataStructure_3,LocationPolicy> dt ( InputIterator first,InputIterator last,DelaunayTriangulationTraits_3 traits = DelaunayTriangulationTraits_3());
//Removal
// template < typename InputIterator > int dt.remove ( InputIterator first, InputIterator beyond)
//Queries
// template <class OutputIteratorBoundaryFacets, class OutputIteratorCells> std::pair<OutputIteratorBoundaryFacets, OutputIteratorCells> dt.find_conflicts ( Point p,Cell_handle c,OutputIteratorBoundaryFacets bfit,OutputIteratorCells cit)
// template <class OutputIteratorBoundaryFacets, class OutputIteratorCells, class OutputIteratorInternalFacets> Triple<OutputIteratorBoundaryFacets, OutputIteratorCells, OutputIteratorInternalFacets> dt.find_conflicts ( Point p,Cell_handle c,OutputIteratorBoundaryFacets bfit,OutputIteratorCells cit,OutputIteratorInternalFacets ifit)
// template <class OutputIterator> OutputIterator dt.vertices_in_conflict ( Point p, Cell_handle c, OutputIterator res)
//Voronoi diagram
// Point dt.dual ( Cell_handle c)
// Object dt.dual ( Facet f) 
// Object dt.dual ( Cell_handle c, int i) same as the previous method for facet (c,i).
// Line dt.dual_support ( Cell_handle c, int i)
// template <class Stream> Stream & dt.draw_dual ( Stream & os) Sends the set of duals to all the facets of dt into os.


#endif //SWIG_CGAL_TRIANGULATION_3_DELAUNAY_TRIANGULATION_3_H


