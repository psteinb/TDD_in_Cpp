#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "geo_vec.hpp"

TEST_CASE( "is default constructable", "[geo_vec]" ) {
  
  geo_vec<int> any;
  REQUIRE( true );
}


TEST_CASE( "has minimal interface", "[geo_vec]" ) {
  
  geo_vec<int> any;
  REQUIRE( any.empty() );

  SECTION( "has size member function" ) {

        REQUIRE( any.size() == 0 );

  }

  SECTION( "has resize member function" ) {
    
    any.resize(2);
    
    REQUIRE( !any.empty());
    REQUIRE( any.size() == 2);

  }

  SECTION( "has begin iterator function" ) {

    any.resize(2);
    REQUIRE( *any.begin() == 0);

  }

  SECTION( "has end iterator function" ) {

    any.resize(2);
    REQUIRE( (any.end() - any.begin()) == 2);

  }

  SECTION( "is vector copyable" ) {
  
    std::vector<int> local_(12,0);
    geo_vec<int> any(local_);
    REQUIRE( any.size() == 12 );
  }


}


TEST_CASE( "computes norm", "[geo_vec]" ) {
  
  std::vector<int> local_(4,2);
  geo_vec<int> any(local_);
  int n = any.norm();
  REQUIRE(n == 8);

  SECTION( "accepts non-standard norm" ) {
  
    std::vector<int> local_(4,2);
    geo_vec<int> any(local_);
    REQUIRE( any.norm(squared_plus()) == 16 );
    
  }

}


SCENARIO( "size changes ", "[geo_vec]" ) {

  GIVEN( "A vector with 5 items" ) {
    geo_vec<int> v( 5, 2 );
      
    REQUIRE( v.size() == 5 );
      
    WHEN( "the size is increased" ) {
      v.resize( 10 );
	
      THEN( "the size and capacity change" ) {
	REQUIRE( v.size() == 10 );

      }
    }
  }
}
