/* $Id$ */
/* Copyright W. Bangerth, University of Heidelberg, 1998 */


#include <grid/dof.h>
#include <grid/dof_levels.h>
#include <grid/dof_accessor.h>
#include <grid/dof_constraints.h>
#include <grid/tria_levels.h>
#include <grid/tria_accessor.h>
#include <grid/tria_iterator.h>
#include <grid/tria.h>
#include <grid/geometry_info.h>
#include <fe/fe.h>
#include <lac/sparsematrix.h>
#include <lac/vector.h>
#include <lac/vector.h>

#include <set>
#include <algorithm>




template <int dim>
DoFHandler<dim>::DoFHandler (Triangulation<dim> *tria) :
		tria(tria),
		used_dofs (0)
{
  tria->subscribe ();
};


template <int dim>
DoFHandler<dim>::~DoFHandler () {
  tria->unsubscribe ();
}






#if deal_II_dimension == 1

template <>
DoFHandler<1>::raw_cell_iterator
DoFHandler<1>::begin_raw (const unsigned int level) const {
  return begin_raw_line (level);
};



template <>
DoFHandler<1>::cell_iterator
DoFHandler<1>::begin (const unsigned int level) const {
  return begin_line (level);
};



template <>
DoFHandler<1>::active_cell_iterator
DoFHandler<1>::begin_active (const unsigned int level) const {
  return begin_active_line (level);
};



template <>
DoFHandler<1>::raw_cell_iterator
DoFHandler<1>::end () const {
  return end_line ();
};



template <>
DoFHandler<1>::raw_cell_iterator
DoFHandler<1>::last_raw () const {
  return last_raw_line ();
};



template <>
DoFHandler<1>::raw_cell_iterator
DoFHandler<1>::last_raw (const unsigned int level) const {
  return last_raw_line (level);
};



template <>
DoFHandler<1>::cell_iterator
DoFHandler<1>::last () const {
  return last_line ();
};



template <>
DoFHandler<1>::cell_iterator
DoFHandler<1>::last (const unsigned int level) const {
  return last_line (level);
};



template <>
DoFHandler<1>::active_cell_iterator
DoFHandler<1>::last_active () const {
  return last_active_line ();
};



template <>
DoFHandler<1>::active_cell_iterator
DoFHandler<1>::last_active (const unsigned int level) const {
  return last_active_line (level);
};



template <>
DoFDimensionInfo<1>::raw_face_iterator
DoFHandler<1>::begin_raw_face (const unsigned int) const {
  Assert (false, ExcFunctionNotUseful());
  return 0;
};



template <>
DoFDimensionInfo<1>::face_iterator
DoFHandler<1>::begin_face (const unsigned int) const {
  Assert (false, ExcFunctionNotUseful());
  return 0;
};



template <>
DoFDimensionInfo<1>::active_face_iterator
DoFHandler<1>::begin_active_face (const unsigned int) const {
  Assert (false, ExcFunctionNotUseful());
  return 0;
};



template <>
DoFDimensionInfo<1>::raw_face_iterator
DoFHandler<1>::end_face () const {
  Assert (false, ExcFunctionNotUseful());
  return 0;
};



template <>
DoFDimensionInfo<1>::raw_face_iterator
DoFHandler<1>::last_raw_face () const {
  Assert (false, ExcFunctionNotUseful());
  return 0;
};



template <>
DoFDimensionInfo<1>::raw_face_iterator
DoFHandler<1>::last_raw_face (const unsigned int) const {
  Assert (false, ExcFunctionNotUseful());
  return 0;
};



template <>
DoFDimensionInfo<1>::face_iterator
DoFHandler<1>::last_face () const {
  Assert (false, ExcFunctionNotUseful());
  return 0;
};



template <>
DoFDimensionInfo<1>::face_iterator
DoFHandler<1>::last_face (const unsigned int) const {
  Assert (false, ExcFunctionNotUseful());
  return 0;
};



template <>
DoFDimensionInfo<1>::active_face_iterator
DoFHandler<1>::last_active_face () const {
  Assert (false, ExcFunctionNotUseful());
  return 0;
};



template <>
DoFDimensionInfo<1>::active_face_iterator
DoFHandler<1>::last_active_face (const unsigned int) const {
  Assert (false, ExcFunctionNotUseful());
  return 0;
};




