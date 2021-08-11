/**
 * @file problem.h
 * @author Jaroslav Janos (janosjar@fel.cvut.cz)
 * @brief 
 * @version 2.0
 * @date 04. 08. 2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __PROBLEM_H__
#define __PROBLEM_H__

#include <deque>

#include "common.h"
#include "environment.h"

template<class R>
struct Problem {
  int Repetition{0};
  Dimensions Dimension{D3};

  SolverType Solver;
  bool Optimize;

  Environment<R> Env;
  std::deque<R> Roots;
  R Goal;
  bool HasGoal{false};
  
  bool AutoRange{false};

  double DistTree;
  double SamplingDist;
  double CollisionDist;
  
  int MaxIterations;
  double PriorityBias{0};
  int MaxMisses{DEFAULT_THRES_MISS};
  
  SaveOptions SaveOpt{None};
  std::map<SaveOptions, FileStruct> FileNames;
  std::map<SaveOptions, int> SaveFreq;
  std::string ID{ "Solver" };

  std::string TspSolver;
  std::string TspType;

  int GetNumRoots() {
    if (HasGoal) {
     return Roots.size() + 1;
    } else {
     return Roots.size();
    }
    return 1;
  }
};

#endif /* __PROBLEM_H__ */
