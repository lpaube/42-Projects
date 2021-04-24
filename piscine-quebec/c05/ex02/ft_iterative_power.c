int	ft_iterative_power(int nb, int power)
{
	int	newNb;

	newNb = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		newNb = nb * newNb;
		power--;
	}
	return (newNb);
}
