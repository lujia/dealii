//----------------------------  grid_generator.h  ---------------------------
//    $Id$
//    Version: $Name$
//
//    Copyright (C) 1998, 1999, 2000 by the deal.II authors
//
//    This file is subject to QPL and may not be  distributed
//    without copyright and license information. Please refer
//    to the file deal.II/doc/license.html for the  text  and
//    further information on this license.
//
//----------------------------  grid_generator.h  ---------------------------
#ifndef __deal2__grid_generator_h
#define __deal2__grid_generator_h


#include <base/exceptions.h>

template <int dim> class Point;
template <int dim> class Triangulation;


/**
 * This class offers triangulations of some standard domains such as hypercubes,
 * hyperball and the like. Following is a list of domains that can be generated
 * by the functions of this class:
 * @begin{itemize}
 *    @item Hypercube triangulations: a hypercube triangulation is a
 *       domain which is the tensor product of an interval $[a,b]$ in
 *       the given number of spatial dimensions. If you want to create such
 *       a domain, which is a common test case for model problems, call
 *       @ref{GridGenerator}@p{::hyper_cube (tria, a,b)}, which produces a
 *       hypercube domain triangulated with exactly one element. You can
 *       get tensor product meshes by successive refinement of this cell.
 *
 *    @item Generalized L-shape domain:
 *      using the @ref{GridGenerator}@p{::hyper_L (tria, a,b)} function produces
 *      the hypercube with the interval $[a,b]$ without the hypercube
 *      made out of the interval $[(a+b)/2,b]$. Let, for example, be $a=-1$
 *      and $b=1$, then the hpyer-L in two dimensions is the region
 *      $[-1,1]^2 - [0,1]^2$. To create a hyper-L in one dimension results in
 *      an error. The function is also implemented for three space dimensions.
 *
 *    @item Hyper balls:
 *      You get the circle or ball (or generalized: hyperball) around origin
 *      @p{p} and with radius @p{r} by calling
 *      @ref{GridGenerator}@p{::hyper_ball (tria, p, r)}. The circle is triangulated
 *      by five cells, the ball by seven cells. The diameter of the center cell is
 *      chosen so that the aspect ratio of the boundary cells after one refinement
 *      is minimized in some way. To create a hyperball in one dimension results in
 *      an error.
 *
 *      Do not forget to also attach a suitable boundary approximation object
 *      to the triangulation object you passed to this function if you later want
 *      the triangulation to be refined at the outer boundaries.
 *
 *    @item Hyper shell: A hyper shell is the region between two hyper
 *      sphere with the same origin. Therefore, it is a ring in two
 *      spatial dimensions. To triangulation it, call the function
 *      @ref{GridGenerator}@p{::hyper_shell (tria, origin, inner_radius, outer_radius, N)},
 *      where the center of the spheres as well as
 *      the inner and outer radius of the two spheres are given as
 *      shown.
 *
 *      The parameter @p{N} denotes how many cells are to be used for
 *      this coarse triangulation. It defaults to zero, which tells
 *      the function to chose the number itself; this, then, is done
 *      such that the aspect ration of the resulting cells is as small
 *      as possible. However, it should be mentioned that this
 *      function does not work very well if the inner radius is much
 *      smaller than the outer radius since only one layer of cells is
 *      used in the radial direction.
 *
 *      You need to attach a boundary object to the triangulation. A
 *      suitable boundary class is provided as @ref{HyperSphereBoundary}
 *      in the library.
 *
 * @item Slit domain: The slit domain is a variant of the hyper cube
 *      domain. In two spatial dimensions, it is a square into which a slit
 *      is sawed; if the initial square is though to be composed of four
 *      smaller squares, then two of them are not connected even though
 *      they are neighboring each other. Analogously, into the cube in
 *      three spatial dimensions, a half-plane is sawed, disconnecting four
 *      of the eight child-cubes from one of their neighbors.
 * @end{itemize}
 *
 * @author Wolfgang Bangerth, 1998, 1999. Slit domain by Stefan Nauber, 1999
 */
