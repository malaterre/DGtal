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
 * @file testArithDSS.cpp
 * @ingroup Tests
 * @author Tristan Roussillon (\c tristan.roussillon@liris.cnrs.fr )
 * Laboratoire d'InfoRmatique en Image et Systèmes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 *
 *
 * @date 2010/07/02
 *
 * This file is part of the DGtal library
 */

/**
 * Description of testArithDSS <p>
 * Aim: simple test of \ref ArithmeticalDSS
 */




#include <iostream>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>

#include "DGtal/base/Common.h"
#include "DGtal/base/Exceptions.h"
#include "DGtal/kernel/SpaceND.h"
#include "DGtal/kernel/domains/HyperRectDomain.h"
#include "DGtal/geometry/2d/ArithmeticalDSS.h"
#include "DGtal/io/boards/Board2D.h"

#ifdef WITH_GMP
#include <gmpxx.h>
#endif

using namespace DGtal;
using namespace std;
using namespace LibBoard;

///////////////////////////////////////////////////////////////////////////////
// Functions for testing class ArithmeticalDSS.
///////////////////////////////////////////////////////////////////////////////
/**
 * Test for 4-connected points
 *
 */
bool testDSS4drawing()
{

	typedef PointVector<2,int> Point;
	typedef std::vector<Point>::iterator Iterator;
	typedef ArithmeticalDSS<Iterator,int,4> DSS4;  

	std::vector<Point> contour;
	contour.push_back(Point(0,0));
	contour.push_back(Point(1,0));
	contour.push_back(Point(1,1));
	contour.push_back(Point(2,1));
	contour.push_back(Point(3,1));
	contour.push_back(Point(3,2));
	contour.push_back(Point(4,2));
	contour.push_back(Point(5,2));
	contour.push_back(Point(6,2));
	contour.push_back(Point(6,3));
	contour.push_back(Point(6,4));

  
  // Adding step
  trace.beginBlock("Add points while it is possible and draw the result");

		DSS4 theDSS4;	
		Iterator i = contour.begin();	
		theDSS4.init(i);
		i++;
		trace.info() << theDSS4 << " " << theDSS4.isValid() << std::endl;

		while ( (i!=contour.end())
					&&(theDSS4.extend(i)) ) {
			i++;
		}
	  trace.info() << theDSS4 << " " << theDSS4.isValid() << std::endl;

		HyperRectDomain< SpaceND<2,int> > domain( Point(0,0), Point(10,10) );

		Board2D board;
		board.setUnit(Board::UCentimeter);
		
  	board << SetMode(domain.styleName(), "Grid")
				  << domain;		
    board << SetMode("PointVector", "Grid");

//  	board << SetMode(theDSS4.styleName(), "Both") 
//					<< theDSS4;
//does not draw the default style

  	board << SetMode(theDSS4.styleName(), "Points") 
					<< theDSS4;
  	board << SetMode(theDSS4.styleName(), "BoundingBox") 
					<< theDSS4;
		
		board.saveSVG("DSS4.svg");
	

  trace.endBlock();

	return true;  
}

/**
 * Test for 8-connected points
 *
 */
