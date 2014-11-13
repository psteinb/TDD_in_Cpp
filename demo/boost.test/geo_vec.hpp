#ifndef _GEO_VEC_H_
#define _GEO_VEC_H_

#include <vector>
#include <numeric>
#include <functional>

template <typename T, typename F = std::plus<T> >
struct geo_vec {

  std::vector<T> data_;

  geo_vec() :
    data_(){}

  geo_vec( const size_t& _len, const T& _value) :
    data_(_len, _value){}

  geo_vec( const std::vector<T>& _v ):
    data_(_v){
    
  }

  bool empty() const {
    return data_.empty();
  }

  T norm () const {
    T value = std::accumulate(data_.begin(), data_.end(),T(0), F());
    return value;
  }
  
  template <typename Op>
  T norm (Op _op) const {
    T value = std::accumulate(data_.begin(), 
			      data_.end(),
			      T(0),
			      _op);
    return value;
  }
  
};


#endif /* _GEO_VEC_H_ */
