#include "PmergeMe.hpp"

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

static void	insertion(t_vector &low, t_vector &high)
{
	for (size_t i = 0; i < high.size(); i++)
		low.push_back(high[i]);

	high = low;
}

void	PmergeMeVector(t_vector &base)
{
	if (base.size() <= 1)
		return;

	t_vector	high, low;
	split(base, high, low);

	PmergeMeVector(high);
	insertion(low, high);

	base = high;
}
