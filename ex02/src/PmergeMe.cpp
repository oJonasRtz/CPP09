#include "PmergeMe.hpp"

#pragma region Vector
static void	split(t_vector &base, t_vector &high, t_vector &low)
{
	size_t	i = 0, len = base.size();

	for (; i + 1 < len; i += 2)
	{
		unsigned int	a = base[i];
		unsigned int	b = base[i + 1];
		if (a < b)
		{
			high.push_back(b);
			low.push_back(a);
		} else{
			high.push_back(a);
			low.push_back(b);
		}
	}

	//Odd values
	if (i < len)
		low.push_back(base[i]);
}

static unsigned int	jacobsthal(unsigned int n)
{
	if (n < 2)
		return (n);
	
	unsigned int	prev1 = 1;
	unsigned int	prev2 = 0;
	unsigned int	current = 0;

	for (unsigned int k = 2; k <= n; k++)
	{
		current = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = current;
	}

	return (current);
}

static void	insertion(t_vector &low, t_vector &high)
{
	unsigned	len = low.size();
	unsigned	inserted = 0;
	unsigned	k = 3;

	if (len)
	{
		t_vector::iterator	pos = std::upper_bound(high.begin(), high.end(), low[0]);
		high.insert(pos, low[0]);
		inserted++;
	}

	while (inserted < len)
	{
		unsigned	JK = jacobsthal(k);
		unsigned	JPrev = jacobsthal(k - 1);

		//Limit the value to the true vector len
		unsigned	upper = std::min(len, JK);
		unsigned	lower = std::min(len, JPrev);

		for (unsigned i = upper - 1; i >= lower; i--)
		{
			unsigned	val = low[i];

			t_vector::iterator	pos = std::upper_bound(high.begin(), high.end(), val);
			high.insert(pos, val);
		}
		inserted = upper;
		k++;
	}	
}

void	PmergeMeVector(t_vector &base)
{
	//Recursion end
	if (base.size() <= 1)
		return;

	//Split values
	t_vector	high, low;
	split(base, high, low);

	//Recursion + put low 'n high back together
	PmergeMeVector(high);
	insertion(low, high);

	//Final result
	base = high;
}

#pragma endregion

#pragma region list

static void	listSplit(t_list &base, t_list &high, t_list &low)
{
	t_list::iterator	it = base.begin();
	
	while (it != base.end())
	{
		unsigned	a = *it;

		it++;
		if (it != base.end())
		{
			unsigned	b = *it;
			if (a < b)
			{
				high.push_back(b);
				low.push_back(a);
			}
			else
			{
				high.push_back(a);
				low.push_back(b);
			}
			it++;
		}
		else
		{
			low.push_back(a);
		}
	}
}

static void	listInsertion(t_list &low, t_list &high)
{
	unsigned	len = low.size();
	unsigned	inserted = 0;
	unsigned	k = 3;

	if (len)
	{
		t_list::iterator	it = low.begin();
		unsigned			val = *it;
		t_list::iterator	pos = std::upper_bound(high.begin(), high.end(), val);

		high.insert(pos, val);
		inserted++;
		it++;
	}
	while (inserted < len)
	{
		unsigned	JK = jacobsthal(k);
		unsigned	JPrev = jacobsthal(k - 1);

		unsigned	upper = std::min(len, JK);
		unsigned	lower = std::min(len, JPrev);

		t_list::iterator	it = low.begin();
		std::advance(it, upper - 1);
		for (unsigned i = upper - 1; i >= lower; i--)
		{
			unsigned	val = *it;
			t_list::iterator	pos = std::upper_bound(high.begin(), high.end(), val);
			
			high.insert(pos, val);
			std::advance(it, -1);
		}
		inserted = upper;
		k++;
	}
}

void	PmergeMeList(t_list &base)
{
	if (base.size() <= 1)
		return;

	t_list	high, low;
	listSplit(base, high, low);

	PmergeMeList(high);
	listInsertion(low, high);

	base = high;
}

#pragma endregion