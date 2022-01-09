#ifndef _PRINT
#define _PRINT

#include <iostream>

template<typename T>
void print(std::ostream& ous,const T&x)
{
	ous<<x<<'\n';
	return;
}

template<typename Arg,typename ...Rest>
void print(std::ostream& ous,const Arg&x,Rest... rest)
{
	ous<<x<<' ';
	print(ous,rest...);
	return;
}

#endif