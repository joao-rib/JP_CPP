#include "MutantStack.hpp"

//std::stack::push(const T& value) - Add to the top
//std::stack::pop() - Remove from the top
//std::stack::top() - Returns the top value (T& or const T&)

void	testStack(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "size(): " << mstack.size() << std::endl;
	std::cout << "top(2): " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size(): " << mstack.size() << std::endl;
	std::cout << "top(1): " << mstack.top() << std::endl << std::endl;

	mstack.push(-3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(-42);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	int j = 0;
	while (it != ite)
	{
		std::cout << "Value " << j << " from the beginning is " << *it << std::endl;
		++it;
		j++;
	}
	it = mstack.begin();
	j = 0;
	while (it != ite)
	{
		std::cout << "Value " << j << " from the end is " << *ite << std::endl;
		--ite;
		j++;
	}

	std::stack<int> s(mstack);
	std::cout << '\n' << "s - size(): " << s.size() << std::endl;
	std::cout << "s - top(): " << s.top() << std::endl;
	//std::cout << "s - begin(): " << *s.begin() << std::endl;
	//std::cout << "s - end(): " << *s.end() << std::endl;
}

void	testVector(void)
{
	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(17);
	std::cout << "size(): " << vec.size() << std::endl;
	std::cout << "back(2): " << vec.back() << std::endl;
	vec.pop_back();
	std::cout << "size(): " << vec.size() << std::endl;
	std::cout << "back(1): " << vec.back() << std::endl << std::endl;

	vec.push_back(-3);
	vec.push_back(5);
	vec.push_back(737);
	vec.push_back(-42);
	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();
	++it;
	--it;
	int j = 0;
	while (it != ite)
	{
		std::cout << "Value " << j << " from the beginning is " << *it << std::endl;
		++it;
		j++;
	}
	it = vec.begin();
	j = 0;
	while (it != ite)
	{
		std::cout << "Value " << j << " from the end is " << *ite << std::endl;
		--ite;
		j++;
	}

	std::vector<int> v(vec);
	std::cout << '\n' << "v - size(): " << v.size() << std::endl;
	std::cout << "v - back(): " << v.back() << std::endl;
	std::cout << "v - begin(): " << *v.begin() << std::endl;
	std::cout << "v - end(): " << *v.end() << std::endl;
}

int main()
{
	std::cout << '\n' << "MUTANT STACK" << std::endl;
	testStack();
	std::cout << '\n' << "REGULAR VECTOR" << std::endl;
	testVector();
	return 0;
}