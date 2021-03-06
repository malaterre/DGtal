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
 * @file   dgtalCairo-5-custom.cpp
 * @author Martial Tola <http://liris.cnrs.fr/martial.tola/>
 * @date   mercredi 25 mai 2011
 * 
 * @brief
 *
 * Simple example of class Board3DTo2D.
 *
 * This file is part of the DGtal library.
 */

///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "DGtal/io/boards/Board3DTo2D.h"
#include "DGtal/io/DrawWithDisplay3DModifier.h"
#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/helpers/Shapes.h"

///////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace DGtal;
using namespace Z3i;


///////////////////////////////////////////////////////////////////////////////
// Standard services - public :

int main( int argc, char** argv )
{
  Board3DTo2D viewer;

  Point p1( -1, -1, -2 );
  Point p2( 2, 2, 3 );
  Domain domain( p1, p2 );

  Point p3( 1, 1, 1 );
  Point p4( 2, -1, 3 );
  Point p5( -1, 2, 3 );
  Point p6( 0, 0, 0 );
  Point p0( 0, 2, 1 );

  viewer << SetMode3D( p1.styleName(), "PavingWired" );
  viewer << p1 << p2 << p3;

  //viewer << SetMode3DCairo( p1.styleName(), "Grid" );
  viewer << CustomColors3D(Color(250, 0,0),Color(250, 0,0));
  viewer << p4 << p5 ;
  viewer << SetMode3D( p1.styleName(), "Both" );
  viewer << CustomColors3D(Color(250, 200,0, 100),Color(250, 0,0, 100));
  viewer << p6;
  viewer << CustomColors3D(Color(250, 200,0, 100),Color(250, 200,0, 20));
  viewer << p0;

  viewer << SetMode3D(domain.styleName(), "Paving");
  viewer << domain;
  viewer << SetMode3D(viewer.styleName(), "WireFrameMode");
  viewer.saveCairo("dgtalCairo-5-custom-wireframe.png", Board3DTo2D::CairoPNG, 600*2, 400*2);
  
  viewer << SetMode3D(viewer.styleName(), "SolidMode");
  viewer.saveCairo("dgtalCairo-5-custom.png", Board3DTo2D::CairoPNG, 600*2, 400*2);
}
//                                                                           //
///////////////////////////////////////////////////////////////////////////////




