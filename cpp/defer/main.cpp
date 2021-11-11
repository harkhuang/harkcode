

//
// Go's defer operator for C++
//
// Examples:
//
#include "defer.h"
//
	#include <stdio.h>

	void done() {
		printf("done\n");
	}

	struct MyStruct {
		void MethodA() { printf("MyStruct.MethodA\n"); }
		void MethodB() { printf("MyStruct.MethodB\n"); }
	};

	int main() {
		defer done;

		defer []{ printf("lambda 1\n"); };
		defer []{ printf("lambda 2\n"); };

		defer std::bind(&MyStruct::MethodA, MyStruct());
		defer std::bind(&MyStruct::MethodB, MyStruct());
		defer std::bind(printf, "printf %s %d\n", "hello world", 2015);

		FILE* fp = fopen("defer.h", "rt");
		if(fp == NULL) {
			printf("open \"defer.h\" failed!\n");
			return -1;
		}
		defer [&]{ printf("fclose(\"defer.h\")\n"); fclose(fp); };

		char* buf = new char[1024];
		defer [&]{ printf("delete buf\n"); delete[] buf; };

		defer []{ printf("defer a: %d\n", 1); };
		defer []{ printf("defer a: %d\n", 2); };
		defer []{ printf("defer a: %d\n", 3); };

		{
			defer []{ printf("local defer a: %d\n", 1); };
			defer []{ printf("local defer a: %d\n", 2); };
			defer []{ printf("local defer a: %d\n", 3); };
		}

		defer []{
			printf("defer c:\n");
			for(int i = 0; i < 3; ++i) {
				defer [&]{
					defer [&]{
						printf("\ti = %d: begin\n", i);
						defer [&]{ printf("\ti = %d: end\n", i); };
						printf("\ti = %d: ...\n", i);
					};
				};
			}
		};

		return 0;
	}