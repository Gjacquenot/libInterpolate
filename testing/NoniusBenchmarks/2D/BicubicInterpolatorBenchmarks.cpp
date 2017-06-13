#include "nonius/nonius.h++"

#include "../Utils/DataSet.hpp"

#include "Interpolators/_2D/BicubicInterpolator.hpp"


NONIUS_BENCHMARK("BicubicInterpolator 5x5 Data Set Construct",
[](nonius::chronometer meter)
{
  _2D::BicubicInterpolator<double> interp;
  _2D::DataSet data(5,5);

  meter.measure( [&](){ interp.setData( data.x, data.y, data.z ); } );

})



NONIUS_BENCHMARK("BicubicInterpolator 5x5 Data Set 1000 Point Interpolation",
[](nonius::chronometer meter)
{
  _2D::BicubicInterpolator<double> interp;
  _2D::DataSet data(5,5);

  interp.setData( data.x, data.y, data.z );

  double dx = 5./100;
  double dy = 5./10;
  meter.measure( [&](){
  for(double i = 0; i < 100; i++)
    for(double j = 0; j < 10; j++)
      interp(i*dx,j*dy);
  } );

})


NONIUS_BENCHMARK("BicubicInterpolator 10x10 Data Set Construct",
[](nonius::chronometer meter)
{
  _2D::BicubicInterpolator<double> interp;
  _2D::DataSet data(10,10);

  meter.measure( [&](){ interp.setData( data.x, data.y, data.z ); } );

})



NONIUS_BENCHMARK("BicubicInterpolator 10x10 Data Set 1000 Point Interpolation",
[](nonius::chronometer meter)
{
  _2D::BicubicInterpolator<double> interp;
  _2D::DataSet data(10,10);

  interp.setData( data.x, data.y, data.z );

  double dx = 10./100;
  double dy = 10./10;
  meter.measure( [&](){
  for(double i = 0; i < 100; i++)
    for(double j = 0; j < 10; j++)
      interp(i*dx,j*dy);
  } );

})






















