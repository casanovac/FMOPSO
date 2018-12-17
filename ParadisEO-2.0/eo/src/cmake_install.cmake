# Install script for directory: /home/carlos/Instaladores/ParadisEO-2.0/eo/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE STATIC_LIBRARY FILES "/home/carlos/Instaladores/ParadisEO-2.0/build/eo/lib/libeo.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/paradiseo/eo" TYPE FILE FILES
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/EO.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/PO.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/apply.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoAlgo.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoBinaryFlight.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoBitParticle.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoBreed.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoCellularEasyEA.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoCloneOps.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoCombinedContinue.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoCombinedInit.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoConstrictedVariableWeightVelocity.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoConstrictedVelocity.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoContinue.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoCounter.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoCtrlCContinue.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoDetSelect.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoDetTournamentSelect.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoDistribUpdater.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoDistribution.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoDualFitness.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoEDA.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoEasyEA.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoEasyPSO.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoEvalContinue.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoEvalCounterThrowException.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoEvalFunc.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoEvalFuncCounter.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoEvalFuncCounterBounder.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoEvalFuncPtr.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoEvalTimeThrowException.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoEvalUserTimeThrowException.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoExceptions.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoExtendedVelocity.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoFactory.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoFitContinue.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoFitnessScalingSelect.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoFixedInertiaWeightedVelocity.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoFlOrBinOp.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoFlOrMonOp.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoFlOrQuadOp.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoFlight.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoFunctor.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoFunctorStore.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoG3Replacement.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoGaussRealWeightUp.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoGenContinue.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoGenOp.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoGeneralBreeder.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoInit.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoInitializer.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoInt.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoIntegerVelocity.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoInvalidateOps.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoLinearDecreasingWeightUp.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoLinearFitScaling.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoLinearTopology.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoMGGReplacement.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoMerge.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoMergeReduce.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoNDSorting.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoNeighborhood.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoObject.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoOneToOneBreeder.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoOp.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoOpContainer.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoOpSelMason.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoOrderXover.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoPSO.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoParticleBestInit.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoParticleFullInitializer.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoPerf2Worth.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoPeriodicContinue.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoPersistent.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoPop.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoPopEvalFunc.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoPopulator.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoPrintable.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoPropGAGenOp.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoProportionalCombinedOp.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoProportionalSelect.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoRandomRealWeightUp.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoRandomSelect.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoRanking.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoRankingSelect.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoRealBoundModifier.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoRealParticle.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoReduce.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoReduceMerge.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoReduceMergeReduce.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoReduceSplit.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoReplacement.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoRingTopology.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSGA.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSGAGenOp.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSGATransform.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSIGContinue.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSTLFunctor.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoScalarFitness.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoScalarFitnessAssembled.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSecondsElapsedContinue.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSelect.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSelectFactory.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSelectFromWorth.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSelectMany.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSelectNumber.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSelectOne.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSelectPerc.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSequentialSelect.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSharing.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSharingSelect.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoShiftMutation.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSigBinaryFlight.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSimpleEDA.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSocialNeighborhood.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoStandardFlight.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoStandardVelocity.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoStarTopology.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSteadyFitContinue.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoStochTournamentSelect.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoStochasticUniversalSelect.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSurviveAndDie.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSwapMutation.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoSyncEasyPSO.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoTimeContinue.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoTopology.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoTransform.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoTruncSelect.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoTruncatedSelectMany.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoTruncatedSelectOne.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoTwoOptMutation.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoVariableInertiaWeightedVelocity.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoVariableLengthCrossover.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoVariableLengthMutation.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoVector.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoVectorParticle.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoVelocity.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoVelocityInit.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eoWeightUpdater.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/es.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/ga.h"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/eo"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/paradiseo/eo" TYPE DIRECTORY FILES
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/do"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/es"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/ga"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/gp"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/other"
    "/home/carlos/Instaladores/ParadisEO-2.0/eo/src/utils"
    FILES_MATCHING REGEX "/[^/]*\\.h$" REGEX "/checkpointing$" REGEX "/external\\_eo$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/carlos/Instaladores/ParadisEO-2.0/build/eo/src/es/cmake_install.cmake")
  include("/home/carlos/Instaladores/ParadisEO-2.0/build/eo/src/ga/cmake_install.cmake")
  include("/home/carlos/Instaladores/ParadisEO-2.0/build/eo/src/utils/cmake_install.cmake")

endif()

