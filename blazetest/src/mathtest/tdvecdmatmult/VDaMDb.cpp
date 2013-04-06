//=================================================================================================
/*!
//  \file src/mathtest/tdvecdmatmult/VDaMDb.cpp
//  \brief Source file for the VDaMDb dense vector/dense matrix multiplication math test
//
//  Copyright (C) 2011 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. This library is free software; you can redistribute
//  it and/or modify it under the terms of the GNU General Public License as published by the
//  Free Software Foundation; either version 3, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with a special
//  exception for linking and compiling against the Blaze library, the so-called "runtime
//  exception"; see the file COPYING. If not, see http://www.gnu.org/licenses/.
*/
//=================================================================================================


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <cstdlib>
#include <iostream>
#include <blaze/math/DynamicMatrix.h>
#include <blaze/math/DynamicVector.h>
#include <blazetest/mathtest/Creator.h>
#include <blazetest/mathtest/tdvecdmatmult/OperationTest.h>
#include <blazetest/system/MathTest.h>


//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
int main()
{
   std::cout << "   Running 'VDaMDb'..." << std::endl;

   using blazetest::mathtest::TypeA;
   using blazetest::mathtest::TypeB;

   try
   {
      // Matrix type definitions
      typedef blaze::DynamicVector<TypeA>  VDa;
      typedef blaze::DynamicMatrix<TypeB>  MDb;

      // Creator type definitions
      typedef blazetest::Creator<VDa>  CVDa;
      typedef blazetest::Creator<MDb>  CMDb;

      // Running tests with small vectors and matrices
      for( size_t i=0UL; i<=6UL; ++i ) {
         for( size_t j=0UL; j<=6UL; ++j ) {
            RUN_TDVECDMATMULT_OPERATION_TEST( CVDa( i ), CMDb( i, j ) );
         }
      }

      // Running tests with large vectors and matrices
      RUN_TDVECDMATMULT_OPERATION_TEST( CVDa(  67UL ), CMDb(  67UL, 127UL ) );
      RUN_TDVECDMATMULT_OPERATION_TEST( CVDa( 127UL ), CMDb( 127UL,  67UL ) );
      RUN_TDVECDMATMULT_OPERATION_TEST( CVDa(  64UL ), CMDb(  64UL, 128UL ) );
      RUN_TDVECDMATMULT_OPERATION_TEST( CVDa( 128UL ), CMDb( 128UL,  64UL ) );
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during dense vector/dense matrix multiplication:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
