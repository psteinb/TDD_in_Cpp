#ifndef _GEO_VEC_HPP_
#define _GEO_VEC_HPP_
#include <numeric>
#include <functional>
#include <vector>
#include <iostream>

struct squared_plus
{
  template <typename T>
  T operator()(const T& _first, const T& _second){

    return _first + _second*_second;
  }
  
};

template <typename T, typename default_Op = std::plus<T> >
struct geo_vec
{
  std::vector<T> data_;
  
  geo_vec() : data_() {};

  geo_vec(const std::vector<T>& _rhs) : data_(_rhs) {};

  geo_vec(const size_t& _size, const T& _item) : data_(_size, _item) {};
  
  virtual ~geo_vec(){};

  bool empty() const {
    return data_.empty();
  }

  size_t size() const {
    return data_.size();
  }

  void resize(const size_t& _num){
    data_.resize(_num);
  }
  
  typename std::vector<T>::iterator begin() {
    return data_.begin();
  }
  
  typename std::vector<T>::iterator end() {
    return data_.end();
  }


  int norm(){
    int value = std::accumulate(data_.begin(), data_.end(),0,default_Op());
    return value;
  }
  

  template <typename Op>
  int norm(Op _operand){
    int value = std::accumulate(data_.begin(), data_.end(),0,_operand);
    return value;
  }
  
};

#endif /* _GEO_VEC_H_ */
