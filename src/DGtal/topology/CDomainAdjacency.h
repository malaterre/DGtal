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

#pragma once

/**
 * @file CDomainAdjacency.h
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5807), University of Savoie, France
 *
 * @date 2010/07/17
 *
 * Header file for concept CDomainAdjacency.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(CDomainAdjacency_RECURSES)
#error Recursive header files inclusion detected in CDomainAdjacency.h
#else // defined(CDomainAdjacency_RECURSES)
/** Prevents recursive inclusion of headers. */
#define CDomainAdjacency_RECURSES

#if !defined CDomainAdjacency_h
/** Prevents repeated inclusion of headers. */
#define CDomainAdjacency_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "boost/concept_check.hpp"
#include "DGtal/base/Common.h"
#include "DGtal/topology/CAdjacency.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

  /////////////////////////////////////////////////////////////////////////////
  // class CDomainAdjacency
  /**
   * Description of \b concept '\b CDomainAdjacency' <p> 
   * @ingroup Concepts 
   *
   * \brief Aim: Refines the concept CAdjacency by telling that the
   * adjacency is specific to a given domain of the embedding digital
   * space.
   *
   * This class is useful to define subspaces with restricted
   * neighborhood relations. For instance, you can limit the adjacency
   * to an object, then to its border, then to a subset of its border,
   * etc.
   * 
   * <p> Refinement of CAdjacency
   *
   * <p> Associated types :
   *
   * - Domain: the domain of this adjacency.
   * - Predicate: the type of the predicate "is in domain ?"
   *
   * <p> Notation
   * - \t X : A type that is a model of CDomainAdjacency
   * - \t x, \t y	: Object of type X
   *
   * <p> Definitions
   *
   * <p> Valid expressions and semantics <br>
   * <table> <tr> <td> \b Name </td> <td> \b Expression </td>
   * <td> \b Type requirements </td> <td> \b Return type </td>
   * <td> \b Precondition </td> <td> \b Semantics </td> 
   * <td> \b Postcondition </td> <td> \b Complexity </td>
   * </tr>
   * <tr> 
   * <td> embedding domain</td> <td> x.domain()</td> 
   * <td> </td> <td> const Domain & </td>
   * <td> </td> <td> return a reference to the embedding domain.</td> <td> </td> <td> O(1) </td>
   * </tr>
   * <tr> 
   * <td> "is in domain ?" predicate</td> <td> x.predicate() </td> 
   * <td> </td> <td> const Predicate & </td>
   * <td> </td> <td> return a reference to the predicate object that is characteristic of the embedding domain.</td> <td> </td> <td> O(1) </td>
   * </tr>
   * </table>
   *
   * <p> Invariants <br>
   *
   * <p> Models <br>
   *
   * - DomainAdjacency
   *
   * <p> Notes <br>
   */
  template <typename T>
  struct CDomainAdjacency : CAdjacency<T>
  {
    // ----------------------- Concept checks ------------------------------
  public:

    typedef typename Adj::Domain Domain;
    typedef typename Adj::Predicate Predicate;

    // ------------------------- Private Datas --------------------------------
  private:
    BOOST_CONCEPT_USAGE( CDomainAdjacency )
    {
      // check domain()
      ConceptUtils::sameType( myDomain, myT.domain() );
      // check predicate()
      ConceptUtils::sameType( myPredicate, myT.predicate() );
    }

    // ------------------------- Internals ------------------------------------
  private:
    T myT;
    Domain myDomain;
    Predicate myPredicate;
    
  }; // end of concept CDomainAdjacency
  
} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions.
#include "DGtal/topology/CDomainAdjacency.ih"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined CDomainAdjacency_h

#undef CDomainAdjacency_RECURSES
#endif // else defined(CDomainAdjacency_RECURSES)
