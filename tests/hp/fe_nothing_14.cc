//----------------------------  fe_nothing_14.cc  ---------------------------
//    $Id$
//    Version: $Name$
//
//    Copyright (C) 2009, 2011 by the deal.II authors
//
//    This file is subject to QPL and may not be  distributed
//    without copyright and license information. Please refer
//    to the file deal.II/doc/license.html for the  text  and
//    further information on this license.
//
//----------------------------  fe_nothing_14.cc  ---------------------------


// check the case where the two children on a face with a hanging node have
// different FENothing structure. compared to _12 and _13, the situation is
// even more wicked since in the picture below 0=FE_Q(1), 1=FE_Nothing,
// 2=FE_Q(2), i.e. 2 dominates 1

// active_fe_index
// *-----*
// |     |
// |  0  |
// |     |
// *--*--*
// | 1| 2|
// *--*--*
// | 1| 2|
// *--*--*

// DoF index
// 2--7--3
// |     |
// 4  8  5
// |     |
// 0--6--1
// |  |  |
// *--11-12
// |  |  |
// *--9--10


#include "../tests.h"
#include <base/logstream.h>
#include <base/function.h>
#include <fe/fe_nothing.h>
#include <fe/fe_q.h>
#include <hp/fe_collection.h>
#include <hp/dof_handler.h>
#include <grid/tria.h>
#include <grid/grid_generator.h>
#include <grid/tria_accessor.h>
#include <grid/tria_iterator.h>
#include <grid/grid_refinement.h>
#include <dofs/dof_accessor.h>
#include <dofs/dof_tools.h>
#include <fe/fe_q.h>
#include <fe/fe_system.h>
#include <hp/dof_handler.h>
#include <hp/fe_values.h>
#include <numerics/vectors.h>


#include <fstream>


template <int dim>
void test ()
{
  Triangulation<dim>       triangulation;
  std::vector<unsigned int> sub(dim, 1);
  sub[dim-1] = 2;

  GridGenerator::subdivided_hyper_rectangle (triangulation, sub, Point<dim>(), Point<dim>());
  triangulation.begin_active()->set_refine_flag();
  triangulation.execute_coarsening_and_refinement();

  hp::FECollection<dim>    fe_collection;
  fe_collection.push_back (FE_Q<dim>(1));
  fe_collection.push_back (FE_Nothing<dim>());
  fe_collection.push_back (FE_Q<dim>(2));
  
  hp::DoFHandler<dim>      dof_handler (triangulation);

  dof_handler.begin_active()->set_active_fe_index(1);
  typename hp::DoFHandler<dim>::active_cell_iterator
    cell = dof_handler.begin_active(0),
    endc = dof_handler.end();
  for (; cell!=endc; ++cell)
    if (cell->index() % 2 == 0)
      cell->set_active_fe_index (1);
    else
      cell->set_active_fe_index (2);

  dof_handler.distribute_dofs (fe_collection);

  ConstraintMatrix constraints;

  DoFTools::make_hanging_node_constraints (dof_handler, constraints);

  constraints.close();

  deallog << "   Number of constraints:        "
          << constraints.n_constraints()
          << std::endl;
  {
    typename hp::DoFHandler<dim>::active_cell_iterator
      cell = dof_handler.begin_active(),
      endc = dof_handler.end();

    for(; cell != endc; cell++)
      {
	deallog << cell << ' ' << cell->active_fe_index() << std::endl
		<< "   ";
	std::vector<unsigned int> local_dof_indices (cell->get_fe().dofs_per_cell);
	cell->get_dof_indices (local_dof_indices);

	for (unsigned int i=0; i<cell->get_fe().dofs_per_cell; ++i)
	  deallog << local_dof_indices[i]
		  << (constraints.is_constrained(local_dof_indices[i]) ?
		      "*" : "")
		  << ' ';
	deallog << std::endl;
      }
  }

  constraints.print (deallog.get_file_stream());
}



int main ()
{
  std::ofstream logfile("fe_nothing_14/output");
  logfile.precision(3);

  deallog.attach(logfile);
  deallog.depth_console(0);
  deallog.threshold_double(1.e-10);

  test<2> ();

  deallog << "OK" << std::endl;
}
