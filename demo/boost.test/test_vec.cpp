#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE geo_vec
#include <boost/test/unit_test.hpp>
#include "geo_vec.hpp"
#include <functional>

BOOST_AUTO_TEST_CASE( geo_vec_constructs_is_empty )
{
  geo_vec<int> v;
  BOOST_CHECK(v.empty());
}


BOOST_AUTO_TEST_CASE( geo_vec_constructs_with_args )
{
  geo_vec<int> v(4,2);
  BOOST_CHECK(!v.empty());
}


struct fixture {

  std::vector<int> fix_v;

  //setup
  fixture():
    fix_v(14,42){}

  //teardown
  ~fixture(){}

};

BOOST_FIXTURE_TEST_SUITE( suite_w_given_vector, fixture)

BOOST_AUTO_TEST_CASE( fixture_works )
{
  BOOST_CHECK(fix_v.size());
}

BOOST_AUTO_TEST_CASE( copy_construct_std_vec )
{
  geo_vec<int> v(fix_v);
  
  BOOST_CHECK(!v.empty());
  BOOST_CHECK(v.norm());
  BOOST_CHECK_EQUAL(v.norm(), 14*42);
}


BOOST_AUTO_TEST_CASE( use_custom_norm )
{
  geo_vec<int> v(fix_v);
  BOOST_CHECK_EQUAL(v.norm(std::plus<int>()), v.norm());  
}

struct add_squared
{
  template <typename T>
  T operator()(const T& _first, const T& _second){
    return _first + _second*_second;
  }
};

BOOST_AUTO_TEST_CASE( use_squared_norm )
{
  geo_vec<int, add_squared> v(fix_v);
  geo_vec<int> def(fix_v);

  BOOST_CHECK_EQUAL(def.norm(), 14*42*42);  
}

BOOST_AUTO_TEST_SUITE_END()

