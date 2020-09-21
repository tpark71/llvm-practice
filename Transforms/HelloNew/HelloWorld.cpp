//include the header file
#include "llvm/Transforms/HelloNew/HelloWorld.h"

//it is required bc the functions from the include files lives in the llvm namespace.
using namespace llvm;

//simply prints out the name of the function to stderr
PreservedAnalyses HelloWorldPass::run(Function &F,
                                      FunctionAnalysisManager &AM) {
  errs() << F.getName() << "\n";
  return PreservedAnalyses::all();
}