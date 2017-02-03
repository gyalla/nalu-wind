/*------------------------------------------------------------------------*/
/*  Copyright 2014 Sandia Corporation.                                    */
/*  This software is released under the license detailed                  */
/*  in the file, LICENSE, which is located in the top-level Nalu          */
/*  directory structure                                                   */
/*------------------------------------------------------------------------*/


#ifndef SteadyThermal3dContactSrcElemSuppAlg_h
#define SteadyThermal3dContactSrcElemSuppAlg_h

#include <SupplementalAlgorithm.h>
#include <AlgTraits.h>
#include <FieldTypeDef.h>

#include <stk_mesh/base/BulkData.hpp>
#include <stk_mesh/base/Entity.hpp>

// Kokkos
#include <Kokkos_Core.hpp>

namespace sierra{
namespace nalu{

class Realm;
class MasterElement;

template<class IntAlgTraits>
class SteadyThermal3dContactSrcElemSuppAlg : public SupplementalAlgorithm
{
public:

  SteadyThermal3dContactSrcElemSuppAlg(
    Realm &realm,
    const stk::topology &theTopo);

  virtual ~SteadyThermal3dContactSrcElemSuppAlg() {}

  virtual void element_execute(
    double *lhs,
    double *rhs,
    stk::mesh::Entity element);
  
  const stk::mesh::BulkData *bulkData_;

  VectorFieldType *coordinates_;

  MasterElement *meSCV_;
  const int *ipNodeMap_;

  const double a_;
  const double k_;
  const double pi_;

  // scratch space
  Kokkos::View<double**> ws_shape_function_;
  Kokkos::View<double**> ws_coordinates_;
  Kokkos::View<double*> ws_scv_volume_;
  Kokkos::View<double*> ws_scvCoords_;
};

} // namespace nalu
} // namespace Sierra

#endif