bool testDSS8drawing()
{

	typedef PointVector<2,int> Point;
	typedef std::vector<Point>::iterator Iterator;
	typedef ArithmeticalDSS<Iterator,int,8> DSS8;  

	std::vector<Point> boundary;
	boundary.push_back(Point(0,0));
	boundary.push_back(Point(1,1));
	boundary.push_back(Point(2,1));
	boundary.push_back(Point(3,2));
	boundary.push_back(Point(4,2));
	boundary.push_back(Point(5,2));
	boundary.push_back(Point(6,3));
	boundary.push_back(Point(6,4));

  // Good Initialisation
  trace.beginBlock("Add points while it is possible and draw the result");
  DSS8 theDSS8;		
	Iterator i = boundary.begin();
	theDSS8.init(i);
	i++;
  trace.info() << theDSS8 << " " << theDSS8.isValid() << std::endl;

	{

		while ( (i!=boundary.end())
					&&(theDSS8.extend(i)) ) {
			i++;
		}
	  trace.info() << theDSS8 << " " << theDSS8.isValid() << std::endl;


		HyperRectDomain< SpaceND<2,int> > domain( Point(0,0), Point(10,10) );

		
		Board2D board;
		board.setUnit(Board::UCentimeter);
		

  	board << SetMode(domain.styleName(), "Paving")
				  << domain;		
    board << SetMode("PointVector", "Both");


//  	board << SetMode(theDSS8.styleName(), "Both") 
//					<< theDSS8;
//does not work


  	board << SetMode(theDSS8.styleName(), "Points") 
					<< theDSS8;
  	board << SetMode(theDSS8.styleName(), "BoundingBox") 
					<< theDSS8;
		
		
		board.saveSVG("DSS8.svg");

	}

  trace.endBlock();

	return true;  
}

/**
 * checking consistency between extension and retractation.
 *
 */
bool testExtendRetract()
{


	typedef PointVector<2,int> Point;
	typedef std::vector<Point>::iterator Iterator;
	typedef ArithmeticalDSS<Iterator,int,4> DSS4;  


	std::vector<Point> contour;
	contour.push_back(Point(0,0));
	contour.push_back(Point(1,0));
	contour.push_back(Point(1,1));
	contour.push_back(Point(2,1));
	contour.push_back(Point(3,1));
	contour.push_back(Point(3,2));
	contour.push_back(Point(4,2));
	contour.push_back(Point(5,2));
	contour.push_back(Point(6,2));
	contour.push_back(Point(6,3));
	contour.push_back(Point(6,4));


  trace.beginBlock("Checking consistency between adding and removing");

		std::deque<DSS4 > v1,v2;
  	DSS4 newDSS4;
		Iterator i = contour.begin();
		newDSS4.init(i);
	  v1.push_back(newDSS4);	 
		i++;

		//forward scan and store each DSS4
		trace.info() << "forward scan" << std::endl;

		while ( (i!=contour.end())
					&&(newDSS4.extend(i)) ) {
	  	v1.push_back(newDSS4);
			i++;
		}

		//backward scan
		trace.info() << "backward scan" << std::endl;

		i--; 
  	DSS4 reverseDSS4;
		reverseDSS4.init(i);

		Iterator j = i; j--;
		while ( (j!=contour.begin())&&(reverseDSS4.extendOppositeEnd(j)) ) {
			j--;
		}
		reverseDSS4.extendOppositeEnd(j);

		trace.info() << "removing" << std::endl;

		//removing step, store each DSS4 for comparison
	  v2.push_front(reverseDSS4);
		while (reverseDSS4.retractOppositeEnd()) {
	  	v2.push_front(reverseDSS4);
		}		
		

		//comparison
		trace.info() << "comparison" << std::endl;
		trace.info() << v1.size() << " == " << v2.size() << std::endl;
		ASSERT(v1.size() == v2.size());

		bool isOk = true;
		for (unsigned int k = 0; k < v1.size(); k++) {
			if (v1.at(k) != v2.at(k)) isOk = false;
			trace.info() << "DSS4 :" << k << std::endl;

			trace.info() << v1.at(k) << v2.at(k) << std::endl;
		}


		if (isOk) trace.info() << "ok for the " << v1.size() << " DSS4" << std::endl;
		else trace.info() << "failure" << std::endl;

  trace.endBlock();

	return isOk;
}


#ifdef WITH_GMP
/**
 * Test for 4-connected points
 *
 */