class GridGenerator
{
  public:
    				     /**
				      * Initialize the given
				      * triangulation with a hypercube
				      * (line in 1D, square in 2D,
				      * etc) consisting of exactly one
				      * cell. The hypercube volume is
				      * the tensor product of the
				      * intervall $[left,right]$ in
				      * the present number of
				      * dimensions, where the limits
				      * are given as arguments. They
				      * default to zero and unity,
				      * then producing the unit
				      * hypercube.
				      *
				      * The triangulation needs to be
				      * void upon calling this
				      * function.
				      */
    template <int dim>
    static void hyper_cube (Triangulation<dim> &tria,
			    const double        left = 0.,
			    const double        right= 1.);

				     /**
				      * Hypercube with a layer of
				      * hypercubes around it. The
				      * first two parameters give the
				      * lower and upper bound of the
				      * inner hypercube in all
				      * coordinate directions.
				      * @p{thickness} marks the size of
				      * the layer cells.
				      *
				      * If the flag colorize is set,
				      * the outer cells get material
				      * id's according tho the
				      * following scheme: extending
				      * over the inner cube in
				      * (+/-) x-direction: 1/2. In y-direction
				      * 4/8, in z-direction 16/32. The cells
				      * at corners and edges (3d) get
				      * these values bitwise or'd.
				      */
    template<int dim>
    static void enclosed_hyper_cube (Triangulation<dim> &tria,
	 			     const double        left = 0.,
				     const double        right= 1.,
				     const double        thickness = 1.,
				     bool                colorize = false);

				     /**
				      * Initialize the given
				      * triangulation with a
				      * hyperball, i.e. a circle or a
				      * ball.  See the general
				      * documentation for a more
				      * concise description. The
				      * center of the hyperball
				      * default to the origin, the
				      * radius defaults to unity.
				      *
				      * The triangulation needs to be
				      * void upon calling this
				      * function.
				      */    
    template <int dim>
    static void hyper_ball (Triangulation<dim> &tria,
			    const Point<dim>   &center = Point<dim>(),
			    const double        radius = 1.);

				     /**
				      * Initialize the given
				      * triangulation with a hyper-L
				      * consisting of exactly
				      * @p{2^dim-1} cells. See the
				      * general documentation for a
				      * description of the
				      * L-region. The limits default
				      * to minus unity and unity.
				      *
				      * The triangulation needs to be
				      * void upon calling this
				      * function.
				      */
    template <int dim>
    static void hyper_L (Triangulation<dim> &tria,
			 const double        left = -1.,
			 const double        right= 1.);
    
                                     /**
				      * Initialize the given
				      * Triangulation with a hypercube
				      * with a slit. The slit goes
				      * from @p{(x=0,y=-1)} to
				      * @p{(0,0)} in 2d.
				      *
				      * The triangulation needs to be void
				      * upon calling this function.
				      */
    template <int dim>
    static void hyper_cube_slit (Triangulation<dim> &tria,
				 const double        left = 0.,
				 const double        right= 1.);

				     /**
				      * Produce a hyper-shell,
				      * i.e. the space between two
				      * circles in two space
				      * dimensions and the region
				      * between two spheres in 3d,
				      * with given inner and outer
				      * radius and a given number of
				      * elements for this initial
				      * triangulation. If the number
				      * of initial cells is zero (as
				      * is the default), then it is
				      * computed adaptively such that
				      * the resulting elements have
				      * the least aspect ratio.
				      *
				      * The triangulation needs to be
				      * void upon calling this
				      * function.
				      */
    template <int dim>
    static void hyper_shell (Triangulation<dim> &tria,
			     const Point<dim>   &center,
			     const double        inner_radius,
			     const double        outer_radius,
			     const unsigned int  n_cells = 0);

				     /**
				      * Exception
				      */
    DeclException0 (ExcInvalidRadii);
};


#endif
