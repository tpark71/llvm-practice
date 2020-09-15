// We are writing a Pass
// We are operating on Function
// We will be doing some printing
#include "llvm/Pass.h"
#include "llvm/Function.h"
#include "llvm/Support/raw_ostream.h"

// Functions from the include files live in the llvm namespace
using namespace llvm;

// Anonymous namespaces: this will only show to the current file
namespace {
	struct Hello : public FunctionPass { // Declares a "Hello" class that is the sublcass of FunctionPass
		static char ID;
		Hello() : FunctionPass(&ID) {} //Declares pass identifier used by LLVM to identify pass. This allwos LLVM to avoid using C++ runtime
		virtual bool runOnFunction(Function &F) { //we declare "runOnFunction": overloads an abstract virtual method inherited from FunctionPass
			err() << "Hello: " << F.getName() << "\n";
			return false;
		}
	}
	char Hello::ID = 0; // LLVM uses ID's address to identify pass so initialization value is not important
	INITIALIZE_PASS(Hello, "hello", "Hello World Pass", false /*Oly looks at CFG */, false /* Analysis Pass*/);
}