bool testGMP()
{
	bool flag = false;


	typedef mpz_class Coordinate;
	typedef PointVector<2,Coordinate> Point;
	typedef std::vector<Point>::iterator Iterator;
	typedef ArithmeticalDSS<Iterator,Coordinate,4> DSS4;  



  trace.beginBlock("Add some points of big coordinates");

		std::vector<Point> contour;
		contour.push_back(Point(1000000000,1000000000));	
		contour.push_back(Point(1000000001,1000000000));
		contour.push_back(Point(1000000002,1000000000));
		contour.push_back(Point(1000000003,1000000000));
		contour.push_back(Point(1000000003,1000000001));
		contour.push_back(Point(1000000004,1000000001));
		contour.push_back(Point(1000000005,1000000001));
		contour.push_back(Point(1000000005,1000000002));

		DSS4 theDSS4;
		Iterator i = contour.begin();
		theDSS4.init(i);
		i++;
		while (i != contour.end()) {
			theDSS4.extend(i);
			i++;
		}
	  trace.info() << theDSS4 << " " << theDSS4.isValid() << std::endl;

		Coordinate mu;
		mu = "-3000000000";
		if( (theDSS4.getA() == 2)
			&&(theDSS4.getB() == 5)
			&&(theDSS4.getMu() == mu)
			&&(theDSS4.getOmega() == 7) ) {
			flag = true;
		} else {
			flag = false;
		}

  trace.endBlock();

	return flag;
}

#endif

/**
 * Test for corners
 * in 8-connected curves
 * (not compatible steps)
 */
bool testCorner()
{

	typedef PointVector<2,int> Point;
	typedef std::vector<Point>::iterator Iterator;
	typedef ArithmeticalDSS<Iterator,int,8> DSS8;  

	std::vector<Point> boundary;
	boundary.push_back(Point(10,10));
	boundary.push_back(Point(10,11));
	boundary.push_back(Point(11,11));


	DSS8 theDSS8;
	Iterator i = boundary.begin();
	theDSS8.init(i);
	i++;
	theDSS8.extend(i);
	i++;
	return ( !theDSS8.extend(i) );

}


bool testSmartDSS()
{

	typedef PointVector<2,int> Point;
	typedef std::vector<Point>::iterator Iterator;
	typedef ArithmeticalDSS<Iterator,int,4> DSS4;  

	std::vector<Point> contour;
	contour.push_back(Point(0,0));
	contour.push_back(Point(1,0));
	contour.push_back(Point(1,1));
	contour.push_back(Point(2,1));
	contour.push_back(Point(3,1));
	contour.push_back(Point(3,2));
	contour.push_back(Point(4,2));
	contour.push_back(Point(5,2));
	contour.push_back(Point(6,2));
	contour.push_back(Point(6,3));
	contour.push_back(Point(6,4));

  
  // Adding step
  trace.beginBlock("extension");
  
  DSS4 s;
  s.init( contour.begin() );
  while ( (s.end()!=contour.end())
	  &&(s.extend()) ) {} 
  

  HyperRectDomain< SpaceND<2,int> > domain( Point(0,0), Point(10,10) );
  
  Board2D board;
  board.setUnit(Board::UCentimeter);
  
  board << SetMode(domain.styleName(), "Grid")
	<< domain;		
  board << SetMode("PointVector", "Grid");
  board << SetMode(s.styleName(), "Points") 
	<< s;
  board << SetMode(s.styleName(), "BoundingBox") 
	<< s;
  
  board.saveEPS("DSS.eps");
  
  trace.endBlock();
  
  return true;  
}

int main(int argc, char **argv)
{

  trace.beginBlock ( "Testing class ArithmeticalDSS" );
  trace.info() << "Args:";
  for ( int i = 0; i < argc; ++i )
    trace.info() << " " << argv[ i ];
  trace.info() << endl;

  bool res = testDSS4drawing() 
					&& testDSS8drawing()
					&& testExtendRetract()
					&& testCorner()
#ifdef WITH_GMP
					&& testGMP()
#endif
         && testSmartDSS()
    ;
  trace.emphase() << ( res ? "Passed." : "Error." ) << endl;
  trace.endBlock();

  return res ? 0 : 1;

}