template <>
DoFHandler<1>::raw_quad_iterator
DoFHandler<1>::begin_raw_quad (const unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::quad_iterator
DoFHandler<1>::begin_quad (const unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::active_quad_iterator
DoFHandler<1>::begin_active_quad (const unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::raw_quad_iterator
DoFHandler<1>::end_quad () const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::raw_quad_iterator
DoFHandler<1>::last_raw_quad (const unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};


template <>
DoFHandler<1>::quad_iterator
DoFHandler<1>::last_quad (const unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::active_quad_iterator
DoFHandler<1>::last_active_quad (const unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::raw_quad_iterator
DoFHandler<1>::last_raw_quad () const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::quad_iterator
DoFHandler<1>::last_quad () const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::active_quad_iterator
DoFHandler<1>::last_active_quad () const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::raw_hex_iterator
DoFHandler<1>::begin_raw_hex (unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::hex_iterator
DoFHandler<1>::begin_hex (unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::active_hex_iterator
DoFHandler<1>::begin_active_hex (unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::raw_hex_iterator
DoFHandler<1>::end_hex () const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::raw_hex_iterator
DoFHandler<1>::last_raw_hex (const unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::raw_hex_iterator
DoFHandler<1>::last_raw_hex () const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::hex_iterator
DoFHandler<1>::last_hex (const unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::hex_iterator
DoFHandler<1>::last_hex () const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::active_hex_iterator
DoFHandler<1>::last_active_hex (const unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<1>::active_hex_iterator
DoFHandler<1>::last_active_hex () const {
  Assert (false, ExcNotImplemented());
  return 0;
};

#endif


#if deal_II_dimension == 2

template <>
DoFHandler<2>::raw_cell_iterator
DoFHandler<2>::begin_raw (const unsigned int level) const {
  return begin_raw_quad (level);
};



template <>
DoFHandler<2>::cell_iterator
DoFHandler<2>::begin (const unsigned int level) const {
  return begin_quad (level);
};



template <>
DoFHandler<2>::active_cell_iterator
DoFHandler<2>::begin_active (const unsigned int level) const {
  return begin_active_quad (level);
};



template <>
DoFHandler<2>::raw_cell_iterator
DoFHandler<2>::end () const {
  return end_quad ();
};



template <>
DoFHandler<2>::raw_cell_iterator
DoFHandler<2>::last_raw () const {
  return last_raw_quad ();
};



template <>
DoFHandler<2>::raw_cell_iterator
DoFHandler<2>::last_raw (const unsigned int level) const {
  return last_raw_quad (level);
};



template <>
DoFHandler<2>::cell_iterator
DoFHandler<2>::last () const {
  return last_quad ();
};



template <>
DoFHandler<2>::cell_iterator
DoFHandler<2>::last (const unsigned int level) const {
  return last_quad (level);
};



template <>
DoFHandler<2>::active_cell_iterator
DoFHandler<2>::last_active () const {
  return last_active_quad ();
};



template <>
DoFHandler<2>::active_cell_iterator
DoFHandler<2>::last_active (const unsigned int level) const {
  return last_active_quad (level);
};


template <>
DoFDimensionInfo<2>::raw_face_iterator
DoFHandler<2>::begin_raw_face (const unsigned int level) const {
  return begin_raw_line (level);
};



template <>
DoFDimensionInfo<2>::face_iterator
DoFHandler<2>::begin_face (const unsigned int level) const {
  return begin_line (level);
};



template <>
DoFDimensionInfo<2>::active_face_iterator
DoFHandler<2>::begin_active_face (const unsigned int level) const {
  return begin_active_line (level);
};



template <>
DoFDimensionInfo<2>::raw_face_iterator
DoFHandler<2>::end_face () const {
  return end_line ();
};



template <>
DoFDimensionInfo<2>::raw_face_iterator
DoFHandler<2>::last_raw_face () const {
  return last_raw_line ();
};



template <>
DoFDimensionInfo<2>::raw_face_iterator
DoFHandler<2>::last_raw_face (const unsigned int level) const {
  return last_raw_line (level);
};



template <>
DoFDimensionInfo<2>::face_iterator
DoFHandler<2>::last_face () const {
  return last_line ();
};



template <>
DoFDimensionInfo<2>::face_iterator
DoFHandler<2>::last_face (const unsigned int level) const {
  return last_line (level);
};



template <>
DoFDimensionInfo<2>::active_face_iterator
DoFHandler<2>::last_active_face () const {
  return last_active_line ();
};



template <>
DoFDimensionInfo<2>::active_face_iterator
DoFHandler<2>::last_active_face (const unsigned int level) const {
  return last_active_line (level);
};



template <>
DoFHandler<2>::raw_hex_iterator
DoFHandler<2>::begin_raw_hex (unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<2>::hex_iterator
DoFHandler<2>::begin_hex (unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<2>::active_hex_iterator
DoFHandler<2>::begin_active_hex (unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<2>::raw_hex_iterator
DoFHandler<2>::end_hex () const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<2>::raw_hex_iterator
DoFHandler<2>::last_raw_hex (const unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<2>::raw_hex_iterator
DoFHandler<2>::last_raw_hex () const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<2>::hex_iterator
DoFHandler<2>::last_hex (const unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<2>::hex_iterator
DoFHandler<2>::last_hex () const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<2>::active_hex_iterator
DoFHandler<2>::last_active_hex (const unsigned int) const {
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
DoFHandler<2>::active_hex_iterator
DoFHandler<2>::last_active_hex () const {
  Assert (false, ExcNotImplemented());
  return 0;
};


#endif





#if deal_II_dimension == 3

template <>
DoFHandler<3>::raw_cell_iterator
DoFHandler<3>::begin_raw (const unsigned int level) const {
  return begin_raw_hex (level);
};



template <>
DoFHandler<3>::cell_iterator
DoFHandler<3>::begin (const unsigned int level) const {
  return begin_hex (level);
};



template <>
DoFHandler<3>::active_cell_iterator
DoFHandler<3>::begin_active (const unsigned int level) const {
  return begin_active_hex (level);
};



template <>
DoFHandler<3>::raw_cell_iterator
DoFHandler<3>::end () const {
  return end_hex ();
};



template <>
DoFHandler<3>::raw_cell_iterator
DoFHandler<3>::last_raw () const {
  return last_raw_hex ();
};



template <>
DoFHandler<3>::raw_cell_iterator
DoFHandler<3>::last_raw (const unsigned int level) const {
  return last_raw_hex (level);
};



template <>
DoFHandler<3>::cell_iterator
DoFHandler<3>::last () const {
  return last_hex ();
};



template <>
DoFHandler<3>::cell_iterator
DoFHandler<3>::last (const unsigned int level) const {
  return last_hex (level);
};



template <>
DoFHandler<3>::active_cell_iterator
DoFHandler<3>::last_active () const {
  return last_active_hex ();
};



template <>
DoFHandler<3>::active_cell_iterator
DoFHandler<3>::last_active (const unsigned int level) const {
  return last_active_hex (level);
};







template <>
DoFHandler<3>::raw_face_iterator
DoFHandler<3>::begin_raw_face (const unsigned int level) const {
  return begin_raw_quad (level);
};



template <>
DoFHandler<3>::face_iterator
DoFHandler<3>::begin_face (const unsigned int level) const {
  return begin_quad (level);
};



template <>
DoFHandler<3>::active_face_iterator
DoFHandler<3>::begin_active_face (const unsigned int level) const {
  return begin_active_quad (level);
};



template <>
DoFHandler<3>::raw_face_iterator
DoFHandler<3>::end_face () const {
  return end_quad ();
};



template <>
DoFHandler<3>::raw_face_iterator
DoFHandler<3>::last_raw_face () const {
  return last_raw_quad ();
};



template <>
DoFHandler<3>::raw_face_iterator
DoFHandler<3>::last_raw_face (const unsigned int level) const {
  return last_raw_quad (level);
};



template <>
DoFHandler<3>::face_iterator
DoFHandler<3>::last_face () const {
  return last_quad ();
};



template <>
DoFHandler<3>::face_iterator
DoFHandler<3>::last_face (const unsigned int level) const {
  return last_quad (level);
};



template <>
DoFHandler<3>::active_face_iterator
DoFHandler<3>::last_active_face () const {
  return last_active_quad ();
};



template <>
DoFHandler<3>::active_face_iterator
DoFHandler<3>::last_active_face (const unsigned int level) const {
  return last_active_quad (level);
};


#endif



template <int dim>
typename DoFHandler<dim>::raw_line_iterator
DoFHandler<dim>::begin_raw_line (const unsigned int level) const {
  return raw_line_iterator (tria,
			    tria->begin_raw_line(level)->level(),
			    tria->begin_raw_line(level)->index(),
			    this);
};



template <int dim>
typename DoFHandler<dim>::line_iterator
DoFHandler<dim>::begin_line (const unsigned int level) const {
  return line_iterator (tria,
			tria->begin_line(level)->level(),
			tria->begin_line(level)->index(),
			this);
};



template <int dim>
typename DoFHandler<dim>::active_line_iterator
DoFHandler<dim>::begin_active_line (const unsigned int level) const {
  return active_line_iterator (tria,
			       tria->begin_active_line(level)->level(),
			       tria->begin_active_line(level)->index(),
			       this);
};



template <int dim>
typename DoFHandler<dim>::raw_quad_iterator
DoFHandler<dim>::begin_raw_quad (const unsigned int level) const {
  return raw_quad_iterator (tria,
			    tria->begin_raw_quad(level)->level(),
			    tria->begin_raw_quad(level)->index(),
			    this);
};



template <int dim>
typename DoFHandler<dim>::quad_iterator
DoFHandler<dim>::begin_quad (const unsigned int level) const {
  return quad_iterator (tria,
			tria->begin_quad(level)->level(),
			tria->begin_quad(level)->index(),
			this);
};



template <int dim>
typename DoFHandler<dim>::active_quad_iterator
DoFHandler<dim>::begin_active_quad (const unsigned int level) const {
  return active_quad_iterator (tria,
			       tria->begin_active_quad(level)->level(),
			       tria->begin_active_quad(level)->index(),
			       this);
};




template <int dim>
typename DoFHandler<dim>::raw_hex_iterator
DoFHandler<dim>::begin_raw_hex (const unsigned int level) const {
  return raw_hex_iterator (tria,
			   tria->begin_raw_hex(level)->level(),
			   tria->begin_raw_hex(level)->index(),
			   this);
};



template <int dim>
typename DoFHandler<dim>::hex_iterator
DoFHandler<dim>::begin_hex (const unsigned int level) const {
  return hex_iterator (tria,
		       tria->begin_hex(level)->level(),
		       tria->begin_hex(level)->index(),
		       this);
};



template <int dim>
typename DoFHandler<dim>::active_hex_iterator
DoFHandler<dim>::begin_active_hex (const unsigned int level) const {
  return active_hex_iterator (tria,
			      tria->begin_active_hex(level)->level(),
			      tria->begin_active_hex(level)->index(),
			      this);
};



template <int dim>
typename DoFHandler<dim>::raw_line_iterator
DoFHandler<dim>::end_line () const {
  return raw_line_iterator (tria, -1, -1, this);
};



template <int dim>
typename DoFHandler<dim>::raw_quad_iterator
DoFHandler<dim>::end_quad () const {
  return raw_quad_iterator (tria, -1, -1, this);
};



template <int dim>
typename DoFHandler<dim>::raw_hex_iterator
DoFHandler<dim>::end_hex () const {
  return raw_hex_iterator (tria, -1, -1, this);
};



template <int dim>
typename DoFDimensionInfo<dim>::raw_cell_iterator
DoFHandler<dim>::end_raw (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  end() :
	  begin_raw (level+1));
};



template <int dim>
typename DoFDimensionInfo<dim>::cell_iterator
DoFHandler<dim>::end (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  cell_iterator(end()) :
	  begin (level+1));
};



template <int dim>
typename DoFDimensionInfo<dim>::active_cell_iterator
DoFHandler<dim>::end_active (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  active_cell_iterator(end()) :
	  begin_active (level+1));
};



template <int dim>
typename DoFDimensionInfo<dim>::raw_face_iterator
DoFHandler<dim>::end_raw_face (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  end_face() :
	  begin_raw_face (level+1));
};



template <int dim>
typename DoFDimensionInfo<dim>::face_iterator
DoFHandler<dim>::end_face (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  face_iterator(end_face()) :
	  begin_face (level+1));
};



template <int dim>
typename DoFDimensionInfo<dim>::active_face_iterator
DoFHandler<dim>::end_active_face (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  active_face_iterator(end_face()) :
	  begin_active_face (level+1));
};



template <int dim>
typename DoFDimensionInfo<dim>::raw_line_iterator
DoFHandler<dim>::end_raw_line (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  end_line() :
	  begin_raw_line (level+1));
};



template <int dim>
typename DoFDimensionInfo<dim>::line_iterator
DoFHandler<dim>::end_line (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  line_iterator(end_line()) :
	  begin_line (level+1));
};



template <int dim>
typename DoFDimensionInfo<dim>::active_line_iterator
DoFHandler<dim>::end_active_line (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  active_line_iterator(end_line()) :
	  begin_active_line (level+1));
};




template <int dim>
typename DoFDimensionInfo<dim>::raw_quad_iterator
DoFHandler<dim>::end_raw_quad (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  end_quad() :
	  begin_raw_quad (level+1));
};



template <int dim>
typename DoFDimensionInfo<dim>::quad_iterator
DoFHandler<dim>::end_quad (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  quad_iterator(end_quad()) :
	  begin_quad (level+1));
};



template <int dim>
typename DoFDimensionInfo<dim>::active_quad_iterator
DoFHandler<dim>::end_active_quad (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  active_quad_iterator(end_quad()) :
	  begin_active_quad (level+1));
};



template <int dim>
typename DoFDimensionInfo<dim>::raw_hex_iterator
DoFHandler<dim>::end_raw_hex (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  end_hex() :
	  begin_raw_hex (level+1));
};



template <int dim>
typename DoFDimensionInfo<dim>::hex_iterator
DoFHandler<dim>::end_hex (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  hex_iterator(end_hex()) :
	  begin_hex (level+1));
};



template <int dim>
typename DoFDimensionInfo<dim>::active_hex_iterator
DoFHandler<dim>::end_active_hex (const unsigned int level) const {
  return (level == levels.size()-1 ?
	  active_hex_iterator(end_hex()) :
	  begin_active_hex (level+1));
};



template <int dim>
typename DoFHandler<dim>::raw_line_iterator
DoFHandler<dim>::last_raw_line (const unsigned int level) const {
  return raw_line_iterator (tria,
			    tria->last_raw_line(level)->level(),
			    tria->last_raw_line(level)->index(),
			    this);
};



template <int dim>
typename DoFHandler<dim>::line_iterator
DoFHandler<dim>::last_line (const unsigned int level) const {
  return line_iterator (tria,
			tria->last_line(level)->level(),
			tria->last_line(level)->index(),
			this);
};



template <int dim>
typename DoFHandler<dim>::active_line_iterator
DoFHandler<dim>::last_active_line (const unsigned int level) const {
  return active_line_iterator (tria,
			       tria->last_active_line(level)->level(),
			       tria->last_active_line(level)->index(),
			       this);
};



template <int dim>
typename DoFHandler<dim>::raw_quad_iterator
DoFHandler<dim>::last_raw_quad (const unsigned int level) const {
  return raw_quad_iterator (tria,
			    tria->last_raw_quad(level)->level(),
			    tria->last_raw_quad(level)->index(),
			    this);
};




template <int dim>
typename DoFHandler<dim>::quad_iterator
DoFHandler<dim>::last_quad (const unsigned int level) const {
  return quad_iterator (tria,
			tria->last_quad(level)->level(),
			tria->last_quad(level)->index(),
			this);
};




template <int dim>
typename DoFHandler<dim>::active_quad_iterator
DoFHandler<dim>::last_active_quad (const unsigned int level) const {
  return active_quad_iterator (tria,
			       tria->last_active_quad(level)->level(),
			       tria->last_active_quad(level)->index(),
			       this);
};



template <int dim>
typename DoFHandler<dim>::raw_hex_iterator
DoFHandler<dim>::last_raw_hex (const unsigned int level) const {
  return raw_hex_iterator (tria,
			   tria->last_raw_hex(level)->level(),
			   tria->last_raw_hex(level)->index(),
			   this);
};




template <int dim>
typename DoFHandler<dim>::hex_iterator
DoFHandler<dim>::last_hex (const unsigned int level) const {
  return hex_iterator (tria,
		       tria->last_hex(level)->level(),
		       tria->last_hex(level)->index(),
		       this);
};




template <int dim>
typename DoFHandler<dim>::active_hex_iterator
DoFHandler<dim>::last_active_hex (const unsigned int level) const {
  return active_hex_iterator (tria,
			      tria->last_active_hex(level)->level(),
			      tria->last_active_hex(level)->index(),
			      this);
};



template <int dim>
typename DoFHandler<dim>::raw_line_iterator
DoFHandler<dim>::last_raw_line () const {
  return last_raw_line (levels.size()-1);
};



template <int dim>
typename DoFHandler<dim>::raw_quad_iterator
DoFHandler<dim>::last_raw_quad () const {
  return last_raw_quad (levels.size()-1);
};



template <int dim>
typename DoFHandler<dim>::raw_hex_iterator
DoFHandler<dim>::last_raw_hex () const {
  return last_raw_hex (levels.size()-1);
};



template <int dim>
typename DoFHandler<dim>::line_iterator
DoFHandler<dim>::last_line () const {
  return last_line (levels.size()-1);
};



template <int dim>
typename DoFHandler<dim>::quad_iterator
DoFHandler<dim>::last_quad () const {
  return last_quad (levels.size()-1);
};



template <int dim>
typename DoFHandler<dim>::hex_iterator
DoFHandler<dim>::last_hex () const {
  return last_hex (levels.size()-1);
};



template <int dim>
typename DoFHandler<dim>::active_line_iterator
DoFHandler<dim>::last_active_line () const {
  return last_active_line (levels.size()-1);
};



template <int dim>
typename DoFHandler<dim>::active_quad_iterator
DoFHandler<dim>::last_active_quad () const {
  return last_active_quad (levels.size()-1);
};



template <int dim>
typename DoFHandler<dim>::active_hex_iterator
DoFHandler<dim>::last_active_hex () const {
  return last_active_hex (levels.size()-1);
};






//------------------------------------------------------------------







template <int dim>
unsigned int DoFHandler<dim>::n_dofs () const {
  return used_dofs;
};



#if deal_II_dimension == 1

template <>
unsigned int DoFHandler<1>::n_boundary_dofs () const {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
unsigned int DoFHandler<1>::n_boundary_dofs (const FunctionMap &) const {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (false, ExcNotImplemented());
  return 0;
};

#endif





template <int dim>
unsigned int DoFHandler<dim>::n_boundary_dofs () const {
  Assert (selected_fe != 0, ExcNoFESelected());
  
  set<int> boundary_dofs;

  const unsigned int dofs_per_face = selected_fe->dofs_per_face;
  vector<int> dofs_on_face(dofs_per_face);
  active_face_iterator face = begin_active_face (),
		       endf = end_face();
  for (; face!=endf; ++face)
    if (face->at_boundary())
      {
	face->get_dof_indices (dofs_on_face);
	for (unsigned int i=0; i<dofs_per_face; ++i)
	  boundary_dofs.insert(dofs_on_face[i]);
      };
  return boundary_dofs.size();
};    



template <int dim>
unsigned int DoFHandler<dim>::n_boundary_dofs (const FunctionMap &boundary_indicators) const {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (boundary_indicators.find(255) == boundary_indicators.end(),
	  ExcInvalidBoundaryIndicator());
  
  set<int> boundary_dofs;

  const unsigned int dofs_per_face = selected_fe->dofs_per_face;
  vector<int> dofs_on_face(dofs_per_face);
  active_face_iterator face = begin_active_face (),
		       endf = end_face();
  for (; face!=endf; ++face)
    if (boundary_indicators.find(face->boundary_indicator()) !=
	boundary_indicators.end())
      {
	face->get_dof_indices (dofs_on_face);
	for (unsigned int i=0; i<dofs_per_face; ++i)
	  boundary_dofs.insert(dofs_on_face[i]);
      };
  return boundary_dofs.size();
};    



template <int dim>
const Triangulation<dim> & DoFHandler<dim>::get_tria () const {
  return *tria;
};



template <int dim>
void DoFHandler<dim>::distribute_dofs (const FiniteElement<dim> &ff,
				       unsigned int offset)
{
  Assert (tria->n_levels() > 0, ExcInvalidTriangulation());
  
  selected_fe = &ff;
  
  reserve_space ();

				   // clear user flags because we will
				   // need them
  tria->clear_user_flags ();
  
  unsigned int next_free_dof = offset;   
  active_cell_iterator cell = begin_active(),
		       endc = end();

  for (; cell != endc; ++cell) 
    next_free_dof = distribute_dofs_on_cell (cell, next_free_dof);
  
  used_dofs = next_free_dof;
};



template <int dim>
void DoFHandler<dim>::clear () {
				   // release lock to old fe
  selected_fe = 0;

				   // release memory
  clear_space ();
};




#if deal_II_dimension == 1

template <>
unsigned int DoFHandler<1>::distribute_dofs_on_cell (active_cell_iterator &cell,
						     unsigned int          next_free_dof) {

				   // distribute dofs of vertices
  for (unsigned int v=0; v<GeometryInfo<1>::vertices_per_cell; ++v)
    {
      cell_iterator neighbor = cell->neighbor(v);

      if (neighbor.state() == valid)
	{
					 // find true neighbor; may be its
					 // a child of #neighbor#
	  while (neighbor->has_children())
	    neighbor = neighbor->child(v==0 ? 1 : 0);

					   // has neighbor already been processed?
	  if (neighbor->user_flag_set())
					   // copy dofs
	    {
	      if (v==0) 
		for (unsigned int d=0; d<selected_fe->dofs_per_vertex; ++d)
		  cell->set_vertex_dof_index (0, d,
					      neighbor->vertex_dof_index (1, d));
	      else
		for (unsigned int d=0; d<selected_fe->dofs_per_vertex; ++d)
		  cell->set_vertex_dof_index (1, d,
					      neighbor->vertex_dof_index (0, d));

					       // next neighbor
	      continue;
	    };
	};
            
				       // otherwise: create dofs newly
      for (unsigned int d=0; d<selected_fe->dofs_per_vertex; ++d)
	cell->set_vertex_dof_index (v, d, next_free_dof++);
    };
  
				   // dofs of line
  for (unsigned int d=0; d<selected_fe->dofs_per_line; ++d)
    cell->set_dof_index (d, next_free_dof++);

				   // note that this cell has been processed
  cell->set_user_flag ();
  
  return next_free_dof;
};

#endif


#if deal_II_dimension == 2

template <>
unsigned int DoFHandler<2>::distribute_dofs_on_cell (active_cell_iterator &cell,
						     unsigned int          next_free_dof) {
  if (selected_fe->dofs_per_vertex > 0)
				     // number dofs on vertices
    for (unsigned int vertex=0; vertex<GeometryInfo<2>::vertices_per_cell; ++vertex)
				       // check whether dofs for this
				       // vertex have been distributed
				       // (only check the first dof)
      if (cell->vertex_dof_index(vertex, 0) == -1)
	for (unsigned int d=0; d<selected_fe->dofs_per_vertex; ++d)
	  cell->set_vertex_dof_index (vertex, d, next_free_dof++);
    
  				   // for the four sides
  if (selected_fe->dofs_per_line > 0)
    for (unsigned int side=0; side<GeometryInfo<2>::faces_per_cell; ++side)
      {
	line_iterator line = cell->line(side);
	
					 // distribute dofs if necessary:
					 // check whether line dof is already
					 // numbered (check only first dof)
	if (line->dof_index(0) == -1)
					   // if not: distribute dofs
	  for (unsigned int d=0; d<selected_fe->dofs_per_line; ++d)
	    line->set_dof_index (d, next_free_dof++);	    
      };
  

      				       // dofs of quad
  if (selected_fe->dofs_per_quad > 0)
    for (unsigned int d=0; d<selected_fe->dofs_per_quad; ++d)
      cell->set_dof_index (d, next_free_dof++);

  
				   // note that this cell has been processed
  cell->set_user_flag ();
  
  return next_free_dof;
};

#endif



#if deal_II_dimension == 3

template <>
unsigned int DoFHandler<3>::distribute_dofs_on_cell (active_cell_iterator &cell,
						     unsigned int          next_free_dof) {
  if (selected_fe->dofs_per_vertex > 0)
				     // number dofs on vertices
    for (unsigned int vertex=0; vertex<GeometryInfo<3>::vertices_per_cell; ++vertex)
				       // check whether dofs for this
				       // vertex have been distributed
				       // (only check the first dof)
      if (cell->vertex_dof_index(vertex, 0) == -1)
	for (unsigned int d=0; d<selected_fe->dofs_per_vertex; ++d)
	  cell->set_vertex_dof_index (vertex, d, next_free_dof++);
    
  				   // for the lines
  if (selected_fe->dofs_per_line > 0)
    for (unsigned int l=0; l<GeometryInfo<3>::lines_per_cell; ++l)
      {
	line_iterator line = cell->line(l);
	
					 // distribute dofs if necessary:
					 // check whether line dof is already
					 // numbered (check only first dof)
	if (line->dof_index(0) == -1)
					   // if not: distribute dofs
	  for (unsigned int d=0; d<selected_fe->dofs_per_line; ++d)
	    line->set_dof_index (d, next_free_dof++);	    
      };

    				   // for the quads
  if (selected_fe->dofs_per_quad > 0)
    for (unsigned int q=0; q<GeometryInfo<3>::quads_per_cell; ++q)
      {
	quad_iterator quad = cell->quad(q);
	
					 // distribute dofs if necessary:
					 // check whether quad dof is already
					 // numbered (check only first dof)
	if (quad->dof_index(0) == -1)
					   // if not: distribute dofs
	  for (unsigned int d=0; d<selected_fe->dofs_per_quad; ++d)
	    quad->set_dof_index (d, next_free_dof++);	    
      };


      				       // dofs of hex
  if (selected_fe->dofs_per_hex > 0)
    for (unsigned int d=0; d<selected_fe->dofs_per_hex; ++d)
      cell->set_dof_index (d, next_free_dof++);

  
				   // note that this cell has been processed
  cell->set_user_flag ();
  
  return next_free_dof;
};

#endif



#if deal_II_dimension == 1

template <>
void DoFHandler<1>::renumber_dofs (const vector<int> &new_numbers) {
  Assert (new_numbers.size() == n_dofs(), ExcRenumberingIncomplete());
#ifdef DEBUG
				   // assert that the new indices are
				   // consecutively numbered
  if (true)
    {
      vector<int> tmp(new_numbers);
      sort (tmp.begin(), tmp.end());
      vector<int>::const_iterator p = tmp.begin();
      int                         i = 0;
      for (; p!=tmp.end(); ++p, ++i)
	Assert (*p == i, ExcNewNumbersNotConsecutive(i));
    };
#endif

				   // note that we can not use cell iterators
				   // in this function since then we would
				   // renumber the dofs on the interface of
				   // two cells more than once. Anyway, this
				   // way it's not only more correct but also
				   // faster; note, however, that dof numbers
				   // may be -1, namely when the appropriate
				   // vertex/line/etc is unused
  for (vector<int>::iterator i=vertex_dofs.begin(); i!=vertex_dofs.end(); ++i)
    if (*i != -1)
      *i = new_numbers[*i];
    else
				       // if index is -1: check if this one
				       // really is unused
      Assert (tria->vertices_used[(i-vertex_dofs.begin()) /
				 selected_fe->dofs_per_vertex] == false,
	      ExcInternalError ());
  
  for (unsigned int level=0; level<levels.size(); ++level) 
    for (vector<int>::iterator i=levels[level]->line_dofs.begin();
	 i!=levels[level]->line_dofs.end(); ++i)
      if (*i != -1)
	*i = new_numbers[*i];
};

#endif


#if deal_II_dimension == 2

template <>
void DoFHandler<2>::renumber_dofs (const vector<int> &new_numbers) {
  Assert (new_numbers.size() == n_dofs(), ExcRenumberingIncomplete());
#ifdef DEBUG
				   // assert that the new indices are
				   // consecutively numbered
  if (true)
    {
      vector<int> tmp(new_numbers);
      sort (tmp.begin(), tmp.end());
      vector<int>::const_iterator p = tmp.begin();
      int                         i = 0;
      for (; p!=tmp.end(); ++p, ++i)
	Assert (*p == i, ExcNewNumbersNotConsecutive(i));
    };
#endif

				   // note that we can not use cell iterators
				   // in this function since then we would
				   // renumber the dofs on the interface of
				   // two cells more than once. Anyway, this
				   // way it's not only more correct but also
				   // faster; note, however, that dof numbers
				   // may be -1, namely when the appropriate
				   // vertex/line/etc is unused
  for (vector<int>::iterator i=vertex_dofs.begin(); i!=vertex_dofs.end(); ++i)
    if (*i != -1)
      *i = new_numbers[*i];
    else
				       // if index is -1: check if this one
				       // really is unused
      Assert (tria->vertices_used[(i-vertex_dofs.begin()) /
				 selected_fe->dofs_per_vertex] == false,
	      ExcInternalError ());
  
  for (unsigned int level=0; level<levels.size(); ++level) 
    {
      for (vector<int>::iterator i=levels[level]->line_dofs.begin();
	   i!=levels[level]->line_dofs.end(); ++i)
	if (*i != -1)
	  *i = new_numbers[*i];
      for (vector<int>::iterator i=levels[level]->quad_dofs.begin();
	   i!=levels[level]->quad_dofs.end(); ++i)
	if (*i != -1)
	  *i = new_numbers[*i];
    };
};

#endif


#if deal_II_dimension == 3

template <>
void DoFHandler<3>::renumber_dofs (const vector<int> &new_numbers) {
  Assert (new_numbers.size() == n_dofs(), ExcRenumberingIncomplete());
#ifdef DEBUG
				   // assert that the new indices are
				   // consecutively numbered
  if (true)
    {
      vector<int> tmp(new_numbers);
      sort (tmp.begin(), tmp.end());
      vector<int>::const_iterator p = tmp.begin();
      int                         i = 0;
      for (; p!=tmp.end(); ++p, ++i)
	Assert (*p == i, ExcNewNumbersNotConsecutive(i));
    };
#endif

				   // note that we can not use cell iterators
				   // in this function since then we would
				   // renumber the dofs on the interface of
				   // two cells more than once. Anyway, this
				   // way it's not only more correct but also
				   // faster; note, however, that dof numbers
				   // may be -1, namely when the appropriate
				   // vertex/line/etc is unused
  for (vector<int>::iterator i=vertex_dofs.begin(); i!=vertex_dofs.end(); ++i)
    if (*i != -1)
      *i = new_numbers[*i];
    else
				       // if index is -1: check if this one
				       // really is unused
      Assert (tria->vertices_used[(i-vertex_dofs.begin()) /
				 selected_fe->dofs_per_vertex] == false,
	      ExcInternalError ());
  
  for (unsigned int level=0; level<levels.size(); ++level) 
    {
      for (vector<int>::iterator i=levels[level]->line_dofs.begin();
	   i!=levels[level]->line_dofs.end(); ++i)
	if (*i != -1)
	  *i = new_numbers[*i];
      for (vector<int>::iterator i=levels[level]->quad_dofs.begin();
	   i!=levels[level]->quad_dofs.end(); ++i)
	if (*i != -1)
	  *i = new_numbers[*i];
      for (vector<int>::iterator i=levels[level]->hex_dofs.begin();
	   i!=levels[level]->hex_dofs.end(); ++i)
	if (*i != -1)
	  *i = new_numbers[*i];
    };
};

#endif



#if deal_II_dimension == 1

template <>
void DoFHandler<1>::make_hanging_node_constraints (ConstraintMatrix &) const {};

#endif



#if deal_II_dimension == 2

template <>
void DoFHandler<2>::make_hanging_node_constraints (ConstraintMatrix &constraints) const {
  const unsigned int dim = 2;
  
				   // first mark all faces which are subject
				   // to constraints. We do so by looping
				   // over all active cells and checking
				   // whether any of the faces are refined
				   // which can only be from the neighboring
				   // cell because this one is active. In that
				   // case, the face is subject to constraints
  tria->clear_user_flags ();
  Triangulation<dim>::active_cell_iterator cell = tria->begin_active(),
					   endc = tria->end();
  for (; cell!=endc; ++cell)
    for (unsigned int face=0; face<GeometryInfo<dim>::faces_per_cell; ++face)
      if (cell->face(face)->has_children()) 
	cell->face(face)->set_user_flag();
	  
  

  
  line_iterator line = begin_line(),
		endl = end_line();
				   // loop over all lines; only on lines
				   // there can be constraints.
  for (; line != endl; ++line)
				     // if dofs on this line are subject
				     // to constraints
    if (line->user_flag_set() == true)
      {
					 // reserve space to gather
					 // the dof numbers. We could
					 // get them when we need them,
					 // but it seems easier to gather
					 // them only once.
	vector<int> dofs_on_mother;
	vector<int> dofs_on_children;
	dofs_on_mother.reserve (2*selected_fe->dofs_per_vertex+
				selected_fe->dofs_per_line);
	dofs_on_children.reserve (selected_fe->dofs_per_vertex+
				  2*selected_fe->dofs_per_line);

	Assert(2*selected_fe->dofs_per_vertex+selected_fe->dofs_per_line ==
	       selected_fe->constraints().n(),
	       ExcDifferentDimensions(2*selected_fe->dofs_per_vertex+
				      selected_fe->dofs_per_line,
				      selected_fe->constraints().n()));
	Assert(selected_fe->dofs_per_vertex+2*selected_fe->dofs_per_line ==
	       selected_fe->constraints().m(),
	       ExcDifferentDimensions(3*selected_fe->dofs_per_vertex+
				      2*selected_fe->dofs_per_line,
				      selected_fe->constraints().m()));
	
					 // fill the dofs indices. Use same
					 // enumeration scheme as in
					 // #FiniteElement::constraints()#
	for (unsigned int vertex=0; vertex<2; ++vertex)
	  for (unsigned int dof=0; dof!=selected_fe->dofs_per_vertex; ++dof)
	    dofs_on_mother.push_back (line->vertex_dof_index(vertex,dof));
	for (unsigned int dof=0; dof!=selected_fe->dofs_per_line; ++dof)
	  dofs_on_mother.push_back (line->dof_index(dof));

	for (unsigned int dof=0; dof!=selected_fe->dofs_per_vertex; ++dof)
	  dofs_on_children.push_back (line->child(0)->vertex_dof_index(1,dof));
	for (unsigned int child=0; child<2; ++child)
	  for (unsigned int dof=0; dof!=selected_fe->dofs_per_line; ++dof)
	    dofs_on_children.push_back (line->child(child)->dof_index(dof));

					 // for each row in the constraint
					 // matrix for this line:
	for (unsigned int row=0; row!=dofs_on_children.size(); ++row) 
	  {
	    constraints.add_line (dofs_on_children[row]);
	    for (unsigned int i=0; i!=dofs_on_mother.size(); ++i)
	      constraints.add_entry (dofs_on_children[row],
				     dofs_on_mother[i],
				     selected_fe->constraints()(row,i));
	  };
      };
};

#endif



#if deal_II_dimension == 3

template <>
void DoFHandler<3>::make_hanging_node_constraints (ConstraintMatrix &constraints) const {
  const unsigned int dim = 3;
  
				   // first mark all faces which are subject
				   // to constraints. We do so by looping
				   // over all active cells and checking
				   // whether any of the faces are refined
				   // which can only be from the neighboring
				   // cell because this one is active. In that
				   // case, the face is subject to constraints
  tria->clear_user_flags ();
  Triangulation<dim>::active_cell_iterator cell = tria->begin_active(),
					   endc = tria->end();
  for (; cell!=endc; ++cell)
    for (unsigned int face=0; face<GeometryInfo<dim>::faces_per_cell; ++face)
      if (cell->face(face)->has_children()) 
	cell->face(face)->set_user_flag();
	  
  

  
  face_iterator face = begin_face(),
		endf = end_face();
				   // loop over all faces; only on faces
				   // there can be constraints.
  for (; face != endf; ++face)
				     // if dofs on this line are subject
				     // to constraints
    if (face->user_flag_set() == true)
      {
					 // reserve space to gather
					 // the dof numbers. We could
					 // get them when we need them,
					 // but it seems easier to gather
					 // them only once.
	vector<int> dofs_on_mother;
	vector<int> dofs_on_children;
	dofs_on_mother.reserve (4*selected_fe->dofs_per_vertex+
				4*selected_fe->dofs_per_line+
				selected_fe->dofs_per_quad);
	dofs_on_children.reserve (5*selected_fe->dofs_per_vertex+
				  12*selected_fe->dofs_per_line+
				  4*selected_fe->dofs_per_quad);

	Assert(4*selected_fe->dofs_per_vertex+
	       4*selected_fe->dofs_per_line+
	       selected_fe->dofs_per_quad
	       ==
	       selected_fe->constraints().n(),
	       ExcDifferentDimensions(4*selected_fe->dofs_per_vertex+
				      4*selected_fe->dofs_per_line+
				      selected_fe->dofs_per_quad,
				      selected_fe->constraints().n()));
	Assert(5*selected_fe->dofs_per_vertex+
	       12*selected_fe->dofs_per_line+
	       4*selected_fe->dofs_per_quad
	       ==
	       selected_fe->constraints().m(),
	       ExcDifferentDimensions(5*selected_fe->dofs_per_vertex+
				      12*selected_fe->dofs_per_line+
				      4*selected_fe->dofs_per_quad,
				      selected_fe->constraints().m()));
	
					 // fill the dofs indices. Use same
					 // enumeration scheme as in
					 // #FiniteElement::constraints()#
	for (unsigned int vertex=0; vertex<4; ++vertex)
	  for (unsigned int dof=0; dof!=selected_fe->dofs_per_vertex; ++dof)
	    dofs_on_mother.push_back (face->vertex_dof_index(vertex,dof));
	for (unsigned int line=0; line<4; ++line)
	  for (unsigned int dof=0; dof!=selected_fe->dofs_per_line; ++dof)
	    dofs_on_mother.push_back (face->line(line)->dof_index(dof));
	for (unsigned int dof=0; dof!=selected_fe->dofs_per_quad; ++dof)
	  dofs_on_mother.push_back (face->dof_index(dof));

					 // dof numbers on vertex at the center
					 // of the face, which is vertex 2 of
					 // child zero, or vertex 3 of child 1
					 // or vertex 0 of child 2 or vertex 1
					 // of child 3. We're a bit cautious and
					 // check this (also an additional safety
					 // check for the internal states of the
					 // library)
	Assert ((face->child(0)->vertex_dof_index(2,0) ==
		 face->child(1)->vertex_dof_index(3,0)) &&
		(face->child(0)->vertex_dof_index(2,0) ==
		 face->child(2)->vertex_dof_index(0,0)) &&
		(face->child(0)->vertex_dof_index(2,0) ==
		 face->child(3)->vertex_dof_index(1,0)),
		ExcInternalError());
	for (unsigned int dof=0; dof!=selected_fe->dofs_per_vertex; ++dof)
	  dofs_on_children.push_back (face->child(0)->vertex_dof_index(2,dof));
	
					 // dof numbers on the centers of
					 // the lines bounding this face
	for (unsigned int line=0; line<4; ++line)
	  for (unsigned int dof=0; dof!=selected_fe->dofs_per_vertex; ++dof)
	    dofs_on_children.push_back (face->line(line)->child(0)->vertex_dof_index(1,dof));

					 // next the dofs on the lines interior
					 // to the face; the order of these
					 // lines is laid down in the
					 // FiniteElement class documentation
	for (unsigned int dof=0; dof<selected_fe->dofs_per_line; ++dof)
	  dofs_on_children.push_back (face->child(0)->line(1)->dof_index(dof));
	for (unsigned int dof=0; dof<selected_fe->dofs_per_line; ++dof)
	  dofs_on_children.push_back (face->child(1)->line(2)->dof_index(dof));
	for (unsigned int dof=0; dof<selected_fe->dofs_per_line; ++dof)
	  dofs_on_children.push_back (face->child(2)->line(3)->dof_index(dof));
	for (unsigned int dof=0; dof<selected_fe->dofs_per_line; ++dof)
	  dofs_on_children.push_back (face->child(3)->line(0)->dof_index(dof));

					 // dofs on the bordering lines
	for (unsigned int line=0; line<4; ++line)
	  for (unsigned int child=0; child<2; ++child)
	    for (unsigned int dof=0; dof!=selected_fe->dofs_per_line; ++dof)
	      dofs_on_children.push_back (face->line(line)->child(child)->dof_index(dof));
	
					 // finally, for the dofs interior
					 // to the four child faces
	for (unsigned int child=0; child<4; ++child)
	  for (unsigned int dof=0; dof!=selected_fe->dofs_per_quad; ++dof)
	    dofs_on_children.push_back (face->child(child)->dof_index(dof));

	Assert (dofs_on_children.size() ==
	       selected_fe->constraints().m(),
	       ExcDifferentDimensions(dofs_on_children.size(),
				      selected_fe->constraints().m()));
	Assert (dofs_on_mother.size() ==
	       selected_fe->constraints().n(),
	       ExcDifferentDimensions(dofs_on_mother.size(),
				      selected_fe->constraints().n()));

					 // for each row in the constraint
					 // matrix for this line:
	for (unsigned int row=0; row!=dofs_on_children.size(); ++row) 
	  {
	    constraints.add_line (dofs_on_children[row]);
	    for (unsigned int i=0; i!=dofs_on_mother.size(); ++i)
	      constraints.add_entry (dofs_on_children[row],
				     dofs_on_mother[i],
				     selected_fe->constraints()(row,i));
	  };
      };
};

#endif



template <int dim>
void DoFHandler<dim>::make_sparsity_pattern (SparseMatrixStruct &sparsity) const {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (sparsity.n_rows() == n_dofs(),
	  ExcDifferentDimensions (sparsity.n_rows(), n_dofs()));
  Assert (sparsity.n_cols() == n_dofs(),
	  ExcDifferentDimensions (sparsity.n_cols(), n_dofs()));

  const unsigned int total_dofs = selected_fe->total_dofs;
  vector<int> dofs_on_this_cell(total_dofs);
  active_cell_iterator cell = begin_active(),
		       endc = end();
  for (; cell!=endc; ++cell) 
    {
      cell->get_dof_indices (dofs_on_this_cell);
				       // make sparsity pattern for this cell
      for (unsigned int i=0; i<total_dofs; ++i)
	for (unsigned int j=0; j<total_dofs; ++j)
	  sparsity.add (dofs_on_this_cell[i],
			dofs_on_this_cell[j]);
    };
};



template <int dim>
void
DoFHandler<dim>::make_sparsity_pattern (const vector<vector<bool> > &mask,
					SparseMatrixStruct          &sparsity) const
{
  const unsigned int total_dofs = selected_fe->total_dofs;

  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (sparsity.n_rows() == n_dofs(),
	  ExcDifferentDimensions (sparsity.n_rows(), n_dofs()));
  Assert (sparsity.n_cols() == n_dofs(),
	  ExcDifferentDimensions (sparsity.n_cols(), n_dofs()));
  Assert (mask.size() == selected_fe->n_components,
	  ExcInvalidMaskDimension(mask.size(), selected_fe->n_components));
  for (unsigned int i=0; i<mask.size(); ++i)
    Assert (mask[i].size() == selected_fe->n_components,
	    ExcInvalidMaskDimension(mask[i].size(), selected_fe->n_components));

				   // first build a mask for each dof,
				   // not like the one given which represents
				   // components
  vector<vector<bool> > dof_mask(total_dofs,
				 vector<bool>(total_dofs, false));
  for (unsigned int i=0; i<total_dofs; ++i)
    for (unsigned int j=0; j<total_dofs; ++j)
      dof_mask[i][j] = mask
		       [selected_fe->system_to_component_index(i).first]
		       [selected_fe->system_to_component_index(j).first];
  
  
  vector<int> dofs_on_this_cell(total_dofs);
  active_cell_iterator cell = begin_active(),
		       endc = end();
  for (; cell!=endc; ++cell) 
    {
      cell->get_dof_indices (dofs_on_this_cell);
				       // make sparsity pattern for this cell
      for (unsigned int i=0; i<total_dofs; ++i)
	for (unsigned int j=0; j<total_dofs; ++j)
	  if (dof_mask[i][j] == true)
	    sparsity.add (dofs_on_this_cell[i],
			  dofs_on_this_cell[j]);
    };
};




#if deal_II_dimension == 1

template <>
void DoFHandler<1>::make_boundary_sparsity_pattern (const vector<int>  &,
						    SparseMatrixStruct &) const {
    Assert (selected_fe != 0, ExcNoFESelected());
    Assert (false, ExcInternalError());
};



template <>
void DoFHandler<1>::make_boundary_sparsity_pattern (const FunctionMap  &,
						    const vector<int>  &,
						    SparseMatrixStruct &) const {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (false, ExcInternalError());
};

#endif



template <int dim>
void DoFHandler<dim>::make_boundary_sparsity_pattern (const vector<int>  &dof_to_boundary_mapping,
						      SparseMatrixStruct &sparsity) const {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (dof_to_boundary_mapping.size() == n_dofs(), ExcInternalError());
  Assert (sparsity.n_rows() == n_boundary_dofs(),
	  ExcDifferentDimensions (sparsity.n_rows(), n_boundary_dofs()));
  Assert (sparsity.n_cols() == n_boundary_dofs(),
	  ExcDifferentDimensions (sparsity.n_cols(), n_boundary_dofs()));
  Assert (*max_element(dof_to_boundary_mapping.begin(),
		       dof_to_boundary_mapping.end()) == (signed int)sparsity.n_rows()-1,
	  ExcInternalError());

  const unsigned int total_dofs = selected_fe->dofs_per_face;
  vector<int> dofs_on_this_face(total_dofs);
  active_face_iterator face = begin_active_face(),
		       endf = end_face();
  for (; face!=endf; ++face)
    if (face->at_boundary())
      {
	face->get_dof_indices (dofs_on_this_face);

					 // make sure all dof indices have a
					 // boundary index
	Assert (*min_element(dofs_on_this_face.begin(),
			     dofs_on_this_face.end()) >=0,
		ExcInternalError());
	
					 // make sparsity pattern for this cell
	for (unsigned int i=0; i<total_dofs; ++i)
	  for (unsigned int j=0; j<total_dofs; ++j) 
	    sparsity.add (dof_to_boundary_mapping[dofs_on_this_face[i]],
			  dof_to_boundary_mapping[dofs_on_this_face[j]]);
      };
};



template <int dim>
void DoFHandler<dim>::make_boundary_sparsity_pattern (const FunctionMap  &boundary_indicators,
						      const vector<int>  &dof_to_boundary_mapping,
						      SparseMatrixStruct &sparsity) const {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (dof_to_boundary_mapping.size() == n_dofs(), ExcInternalError());
  Assert (boundary_indicators.find(255) == boundary_indicators.end(),
	  ExcInvalidBoundaryIndicator());
  Assert (sparsity.n_rows() == n_boundary_dofs(boundary_indicators),
	  ExcDifferentDimensions (sparsity.n_rows(), n_boundary_dofs(boundary_indicators)));
  Assert (sparsity.n_cols() == n_boundary_dofs(boundary_indicators),
	  ExcDifferentDimensions (sparsity.n_cols(), n_boundary_dofs(boundary_indicators)));
  Assert (*max_element(dof_to_boundary_mapping.begin(),
		       dof_to_boundary_mapping.end()) == (signed int)sparsity.n_rows()-1,
	  ExcInternalError());

  const unsigned int total_dofs = selected_fe->dofs_per_face;
  vector<int> dofs_on_this_face(total_dofs);
  active_face_iterator face = begin_active_face(),
		       endf = end_face();
  for (; face!=endf; ++face)
    if (boundary_indicators.find(face->boundary_indicator()) !=
	boundary_indicators.end())
      {
	face->get_dof_indices (dofs_on_this_face);

					 // make sure all dof indices have a
					 // boundary index
	Assert (*min_element(dofs_on_this_face.begin(),
			     dofs_on_this_face.end()) >=0,
		ExcInternalError());
					 // make sparsity pattern for this cell
	for (unsigned int i=0; i<total_dofs; ++i)
	  for (unsigned int j=0; j<total_dofs; ++j)
	    sparsity.add (dof_to_boundary_mapping[dofs_on_this_face[i]],
			  dof_to_boundary_mapping[dofs_on_this_face[j]]);
      };
};




#if deal_II_dimension == 1

template <>
unsigned int DoFHandler<1>::max_couplings_between_dofs () const {
  Assert (selected_fe != 0, ExcNoFESelected());
  return 3*selected_fe->dofs_per_vertex + 2*selected_fe->dofs_per_line;
};



template <>
unsigned int DoFHandler<1>::max_couplings_between_boundary_dofs () const {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (false, ExcInternalError());
  return 0;
};

#endif



#if deal_II_dimension == 2

template <>
unsigned int DoFHandler<2>::max_couplings_between_dofs () const {
  Assert (selected_fe != 0, ExcNoFESelected());

				   // get these numbers by drawing pictures
				   // and counting...
				   // example:
				   //   |     |     |
				   // --x-----x--x--X--
				   //   |     |  |  |
				   //   |     x--x--x
				   //   |     |  |  |
				   // --x--x--*--x--x--
				   //   |  |  |     |
				   //   x--x--x     |
				   //   |  |  |     |
				   // --X--x--x-----x--
				   //   |     |     |
				   // x = vertices connected with center vertex *;
				   //   = total of 19
				   // (the X vertices are connected with * if
				   // the vertices adjacent to X are hanging
				   // nodes)
				   // count lines -> 28 (don't forget to count
				   // mother and children separately!)
  switch (tria->max_adjacent_cells())
    {
      case 4:
	    return (19*selected_fe->dofs_per_vertex +
		    28*selected_fe->dofs_per_line +
		    8*selected_fe->dofs_per_quad);
      case 5:
	    return (21*selected_fe->dofs_per_vertex +
		    31*selected_fe->dofs_per_line +
		    9*selected_fe->dofs_per_quad);
      case 6:
	    return (28*selected_fe->dofs_per_vertex +
		    42*selected_fe->dofs_per_line +
		    12*selected_fe->dofs_per_quad);
      case 7:
	    return (30*selected_fe->dofs_per_vertex +
		    45*selected_fe->dofs_per_line +
		    13*selected_fe->dofs_per_quad);
      case 8:
	    return (37*selected_fe->dofs_per_vertex +
		    56*selected_fe->dofs_per_line +
		    16*selected_fe->dofs_per_quad);
      default:
	    Assert (false, ExcNotImplemented());
	    return 0;
    };
};



template <>
unsigned int DoFHandler<2>::max_couplings_between_boundary_dofs () const {
  Assert (selected_fe != 0, ExcNoFESelected());
  return 3*selected_fe->dofs_per_vertex + 2*selected_fe->dofs_per_line;
};

#endif


#if deal_II_dimension == 3

template <>
unsigned int DoFHandler<3>::max_couplings_between_dofs () const {
  Assert (selected_fe != 0, ExcNoFESelected());

				   // doing the same thing here is a rather
				   // complicated thing, compared to the 2d
				   // case, since it is hard to draw pictures
				   // with several refined hexahedra :-) so I
				   // presently only give a coarse estimate
				   // for the case that at most 8 hexes meet
				   // at each vertex
				   //
				   // can anyone give better estimate here?
  const unsigned int max_adjacent_cells = tria->max_adjacent_cells();

  if (max_adjacent_cells <= 8)
    return (7*7*7*selected_fe->dofs_per_vertex +
	    7*6*7*3*selected_fe->dofs_per_line +
	    9*4*7*3*selected_fe->dofs_per_quad +
	    27*selected_fe->dofs_per_hex);

  
  Assert (false, ExcNotImplemented());
  return 0;
};



template <>
unsigned int DoFHandler<3>::max_couplings_between_boundary_dofs () const {
  Assert (selected_fe != 0, ExcNoFESelected());
				   // we need to take refinement of
				   // one boundary face into consideration
				   // here; in fact, this function returns
				   // what #max_coupling_between_dofs<2>
				   // returns
				   //
				   // we assume here, that only four faces
				   // meet at the boundary; this assumption
				   // is not justified and needs to be
				   // fixed some time. fortunately, ommitting
				   // it for now does no harm since the
				   // matrix will cry foul if its requirements
				   // are not satisfied
  return (19*selected_fe->dofs_per_vertex +
	  28*selected_fe->dofs_per_line +
	  8*selected_fe->dofs_per_quad);
};



#endif




template <int dim>
template <typename Number>
void DoFHandler<dim>::distribute_cell_to_dof_vector (const Vector<Number> &cell_data,
						     Vector<double>       &dof_data,
						     const unsigned int    component) const {
  Assert (cell_data.size()==tria->n_active_cells(),
	  ExcWrongSize (cell_data.size(), tria->n_active_cells()));
  Assert (dof_data.size()==n_dofs(), ExcWrongSize (dof_data.size(), n_dofs()));
  Assert (component < selected_fe->n_components,
	  ExcInvalidComponent(component, selected_fe->n_components));

				   // store a flag whether we should care
				   // about different components. this is
				   // just a simplification, we could ask
				   // for this at every single place
				   // equally well
  const bool consider_components = (selected_fe->n_components != 1);
  
				   // count how often we have added a value
				   // in the sum for each dof
  vector<unsigned char> touch_count (n_dofs(), 0);

  active_cell_iterator cell = begin_active(),
		       endc = end();
  unsigned int present_cell = 0;
  const unsigned int total_dofs = selected_fe->total_dofs;
  vector<int> dof_indices (total_dofs);

  for (; cell!=endc; ++cell, ++present_cell) 
    {
      cell->get_dof_indices (dof_indices);
      for (unsigned int i=0; i<total_dofs; ++i)
					 // consider this dof only if it
					 // is the right component. if there
					 // is only one component, short cut
					 // the test
	if (!consider_components ||
	    (selected_fe->system_to_component_index(i).first == component))
	  {
					     // sum up contribution of the
					     // present_cell to this dof
	    dof_data(dof_indices[i]) += cell_data(present_cell);
					     // note that we added another
					     // summand
	    ++touch_count[dof_indices[i]];
	  };
    };
  
				   // compute the mean value on all the
				   // dofs by dividing with the number
				   // of summands.
  for (unsigned int i=0; i<n_dofs(); ++i)
    {
				       // assert that each dof was used
				       // at least once. this needs not be
				       // the case if the vector has more than
				       // one component
      Assert (consider_components || (touch_count[i]!=0),
	      ExcInternalError());
      if (touch_count[i] != 0)
	dof_data(i) /=  touch_count[i];
    };
};



#if deal_II_dimension == 1

template <>
void DoFHandler<1>::map_dof_to_boundary_indices (vector<int> &) const {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (false, ExcNotImplemented());
};



template <>
void DoFHandler<1>::map_dof_to_boundary_indices (const FunctionMap &,
						 vector<int> &) const {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (false, ExcNotImplemented());
};

#endif



template <int dim>
void DoFHandler<dim>::map_dof_to_boundary_indices (vector<int> &mapping) const {
  Assert (selected_fe != 0, ExcNoFESelected());

  mapping.clear ();
  mapping.insert (mapping.end(), n_dofs(), -1);
  
  const unsigned int dofs_per_face = selected_fe->dofs_per_face;
  vector<int> dofs_on_face(dofs_per_face);
  int next_boundary_index = 0;
  
  active_face_iterator face = begin_active_face(),
		       endf = end_face();
  for (; face!=endf; ++face)
    if (face->at_boundary()) 
      {
	face->get_dof_indices (dofs_on_face);
	for (unsigned int i=0; i<dofs_per_face; ++i)
	  if (mapping[dofs_on_face[i]] == -1)
	    mapping[dofs_on_face[i]] = next_boundary_index++;
      };

  Assert (static_cast<unsigned int>(next_boundary_index) == n_boundary_dofs(),
	  ExcInternalError());
};



template <int dim>
void DoFHandler<dim>::map_dof_to_boundary_indices (const FunctionMap &boundary_indicators,
						   vector<int> &mapping) const {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (boundary_indicators.find(255) == boundary_indicators.end(),
	  ExcInvalidBoundaryIndicator());

  mapping.clear ();
  mapping.insert (mapping.end(), n_dofs(), -1);

				   // return if there is nothing to do
  if (boundary_indicators.size() == 0)
    return;
  
  const unsigned int dofs_per_face = selected_fe->dofs_per_face;
  vector<int> dofs_on_face(dofs_per_face);
  int next_boundary_index = 0;
  
  active_face_iterator face = begin_active_face(),
		       endf = end_face();
  for (; face!=endf; ++face)
    if (boundary_indicators.find(face->boundary_indicator()) !=
	boundary_indicators.end())
      {
	face->get_dof_indices (dofs_on_face);
	for (unsigned int i=0; i<dofs_per_face; ++i)
	  if (mapping[dofs_on_face[i]] == -1)
	    mapping[dofs_on_face[i]] = next_boundary_index++;
      };

  Assert (static_cast<unsigned int>(next_boundary_index)
	  == n_boundary_dofs(boundary_indicators),
	  ExcInternalError());
};



#if deal_II_dimension == 1

template <>
void DoFHandler<1>::reserve_space () {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (tria->n_levels() > 0, ExcInvalidTriangulation());
                                   // delete all levels and set them up
                                   // newly, since vectors are
                                   // troublesome if you want to change
                                   // their size
  clear_space ();
  
  vertex_dofs = vector<int>(tria->vertices.size()*
			    selected_fe->dofs_per_vertex,
			    -1);
    
  for (unsigned int i=0; i<tria->n_levels(); ++i) 
    {
      levels.push_back (new DoFLevel<1>);

      levels.back()->line_dofs = vector<int>(tria->levels[i]->lines.lines.size() *
					     selected_fe->dofs_per_line,
					     -1);
    };
};


#endif


#if deal_II_dimension == 2

template <>
void DoFHandler<2>::reserve_space () {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (tria->n_levels() > 0, ExcInvalidTriangulation());
  
                                   // delete all levels and set them up
                                   // newly, since vectors are
                                   // troublesome if you want to change
                                   // their size
  clear_space ();
  
  vertex_dofs = vector<int>(tria->vertices.size()*
			    selected_fe->dofs_per_vertex,
			    -1);
  for (unsigned int i=0; i<tria->n_levels(); ++i) 
    {
      levels.push_back (new DoFLevel<2>);

      levels.back()->line_dofs = vector<int> (tria->levels[i]->lines.lines.size() *
					      selected_fe->dofs_per_line,
					      -1);
      levels.back()->quad_dofs = vector<int> (tria->levels[i]->quads.quads.size() *
					      selected_fe->dofs_per_quad,
					      -1);
    };
};

#endif


#if deal_II_dimension == 3

template <>
void DoFHandler<3>::reserve_space () {
  Assert (selected_fe != 0, ExcNoFESelected());
  Assert (tria->n_levels() > 0, ExcInvalidTriangulation());
  
                                   // delete all levels and set them up
                                   // newly, since vectors are
                                   // troublesome if you want to change
                                   // their size
  clear_space ();
  
  vertex_dofs = vector<int>(tria->vertices.size()*
			    selected_fe->dofs_per_vertex,
			    -1);
  for (unsigned int i=0; i<tria->n_levels(); ++i) 
    {
      levels.push_back (new DoFLevel<3>);

      levels.back()->line_dofs = vector<int> (tria->levels[i]->lines.lines.size() *
					      selected_fe->dofs_per_line,
					      -1);
      levels.back()->quad_dofs = vector<int> (tria->levels[i]->quads.quads.size() *
					      selected_fe->dofs_per_quad,
					      -1);
      levels.back()->hex_dofs = vector<int> (tria->levels[i]->hexes.hexes.size() *
					     selected_fe->dofs_per_hex,
					     -1);
    };
};

#endif


template <int dim>
void DoFHandler<dim>::clear_space () {  
  for (unsigned int i=0; i<levels.size(); ++i)
    delete levels[i];
  levels.resize (0);
};



/*-------------- Explicit Instantiations -------------------------------*/
template class DoFHandler<deal_II_dimension>;

template
void
DoFHandler<deal_II_dimension>::distribute_cell_to_dof_vector (const Vector<float>  &cell_data,
							      Vector<double>       &dof_data) const;

template
void
DoFHandler<deal_II_dimension>::distribute_cell_to_dof_vector (const Vector<double> &cell_data,
							      Vector<double>       &dof_data) const;



