

// STL알고리즘 
// === myheader.h

#ifndef MYHEADER_H_
#define MYHEADER_H_
template <typename T>
void print(const T &v, const char *message = " ")
{
	typename T::const_iterator it;
	std::cout << message;
	std::cout << "( ";
	for (it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << " )" << std::endl;
}
#endif