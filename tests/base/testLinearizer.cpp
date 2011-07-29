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
 * @file testLinearizer.cpp
 * @ingroup Tests
 * @author David Coeurjolly (\c david.coeurjolly@liris.cnrs.fr )
 * Laboratoire d'InfoRmatique en Image et Systèmes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 *
 * @date 2011/07/29
 *
 * Functions for testing class Linearizer.
 *
 * This file is part of the DGtal library.
 */

///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "DGtal/base/Common.h"

#include "DGtal/helpers/StdDefs.h"
#include "DGtal/base/Linearizer.h"
#include "DGtal/base/Delinearizer.h"


///////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace DGtal;

///////////////////////////////////////////////////////////////////////////////
// Functions for testing class Linearizer.
///////////////////////////////////////////////////////////////////////////////
/**
 * Example of a test. To be completed.
 *
 */
bool testLinearizer()
{
  unsigned int nbok = 0;
  unsigned int nb = 0;
  
  trace.beginBlock ( "Testing Linearizer 2D ..." );

  Z2i::Point p(10,0);
  Z2i::Point q(0,4);

  Z2i::Point p2(9,-1);
  Z2i::Point q2(-1,3);

  Z2i::Point p3(11,1);
  Z2i::Point q3(1,5);

  Z2i::Point lower(0,0);
  Z2i::Point upper(19,19);

  Z2i::Point lower2(-1,-1);
  Z2i::Point upper2(18,18);

  Z2i::Point lower3(1,1);
  Z2i::Point upper3(20,20);
  
  trace.info() << "Linearization of "<< p<< " = "
	       << Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(p,lower,upper) << endl;
  trace.info() << "Linearization of "<< q<< " = "
	       << Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(q,lower,upper) << endl;

  trace.info() << "Linearization bis of "<< p2<< " = "
	       << Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(p2,lower2,upper2) << endl;
  trace.info() << "Linearization bis of "<< q2<< " = "
	       << Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(q2,lower2, upper2) << endl;

  trace.info() << "Linearization ter of "<< p3<< " = "
	       << Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(p3,lower3,upper3) << endl;
  trace.info() << "Linearization ter of "<< q3<< " = "
	       << Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(q3,lower3, upper3) << endl;
  
  

  nbok += ( Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(p,lower,upper) ==
	    Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(p2,lower2,upper2))? 1 : 0; 
  nb++;
  nbok += ( Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(p,lower,upper) ==
	    Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(p3,lower3,upper3))? 1 : 0; 
  nb++;

  nbok += ( Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(q,lower,upper) ==
	    Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(q2,lower2,upper2))? 1 : 0; 
  nb++;
  nbok += ( Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(q,lower,upper) ==
	    Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(q3,lower3,upper3))? 1 : 0; 
  nb++;


  trace.info() << "(" << nbok << "/" << nb << ") "
	       << "true == true" << std::endl;
  trace.endBlock();
  
  return nbok == nb;
}


bool testDelinearizer()
{
  unsigned int nbok = 0;
  unsigned int nb = 0;
  
  trace.beginBlock ( "Testing Delinearizer 2D ..." );

  Z2i::Point p(10,0);
  Z2i::Point q(0,4);

  Z2i::Point p2(9,-1);
  Z2i::Point q2(-1,3);

  Z2i::Point p3(11,1);
  Z2i::Point q3(1,5);

  Z2i::Point lower(0,0);
  Z2i::Point upper(19,19);

  Z2i::Point lower2(-1,-1);
  Z2i::Point upper2(18,18);

  Z2i::Point lower3(1,1);
  Z2i::Point upper3(20,20);
  

  nbok += ( Delinearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(p,lower,upper),lower,upper) == p)? 1 : 0; 
  nb++;

  nbok += ( Delinearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(p2,lower2,upper2), lower2,upper2) == p2)? 1 : 0; 
  nb++;

  nbok += ( Delinearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(Linearizer<Z2i::Domain, 2 , DGtal::uint64_t>::apply(p3,lower3,upper3), lower3,upper3) == p3)? 1 : 0; 
  nb++;

  trace.info() << "(" << nbok << "/" << nb << ") "
	       << "true == true" << std::endl;
   trace.endBlock();
  
  return nbok == nb;
}

bool testDelinearizer3D()
{
  unsigned int nbok = 0;
  unsigned int nb = 0;
  
  trace.beginBlock ( "Testing Delinearizer 3D ..." );

  Z3i::Point p(10,0,0);
  Z3i::Point q(0,4,2);

  Z3i::Point p2(9,-1,-1);
  Z3i::Point q2(-1,3,1);

  Z3i::Point p3(11,1,1);
  Z3i::Point q3(1,5,3);

  Z3i::Point lower(0,0,0);
  Z3i::Point upper(19,19,19);

  Z3i::Point lower2(-1,-1,-1);
  Z3i::Point upper2(18,18,18);

  Z3i::Point lower3(1,1,1);
  Z3i::Point upper3(20,20,20);
  

  nbok += ( Delinearizer<Z3i::Domain, 3 , DGtal::uint64_t>::apply(Linearizer<Z3i::Domain, 3 , DGtal::uint64_t>::apply(p,lower,upper),lower,upper) == p)? 1 : 0; 
  nb++;

  nbok += ( Delinearizer<Z3i::Domain, 3 , DGtal::uint64_t>::apply(Linearizer<Z3i::Domain, 3 , DGtal::uint64_t>::apply(p2,lower2,upper2), lower2,upper2) == p2)? 1 : 0; 
  nb++;

  nbok += ( Delinearizer<Z3i::Domain, 3 , DGtal::uint64_t>::apply(Linearizer<Z3i::Domain, 3 , DGtal::uint64_t>::apply(p3,lower3,upper3), lower3,upper3) == p3)? 1 : 0; 
  nb++;

  trace.info() << "(" << nbok << "/" << nb << ") "
	       << "true == true" << std::endl;
   trace.endBlock();
  
  return nbok == nb;
}

///////////////////////////////////////////////////////////////////////////////
// Standard services - public :

int main( int argc, char** argv )
{
  trace.beginBlock ( "Testing class Linearizer" );
  trace.info() << "Args:";
  for ( int i = 0; i < argc; ++i )
    trace.info() << " " << argv[ i ];
  trace.info() << endl;

  bool res = testLinearizer() &&
    testDelinearizer() &&
    testDelinearizer3D();// && ... other tests
  trace.emphase() << ( res ? "Passed." : "Error." ) << endl;
  trace.endBlock();
  return res ? 0 : 1;
}
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
