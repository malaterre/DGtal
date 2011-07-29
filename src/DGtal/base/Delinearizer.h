/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

/**
 * @file Delinearizer.h
 * @author David Coeurjolly (\c david.coeurjolly@liris.cnrs.fr )
 * Laboratoire d'InfoRmatique en Image et Systèmes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 *
 * @date 2011/07/28
 *
 *
 * This file is part of the DGtal library.
 */

///////////////////////////////////////////////////////////////////////////////
// Helper classes defined in the compilation unit (anonymous namespace)

namespace DGtal
{

  /**
   * Class template for delinearization of the coordinates of a Point.
   * This class template is to be specialized for efficiency for dimensions 1,
   * 2 and 3 to prevent the use of a loop in these cases.
   *
   */
  template < typename Domain, int dimension, typename Size >
  struct Delinearizer
  {

    typedef typename Domain::Point Point;

    /**
     * Compute the linearized offset of a point in a vector container.
     *
     * @param aPoint A point
     * @param lowerBound The lower bound of the image domain.
     * @param upperBound The upper bound of the image domain.
     *
     * @return
     */
    static 
    Point apply( const Size & aPos,
		 const Point & lowerBound,
		 const Point & upperBound )
    {
      
      return Point();
    }
  };

  /**
   * Specialization of the linearizer class for dimension 1.
   *
   */
  template < typename Domain, typename Size >
  struct Delinearizer< Domain, 1, Size >
  {
    typedef typename Domain::Point Point;

    static 
    Point apply( const Size & aPos,
		 const Point & lowerBound,
		 const Point & upperBound )
    {
      return Point(lowerBound[0] + aPos);
    }
  };
  
  /**
   * Specialization of the linearizer class for dimension 2.
   *
   */
  template < typename Domain, typename Size >
  struct Delinearizer< Domain, 2, Size >
  {
    typedef typename Domain::Point Point;
    
    static 
    Point apply( const Size & aPos,
		 const Point & lowerBound,
		 const Point & upperBound )
    {
      Size multiplier = 1 + upperBound[ 0 ] - lowerBound[ 0 ];
      return Point( lowerBound[ 0 ] + (aPos % multiplier), 
		    lowerBound[ 1 ] + (aPos / multiplier));
    }
  };
  
  /**
   * Specialization of the linearizer class for dimension 3.
   *
   */
  template < typename Domain, typename Size >
  struct Delinearizer< Domain, 3, Size >
  {
    typedef typename Domain::Point Point;
    
    static 
    Point apply( const Size & aPos,
		 const Point & lowerBound,
		 const Point & upperBound )
    {
      Size multiplier = 1 + upperBound[ 0 ] - lowerBound[ 0 ];
      Size multiplier2 = multiplier*(1 + upperBound[ 1 ] - lowerBound[ 1 ]);
      Point res = lowerBound;
      res[ 2 ] +=  (aPos / multiplier2);
      Size aPos2 = aPos % multiplier2;
      res[ 1 ] +=  (aPos2 / multiplier);
      res[ 0 ] +=  (aPos2 % multiplier);
				     
      return res;
    }
  };
}
