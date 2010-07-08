/**
 * @file testInteger.cpp
 * @ingroup Tests
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5807), University of Savoie, France
 *
 * @date 2010/07/02
 *
 * Functions for testing class Integer.
 *
 * This file is part of the DGtal library.
 */

///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "DGtal/base/Common.h"
#include "DGtal/kernel/CInteger.h"
#include "DGtal/kernel/CUnsignedInteger.h"
///////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace DGtal;

///////////////////////////////////////////////////////////////////////////////
// Functions for testing class Integer.
///////////////////////////////////////////////////////////////////////////////
/**
 * Example of a test. To be completed.
 *
 *
 */
bool testInteger()
{
  unsigned int nbok = 0;
  unsigned int nb = 0;
  
  trace.beginBlock ( "Checking CInteger models ..." );
  BOOST_CONCEPT_ASSERT(( CInteger<int> ));
  BOOST_CONCEPT_ASSERT(( CInteger<unsigned int> ));
  BOOST_CONCEPT_ASSERT(( CInteger<long long int> ));
  BOOST_CONCEPT_ASSERT(( CInteger<DGtal::uint16_t> ));
  BOOST_CONCEPT_ASSERT(( CInteger<DGtal::int16_t> ));
  // These tests fail : bool is not a model of CInteger.
  // BOOST_CONCEPT_ASSERT(( CInteger<std::string> ));
  // BOOST_CONCEPT_ASSERT(( CInteger<bool> ));
  nbok += true ? 1 : 0; 
  nb++;
  trace.info() << "(" << nbok << "/" << nb << ") "
	       << "true == true" << std::endl;

  trace.info() << "  - max int16 = " << IntegerTraits<DGtal::int16_t>::max()
	       << std::endl;
  trace.info() << "  - min int16 = " << IntegerTraits<DGtal::int16_t>::min()
	       << std::endl;
  trace.info() << "  - max int32 = " << IntegerTraits<DGtal::int32_t>::max()
	       << std::endl;
  trace.info() << "  - min int32 = " << IntegerTraits<DGtal::int32_t>::min()
	       << std::endl;
  trace.info() << "  - max int64 = " << IntegerTraits<DGtal::int64_t>::max()
	       << std::endl;
  trace.info() << "  - min int64 = " << IntegerTraits<DGtal::int64_t>::min()
	       << std::endl;
  trace.info() << "  - max uint16 = " << IntegerTraits<DGtal::uint16_t>::max()
	       << std::endl;
  trace.info() << "  - min uint16 = " << IntegerTraits<DGtal::uint16_t>::min()
	       << std::endl;
  trace.info() << "  - max uint32 = " << IntegerTraits<DGtal::uint32_t>::max()
	       << std::endl;
  trace.info() << "  - min uint32 = " << IntegerTraits<DGtal::uint32_t>::min()
	       << std::endl;
  trace.info() << "  - max uint64 = " << IntegerTraits<DGtal::uint64_t>::max()
	       << std::endl;
  trace.info() << "  - min uint64 = " << IntegerTraits<DGtal::uint64_t>::min()
	       << std::endl;

  trace.endBlock();

  trace.beginBlock ( "Checking CUnsignedInteger models ..." );
  BOOST_CONCEPT_ASSERT(( CUnsignedInteger<unsigned int> ));
  // These tests fail : int is not a model of CUnsignedInteger.
  // BOOST_CONCEPT_ASSERT(( CUnsignedInteger<int> ));
  nbok += true ? 1 : 0; 
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
  trace.beginBlock ( "Testing class Integer" );
  trace.info() << "Args:";
  for ( int i = 0; i < argc; ++i )
    trace.info() << " " << argv[ i ];
  trace.info() << endl;

  bool res = testInteger(); // && ... other tests
  trace.emphase() << ( res ? "Passed." : "Error." ) << endl;
  trace.endBlock();
  return res ? 0 : 1;
}
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
