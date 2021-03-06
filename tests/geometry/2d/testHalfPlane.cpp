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
 * @file testHalfPlane.cpp
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
 * Description of testHalfPlane <p>
 * Aim: simple test of \ref StraightLine and \ref Point2ShapePredicate
 */

#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <iterator>




#include "DGtal/base/Common.h"
#include "DGtal/base/Exceptions.h"
#include "DGtal/kernel/SpaceND.h"
#include "DGtal/kernel/domains/DomainPredicate.h"
#include "DGtal/kernel/domains/HyperRectDomain.h"
#include "DGtal/io/boards/Board2D.h"

#include "DGtal/geometry/2d/StraightLine.h"
#include "DGtal/geometry/2d/Point2ShapePredicate.h"
	

using namespace DGtal;

using namespace LibBoard;




int main(int argc, char **argv)
{



	typedef int Coordinate;
	typedef PointVector<2,Coordinate> Point;
	typedef StraightLine<Coordinate> StraightLine;

	Point p(0,0);
	Point q(5,2);
	Point r1(2,0);
	Point r2(0,2);
	Point r3(10,4);

	StraightLine line(p,q);


	//halfplane upward oriented and closed 
  typedef Point2ShapePredicate<StraightLine,true,true> UpClosedHalfPlane; 
	//halfplane upward oriented and open 
  typedef Point2ShapePredicate<StraightLine,true,false> UpOpenHalfPlane; 
	//halfplane downward oriented and closed 
  typedef Point2ShapePredicate<StraightLine,false,true> DownClosedHalfPlane; 

  //Location
  trace.beginBlock("Creation of a halfplane and test some points");

	std::string res;

  trace.info() << "created line:" << std::endl;
  trace.info() << line << std::endl;

  UpClosedHalfPlane hp(line);
  trace.info() << "created hp:" << std::endl;
	trace.info() << hp << std::endl;

  trace.info() << "Does " << r1 << " belongs to hp (no)?" << std::endl;
	res = hp(r1)?"yes":"no";
  trace.info() << res << std::endl;

  trace.info() << "Does " << r2 << " belongs to hp (yes)?" << std::endl;
	res = hp(r2)?"yes":"no";
  trace.info() << res << std::endl;

  trace.info() << "Does " << r3 << " belongs to hp (yes)?" << std::endl;
	res = hp(r3)?"yes":"no";
  trace.info() << res << std::endl;


  UpOpenHalfPlane hp2(line);
  trace.info() << "created h2:" << std::endl;
	trace.info() << hp2 << std::endl;

  trace.info() << "Does " << r1 << " belongs to hp2 (no)?" << std::endl;
	res = hp2(r1)?"yes":"no";
  trace.info() << res << std::endl;

  trace.info() << "Does " << r2 << " belongs to hp2 (yes)?" << std::endl;
	res = hp2(r2)?"yes":"no";
  trace.info() << res << std::endl;

  trace.info() << "Does " << r3 << " belongs to hp2 (no)?" << std::endl;
	res = hp2(r3)?"yes":"no";
  trace.info() << res << std::endl;

  DownClosedHalfPlane hp3(line);
  trace.info() << "created h3:" << std::endl;
	trace.info() << hp3 << std::endl;

  trace.info() << "Does " << r1 << " belongs to hp3 (yes)?" << std::endl;
	res = hp3(r1)?"yes":"no";
  trace.info() << res << std::endl;

  trace.info() << "Does " << r2 << " belongs to hp3 (no)?" << std::endl;
	res = hp3(r2)?"yes":"no";
  trace.info() << res << std::endl;

  trace.info() << "Does " << r3 << " belongs to hp3 (yes)?" << std::endl;
	res = hp3(r3)?"yes":"no";
  trace.info() << res << std::endl;

  trace.endBlock();


  return 0;
}
