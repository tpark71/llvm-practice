add_llvm_component_library(LLVMHelloWorld
	HelloWorld.cpp

	DEPENDS
	intrinsics_gen
	)