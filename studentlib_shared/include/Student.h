#include<string>

#ifdef _WIN32
    #ifdef testStudent_EXPORTS
        #define TESTSTUDENT_EXPORT __declspec(dllexport)
    #else
        #define TESTSTUDENT_EXPORT __declspec(dllimport)
    #endif
#else
    #define TESTSTUDENT_EXPORT
#endif

class TESTSTUDENT_EXPORT Student{

private:

	const char* name;
public:
	Student(std::string);
	virtual void display();
};
